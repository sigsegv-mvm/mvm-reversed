/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/spy/tf_bot_spy_escape.cpp
 * used in MvM: TODO
 */


CTFBotSpyEscape::CTFBotSpyEscape()
{
}

CTFBotSpyEscape::~CTFBotSpyEscape()
{
}


const char *CTFBotSpyEscape::GetName() const
{
	return "SpyEscape";
}


ActionResult<CTFBot> CTFBotSpyEscape::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	CONTINUE();
}

ActionResult<CTFBot> CTFBotSpyEscape::Update(CTFBot *actor, float dt)
{
	CONTINUE();
}


QueryResponse CTFBotSpyEscape::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	return QueryResponse::NO;
}
