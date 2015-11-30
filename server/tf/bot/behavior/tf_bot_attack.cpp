/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_attack.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_path_lookahead_range("tf_bot_path_lookahead_range", "300", FCVAR_NONE);
ConVar tf_bot_sniper_aim_error("tf_bot_sniper_aim_error", "0.01", FCVAR_CHEAT);
ConVar tf_bot_sniper_aim_steady_rate("tf_bot_sniper_aim_steady_rate", "10", FCVAR_CHEAT);
ConVar tf_bot_debug_sniper("tf_bot_debug_sniper", "0", FCVAR_CHEAT);
ConVar tf_bot_fire_weapon_min_time("tf_bot_fire_weapon_min_time", "1", FCVAR_CHEAT);
ConVar tf_bot_taunt_victim_chance("tf_bot_taunt_victim_chance", "20", FCVAR_NONE);
ConVar tf_bot_notice_backstab_chance("tf_bot_notice_backstab_chance", "25", FCVAR_CHEAT);
ConVar tf_bot_notice_backstab_min_chance("tf_bot_notice_backstab_min_chance", "100", FCVAR_CHEAT);
ConVar tf_bot_notice_backstab_max_chance("tf_bot_notice_backstab_max_chance", "750", FCVAR_CHEAT);
ConVar tf_bot_arrow_elevation_rate("tf_bot_arrow_elevation_rate", "0.0001", FCVAR_CHEAT,
	"When firing arrows at far away targets, this is the degree/range slope to raise our aim");
ConVar tf_bot_ballistic_elevation_rate("tf_bot_ballistic_elevation_rate", "0.01", FCVAR_CHEAT,
	"When lobbing grenades at far away targets, this is the degree/range slope to raise our aim");
ConVar tf_bot_hitscan_range_limit("tf_bot_hitscan_range_limit", "1800", FCVAR_CHEAT);
ConVar tf_bot_always_full_reload("tf_bot_always_full_reload", "0", FCVAR_CHEAT);
ConVar tf_bot_fire_weapon_allowed("tf_bot_fire_weapon_allowed", "1", FCVAR_CHEAT,
	"If zero, TFBots will not pull the trigger of their weapons (but will act like they did)");



