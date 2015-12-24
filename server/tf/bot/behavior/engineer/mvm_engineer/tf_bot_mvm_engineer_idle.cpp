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


CTFBotMvMEngineerIdle::CTFBotMvMEngineerIdle(/* TODO */)
{
	// TODO
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
	// TODO
}

ActionResult<CTFBot> CTFBotMvMEngineerIdle::Update(CTFBot *actor, float dt)
{
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
	// TODO
}

void CTFBotMvMEngineerIdle::TryToDetonateStaleNest()
{
	// TODO
}


bool CTFBotMvMEngineerHintFinder::FindHint(bool b1, bool b2, CHandle<CTFBotHintEngineerNest> *hint)
{
	CUtlVector<CTFBotHintEngineerNest *> hints;
	
	// TODO
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
