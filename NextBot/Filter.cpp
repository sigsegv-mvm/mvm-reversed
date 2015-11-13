/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: filters
 */


CUsefulHealTargetFilter::CUsefulHealTargetFilter(int teamnum)
	: m_iTeamNum(teamnum)
{
}


bool CUsefulHealTargetFilter::IsAllowed(CBaseEntity *ent) const
{
	if (ent == nullptr || !ent->IsPlayer() ||
		ent->GetTeamNumber() != this->m_iTeamNum) {
		return false;
	}
	
	if (ToTFPlayer(ent)->IsPlayerClass(TF_CLASS_MEDIC) ||
		ToTFPlayer(ent)->IsPlayerClass(TF_CLASS_SNIPER)) {
		return false;
	}
	
	return true;
}


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


CAmmoFilter::CAmmoFilter(CBaseEntity *actor)
	: m_Actor(actor)
{
}


bool CAmmoFilter::IsSelected(const CBaseEntity *ent) const
{
	// TODO
}
