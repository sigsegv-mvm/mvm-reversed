/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/tf_bot_manager.cpp
 */


ConVar tf_bot_difficulty("tf_bot_difficulty", "1", FCVAR_NONE,
	"Defines the skill of bots joining the game.  Values are: 0=easy, 1=normal, 2=hard, 3=expert.");
ConVar tf_bot_quota("tf_bot_quota", "0", FCVAR_NONE,
	"Determines the total number of tf bots in the game.");
ConVar tf_bot_quota_mode("tf_bot_quota_mode", "normal", FCVAR_NONE,
	"Determines the type of quota. Allowed values: 'normal', 'fill', and 'match'. If 'fill', the server will adjust bots to keep N players in the game, where N is bot_quota. If 'match', the server will maintain a 1:N ratio of humans to bots, where N is bot_quota.");
ConVar tf_bot_join_after_player("tf_bot_join_after_player", "1", FCVAR_NONE,
	"If nonzero, bots wait until a player joins before entering the game.");
ConVar tf_bot_auto_vacate("tf_bot_auto_vacate", "1", FCVAR_NONE,
	"If nonzero, bots will automatically leave to make room for human players.");
ConVar tf_bot_offline_practice("tf_bot_offline_practice", "0", FCVAR_NONE,
	"Tells the server that it is in offline practice mode.");
ConVar tf_bot_melee_only("tf_bot_melee_only", "0", FCVAR_GAMEDLL,
	"If nonzero, TFBots will only use melee weapons");

ConCommand tf_bot_debug_log_command("tf_bot_debug_stuck_log", &tf_bot_debug_stuck_log,
	"Given a server logfile, visually display bot stuck locations.", FCVAR_CHEAT | FCVAR_GAMEDLL);
ConCommand tf_bot_debug_log_clear_command("tf_bot_debug_stuck_log_clear", &tf_bot_stuck_log_clear,
	"Clear currently loaded bot stuck data", FCVAR_CHEAT | FCVAR_GAMEDLL);


CTFBotManager sTFBotManager;


CTFBotManager *TheTFBots()
{
	/* uh... yeah... this isn't valid at all, since the pointer returned by
	 * TheNextBots() is not actually a CTFBotManager!
	 * (why the hell doesn't this return sTFBotManager, which is a valid
	 * CTFBotManager that is completely unused?) */
	return static_cast<CTFBotManager *>(TheNextBots());
}
