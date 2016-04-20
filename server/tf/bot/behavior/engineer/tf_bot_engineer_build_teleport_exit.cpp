/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_build_teleport_exit.cpp
 * used in MvM: TODO
 */


CTFBotEngineerBuildTeleportExit::CTFBotEngineerBuildTeleportExit()
{
	// TODO
}

CTFBotEngineerBuildTeleportExit::CTFBotEngineerBuildTeleportExit(const Vector& v1, float f1)
{
	// TODO
}

CTFBotEngineerBuildTeleportExit::~CTFBotEngineerBuildTeleportExit()
{
}


const char *CTFBotEngineerBuildTeleportExit::GetName() const
{
	return "EngineerBuildTeleportExit";
}


ActionResult<CTFBot> CTFBotEngineerBuildTeleportExit::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}

ActionResult<CTFBot> CTFBotEngineerBuildTeleportExit::Update(CTFBot *actor, float dt)
{
	// TODO
}

ActionResult<CTFBot> CTFBotEngineerBuildTeleportExit::OnResume(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}


EventDesiredResult<CTFBot> CTFBotEngineerBuildTeleportExit::OnStuck(CTFBot *actor)
{
	this->m_PathFollower.Invalidate();
	
	return EventDesiredResult<CTFBot>::Continue();
}
