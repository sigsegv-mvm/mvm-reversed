/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_building.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_engineer_retaliate_range("tf_bot_engineer_retaliate_range", "750", FCVAR_CHEAT,
	"If attacker who destroyed sentry is closer than this, attack. Otherwise, retreat");
ConVar tf_bot_engineer_exit_near_sentry_range("tf_bot_engineer_exit_near_sentry_range", "2500", FCVAR_CHEAT,
	"Maximum travel distance between a bot's Sentry gun and its Teleporter Exit");
ConVar tf_bot_engineer_max_sentry_travel_distance_to_point("tf_bot_engineer_max_sentry_travel_distance_to_point", "2500", FCVAR_CHEAT,
	"Maximum travel distance between a bot's Sentry gun and the currently contested point");


CTFBotEngineerBuilding::CTFBotEngineerBuilding()
{
	// TODO
}

CTFBotEngineerBuilding::CTFBotEngineerBuilding(CTFBotHintSentrygun *hint)
{
	// TODO
}

CTFBotEngineerBuilding::~CTFBotEngineerBuilding()
{
}


const char *CTFBotEngineerBuilding::GetName() const
{
	return "EngineerBuilding";
}


ActionResult<CTFBot> CTFBotEngineerBuilding::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}

ActionResult<CTFBot> CTFBotEngineerBuilding::Update(CTFBot *actor, float dt)
{
	// TODO
}

void CTFBotEngineerBuilding::OnEnd(CTFBot *actor, Action<CTFBot> *action)
{
	actor->m_bLookAroundForEnemies = true;
}


ActionResult<CTFBot> CTFBotEngineerBuilding::OnResume(CTFBot *actor, Action<CTFBot> *action)
{
	return ActionResult<CTFBot>::Continue();
}


EventDesiredResult<CTFBot> CTFBotEngineerBuilding::OnTerritoryCaptured(CTFBot *actor, int i1)
{
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotEngineerBuilding::OnTerritoryLost(CTFBot *actor, int i1)
{
	return EventDesiredResult<CTFBot>::Continue();
}


bool CTFBotEngineerBuilding::CheckIfSentryIsOutOfPosition(CTFBot *actor) const
{
	// TODO
}

bool CTFBotEngineerBuilding::IsMetalSourceNearby(CTFBot *actor) const
{
	// TODO
}

void CTFBotEngineerBuilding::UpgradeAndMaintainBuildings(CTFBot *actor)
{
	// TODO
}
