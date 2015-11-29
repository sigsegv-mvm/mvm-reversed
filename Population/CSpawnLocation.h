/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Population: spawn location
 */


enum SpawnResult
{
	SPAWN_FAIL     = 0,
	SPAWN_NORMAL   = 1,
	SPAWN_TELEPORT = 2,
};


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
	SpawnResult FindSpawnLocation(Vector& vec) const;
	
private:
	CTFNavArea *SelectSpawnArea() const;
	
	Where m_iWhere;                            // +0x00
	CUtlVector<CHandle<CBaseEntity>> m_Spawns; // +0x04
};


SpawnResult DoTeleporterOverride(CBaseEntity *ent, Vector& vec);
void OnBotTelported(CTFBot *bot);
