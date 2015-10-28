/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: spawners
 */


CMobSpawner::CMobSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	this->m_iCount     = 0;
	this->m_SubSpawner = NULL;
}

CSentryGunSpawner::CSentryGunSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	this->m_iLevel = 0;
}

CTankSpawner::CTankSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	this->m_iHealth             = 50000;
	this->m_flSpeed             = 75.0f;
	this->m_strName             = "Tank";
	this->m_strStartNode        = NULL;
	this->m_iSkin               = 0;
	this->m_OnKilledOutput      = NULL;
	this->m_OnBombDroppedOutput = NULL;
}

CTFBotSpawner::CTFBotSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	this->m_iClass        = TF_CLASS_UNKNOWN;
	this->m_strClassIcon  = NULL_STRING;
	this->m_iHealth       = -1;
	this->m_flScale       = -1.0f;
	this->m_flAutoJumpMax = 0.0f;
	this->m_flAutoJumpMin = 0.0f;
	
	/* apparently it wasn't enough to reset this once with the default ctor,
	 * so they reset it again here */
	this->m_DefaultAttrs.Reset();
}

CSquadSpawner::CSquadSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	this->m_flFormationSize      = -1.0f;
	this->m_bShouldPreserveSquad = false;
}

CRandomChoiceSpawner::CRandomChoiceSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	this->m_iSpawned = 0;
}


CMobSpawner::~CMobSpawner()
{
	if (m_SubSpawner != NULL) {
		delete m_SubSpawner;
	}
}

CSentryGunSpawner::~CSentryGunSpawner()
{
}

CTankSpawner::~CTankSpawner()
{
	/* likely bug: the EventInfo members were new'd, but are not delete'd */
}

CTFBotSpawner::~CTFBotSpawner()
{
	// TODO
}

CSquadSpawner::~CSquadSpawner()
{
}

CRandomChoiceSpawner::~CRandomChoiceSpawner()
{
}


bool CMobSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Count") == 0) {
				this->m_iCount = subkey->GetInt(NULL);
			} else {
				IPopulationSpawner *spawner =
					IPopulationSpawner::ParseSpawner(this->m_Populator, subkey);
				if (spawner != NULL) {
					if (this->m_SubSpawner == NULL) {
						this->m_SubSpawner = spawner;
					} else {
						Warning("CMobSpawner: Duplicate spawner encountered - discarding!\n");
						delete spawner;
					}
				} else {
					Warning("Unknown attribute '%s' in Mob definition.\n", name);
				}
			}
		}
	}
	
	return true;
}

bool CSentryGunSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Level") == 0) {
				this->m_iLevel = subkey->GetInt(NULL);
			} else {
				Warning("Invalid attribute '%s' in SentryGun definition\n", name);
				return false;
			}
		}
	}
	
	return true;
}

bool CTankSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Health") == 0) {
				this->m_iHealth = subkey->GetInt(NULL);
			} else if (V_stricmp(name, "Speed") == 0) {
				this->m_flSpeed = subkey->GetFloat(NULL);
			} else if (V_stricmp(name, "Name") == 0) {
				this->m_strName = subkey->GetString(NULL);
			} else if (V_stricmp(name, "Skin") == 0) {
				this->m_iSkin = subkey->GetInt(NULL);
			} else if (V_stricmp(name, "StartingPathTrackNode") == 0) {
				this->m_strStartNode = subkey->GetString(NULL);
			} else if (V_stricmp(name, "OnKilledOutput") == 0) {
				this->m_OnKilledOutput = ParseEvent(subkey);
			} else if (V_stricmp(name, "OnBombDroppedOutput") == 0) {
				this->m_OnBombDroppedOutput = ParseEvent(subkey);
			} else {
				Warning("Invalid attribute '%s' in Tank definition\n", name);
				return false;
			}
		}
	}
	
	return true;
}

bool CTFBotSpawner::Parse(KeyValues *kv)
{
	this->m_iClass        = TF_CLASS_UNKNOWN;
	this->m_strClassIcon  = NULL_STRING;
	this->m_iHealth       = -1;
	this->m_flScale       = -1.0f;
	this->m_flAutoJumpMax = 0.0f;
	this->m_flAutoJumpMin = 0.0f;
	
	this->m_DefaultAttrs.Reset();
	
	this->m_ECAttrs.RemoveAll();
	
	/* handle the template reference (if any) before doing anything else */
	KeyValues *kv_tref = kv->FindKey("Template");
	if (kv_tref != NULL) {
		const char *tname = kv_tref->GetString(NULL);
		
		KeyValues *kv_timpl =
			this->m_Populator->m_PopMgr->m_kvTemplates->FindKey(tname);
		if (kv_timpl != NULL) {
			if (!this->Parse(kv_timpl)) {
				return false;
			}
		} else {
			Warning("Unknown Template '%s' in TFBotSpawner definition\n",
				tname);
		}
	}
	
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Template") == 0) {
				/* skip, since we already handled templates earlier */
			} else if (V_stricmp(name, "Class") == 0) {
				const char *str = subkey->GetString(NULL);
				if ((this->m_iClass = GetClassIndexFromString(str, 10)) !=
					TF_CLASS_UNKNOWN) {
					if (this->m_strName.IsEmpty()) {
						this->m_strName = str;
					}
				} else {
					Warning("TFBotSpawner: Invalid class '%s'\n", str);
					return false;
				}
			} else if (V_stricmp(name, "ClassIcon") == 0) {
				this->m_strClassIcon =
					STRING(AllocPooledString(subkey->GetString(NULL)));
			} else if (V_stricmp(name, "Health") == 0) {
				this->m_iHealth = subkey->GetInt(NULL);
			} else if (V_stricmp(name, "Scale") == 0) {
				this->m_flScale = subkey->GetFloat(NULL);
			} else if (V_stricmp(name, "Name") == 0) {
				this->m_strName = subkey->GetString(NULL);
			} else if (V_stricmp(name, "TeleportWhere") == 0) {
				this->m_TeleportWhere.AddToHead(strdup(subkey->GetString(NULL)));
			} else if (V_stricmp(name, "AutoJumpMin") == 0) {
				this->m_flAutoJumpMin = subkey->GetFloat(NULL);
			} else if (V_stricmp(name, "AutoJumpMax") == 0) {
				this->m_flAutoJumpMax = subkey->GetFloat(NULL);
			} else {
				if (V_stricmp(name, "EventChangeAttributes") == 0) {
					if (!this->ParseEventChangeAttributes(subkey)) {
						Warning("TFBotSpawner: Failed to parse EventChangeAttributes\n");
						return false;
					}
				} else {
					if (!ParseDynamicAttributes(this->m_DefaultAttrs, subkey)) {
						Warning("TFBotSpawner: Unknown field '%s'\n", name);
						return false;
					}
				}
			}
		}
	}
	
	return true;
}

bool CSquadSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "FormationSize") == 0) {
				this->m_flFormationSize = subkey->GetFloat(NULL);
			} else if (V_stricmp(name, "ShouldPreserveSquad") == 0) {
				this->m_bShouldPreserveSquad = subkey->GetBool(NULL);
			} else {
				IPopulationSpawner *spawner =
					IPopulationSpawner::ParseSpawner(this->m_Populator, subkey);
				if (spawner != NULL) {
					this->m_SubSpawners.AddToTail(spawner);
				} else {
					Warning("Unknown attribute '%s' in Mob definition.\n", name);
				}
			}
		}
	}
	
	return true;
}

bool CRandomChoiceSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			IPopulationSpawner *spawner =
				IPopulationSpawner::ParseSpawner(this->m_Populator, subkey);
			if (spawner != NULL) {
				this->m_SubSpawners.AddToTail(spawner);
			} else {
				Warning("Unknown attribute '%s' in RandomChoice definition.\n",
					name);
			}
		}
	}
	
	return true;
}


int CMobSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> *ents)
{
	if (this->m_SubSpawner == NULL) {
		return 0;
	}
	
	for (int i = 0; i < this->m_iCount; ++i) {
		if (!this->m_SubSpawner->Spawn(where, ents)) {
			return 0;
		}
	}
	
	return 1;
}

int CSentryGunSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> *ents)
{
	CBaseEntity *sentry = CreateEntityByName("obj_sentrygun");
	if (sentry == NULL) {
		if (tf_populator_debug.GetBool()) {
			DevMsg("CSentryGunSpawner: %3.2f: Failed to create obj_sentrygun\n",
				gpGlobals->curtime);
		}
		
		return 0;
	}
	
	sentry->SetAbsOrigin(where);
	sentry->SetAbsAngles(vec3_angle);
	sentry->Spawn();
	sentry->ChangeTeam(TF_TEAM_BLU);
	
	/* undocumented: CBaseObject+0x9e4 */
	sentry->m_iUpgradeLevelDesired = this->m_iLevel + 1;
	
	sentry->InitializeMapPlacedObject();
	
	if (ents != NULL) {
		ents.AddToTail(sentry->GetRefEHandle());
	}
	
	return 1;
}

int CTankSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> *ents)
{
	CBaseEntity *tank = CreateEntityByName("tank_boss");
	if (tank == NULL) {
		if (tf_populator_debug.GetBool()) {
			DevMsg("CTankSpawner: %3.2f: Failed to create base_boss\n",
				gpGlobals->curtime);
		}
		
		return 0;
	}
	
	tank->SetAbsOrigin(where);
	tank->SetAbsAngles(vec3_angle);
	tank->m_iBossHealth = (int)((float)this->m_iHealth *
		g_pPopulationManager->GetHealthMultiplier(true));
	tank->m_flBossSpeed = this->m_flSpeed;
	tank->m_iName = MAKE_STRING(this->m_strName.Get());
	tank->SetSkin(this->m_iSkin);
	tank->SetStartingPathTrackNode(this->m_strStartNode.GetForModify());
	tank->Spawn();
	
	if (this->m_OnKilledOutput != NULL) {
		/* implicit member-by-member copy of the EventInfo struct */
		tank->m_OnKilledOutput = *this->m_OnKilledOutput;
	}
	if (this->m_OnBombDroppedOutput != NULL) {
		/* implicit member-by-member copy of the EventInfo struct */
		tank->m_OnBombDroppedOutput = *this->m_OnBombDroppedOutput;
	}
	
	if (ents != NULL) {
		ents.AddToTail(tank->GetRefEHandle());
	}
	
	return 1;
}

int CTFBotSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> *ents)
{
	// TODO
}

int CSquadSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> *ents)
{
	VPROF_BUDGET("CSquadSpawner::Spawn", "NextBot");
	
	if (tf_populator_debug.GetBool()) {
		DevMsg("CSquadSpawner: %3.2f: <<<< Spawning Squad >>>>\n",
			gpGlobals->curtime);
	}
	
	int spawned = 0;
	
	int squad_size = this->m_SubSpawners.Count();
	if (GetGlobalTeam(TEAM_SPECTATOR)->GetNumPlayers() >= squad_size) {
		CTFBotSquad *squad = new CTFBotSquad();
		if (squad != NULL) {
			// TODO
		}
		
		// TODO
	}
	
	// TODO
	
	return spawned;
}

int CRandomChoiceSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> *ents)
{
	int spawned = 0;
	
	if (!this->m_SubSpawners.IsEmpty()) {
		this->GenerateRandomIndexes(this->m_iSpawned);
		
		IPopulationSpawner *spawner = this->m_SubSpawners[this->m_iSpawned];
		spawned = spawner->Spawn(where, ents);
		
		++this->m_iSpawned;
	}
	
	return spawned;
}


bool IPopulationSpawner::IsWhereRequired()
{
	return true;
}

bool CTankSpawner::IsWhereRequired()
{
	return false;
}


bool IPopulationSpawner::IsVarious()
{
	return false;
}

bool CSquadSpawner::IsVarious()
{
	return true;
}

bool CRandomChoiceSpawner::IsVarious()
{
	return true;
}


int IPopulationSpawner::GetClass(int index)
{
	return 0;
}

int CTFBotSpawner::GetClass(int index)
{
	return this->m_iClass;
}

int CSquadSpawner::GetClass(int index)
{
	if (index < 0 || this->m_SubSpawners.IsEmpty()) {
		return TF_CLASS_UNKNOWN;
	}
	
	index %= this->m_SubSpawners.Count();
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	
	if (!spawner->IsVarious()) {
		return spawner->GetClass(-1);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return TF_CLASS_UNKNOWN;
	}
}

int CRandomChoiceSpawner::GetClass(int index)
{
	if (index < 0) {
		return TF_CLASS_UNKNOWN;
	}
	
	this->GenerateRandomIndexes(index);
	
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	if (!spawner->IsVarious()) {
		return spawner->GetClass(-1);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return TF_CLASS_UNKNOWN;
	}
}


string_t IPopulationSpawner::GetClassIcon(int index)
{
	return NULL_STRING;
}

string_t CTankSpawner::GetClassIcon(int index)
{
	return MAKE_STRING("tank");
}

string_t CTFBotSpawner::GetClassIcon(int index)
{
	if (!this->m_strClassIcon) {
		return AllocPooledString(g_aRawPlayerClassNamesShort[this->m_iClass]);
	} else {
		return this->m_strClassIcon;
	}
}

string_t CSquadSpawner::GetClassIcon(int index)
{
	if (index < 0 || this->m_SubSpawners.IsEmpty()) {
		return NULL_STRING;
	}
	
	index %= this->m_SubSpawners.Count();
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	
	if (!spawner->IsVarious()) {
		return spawner->GetClassIcon(-1);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return NULL_STRING;
	}
}

string_t CRandomChoiceSpawner::GetClassIcon(int index)
{
	if (index < 0) {
		return NULL_STRING;
	}
	
	this->GenerateRandomIndexes(index);
	
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	if (!spawner->IsVarious()) {
		return spawner->GetClassIcon(-1);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return NULL_STRING;
	}
}


int IPopulationSpawner::GetHealth(int index)
{
	return 0;
}

int CTankSpawner::GetHealth(int index)
{
	return m_iHealth;
}

int CTFBotSpawner::GetHealth(int index)
{
	return m_iHealth;
}

int CSquadSpawner::GetHealth(int index)
{
	if (index < 0 || this->m_SubSpawners.IsEmpty()) {
		return 0;
	}
	
	index %= this->m_SubSpawners.Count();
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	
	if (!spawner->IsVarious()) {
		return spawner->GetHealth(-1);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return 0;
	}
}

int CRandomChoiceSpawner::GetHealth(int index)
{
	if (index < 0) {
		return 0;
	}
	
	this->GenerateRandomIndexes(index);
	
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	if (!spawner->IsVarious()) {
		return spawner->GetHealth(-1);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return 0;
	}
}


bool IPopulationSpawner::IsMiniBoss()
{
	return false;
}

bool CTankSpawner::IsMiniBoss()
{
	return true;
}

bool CTFBotSpawner::IsMiniBoss()
{
	return ((this->m_DefaultAttrs.m_nBotAttrs & BOT_ATTRIBUTES_MINIBOSS) != 0);
}

bool CSquadSpawner::IsMiniBoss()
{
	if (index < 0 || this->m_SubSpawners.IsEmpty()) {
		return false;
	}
	
	index %= this->m_SubSpawners.Count();
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	
	if (!spawner->IsVarious()) {
		return spawner->IsMiniBoss(-1);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return false;
	}
}

bool CRandomChoiceSpawner::IsMiniBoss()
{
	if (index < 0) {
		return false;
	}
	
	this->GenerateRandomIndexes(index);
	
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	if (!spawner->IsVarious()) {
		return spawner->IsMiniBoss(-1);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return false;
	}
}


bool IPopulationSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	return false;
}

bool CTFBotSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	return ((this->m_DefaultAttrs.m_nBotAttrs & attr) != 0);
}

bool CSquadSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	if (index < 0 || this->m_SubSpawners.IsEmpty()) {
		return false;
	}
	
	index %= this->m_SubSpawners.Count();
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	
	if (!spawner->IsVarious()) {
		/* likely bug: passing index thru to the sub-spawner (rather than -1) */
		return spawner->HasAttribute(attr, index);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return false;
	}
}

bool CRandomChoiceSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	if (index < 0) {
		return false;
	}
	
	this->GenerateRandomIndexes(index);
	
	IPopulationSpawner *spawner = this->m_SubSpawners[index];
	if (!spawner->IsVarious()) {
		/* likely bug: passing index thru to the sub-spawner (rather than -1) */
		return spawner->HasAttribute(attr, index);
	} else {
		DevWarning("Nested complex spawner types... need a method for counting these.");
		return false;
	}
}


bool CMobSpawner::HasEventChangeAttributes(const char *name) const
{
	if (this->m_SubSpawner != NULL) {
		return this->m_SubSpawner->HasEventChangeAttributes(name);
	} else {
		return false;
	}
}

bool CSentryGunSpawner::HasEventChangeAttributes(const char *name) const
{
	return false;
}

bool CTankSpawner::HasEventChangeAttributes(const char *name) const
{
	return false;
}

bool CTFBotSpawner::HasEventChangeAttributes(const char *name) const
{
	FOR_EACH_VEC(this->m_ECAttrs, i) {
		CTFBot::EventChangeAttributes_t& ecattr = this->m_ECAttrs[i];
		
		const char *ecname = ecattr.m_strName.Get();
		if (name == ecname || V_stricmp(name, ecname) == 0) {
			return true;
		}
	}
	
	return false;
}

bool CSquadSpawner::HasEventChangeAttributes(const char *name) const
{
	FOR_EACH_VEC(this->m_SubSpawners, i) {
		if (this->m_SubSpawners[i]->HasEventChangeAttributes(name)) {
			return true;
		}
	}
	
	return false;
}

bool CRandomChoiceSpawner::HasEventChangeAttributes(const char *name) const
{
	/* weird: this function still recurses over the sub-spawners, yet it always
	 * returns false regardless */
	
	FOR_EACH_VEC(this->m_SubSpawners, i) {
		(void)this->m_SubSpawners[i]->HasEventChangeAttributes(name);
	}
	
	return false;
}


IPopulationSpawner *IPopulationSpawner::ParseSpawner(IPopulator *populator, KeyValues *kv)
{
	const char *name = kv->GetName();
	if (strlen(name) <= 0) {
		return NULL;
	}
	
	IPopulationSpawner* spawner;
	if (V_stricmp(name, "TFBot") == 0) {
		spawner = new CTFBotSpawner(this);
		if (spawner->Parse(populator)) {
			return spawner;
		} else {
			Warning("Warning reading TFBot spawner definition\n");
		}
	} else if (V_stricmp(name, "Tank") == 0) {
		spawner = new TankSpawner(this);
		if (spawner->Parse(populator)) {
			return spawner;
		} else {
			Warning("Warning reading Tank spawner definition\n");
		}
	} else if (V_stricmp(name, "SentryGun") == 0) {
		spawner = new CSentryGunSpawner(this);
		if (spawner->Parse(populator)) {
			return spawner;
		} else {
			Warning("Warning reading SentryGun spawner definition\n");
		}
	} else if (V_stricmp(name, "Squad") == 0) {
		spawner = new CSquadSpawner(this);
		if (spawner->Parse(populator)) {
			return spawner;
		} else {
			Warning("Warning reading Squad spawner definition\n");
		}
	} else if (V_stricmp(name, "Mob") == 0) {
		spawner = new CMobSpawner(this);
		if (spawner->Parse(populator)) {
			return spawner;
		} else {
			Warning("Warning reading Mob spawner definition\n");
		}
	} else if (V_stricmp(name, "RandomChoice") == 0) {
		spawner = new CRandomChoiceSpawner(this);
		if (spawner->Parse(populator)) {
			return spawner;
		} else {
			Warning("Warning reading RandomChoice spawner definition\n");
		}
	}
	
	delete spawner;
	return NULL;
}


bool CTFBotSpawner::ParseEventChangeAttributes(KeyValues *kv)
{
	if (kv == NULL) {
		return true;
	}
	
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		
		this->m_ECAttrs.AddToTail();
		CTFBot::EventChangeAttributes_t& ecattr = this->m_ECAttrs.Tail();
		ecattr.m_strName = name;
		
		FOR_EACH_SUBKEY(subkey, subsubkey) {
			if (!ParseDynamicAttributes(ecattr, subsubkey)) {
				Warning("TFBotSpawner EventChangeAttributes: Failed to parse event '%s' with unknown attribute '%s'\n",
					subkey->GetName(), subsubkey->GetName());
				return false;
			}
		}
		
		if (V_stricmp(name, "default") == 0) {
			/* use the default copy constructor */
			this->m_DefaultAttrs = ecattr;
		}
	}
	
	return true;
}


void CRandomChoiceSpawner::GenerateRandomIndexes(int index)
{
	/* ensure that m_Indexes has been random generated at least enough so that
	 * an access to m_Indexes[index] can succeed */
	
	int size_before = this->m_Indexes.Count();
	int size_wanted = (index + 1);
	
	int size_growby = size_wanted - size_before;
	if (size_growby > 0) {
		this->m_Indexes.AddMultipleToTail(size_growby);
		
		for (int i = size_before; i < size_wanted; ++i) {
			this->m_Indexes[i] = RandomInt(0, this->m_SubSpawners.Count() - 1);
		}
	}
}


// fastcall
// eax: ecattr
// edx: kv
bool ParseDynamicAttributes(CTFBot::EventChangeAttributes_t& ecattr, KeyValues *kv)
{
	const char *name = kv->GetName();
	
	if (V_stricmp(name, "Skill") == 0) {
		const char *val = kv->GetString(NULL);
		
		if (V_stricmp(val, "Easy") == 0) {
			ecattr.m_iSkill = BOT_SKILL_EASY;
		} else if (V_stricmp(val, "Normal") == 0) {
			ecattr.m_iSkill = BOT_SKILL_NORMAL;
		} else if (V_stricmp(val, "Hard") == 0) {
			ecattr.m_iSkill = BOT_SKILL_HARD;
		} else if (V_stricmp(val, "Expert") == 0) {
			ecattr.m_iSkill = BOT_SKILL_EXPERT;
		} else {
			Warning("TFBotSpawner: Invalid skill '%s'\n", val);
			return false;
		}
		
		return true;
	}
	
	if (V_stricmp(name, "WeaponRestrictions") == 0) {
		const char *val = kv->GetString(NULL);
		
		if (V_stricmp(val, "MeleeOnly") == 0) {
			ecattr.m_nWeaponRestrict = BOT_RESTRICT_MELEEONLY;
		} else if (V_stricmp(val, "PrimaryOnly") == 0) {
			ecattr.m_nWeaponRestrict = BOT_RESTRICT_PRIMARYONLY;
		} else if (V_stricmp(val, "SecondaryOnly") == 0) {
			ecattr.m_nWeaponRestrict = BOT_RESTRICT_SECONDARYONLY;
		} else {
			Warning("TFBotSpawner: Invalid weapon restriction '%s'\n", val);
			return false;
		}
		
		return true;
	}
	
	if (V_stricmp(name, "BehaviorModifiers") == 0) {
		const char *val = kv->GetString(NULL);
		
		if (V_stricmp(val, "Mobber") == 0 ||
			V_stricmp(val, "Push") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_AGGRESSIVE;
		} else {
			Warning("TFBotSpawner: invalid behavior modifier '%s'\n", val);
			return false;
		}
		
		return true;
	}
	
	if (V_stricmp(name, "MaxVisionRange") == 0) {
		ecattr.m_flVisionRange = kv->GetFloat(NULL);
		return true;
	}
	
	if (V_stricmp(name, "Item") == 0) {
		ecattr.m_ItemNames.CopyAndAddToTail(kv->GetString(NULL));
		return true;
	}
	
	if (V_stricmp(name, "Tag") == 0) {
		ecattr.m_Tags.CopyAndAddToTail(kv->GetString(NULL));
		return true;
	}
	
	if (V_stricmp(name, "Attributes") == 0) {
		const char *val = kv->GetString(NULL);
		
		if (V_stricmp(val, "RemoveOnDeath") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_REMOVEONDEATH;
		} else if (V_stricmp(val, "Aggressive") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_AGGRESSIVE;
		} else if (V_stricmp(val, "SuppressFire") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_SUPPRESSFIRE;
		} else if (V_stricmp(val, "DisableDodge") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_DISABLEDODGE;
		} else if (V_stricmp(val, "BecomeSpectatorOnDeath") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_BECOMESPECTATORONDEATH;
		} else if (V_stricmp(val, "RetainBuildings") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_RETAINBUILDINGS;
		} else if (V_stricmp(val, "SpawnWithFullCharge") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_SPAWNWITHFULLCHARGE;
		} else if (V_stricmp(val, "AlwaysCrit") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_ALWAYSCRIT;
		} else if (V_stricmp(val, "IgnoreEnemies") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_IGNOREENEMIES;
		} else if (V_stricmp(val, "HoldFireUntilFullReload") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_HOLDFIREUNTILFULLRELOAD;
		} else if (V_stricmp(val, "AlwaysFireWeapon") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_ALWAYSFIREWEAPON;
		} else if (V_stricmp(val, "TeleportToHint") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_TELEPORTTOHINT;
		} else if (V_stricmp(val, "MiniBoss") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_MINIBOSS;
		} else if (V_stricmp(val, "UseBossHealthBar") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_USEBOSSHEALTHBAR;
		} else if (V_stricmp(val, "IgnoreFlag") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_IGNOREFLAG;
		} else if (V_stricmp(val, "AutoJump") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_AUTOJUMP;
		} else if (V_stricmp(val, "AirChargeOnly") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_AIRCHARGEONLY;
		} else if (V_stricmp(val, "VaccinatorBullets") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_VACCINATORBULLETS;
		} else if (V_stricmp(val, "VaccinatorBlast") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_VACCINATORBLAST;
		} else if (V_stricmp(val, "VaccinatorFire") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_VACCINATORFIRE;
		} else if (V_stricmp(val, "BulletImmune") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_BULLETIMMUNE;
		} else if (V_stricmp(val, "BlastImmune") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_BLASTIMMUNE;
		} else if (V_stricmp(val, "FireImmune") == 0) {
			ecattr.m_nBotAttrs |= BOT_ATTRIBUTES_FIREIMMUNE;
		} else {
			Warning("TFBotSpawner: Invalid attribute '%s'\n", val);
			return false;
		}
		
		return true;
	}
	
	if (V_stricmp(name, "CharacterAttributes") == 0) {
		CUtlVector<static_attrib_t> attrs;
		
		FOR_EACH_SUBKEY(kv, subkey) {
			static_attrib_t attr;
			CUtlVectorAutoPurge<CUtlString> errors;
			
			if (attr.BInitFromKV_SingleLine("CharacterAttributes",
				subkey, &errors, true)) {
				attrs.AddToHead(attr);
			} else {
				FOR_EACH_VEC(errors, i) {
					Warning("TFBotSpawner: attribute error: '%s'\n",
						errors[i].Get());
				}
			}
		}
		
		FOR_EACH_VEC(attrs, i) {
			static_attrib_t& attr_new = attrs[i];
			
			/* if the same character attribute is specified again, find the
			 * existing entry and overwrite the value */
			bool found_old = false;
			FOR_EACH_VEC(ecattr.m_CharAttrs, j) {
				static_attrib_t& attr_old = ecattr.m_CharAttrs[j];
				
				if (attr_new.m_iAttrIndex == attr_old.m_iAttrIndex) {
					attr_old.m_Value = attr_new.m_Value;
					
					found_old = true;
					break;
				}
			}
			
			if (!found_old) {
				ecattr.m_CharAttrs.AddToHead(attr_new);
			}
		}
		
		return true;
	}
	
	if (V_stricmp(name, "ItemAttributes") == 0) {
		const char *item_name = NULL;
		CUtlVector<static_attrib_t> attrs;
		
		FOR_EACH_SUBKEY(kv, subkey) {
			if (V_stricmp(subkey->GetName(NULL), "ItemName") == 0) {
				if (item_name == NULL) {
					item_name = subkey->GetString(NULL);
				} else {
					Warning("TFBotSpawner: \"ItemName\" field specified multiple times ('%s' / '%s').\n",
						item_name, subkey->GetString(NULL));
				}
			} else {
				static_attrib_t attr;
				CUtlVectorAutoPurge<CUtlString> errors;
				
				if (attr.BInitFromKV_SingleLine("ItemAttributes",
					subkey, &errors, true)) {
					attrs.AddToHead(attr);
				} else {
					FOR_EACH_VEC(errors, i) {
						Warning("TFBotSpawner: attribute error: '%s'\n",
							errors[i].Get());
					}
				}
			}
		}
		
		if (item_name == NULL) {
			Warning("TFBotSpawner: need to specify ItemName in ItemAttributes.\n");
		} else {
			FOR_EACH_VEC(attrs, i) {
				static_attrib_t& attr_new = attrs[i];
				
				/* check if we already have an attr list for this item */
				bool found_item_old = false;
				FOR_EACH_VEC(ecattr.m_ItemAttrs, j) {
					CTFBot::EventChangeAttributes_t::item_attributes_t& item_old = ecattr.m_ItemAttrs[j];
					
					if (V_stricmp(item_old.strItemName, item_name) == 0) {
						/* check if we already have an attr list entry for this
						 * attribute on this item */
						bool found_attr_old = false;
						FOR_EACH_VEC(item_old.m_Attrs, k) {
							static_attrib_t& attr_old = item_old.m_Attrs[k];
							
							if (attr_new.m_iAttrIndex == attr_old.m_iAttrIndex) {
								attr_old.m_Value = attr_new.m_Value;
								
								found_attr_old = true;
								break;
							}
						}
						
						if (!found_attr_old) {
							item_old.m_Attrs.AddToHead(attr_new);
						}
						
						found_item_old = true;
						break;
					}
				}
				
				if (!found_item_old) {
					CTFBot::EventChangeAttributes_t::item_attributes_t item_new;
					item_new.m_strItemName = item_name;
					item_new.m_Attrs.AddToHead(attr_new);
					
					ecattr.m_ItemAttrs.AddToTail(item_new);
				}
			}
		}
		
		return true;
	}
	
	return false;
}
