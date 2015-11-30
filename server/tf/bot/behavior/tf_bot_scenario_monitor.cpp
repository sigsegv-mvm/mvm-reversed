/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_scenario_monitor.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_fetch_lost_flag_time("tf_bot_fetch_lost_flag_time", "10", FCVAR_CHEAT,
	"How long busy TFBots will ignore the dropped flag before they give up what they are doing and go after it");
ConVar tf_bot_flag_kill_on_touch("tf_bot_flag_kill_on_touch", "0", FCVAR_CHEAT,
	"If nonzero, any bot that picks up the flag dies. For testing.");



