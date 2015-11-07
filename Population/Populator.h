/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * Population: populators
 */


class IPopulator
{
public:
	virtual ~IPopulator();
	
	virtual bool Parse(KeyValues *kv) = 0;
	virtual void PostInitialize();
	virtual void Update();
	virtual void UnpauseSpawning();
	virtual void OnPlayerKilled(CTFPlayer *player);
	virtual bool HasEventChangeAttributes(const char *name) const;
	
protected:
	IPopulationSpawner *m_Spawner; // +0x04
	CPopulationManager *m_PopMgr;  // +0x08
};


class CRandomPlacementPopulator : public IPopulator
{
public:
	CRandomPlacementPopulator(CPopulationManager *popmgr);
	virtual ~CRandomPlacementPopulator();
	
	virtual bool Parse(KeyValues *kv) override;
	virtual void PostInitialize() override;
	
private:
	int m_iCount;                // +0x0c
	float m_flMinimumSeparation; // +0x10
	// +0x14 NavAreaFilter dword -1 TODO: enum for this?
};


class CPeriodicSpawnPopulator : public IPopulator
{
public:
	CPeriodicSpawnPopulator(CPopulationManager *popmgr);
	virtual ~CPeriodicSpawnPopulator();
	
	virtual bool Parse(KeyValues *kv) override;
	virtual void PostInitialize() override;
	virtual void Update() override;
	virtual void UnpauseSpawning() override;
	
private:
	CSpawnLocation m_Where; // +0x0c
	float m_flMinInterval;  // +0x24
	float m_flMaxInterval;  // +0x28
	// +0x2c CountdownTimer
};


class CMissionPopulator : public IPopulator
{
public:
	CMissionPopulator(CPopulationManager *popmgr);
	virtual ~CMissionPopulator();
	
	virtual bool Parse(KeyValues *kv) override;
	virtual void Update() override;
	virtual void UnpauseSpawning() override;
	
	bool UpdateMission(CTFBot::MissionType mtype);
	bool UpdateMissionDestroySentries();
	
private:
	CTFBot::MissionType m_Objective; // +0x0c
	CSpawnLocation m_Where;          // +0x10
	// +0x28 dword 0
	float m_flInitialCooldown;       // +0x2c
	float m_flCooldownTime;          // +0x30
	CountdownTimer m_Timer1;         // +0x34
	CountdownTimer m_Timer2;         // +0x40
	int m_iDesiredCount;             // +0x4c
	int m_iBeginAtWave;              // +0x50
	int m_iEndBeforeThisWave;        // +0x54
};


class CWaveSpawnPopulator : public IPopulator
{
public:
	enum InternalStateType
	{
		// TODO
	};
	
	CWaveSpawnPopulator(CPopulationManager *popmgr);
	virtual ~CWaveSpawnPopulator();
	
	virtual bool Parse(KeyValues *kv) override;
	virtual void Update() override;
	virtual void OnPlayerKilled(CTFPlayer *player) override;
	
	bool IsFinishedSpawning();
	void OnNonSupportWavesDone();
	void ForceFinish();
	
	void SetState(CWaveSpawnPopulator::InternalStateType newstate);
	
	int GetCurrencyAmountPerDeath();
	
private:
	static int m_reservedPlayerSlotCount = ???;
	
	// +0x00c CSpawnLocation
	// +0x024 TotalCount dword 0
	// +0x028 
	// +0x02c 
	// +0x030 MaxActive dword decimal 999
	// +0x034 SpawnCount dword 1
	// +0x038 WaitBeforeStarting float 0
	// +0x03c float 0
	// +0x040 byte 0
	// +0x044 StartWaveWarningSound CFmtStrN<256>
	// +0x150 StartWaveOutput EventInfo *
	// +0x154 FirstSpawnWarningSound CFmtStrN<256>
	// +0x260 FirstSpawnOutput EventInfo *
	// +0x264 LastSpawnWarningSound CFmtStrN<256>
	// +0x370 LastSpawnOutput EventInfo *
	// +0x374 DoneWarningSound CFmtStrN<256>
	// +0x480 DoneOutput EventInfo *
	// +0x484 TotalCurrency dword
	// +0x488 
	// +0x48c Name CUtlString
	// +0x490 WaitForAllSpawned CUtlString
	// +0x494 dword/float 0
	// +0x498 CountdownTimer
	// +0x4a4 dword/float 0
	// +0x4a8 dword/float 0
	// +0x4ac dword/float 0
	// +0x4b0 dword/float 0
	// +0x4b4 dword/float 0
	// +0x4b8 
	// +0x4bc 
	// +0x4c0 Support bool
	// +0x4c1 SupportLimited bool
	// +0x4c4 dword/float 0
	// +0x4c8 
	// +0x4cc RandomSpawn bool
	// +0x4d0 dword/float 0
};


class CWave : public IPopulator
{
public:
	CWave(CPopulationManager *popmgr);
	virtual ~CWave();
	
	virtual bool Parse(KeyValues *kv) override;
	virtual void Update() override;
	virtual void OnPlayerKilled(CTFPlayer *player) override;
	virtual bool HasEventChangeAttributes(const char *name) const override;
	
	bool IsDoneWithNonSupportWaves();
	void ForceFinish();
	void ForceReset();
	
	void ActiveWaveUpdate();
	void WaveCompleteUpdate();
	void WaveIntermissionUpdate();
	
	CWaveSpawnPopulator *FindWaveSpawnPopulator(char const *name);
	void AddClassType(string_t icon, int count, unsigned int flags);
	
private:
	CUtlVectorAutoPurge<CWaveSpawnPopulator *> m_WaveSpawns;
	// +0x020 byte 0
	// +0x021 byte 0
	// +0x024 
	// +0x028 
	// +0x02c 
	// +0x030 
	// +0x034 
	// +0x038 CUtlVector<WaveClassCount_t> (aka int)
	// +0x04c 
	// +0x050 StartWaveOutput EventInfo *
	// +0x054 DoneOutput EventInfo *
	// +0x058 InitWaveOutput EventInfo *
	// +0x05c Description CFmtStr<256>
	// +0x168 Sound CFmtStr<256>
	// +0x274 WaitWhenDone float
	// +0x278 CountdownTimer
	// +0x284 byte 1
	// +0x288 
	// +0x28c byte 0
	// +0x290 CountdownTimer
	// +0x29c byte 0
	// +0x2a0 
};
