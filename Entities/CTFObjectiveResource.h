/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Entities: objective resource
 */


class CTFObjectiveResource : public CBaseTeamObjectiveResource
{
public:
	// TODO
	
private:
	CNetworkVar(int,   m_nMannVsMachineMaxWaveCount);   // +0x0fa4
	CNetworkVar(int,   m_nMannVsMachineWaveCount);      // +0x0fa8
	CNetworkVar(int,   m_nMannVsMachineWaveEnemyCount); // +0x0fac
	CNetworkVar(int,   m_nMvMWorldMoney);               // +0x0fb0
	CNetworkVar(float, m_flMannVsMachineNextWaveTime);  // +0x0fb4
	CNetworkVar(bool,  m_bMannVsMachineBetweenWaves);   // +0x0fb8
	
	CNetworkArray(int, m_nMannVsMachineWaveClassCounts,  12); // +0x0fbc
	CNetworkArray(int, m_nMannVsMachineWaveClassCounts2, 12); // +0x0fec
	
	CNetworkArray(string_t, m_iszMannVsMachineWaveClassNames,  12); // +0x101c
	CNetworkArray(string_t, m_iszMannVsMachineWaveClassNames2, 12); // +0x104c
	
	CNetworkArray(unsigned int, m_nMannVsMachineWaveClassFlags,  12); // +0x107c
	CNetworkArray(unsigned int, m_nMannVsMachineWaveClassFlags2, 12); // +0x10ac
	
	CNetworkArray(bool, m_bMannVsMachineWaveClassActive,  12); // +0x10dc
	CNetworkArray(bool, m_bMannVsMachineWaveClassActive2, 12); // +0x10e8
	
	CNetworkVar(int,      m_nFlagCarrierUpgradeLevel); // +0x10f4
	CNetworkVar(float,    m_flMvMBaseBombUpgradeTime); // +0x10f8
	CNetworkVar(float,    m_flMvMNextBombUpgradeTime); // +0x10fc
	CNetworkVar(int,      m_iChallengeIndex);          // +0x1100
	CNetworkVar(string_t, m_iszMvMPopfileName);        // +0x1104
	CNetworkVar(int,      m_nMvMEventPopfileType);     // +0x1108
	
	// TODO: 0x110c (string_t, "teleporter", I think)
};
