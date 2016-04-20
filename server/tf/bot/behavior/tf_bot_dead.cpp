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
	this->m_itDeathEpoch.Start();
	
	return Continue();
}

ActionResult<CTFBot> CTFBotDead::Update(CTFBot *actor, float dt)
{
	if (actor->IsAlive()) {
		// TODO: figure out constructor args for CTFBotMainAction
		return ChangeTo(new CTFBotMainAction(/* TODO */), "This should not happen!");
	}
	
	if (!this->m_itDeathEpoch.IsGreaterThen(5.0f)) {
		return Continue();
	}
	
	if ((actor->m_nBotAttrs & CTFBot::AttributeType::REMOVEONDEATH) != 0) {
		// TODO: kickid stuff
		return Continue();
	}
	
	if ((actor->m_nBotAttrs & CTFBot::AttributeType::BECOMESPECTATORONDEATH) == 0) {
		return Continue();
	}
	
	actor->ChangeTeam(TEAM_SPECTATOR, false, true);
	return Done();
}
