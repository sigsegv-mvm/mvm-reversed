/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
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
};


class CRandomPlacementPopulator : public IPopulator
{
public:
	CRandomPlacementPopulator(CPopulationManager *);
	virtual ~CRandomPlacementPopulator();
	
	virtual bool Parse(KeyValues *);
	virtual void PostInitialize();
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
};
