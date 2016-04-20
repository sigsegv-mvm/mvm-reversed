/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_seek_and_destroy.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_debug_seek_and_destroy("tf_bot_debug_seek_and_destroy", "0", FCVAR_CHEAT);


CTFBotSeekAndDestroy::CTFBotSeekAndDestroy(float duration)
{
	// BUG: apparent default parameter doesn't match this check
	// (see also: CTFBotAttackFlagDefenders)
	if (duration != 0.0f) {
		this->m_ctActionDuration.Start(duration);
	}
}

CTFBotSeekAndDestroy::~CTFBotSeekAndDestroy()
{
}


const char *CTFBotSeekAndDestroy::GetName() const
{
	return "SeekAndDestroy";
}


ActionResult<CTFBot> CTFBotSeekAndDestroy::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	this->m_PathFollower.SetMinLookAheadDistance(actor->GetDesiredPathLookAheadRange());
	
	this->RecomputeSeekPath(actor);
	
	// TODO
	
	return ActionResult<CTFBot>::Continue();
}

ActionResult<CTFBot> CTFBotSeekAndDestroy::Update(CTFBot *actor, float dt)
{
	// TODO
}

ActionResult<CTFBot> CTFBotSeekAndDestroy::OnResume(CTFBot *actor, Action<CTFBot> *action)
{
	this->RecomputeSeekPath(actor);
	
	return ActionResult<CTFBot>::Continue();
}


EventDesiredResult<CTFBot> CTFBotSeekAndDestroy::OnMoveToSuccess(CTFBot *actor, const Path *path)
{
	this->RecomputeSeekPath(actor);
	
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotSeekAndDestroy::OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail)
{
	this->RecomputeSeekPath(actor);
	
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotSeekAndDestroy::OnStuck(CTFBot *actor)
{
	this->RecomputeSeekPath(actor);
	
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotSeekAndDestroy::OnTerritoryContested(CTFBot *actor, int i1)
{
	return EventDesiredResult<CTFBot>::Done("Defending the point", ResultSeverity::MEDIUM);
}

EventDesiredResult<CTFBot> CTFBotSeekAndDestroy::OnTerritoryCaptured(CTFBot *actor, int i1)
{
	return EventDesiredResult<CTFBot>::Done("Giving up due to point capture", ResultSeverity::MEDIUM);
}

EventDesiredResult<CTFBot> CTFBotSeekAndDestroy::OnTerritoryLost(CTFBot *actor, int i1)
{
	return EventDesiredResult<CTFBot>::Done("Giving up due to point lost", ResultSeverity::MEDIUM);
}


QueryResponse CTFBotSeekAndDestroy::ShouldHurry(const INextBot *nextbot) const
{
	return QueryResponse::DONTCARE;
}

QueryResponse CTFBotSeekAndDestroy::ShouldRetreat(const INextBot *nextbot) const
{
	if (nextbot->GetEntity()->IsPlayerClass(TF_CLASS_PYRO)) {
		return QueryResponse::NO;
	} else {
		return QueryResponse::DONTCARE;
	}
}


CTFNavArea *CTFBotSeekAndDestroy::ChooseGoalArea(CTFBot *actor)
{
	CUtlVector<CTFNavArea *> areas;
	TheNavMesh->CollectSpawnRoomThresholdAreas(&areas, GetEnemyTeam(actor));
	
	CTeamControlPoint *point = actor->GetMyControlPoint();
	if (point != nullptr) {
		// TODO
	}
	
	if (tf_bot_debug_seek_and_destroy.GetBool()) {
		
	}
	
	
	// TODO
}

void CTFBotSeekAndDestroy::RecomputeSeekPath(CTFBot *actor)
{
	// TODO
}


// TODO: need CTeamControlPoint *CTFBot::GetMyControlPoint
