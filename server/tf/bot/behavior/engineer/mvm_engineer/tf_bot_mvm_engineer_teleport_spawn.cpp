/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_teleport_spawn.cpp
 * used in MvM: TODO
 */


CTFBotMvMEngineerTeleportSpawn::CTFBotMvMEngineerTeleportSpawn(CBaseTFBotHintEntity *hint, bool non_silent)
{
	this->m_hintEntity = hint;
	this->m_bNonSilent = non_silent;
}

CTFBotMvMEngineerTeleportSpawn::~CTFBotMvMEngineerTeleportSpawn()
{
}


const char *CTFBotMvMEngineerTeleportSpawn::GetName() const
{
	return "MvMEngineerTeleportSpawn";
}


ActionResult<CTFBot> CTFBotMvMEngineerTeleportSpawn::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	if ((actor->m_nBotAttrs & CTFBot::AttributeType::TELEPORTTOHINT) == 0) {
		return Done("Cannot teleport to hint with out Attributes TeleportToHint");
	}
	
	return Continue();
}

ActionResult<CTFBot> CTFBotMvMEngineerTeleportSpawn::Update(CTFBot *actor, float dt)
{
	if (!this->m_ctPushAway.HasStarted()) {
		this->m_ctPushAway.Start(0.1f);
		
		CBaseEntity *hint = this->m_hintEntity();
		if (hint != nullptr) {
			TFGameRules()->PushAllPlayersAway(hint->GetAbsOrigin(),
				400.0f, 500.0f, TF_TEAM_RED, nullptr);
		}
		
		return Continue();
	}
	
	if (!this->m_ctPushAway.IsElapsed()) {
		return Continue();
	}
	
	CBaseEntity *hint = this->m_hintEntity();
	if (hint == nullptr) {
		return Done("Cannot teleport to hint as m_hintEntity is NULL");
	}
	
	Vector tele_pos = hint->GetAbsOrigin();
	QAngle tele_ang = hint->GetAbsAngles();
	
	actor->Teleport(tele_pos, tele_ang, nullptr);
	
	CPVSFilter filter(tele_pos);
	
	TE_TFParticleEffect(filter, 0.0f, "teleported_blue", tele_pos, vec3_angle);
	TE_TFParticleEffect(filter, 0.0f, "player_sparkles_blue", tele_pos, vec3_angle);
	
	if (this->m_bNonSilent) {
		TE_TFParticleEffect(filter, 0.0f, "teleported_mvm_bot", tele_pos, vec3_angle);
		actor->EmitSound("Engineer.MvM_BattleCry07");
		this->m_hintEntity()->EmitSound("MvM.Robot_Engineer_Spawn");
		
		if (g_pPopulationManager != nullptr) {
			CWave *wave = g_pPopulationManager->GetCurrentWave();
			if (wave != nullptr) {
				if (wave->m_iEngiesTeleportedIn == 0) {
					g_pGameRules->BroadcastSound(255,
						"Announcer.MvM_First_Engineer_Teleport_Spawned");
				} else {
					g_pGameRules->BroadcastSound(255,
						"Announcer.MvM_Another_Engineer_Teleport_Spawned");
				}
				++wave->m_iEngiesTeleportedIn;
			}
		}
	}
	
	return Done("Teleported");
}
