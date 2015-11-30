/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/tf_mann_vs_machine_stats.h
 */


// 0x18 <= sizeof <= 0x1c
struct CMannVsMachineWaveStats
{
	// 0x00 vtable (NetworkStateChanged)
	// 0x04 int m_nCreditsDropped
	// 0x08 int m_nCreditsAcquired
	// 0x0c int m_nCreditsBonus
	// 0x10 int m_nPlayerDeaths
	// 0x14 int m_nBuyBacks
	// 0x18?
};


class CMannVsMachineStats : public CBaseEntity
{
public:
	// TODO
	
private:
	// 0x588 CMannVsMachineWaveStats m_runningTOtalWaveStats
	// 0x5a4 CMannVsMachineWaveStats m_previousWaveStats
	// 0x5c0 CMannVsMachineWaveStats m_currentWaveStats
	// 0x5dc int m_iCurrentWaveIdx
	// 0x5e0 int m_iServerWaveID
	// 0x638 int m_iCurrencyCollectedForRespec
	// 0x63c int m_nRespecsAwardedInWave
	
	// TODO
};

// TODO: enum eMannVsMachineEvent

// TODO: CPlayerWaveSpendingStats

// TODO: all the global functions for stats
