/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_attack.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_path_lookahead_range("tf_bot_path_lookahead_range", "300", FCVAR_NONE);
ConVar tf_bot_sniper_aim_error("tf_bot_sniper_aim_error", "0.01", FCVAR_CHEAT);
ConVar tf_bot_sniper_aim_steady_rate("tf_bot_sniper_aim_steady_rate", "10", FCVAR_CHEAT);
ConVar tf_bot_debug_sniper("tf_bot_debug_sniper", "0", FCVAR_CHEAT);
ConVar tf_bot_fire_weapon_min_time("tf_bot_fire_weapon_min_time", "1", FCVAR_CHEAT);
ConVar tf_bot_taunt_victim_chance("tf_bot_taunt_victim_chance", "20", FCVAR_NONE);
ConVar tf_bot_notice_backstab_chance("tf_bot_notice_backstab_chance", "25", FCVAR_CHEAT);
ConVar tf_bot_notice_backstab_min_chance("tf_bot_notice_backstab_min_chance", "100", FCVAR_CHEAT);
ConVar tf_bot_notice_backstab_max_chance("tf_bot_notice_backstab_max_chance", "750", FCVAR_CHEAT);
ConVar tf_bot_arrow_elevation_rate("tf_bot_arrow_elevation_rate", "0.0001", FCVAR_CHEAT,
	"When firing arrows at far away targets, this is the degree/range slope to raise our aim");
ConVar tf_bot_ballistic_elevation_rate("tf_bot_ballistic_elevation_rate", "0.01", FCVAR_CHEAT,
	"When lobbing grenades at far away targets, this is the degree/range slope to raise our aim");
ConVar tf_bot_hitscan_range_limit("tf_bot_hitscan_range_limit", "1800", FCVAR_CHEAT);
ConVar tf_bot_always_full_reload("tf_bot_always_full_reload", "0", FCVAR_CHEAT);
ConVar tf_bot_fire_weapon_allowed("tf_bot_fire_weapon_allowed", "1", FCVAR_CHEAT,
	"If zero, TFBots will not pull the trigger of their weapons (but will act like they did)");


CTFBotAttack::CTFBotAttack()
{
}

CTFBotAttack::~CTFBotAttack()
{
}


const char *CTFBotAttack::GetName() const
{
	return "Attack";
}


ActionResult<CTFBot> CTFBotAttack::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	this->m_PathFollower.SetMinLookaheadDistance(actor->GetDesiredPathLookAheadRange());
	
	return ActionResult<CTFBot>::Continue();
}

ActionResult<CTFBot> CTFBotAttack::Update(CTFBot *actor, float dt)
{
	bool is_melee = false;
	
	CTFWeaponBase *weapon = actor->GetActiveTFWeapon();
	if (weapon != nullptr) {
		if (weapon->IsWeapon(TF_WEAPON_FLAMETHROWER) || weapon->IsMeleeWeapon()) {
			is_melee = true;
		}
	}
	
	const CKnownEntity *threat = actor->GetVisionInterface()->GetPrimaryKnownThreat();
	if (threat == nullptr || threat->IsObsolete() || actor->GetIntentionInterface()->ShouldAttack(actor, threat) == QueryResponse::NO) {
		return ActionResult<CTFBot>::Done("No threat");
	}
	
	actor->EquipBestWeaponForThreat(threat);
	
	if (is_melee && threat->IsVisibleRecently() && actor->IsRangeLessThan(threat->GetLastKnownPosition(),
		1.1f * actor->GetDesiredAttackRange())) {
		if (actor->TransientlyConsistentRandomValue(3.0f, 0) < 0.5f) {
			actor->PressLeftButton();
		} else {
			actor->PressRightButton();
		}
	}
	
	if (threat->IsVisibleRecently() && !actor->IsRangeGreaterThan(threat->GetEntity()->GetAbsOrigin(),
		actor->GetDesiredAttackRange()) && actor->IsLineOfFireClear(threat->GetEntity()->EyePosition())) {
		return ActionResult<CTFBot>::Continue();
	}
	
	if (threat->IsVisibleRecently()) {
		CTFBotPathCost cost_func(actor, (is_melee && TFGameRules()->IsMannVsMachineMode() ? SAFEST_ROUTE : DEFAULT_ROUTE));
		this->m_ChasePath.Update(actor, threat->GetEntity(), cost_func, nullptr);
		
		return ActionResult<CTFBot>::Continue();
	}
	
	this->m_ChasePath.Invalidate();
	
	if (actor->IsRangeLessThan(threat->GetLastKnownPosition(), 20.0f)) {
		actor->GetVisionInterface()->ForgetEntity(threat->GetEntity());
		
		return ActionResult<CTFBot>::Done("I lost my target!");
	}
	
	if (actor->IsRangeLessThan(threat->GetLastKnownPosition(), actor->GetMaxAttackRange())) {
		// HumanEyeHeight = 62.0f, from nav.h; value is from CS:S and is actually a bit wrong for TF2
		Vector eye = threat->GetLastKnownPosition() + Vector(0.0f, 0.0f, HumanEyeHeight);
		
		actor->GetBodyInterface()->AimHeadTowards(eye, IBody::LookAtPriorityType::IMPORTANT, 0.2f, nullptr, "Looking towards where we lost sight of our victim");
	}
	
	this->m_PathFollower.Update(actor);
	
	if (this->m_ctRecomputePath.IsElapsed()) {
		this->m_ctRecomputePath.Start(RandomFloat(3.0f, 5.0f));
		
		CTFBotPathCost cost_func(actor, (is_melee && TFGameRules()->IsMannVsMachineMode() ? SAFEST_ROUTE : DEFAULT_ROUTE));
		this->m_PathFollower.Compute(actor, threat->GetLastKnownPosition(), cost_func, 0.0f, true);
		
		return ActionResult<CTFBot>::Continue();
	}
}


EventDesiredResult<CTFBot> CTFBotAttack::OnMoveToSuccess(CTFBot *actor, const Path *path)
{
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotAttack::OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail)
{
	return EventDesiredResult<CTFBot>::Continue();
}

EventDesiredResult<CTFBot> CTFBotAttack::OnStuck(CTFBot *actor)
{
	return EventDesiredResult<CTFBot>::Continue();
}


QueryResponse CTFBotAttack::ShouldHurry(const INextBot *nextbot) const
{
	return QueryResponse::DONTCARE;
}

QueryResponse CTFBotAttack::ShouldRetreat(const INextBot *nextbot) const
{
	return QueryResponse::DONTCARE;
}
