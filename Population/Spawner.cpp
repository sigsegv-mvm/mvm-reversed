/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: spawners
 */


CMobSpawner::CMobSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	m_iCount     = 0;
	m_SubSpawner = NULL;
	
	// TODO
}

CSentryGunSpawner::CSentryGunSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	m_iLevel = 0;
}

CTankSpawner::CTankSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	m_iHealth             = 50000;
	m_flSpeed             = 75.0f;
	m_strName             = "Tank";
	m_strStartNode        = NULL;
	m_iSkin               = 0;
	m_OnKilledOutput      = NULL;
	m_OnBombDroppedOutput = NULL;
}

CTFBotSpawner::CTFBotSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	// TODO
	
	// there's some exception handling in here...
}

CSquadSpawner::CSquadSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	// TODO
}

CRandomChoiceSpawner::CRandomChoiceSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	// TODO
}


bool CMobSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			IPopulationSpawner *spawner;
			
			if (V_stricmp(name, "Count") == 0) {
				this->m_iCount = subkey->GetInt(NULL);
			} else if ((spawner = IPopulationSpawner::ParseSpawner(this->m_Populator, subkey)) != NULL) {
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
	this->m_iClass = TFCLASS_UNKNOWN;
	this->m_strClassIcon = NULL_STRING;
	this->m_iHealth = -1;
	this->m_flScale = -1.0f;
	this->m_flAutoJumpMax = 0.0f;
	this->m_flAutoJumpMin = 0.0f;
	
	// CUtlString* @ ebp-0x24: reference to this+0x38 (???)
	// gets set to "default"
	
	// initialize this->
	// 0x3c
	// 0x40
	// 0x44
	// 0x48
	// 0x4c
	// 0x50
	// 0x60
	
	this->m_ItemAttrs.RemoveAll();
	
	// initialize this->
	// 0x88
	// 0x9c
	
	this->m_Attrs.RemoveAll();
	
	
	// BEFORE THE FOREACH,
	// it specifically searches for any Template keys
	// then, in the foreach, it SPECIFICALLY IGNORES template keys
	// (i.e. an empty case, no error)
	
	
	// CUtlString* @ ebp-0x28: reference to this+0x20 (Name)
	// CUtlString* @ ebp-0x2c: reference to this+0x24 (Teleport)
	
	
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Template") == 0) {
				// TODO: template stuff
				// on template KV found: call this->Parse(other_kv) and check result
				// on failure: Warning("Unknown template etc")
			} else if (V_stricmp(name, "Class") == 0) {
				const char *str = subkey->GetString(NULL);
				if ((this->m_iClass = GetClassIndexFromString(str, 10)) !=
					TFCLASS_UNKNOWN) {
					// TODO
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
				// TODO
			} else if (V_stricmp(name, "Teleport") == 0) {
				// TODO
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
					if (!ParseDynamicAttributes(/* TODO */)) {
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
	// TODO
}

bool CRandomChoiceSpawner::Parse(KeyValues *kv)
{
	// TODO
}


bool CMobSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CSentryGunSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CTankSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CTFBotSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CSquadSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CRandomChoiceSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
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
	// TODO
}

int CSquadSpawner::GetClass(int index)
{
	// TODO
}

int CRandomChoiceSpawner::GetClass(int index)
{
	// TODO
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
	// TODO
}

string_t CSquadSpawner::GetClassIcon(int index)
{
	// TODO
}

string_t CRandomChoiceSpawner::GetClassIcon(int index)
{
	// TODO
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
	// TODO
}

int CRandomChoiceSpawner::GetHealth(int index)
{
	// TODO
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
	// TODO
	// returns byte at this+0x283c (probably player->m_Shared.m_bIsMiniBoss or however that's accessed)
}

bool CSquadSpawner::IsMiniBoss()
{
	// TODO
}

bool CRandomChoiceSpawner::IsMiniBoss()
{
	// TODO
}


bool IPopulationSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	return false;
}

bool CTFBotSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	// TODO
}

bool CSquadSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	// TODO
}

bool CRandomChoiceSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	// TODO
}


bool CMobSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
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
	// TODO
}

bool CSquadSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
}

bool CRandomChoiceSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
}


IPopulationSpawner *IPopulationSpawner::ParseSpawner(IPopulator *populator, KeyValues *kv)
{
	// TODO
}


bool CTFBotSpawner::ParseEventChangeAttributes(KeyValues *kv)
{
	if (kv == NULL) {
		return true;
	}
	
	// ebp+0x28: ptr to this->m_ItemAttrs
	// ebp+0x2c: ptr to CUtlString @ this+0x38
	// ebp+0x30: ptr to CUtlStringList @ this+0x54
	
	FOR_EACH_SUBKEY(kv, subkey) {
		
	}
	
	// TODO
}


/* weird calling convention: attr in eax, kv in edx */
bool ParseDynamicAttributes(CTFBot::EventChangeAttributes_t& attr, KeyValues *kv)
{
	const char *name = kv->GetName();
	
	if (V_stricmp(name, "Skill") == 0) {
		const char *val = kv->GetString(NULL);
		
		if (V_stricmp(val, "Easy") == 0) {
			attr.m_iSkill = BOT_SKILL_EASY;
		} else if (V_stricmp(val, "Normal") == 0) {
			attr.m_iSkill = BOT_SKILL_NORMAL;
		} else if (V_stricmp(val, "Hard") == 0) {
			attr.m_iSkill = BOT_SKILL_HARD;
		} else if (V_stricmp(val, "Expert") == 0) {
			attr.m_iSkill = BOT_SKILL_EXPERT;
		} else {
			Warning("TFBotSpawner: Invalid skill '%s'\n", val);
			return false;
		}
		
		return true;
	}
	
	if (V_stricmp(name, "WeaponRestrictions") == 0) {
		const char *val = kv->GetString(NULL);
		
		if (V_stricmp(val, "MeleeOnly") == 0) {
			attr.m_nWeaponRestrict = BOT_RESTRICT_MELEEONLY;
		} else if (V_stricmp(val, "PrimaryOnly") == 0) {
			attr.m_nWeaponRestrict = BOT_RESTRICT_PRIMARYONLY;
		} else if (V_stricmp(val, "SecondaryOnly") == 0) {
			attr.m_nWeaponRestrict = BOT_RESTRICT_SECONDARYONLY;
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
			attr.m_nAttributes |= BOT_ATTRIBUTES_AGGRESSIVE;
		} else {
			Warning("TFBotSpawner: invalid behavior modifier '%s'\n", val);
			return false;
		}
		
		return true;
	}
	
	if (V_stricmp(name, "MaxVisionRange") == 0) {
		attr.m_flVisionRange = kv->GetFloat(NULL);
		return true;
	}
	
	if (V_stricmp(name, "Item") == 0) {
		attr.m_ItemNames.CopyAndAddToTail(kv->GetString(NULL));
		return true;
	}
	
	if (V_stricmp(name, "Tag") == 0) {
		attr.m_Tags.CopyAndAddToTail(kv->GetString(NULL));
		return true;
	}
	
	if (V_stricmp(name, "Attributes") == 0) {
		const char *val = kv->GetString(NULL);
		
		if (V_stricmp(val, "RemoveOnDeath") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_REMOVEONDEATH;
		} else if (V_stricmp(val, "Aggressive") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_AGGRESSIVE;
		} else if (V_stricmp(val, "SuppressFire") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_SUPPRESSFIRE;
		} else if (V_stricmp(val, "DisableDodge") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_DISABLEDODGE;
		} else if (V_stricmp(val, "BecomeSpectatorOnDeath") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_BECOMESPECTATORONDEATH;
		} else if (V_stricmp(val, "RetainBuildings") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_RETAINBUILDINGS;
		} else if (V_stricmp(val, "SpawnWithFullCharge") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_SPAWNWITHFULLCHARGE;
		} else if (V_stricmp(val, "AlwaysCrit") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_ALWAYSCRIT;
		} else if (V_stricmp(val, "IgnoreEnemies") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_IGNOREENEMIES;
		} else if (V_stricmp(val, "HoldFireUntilFullReload") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_HOLDFIREUNTILFULLRELOAD;
		} else if (V_stricmp(val, "AlwaysFireWeapon") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_ALWAYSFIREWEAPON;
		} else if (V_stricmp(val, "TeleportToHint") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_TELEPORTTOHINT;
		} else if (V_stricmp(val, "MiniBoss") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_MINIBOSS;
		} else if (V_stricmp(val, "UseBossHealthBar") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_USEBOSSHEALTHBAR;
		} else if (V_stricmp(val, "IgnoreFlag") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_IGNOREFLAG;
		} else if (V_stricmp(val, "AutoJump") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_AUTOJUMP;
		} else if (V_stricmp(val, "AirChargeOnly") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_AIRCHARGEONLY;
		} else if (V_stricmp(val, "VaccinatorBullets") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_VACCINATORBULLETS;
		} else if (V_stricmp(val, "VaccinatorBlast") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_VACCINATORBLAST;
		} else if (V_stricmp(val, "VaccinatorFire") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_VACCINATORFIRE;
		} else if (V_stricmp(val, "BulletImmune") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_BULLETIMMUNE;
		} else if (V_stricmp(val, "BlastImmune") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_BLASTIMMUNE;
		} else if (V_stricmp(val, "FireImmune") == 0) {
			attr.m_nAttributes |= BOT_ATTRIBUTES_FIREIMMUNE;
		} else {
			Warning("TFBotSpawner: Invalid attribute '%s'\n", val);
			return false;
		}
		
		return true;
	}
	
	if (V_stricmp(name, "CharacterAttributes") == 0) {
		CUtlVector<static_attrib_t> v1;
		CUtlVector<static_attrib_t> v2;
		
		FOR_EACH_SUBKEY(kv, subkey) {
			
		}
	}
	
	if (V_stricmp(name, "ItemAttributes") == 0) {
		
	}
	
	return false;
}
