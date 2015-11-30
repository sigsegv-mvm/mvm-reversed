/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/tf_bot_vision.cpp
 */


ConVar tf_bot_choose_target_interval("tf_bot_choose_target_interval", "0.3f", FCVAR_CHEAT,
	"How often, in seconds, a TFBot can reselect his target");
ConVar tf_bot_sniper_choose_target_interval("tf_bot_sniper_choose_target_interval", "3.0f", FCVAR_CHEAT,
	"How often, in seconds, a zoomed-in Sniper can reselect his target");



