/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_behavior.cpp
 * used in MvM: TODO
 */


CTFBotMainAction::CTFBotMainAction(/* TODO */)
 {
 	// TODO
 }
 
CTFBotMainAction::~CTFBotMainAction()
{
}


const char *CTFBotMainAction::GetName() const
{
	return "MainAction";
}


ActionResult<CTFBot> CTFBotMainAction::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	// TODO
	
	return ActionResult<CTFBot>::Continue();
}

ActionResult<CTFBot> CTFBotMainAction::Update(CTFBot *actor, float dt)
{
	VPROF_BUDGET("CTFBotMainAction::Update", "NextBot");
	
	if (!actor->IsAlive()) {
		return ActionResult<CTFBot>::ChangeTo(new CTFBotDead(), "I died!");
	}
	
	if (actor->GetTeamNumber() != TF_TEAM_BLUE &&
		actor->GetTeamNumber() != TF_TEAM_RED) {
		return ActionResult<CTFBot>::Done("Not on a playing team");
	}
	
	if (actor->FindPartnerTauntInitiator()) {
		return ActionResult<CTFBot>::SuspendFor(new CTFBotTaunt(),
			"Responding to teammate partner taunt");
	}
	
	actor->GetVisionInterface()->SetFieldOfView(actor->GetFOV());
	
	if (g_pGameRules->IsInTraining() && actor->GetTeamNumber() == TF_TEAM_BLUE) {
		// TODO: enum for GiveAmmo param 2?
		// TODO: default val for GiveAmmo param 3?
		actor->GiveAmmo(1000, 3, true);
	}
	
	actor->EyeAngles();
	
	// TODO
}


Action<CTFBot> *CTFBotMainAction::InitialContainedAction(CTFBot *actor)
{
	// TODO: get ctor args for CTFBotTacticalMonitor
	return new CTFBotTacticalMonitor(/* TODO */);
}


EventDesiredResult<CTFBot> CTFBotMainAction::OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace)
{
	// TODO
}


EventDesiredResult<CTFBot> CTFBotMainAction::OnStuck(CTFBot *actor)
{
	// TODO
}


EventDesiredResult<CTFBot> CTFBotMainAction::OnInjured(CTFBot *actor, const CTakeDamageInfo& info)
{
	// TODO
}

EventDesiredResult<CTFBot> CTFBotMainAction::OnOtherKilled(CTFBot *actor, CBaseCombatCharacter *who, const CTakeDamageInfo& info)
{
	// TODO
}


QueryResponse CTFBotMainAction::ShouldHurry(const INextBot *nextbot) const
{
	// TODO
}

QueryResponse CTFBotMainAction::ShouldRetreat(const INextBot *nextbot) const
{
	// TODO
}

QueryResponse CTFBotMainAction::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	// TODO
}

Vector CTFBotMainAction::SelectTargetPoint(const INextBot *nextbot, const CBaseCombatCharacter *them) const
{
	// TODO
}

QueryResponse CTFBotMainAction::IsPositionAllowed(const INextBot *nextbot, const Vector& v1) const
{
	return QueryResponse::YES;
}

const CKnownEntity *CTFBotMainAction::SelectMoreDangerousThreat(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const
{
	CTFBot *actor = ToTFBot(nextbot->GetEntity());
	
	const CKnownEntity *result = this->SelectMoreDangerousThreatInternal(actor, them, threat1, threat2);
	
	if (actor->m_iSkill != CTFBot::DifficultyType::EASY &&
		actor->m_iSkill != CTFBot::DifficultyType::NORMAL) {
		if (actor->TransientlyConsistentRandomValue(10.0f, 0) >= 0.5f) {
			return this->GetHealerOfThreat(result);
		}
	}
	
	return result;
}


void CTFBotMainAction::Dodge(CTFBot *actor)
{
	if (actor->m_iSkill == CTFBot::DifficultyType::EASY) {
		return;
	}
	
	if (actor->m_Shared.IsInvulnerable() ||
		actor->m_Shared.InCond(TF_COND_ZOOMED) ||
		actor->m_Shared.InCond(TF_COND_TAUNTING) ||
		(actor->m_nBotAttrs & CTFBot::AttributeType::DISABLEDODGE) != 0 ||
		actor->IsCombatWeapon()) {
		return;
	}
	
	if (actor->GetIntentionInterface()->ShouldHurry() == QueryResponse::YES ||
		actor->IsPlayerClass(TF_CLASS_ENGINEER) ||
		actor->m_Shared.InCond(TF_COND_DISGUISED) ||
		actor->m_Shared.InCond(TF_COND_DISGUISING) ||
		actor->m_Shared.IsStealthed()) {
		return;
	}
	
	const CKnownEntity *threat = this->GetVisionInterface()->GetPrimaryKnownThreat();
	if (threat == nullptr || !threat->IsVisibleRecently()) {
		return;
	}
	
	CTFWeaponBase *weapon = static_cast<CTFWeaponBase *>(actor->Weapon_GetSlot(0));
	if (weapon != nullptr && weapon->IsWeapon(TF_WEAPON_COMPOUND_BOW)) {
		CTFCompoundBow *huntsman = static_cast<CTFCompoundBow *>(weapon);
		if (huntsman->GetCurrentCharge() != 0.0f) {
			return;
		}
	} else {
		if (!this->IsLineOfFireClear(threat->GetLastKnownPosition())) {
			return;
		}
	}
	
	Vector eye_vec;
	actor->EyeVectors(&eye_vec);
	
	Vector2D side_dir = {
		.x = -eye_vec.y,
		.y =  eye_vec.x,
	};
	side_dir.NormalizeInPlace();
	
	int random = RandomInt(0, 100);
	if (random < 33) {
		Vector strafe_left = actor->GetAbsOrigin() + {
			.x = 25.0f * side_dir.x,
			.y = 25.0f * side_dir.y,
			.z = 0.0f,
		};
		
		if (!actor->GetLocomotionInterface()->HasPotentialGap(
			actor->GetAbsOrigin(), strafe_left, nullptr)) {
			actor->PressLeftButton();
		}
	} else if (rand > 66) {
		Vector strafe_right = actor->GetAbsOrigin() - {
			.x = 25.0f * side_dir.x,
			.y = 25.0f * side_dir.y,
			.z = 0.0f,
		};
		
		if (!actor->GetLocomotionInterface()->HasPotentialGap(
			actor->GetAbsOrigin(), strafe_right, nullptr)) {
			actor->PressRightButton();
		}
	}
}

void CTFBotMainAction::FireWeaponAtEnemy(CTFBot *actor)
{
	// TODO
}

const CKnownEntity *CTFBotMainAction::GetHealerOfThreat(const CKnownEntity *threat) const
{
	if (threat == nullptr || threat->GetEntity() == nullptr) {
		return nullptr;
	}
	
	CTFPlayer *threat_player = ToTFPlayer(threat->GetEntity());
	if (threat_player == nullptr) {
		return threat;
	}
	
	const CKnownEntity *healer = threat;
	
	for (int i = 0; i < threat_player->m_Shared.m_nNumHealers; ++i) {
		CTFPlayer *healer_i = ToTFPlayer(threat_player->m_Shared.GetHealerByIndex(i));
		if (healer_i != nullptr) {
			healer = this->GetActor()->GetVisionInterface()->GetKnown(healer_i);
			if (healer != nullptr && healer->IsVisibleInFOVNow()) {
				break;
			}
		}
	}
	
	return healer;
}

bool CTFBotMainAction::IsImmediateThreat(const CBaseCombatCharacter *who, const CKnownEntity *known) const
{
	// TODO
}

const CKnownEntity *CTFBotMainAction::SelectCloserThreat(CTFBot *actor, const CKnownEntity *known1, const CKnownEntity *known2) const
{
	// TODO
}

const CKnownEntity *CTFBotMainAction::SelectMoreDangerousThreatInternal(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const
{
	// TODO
}


const CKnownEntity *SelectClosestSpyToMe(CTFBot *actor, const CKnownEntity *known1, const CKnownEntity *known2)
{
	CTFPlayer *spy1 = ToTFPlayer(known1->GetEntity());
	CTFPlayer *spy2 = ToTFPlayer(known2->GetEntity());
	
	bool spy1_valid = (spy1 != nullptr && spy1->IsPlayerClass(TF_CLASS_SPY));
	bool spy2_valid = (spy2 != nullptr && spy2->IsPlayerClass(TF_CLASS_SPY));
	
	if (spy1_valid && spy2_valid) {
		float range1 = actor->GetRangeSquaredTo(spy1);
		float range2 = actor->GetRangeSquaredTo(spy2);
		
		if (range1 > range2) {
			return known2;
		} else {
			return known1;
		}
	}
	
	if (spy1_valid) {
		return known1;
	}
	if (spy2_valid) {
		return known2;
	}
	
	return nullptr;
}
