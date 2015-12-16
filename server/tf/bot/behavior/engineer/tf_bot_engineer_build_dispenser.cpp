/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_build_dispenser.cpp
 * used in MvM: TODO
 */


CTFBotEngineerBuildDispenser::CTFBotEngineerBuildDispenser(/* TODO */)
{
	// TODO
}

CTFBotEngineerBuildDispenser::~CTFBotEngineerBuildDispenser()
{
}


const char *CTFBotEngineerBuildDispenser::GetName() const
{
	return "EngineerBuildDispenser";
}


ActionResult<CTFBot> CTFBotEngineerBuildDispenser::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}

ActionResult<CTFBot> CTFBotEngineerBuildDispenser::Update(CTFBot *actor, float dt)
{
	// TODO
}

void CTFBotEngineerBuildDispenser::OnEnd(CTFBot *actor, Action<CTFBot> *action)
{
	actor->GetBodyInterface()->ClearPendingAimReply();
}


ActionResult<CTFBot> CTFBotEngineerBuildDispenser::OnResume(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}
