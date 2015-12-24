/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_build_teleporter.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_engineer_building_health_multiplier("tf_bot_engineer_building_health_multiplier", "2", FCVAR_CHEAT);


CTFBotMvMEngineerBuildTeleportExit::CTFBotMvMEngineerBuildTeleportExit(CTFBotHintTeleportExit *hint)
{
	this->m_hintEntity = hint;
}

CTFBotMvMEngineerBuildTeleportExit::~CTFBotMvMEngineerBuildTeleportExit()
{
}


const char *CTFBotMvMEngineerBuildTeleportExit::GetName() const
{
	return "MvMEngineerBuildTeleportExit";
}


ActionResult<CTFBot> CTFBotMvMEngineerBuildTeleportExit::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	CONTINUE();
}

ActionResult<CTFBot> CTFBotMvMEngineerBuildTeleportExit::Update(CTFBot *actor, float dt)
{
	CBaseEntity *hint = this->m_hintEntity();
	if (hint == nullptr) {
		DONE("No hint entity");
	}
	
	if (actor->IsRangeGreaterThan(hint->GetAbsOrigin(), 25.0f)) {
		if (this->m_ctRecomputePath.IsElapsed()) {
			this->m_ctRecomputePath.Start(RandomFloat(1.0f, 2.0f));
			
			CTFBotPathCost cost_func(actor, FASTEST_ROUTE);
			this->m_PathFollower.Compute<CTFBotPathCost>(actor,
				this->m_hintEntity()->GetAbsOrigin(), cost_func, 0.0f, true);
		}
		
		this->m_PathFollower.Update(actor);
		if (!this->m_PathFollower.IsValid()) {
			/* BUG: one path failure ends the entire behavior...
			 * could this be why engiebots sometimes zone out? */
			DONE("Path failed");
		}
		
		CONTINUE();
	}
	
	if (!this->m_ctPushAway.HasStarted()) {
		this->m_ctPushAway.Start(0.1f);
		
		hint = this->m_hintEntity();
		if (hint != nullptr) {
			TFGameRules()->PushAllPlayersAway(hint->GetAbsOrigin(),
				400.0f, 500.0f, TF_TEAM_RED, nullptr);
		}
		
		CONTINUE();
	}
	
	if (!this->m_ctPushAway.IsElapsed()) {
		CONTINUE();
	}
	
	actor->DetonateObjectOfType(OBJ_TELEPORTER, 1, true);
	
	CBaseEntity *ent = CreateEntityByName("obj_teleporter");
	if (tele == nullptr) {
		CONTINUE();
	}
	
	CObjectTeleporter *tele = static_cast<CObjectTeleporter *>(ent);
	
	tele->SetAbsOrigin(this->m_hintEntity()->GetAbsOrigin());
	tele->SetAbsAngles(this->m_hintEntity()->GetAbsAngles());
	tele->SetObjectMode(1);
	tele->Spawn();
	
	/* CObjectTeleporter+0xaec: CUtlStringList m_TeleportWhere */
	FOR_EACH_VEC(actor->m_TeleportWhere, i) {
		tele->m_TeleportWhere.CopyAndAddToTail(actor->m_TeleportWhere[i]);
	}
	
	/* CTFBot::m_bTeleQuickBuild is a relic from the past, nothing in the game
	 * is currently capable of turning it on */
	if (actor->m_bTeleQuickBuild) {
		// TODO: set byte @ tele+0xaa0 to true
		// (causes CBaseObject::ShouldQuickBuild to return true)
	}
	
	tele->StartPlacement(actor);
	tele->StartBuilding(actor);
	
	int max_health = (int)((float)tele->GetMaxHealthForCurrentLevel() *
		tf_bot_engineer_building_health_multiplier.GetFloat());
	
	tele->SetMaxHealth(max_health);
	tele->SetHealth(max_health);
	
	this->m_hintEntity()->SetOwnerEntity(tele);
	
	DONE("Teleport exit built");
}
