/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_move_to_build.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_debug_sentry_placement("tf_bot_debug_sentry_placement", "0", FCVAR_CHEAT);
ConVar tf_bot_max_teleport_exit_travel_to_point("tf_bot_max_teleport_exit_travel_to_point", "2500", FCVAR_CHEAT,
	"In an offensive engineer bot's tele exit is farther from the point than this, destroy it");
ConVar tf_bot_min_teleport_travel("tf_bot_min_teleport_travel", "3000", FCVAR_CHEAT,
	"Minimum travel distance between teleporter entrance and exit before engineer bot will build one");


CTFBotEngineerMoveToBuild::CTFBotEngineerMoveToBuild(/* TODO */)
{
	// TODO
}

CTFBotEngineerMoveToBuild::~CTFBotEngineerMoveToBuild()
{
}


const char *CTFBotEngineerMoveToBuild::GetName() const
{
	return "EngineerMoveToBuild";
}


ActionResult<CTFBot> CTFBotEngineerMoveToBuild::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}

ActionResult<CTFBot> CTFBotEngineerMoveToBuild::Update(CTFBot *actor, float dt)
{
	// TODO
}


EventDesiredResult<CTFBot> CTFBotEngineerMoveToBuild::OnMoveToSuccess(CTFBot *actor, const Path *path)
{
	CONTINUE();
}

EventDesiredResult<CTFBot> CTFBotEngineerMoveToBuild::OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail)
{
	// TODO
}

EventDesiredResult<CTFBot> CTFBotEngineerMoveToBuild::OnStuck(CTFBot *actor)
{
	CONTINUE();
}

EventDesiredResult<CTFBot> CTFBotEngineerMoveToBuild::OnTerritoryLost(CTFBot *actor, int i1)
{
	// TODO
}


void CTFBotEngineerMoveToBuild::CollectBuildAreas(CTFBot *actor)
{
	// TODO
}

void CTFBotEngineerMoveToBuild::SelectBuildLocation(CTFBot *actor)
{
	// TODO
}
