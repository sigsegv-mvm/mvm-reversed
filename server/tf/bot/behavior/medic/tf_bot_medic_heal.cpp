/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/medic/tf_bot_medic_heal.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_medic_stop_follow_range("tf_bot_medic_stop_follow_range", "75", FCVAR_CHEAT);
ConVar tf_bot_medic_start_follow_range("tf_bot_medic_start_follow_range", "250", FCVAR_CHEAT);
ConVar tf_bot_medic_max_heal_range("tf_bot_medic_max_heal_range", "600", FCVAR_CHEAT);
ConVar tf_bot_medic_debug("tf_bot_medic_debug", "0", FCVAR_CHEAT);
ConVar tf_bot_medic_max_call_response_range("tf_bot_medic_max_call_response_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_medic_cover_test_resolution("tf_bot_medic_cover_test_resolution", "8", FCVAR_CHEAT);


CTFBotMedicHeal::CTFBotMedicHeal()
{
}

CTFBotMedicHeal::~CTFBotMedicHeal()
{
}


const char *CTFBotMedicHeal::GetName() const
{
	return "Heal";
}


ActionResult<CTFBot> CTFBotMedicHeal::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
	
	return ActionResult<CTFBot>::Continue();
}

ActionResult<CTFBot> CTFBotMedicHeal::Update(CTFBot *actor, float dt)
{
	// TODO
}


ActionResult<CTFBot> CTFBotMedicHeal::OnResume(CTFBot *actor, Action<CTFBot> *action)
{
	// probably ChasePath::Invalidate
	// (seems to be inlined; invalidates a couple CountdownTimers,
	// then calls PathFollower::Invalidate)
	
	// TODO
	
	return ActionResult<CTFBot>::Continue();
}


EventDesiredResult<CTFBot> CTFBotMedicHeal::OnMoveToSuccess(CTFBot *actor, const Path *path)
{
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotMedicHeal::OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail)
{
	return EventDesiredResult<CTFBot>::Continue();
}


EventDesiredResult<CTFBot> CTFBotMedicHeal::OnStuck(CTFBot *actor)
{
	return EventDesiredResult<CTFBot>::Continue();
}


EventDesiredResult<CTFBot> CTFBotMedicHeal::OnActorEmoted(CTFBot *actor, CBaseCombatCharacter *who, int i1)
{
	// TODO
	
	return EventDesiredResult<CTFBot>::Continue();
}


QueryResponse CTFBotMedicHeal::ShouldHurry(const INextBot *nextbot) const
{
	return QueryResponse::YES;
}

QueryResponse CTFBotMedicHeal::ShouldRetreat(const INextBot *nextbot) const
{
	// TODO
}

QueryResponse CTFBotMedicHeal::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	// TODO
}


UNKNOWN CTFBotMedicHeal::ComputeFollowPosition(CTFBot *actor)
{
	// TODO
}

bool CTFBotMedicHeal::IsGoodUberTarget(CTFPlayer *player) const
{
	// TODO
	
	/* BUG: this function always returns false! */
}

bool CTFBotMedicHeal::IsReadyToDeployUber(const CWeaponMedigun *medigun) const
{
	// TODO
}

bool CTFBotMedicHeal::IsStable(CTFPlayer *player) const
{
	// TODO
}

bool CTFBotMedicHeal::IsVisibleToEnemy(CTFBot *actor, const Vector& v1) const
{
	// TODO
}

UNKNOWN CTFBotMedicHeal::SelectPatient(CTFBot *actor, CTFPlayer *player)
{
	// TODO
}
