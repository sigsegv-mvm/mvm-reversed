/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_get_ammo.cpp
 * used in MvM: TODO
 */


// TODO: static s_possibleAmmo = -1


ConVar tf_bot_ammo_search_range("tf_bot_ammo_search_range", "5000", FCVAR_CHEAT,
	"How far bots will search to find ammo around them");
ConVar tf_bot_debug_ammo_scavanging("tf_bot_debug_ammo_scavanging", "0", FCVAR_CHEAT);


CTFBotGetAmmo::CTFBotGetAmmo(/* TODO */)
{
	// TODO
}

CTFBotGetAmmo::~CTFBotGetAmmo()
{
}


const char *CTFBotGetAmmo::GetName() const
{
	return "GetAmmo";
}


ActionResult<CTFBot> CTFBotGetAmmo::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	VPROF_BUDGET("CTFBotGetAmmo::OnStart", "NextBot");
	
	// TODO
}

ActionResult<CTFBot> CTFBotGetAmmo::Update(CTFBot *actor, float dt)
{
	// TODO
}


EventDesiredResult<CTFBot> CTFBotGetAmmo::OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace)
{
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotGetAmmo::OnMoveToSuccess(CTFBot *actor, const Path *path)
{
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotGetAmmo::OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail)
{
	return EventDesiredResult<CTFBot>::Done("Failed to reach ammo", ResultSeverity::CRITICAL);
}

EventDesiredResult<CTFBot> CTFBotGetAmmo::OnStuck(CTFBot *actor)
{
	return EventDesiredResult<CTFBot>::Done("Stuck trying to reach ammo", ResultSeverity::CRITICAL);
}


QueryResponse CTFBotGetAmmo::ShouldHurry(const INextBot *nextbot) const
{
	return QueryResponse::YES;
}


bool CTFBotGetAmmo::IsPossible(CTFBot *actor)
{
	VPROF_BUDGET("CTFBotGetAmmo::IsPossible", "NextBot");
	
	// TODO
}


CAmmoFilter::CAmmoFilter(CBaseEntity *actor)
	: m_Actor(actor)
{
}


bool CAmmoFilter::IsSelected(const CBaseEntity *ent) const
{
	// TODO
}
