/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Population: spawn location
 */


CSpawnLocation::CSpawnLocation()
{
	this->m_iWhere = Where::TEAMSPAWN;
}


bool CSpawnLocation::Parse(KeyValues *kv)
{
	// TODO
}

CTFNavArea *CSpawnLocation::SelectSpawnArea()
{
	// TODO
}

SpawnResult CSpawnLocation::FindSpawnLocation(Vector& vec)
{
	// TODO
}


static CHandle<CBaseEntity> s_lastTeleporter;
static float s_flLastTeleportTime;


SpawnResult DoTeleporterOverride(CBaseEntity *ent, Vector& vec)
{
	CUtlVector<CBaseEntity *> teleporters;
	
	for (int i = 0; i < IBaseObjectAutoList::AutoList().Count(); ++i) {
		CBaseObject *obj = static_cast<CBaseObject *>(IBaseObjectAutoList::AutoList()[i]);
		
		// TODO: not sure if this is really the right enum name for object type
		if (obj->GetType() == OBJ_TELEPORTER &&
			obj->GetTeamNumber() == TF_TEAM_BLU &&
			!obj->IsBuilding() && !obj->HasSapper()) {
			const char *ent_name = STRING(obj->GetEntityName());
			
		}
	}
	
	// CBaseObject+0xaec dword: 
	// CBaseObject+0xaf8 dword: 
	
	// TODO
}

void OnBotTeleported(CTFBot *bot)
{
	CBaseEntity *tele = s_lastTeleporter();
	
	// TODO
	
	
	
	
	// TODO
}
