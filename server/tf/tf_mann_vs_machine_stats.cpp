/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/tf_mann_vs_machine_stats.cpp
 */


// g_pMVMStats


void CMannVsMachineStats::PlayerEvent_BoughtInstantRespawn(CTFPlayer *player, int i1)
{
	// TODO
}

void CMannVsMachineStats::PlayerEvent_DealtDamageToBots(CTFPlayer *player, int damage)
{
	if (!player->IsBot() && TFGameRules() != nullptr && TFGameRules()->IsPVEModeActive()) {
		// idx 00 => 0x364
		// idx 01 => 0x374
		// idx 30 => 0x544
		// idx 31 => 0x554
		// idx 32 => 0x564
		
		*(this + 0x360 + (0x10*idx) + 0x4) += damage;
		
		// TODO
	}
}

void CMannVsMachineStats::PlayerEvent_DealtDamageToGiants(CTFPlayer *player, int damage)
{
	if (!player->IsBot() && TFGameRules() != nullptr && TFGameRules()->IsPVEModeActive()) {
		// TODO
	}
}

void CMannVsMachineStats::PlayerEvent_DealtDamageToTanks(CTFPlayer *player, int damage)
{
	if (!player->IsBot() && TFGameRules() != nullptr && TFGameRules()->IsPVEModeActive()) {
		// TODO
	}
}

void CMannVsMachineStats::PlayerEvent_Died(CTFPlayer *player)
{
	if (!player->IsBot() && TFGameRules() != nullptr && TFGameRules()->IsPVEModeActive()) {
		// TODO
	}
}

void CMannVsMachineStats::PlayerEvent_PickedUpCredits(CTFPlayer *player, unsigned int i1, int i2)
{
	// TODO
}

void CMannVsMachineStats::PlayerEvent_PointsChanged(CTFPlayer *player, int i1)
{
}

void CMannVsMachineStats::PlayerEvent_Upgraded(CTFPlayer *player, unsigned short i1, unsigned short i2, unsigned char i3, short i4, bool is_canteen)
{
	// TODO
}


