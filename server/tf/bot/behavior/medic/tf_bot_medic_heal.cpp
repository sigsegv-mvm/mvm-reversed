/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/medic/tf_bot_medic_heal.cpp
 * used in MvM: TODO
 */


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

ActionResult<CTFBot> CTFBotMedicHeal::Update(CTFBot *actor, float f1)
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
