/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/NextBot/Player/NextBotPlayerBody.cpp
 */


ConVar nb_saccade_time("nb_saccade_time", "0.1", FCVAR_CHEAT);
ConVar nb_saccade_speed("nb_saccade_speed", "1000", FCVAR_CHEAT);
ConVar nb_head_aim_steady_max_rate("nb_head_aim_steady_max_rate", "100", FCVAR_CHEAT);
ConVar nb_head_aim_settle_duration("nb_head_aim_settle_duration", "0.3", FCVAR_CHEAT);
ConVar nb_head_aim_resettle_angle("nb_head_aim_resettle_angle", "100", FCVAR_CHEAT,
	"After rotating through this angle, the bot pauses to 'recenter' its virtual mouse on its virtual mousepad");
ConVar nb_head_aim_resettle_time("nb_head_aim_resettle_time", "0.3", FCVAR_CHEAT,
	"How long the bot pauses to 'recenter' its virtual mouse on its virtual mousepad");
ConVar bot_mimic("bot_mimic", "0", FCVAR_NONE,
	"Bot uses usercmd of player by index.");



