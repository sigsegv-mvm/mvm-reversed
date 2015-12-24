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
	
	CONTINUE();
}

ActionResult<CTFBot> CTFBotDead::Update(CTFBot *actor, float dt)
{
	if (actor->IsAlive()) {
		// TODO: figure out constructor args for CTFBotMainAction
		CHANGE_TO(new CTFBotMainAction(/* TODO */), "This should not happen!");
	}
	
	if (!this->m_itTimeSinceDeath.IsGreaterThen(5.0f)) {
		CONTINUE();
	}
	
	if ((actor->m_nBotAttrs & CTFBot::AttributeType::REMOVEONDEATH) != 0) {
		// TODO: kickid stuff
		CONTINUE();
	}
	
	if ((actor->m_nBotAttrs & CTFBot::AttributeType::BECOMESPECTATORONDEATH) == 0) {
		CONTINUE();
	}
	
	actor->ChangeTeam(TEAM_SPECTATOR, false, true);
	DONE();
}
