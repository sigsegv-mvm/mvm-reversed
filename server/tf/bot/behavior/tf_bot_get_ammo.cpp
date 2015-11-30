/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_get_ammo.cpp
 * used in MvM: TODO
 */


// TODO: static s_possibleAmmo = -1


ConVar tf_bot_ammo_search_range("tf_bot_ammo_search_range", "5000", FCVAR_CHEAT,
	"How far bots will search to find ammo around them");
ConVar tf_bot_debug_ammo_scavanging("tf_bot_debug_ammo_scavanging", "0", FCVAR_CHEAT);





CAmmoFilter::CAmmoFilter(CBaseEntity *actor)
	: m_Actor(actor)
{
}


bool CAmmoFilter::IsSelected(const CBaseEntity *ent) const
{
	// TODO
}
