/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_get_health.cpp
 * used in MvM: TODO
 */


// TODO: static s_possibleHealth = -1


ConVar tf_bot_health_critical_ratio("tf_bot_health_critical_ratio", "0.3", FCVAR_CHEAT);
ConVar tf_bot_health_ok_ratio("tf_bot_health_ok_ratio", "0.8", FCVAR_CHEAT);
ConVar tf_bot_health_search_near_range("tf_bot_health_search_near_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_health_search_far_range("tf_bot_health_search_far_range", "2000", FCVAR_CHEAT);





CHealthFilter::CHealthFilter(CBaseEntity *actor)
	: m_Actor(actor)
{
}


bool CHealthFilter::IsSelected(const CBaseEntity *ent) const
{
	if (ent == nullptr) {
		return false;
	}
	
	CNavArea *nearest =
		TheNavMesh()->GetNearestNavArea(ent->WorldSpaceCenter(), 0);
	if (nearest == nullptr) {
		return false;
	}
	
	// TODO
	
	// CClosestTFPlayer is a class
	// size >= 0x10
	// has operator()
}
