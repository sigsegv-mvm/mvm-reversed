/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Entities: population manager
 */


// TODO: class/struct CMvMBotUpgrade (sizeof: 0x54 probably)
// TODO: class/struct CUpgradeInfo (sizeof: 0x20 probably)


class CPopulationManager : public CPointEntity, public CGameEventListener
{
public:
	struct PlayerUpgradeHistory
	{
		// sizeof: 0x20
		// has a CUtlVector<CUpgradeInfo> @ 0x8 I think
		// has an int @ 0x1c which is returned by GetPlayerCurrencySpent
	};
	
	struct CheckpointSnapshotInfo
	{
		// TODO
		// sizeof: at least 0x1c
	};
	
	CPopulationManager();
	virtual ~CPopulationManager();
	
	/* CBaseEntity overrides */
	virtual void Spawn() override;
	virtual void Precache() override;
	
	/* CGameEventListener overrides */
	virtual void FireGameEvent(IGameEvent *event) override;
	
	virtual void Reset();
	virtual bool Initialize();
	
	void AddPlayerCurrencySpent(CTFPlayer *player, int amount);
	void AddRespecToPlayer(CTFPlayer *player);
	void AdjustMinPlayerSpawnTime();
	void AllocateBots();
	void ClearCheckpoint();
	int CollectMvMBots(CUtlVector<CTFPlayer *> *bots);
	void CycleMission();
	void DebugWaveStats();
	void EndlessFlagHasReset();
	void EndlessParseBotUpgrades();
	void EndlessRollEscalation();
	void EndlessSetAttributesForBot(CTFBot *bot);
	bool EndlessShouldResetFlag();
	UNKNOWN FindCheckpointSnapshot(CSteamID steamid) const; // probably returns CheckpointSnapshotInfo *
	UNKNOWN FindCheckpointSnapshot(CTFPlayer *player) const; // probably returns CheckpointSnapshotInfo *
	PlayerUpgradeHistory *FindOrAddPlayerUpgradeHistory(CSteamID steamid);
	PlayerUpgradeHistory *FindOrAddPlayerUpgradeHistory(CTFPlayer *player);
	void ForgetOtherBottleUpgrades(CTFPlayer *player, CEconItemView *bottle, int i1);
	UNKNOWN GetCurrentWave(); // probably returns CWave *
	float GetDamageMultiplier();
	float GetHealthMultiplier(bool b1);
	int GetNumRespecsAvailableForPlayer(CTFPlayer *player);
	int GetPlayerCurrencySpent(CTFPlayer *player);
	UNKNOWN GetPlayerUpgradeHistory(CTFPlayer *player); // probably returns PlayerUpgradeHistory * or CUtlVector<CUpgradeInfo> *
	const char *GetPopulationFilename();
	const char *GetPopulationFilenameShort();
	void GetSentryBusterDamageAndKillThreshold(int& i1, int& i2) const;
	int GetTotalPopFileCurrency();
	bool HasEventChangeAttributes(const char *name) const;
	bool IsInEndlessWaves();
	bool IsValidMvMMap(const char *name);
	void JumpToWave(unsigned int i1, float f1);
	void LoadLastKnownMission();
	void LoadMissionCycleFile();
	bool LoadMvMMission(KeyValues *kv);
	void MvMVictory();
	void OnCurrencyCollected(int i1, bool b1, bool b2);
	void OnCurrencyPackFade();
	void OnPlayerKilled(CTFPlayer *player);
	bool Parse();
	void PauseSpawning();
	void PlayerDoneViewingLoot(const CTFPlayer *player);
	void PostInitialize();
	void RemovePlayerAndItemUpgradesFromHistory(CTFPlayer *player);
	void RemoveRespecFromPlayer(CTFPlayer *player);
	void ResetMap();
	void ResetRespecPoints();
	void RestoreCheckpoint();
	void RestoreItemToCheckpointState(CTFPlayer *player, CEconItemView *item);
	void RestorePlayerCurrency();
	void SendUpgradesToPlayer(CTFPlayer *player);
	void SetCheckpoint(int i1);
	void SetNumRespecsForPlayer(CTFPlayer *player, int num);
	void SetPopulationFilename(const char *name);
	void SetupOnRoundStart();
	void ShowNextWaveDescription();
	void StartCurrentWave();
	void UnpauseSpawning();
	void Update();
	void UpdateObjectiveResource();
	void WaveEnd(bool b1);
	
private:
	// +0x000: vtable CBaseEntity
	// +0x360: vtable CGameEventListener
	
	// 364 byte
	CUtlVectorAutoPurge<IPopulator *> m_Populators; // +0x368 (used for MissionPopulators and RandomPlacementPopulators)
	char m_szPopFileNameFull[MAX_PATH];             // +0x37c
	char m_szPopFileNameShort[MAX_PATH];            // +0x480
	KeyValues *m_kvTemplates; // +0x584
	// 588 byte
	// 589 byte
	// 58a?
	// 58b?
	// 58c dword
	int m_iStartingCurrency;               // +0x590 (from popfile)
	bool m_bEventPopfile;                  // +0x594 (from popfile)
	int m_iRespawnWaveTime;                // +0x598 (from popfile)
	bool m_bFixed;                         // +0x59c (from popfile)
	bool m_bCanBotsAttackWhileInSpawnRoom; // +0x59d (from popfile)
	// 59e?
	// 59f?
	int m_iSentryBusterThresholdDamage;    // +0x5a0
	int m_iSentryBusterThresholdKills;     // +0x5a4
	// 5a8 current wave index, probably
	CUtlVector<CWave *> m_Waves; // +0x5ac
	// 5c0 
	CUtlVector<PlayerUpgradeHistory *> m_UpgradeHistory; // +0x5c4
	// 5d8 bool
	bool m_bAdvanced; // +0x5d9 (from popfile)
	// 5da?
	// 5db?
	CMannVsMachineStats *m_pMvMStats; // +0x5dc
	KeyValues *m_kvMissionCycle; // +0x5e0
	// 5e4?
	bool m_bIsPaused;  // +0x5e5
	// 5e6?
	bool m_bIsEndless; // +0x5e7
	// 5e8 CUtlVector<CMvMBotUpgrade> something related to endless bot upgrades
	// 5fc CUtlVector<CMvMBotUpgrade> something related to endless bot upgrades
	// 610 CUniformRandomStream (sizeof: 0x94)
	// 6a4 CUtlVector<int>
	// 6b8 
	// 6bc CUtlVector<const CTFPlayer *> (used in PlayerDoneViewingLoot)
	// 6d0 CUtlString, set to "Default" in reset, almost undoubtably the current eventchangeattributes set name
	// 6d4 CUtlRBTree<CUtlMap<unsigned long long, int, unsigned short>::Node_t, ...> (don't know size of this), seems to store number of respec credits for each player
	// 6d8 ptr to something of size 0x294
	// 6dc 
	// 6e0 
	// 6e4 
	// 6e8 
	// 6ec 
	// 6f0 
	// 6f4 dword (number of respecs possibly)
	// 6f8 dword (respec credit progress possibly)
	
	static int m_nNumConsecutiveWipes = 0;
	static int m_checkpointWaveIndex = 0;
	static CUtlVector<CheckpointSnapshotInfo *> m_checkpointSnapshot; // maybe autopurge
};

// global static s_iLastKnownMission
// global static s_iLastKnownMissionCategory
