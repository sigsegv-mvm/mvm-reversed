/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/missions/tf_bot_mission_suicide_bomber.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_suicide_bomb_range("tf_bot_suicide_bomb_range", "300", FCVAR_CHEAT);
ConVar tf_bot_suicide_bomb_friendly_fire("tf_bot_suicide_bomb_friendly_fire", "1", FCVAR_CHEAT);


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
	this->m_bDetonating       = false;
	this->m_bDetReachedGoal   = false;
	this->m_bDetLostAllHealth = false;
	
	this->m_PathFollower->SetMinLookaheadDistance(actor->GetDesiredPathLookAheadRange);
	
	this->m_ctTimer3->Invalidate();
	this->m_nConsecutivePathFailures = 0;
	
	if (actor->m_hSBTarget() != nullptr) {
		CBaseEntity *target = actor->m_hSBTarget();
		this->m_hTarget = target;
		
		if (target != nullptr) {
			this->m_vecTargetPos = target->GetAbsOrigin();
		}
	} else {
		this->m_hTarget = nullptr;
	}
	
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
	if (!this->m_bDetonating && !this->m_ctTimer3.HasStarted()) {
		this->StartDetonate(actor, false, false);
	}
	
	return EventDesiredResult<CTFBot>::Continue();
}


EventDesiredResult<CTFBot> CTFBotMissionSuicideBomber::OnKilled(CTFBot *actor, const CTakeDamageInfo& info)
{
	/* how we get here:
	 * CBaseCombatCharacter::Event_Killed
	 * NextBotManager::OnKilled
	 * Action<CTFBot>::OnKilled
	 * CTFBotMissionSuicideBomber::OnKilled
	 */
	
	if (!this->m_bDetonating) {
		if (!this->m_ctTimer3.HasStarted()) {
			this->StartDetonate(actor, false, false);
		} else {
			/* BUG: probably bad to call Detonate when m_bDetonating is false
			 * and we haven't called StartDetonate... */
			if (this->m_ctTimer3.IsElapsed()) {
				this->Detonate();
			} else {
				if (actor->GetTeamNumber != TEAM_SPECTATOR) {
					actor->m_lifeState = LIFE_ALIVE;
					actor->SetHealth(1);
				}
			}
		}
	}
	
	return EventDesiredResult<CTFBot>::Continue();
}


QueryResponse CTFBotMissionSuicideBomber::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	return QueryResponse::NO;
}


void CTFBotMissionSuicideBomber::StartDetonate(CTFBot *actor, bool reached_goal, bool lost_all_health)
{
	if (this->m_ctTimer3.HasStarted()) {
		return;
	}
	
	if ((!actor->IsAlive() || actor->GetHealth() <= 0) &&
		actor->GetTeamNumber() != TEAM_SPECTATOR) {
		actor->m_lifeState = LIFE_ALIVE;
		actor->SetHealth(1);
	}
	
	this->m_bDetReachedGoal   = reached_goal;
	this->m_bDetLostAllHealth = lost_all_health;
	
	actor->m_takedamage = DAMAGE_NO;
	
	// TODO: enum/default values for CTFPlayer::Taunt(taunts_t, int)
	actor->Taunt(0, 0);
	
	this->m_ctTimer3.Start(2.0f);
	
	actor->EmitSound("MvM.SentryBusterSpin");
}

void CTFBotMissionSuicideBomber::Detonate(CTFBot *actor)
{
	this->m_bDetonating = true;
	
	DispatchParticleEffect("explosionTrail_seeds_mvm",
		actor->GetAbsOrigin(), actor->GetAbsAngles());
	DispatchParticleEffect("fluidSmokeExpl_ring_mvm",
		actor->GetAbsOrigin(), actor->GetAbsAngles());
	
	actor->EmitSound("MvM.SentryBusterExplode");
	
	UTIL_ScreenShake(actor->GetAbsOrigin(),
		25.0f, 5.0f, 5.0f, 1000.0f, SHAKE_START);
	
	if (!this->m_bDetReachedGoal && TFGameRules() != nullptr &&
		TFGameRules()->IsMannVsMachineMode()) {
		TFGameRules()->HaveAllPlayersSpeakConceptIfAllowed(
			TLK_MVM_SENTRY_BUSTER_DOWN, TF_TEAM_RED);
		
		for (int i = 0; i < 4; ++i) {
			CTFPlayer *damager = TFGameRules()->GetRecentDamager(actor, i, 5.0f);
			if (damager != nullptr) {
				damager->AwardAchievement(TF_MVM_KILL_SENTRY_BUSTER);
			}
		}
	}
	
	CUtlVector<CTFPlayer *> players_bothteams;
	CollectPlayers<CTFPlayer>(&players_bothteams, TF_TEAM_RED, true, false);
	CollectPlayers<CTFPlayer>(&players_bothteams, TF_TEAM_BLUE, true, true);
	
	CUtlVector<CBaseCombatCharacter *> potential_victims;
	FOR_EACH_VEC(players_bothteams, i) {
		CTFPlayer *player = players_bothteams[i];
		potential_victims.AddToTail(static_cast<CBaseCombatCharacter *>(player));
	}
	
	CTFTeam *team_blu = GetGlobalTFTeam(TF_TEAM_BLUE);
	if (team_blu != nullptr) {
		for (int i = 0; i < team_blu->GetNumObjects(); ++i) {
			CBaseObject *obj = team_blu->GetObject(i);
			if (obj != nullptr) {
				potential_victims.AddToTail(static_cast<CBaseCombatCharacter *>(obj));
			}
		}
	}
	
	CTFTeam *team_red = GetGlobalTFTeam(TF_TEAM_RED);
	if (team_red != nullptr) {
		for (int i = 0; i < team_red->GetNumObjects(); ++i) {
			CBaseObject *obj = team_red->GetObject(i);
			if (obj != nullptr) {
				potential_victims.AddToTail(static_cast<CBaseCombatCharacter *>(obj));
			}
		}
	}
	
	CUtlVector<INextBot *> nextbots;
	TheNextBots()->CollectAllBots(&nextbots);
	FOR_EACH_VEC(nextbots, i) {
		INextBot *nextbot = nextbots[i];
		CBaseEntity *ent = nextbot->GetEntity();
		
		if (!ent->IsPlayer() && ent->IsAlive()) {
			potential_victims.AddToTail(ent);
		}
	}
	
	if (this->m_bDetLostAllHealth) {
		CGameEvent *event = gameeventmanager->CreateEvent("mvm_sentrybuster_killed");
		if (event != nullptr) {
			event->SetInt("sentry_buster", ENTINDEX(actor));
			gameeventmanager->FireEvent(event);
		}
	}
	
	// TODO: enum for (CTFBot::MissionType)0
	actor->SetMission(0, false);
	
	actor->m_takedamage = DAMAGE_YES;
	
	FOR_EACH_VEC(potential_victims, i) {
		CBaseCombatCharacter *victim = potential_victims[i];
		
		Vector delta_wsc = victim->WorldSpaceCenter() - actor->WorldSpaceCenter();
		float dist_sqr = delta_wsc.LengthSqr();
		
		if (dist_sqr > (tf_bot_suicide_bomb_range.GetFloat() *
			tf_bot_suicide_bomb_range.GetFloat())) {
			continue;
		}
		
		if (victim->IsPlayer()) {
			UTIL_ScreenFade(victim, {
				.r = 255,
				.g = 255,
				.b = 255,
				.a = 255,
			}, 1.0f, 0.1f, FFADE_IN);
		}
		
		if (actor->IsLineOfFireClear(victim)) {
			float dmg = victim->GetHealth();
			if (victim->GetHealth() > victim->GetMaxHealth()) {
				dmg = victim->GetMaxHealth();
			}
			
			/* NOTE: CTFPlayer::OnTakeDamage reduces the damage to 600 if:
			 * victim is a bot
			 * m_bForceFriendlyFire is true
			 * victim in same team as attacker
			 * victim->IsMiniBoss
			 */
			
			CTakeDamageInfo dmginfo;
			if (tf_bot_suicide_bomb_friendly_fire.GetBool()) {
				dmginfo.SetForceFriendlyFire(true);
			}
			
			CalculateMeleeDamageForce(&dmginfo, VectorNormalize(delta_wsc),
				actor->WorldSpaceCenter());
			victim->TakeDamage(dmginfo);
		}
	}
	
	if (actor->IsAlive()) {
		actor->ForceChangeTeam(TEAM_SPECTATOR, false);
	}
	
	if (this->m_bDetLostAllHealth) {
		CWave *wave = g_pPopulationManager->GetCurrentWave();
		if (wave != nullptr) {
			// TODO: name for CWave::field_34
			++wave->field_34;
		}
	}
}
