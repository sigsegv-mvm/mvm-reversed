/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * Population: populators
 */


class IPopulator
{
public:
	virtual ~IPopulator() {}
	
	virtual bool Parse(KeyValues *) = 0;
	virtual void PostInitialize();
	virtual void Update();
	virtual void UnpauseSpawning();
	virtual void OnPlayerKilled(CTFPlayer *);
	virtual bool HasEventChangeAttributes(const char *) const;
	
protected:
	IPopulationSpawner *m_Spawner; // +0x04
	CPopulationManager *m_PopMgr;  // +0x08
};


class CRandomPlacementPopulator : public IPopulator
{
public:
	CRandomPlacementPopulator(CPopulationManager *);
	virtual ~CRandomPlacementPopulator();
	
	virtual bool Parse(KeyValues *);
	virtual void PostInitialize();
	
private:
	// TODO: 0x0c+
};


class CPeriodicSpawnPopulator : public IPopulator
{
public:
	CPeriodicSpawnPopulator(CPopulationManager *);
	virtual ~CPeriodicSpawnPopulator();
	
	virtual bool Parse(KeyValues *);
	virtual void PostInitialize();
	virtual void Update();
	virtual void UnpauseSpawning();
	
private:
	// TODO: 0x0c+
};


class CMissionPopulator : public IPopulator
{
public:
	CMissionPopulator(CPopulationManager *);
	virtual ~CMissionPopulator();
	
	virtual bool Parse(KeyValues *);
	virtual void Update();
	virtual void UnpauseSpawning();
	
	// UpdateMission(CTFBot::MissionType)
	// UpdateMissionDestroySentries()
	
private:
	// TODO: 0x0c+
};


class CWaveSpawnPopulator : public IPopulator
{
public:
	CWaveSpawnPopulator(CPopulationManager *);
	virtual ~CWaveSpawnPopulator();
	
	virtual bool Parse(KeyValues *);
	virtual void Update();
	virtual void OnPlayerKilled(CTFPlayer *);
	
	// ForceFinish()
	// GetCurrencyAmountPerDeath()
	// IsFinishedSpawning()
	// OnNonSupportWavesDone()
	// SetState(CWaveSpawnPopulator::InternalStateType)
	
private:
	// TODO: 0x0c+
};


class CWave : public IPopulator
{
public:
	CWave(CPopulationManager *);
	virtual ~CWave();
	
	virtual bool Parse(KeyValues *);
	virtual void Update();
	virtual void OnPlayerKilled(CTFPlayer *);
	virtual bool HasEventChangeAttributes(const char *) const;
	
	// ActiveWaveUpdate()
	// AddClassType(string_t, int, uint)
	// FindWaveSpawnPopulator(char const*)
	// ForceFinish()
	// ForceReset()
	// IsDoneWithNonSupportWaves()
	// WaveCompleteUpdate()
	// WaveIntermissionUpdate()
	
private:
	// TODO: 0x0c+
};
