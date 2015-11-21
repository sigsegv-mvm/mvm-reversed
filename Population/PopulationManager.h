/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Population: population manager
 */


// TODO: class/struct CMvMBotUpgrade (sizeof: 0x54 probably)
// TODO: class/struct CPopulationManager::PlayerUpgradeHistory (sizeof: 0x20)
//       - contains a CUtlVector<CUpgradeInfo>
// TODO: class/struct CPopulationManager::CheckpointSnapshotInfo


class CPopulationManager : public CPointEntity, public CGameEventListener
{
public:
	// TODO: get list of all functions (virtual first, then non-virtual)
	
private:
	// +0x000: vtable CBaseEntity
	// +0x360: vtable CGameEventListener
	
	// 364 byte
	// 368 CUtlVector<IPopulator *> (pretty sure this is an AutoPurge; this is used for MissionPopulators and RandomPlacementPopulators)
	// 37c string pop file name (full path)
	// ...
	// 480 string pop file name (short)
	// ...
	// 580 
	KeyValues *m_kvTemplates; // +0x584
	// 588 byte
	// 589 byte
	// 58a?
	// 58b?
	// 58c dword
	// 590 int StartingCurrency
	// 594 bool EventPopfile
	// 598 int RespawnWaveTime
	// 59c bool Fixed
	// 59d bool CanBotsAttackWhileInSpawnRoom
	// 59e?
	// 59f?
	// 5a0 int sentry buster threshold damage
	// 5a4 int sentry buster threshold kills
	// 5a8 dword or possibly word, related to endless bot upgrades
	// 5ac CUtlVector<CWave *> (very likely an AutoPurge)
	// 5c0 
	// 5c4 CUtlVector<CPopulationManager::PlayerUpgradeHistory *> (maybe auto-purge, dunno)
	// 5d8 bool
	// 5d9 bool Advanced
	// 5da?
	// 5db?
	// 5dc ptr to mvm stats instance (g_pMVMStats)
	// 5e0 KeyValues* for mission cycle file
	// 5e4?
	// 5e5 bool (pause status: true when spawning is paused)
	// 5e6?
	// 5e7 bool IsEndless
	// 5e8-5fb: five dwords, auto-init to zero, probably a CUtlVector
	// 5fc CUtlVector<CMvMBotUpgrade> endless bot upgrades
	// 610 CUniformRandomStream (sizeof: 0x94)
	// 6a4 CUtlVector<int>
	// 6b8 
	// 6bc CUtlVector<const CTFPlayer *> (used in PlayerDoneViewingLoot)
	// ...
	// 6d0 CUtlString, set to "Default" in reset, almost undoubtably the current eventchangeattributes set name
	// 6d4 CUtlRBTree<CUtlMap<unsigned long long, int, unsigned short>::Node_t, ...> (don't know size of this)
	// 6d8 ptr to something of size 0x294
	// 6dc 
	// ...
	// 6f0 
	// 6f4 dword (number of respecs possibly)
	// 6f8 dword (respec credit progress possibly)
	
	static int m_nNumConsecutiveWipes = 0;
	// static int m_checkpointWaveIndex = ???
	static CUtlVector<CheckpointSnapshotInfo *> m_checkpointSnapshot; // maybe autopurge
};

// global static s_iLastKnownMission
// global static s_iLastKnownMissionCategory
