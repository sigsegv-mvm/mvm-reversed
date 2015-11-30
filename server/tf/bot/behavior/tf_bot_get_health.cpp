/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_get_health.cpp
 * used in MvM: TODO
 */





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
