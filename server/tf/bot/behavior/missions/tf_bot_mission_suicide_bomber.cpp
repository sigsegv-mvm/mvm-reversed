/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/missions/tf_bot_mission_suicide_bomber.cpp
 * used in MvM: TODO
 */


CTFBotMissionSuicideBomber::CTFBotMissionSuicideBomber()
{
}

CTFBotMissionSuicideBomber::~CTFBotMissionSuicideBomber()
{
}

const char *CTFBotMissionSuicideBomber::GetName() const
{
	return "MissionSuicideBomber";
}


ActionResult<CTFBot> CTFBotMissionSuicideBomber::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
	
	return ActionResult<CTFBot>::Continue();
}

ActionResult<CTFBot> CTFBotMissionSuicideBomber::Update(CTFBot *actor, float f1)
{
	// TODO
}

void CTFBotMissionSuicideBomber::OnEnd(CTFBot *actor, Action<CTFBot> *action)
{
}


EventDesiredResult<CTFBot> CTFBotMissionSuicideBomber::OnStuck(CTFBot *actor)
{
	// TODO
	
	return EventDesiredResult<CTFBot>::Continue();
}


EventDesiredResult<CTFBot> CTFBotMissionSuicideBomber::OnKilled(CTFBot *actor, const CTakeDamageInfo& info)
{
	// TODO
	
	return EventDesiredResult<CTFBot>::Continue();
}


QueryResponse CTFBotMissionSuicideBomber::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	return QueryResponse::NO;
}
