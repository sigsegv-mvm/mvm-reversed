/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Population: populators
 */


IPopulator::IPopulator(CPopulationManager *popmgr)
	: m_PopMgr(popmgr)
{
}

CRandomPlacementPopulator::CRandomPlacementPopulator(CPopulationManager *popmgr)
	: IPopulator(popmgr)
{
	this->m_iCount = 0;
	this->m_flMinimumSeparation = 0.0f;
	// TODO
}

CPeriodicSpawnPopulator::CPeriodicSpawnPopulator(CPopulationManager *popmgr)
	: IPopulator(popmgr)
{
	this->m_flMinInterval = 30.0f;
	this->m_flMaxInterval = 30.0f;
}

CMissionPopulator::CMissionPopulator(CPopulationManager *popmgr)
	: IPopulator(popmgr)
{
	// TODO
	this->m_flInitialCooldown  = 0.0f;
	this->m_flCooldownTime     = 0.0f;
	this->m_iDesiredCount      = 0;
	this->m_iBeginAtWave       = 0;
	this->m_iEndBeforeThisWave = 9999;
	// TODO
}

CWaveSpawnPopulator::CWaveSpawnPopulator(CPopulationManager *popmgr)
	: IPopulator(popmgr)
{
	// TODO
}

CWave::CWave(CPopulationManager *popmgr)
	: IPopulator(popmgr)
{
	// TODO
}


IPopulator::~IPopulator()
{
	if (this->m_Spawner != nullptr) {
		delete this->m_Spawner;
	}
}

CRandomPlacementPopulator::~CRandomPlacementPopulator()
{
}

CPeriodicSpawnPopulator::~CPeriodicSpawnPopulator()
{
}

CMissionPopulator::~CMissionPopulator()
{
}

CWaveSpawnPopulator::~CWaveSpawnPopulator()
{
	// TODO
}

CWave::~CWave()
{
	// TODO
}


bool CRandomPlacementPopulator::Parse(KeyValues *kv)
{
	// TODO
}

bool CPeriodicSpawnPopulator::Parse(KeyValues *kv)
{
	// TODO
}

bool CMissionPopulator::Parse(KeyValues *kv)
{
	int runforthismanywaves = 99999;
	
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) <= 0) {
			continue;
		}
		
		if (this->m_Where->Parse(subkey)) {
			continue;
		}
		
		if (V_stricmp(name, "Objective") == 0) {
			if (V_stricmp(subkey->GetString(), "DestroySentries") == 0 ||
				V_stricmp(subkey->GetString(), "SeekAndDestroy") == 0) {
				this->m_Objective = CTFBot::MissionType::DESTROY_SENTRIES;
			} else if (V_stricmp(subkey->GetString(), "Sniper") == 0) {
				this->m_Objective = CTFBot::MissionType::SNIPER;
			} else if (V_stricmp(subkey->GetString(), "Spy") == 0) {
				this->m_Objective = CTFBot::MissionType::SPY;
			} else if (V_stricmp(subkey->GetString(), "Engineer") == 0) {
				this->m_Objective = CTFBot::MissionType::ENGINEER;
			} else {
				Warning("Invalid mission '%s'\n", subkey->GetString());
				return false;
			}
		} else if (V_stricmp(name, "InitialCooldown") == 0) {
			this->m_flInitialCooldown = subkey->GetFloat();
		} else if (V_stricmp(name, "CooldownTime") == 0) {
			this->m_flCooldownTime = subkey->GetFloat();
		} else if (V_stricmp(name, "BeginAtWave") == 0) {
			this->m_iBeginAtWave = subkey->GetInt();
		} else if (V_stricmp(name, "RunForThisManyWaves") == 0) {
			runforthismanywaves = subkey->GetInt();
		} else if (V_stricmp(name, "DesiredCount") == 0) {
			this->m_iDesiredCount = subkey->GetInt();
		} else {
			/* BUG: duplicate spawner definitions will leak memory */
			this->m_Spawner =
				IPopulationSpawner::ParseSpawner(this, subkey);
			if (this->m_Spawner == nullptr) {
				Warning("Unknown attribute '%s' in Mission definition.\n",
					name);
			}
		}
	}
	
	this->m_iEndBeforeThisWave = this->m_iBeginAtWave + runforthismanywaves;
	
	return true;
}

bool CWaveSpawnPopulator::Parse(KeyValues *kv)
{
	/* handle the template reference (if any) before doing anything else */
	KeyValues *kv_tref = kv->FindKey("Template");
	if (kv_tref != nullptr) {
		const char *tname = kv_tref->GetString();
		
		KeyValues *kv_timpl =
			this->m_Populator->m_PopMgr->m_kvTemplates->FindKey(tname);
		if (kv_timpl != nullptr) {
			if (!this->Parse(kv_timpl)) {
				return false;
			}
		} else {
			Warning("Unknown Template '%s' in WaveSpawn definition\n",
				tname);
		}
	}
	
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) <= 0) {
			continue;
		}
		
		if (this->m_Where->Parse(subkey)) {
			continue;
		}
		
		if (V_stricmp(name, "Template") == 0) {
			continue;
		}
		
		if (V_stricmp(name, "TotalCount") == 0) {
			this->m_iTotalCount = subkey->GetInt();
		} else if (V_stricmp(name, "MaxActive") == 0) {
			this->m_iMaxActive = subkey->GetInt();
		} else if (V_stricmp(name, "SpawnCount") == 0) {
			this->m_iSpawnCount = subkey->GetInt();
		} else if (V_stricmp(name, "WaitBeforeStarting") == 0) {
			this->m_flWaitBeforeStarting = subkey->GetFloat();
		} else if (V_stricmp(name, "WaitBetweenSpawns") == 0) {
			if (this->m_flWaitBetweenSpawns == 0.0f ||
				!this->m_bWaitBetweenSpawnsAfterDeath) {
				this->m_flWaitBetweenSpawns = subkey->GetFloat();
			} else {
				Warning("Already specified WaitBetweenSpawnsAfterDeath time, WaitBetweenSpawns won't be used\n");
				continue;
			}
		} else if (V_stricmp(name, "WaitBetweenSpawnsAfterDeath") == 0) {
			if (this->m_flWaitBetweenSpawns == 0.0f) {
				this->m_bWaitBetweenSpawnsAfterDeath = true;
				this->m_flWaitBetweenSpawns = subkey->GetFloat();
			} else {
				Warning("Already specified WaitBetweenSpawns time, WaitBetweenSpawnsAfterDeath won't be used\n");
				continue;
			}
		} else if (V_stricmp(name, "StartWaveWarningSound") == 0) {
			this->m_strStartWaveWarningSound.sprintf("%s",
				subkey->GetString());
		} else if (V_stricmp(name, "StartWaveOutput") == 0) {
			this->m_StartWaveOutput = ParseEvent(subkey);
		} else if (V_stricmp(name, "FirstSpawnWarningSound") == 0) {
			this->m_strFirstSpawnWarningSound.sprintf("%s",
				subkey->GetString());
		} else if (V_stricmp(name, "FirstSpawnOutput") == 0) {
			this->m_FirstSpawnOutput = ParseEvent(subkey);
		} else if (V_stricmp(name, "LastSpawnWarningSound") == 0) {
			this->m_strLastSpawnWarningSound.sprintf("%s",
				subkey->GetString());
		} else if (V_stricmp(name, "LastSpawnOutput") == 0) {
			this->m_LastSpawnOutput = ParseEvent(subkey);
		} else if (V_stricmp(name, "DoneWarningSound") == 0) {
			this->m_strDoneWarningSound.sprintf("%s",
				subkey->GetString());
		} else if (V_stricmp(name, "DoneOutput") == 0) {
			this->m_DoneOutput = ParseEvent(subkey);
		} else if (V_stricmp(name, "TotalCurrency") == 0) {
			this->m_iTotalCurrency = subkey->GetInt();
		} else if (V_stricmp(name, "Name") == 0) {
			this->m_strName = subkey->GetString();
		} else if (V_stricmp(name, "WaitForAllSpawned") == 0) {
			this->m_strWaitForAllSpawned = subkey->GetString();
		} else if (V_stricmp(name, "WaitForAllDead") == 0) {
			this->m_strWaitForAllDead = subkey->GetString();
		} else if (V_stricmp(name, "Support") == 0) {
			this->m_bSupport = true;
			this->m_bSupportLimited =
				(V_stricmp(subkey->GetString(), "Limited") == 0);
		} else if (V_stricmp(name, "RandomSpawn") == 0) {
			this->m_bRandomSpawn = subkey->GetBool();
		} else {
			this->m_Spawner = IPopulationSpawner::ParseSpawner(this, subkey);
			if (this->m_Spawner == nullptr) {
				Warning("Unknown attribute '%s' in WaveSpawn definition.\n",
					name);
			}
		}
		
		this->m_iCountNotYetSpawned = this->m_iTotalCount;
		this->m_iCurrencyLeft = this->m_iTotalCurrency;
	}
	
	return true;
}

bool CWave::Parse(KeyValues *kv)
{
	// TODO
	
	// this is the function responsible for adding up class types
	// (it should be using a recursive algorithm but isn't)
}


void IPopulator::PostInitialize()
{
}

void CRandomPlacementPopulator::PostInitialize()
{
	// TODO
}

void CPeriodicSpawnPopulator::PostInitialize()
{
	// TODO
}


void IPopulator::Update()
{
}

void CPeriodicSpawnPopulator::Update()
{
	// TODO
}

void CMissionPopulator::Update()
{
	VPROF_BUDGET("CMissionPopulator::Update", "NextBot");
	
	if (!TFGameRules()->IsMannVsMachineMode()) {
		this->m_iState = State::NOT_STARTED;
		return;
	}
	
	int wavenum = this->m_PopMgr->m_iCurrentWave;
	if (wavenum < this->m_iBeginAtWave ||
		wavenum >= this->m_iEndBeforeThisWave) {
		this->m_iState = State::NOT_STARTED;
		return;
	}
	
	if (TFObjectiveResource()->GetMannVsMachineIsBetweenWaves()) {
		this->m_iState = State::NOT_STARTED;
		return;
	}
	
	if (this->m_iState == State::NOT_STARTED) {
		if (this->m_flInitialCooldown != 0.0f) {
			this->m_iState = State::INITIAL;
			this->m_ctTimer1.Start(this->m_flInitialCooldown);
			return;
		}
	} else if (this->m_iState == State::INITIAL) {
		if (!this->m_ctTimer1.IsElapsed()) {
			return;
		}
		
		this->m_iState = State::RUNNING;
		this->m_ctTimer1.Invalidate();
	}
	
	CTFBot::MissionType objective = this->m_Objective;
	if (objective == CTFBot::MissionType::DESTROY_SENTRIES) {
		this->UpdateMissionDestroySentries();
	} else {
		if (objective < CTFBot::MissionType::DESTROY_SENTRIES) {
			return;
		} else if (objective > CTFBot::MissionType::ENGINEER) {
			return;
		}
		
		this->UpdateMission(objective);
	}
}

void CWaveSpawnPopulator::Update()
{
	VPROF_BUDGET("CWaveSpawnPopulator::Update", "NextBot");
	
	switch (this->m_iState) {
		
	case InternalStateType::INITIAL:
		this->m_ctPreSpawnDelay.Start(this->m_flWaitBeforeStarting);
		this->m_reservedPlayerSlotCount = 0;
		this->SetState(InternalStateType::PRE_SPAWN_DELAY);
		return;
		
	case InternalStateType::PRE_SPAWN_DELAY:
		if (this->m_ctPreSpawnDelay.IsElapsed()) {
			// TODO: field_4b8 = 0
			// TODO: field_4bc = 0
			this->SetState(InternalStateType::SPAWNING);
		}
		return;
		
	case InternalStateType::SPAWNING:
		if (!this->m_ctPreSpawnDelay.IsElapsed() ||
			g_pPopulationManager->m_bIsPaused) {
			return;
		}
		
		int num_active = 0;
		FOR_EACH_VEC(this->m_ActiveBots, i) {
			CBaseEntity *ent = this->m_ActiveBots[i]();
			if (ent != nullptr && ent->IsAlive()) {
				++num_active;
			}
		}
		
		// TODO
		
		return;
		
	case InternalStateType::WAIT_FOR_ALL_DEAD:
		FOR_EACH_VEC(this->m_ActiveBots, i) {
			CBaseEntity *ent = this->m_ActiveBots[i]();
			if (ent != nullptr && ent->IsAlive()) {
				return;
			}
		}
		
		this->SetState(InternalStateType::DONE);
		return;
	}
}

void CWave::Update()
{
	// TODO
}


void IPopulator::UnpauseSpawning()
{
}

void CPeriodicSpawnPopulator::UnpauseSpawning()
{
	// TODO
}

void CMissionPopulator::UnpauseSpawning()
{
	this->m_ctTimer1.Start(this->m_flCooldownTime);
	this->m_ctTimer2.Start(RandomFloat(5.0f, 10.0f));
}


void IPopulator::OnPlayerKilled(CTFPlayer *player)
{
}

void CWaveSpawnPopulator::OnPlayerKilled(CTFPlayer *player)
{
	// TODO
}

void CWave::OnPlayerKilled(CTFPlayer *player)
{
	// TODO
}


bool IPopulator::HasEventChangeAttributes(const char *name) const
{
	// TODO
}

bool CWave::HasEventChangeAttributes(const char *name) const
{
	// TODO
}


bool CMissionPopulator::UpdateMission(CTFBot::MissionType mtype)
{
	VPROF_BUDGET("CMissionPopulator::UpdateMission", "NextBot");
	
	Vector<CTFPlayer *> blu_players;
	CollectPlayers<CTFPlayer>(&players, TF_TEAM_BLU, true);
	
	int num_existing_bots_with_same_mission = 0;
	FOR_EACH_VEC(blu_players, i) {
		CTFBot *bot = dynamic_cast<CTFBot *>(blu_players[i]);
		if (bot != nullptr) {
			if (bot->m_nMission == mtype) {
				++num_existing_bots_with_same_mission;
			}
		}
	}
	
	if (g_pPopulationManager->m_bIsPaused) {
		return false;
	}
	
	if (num_existing_bots_with_same_mission != 0) {
		this->m_ctTimer1.Start(this->m_flCooldownTime);
		return false;
	}
	
	if (!this->m_ctTimer1.IsElapsed()) {
		return false;
	}
	
	if (GetGlobalTeam(TF_TEAM_BLU)->GetNumPlayers() > 22) {
		if (tf_populator_debug.GetBool()) {
			DevMsg("MANN VS MACHINE: %3.2f: Waiting for slots to spawn mission.\n",
				gpGlobals->curtime);
		}
		
		return false;
	}
	
	if (tf_populator_debug.GetBool()) {
		DevMsg("MANN VS MACHINE: %3.2f: <<<< Spawning Mission >>>>\n",
			gpGlobals->curtime);
	}
	
	int num_sniper_bots = 0;
	FOR_EACH_VEC(blu_players, i) {
		CTFBot *bot = dynamic_cast<CTFBot *>(blu_players[i]);
		if (bot != nullptr) {
			if (bot->IsPlayerClass(TF_CLASS_SNIPER)) {
				++num_sniper_bots;
			}
		}
	}
	
	for (int i = 0; i < this->m_iDesiredCount; ++i) {
		Vector where;
		SpawnResult where_result =
			this->m_Where->FindSpawnLocation(&where);
		
		if (where_result != SPAWN_FAIL) {
			CUtlVector<CHandle<CBaseEntity>> spawned;
			if (this->m_Spawner->Spawn(&where, &spawned)) {
				FOR_EACH_VEC(spawned, j) {
					CBaseEntity *ent = spawned[j]();
					if (!ent->IsPlayer()) {
						continue;
					}
					
					CTFPlayer *player = ToTFPlayer(ent);
					if (!player->IsBotOfType(1337)) {
						continue;
					}
					
					CTFBot *bot = static_cast<CTFBot *>(player);
					bot->SetFlagTarget(nullptr);
					bot->SetMission(mtype, true);
					
					// TODO: set bool @ CTFPlayer+0x2834 to true (mission bot)
					
					if (TFObjectiveResource() != nullptr) {
						// TODO: define bits for wave status flags
						
						// TODO
					}
					
					if (TFGameRules()->IsMannVsMachineMode()) {
						if (bot->m_nMission == CTFBot::MissionType::SNIPER) {
							++num_sniper_bots;
							if (num_sniper_bots == 1) {
								TFGameRules()->HaveAllPlayersSpeakConceptIfAllowed(TLK_MVM_SNIPER_CALLOUT,
									TF_TEAM_RED);
							}
						}
					}
					
					if (where_result == SPAWN_TELEPORT) {
						OnBotTeleported(bot);
					}
				}
			}
		} else {
			if (tf_populator_debug.GetBool()) {
				DevMsg("MissionPopulator: %3.2f: Skipped a member - can't find a place to spawn\n",
					gpGlobals->curtime);
			}
		}
	}
	
	this->m_ctTimer1.Start(this->m_flCooldownTime);
	return true;
}

bool CMissionPopulator::UpdateMissionDestroySentries()
{
	VPROF_BUDGET("CMissionPopulator::UpdateMissionDestroySentries", "NextBot");
	
	// TODO
}


bool CWaveSpawnPopulator::IsFinishedSpawning()
{
	// TODO
}

bool CWave::IsDoneWithNonSupportWaves()
{
	// TODO
}


void CWaveSpawnPopulator::OnNonSupportWavesDone()
{
	// TODO
}


void CWaveSpawnPopulator::ForceFinish()
{
	// TODO
}

void CWave::ForceFinish()
{
	// TODO
}


void CWave::ForceReset()
{
	// TODO
}


int CWaveSpawnPopulator::GetCurrencyAmountPerDeath()
{
	// TODO
}


void CWaveSpawnPopulator::SetState(CWaveSpawnPopulator::InternalStateType newstate)
{
	this->m_iState = newstate;
	
	/* specifying teamnum 255 in event "teamplay_broadcast_audio" is a special
	 * case that causes the sound to play for players on all teams; see
	 * ClientModeShared::FireGameEvent in clientmode_shared.cpp */
	
	if (newstate == InternalStateType::PRE_SPAWN_DELAY) {
		if (this->m_strStartWaveWarningSound.Length() > 0) {
			g_pGameRules->BroadcastSound(255,
				this->m_strStartWaveWarningSound());
		}
		
		FireEvent(this->m_StartWaveOutput, "StartWaveOutput");
		
		if (tf_populator_debug.GetBool()) {
			DevMsg("%3.2f: WaveSpawn(%s) started PRE_SPAWN_DELAY\n",
				gpGlobals->curtime, this->m_strName());
		}
	} else if (newstate == InternalStateType::SPAWNING) {
		if (this->m_strFirstSpawnWarningSound.Length() > 0) {
			g_pGameRules->BroadcastSound(255,
				this->m_strFirstSpawnWarningSound());
		}
		
		FireEvent(this->m_FirstSpawnOutput, "FirstSpawnOutput");
		
		if (tf_populator_debug.GetBool()) {
			DevMsg("%3.2f: WaveSpawn(%s) started SPAWNING\n",
				gpGlobals->curtime, this->m_strName());
		}
	} else if (newstate == InternalStateType::WAIT_FOR_ALL_DEAD) {
		if (this->m_strLastSpawnWarningSound.Length() > 0) {
			g_pGameRules->BroadcastSound(255,
				this->m_strLastSpawnWarningSound());
		}
		
		FireEvent(this->m_LastSpawnOutput, "LastSpawnOutput");
		
		if (tf_populator_debug.GetBool()) {
			DevMsg("%3.2f: WaveSpawn(%s) started WAIT_FOR_ALL_DEAD\n",
				gpGlobals->curtime, this->m_strName());
		}
	} else if (newstate == InternalStateType::DONE) {
		if (this->m_strDoneWarningSound.Length() > 0) {
			g_pGameRules->BroadcastSound(255,
				this->m_strDoneWarningSound());
		}
		
		FireEvent(this->m_DoneOutput, "DoneOutput");
		
		if (tf_populator_debug.GetBool()) {
			DevMsg("%3.2f: WaveSpawn(%s) DONE\n",
				gpGlobals->curtime, this->m_strName());
		}
	}
}


void CWave::ActiveWaveUpdate()
{
	// TODO
}

void CWave::WaveCompleteUpdate()
{
	// TODO
}

void CWave::WaveIntermissionUpdate()
{
	// TODO
}
