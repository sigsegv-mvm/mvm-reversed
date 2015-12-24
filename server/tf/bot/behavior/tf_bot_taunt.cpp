/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_taunt.cpp
 * used in MvM: TODO
 */


CTFBotTaunt::CTFBotTaunt()
{
}

CTFBotTaunt::~CTFBotTaunt()
{
}


const char *CTFBotTaunt::GetName() const
{
	return "Taunt";
}


ActionResult<CTFBot> CTFBotTaunt::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	this->m_ctStart.Start(RandomFloat(0.0f, 1.0f));
	this->m_bStartedTaunting = false;
	
	CONTINUE();
}

ActionResult<CTFBot> CTFBotTaunt::Update(CTFBot *actor, float dt)
{
	if (this->m_ctStart.IsElapsed()) {
		// TODO
	}
	
	CONTINUE();
}
