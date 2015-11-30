/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_dead.cpp
 * used in MvM: TODO
 */


CTFBotDead::CTFBotDead()
{
}

CTFBotDead::~CTFBotDead()
{
}


const char *CTFBotDead::GetName() const
{
	return "Dead";
}


ActionResult<CTFBot> CTFBotDead::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	this->m_itTimeSinceDeath.Start();
	
	return ActionResult<CTFBot>::Continue();
}

ActionResult<CTFBot> CTFBotDead::Update(CTFBot *actor, float f1)
{
	// TODO
}
