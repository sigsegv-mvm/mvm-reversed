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
	if (actor->m_Squad != nullptr) {
		// TODO
	} else {
		actor->SetMission(CTFBot::MissionType::NONE, false);
	}
	
	this->m_hPatient = this->SelectPatient(actor, this->m_hPatient);
	
	if (TFGameRules() != nullptr && TFGameRules()->IsMannVsMachineMode()) {
		if (this->m_hPatient->IsPlayerClass(TF_CLASS_MEDIC)) {
			// TODO
			// stack space for the CUtlVector is shared with path computation junk, ugh
		}
	}
	
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

EventDesiredResult<CTFBot> CTFBotMedicHeal::OnActorEmoted(CTFBot *actor, CBaseCombatCharacter *who, int concept)
{
	if (!who->IsPlayer()) {
		return EventDesiredResult<CTBot>::Continue();
	}
	
	CTFPlayer *player = ToTFPlayer(who);
	if (player == nullptr) {
		return EventDesiredResult<CTBot>::Continue();
	}
	
	if (concept == MP_CONCEPT_PLAYER_GO ||
		concept == MP_CONCEPT_PLAYER_ACTIVATECHARGE) {
		CTFPlayer *patient = this->m_hPatient();
		if (patient != nullptr && player != nullptr &&
			ENTINDEX(player) == ENTINDEX(patient)) {
			CWeaponMedigun *medigun = dynamic_cast<CWeaponMedigun *>(
				actor->m_Shared.GetActiveTFWeapon());
			
			if (this->IsReadyToDeployUber(medigun)) {
				actor->PressAltFireButton();
			}
		}
	}
	
	return EventDesiredResult<CTFBot>::Continue();
}


QueryResponse CTFBotMedicHeal::ShouldHurry(const INextBot *nextbot) const
{
	return QueryResponse::YES;
}

QueryResponse CTFBotMedicHeal::ShouldRetreat(const INextBot *nextbot) const
{
	CTFBot *actor = static_cast<CTFBot *>(nextbot->GetEntity());
	
	return (actor->m_Shared.IsControlStunned() ||
		actor->m_Shared.IsLoserStateStunned());
}

QueryResponse CTFBotMedicHeal::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	CTFBot *actor = static_cast<CTFBot *>(nextbot->GetEntity());
	
	return actor->IsCombatWeapon();
}


void CTFBotMedicHeal::ComputeFollowPosition(CTFBot *actor)
{
	VPROF_BUDGET("CTFBotMedicHeal::ComputeFollowPosition", "NextBot");
	
	this->m_vecFollowPosition = actor->GetAbsOrigin();
	
	// TODO
}

bool CTFBotMedicHeal::IsGoodUberTarget(CTFPlayer *player) const
{
	if (player->IsPlayerClass(TF_CLASS_MEDIC) ||
		player->IsPlayerClass(TF_CLASS_SNIPER) ||
		player->IsPlayerClass(TF_CLASS_ENGINEER) ||
		player->IsPlayerClass(TF_CLASS_SCOUT) ||
		player->IsPlayerClass(TF_CLASS_SPY)) {
		return false;
	}
	
	/* BUG: this function always returns false! */
	return false;
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

CTFPlayer *CTFBotMedicHeal::SelectPatient(CTFBot *actor, CTFPlayer *old_patient)
{
	// TODO
}


bool CKnownCollector::Inspect(const CKnownEntity& known)
{
	this->m_KnownEntities.AddToTail(&known);
	return true;
}


bool CFindMostInjuredNeighbor::Inspect(const CKnownEntity& known)
{
	if (!known.GetEntity()->IsPlayer()) {
		return true;
	}
	
	CTFPlayer *player = ToTFPlayer(known.GetEntity());
	if (this->m_pMedic->IsRangeGreaterThan(player, this->m_flRangeLimit) ||
		!this->m_pMedic->IsLineOfFireClear(player->EyePosition())) {
		return true;
	}
	
	if (this->m_pMedic->IsSelf(player) || !player->IsAlive() ||
		player->InSameTeam(this->m_pMedic)) {
		return true;
	}
	
	float max_health;
	if (this->m_bUseNonBuffedMaxHealth) {
		max_health = (float)player->GetMaxHealth();
	} else {
		max_health = (float)player->GetMaxBuffedHealth(false, false);
	}
	
	float health_ratio = (float)player->GetHealth() / max_health;
	
	if (this->m_bIsOnFire) {
		if (!player->m_Shared.InCond(TF_COND_BURNING)) {
			return true;
		}
	} else {
		if (player->m_Shared.InCond(TF_COND_BURNING)) {
			this->m_pMostInjured = player;
			this->m_flHealthRatio = health_ratio;
			this->m_bIsOnFire = true;
			return true;
		}
	}
	
	if (health_ratio < this->m_flHealthRatio) {
		this->m_pMostInjured = player;
		this->m_flHealthRatio = health_ratio;
	}
	
	return true;
}


bool CSelectPrimaryPatient::Inspect(const CKnownEntity& known)
{
	/* BUG: medics will refuse to heal friendly spies because they magically
	 * know whether players are actually friendly instead of believing the
	 * spy's disguise */
	if (known.GetEntity() == nullptr ||
		!known.GetEntity()->IsPlayer() ||
		!known.GetEntity()->IsAlive() ||
		!this->m_pMedic->IsFriend(known.GetEntity())) {
		return true;
	}
	
	CTFPlayer *player = dynamic_cast<CTFPlayer *>(known.GetEntity());
	if (player == nullptr || this->m_pMedic->IsSelf(player)) {
		return true;
	}
	
	if (!player->HasTheFlag() && !this->m_pMedic->m_Squad == nullptr)
		if (player->IsPlayerClass(TF_CLASS_MEDIC) ||
			player->IsPlayerClass(TF_CLASS_SNIPER) ||
			player->IsPlayerClass(TF_CLASS_ENGINEER) ||
			player->IsPlayerClass(TF_CLASS_SPY))) {
			return true;
		}
	}
	
	CTFPlayer *patient = this->m_pPatient;
	
	if (TFGameRules()->IsInTraining()) {
		if (patient != nullptr && !patient->IsBot()) {
			this->m_pPatient = patient;
			return true;
		} else {
			this->m_pPatient = player;
			return true;
		}
	}
	
	if (ENTINDEX(this->m_pMedic->m_Squad->GetLeader()) == ENTINDEX(patient)) {
		this->m_pPatient = patient;
		return true;
	}
	
	if (ENTINDEX(this->m_pMedic->m_Squad->GetLeader()) == ENTINDEX(player)) {
		this->m_pPatient = player;
		return true;
	}
	
	int num_healers = patient->m_Shared.m_nNumHealers;
	for (int i = 0; i < num_healers; ++i) {
		CTFPlayer *healer = ToTFPlayer(patient->m_Shared.GetHealerByIndex(i));
		if (healer != nullptr) {
			if (!this->m_pMedic->IsSelf(healer)) {
				this->m_pPatient = player;
				return true;
			}
		}
	}
	
	for (int i = 0; i < player->m_Shared.m_nNumHealers; ++i) {
		CTFBotPathCost cost_func(this->m_pMedic, FASTEST_ROUTE);
		
	}
	
	
	// TODO
	
	return true;
}

UNKNOWN CSelectPrimaryPatient::SelectPreferred(CTFPlayer *player1, CTFPlayer *player2)
{
	static int preferredClass[] = {
		TF_CLASS_HEAVYWEAPONS,
		TF_CLASS_SOLDIER,
		TF_CLASS_PYRO,
		TF_CLASS_DEMOMAN,
		TF_CLASS_UNDEFINED,
	}
	
	// TODO
}
