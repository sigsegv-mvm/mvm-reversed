// convars (and other static/global variables and file-level stuff)
// TODO: determine which convars are accessed and which are dormant/unused


// shared/econ/attribute_manager.cpp


// shared/tf/tf_condition.cpp

// shared/tf/tf_gamerules.cpp
// NOTE: skipped many unrelated convars here
ConVar tf_halloween_boss_spawn_interval("tf_halloween_boss_spawn_interval", "480", FCVAR_CHEAT, "Average interval between boss spawns, in seconds");
ConVar tf_halloween_boss_spawn_interval_variation("tf_halloween_boss_spawn_interval_variation", "60", FCVAR_CHEAT, "Variation of spawn interval +/-");
ConVar tf_halloween_eyeball_boss_spawn_interval("tf_halloween_eyeball_boss_spawn_interval", "180", FCVAR_CHEAT, "Average interval between boss spawns, in seconds");
ConVar tf_halloween_eyeball_boss_spawn_interval_variation("tf_halloween_eyeball_boss_spawn_interval_variation", "30", FCVAR_CHEAT, "Variation of spawn interval +/-");
ConVar tf_merasmus_spawn_interval("tf_merasmus_spawn_interval", "180", FCVAR_CHEAT, "Average interval between boss spawns, in seconds");
ConVar tf_merasmus_spawn_interval_variation("tf_merasmus_spawn_interval_variation", "30", FCVAR_CHEAT, "Variation of spawn interval +/-");
ConVar tf_halloween_zombie_mob_enabled("tf_halloween_zombie_mob_enabled", "0", FCVAR_CHEAT, "If set to 1, spawn zombie mobs on non-Halloween Valve maps");
ConVar tf_halloween_zombie_mob_spawn_interval("tf_halloween_zombie_mob_spawn_interval", "180", FCVAR_CHEAT, "Average interval between zombie mob spawns, in seconds");
ConVar tf_halloween_zombie_mob_spawn_count("tf_halloween_zombie_mob_spawn_count", "20", FCVAR_CHEAT, "How many zombies to spaw");
ConVar tf_forced_holiday("tf_forced_holiday", "0", FCVAR_REPLICATED, "Forced holiday, \n   Birthday = 1\n   Halloween = 2\n");
ConVar tf_item_based_forced_holiday("tf_item_based_forced_holiday", "0", FCVAR_REPLICATED);
ConVar tf_force_holidays_off("tf_force_holidays_off", "0", FCVAR_REPLICATED | FCVAR_NOTIFY | FCVAR_DEVELOPMENTONLY);
ConVar tf_birthday("tf_birthday", "0", FCVAR_REPLICATED | FCVAR_NOTIFY);
ConVar mp_tournament_redteamname("mp_tournament_redteamname", "RED", FCVAR_REPLICATED | FCVAR_HIDDEN);
ConVar mp_tournament_blueteamname("mp_tournament_blueteamname", "BLU", FCVAR_REPLICATED | FCVAR_HIDDEN);
ConVar mp_tournament_stopwatch("mp_tournament_stopwatch", "1", FCVAR_REPLICATED | FCVAR_NOTIFY);
ConVar mp_tournament_readymode("mp_tournament_readymode", "0", FCVAR_REPLICATED | FCVAR_NOTIFY, "Enable per-player ready status for tournament mode.");
ConVar mp_tournament_readymode_min("mp_tournament_readymode_min", "2", FCVAR_REPLICATED | FCVAR_NOTIFY, "Minimum number of players required on the server before players can toggle ready status.");
ConVar mp_tournament_readymode_team_size("mp_tournament_readymode_team_size", "0", FCVAR_REPLICATED | FCVAR_NOTIFY, "Minimum number of players required to be ready per-team before the game can begin.");
ConVar mp_tournament_readymode_countdown("mp_tournament_readymode_countdown", "10", FCVAR_REPLICATED | FCVAR_NOTIFY, "The number of seconds before a match begins when both teams are ready.");
ConVar tf_tournament_classlimit_scout("tf_tournament_classlimit_scout", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Scouts.\n");
ConVar tf_tournament_classlimit_sniper("tf_tournament_classlimit_sniper", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Snipers.\n");
ConVar tf_tournament_classlimit_soldier("tf_tournament_classlimit_soldier", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Soldiers.\n");
ConVar tf_tournament_classlimit_demoman("tf_tournament_classlimit_demoman", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Demomenz.\n");
ConVar tf_tournament_classlimit_medic("tf_tournament_classlimit_medic", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Medics.\n");
ConVar tf_tournament_classlimit_heavy("tf_tournament_classlimit_heavy", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Heavies.\n");
ConVar tf_tournament_classlimit_pyro("tf_tournament_classlimit_pyro", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Pyros.\n");
ConVar tf_tournament_classlimit_spy("tf_tournament_classlimit_spy", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Spies.\n");
ConVar tf_tournament_classlimit_engineer("tf_tournament_classlimit_engineer", "-1", FCVAR_REPLICATED, "Tournament mode per-team class limit for Engineers.\n");
ConVar tf_tournament_classchange_allowed("tf_tournament_classchange_allowed", "1", FCVAR_REPLICATED, "Allow players to change class while the game is active?.");
ConVar tf_tournament_classchange_ready_allowed("tf_tournament_classchange_ready_allowed", "1", FCVAR_REPLICATED, "Allow players to change class after they are READY?.");
ConVar mp_humans_must_join_team("mp_humans_must_join_team", "any", FCVAR_REPLICATED, "Restricts human players to a single team {any, blue, red, spectator}");
ConVar tf_medieval("tf_medieval", "0", FCVAR_REPLICATED | FCVAR_NOTIFY, "Enable Medieval Mode.\n", true, 0.0f, true, 1.0f, &cc_tf_medieval_changed);
ConVar tf_mvm_min_players_to_start("tf_mvm_min_players_to_start", "3", FCVAR_REPLICATED | FCVAR_NOTIFY, "Minimum number of players connected to start a countdown timer");
ConVar tf_mvm_respec_enabled("tf_mvm_respec_enabled", "1", FCVAR_CHEAT | FCVAR_REPLICATED, "Allow players to refund credits spent on player and item upgrades.");
ConVar tf_mvm_respec_limit("tf_mvm_respec_limit", "0", FCVAR_CHEAT | FCVAR_REPLICATED, "The total number of respecs a player can earn.  Default: 0 (no limit).");
ConVar tf_mvm_respec_credit_goal("tf_mvm_respec_credit_goal", "2000", FCVAR_CHEAT | FCVAR_REPLICATED, "When tf_mvm_respec_limit is non-zero, the total amount of money the team must collect to earn a respec credit.");
ConVar tf_grapplinghook_enable("tf_grapplinghook_enable", "0", FCVAR_REPLICATED);
ConCommand tf_mvm_popfile_command("tf_mvm_popfile", &tf_mvm_popfile, "Change to a target popfile for MvM", FCVAR_GAMEDLL, nullptr);
ConVar tf_gamemode_mvm("tf_gamemode_mvm", "0", FCVAR_REPLICATED | FCVAR_NOTIFY | FCVAR_DEVELOPMENTONLY);
ConVar tf_bot_count("tf_bot_count", "0", FCVAR_NOTIFY | FCVAR_DEVELOPMENTONLY);
ConVar tf_powerup_mode("tf_powerup_mode", "0", FCVAR_NOTIFY, "Enable/disable powerup mode. Not compatible with Mann Vs Machine mode", true, 0.0f, true, 1.0f, &cc_powerup_mode);
CAutoGameSystem g_TFGameModeHistory(nullptr);
// TODO: server class init for CTFGameRules
// TODO: server class init for CTFGameRulesProxy ("tf_gamerules")
ConCommand tf_halloween_force_boss_spawn_command
ConCommand tcc_spawn_merasmus_at_level_command

// shared/tf/tf_gamestats_shared.cpp
// shared/tf/tf_item_powerup_bottle.cpp

// shared/tf/tf_playerclass_shared.cpp
ConVar tf_mvm_bot_flag_carrier_movement_penalty("tf_mvm_bot_flag_carrier_movement_penalty", "0.5", FCVAR_CHEAT | FCVAR_REPLICATED);

// shared/tf/tf_mann_vs_machine_stats.cpp
// shared/tf/tf_revive.cpp
// shared/tf/tf_upgrades_shared.cpp


// server/basecombatcharacter.cpp
ConVar nb_last_area_update_tolerance("nb_last_area_update_tolerance", "4.0", FCVAR_CHEAT, "Distance a character needs to travel in order to invalidate cached area");


// server/NextBot/NavMeshEntities/func_nav_prerequisive.cpp

// server/NextBot/NextBot.cpp
ConVar NextBotStop("nb_stop", "0", FCVAR_CHEAT | FCVAR_REPLICATED, "Stop all NextBots");
ConCommand nb_command_command("nb_command", &nb_command, "Sends a command string to all bots", FCVAR_CHEAT, nullptr);
// TODO: server class init for NextBotCombatCharacter
ConCommand nb_delete_all_command("nb_delete_all", &nb_delete_all, "Delete all non-player NextBot entities.", FCVAR_CHEAT, nullptr);
ConCommand nb_move_to_cursor_command("nb_move_to_cursor", &nb_move_to_cursor, "Tell all NextBots to move to the cursor position", FCVAR_CHEAT, nullptr);

// server/NextBot/NextBotBodyInterface.cpp
// server/NextBot/NextBotComponentInterface.cpp
// server/NextBot/NextBotGroundLocomotion.cpp
// server/NextBot/NextBotIntentionInterface.cpp

// server/NextBot/NextBotInterface.cpp
ConVar NextBotDebugHistory("nb_debug_history", "1", FCVAR_CHEAT, "If true, each bot keeps a history of debug output in memory");

// server/NextBot/NextBotLocomotionInterface.cpp

// server/NextBot/NextBotManager.cpp
// TODO: static var init for a bunch of unnamed vars (12 x dword @ 1630d14)
ConVar nb_update_frequency("nb_update_frequency", ".1", FCVAR_CHEAT);
ConVar nb_update_framelimit("nb_update_framelimit", "15", FCVAR_CHEAT);
ConVar nb_update_maxslide("nb_update_maxslide", "2", FCVAR_CHEAT);
ConVar nb_update_debug("nb_update_debug", "0", FCVAR_CHEAT);
ConCommand SetDebug("nb_debug", &CC_SetDebug, "Debug NextBots.  Categories are: BEHAVIOR, LOOK_AT, PATH, ANIMATION, LOCOMOTION, VISION, HEARING, EVENTS, ERRORS.", FCVAR_CHEAT, nullptr);
ConCommand SetDebugFilter("nb_debug_filter", &CC_SetDebugFilter, "Add items to the NextBot debug filter. Items can be entindexes or part of the indentifier of one or more bots.", FCVAR_CHEAT, nullptr);
ConCommand SelectBot("nb_select", &CC_SelectBot, "Select the bot you are aiming at for further debug operations.", FCVAR_CHEAT, nullptr);
ComCommand ForceLookAt("nb_force_look_at", &CC_ForceLookAt, "Force selected bot to look at the local player's position", FCVAR_CHEAT, nullptr);
ConCommand WarpSelectedHere("nb_warp_selected_here", &CC_WarpSelectedHere, "Teleport the selected bot to your cursor position", FCVAR_CHEAT, nullptr);

// server/NextBot/NextBotVisionInterface.cpp
ConVar nb_blind("nb_blind", "0", FCVAR_CHEAT, "Disable vision");
ConVar nb_debug_known_entities("nb_debug_known_entities", "0", FCVAR_CHEAT, "Show the 'known entities' for the bot that is the current spectator target");

// server/NextBot/Path/NextBotChasePath.cpp

// server/NextBot/Path/NextBotPath.cpp
ConVar NextBotPathDrawIncrement("nb_path_draw_inc", "100", FCVAR_CHEAT);
ConVar NextBotPathDrawSegmentCount("nb_path_draw_segment_count", "100", FCVAR_CHEAT);
ConVar NextBotPathSegmentInfluenceRadius("nb_path_segment_influence_radius", "100", FCVAR_CHEAT);

// server/NextBot/Path/NextBotPathFollow.cpp
ConVar NextBotSpeedLookAheadRange("nb_speed_look_ahead_range", "150", FCVAR_CHEAT);
ConVar NextBotGoalLookAheadRange("nb_goal_look_ahead_range", "50", FCVAR_CHEAT);
ConVar NextBotLadderAlignRange("nb_ladder_align_range", "50", FCVAR_CHEAT);
ConVar NextBotAllowAvoiding("nb_allow_avoiding", "1", FCVAR_CHEAT);
ConVar NextBotAllowClimbing("nb_allow_climbing", "1", FCVAR_CHEAT);
ConVar NextBotAllowGapJumping("nb_allow_gap_jumping", "1", FCVAR_CHEAT);
ConVar NextBotDebugClimbing("nb_debug_climbing", "0", FCVAR_CHEAT);

// server/NextBot/Player/NextBotPlayer.cpp
ConVar NextBotPlayerStop("nb_player_stop", "0", FCVAR_CHEAT, "Stop all NextBotPlayers from updating");
ConVar NextBotPlayerWalk("nb_player_walk", "0", FCVAR_CHEAT, "Force bots to walk");
ConVar NextBotPlayerCrouch("nb_player_crouch", "0", FCVAR_CHEAT, "Force bots to crouch");
ConVar NextBotPlayerMove("nb_player_move", "0", FCVAR_CHEAT, "Prevents bots from moving");

// server/NextBot/Player/NextBotPlayerBody.cpp
ConVar nb_saccade_time("nb_saccade_time", "0.1", FCVAR_CHEAT);
ConVar nb_saccade_speed("nb_saccade_speed", "1000", FCVAR_CHEAT);
ConVar nb_head_aim_steady_max_rate("nb_head_aim_steady_max_rate", "100", FCVAR_CHEAT);
ConVar nb_head_aim_settle_duration("nb_head_aim_settle_duration", "0.3", FCVAR_CHEAT);
ConVar nb_head_aim_resettle_angle("nb_head_aim_resettle_angle", "100", FCVAR_CHEAT, "After rotating through this angle, the bot pauses to 'recenter' its virtual mouse on its virtual mousepad");
ConVar nb_head_aim_resettle_time("nb_head_aim_resettle_time", "0.3", FCVAR_CHEAT, "How long the bot pauses to 'recenter' its virtual mouse on its virtual mousepad");
ConVar bot_mimic("bot_mimic", "0", FCVAR_NONE, "Bot uses usercmd of player by index.");

// server/NextBot/Player/NextBotPlayerLocomotion.cpp
ConVar NextBotPlayerMoveDirect("nb_player_move_direct", "0", FCVAR_NONE);

// server/NextBot/simple_bot.cpp


// server/tf/bot/behavior/demoman/tf_bot_prepare_stickybomb_trap.cpp
ConVar tf_bot_stickybomb_density("tf_bot_stickybomb_density", 0.0001, FCVAR_CHEAT, "Number of stickies to place per square inch");

// server/tf/bot/behavior/demoman/tf_bot_stickybomb_sentrygun.cpp
ConVar tf_bot_sticky_base_range("tf_bot_sticky_base_range", "800", FCVAR_CHEAT);
ConVar tf_bot_sticky_charge_rate("tf_bot_sticky_charge_rate", "0.01", FCVAR_CHEAT, "Seconds of charge per unit range beyond base");

// server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_build_sentry.cpp

// server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_build_teleporter.cpp
ConVar tf_bot_engineer_building_health_multiplier("tf_bot_engineer_building_health_multiplier", "2", FCVAR_CHEAT);

// server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_idle.cpp
ConVar tf_bot_engineer_mvm_sentry_hint_bomb_forward_range("tf_bot_engineer_mvm_sentry_hint_bomb_forward_range", "0", FCVAR_CHEAT);
ConVar tf_bot_engineer_mvm_sentry_hint_bomb_backward_range("tf_bot_engineer_mvm_sentry_hint_bomb_backward_range", "3000", FCVAR_CHEAT);
ConVar tf_bot_engineer_mvm_hint_min_distance_from_bomb("tf_bot_engineer_mvm_hint_min_distance_from_bomb", "1300", FCVAR_CHEAT);
ConCommand tf_bot_mvm_show_engineer_hint_region_command("tf_bot_mvm_show_engineer_hint_region", &tf_bot_mvm_show_engineer_hint_region, "Show the nav areas MvM engineer bots will consider when selecting sentry and teleporter hints", FCVAR_CHEAT, nullptr);

// server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_teleport_spawn.cpp

// server/tf/bot/behavior/engineer/tf_bot_engineer_build.cpp
ConVar tf_raid_engineer_infinte_metal("tf_raid_engineer_infinte_metal", "1", FCVAR_CHEAT | FCVAR_DEVELOPMENTONLY);

// server/tf/bot/behavior/engineer/tf_bot_engineer_building.cpp
ConVar tf_bot_engineer_retaliate_range("tf_bot_engineer_retaliate_range", "750", FCVAR_CHEAT, "If attacker who destroyed sentry is closer than this, attack. Otherwise, retreat");
ConVar tf_bot_engineer_exit_near_sentry_range("tf_bot_engineer_exit_near_sentry_range", "2500", FCVAR_CHEAT, "Maximum travel distance between a bot's Sentry gun and its Teleporter Exit");
ConVar tf_bot_engineer_max_sentry_travel_distance_to_point("tf_bot_engineer_max_sentry_travel_distance_to_point", "2500", FCVAR_CHEAT, "Maximum travel distance between a bot's Sentry gun and the currently contested point");

// server/tf/bot/behavior/engineer/tf_bot_engineer_build_sentrygun.cpp

// server/tf/bot/behavior/engineer/tf_bot_engineer_build_teleport_entrance.cpp
ConVar tf_bot_max_teleport_entrance_travel("tf_bot_max_teleport_entrance_travel", "1500", FCVAR_CHEAT, "Don't plant teleport entrances farther than this travel distance from our spawn room");
ConVar tf_bot_teleport_build_surface_normal_limit("tf_bot_teleport_build_surface_normal_limit", "0.99", FCVAR_CHEAT, "If the ground normal Z component is less that this value, Engineer bots won't place their entrance teleporter");

// server/tf/bot/behavior/engineer/tf_bot_engineer_build_teleport_exit.cpp

// server/tf/bot/behavior/engineer/tf_bot_engineer_move_to_build.cpp
ConVar tf_bot_debug_sentry_placement("tf_bot_debug_sentry_placement", "0", FCVAR_CHEAT);
ConVar tf_bot_max_teleport_exit_travel_to_point("tf_bot_max_teleport_exit_travel_to_point", "2500", FCVAR_CHEAT, "In an offensive engineer bot's tele exit is farther from the point than this, destroy it");
ConVar tf_bot_min_teleport_travel("tf_bot_min_teleport_travel", "3000", FCVAR_CHEAT, "Minimum travel distance between teleporter entrance and exit before engineer bot will build one");

// server/tf/bot/behavior/medic/tf_bot_medic_heal.cpp
ConVar tf_bot_medic_stop_follow_range("tf_bot_medic_stop_follow_range", "75", FCVAR_CHEAT);
ConVar tf_bot_medic_start_follow_range("tf_bot_medic_start_follow_range", "250", FCVAR_CHEAT);
ConVar tf_bot_medic_max_heal_range("tf_bot_medic_max_heal_range", "600", FCVAR_CHEAT);
ConVar tf_bot_medic_debug("tf_bot_medic_debug", "0", FCVAR_CHEAT);
ConVar tf_bot_medic_max_call_response_range("tf_bot_medic_max_call_response_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_medic_cover_test_resolution("tf_bot_medic_cover_test_resolution", "8", FCVAR_CHEAT);

// server/tf/bot/behavior/medic/tf_bot_medic_retreat.cpp

// server/tf/bot/behavior/missions/tf_bot_mission_destroy_sentries.cpp
// server/tf/bot/behavior/missions/tf_bot_mission_reprogrammed.cpp

// server/tf/bot/behavior/missions/tf_bot_mission_suicide_bomber.cpp
ConVar tf_bot_suicide_bomb_range("tf_bot_suicide_bomb_range", "300", FCVAR_CHEAT);
ConVar tf_bot_suicide_bomb_friendly_fire("tf_bot_suicide_bomb_friendly_fire", "1", FCVAR_CHEAT);

// server/tf/bot/behavior/nav_entities/tf_bot_nav_ent_destroy_entity.cpp
// server/tf/bot/behavior/nav_entities/tf_bot_nav_ent_move_to.cpp
// server/tf/bot/behavior/nav_entities/tf_bot_nav_ent_wait.cpp

// server/tf/bot/behavior/scenario/capture_point/tf_bot_capture_point.cpp
ConVar tf_bot_offense_must_push_time("tf_bot_offense_must_push_time", "120", FCVAR_CHEAT, "If timer is less than this, bots will push hard to cap");
ConVar tf_bot_capture_seek_and_destroy_min_duration("tf_bot_capture_seek_and_destroy_min_duration", "15", FCVAR_CHEAT, "If a capturing bot decides to go hunting, this is the min duration he will hunt for before reconsidering");
ConVar tf_bot_capture_seek_and_destroy_max_duration("tf_bot_capture_seek_and_destroy_max_duration", "30", FCVAR_CHEAT, "If a capturing bot decides to go hunting, this is the max duration he will hunt for before reconsidering");

// server/tf/bot/behavior/scenario/capture_point/tf_bot_defend_point.cpp
ConVar tf_bot_defense_must_defend_time("tf_bot_defense_must_defend_time", "300", FCVAR_CHEAT, "If timer is less than this, bots will stay near point and guard");
ConVar tf_bot_max_point_defend_range("tf_bot_max_point_defend_range", "1250", FCVAR_CHEAT, "How far (in travel distance) from the point defending bots will take up positions");
ConVar tf_bot_defense_debug("tf_bot_defense_debug", "0", FCVAR_CHEAT);

// server/tf/bot/behavior/scenario/capture_point/tf_bot_defend_point_block_capture.cpp
ConVar tf_bot_defend_owned_point_percent("tf_bot_defend_owned_point_percent", "0.5", FCVAR_CHEAT, "Stay on the contested point we own until enemy cap percent falls below this");

// server/tf/bot/behavior/scenario/capture_the_flag/tf_bot_attack_flag_defenders.cpp
ConVar tf_bot_flag_escort_range("tf_bot_flag_escort_range", "500", FCVAR_CHEAT);

// server/tf/bot/behavior/scenario/capture_the_flag/tf_bot_deliver_flag.cpp
ConVar tf_mvm_bot_allow_flag_carrier_to_fight("tf_mvm_bot_allow_flag_carrier_to_fight", "1", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_1st_upgrade("tf_mvm_bot_flag_carrier_interval_to_1st_upgrade", "5", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_2nd_upgrade("tf_mvm_bot_flag_carrier_interval_to_2nd_upgrade", "15", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_3rd_upgrade("tf_mvm_bot_flag_carrier_interval_to_3rd_upgrade", "15", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_health_regen("tf_mvm_bot_flag_carrier_health_regen", "45.0f", FCVAR_CHEAT);

// server/tf/bot/behavior/scenario/capture_the_flag/tf_bot_escort_flag_carrier.cpp
ConVar tf_bot_flag_escort_give_up_range("tf_bot_flag_escort_give_up_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_flag_escort_max_count("tf_bot_flag_escort_max_count", "4", FCVAR_CHEAT);

// server/tf/bot/behavior/scenario/capture_the_flag/tf_bot_fetch_flag.cpp
// server/tf/bot/behavior/scenario/???/tf_bot_creep_wave.cpp
// server/tf/bot/behavior/scenario/payload/tf_bot_payload_block.cpp

// server/tf/bot/behavior/scenario/payload/tf_bot_payload_guard.cpp
ConVar tf_bot_payload_guard_range("tf_bot_payload_guard_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_debug_payload_guard_vantage_points("tf_bot_debug_payload_guard_vantage_points", nullptr, FCVAR_CHEAT);

// server/tf/bot/behavior/scenario/payload/tf_bot_payload_push.cpp
ConVar tf_bot_cart_push_radius("tf_bot_cart_push_radius", "60", FCVAR_CHEAT);

// server/tf/bot/behavior/scenario/???/tf_bot_companion.cpp
// server/tf/bot/behavior/scenario/???/tf_bot_guard_area.cpp
// server/tf/bot/behavior/scenario/???/tf_bot_mob_rush.cpp
// server/tf/bot/behavior/scenario/???/tf_bot_squad_attack.cpp
// server/tf/bot/behavior/scenario/???/tf_bot_wander.cpp

// server/tf/bot/behavior/squad/tf_bot_sniper_attack.cpp
ConVar tf_bot_sniper_flee_range("tf_bot_sniper_flee_range", "400", FCVAR_CHEAT, "If threat is closer than this, retreat");
ConVar tf_bot_sniper_melee_range("tf_bot_sniper_melee_range", "200", FCVAR_CHEAT, "If threat is closer than this, attack with melee weapon");
ConVar tf_bot_sniper_linger_time("tf_bot_sniper_linger_time", "5", FCVAR_CHEAT, "How long Sniper will wait around after losing his target before giving up");

// server/tf/bot/behavior/sniper/tf_bot_sniper_lurk.cpp
ConVar tf_bot_sniper_patience_duration("tf_bot_sniper_patience_duration", "10", FCVAR_CHEAT, "How long a Sniper bot will wait without seeing an enemy before picking a new spot");
ConVar tf_bot_sniper_target_linger_duration("tf_bot_sniper_target_linger_duration", "2", FCVAR_CHEAT, "How long a Sniper bot will keep toward at a target it just lost sight of");
ConVar tf_bot_sniper_allow_opportunistic("tf_bot_sniper_allow_opportunistic", "1", FCVAR_NONE, "If set, Snipers will stop on their way to their preferred lurking spot to snipe at opportunistic targets");
ConVar tf_mvm_bot_sniper_target_by_dps("tf_mvm_bot_sniper_target_by_dps", "1", FCVAR_CHEAT | FCVAR_DEVELOPMENTONLY, "If set, Snipers in MvM mode target the victim that has the highest DPS");

// server/tf/bot/behavior/spy/tf_bot_spy_attack.cpp
ConVar tf_bot_spy_knife_range("tf_bot_spy_knife_range", "300", FCVAR_CHEAT, "If threat is closer than this, prefer our knife");
ConVar tf_bot_spy_change_target_range_threshold("tf_bot_spy_change_target_range_threshold", "300", FCVAR_CHEAT);

// server/tf/bot/behavior/spy/tf_bot_spy_backstab.cpp
// server/tf/bot/behavior/spy/tf_bot_spy_escape.cpp
// server/tf/bot/behavior/spy/tf_bot_spy_hide.cpp

// server/tf/bot/behavior/spy/tf_bot_spy_infiltrate.cpp
ConVar tf_bot_debug_spy("tf_bot_debug_spy", "0", FCVAR_CHEAT);

// server/tf/bot/behavior/spy/tf_bot_spy_leave_spawn_room.cpp
// server/tf/bot/behavior/spy/tf_bot_spy_lurk.cpp
// server/tf/bot/behavior/spy/tf_bot_spy_sap.cpp

// server/tf/bot/behavior/squad/tf_bot_escort_squad_leader.cpp
ConVar tf_bot_squad_escort_range("tf_bot_squad_escort_range", "500", FCVAR_CHEAT);
ConVar tf_bot_formation_debug("tf_bot_formation_debug", "0", FCVAR_CHEAT);

// server/tf/bot/behavior/tf_bot_approach_object.cpp

// server/tf/bot/behavior/tf_bot_attack.cpp
ConVar tf_bot_path_lookahead_range("tf_bot_path_lookahead_range", "300", FCVAR_NONE);
ConVar tf_bot_sniper_aim_error("tf_bot_sniper_aim_error", "0.01", FCVAR_CHEAT);
ConVar tf_bot_sniper_aim_steady_rate("tf_bot_sniper_aim_steady_rate", "10", FCVAR_CHEAT);
ConVar tf_bot_debug_sniper("tf_bot_debug_sniper", "0", FCVAR_CHEAT);
ConVar tf_bot_fire_weapon_min_time("tf_bot_fire_weapon_min_time", "1", FCVAR_CHEAT);
ConVar tf_bot_taunt_victim_chance("tf_bot_taunt_victim_chance", "20", FCVAR_NONE);
ConVar tf_bot_notice_backstab_chance("tf_bot_notice_backstab_chance", "25", FCVAR_CHEAT);
ConVar tf_bot_notice_backstab_min_chance("tf_bot_notice_backstab_min_chance", "100", FCVAR_CHEAT);
ConVar tf_bot_notice_backstab_max_chance("tf_bot_notice_backstab_max_chance", "750", FCVAR_CHEAT);
ConVar tf_bot_arrow_elevation_rate("tf_bot_arrow_elevation_rate", "0.0001", FCVAR_CHEAT, "When firing arrows at far away targets, this is the degree/range slope to raise our aim");
ConVar tf_bot_ballistic_elevation_rate("tf_bot_ballistic_elevation_rate", "0.01", FCVAR_CHEAT, "When lobbing grenades at far away targets, this is the degree/range slope to raise our aim");
ConVar tf_bot_hitscan_range_limit("tf_bot_hitscan_range_limit", "1800", FCVAR_CHEAT);
ConVar tf_bot_always_full_reload("tf_bot_always_full_reload", "0", FCVAR_CHEAT);
ConVar tf_bot_fire_weapon_allowed("tf_bot_fire_weapon_allowed", "1", FCVAR_CHEAT, "If zero, TFBots will not pull the trigger of their weapons (but will act like they did)");

// server/tf/bot/behavior/tf_bot_behavior.cpp
// server/tf/bot/behavior/tf_bot_dead.cpp

// server/tf/bot/behavior/tf_bot_destroy_enemy_sentry.cpp
ConVar tf_bot_debug_destroy_enemy_sentry("tf_bot_debug_destroy_enemy_sentry", "0", FCVAR_CHEAT);
ConVar tf_bot_max_grenade_launch_at_sentry_range("tf_bot_max_grenade_launch_at_sentry_range", "1500", FCVAR_CHEAT);
ConVar tf_bot_max_sticky_launch_at_sentry_range("tf_bot_max_sticky_launch_at_sentry_range", "1500", FCVAR_CHEAT);

// server/tf/bot/behavior/tf_bot_escort.cpp
ConVar tf_bot_escort_range("tf_bot_escort_range", "300", FCVAR_CHEAT);

// server/tf/bot/behavior/tf_bot_get_ammo.cpp
ConVar tf_bot_ammo_search_range("tf_bot_ammo_search_range", "5000", FCVAR_CHEAT, "How far bots will search to find ammo around them");
ConVar tf_bot_debug_ammo_scavanging("tf_bot_debug_ammo_scavanging", "0", FCVAR_CHEAT);
// TODO: static var init, s_possibleAmmo, -1

// server/tf/bot/behavior/tf_bot_get_health.cpp
ConVar tf_bot_health_critical_ratio("tf_bot_health_critical_ratio", "0.3", FCVAR_CHEAT);
ConVar tf_bot_health_ok_ratio("tf_bot_health_ok_ratio", "0.8", FCVAR_CHEAT);
ConVar tf_bot_health_search_near_range("tf_bot_health_search_near_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_health_search_far_range("tf_bot_health_search_far_range", "2000", FCVAR_CHEAT);
// TODO: static var init, s_possibleHealth, -1

// server/tf/bot/behavior/tf_bot_melee_attack.cpp
ConVar tf_bot_melee_attack_abandon_range("tf_bot_melee_attack_abandon_range", "500", FCVAR_CHEAT, "If threat is farther away than this, bot will switch back to its primary weapon and attack");

// server/tf/bot/behavior/tf_bot_move_to_vantage_point.cpp
// server/tf/bot/behavior/tf_bot_mvm_deploy_bomb.cpp

// server/tf/bot/behavior/tf_bot_retreat_to_cover.cpp
ConVar tf_bot_retreat_to_cover_range("tf_bot_retreat_to_cover_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_debug_retreat_to_cover("tf_bot_debug_retreat_to_cover", "0", FCVAR_CHEAT);
ConVar tf_bot_wait_in_cover_min_time("tf_bot_wait_in_cover_min_time", "1", FCVAR_CHEAT);
ConVar tf_bot_wait_in_cover_max_time("tf_bot_wait_in_cover_max_time", "2", FCVAR_CHEAT);

// server/tf/bot/behavior/tf_bot_scenario_monitor.cpp
ConVar tf_bot_fetch_lost_flag_time("tf_bot_fetch_lost_flag_time", "10", FCVAR_CHEAT, "How long busy TFBots will ignore the dropped flag before they give up what they are doing and go after it");
ConVar tf_bot_flag_kill_on_touch("tf_bot_flag_kill_on_touch", "0", FCVAR_CHEAT, "If nonzero, any bot that picks up the flag dies. For testing.");

// server/tf/bot/behavior/tf_bot_seek_and_destroy.cpp
ConVar tf_bot_debug_seek_and_destroy("tf_bot_debug_seek_and_destroy", "0", FCVAR_CHEAT);

// server/tf/bot/behavior/tf_bot_tactical_monitor.cpp
ConVar tf_bot_force_jump("tf_bot_force_jump", "0", FCVAR_CHEAT, "Force bots to continuously jump");

// server/tf/bot/behavior/tf_bot_taunt.cpp
// server/tf/bot/behavior/tf_bot_use_item.cpp
// server/tf/bot/behavior/tf_bot_use_teleporter.cpp
// server/tf/bot/behavior/training/tf_bot_training.cpp
// server/tf/bot/map_entities/tf_bot_generator.cpp
// server/tf/bot/map_entities/tf_bot_hint.cpp
// server/tf/bot/map_entities/tf_bot_hint_engineer_nest.cpp
// server/tf/bot/map_entities/tf_bot_hint_entity.cpp
// server/tf/bot/map_entities/tf_bot_hint_sentrygun.cpp
// server/tf/bot/map_entities/tf_bot_hint_teleporter_exit.cpp
// server/tf/bot/map_entities/tf_bot_proxy.cpp
// server/tf/bot/map_entities/tf_bot_roster.cpp
// server/tf/bot/map_entities/tf_spawner.cpp
// server/tf/bot/map_entities/tf_spawner_boss.cpp

// server/tf/bot/tf_bot.cpp
ConVar tf_bot_force_class("tf_bot_force_class", "", FCVAR_GAMEDLL, "If set to a class name, all TFBots will respawn as that class");
ConVar tf_bot_notice_gunfire_range("tf_bot_notice_gunfire_range", "3000", FCVAR_GAMEDLL);
ConVar tf_bot_notice_quiet_gunfire_range("tf_bot_notice_quiet_gunfire_range", "500", FCVAR_GAMEDLL);
ConVar tf_bot_sniper_personal_space_range("tf_bot_sniper_personal_space_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_pyro_deflect_tolerance("tf_bot_pyro_deflect_tolerance", "0.5", FCVAR_CHEAT);
ConVar tf_bot_keep_class_after_death("tf_bot_keep_class_after_death", "0", FCVAR_GAMEDLL);
ConVar tf_bot_prefix_name_with_difficulty("tf_bot_prefix_name_with_difficulty", "0", FCVAR_GAMEDLL, "Append the skill level of the bot to the bot's name");
ConVar tf_bot_near_point_travel_distance("tf_bot_near_point_travel_distance", "750", FCVAR_CHEAT);
ConVar tf_bot_pyro_shove_away_range("tf_bot_pyro_shove_away_range", "250", FCVAR_CHEAT, "If a Pyro bot's target is closer than this, compression blast them away");
ConVar tf_bot_pyro_always_reflect("tf_bot_pyro_always_reflect", "0", FCVAR_CHEAT, "Pyro bots will always reflect projectiles fired at them. For tesing/debugging purposes.");
ConVar tf_bot_sniper_spot_min_range("tf_bot_sniper_spot_min_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_sniper_spot_max_count("tf_bot_sniper_spot_max_count", "10", FCVAR_CHEAT, "Stop searching for sniper spots when each side has found this many");
ConVar tf_bot_sniper_spot_search_count("tf_bot_sniper_spot_search_count", "10", FCVAR_CHEAT, "Search this many times per behavior update frame");
ConVar tf_bot_sniper_spot_point_tolerance("tf_bot_sniper_spot_point_tolerance", "750", FCVAR_CHEAT);
ConVar tf_bot_sniper_spot_epsilon("tf_bot_sniper_spot_epsilon", "100", FCVAR_CHEAT);
ConVar tf_bot_sniper_goal_entity_move_tolerance("tf_bot_sniper_goal_entity_move_tolerance", "500", FCVAR_CHEAT);
ConVar tf_bot_suspect_spy_touch_interval("tf_bot_suspect_spy_touch_interval", "5", FCVAR_CHEAT, "How many seconds back to look for touches against suspicious spies");
ConVar tf_bot_suspect_spy_forced_cooldown("tf_bot_suspect_spy_forced_cooldown", "5", FCVAR_CHEAT, "How long to consider a suspicious spy as suspicious");
ConVar tf_bot_debug_tags("tf_bot_debug_tags", "0", FCVAR_CHEAT, "ent_text will only show tags on bots");
ConCommand tf_bot_add_command("tf_bot_add", &tf_bot_add, "Add a bot.", FCVAR_GAMEDLL, nullptr);
ConCommand tf_bot_kick_command("tf_bot_kick", &tf_bot_kick, "Remove a TFBot by name, or all bots (\"all\").", FCVAR_GAMEDLL, nullptr);
ConCommand tf_bot_kill_command("tf_bot_kill", &tf_bot_kill, "Kill a TFBot by name, or all bots (\"all\").", FCVAR_GAMEDLL, nullptr);
ConCommand tf_bot_warp_team_to_me("tf_bot_warp_team_to_me", &CMD_BotWarpTeamToMe, "", FCVAR_CHEAT | FCVAR_GAMEDLL, nullptr);

// server/tf/bot/tf_bot_body.cpp
// server/tf/bot/tf_bot_locomotion.cpp

// server/tf/bot/tf_bot_manager.cpp
CTFBotManager sTFBotManager;
ConVar tf_bot_difficulty("tf_bot_difficulty", "1", FCVAR_NONE, "Defines the skill of bots joining the game.  Values are: 0=easy, 1=normal, 2=hard, 3=expert.");
ConVar tf_bot_quota("tf_bot_quota", "0", FCVAR_NONE, "Determines the total number of tf bots in the game.");
ConVar tf_bot_quota_mode("tf_bot_quota_mode", "normal", FCVAR_NONE, "Determines the type of quota. Allowed values: 'normal', 'fill', and 'match'. If 'fill', the server will adjust bots to keep N players in the game, where N is bot_quota. If 'match', the server will maintain a 1:N ratio of humans to bots, where N is bot_quota.");
ConVar tf_bot_join_after_player("tf_bot_join_after_player", "1", FCVAR_NONE, "If nonzero, bots wait until a player joins before entering the game.");
ConVar tf_bot_auto_vacate("tf_bot_auto_vacate", "1", FCVAR_NONE, "If nonzero, bots will automatically leave to make room for human players.");
ConVar tf_bot_offline_practice("tf_bot_offline_practice", "0", FCVAR_NONE, "Tells the server that it is in offline practice mode.");
ConVar tf_bot_melee_only("tf_bot_melee_only", "0", FCVAR_GAMEDLL, "If nonzero, TFBots will only use melee weapons");
ConCOmmand tf_bot_debug_log_command("tf_bot_debug_stuck_log", &tf_bot_debug_stuck_log, "Given a server logfile, visually display bot stuck locations.", FCVAR_CHEAT | FCVAR_GAMEDLL, nullptr);
ConCommand tf_bot_debug_log_clear_command("tf_bot_debug_stuck_log_clear", &tf_bot_stuck_log_clear, "Clear currently loaded bot stuck data", FCVAR_CHEAT | FCVAR_GAMEDLL, nullptr);

// server/tf/bot/tf_bot_squad.cpp

// server/tf/bot/tf_bot_vision.cpp
ConVar tf_bot_choose_target_interval("tf_bot_choose_target_interval", "0.3f", FCVAR_CHEAT, "How often, in seconds, a TFBot can reselect his target");
ConVar tf_bot_sniper_choose_target_interval("tf_bot_sniper_choose_target_interval", "3.0f", FCVAR_CHEAT, "How often, in seconds, a zoomed-in Sniper can reselect his target");

// server/tf/bot_npc/bot_npc.cpp

// server/tf/bot_npc/bot_npc_archer.cpp
ConVar tf_bot_npc_archer_health("tf_bot_npc_archer_health", "100", FCVAR_CHEAT);
ConVar tf_bot_npc_archer_speed("tf_bot_npc_archer_speed", "100", FCVAR_CHEAT);
ConVar tf_bot_npc_archer_shoot_interval("tf_bot_npc_archer_shoot_interval", "2", FCVAR_CHEAT);
ConVar tf_bot_npc_archer_arrow_damage("tf_bot_npc_archer_arrow_damage", "75", FCVAR_CHEAT);
// TODO: entity factory for "bot_npc_archer"

// server/tf/bot_npc/bot_npc_decoy.cpp
// TODO: entity factory for "bot_npc_decoy"
ConVar tf_decoy_lifetime("tf_decoy_lifetime", "5", FCVAR_CHEAT, "The lifetime of a decoy, in seconds");

// server/tf/bot_npc/bot_npc_mini.cpp
// server/tf/bot_npc/bot_npc_minion.cpp


// server/tf/entity_currencypack.cpp


// server/tf/nav_mesh/tf_nav_area.cpp
ConVar tf_nav_show_incursion_distances("tf_nav_show_incursion_distance", "0", FCVAR_CHEAT, "Display travel distances from current spawn room (1=red, 2=blue)");
ConVar tf_nav_show_bomb_target_distance("tf_nav_show_bomb_target_distance", "0", FCVAR_CHEAT, "Display travel distances to bomb target (MvM mode)");
ConVar tf_nav_show_turf_ownership("tf_nav_show_turf_ownership", "0", FCVAR_CHEAT, "Color nav area by smallest incursion distance");
ConVar tf_nav_in_combat_duration("tf_nav_in_combat_duration", "30", FCVAR_CHEAT, "How long after gunfire occurs is this area still considered to be 'in combat'");
ConVar tf_nav_combat_build_rate("tf_nav_combat_build_rate", "0.05", FCVAR_CHEAT, "Gunfire/second increase (combat caps at 1.0)");
ConVar tf_nav_combat_decay_rate("tf_nav_combat_decay_rate", "0.022", FCVAR_CHEAT, "Decay/second toward zero");
ConVar tf_show_sniper_areas("tf_show_sniper_areas", "0", FCVAR_CHEAT);
ConVar tf_show_sniper_areas_safety_range("tf_show_sniper_areas_safety_range", "1000", FCVAR_CHEAT);
ConVar tf_show_incursion_range("tf_show_incursion_range", "0", FCVAR_CHEAT, "1 = red, 2 = blue");
ConVar tf_show_incursion_range_min("tf_show_incursion_range_min", "0", FCVAR_CHEAT, "Highlight areas with incursion distances between min and max cvar values");
ConVar tf_show_incursion_range_max("tf_show_incursion_range_max", "0", FCVAR_CHEAT, "Highlight areas with incursion distances between min and max cvar values");

// server/tf/nav_mesh/tf_nav_interface.cpp

// server/tf/nav_mesh/tf_nav_mesh.cpp
ConVar tf_show_in_combat_areas("tf_show_in_combat_areas", "0", FCVAR_CHEAT);
ConVar tf_show_enemy_invasion_areas("tf_show_enemy_invasion_areas", "0", FCVAR_CHEAT, "Highlight areas where the enemy team enters the visible environment of the local player");
ConVar tf_show_blocked_areas("tf_show_blocked_areas", "0", FCVAR_CHEAT, "Highlight areas that are considered blocked for TF-specific reasons");
ConVar tf_show_incursion_flow("tf_show_incursion_flow", "0", FCVAR_CHEAT);
ConVar tf_show_incursion_flow_range("tf_show_incursion_flow_range", "150", FCVAR_CHEAT, "1 = red, 2 = blue");
ConVar tf_show_incursion_flow_gradient("tf_show_incursion_flow_gradient", "0", FCVAR_CHEAT, "1 = red, 2 = blue");
ConVar tf_show_mesh_decoration("tf_show_mesh_decoration", "0", FCVAR_CHEAT, "Highlight special areas");
ConVar tf_show_mesh_decoration_manual("tf_show_mesh_decoration_manual", "0", FCVAR_CHEAT, "Highlight special areas marked by hand");
ConVar tf_show_sentry_danger("tf_show_sentry_danger", "0", FCVAR_CHEAT, "Show sentry danger areas. 1:Use m_sentryAreas. 2:Check all nav areas.");
ConVar tf_show_actor_potential_visibility("tf_show_actor_potential_visibility", "0", FCVAR_CHEAT);
ConVar tf_show_control_points("tf_show_control_points", "0", FCVAR_CHEAT);
ConVar tf_show_bomb_drop_areas("tf_show_bomb_drop_areas", "0", FCVAR_CHEAT);
ConVar tf_bot_min_setup_gate_defend_range("tf_bot_min_setup_gate_defend_range", "750", FCVAR_CHEAT, "How close from the setup gate(s) defending bots can take up positions. Areas closer than this will be in cover to ambush.");
ConVar tf_bot_max_setup_gate_defend_range("tf_bot_max_setup_gate_defend_range", "2000", FCVAR_CHEAT, "How far from the setup gate(s) defending bots can take up positions");
ConVar tf_bot_min_setup_gate_sniper_defend_range("tf_bot_min_setup_gate_sniper_defend_range", "1500", FCVAR_CHEAT, "How far from the setup gate(s) a defending sniper will take up position");
ConVar tf_show_gate_defense_areas("tf_show_gate_defense_areas", "0", FCVAR_CHEAT);
ConVar tf_show_point_defense_areas("tf_show_point_defense_areas", "0", FCVAR_CHEAT);
ConVar tf_select_ambush_areas_radius("tf_select_ambush_areas_radius", "750", FCVAR_CHEAT);
ConVar tf_select_ambush_areas_close_range("tf_select_ambush_areas_close_range", "300", FCVAR_CHEAT);
ConVar tf_select_ambush_areas_max_enemy_exposure_area("tf_select_ambush_areas_max_enemy_exposure_area", "500000", FCVAR_CHEAT);
ConCommand tf_select_ambush_areas("tf_select_ambush_areas", &CMD_SelectAmbushAreas, "Add good ambush spots to the selected set. For debugging.", FCVAR_CHEAT | FCVAR_GAMEDLL, nullptr);

// server/tf/nav_mesh/tf_nav_edit.cpp
// server/tf/nav_mesh/tf_path_follower.cpp


// server/tf/player_vs_environment/archer_proxy.cpp
// server/tf/player_vs_environment/???/boss_alpha_behavior.cpp
// server/tf/player_vs_environment/???/boss_alpha_chase_victim.cpp
// server/tf/player_vs_environment/???/boss_alpha_get_off_me.cpp
// server/tf/player_vs_environment/???/boss_alpha_guard_spot.cpp
// server/tf/player_vs_environment/???/boss_alpha_launch_grenades.cpp
// server/tf/player_vs_environment/???/boss_alpha_launch_rockets.cpp
// server/tf/player_vs_environment/???/boss_alpha_lost_victim.cpp
// server/tf/player_vs_environment/???/boss_alpha_nuke_attack.cpp
// server/tf/player_vs_environment/???/boss_alpha_stunned.cpp
// server/tf/player_vs_environment/???/boss_alpha_tactical_monitor.cpp
// server/tf/player_vs_environment/???/boss_alpha_wait_for_players.cpp
// server/tf/player_vs_environment/boss_alpha.cpp
// server/tf/player_vs_environment/monster_resource.cpp
// server/tf/player_vs_environment/tf_base_boss.cpp

// server/tf/player_vs_environment/tf_boss_battle_logic.cpp
// server/tf/player_vs_environment/tf_mann_vs_machine_logic.cpp
// server/tf/player_vs_environment/tf_point_weapon_mimic.cpp

// server/tf/player_vs_environment/tf_population_manager.cpp
ConVar tf_mvm_missioncyclefile("tf_mvm_missioncyclefile", "tf_mvm_missioncycle.res", FCVAR_NONE, "Name of the .res file used to cycle mvm misisons", &MvMMissionCycleFileChangedCallback);
ConVar tf_populator_debug("tf_populator_debug", "0", FCVAR_CHEAT);
ConVar tf_populator_active_buffer_range("tf_populator_active_buffer_range", "3000", FCVAR_CHEAT, "Populate the world this far ahead of lead raider, and this far behind last raider");
ConVar tf_mvm_default_sentry_buster_damage_dealt_threshold("tf_mvm_default_sentry_buster_damage_dealt_threshold", "3000", FCVAR_CHEAT | FCVAR_DEVELOPMENTONLY);
ConVar tf_mvm_default_sentry_buster_kill_threshold("tf_mvm_default_sentry_buster_kill_threshold", "15", FCVAR_CHEAT | FCVAR_DEVELOPMENTONLY);
ConVar tf_mvm_miniboss_scale("tf_mvm_miniboss_scale", "1.75", FCVAR_CHEAT | FCVAR_REPLICATED, "Full body scale for minibosses.", &MinibossScaleChangedCallBack);
ConVar tf_mvm_disconnect_on_victory("tf_mvm_disconnect_on_victory", "0", FCVAR_REPLICATED, "Enable to Disconnect Players after completing MvM");
ConVar tf_mvm_victory_reset_time("tf_mvm_victory_reset_time", "60.0", FCVAR_REPLICATED, "Seconds to wait after MvM victory before cycling to the next mission.  (Only used if tf_mvm_disconnect_on_victory is false.)");
ConVar tf_mvm_victory_disconnect_time("tf_mvm_victory_disconnect_time", "180.0", FCVAR_REPLICATED, "Seconds to wait after MvM victory before kicking players.  (Only used if tf_mvm_disconnect_on_victory is true.)");
ConVar tf_mvm_endless_force_on("tf_mvm_endless_force_on", "0", FCVAR_DONTRECORD | FCVAR_CHEAT | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "Force MvM Endless mode on");
ConVar tf_mvm_endless_wait_time("tf_mvm_endless_wait_time", "5.0f", FCVAR_DONTRECORD | FCVAR_CHEAT | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY);
ConVar tf_mvm_endless_bomb_reset("tf_mvm_endless_bomb_reset", "5", FCVAR_DONTRECORD | FCVAR_CHEAT | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "Number of Waves to Complete before bomb reset");
ConVar tf_mvm_endless_bot_cash("tf_mvm_endless_bot_cash", "120", FCVAR_DONTRECORD | FCVAR_CHEAT | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "In Endless, number of credits bots get per wave");
ConVar tf_mvm_endless_tank_boost("tf_mvm_endless_tank_boost", "0.2", FCVAR_DONTRECORD | FCVAR_CHEAT | FCVAR_REPLICATED | FCVAR_DEVELOPMENTONLY, "In Endless, amount of extra health for the tank per wave");
ConVar tf_populator_health_multiplier("tf_populator_health_multiplier", "1.0", FCVAR_DONTRECORD | FCVAR_CHEAT | FCVAR_REPLICATED);
ConVar tf_populator_damage_multiplier("tf_populator_damage_multiplier", "1.0", FCVAR_DONTRECORD | FCVAR_CHEAT | FCVAR_REPLICATED);
ConVar tf_mvm_skill("tf_mvm_skill", "1", FCVAR_DONTRECORD | FCVAR_CHEAT | FCVAR_REPLICATED, "Sets the challenge level of the invading bot army. 1 = easiest, 3 = normal, 5 = hardest", true, 1.0f, true, 5.0f, &MVMSkillChangedCallback);
ConCommand tf_mvm_nextmission_command("tf_mvm_nextmission", &tf_mvm_nextmission, "Load the next mission", FCVAR_CHEAT, nullptr);
ConCommand tf_mvm_force_victory_command("tf_mvm_force_victory", &tf_mvm_force_victory, "Force immediate victory.", FCVAR_CHEAT, nullptr);
ConCommand tf_mvm_checkpoint_command("tf_mvm_checkpoint", &tf_mvm_checkpoint, "Save a checkpoint snapshot", FCVAR_CHEAT, nullptr);
ConCommand tf_mvm_checkpoint_clear_command("tf_mvm_checkpoint_clear", &tf_mvm_checkpoint_clear, "Clear the saved checkpoint", FCVAR_CHEAT, nullptr);
ConCommand tf_mvm_jump_to_wave_command("tf_mvm_jump_to_wave", &tf_mvm_jump_to_wave, "Jumps directly to the given Mann Vs Machine wave number", FCVAR_CHEAT, nullptr);
ConCommand tf_mvm_debugstats_command("tf_mvm_debugstats", &tf_mvm_debugstats, "Dumpout MvM Data", FCVAR_CHEAT, nullptr);
// TODO: server class init for CPopulationManager ("info_populator")
// TODO: static var init for CPopulationManager::m_checkpointSnapshot

// server/tf/player_vs_environment/tf_populators.cpp
ConVar tf_mvm_engineer_teleporter_uber_duration("tf_mvm_engineer_teleporter_uber_duration", "5.f", FCVAR_CHEAT);
// TODO: static var init, s_lastTeleporter, probably an entity handle

// server/tf/player_vs_environment/tf_populator_interface.cpp
// server/tf/player_vs_environment/tf_populator_spawners.cpp

// server/tf/player_vs_environment/tf_tank_boss.cpp
// TODO: server class init for CTFTankDestruction ("tank_destruction")
// TODO: server class init for CTFTankBoss ("tank_boss")
ConCommand tf_mvm_tank_kill("tf_mvm_tank_kill", CMD_TankKill, "", FCVAR_CHEAT | FCVAR_GAMEDLL, nullptr);
ConCommand tf_mvm_tank_health("tf_mvm_tank_health", CMD_TankHealth, "", FCVAR_CHEAT | FCVAR_GAMEDLL, nullptr);

// server/tf/tf_raid_logic.cpp


// server/tf/tf_bot_temp.cpp
ConVar bot_debug("bot_debug", "0", FCVAR_CHEAT, "Bot debugging.");
ConVar bot_forcefireweapon("bot_forcefireweapon", "", FCVAR_NONE, "Force bots with the specified weapon to fire.");
ConVar bot_forceattack("bot_forceattack", "0", FCVAR_NONE, "When on, all bots fire their guns.");
ConVar bot_forceattack2("bot_forceattack2", "0", FCVAR_NONE, "When firing, use attack2.");
ConVar bot_forceattack_down("bot_forceattack_down", "1", FCVAR_NONE, "When firing, don't tap fire, hold it down.");
ConVar bot_changeclass("bot_changeclass", "0", FCVAR_NONE, "Force all bots to change to the specified class.");
ConVar bot_dontmove("bot_dontmove", "0", FCVAR_CHEAT);
ConVar bot_saveme("bot_saveme", "0", FCVAR_CHEAT);
ConVar bot_mimic_inverse("bot_mimic_inverse", "0", FCVAR_NONE, "Bot uses usercmd of player by index.");
ConVar bot_mimic_yaw_offset("bot_mimic_yaw_offset", "180", FCVAR_NONE, "Offsets the bot yaw.");
ConVar bot_selectweaponslot("bot_selectweaponslot", "-1", FCVAR_CHEAT, "set to weapon slot that bot should switch to.");
ConVar bot_randomnames("bot_randomnames", "0", FCVAR_CHEAT);
ConVar bot_jump("bot_jump", "0", FCVAR_CHEAT, "Force all bots to repeatedly jump.");
ConVar bot_crouch("bot_crouch", "0", FCVAR_CHEAT, "Force all bots to crouch.");
ConVar bot_nav_turnspeed("bot_nav_turnspeed", "5", FCVAR_CHEAT, "Rate at which bots turn to face their targets.");
ConVar bot_nav_wpdistance("bot_nav_wpdistance", "16", FCVAR_CHEAT, "Distance to a waypoint within which a bot considers as having reached it.");
ConVar bot_nav_wpdeceldistance("bot_nav_wpdeceldistance", "128", FCVAR_CHEAT, "Distance to a waypoint to which a bot starts to decelerate to reach it.");
ConVar bot_nav_simplifypaths("bot_nav_simplifypaths", "1", FCVAR_CHEAT, "If set, bots will skip waypoints if they already see the waypoint post.");
ConVar bot_nav_useoffsetpaths("bot_nav_useoffsetpaths", "1", FCVAR_CHEAT, "If set, bots will generate waypoints on both sides of portals between waypoints when building paths.");
ConVar bot_nav_offsetpathinset("bot_nav_offsetpathinset", "20", FCVAR_CHEAT, "Distance into an area that waypoints should be generated when pathfinding through portals.");
ConVar bot_nav_usefeelers("bot_nav_usefeelers", "1", FCVAR_CHEAT, "If set, bots will extend feelers to their sides to find & avoid upcoming collisions.");
ConVar bot_nav_recomputetime("bot_nav_recomputetime", "0.5", FCVAR_CHEAT, "Delay before bots recompute their path to targets that have moved when moving to them.");
ConVar bot_com_meleerange("bot_com_meleerange", "80", FCVAR_CHEAT, "Distance to a target that a melee bot wants to be within to attack.");
ConVar bot_com_wpnrange("bot_com_wpnrange", "400", FCVAR_CHEAT, "Distance to a target that a ranged bot wants to be within to attack.");
ConVar bot_com_viewrange("bot_com_viewrange", "2000", FCVAR_CHEAT, "Distance within which bots looking for any enemies will find them.");
// TODO: static var init for g_BotData (seems to be a CUtlVector<botdata_t::CommandInfo>)
ConCommand bot_kick_command("bot_kick", &bot_kick, "Remove a bot by name, or an entire team (\"red\" or \"blue\"), or all bots (\"all\").", FCVAR_CHEAT, nullptr);
ConCommand bot_command("bot", &bot, "Add a bot.", FCVAR_NONE, nullptr);
ConCommand bot_hurt_command("bot_hurt", &bot_hurt, "Hurt a bot by team, or all bots (\"all\").", FCVAR_GAMEDLL, nullptr);
ConCommand bot_sendcommand("bot_command", &cc_bot_sendcommand, "<bot id> <command string...>.  Sends specified command on behalf of specified bot", FCVAR_CHEAT, nullptr);
ConCommand bot_kill("bot_kill", &cc_bot_kill, "Kills a bot. Usage: bot_kill <bot name>", FCVAR_CHEAT, nullptr);
ConCommand bot_changeteams_command("bot_changeteams", &bot_changeteams, "Make all bots change teams", FCVAR_CHEAT, nullptr);
ConCommand bot_refill_command("bot_refill", &bot_refill, "Refill all bot ammo counts", FCVAR_CHEAT, nullptr);
ConCommand bot_whack_command("bot_whack", &bot_whack, "Deliver lethal damage from player to specified bot. Usage: bot_whack <bot name>", FCVAR_CHEAT, nullptr);
ConCommand bot_teleport_command("bot_teleport", &bot_teleport, "Teleport the specified bot to the specified position & angles.\n\tFormat: bot_teleport <bot name> <X> <Y> <Z> <Pitch> <Yaw> <Roll>", FCVAR_CHEAT, nullptr);
ConCommand bot_mirror_command("bot_mirror", &bot_mirror, "Forces the specified bot to be the same class, and use the same items, as you.", FCVAR_CHEAT, nullptr);
ConCommand bot_selectweapon_command("bot_selectweapon", &cc_bot_selectweapon, "Force a bot to select a weapon in a slot. Usage: bot_selectweapon <bot name> <weapon slot>", FCVAR_CHEAT, nullptr);
ConCommand bot_drop_command("bot_drop", &bot_drop, "Force the specified bot to drop his active weapon. Usage: bot_drop <bot name>", FCVAR_CHEAT, nullptr);
ConCommand bot_moveto_command("bot_moveto", &bot_moveto, "Force the specified bot to move to the point under your crosshair. Usage: bot_moveto <bot name>", FCVAR_CHEAT, nullptr);
// TODO: server class init for CTFBotController ("bot_controller")


// server/tf/tf_obj_sapper.cpp
ConVar tf_mvm_notice_sapped_squadmates_delay("tf_mvm_notice_sapped_squadmates_delay", "1", FCVAR_CHEAT | FCVAR_DEVELOPMENTONLY, "How long it takes for a squad leader to notice his squadmate was sapped");


// server/tf/tf_player.cpp
ConVar tf_deploying_bomb_time("tf_deploying_bomb_time", "1.90", FCVAR_CHEAT | FCVAR_DEVELOPMENTONLY, "Time to deploy bomb before the point of no return.");
ConVar tf_deploying_bomb_delay_time("tf_deploying_bomb_delay_time", "0.0", FCVAR_CHEAT | FCVAR_DEVELOPMENTONLY, "Time to delay before deploying bomb.");
ConVar tf_mvm_death_penalty("tf_mvm_death_penalty", "0", FCVAR_CHEAT | FCVAR_NOTIFY | FCVAR_DEVELOPMENTONLY, "How much currency players lose when dying");
ConVar tf_nav_in_combat_range("tf_nav_in_combat_range", "1000", FCVAR_CHEAT);
ConCommand currency_give_command("currency_give", &currency_give, "Have some in-game money.", FCVAR_CHEAT, nullptr);


// client/NextBot/C_NextBot.cpp
ConVar nb_shadow_dist("nb_shadow_dist", "400", FCVAR_NONE);
// TODO: client class init for NextBotCombatCharacter

// client/tf/player_vs_environment/c_tf_upgrades.cpp
ConVar tf_mvm_tabs_discovered("tf_mvm_tabs_discovered", "0", FCVAR_ARCHIVE, "Remember how many times players have clicked tabs.");

// client/tf/vgui/tf_classmenu.cpp
ConVar tf_mvm_classupgradehelpcount("tf_mvm_classupgradehelpcount", "0", FCVAR_DONTRECORD | FCVAR_ARCHIVE | FCVAR_HIDDEN | FCVAR_CLIENTDLL, "The number of times the player upgrade help dialog has displayed.");
