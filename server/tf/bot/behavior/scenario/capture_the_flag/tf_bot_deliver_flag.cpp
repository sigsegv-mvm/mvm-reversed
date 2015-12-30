/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/scenario/capture_the_flag/tf_bot_deliver_flag.cpp
 * used in MvM: TODO
 */


ConVar tf_mvm_bot_allow_flag_carrier_to_fight("tf_mvm_bot_allow_flag_carrier_to_fight", "1", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_1st_upgrade("tf_mvm_bot_flag_carrier_interval_to_1st_upgrade", "5", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_2nd_upgrade("tf_mvm_bot_flag_carrier_interval_to_2nd_upgrade", "15", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_3rd_upgrade("tf_mvm_bot_flag_carrier_interval_to_3rd_upgrade", "15", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_health_regen("tf_mvm_bot_flag_carrier_health_regen", "45.0f", FCVAR_CHEAT);


CTFBotDeliverFlag::CTFBotDeliverFlag(/* TODO */)
{
	// TODO
}

CTFBotDeliverFlag::~CTFBotDeliverFlag()
{
}


const char *CTFBotDeliverFlag::GetName() const
{
	return "DeliverFlag";
}


ActionResult<CTFBot> CTFBotDeliverFlag::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}

ActionResult<CTFBot> CTFBotDeliverFlag::Update(CTFBot *actor, float dt)
{
	// TODO
	
	// NOTE: CTFBotDeliverFlag::Update
	// calls CTFBotPathCost::CTFBotPathCost
	// which is only in certain versions (e.g. ServerLinux 20140619a)
}

void CTFBotDeliverFlag::OnEnd(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
}


EventDesiredResult<CTFBot> CTFBotDeliverFlag::OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace)
{
	// TODO
}


QueryResponse CTFBotDeliverFlag::ShouldHurry(const INextBot *nextbot) const
{
	return QueryResponse::YES;
}

QueryResponse CTFBotDeliverFlag::ShouldRetreat(const INextBot *nextbot) const
{
	return QueryResponse::NO;
}

QueryResponse CTFBotDeliverFlag::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	if (tf_mvm_bot_allow_flag_carrier_to_fight.GetBool()) {
		return QueryResponse::YES;
	} else {
		return QueryResponse::NO;
	}
}


bool CTFBotDeliverFlag::UpgradeOverTime(CTFBot *actor)
{
	// TODO
}


CTFBotPushToCapturePoint::CTFBotPushToCapturePoint(Action<CTFBot> *done_action)
{
	this->m_DoneAction = done_action;
}

CTFBotPushToCapturePoint::~CTFBotPushToCapturePoint()
{
}


const char *CTFBotPushToCapturePoint::GetName() const
{
	return "PushToCapturePoint";
}


ActionResult<CTFBot> CTFBotPushToCapturePoint::Update(CTFBot *actor, float dt)
{
	// TODO
}


EventDesiredResult<CTFBot> CTFBotPushToCapturePoint::OnNavAreaChanged(CTFBot *actor, CNavArea *area1, CNavArea *area2)
{
	if (area1 == nullptr || !area1->HasPrerequisite) {
		return Continue();
	}
	
	FOR_EACH_VEC(area1->GetPrerequisiteVector(), i) {
		CFuncNavPrerequisite *prereq = area1->GetPrerequisiteVector()[i]();
		if (prereq == nullptr || prereq->m_isDisabled ||
			!prereq->PassesTriggerFilters(actor)) {
			continue;
		}
		
		if (prereq->IsTask(CFuncNavPrerequisite::TaskType::WAIT)) {
			SUSPEND_FOR(new CTFBotNavEntMoveTo(prereq,
				"Prerequisite commands me to move to an entity"));
		}
		
		if (prereq->IsTask(CFuncNavPrerequisite::TaskType::MOVE_TO)) {
			SUSPEND_FOR(new CTFBotNavEntWait(prereq,
				"Prerequisite commands me to wait"));
		}
	}
	
	return Continue();
}
