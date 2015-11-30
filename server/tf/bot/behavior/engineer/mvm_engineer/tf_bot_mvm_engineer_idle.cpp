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





bool CTFBotMvMEngineerHintFinder::FindHint(bool b1, bool b2, CHandle<CTFBotHintEngineerNest> *hint)
{
	// TODO
}
