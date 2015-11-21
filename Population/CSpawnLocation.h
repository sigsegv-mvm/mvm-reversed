/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Population: spawn location
 */


class CSpawnLocation
{
public:
	enum class Where : int
	{
		TEAMSPAWN = 0,
		AHEAD     = 1,
		BEHIND    = 2,
		ANYWHERE  = 3,
	};
	
	CSpawnLocation();
	
	bool Parse(KeyValues *kv);
	CTFNavArea *SelectSpawnArea();
	bool FindSpawnLocation(Vector& vec);
	
private:
	Where m_iWhere;                            // +0x00
	CUtlVector<CHandle<CBaseEntity>> m_Spawns; // +0x04
};
