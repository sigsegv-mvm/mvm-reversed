/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_building.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_engineer_retaliate_range("tf_bot_engineer_retaliate_range", "750", FCVAR_CHEAT,
	"If attacker who destroyed sentry is closer than this, attack. Otherwise, retreat");
ConVar tf_bot_engineer_exit_near_sentry_range("tf_bot_engineer_exit_near_sentry_range", "2500", FCVAR_CHEAT,
	"Maximum travel distance between a bot's Sentry gun and its Teleporter Exit");
ConVar tf_bot_engineer_max_sentry_travel_distance_to_point("tf_bot_engineer_max_sentry_travel_distance_to_point", "2500", FCVAR_CHEAT,
	"Maximum travel distance between a bot's Sentry gun and the currently contested point");



