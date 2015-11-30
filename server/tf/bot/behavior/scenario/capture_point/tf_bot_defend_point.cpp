/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/scenario/capture_point/tf_bot_defend_point.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_defense_must_defend_time("tf_bot_defense_must_defend_time", "300", FCVAR_CHEAT,
	"If timer is less than this, bots will stay near point and guard");
ConVar tf_bot_max_point_defend_range("tf_bot_max_point_defend_range", "1250", FCVAR_CHEAT,
	"How far (in travel distance) from the point defending bots will take up positions");
ConVar tf_bot_defense_debug("tf_bot_defense_debug", "0", FCVAR_CHEAT);



