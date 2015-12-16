/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_idle.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_engineer_mvm_sentry_hint_bomb_forward_range("tf_bot_engineer_mvm_sentry_hint_bomb_forward_range", "0", FCVAR_CHEAT);
ConVar tf_bot_engineer_mvm_sentry_hint_bomb_backward_range("tf_bot_engineer_mvm_sentry_hint_bomb_backward_range", "3000", FCVAR_CHEAT);
ConVar tf_bot_engineer_mvm_hint_min_distance_from_bomb("tf_bot_engineer_mvm_hint_min_distance_from_bomb", "1300", FCVAR_CHEAT);

ConCommand tf_bot_mvm_show_engineer_hint_region_command("tf_bot_mvm_show_engineer_hint_region", &tf_bot_mvm_show_engineer_hint_region,
	"Show the nav areas MvM engineer bots will consider when selecting sentry and teleporter hints", FCVAR_CHEAT);


CTFBotMvMEngineerIdle::CTFBotMvMEngineerIdle(/* TODO */)
{
	// TODO
}

CTFBotMvMEngineerIdle::~CTFBotMvMEngineerIdle()
{
}


const char *CTFBotMvMEngineerIdle::GetName() const
{
	return "MvMEngineerIdle";
}


ActionResult<CTFBot> CTFBotMvMEngineerIdle::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}

ActionResult<CTFBot> CTFBotMvMEngineerIdle::Update(CTFBot *actor, float dt)
{
	// TODO
}


QueryResponse CTFBotMvMEngineerIdle::ShouldHurry(const INextBot *nextbot) const
{
	// TODO
}

QueryResponse CTFBotMvMEngineerIdle::ShouldRetreat(const INextBot *nextbot) const
{
	// TODO
}

QueryResponse CTFBotMvMEngineerIdle::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	// TODO
}


bool CTFBotMvMEngineerIdle::ShouldAdvanceNestSpot(CTFBot *actor)
{
	// TODO
}

void CTFBotMvMEngineerIdle::TakeOverStaleNest(CBaseTFBotHintEntity *hint, CTFBot *actor)
{
	// TODO
}

void CTFBotMvMEngineerIdle::TryToDetonateStaleNest()
{
	// TODO
}


bool CTFBotMvMEngineerHintFinder::FindHint(bool b1, bool b2, CHandle<CTFBotHintEngineerNest> *hint)
{
	// TODO
}
