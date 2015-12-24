/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_build_sentrygun.cpp
 * used in MvM: TODO
 */


CTFBotEngineerBuildSentryGun::CTFBotEngineerBuildSentryGun()
{
	// TODO
}

CTFBotEngineerBuildSentryGun::CTFBotEngineerBuildSentryGun(CTFBotHintSentrygun *hint)
{
	// TODO
}

CTFBotEngineerBuildSentryGun::~CTFBotEngineerBuildSentryGun()
{
}


const char *CTFBotEngineerBuildSentryGun::GetName() const
{
	return "EngineerBuildSentryGun";
}


ActionResult<CTFBot> CTFBotEngineerBuildSentryGun::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}

ActionResult<CTFBot> CTFBotEngineerBuildSentryGun::Update(CTFBot *actor, float dt)
{
	// TODO
}

ActionResult<CTFBot> CTFBotEngineerBuildSentryGun::OnResume(CTFBot *actor, Action<CTFBot> *action)
{
	this->m_PathFollower.Invalidate();
	// TODO: CountdownTimer @ 0x58 .Invalidate()
	
	CONTINUE();
}
