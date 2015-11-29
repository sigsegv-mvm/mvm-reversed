/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: taunt
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
	
	return ActionResult<CTFBot>::Continue();
}

ActionResult<CTFBot> CTFBotTaunt::Update(CTFBot *actor, float f1)
{
	if (this->m_ctStart.IsElapsed()) {
		// TODO
	}
	
	return ActionResult<CTFBot>::Continue();
}
