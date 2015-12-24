/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_idle.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_engineer_mvm_sentry_hint_bomb_forward_range("tf_bot_engineer_mvm_sentry_hint_bomb_forward_range", "0", FCVAR_CHEAT);
ConVar tf_bot_engineer_mvm_sentry_hint_bomb_backward_range("tf_bot_engineer_mvm_sentry_hint_bomb_backward_range", "3000", FCVAR_CHEAT);
ConVar tf_bot_engineer_mvm_hint_min_distance_from_bomb("tf_bot_engineer_mvm_hint_min_distance_from_bomb", "1300", FCVAR_CHEAT);

ConCommand tf_bot_mvm_show_engineer_hint_region_command("tf_bot_mvm_show_engineer_hint_region", &tf_bot_mvm_show_engineer_hint_region,
	"Show the nav areas MvM engineer bots will consider when selecting sentry and teleporter hints", FCVAR_CHEAT);


CTFBotMvMEngineerIdle::CTFBotMvMEngineerIdle()
{
}

CTFBotMvMEngineerIdle::~CTFBotMvMEngineerIdle()
{
}


const char *CTFBotMvMEngineerIdle::GetName() const
{
	return "MvMEngineerIdle";
}


ActionResult<CTFBot> CTFBotMvMEngineerIdle::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	this->m_PathFollower->SetMinLookaheadDistance(actor->GetDesiredPathLookAheadRange);
	
	actor->m_bLookAroundForEnemies = false;
	
	this->m_hHintSentry = nullptr;
	this->m_hHintTele   = nullptr;
	this->m_hHintNest   = nullptr;
	
	this->m_nTeleportAttempts = 0;
	
	this->m_bTeleportedToHint         = false;
	this->m_bTriedToDetonateStaleNest = false;
	
	CONTINUE();
}

ActionResult<CTFBot> CTFBotMvMEngineerIdle::Update(CTFBot *actor, float dt)
{
	if (!actor->IsAlive()) {
		DONE();
	}
	
	// TODO: slot enum
	CBaseCombatWeapon *w_melee = bot->Weapon_GetSlot(2);
	if (w_melee != nullptr) {
		actor->Weapon_Switch(w_melee);
	}
	
	if (this->m_hHintNest() == nullptr || this->ShouldAdvanceNestSpot(actor)) {
		if (this->m_ctFindNestHint.HasStarted()) {
			if (!this->m_ctFindNestHint.IsElapsed()) {
				CONTINUE();
			}
		}
		this->m_ctFindNestHint.Start(RandomFloat(1.0f, 2.0f));
		
		CHandle<CTFBotHintEngineerNest> h_nest;
		
		bool box_check = (!this->m_bTeleportedToHint &&
			(actor->m_nBotAttrs & CTFBot::AttributeType::TELEPORTTOHINT) != 0);
		if (!CTFBotMvMEngineerHintFinder::FindHint(box_check,
			(actor->m_nBotAttrs & CTFBot::AttributeType::TELEPORTTOHINT) == 0,
			&h_nest)) {
			CONTINUE();
		}
		
		CTFBotHintEngineerNest *old_nest = this->m_hHintNest();
		if (old_nest != nullptr) {
			old_nest->SetOwnerEntity(nullptr);
		}
		
		this->m_hHintNest = h_nest;
		
		CTFBotHintEngineerNest *new_nest = h_nest();
		new_nest->SetOwnerEntity(actor);
		
		CTFBotHintSentryGun *hint_sentry = this->m_hHintNest()->GetSentryHint();
		this->m_hHintSentry = hint_sentry;
		this->TakeOverStaleNest(hint_sentry, actor);
		
		if (!actor->m_TeleportWhere.IsEmpty()) {
			CTFBotHintTeleporterExit *hint_tele = this->m_hHintNest()->GetTeleporterHint();
			this->m_hHintTele = hint_tele;
			this->TakeOverStaleNest(hint_tele, actor);
		}
	}
	
	if (!this->m_bTeleportedToHint &&
		(actor->m_nBotAttrs & CTFBot::AttributeType::TELEPORTTOHINT) != 0) {
		this->m_bTeleportedToHint = true;
		SUSPEND_FOR(new CTFBotMvMEngineerTeleportSpawn(this->m_hHintNest(),
			++this->m_nTeleportAttempts == 1), "In spawn area - "
			"teleport to the teleporter hint");
	}
	
	
	
	// TODO
}


QueryResponse CTFBotMvMEngineerIdle::ShouldHurry(const INextBot *nextbot) const
{
	return QueryResponse::YES;
}

QueryResponse CTFBotMvMEngineerIdle::ShouldRetreat(const INextBot *nextbot) const
{
	return QueryResponse::NO;
}

QueryResponse CTFBotMvMEngineerIdle::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	return QueryResponse::NO;
}


bool CTFBotMvMEngineerIdle::ShouldAdvanceNestSpot(CTFBot *actor)
{
	// TODO
}

void CTFBotMvMEngineerIdle::TakeOverStaleNest(CBaseTFBotHintEntity *hint, CTFBot *actor)
{
	if (hint == nullptr || hint->OwnerObjectHasNoOwner()) {
		return;
	}
	
	CBaseObject *obj = static_cast<CBaseObject *>(hint->GetOwnerEntity());
	obj->SetOwnerEntity(actor);
	obj->SetBuilder(actor);
	actor->AddObject(obj);
}

void CTFBotMvMEngineerIdle::TryToDetonateStaleNest()
{
	// TODO
}


bool CTFBotMvMEngineerHintFinder::FindHint(bool box_check, bool out_of_range_ok, CHandle<CTFBotHintEngineerNest> *the_hint)
{
	CUtlVector<CTFBotHintEngineerNest *> hints;
	
	for (int i = 0; i < ITFBotHintEntityAutoList::AutoList().Count(); ++i) {
		CBaseTFBotHintEntity *hint = static_cast<CBaseTFBotHintEntity *>(
			ITFBotHintEntityAutoList::AutoList()[i]);
		
		if (hint->GetHintType() == CBaseTFBotHintEntity::HintType::SENTRY_GUN &&
			!hint->m_bDisabled && hint->GetOwnerEntity() == nullptr) {
			hints.AddToTail(static_cast<CTFBotHintEngineerNest *>(hint));
		}
	}
	
	BombInfo_t bomb_info;
	GetBombInfo(&bomb_info);
	
	CUtlVector<CTFBotHintEngineerNest *> hints1; // in fwd~back, stale
	CUtlVector<CTFBotHintEngineerNest *> hints2; // in fwd~back, within min bomb distance
	CUtlVector<CTFBotHintEngineerNest *> hints3; // in fwd~infinity
	CUtlVector<CTFBotHintEngineerNest *> hints4; // others
	
	FOR_EACH_VEC(hints, i) {
		CTFBotHintEngineerNest *hint = hints[i];
		
		CTFNavArea *area = TheNavMesh->GetNearestNavArea(hint->GetAbsOrigin());
		if (area == nullptr) {
			Warning("Sentry hint has NULL nav area!\n");
			continue;
		}
		
		float dist = area->m_flBombTargetDistance;
		if (dist > bomb_info.hatch_dist_back && dist < bomb_info.hatch_dist_fwd) {
			CBaseEntity *pList[256];
			if (box_check && UTIL_EntitiesInBox(pList, 256,
				hint->GetAbsOrigin() + VEC_HULL_MIN,
				hint->GetAbsOrigin() + VEC_HULL_MAX,
				FL_OBJECT | FL_FAKECLIENT) > 0) {
				continue;
			}
			
			if (hint->IsStaleNest) {
				hints1.AddToTail(hint);
			} else {
				if (hint->GetAbsOrigin()->DistTo(bomb_info.closest_pos) >=
					tf_bot_engineer_mvm_hint_min_distance_from_bomb.GetFloat()) {
					hints2.AddToTail(hint);
				}
			}
		} else if (dist > bomb_info.hatch_dist_fwd) {
			hints3.AddToTail(hint);
		} else {
			hints4.AddToTail(hint);
		}
	}
	
	CTFBotHintEngineerNest *hint;
	if (!hints1.IsEmpty()) {
		hint = hints1.Random();
	} else if (!hints2.IsEmpty()) {
		hint = hints2.Random();
	} else if (out_of_range_ok) {
		hint = SelectOutOfRangeNest(hints3);
		if (hint == nullptr) {
			hint = SelectOutOfRangeNest(hints4);
		}
	}
	
	if (the_hint != nullptr) {
		*the_hint = hint;
	}
	
	return (hint != nullptr);
}


CTFBotHintEngineerNest *SelectOutOfRangeNest(const CUtlVector<CTFBotHintEngineerNest *>& nests)
{
	if (nests.IsEmpty()) {
		return nullptr;
	}
	
	FOR_EACH_VEC(nests, i) {
		CTFBotHintEngineerNest *nest = nests[i];
		
		if (nest->IsStaleNest()) {
			return nest;
		}
	}
	
	return nests.Random();
}

bool GetBombInfo(BombInfo_t *info)
{
	float max_hatch_dist = 0.0f;
	
	FOR_EACH_VEC(TheNavAreas, i) {
		CTFNavArea *area = static_cast<CTFNavArea *>(TheNavAreas[i]);
		
		if ((area->m_nAttributes & (BLUE_SPAWN_ROOM | RED_SPAWN_ROOM)) != 0) {
			continue;
		}
		
		max_hatch_dist = Max(Max(area->m_flBombTargetDistance, max_hatch_dist), 0.0f);
	}
	
	CCaptureFlag *closest_flag = nullptr;
	float closest_flag_x;
	float closest_flag_y;
	float closest_flag_z;
	
	for (int i = 0; i < ICaptureFlagAutoList::AutoList().Count(); ++i) {
		CCaptureFlag *flag = static_cast<CCaptureFlag *>(ICaptureFlagAutoList::AutoList()[i]);
		
		Vector flag_pos;
		
		CTFPlayer *owner = ToTFPlayer(flag->GetOwnerEntity());
		if (owner != nullptr) {
			flag_pos = owner->GetAbsOrigin();
		} else {
			flag_pos = flag->WorldSpaceCenter();
		}
		
		CTFNavArea *area = TheNavMesh->GetNearestNavArea(flag_pos);
		if (area != nullptr && area->m_flBombTargetDistance < max_hatch_dist) {
			closest_flag = flag;
			max_hatch_dist = area->m_flBombTargetDistance;
			closest_flag_pos = flag_pos;
		}
	}
	
	bool success = (closest_flag != nullptr);
	
	float range_back = tf_bot_engineer_mvm_sentry_hint_bomb_backward_range.GetFloat();
	float range_fwd  = tf_bot_engineer_mvm_sentry_hint_bomb_forward_range.GetFloat();
	
	if (info != nullptr) {
		info->closest_pos = {
			.x = closest_flag_x,
			.y = closest_flag_y,
			.z = closest_flag_z,
		};
		info->hatch_dist_back = max_hatch_dist - range_back;
		info->hatch_dist_fwd  = max_hatch_dist + range_fwd;
	}
	
	return success;
}
