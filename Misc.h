#define COLOR_WHITE    Color(255, 255, 255, 255)
#define COLOR_LTYELLOW Color(255, 255, 150, 255)
#define COLOR_LTGREEN  Color(150, 255, 150, 255)
#define COLOR_GREEN    Color(  0, 255,   0, 255)
#define COLOR_RED      Color(255,   0,   0, 255)
#define COLOR_MAGENTA  Color(255,   0, 255, 255)
#define COLOR_GRAY100  Color(100, 100, 100, 255)


ConVar NextBotDebugHistory("nb_debug_history", "1", FCVAR_CHEAT, "If true, each bot keeps a history of debug output in memory");
/* TODO:
nb_allow_avoiding                        : 1        : , "sv", "cheat"  : 
nb_allow_climbing                        : 1        : , "sv", "cheat"  : 
nb_allow_gap_jumping                     : 1        : , "sv", "cheat"  : 
nb_blind                                 : 0        : , "sv", "cheat"  : Disable vision
nb_command                               : cmd      : , "sv", "cheat"  : Sends a command string to all bots
nb_debug                                 : cmd      : , "sv", "cheat"  : Debug NextBots.  Categories are: BEHAVIOR, LOOK_AT, PATH, ANIMATION, LOCOMOTION, VISION, HEARING, EVENTS, ERRORS.
nb_debug_climbing                        : 0        : , "sv", "cheat"  : 
nb_debug_filter                          : cmd      : , "sv", "cheat"  : Add items to the NextBot debug filter. Items can be entindexes or part of the indentifier of one or more bots.
nb_debug_history                         : 1        : , "sv", "cheat"  : If true, each bot keeps a history of debug output in memory
nb_debug_known_entities                  : 0        : , "sv", "cheat"  : Show the 'known entities' for the bot that is the current spectator target
nb_delete_all                            : cmd      : , "sv", "cheat"  : Delete all non-player NextBot entities.
nb_force_look_at                         : cmd      : , "sv", "cheat"  : Force selected bot to look at the local player's position
nb_goal_look_ahead_range                 : 50       : , "sv", "cheat"  : 
nb_head_aim_resettle_angle               : 100      : , "sv", "cheat"  : After rotating through this angle, the bot pauses to 'recenter' its virtual mouse on its virtual mousepad
nb_head_aim_resettle_time                : 0.3      : , "sv", "cheat"  : How long the bot pauses to 'recenter' its virtual mouse on its virtual mousepad
nb_head_aim_settle_duration              : 0.3      : , "sv", "cheat"  : 
nb_head_aim_steady_max_rate              : 100      : , "sv", "cheat"  : 
nb_ladder_align_range                    : 50       : , "sv", "cheat"  : 
nb_last_area_update_tolerance            : 4.0      : , "sv", "cheat"  : Distance a character needs to travel in order to invalidate cached area
nb_move_to_cursor                        : cmd      : , "sv", "cheat"  : Tell all NextBots to move to the cursor position
nb_path_draw_inc                         : 100      : , "sv", "cheat"  : 
nb_path_draw_segment_count               : 100      : , "sv", "cheat"  : 
nb_path_segment_influence_radius         : 100      : , "sv", "cheat"  : 
nb_player_crouch                         : 0        : , "sv", "cheat"  : Force bots to crouch
nb_player_move                           : 1        : , "sv", "cheat"  : Prevents bots from moving
nb_player_move_direct                    : 0        : , "sv"           : 
nb_player_stop                           : 0        : , "sv", "cheat"  : Stop all NextBotPlayers from updating
nb_player_walk                           : 0        : , "sv", "cheat"  : Force bots to walk
nb_saccade_speed                         : 1000     : , "sv", "cheat"  : 
nb_saccade_time                          : 0.1      : , "sv", "cheat"  : 
nb_select                                : cmd      : , "sv", "cheat"  : Select the bot you are aiming at for further debug operations.
nb_shadow_dist                           : 400      : , "cl"           : 
nb_speed_look_ahead_range                : 150      : , "sv", "cheat"  : 
nb_stop                                  : 0        : , "sv", "cheat", "rep" : Stop all NextBots
nb_update_debug                          : 0        : , "sv", "cheat"  : 
nb_update_framelimit                     : 15       : , "sv", "cheat"  : 
nb_update_frequency                      : .1       : , "sv", "cheat"  : 
nb_update_maxslide                       : 2        : , "sv", "cheat"  : 
nb_warp_selected_here                    : cmd      : , "sv", "cheat"  : Teleport the selected bot to your cursor position

tf_mvm_bot_allow_flag_carrier_to_fight   : 1        : , "sv", "cheat"  : 
tf_mvm_bot_flag_carrier_health_regen     : 45.0f    : , "sv", "cheat"  : 
tf_mvm_bot_flag_carrier_interval_to_1st_upgrade : 5        : , "sv", "cheat"  : 
tf_mvm_bot_flag_carrier_interval_to_2nd_upgrade : 15       : , "sv", "cheat"  : 
tf_mvm_bot_flag_carrier_interval_to_3rd_upgrade : 15       : , "sv", "cheat"  : 
tf_mvm_bot_flag_carrier_movement_penalty : 0.5      : , "sv", "cheat", "rep" : 
tf_mvm_bot_sniper_target_by_dps          : 1        : , "sv", "cheat", "launcher" : If set, Snipers in MvM mode target the victim that has the highest DPS
tf_mvm_buybacks_method                   : 0        : , "sv", "cheat", "rep", "matsys" : When set to 0, use the traditional, currency-based system.  When set to 1, use finite, charge-based system.
tf_mvm_buybacks_per_wave                 : 3        : , "sv", "cheat", "rep", "matsys" : The fixed number of buybacks players can use per-wave.
tf_mvm_checkpoint                        : cmd      : , "sv", "cheat"  : Save a checkpoint snapshot
tf_mvm_checkpoint_clear                  : cmd      : , "sv", "cheat"  : Clear the saved checkpoint
tf_mvm_classupgradehelpcount             : 3        : , "a", "norecord", "cl", "matsys" : The number of times the player upgrade help dialog has displayed.
tf_mvm_currency_bonus_ratio_max          : 1.f      : , "sv", "cheat", "matsys" : The highest percentage of wave money players must collect in order to qualify for max bonus - 0.1 to 1.0.  Half the bonus amount will be awarded when reaching min ratio, and half when reaching max.
tf_mvm_currency_bonus_ratio_min          : 1.f      : , "sv", "cheat", "matsys" : The minimum percentage of wave money players must collect in order to qualify for min bonus - 0.1 to 1.0.  Half the bonus amount will be awarded when reaching min ratio, and half when reaching max.
tf_mvm_death_penalty                     : 0        : , "sv", "cheat", "nf", "launcher" : How much currency players lose when dying
tf_mvm_debugstats                        : cmd      : , "sv", "cheat"  : Dumpout MvM Data
tf_mvm_default_sentry_buster_damage_dealt_threshold : 3000     : , "sv", "cheat", "launcher" : 
tf_mvm_default_sentry_buster_kill_threshold : 15       : , "sv", "cheat", "launcher" : 
tf_mvm_disconnect_on_victory             : 0        : , "sv", "rep"    : Enable to Disconnect Players after completing MvM
tf_mvm_endless_bomb_reset                : 5        : , "sv", "cheat", "rep", "norecord", "launcher" : Number of Waves to Complete before bomb reset
tf_mvm_endless_bot_cash                  : 120      : , "sv", "cheat", "rep", "norecord", "launcher" : In Endless, number of credits bots get per wave
tf_mvm_endless_force_on                  : 0        : , "sv", "cheat", "rep", "norecord", "launcher" : Force MvM Endless mode on
tf_mvm_endless_tank_boost                : 0.2      : , "sv", "cheat", "rep", "norecord", "launcher" : In Endless, amount of extra health for the tank per wave
tf_mvm_endless_wait_time                 : 5.0f     : , "sv", "cheat", "rep", "norecord", "launcher" : 
tf_mvm_engineer_teleporter_uber_duration : 5.f      : , "sv", "cheat"  : 
tf_mvm_force_victory                     : cmd      : , "sv", "cheat"  : Force immediate victory.
tf_mvm_jump_to_wave                      : cmd      : , "sv", "cheat"  : Jumps directly to the given Mann Vs Machine wave number
tf_mvm_min_players_to_start              : 3        : , "sv", "nf", "rep" : Minimum number of players connected to start a countdown timer
tf_mvm_miniboss_scale                    : 1.75     : , "sv", "cheat", "rep" : Full body scale for minibosses.
tf_mvm_missioncyclefile                  : tf_mvm_missioncycle.res : , "sv"           : Name of the .res file used to cycle mvm misisons
tf_mvm_nextmission                       : cmd      : , "sv", "cheat"  : Load the next mission
tf_mvm_notice_sapped_squadmates_delay    : 1        : , "sv", "cheat", "launcher" : How long it takes for a squad leader to notice his squadmate was sapped
tf_mvm_popfile                           : cmd      : , "sv"           : Change to a target popfile for MvM
tf_mvm_respec_credit_goal                : 2000     : , "sv", "cheat", "rep" : When tf_mvm_respec_limit is non-zero, the total amount of money the team must collect to earn a respec credit.
tf_mvm_respec_enabled                    : 1        : , "sv", "cheat", "rep" : Allow players to refund credits spent on player and item upgrades.
tf_mvm_respec_limit                      : 0        : , "sv", "cheat", "rep" : The total number of respecs a player can earn.  Default: 0 (no limit).
tf_mvm_skill                             : 3        : , "sv", "cheat", "rep", "norecord" : Sets the challenge level of the invading bot army. 1 = easiest, 3 = normal, 5 = hardest
tf_mvm_tabs_discovered                   : 3        : , "a", "cl"      : Remember how many times players have clicked tabs.
tf_mvm_tank_health                       : cmd      : , "sv", "cheat"  : 
tf_mvm_tank_kill                         : cmd      : , "sv", "cheat"  : 
tf_mvm_victory_disconnect_time           : 180.0    : , "sv", "rep"    : Seconds to wait after MvM victory before kicking players.  (Only used if tf_mvm_disconnect_on_victory is true.)
tf_mvm_victory_reset_time                : 60.0     : , "sv", "rep"    : Seconds to wait after MvM victory before cycling to the next mission.  (Only used if tf_mvm_disconnect_on_victory is false.)

tf_bot_add                               : cmd      : , "sv"           : Add a bot.
tf_bot_always_full_reload                : 0        : , "sv", "cheat"  : 
tf_bot_ammo_search_range                 : 5000     : , "sv", "cheat"  : How far bots will search to find ammo around them
tf_bot_arrow_elevation_rate              : 0.0001   : , "sv", "cheat"  : When firing arrows at far away targets, this is the degree/range slope to raise our aim
tf_bot_auto_vacate                       : 1        : , "sv"           : If nonzero, bots will automatically leave to make room for human players.
tf_bot_ballistic_elevation_rate          : 0.01     : , "sv", "cheat"  : When lobbing grenades at far away targets, this is the degree/range slope to raise our aim
tf_bot_capture_seek_and_destroy_max_duration : 30       : , "sv", "cheat"  : If a capturing bot decides to go hunting, this is the max duration he will hunt for before reconsidering
tf_bot_capture_seek_and_destroy_min_duration : 15       : , "sv", "cheat"  : If a capturing bot decides to go hunting, this is the min duration he will hunt for before reconsidering
tf_bot_cart_push_radius                  : 60       : , "sv", "cheat"  : 
tf_bot_choose_target_interval            : 0.3f     : , "sv", "cheat"  : How often, in seconds, a TFBot can reselect his target
tf_bot_count                             : 22       : , "sv", "nf", "launcher" : 
tf_bot_debug_ammo_scavenging             : 0        : , "sv", "cheat"  : 
tf_bot_debug_destroy_enemy_sentry        : 0        : , "sv", "cheat"  : 
tf_bot_debug_payload_guard_vantage_points :          : , "sv", "cheat"  : 
tf_bot_debug_retreat_to_cover            : 0        : , "sv", "cheat"  : 
tf_bot_debug_seek_and_destroy            : 0        : , "sv", "cheat"  : 
tf_bot_debug_sentry_placement            : 0        : , "sv", "cheat"  : 
tf_bot_debug_sniper                      : 0        : , "sv", "cheat"  : 
tf_bot_debug_spy                         : 0        : , "sv", "cheat"  : 
tf_bot_debug_stuck_log                   : cmd      : , "sv", "cheat"  : Given a server logfile, visually display bot stuck locations.
tf_bot_debug_stuck_log_clear             : cmd      : , "sv", "cheat"  : Clear currently loaded bot stuck data
tf_bot_debug_tags                        : 0        : , "sv", "cheat"  : ent_text will only show tags on bots
tf_bot_defend_owned_point_percent        : 0.5      : , "sv", "cheat"  : Stay on the contested point we own until enemy cap percent falls below this
tf_bot_defense_debug                     : 0        : , "sv", "cheat"  : 
tf_bot_defense_must_defend_time          : 300      : , "sv", "cheat"  : If timer is less than this, bots will stay near point and guard
tf_bot_difficulty                        : 1        : , "sv"           : Defines the skill of bots joining the game.  Values are: 0=easy, 1=normal, 2=hard, 3=expert.
tf_bot_engineer_building_health_multiplier : 2        : , "sv", "cheat"  : 
tf_bot_engineer_exit_near_sentry_range   : 2500     : , "sv", "cheat"  : Maximum travel distance between a bot's Sentry gun and its Teleporter Exit
tf_bot_engineer_max_sentry_travel_distance_to_point : 2500     : , "sv", "cheat"  : Maximum travel distance between a bot's Sentry gun and the currently contested point
tf_bot_engineer_mvm_hint_min_distance_from_bomb : 1300     : , "sv", "cheat"  : 
tf_bot_engineer_mvm_sentry_hint_bomb_backward_range : 3000     : , "sv", "cheat"  : 
tf_bot_engineer_mvm_sentry_hint_bomb_forward_range : 0        : , "sv", "cheat"  : 
tf_bot_engineer_retaliate_range          : 750      : , "sv", "cheat"  : If attacker who destroyed sentry is closer than this, attack. Otherwise, retreat
tf_bot_escort_range                      : 300      : , "sv", "cheat"  : 
tf_bot_fetch_lost_flag_time              : 10       : , "sv", "cheat"  : How long busy TFBots will ignore the dropped flag before they give up what they are doing and go after it
tf_bot_fire_weapon_allowed               : 1        : , "sv", "cheat"  : If zero, TFBots will not pull the trigger of their weapons (but will act like they did)
tf_bot_fire_weapon_min_time              : 1        : , "sv", "cheat"  : 
tf_bot_flag_escort_give_up_range         : 1000     : , "sv", "cheat"  : 
tf_bot_flag_escort_max_count             : 4        : , "sv", "cheat"  : 
tf_bot_flag_escort_range                 : 500      : , "sv", "cheat"  : 
tf_bot_flag_kill_on_touch                : 0        : , "sv", "cheat"  : If nonzero, any bot that picks up the flag dies. For testing.
tf_bot_force_class                       :          : , "sv"           : If set to a class name, all TFBots will respawn as that class
tf_bot_force_jump                        : 0        : , "sv", "cheat"  : Force bots to continuously jump
tf_bot_formation_debug                   : 0        : , "sv", "cheat"  : 
tf_bot_health_critical_ratio             : 0.3      : , "sv", "cheat"  : 
tf_bot_health_ok_ratio                   : 0.8      : , "sv", "cheat"  : 
tf_bot_health_search_far_range           : 2000     : , "sv", "cheat"  : 
tf_bot_health_search_near_range          : 1000     : , "sv", "cheat"  : 
tf_bot_hitscan_range_limit               : 1800     : , "sv", "cheat"  : 
tf_bot_join_after_player                 : 1        : , "sv"           : If nonzero, bots wait until a player joins before entering the game.
tf_bot_keep_class_after_death            : 0        : , "sv"           : 
tf_bot_kick                              : cmd      : , "sv"           : Remove a TFBot by name, or all bots ("all").
tf_bot_kill                              : cmd      : , "sv"           : Kill a TFBot by name, or all bots ("all").
tf_bot_max_grenade_launch_at_sentry_range : 1500     : , "sv", "cheat"  : 
tf_bot_max_point_defend_range            : 1250     : , "sv", "cheat"  : How far (in travel distance) from the point defending bots will take up positions
tf_bot_max_setup_gate_defend_range       : 2000     : , "sv", "cheat"  : How far from the setup gate(s) defending bots can take up positions
tf_bot_max_sticky_launch_at_sentry_range : 1500     : , "sv", "cheat"  : 
tf_bot_max_teleport_entrance_travel      : 1500     : , "sv", "cheat"  : Don't plant teleport entrances farther than this travel distance from our spawn room
tf_bot_max_teleport_exit_travel_to_point : 2500     : , "sv", "cheat"  : In an offensive engineer bot's tele exit is farther from the point than this, destroy it
tf_bot_medic_cover_test_resolution       : 8        : , "sv", "cheat"  : 
tf_bot_medic_debug                       : 0        : , "sv", "cheat"  : 
tf_bot_medic_max_call_response_range     : 1000     : , "sv", "cheat"  : 
tf_bot_medic_max_heal_range              : 600      : , "sv", "cheat"  : 
tf_bot_medic_start_follow_range          : 250      : , "sv", "cheat"  : 
tf_bot_medic_stop_follow_range           : 75       : , "sv", "cheat"  : 
tf_bot_melee_attack_abandon_range        : 500      : , "sv", "cheat"  : If threat is farther away than this, bot will switch back to its primary weapon and attack
tf_bot_melee_only                        : 0        : , "sv"           : If nonzero, TFBots will only use melee weapons
tf_bot_min_setup_gate_defend_range       : 750      : , "sv", "cheat"  : How close from the setup gate(s) defending bots can take up positions. Areas closer than this will be in cover to ambush.
tf_bot_min_setup_gate_sniper_defend_range : 1500     : , "sv", "cheat"  : How far from the setup gate(s) a defending sniper will take up position
tf_bot_min_teleport_travel               : 3000     : , "sv", "cheat"  : Minimum travel distance between teleporter entrance and exit before engineer bot will build one
tf_bot_mvm_show_engineer_hint_region     : cmd      : , "sv", "cheat"  : Show the nav areas MvM engineer bots will consider when selecting sentry and teleporter hints
tf_bot_near_point_travel_distance        : 750      : , "sv", "cheat"  : If within this travel distance to the current point, bot is 'near' it
tf_bot_notice_backstab_chance            : 25       : , "sv", "cheat"  : 
tf_bot_notice_backstab_max_range         : 750      : , "sv", "cheat"  : 
tf_bot_notice_backstab_min_range         : 100      : , "sv", "cheat"  : 
tf_bot_notice_gunfire_range              : 3000     : , "sv"           : 
tf_bot_notice_quiet_gunfire_range        : 500      : , "sv"           : 
tf_bot_npc_archer_arrow_damage           : 75       : , "sv", "cheat"  : 
tf_bot_npc_archer_health                 : 100      : , "sv", "cheat"  : 
tf_bot_npc_archer_shoot_interval         : 2        : , "sv", "cheat"  : 
tf_bot_npc_archer_speed                  : 100      : , "sv", "cheat"  : 
tf_bot_offense_must_push_time            : 120      : , "sv", "cheat"  : If timer is less than this, bots will push hard to cap
tf_bot_offline_practice                  : 0        : , "sv"           : Tells the server that it is in offline practice mode.
tf_bot_path_lookahead_range              : 300      : , "sv"           : 
tf_bot_payload_guard_range               : 1000     : , "sv", "cheat"  : 
tf_bot_prefix_name_with_difficulty       : 0        : , "sv"           : Append the skill level of the bot to the bot's name
tf_bot_pyro_always_reflect               : 0        : , "sv", "cheat"  : Pyro bots will always reflect projectiles fired at them. For tesing/debugging purposes.
tf_bot_pyro_deflect_tolerance            : 0.5      : , "sv", "cheat"  : 
tf_bot_pyro_shove_away_range             : 250      : , "sv", "cheat"  : If a Pyro bot's target is closer than this, compression blast them away
tf_bot_quota                             : 0        : , "sv"           : Determines the total number of tf bots in the game.
tf_bot_quota_mode                        : normal   : , "sv"           : Determines the type of quota. Allowed values: 'normal', 'fill', and 'match'. If 'fill', the server will adjust bots to keep N players in the game, where N is bot_quota. If 'match', the server will maintain a 1:N ratio of humans to bots, where N is bot_quota.
tf_bot_retreat_to_cover_range            : 1000     : , "sv", "cheat"  : 
tf_bot_sniper_aim_error                  : 0.01     : , "sv", "cheat"  : 
tf_bot_sniper_aim_steady_rate            : 10       : , "sv", "cheat"  : 
tf_bot_sniper_allow_opportunistic        : 1        : , "sv"           : If set, Snipers will stop on their way to their preferred lurking spot to snipe at opportunistic targets
tf_bot_sniper_choose_target_interval     : 3.0f     : , "sv", "cheat"  : How often, in seconds, a zoomed-in Sniper can reselect his target
tf_bot_sniper_flee_range                 : 400      : , "sv", "cheat"  : If threat is closer than this, retreat
tf_bot_sniper_goal_entity_move_tolerance : 500      : , "sv", "cheat"  : 
tf_bot_sniper_linger_time                : 5        : , "sv", "cheat"  : How long Sniper will wait around after losing his target before giving up
tf_bot_sniper_melee_range                : 200      : , "sv", "cheat"  : If threat is closer than this, attack with melee weapon
tf_bot_sniper_patience_duration          : 10       : , "sv", "cheat"  : How long a Sniper bot will wait without seeing an enemy before picking a new spot
tf_bot_sniper_personal_space_range       : 1000     : , "sv", "cheat"  : Enemies beyond this range don't worry the Sniper
tf_bot_sniper_spot_epsilon               : 100      : , "sv", "cheat"  : 
tf_bot_sniper_spot_max_count             : 10       : , "sv", "cheat"  : Stop searching for sniper spots when each side has found this many
tf_bot_sniper_spot_min_range             : 1000     : , "sv", "cheat"  : 
tf_bot_sniper_spot_point_tolerance       : 750      : , "sv", "cheat"  : 
tf_bot_sniper_spot_search_count          : 10       : , "sv", "cheat"  : Search this many times per behavior update frame
tf_bot_sniper_target_linger_duration     : 2        : , "sv", "cheat"  : How long a Sniper bot will keep toward at a target it just lost sight of
tf_bot_spy_change_target_range_threshold : 300      : , "sv", "cheat"  : 
tf_bot_spy_knife_range                   : 300      : , "sv", "cheat"  : If threat is closer than this, prefer our knife
tf_bot_squad_escort_range                : 500      : , "sv", "cheat"  : 
tf_bot_sticky_base_range                 : 800      : , "sv", "cheat"  : 
tf_bot_sticky_charge_rate                : 0.01     : , "sv", "cheat"  : Seconds of charge per unit range beyond base
tf_bot_stickybomb_density                : 0.0001   : , "sv", "cheat"  : Number of stickies to place per square inch
tf_bot_suicide_bomb_friendly_fire        : 1        : , "sv", "cheat"  : 
tf_bot_suicide_bomb_range                : 300      : , "sv", "cheat"  : 
tf_bot_suspect_spy_forget_cooldown       : 5        : , "sv", "cheat"  : How long to consider a suspicious spy as suspicious
tf_bot_suspect_spy_touch_interval        : 5        : , "sv", "cheat"  : How many seconds back to look for touches against suspicious spies
tf_bot_taunt_victim_chance               : 20       : , "sv"           : 
tf_bot_teleport_build_surface_normal_limit : 0.99     : , "sv", "cheat"  : If the ground normal Z component is less that this value, Engineer bots won't place their entrance teleporter
tf_bot_wait_in_cover_max_time            : 2        : , "sv", "cheat"  : 
tf_bot_wait_in_cover_min_time            : 1        : , "sv", "cheat"  : 
tf_bot_warp_team_to_me                   : cmd      : , "sv", "cheat"  : 

bot                                      : cmd      : , "sv"           : Add a bot.
bot_changeclass                          : 0        : , "sv"           : Force all bots to change to the specified class.
bot_changeteams                          : cmd      : , "sv", "cheat"  : Make all bots change teams
bot_com_meleerange                       : 80       : , "sv", "cheat"  : Distance to a target that a melee bot wants to be within to attack.
bot_com_viewrange                        : 2000     : , "sv", "cheat"  : Distance within which bots looking for any enemies will find them.
bot_com_wpnrange                         : 400      : , "sv", "cheat"  : Distance to a target that a ranged bot wants to be within to attack.
bot_command                              : cmd      : , "sv", "cheat"  : <bot id> <command string...>.  Sends specified command on behalf of specified bot
bot_crouch                               : 0        : , "sv", "cheat"  : Force all bots to crouch.
bot_debug                                : 0        : , "sv", "cheat"  : Bot debugging.
bot_dontmove                             : 0        : , "sv", "cheat"  : 
bot_drop                                 : cmd      : , "sv", "cheat"  : Force the specified bot to drop his active weapon. Usage: bot_drop <bot name>
bot_forceattack                          : 0        : , "sv"           : When on, all bots fire their guns.
bot_forceattack2                         : 0        : , "sv"           : When firing, use attack2.
bot_forceattack_down                     : 1        : , "sv"           : When firing, don't tap fire, hold it down.
bot_forcefireweapon                      :          : , "sv"           : Force bots with the specified weapon to fire.
bot_hurt                                 : cmd      : , "sv"           : Hurt a bot by team, or all bots ("all").
bot_jump                                 : 0        : , "sv", "cheat"  : Force all bots to repeatedly jump.
bot_kick                                 : cmd      : , "sv", "cheat"  : Remove a bot by name, or an entire team ("red" or "blue"), or all bots ("all").
bot_kill                                 : cmd      : , "sv", "cheat"  : Kills a bot. Usage: bot_kill <bot name>
bot_mimic                                : 0        : , "sv"           : Bot uses usercmd of player by index.
bot_mimic_inverse                        : 0        : , "sv"           : Bot uses usercmd of player by index.
bot_mimic_yaw_offset                     : 180      : , "sv"           : Offsets the bot yaw.
bot_mirror                               : cmd      : , "sv", "cheat"  : Forces the specified bot to be the same class, and use the same items, as you.
bot_moveto                               : cmd      : , "sv", "cheat"  : Force the specified bot to move to the point under your crosshair. Usage: bot_moveto <bot name>
bot_nav_offsetpathinset                  : 20       : , "sv", "cheat"  : Distance into an area that waypoints should be generated when pathfinding through portals.
bot_nav_recomputetime                    : 0.5      : , "sv", "cheat"  : Delay before bots recompute their path to targets that have moved when moving to them.
bot_nav_simplifypaths                    : 1        : , "sv", "cheat"  : If set, bots will skip waypoints if they already see the waypoint post.
bot_nav_turnspeed                        : 5        : , "sv", "cheat"  : Rate at which bots turn to face their targets.
bot_nav_usefeelers                       : 1        : , "sv", "cheat"  : If set, bots will extend feelers to their sides to find & avoid upcoming collisions.
bot_nav_useoffsetpaths                   : 1        : , "sv", "cheat"  : If set, bots will generate waypoints on both sides of portals between waypoints when building paths.
bot_nav_wpdeceldistance                  : 128      : , "sv", "cheat"  : Distance to a waypoint to which a bot starts to decelerate to reach it.
bot_nav_wpdistance                       : 16       : , "sv", "cheat"  : Distance to a waypoint within which a bot considers as having reached it.
bot_randomnames                          : 0        : , "sv", "cheat"  : 
bot_refill                               : cmd      : , "sv", "cheat"  : Refill all bot ammo counts
bot_saveme                               : 0        : , "sv", "cheat"  : 
bot_selectweaponslot                     : -1       : , "sv", "cheat"  : set to weapon slot that bot should switch to.
bot_teleport                             : cmd      : , "sv", "cheat"  : Teleport the specified bot to the specified position & angles.  Format: bot_teleport <bot name> <X> <Y> <Z> <Pitch> <Yaw> <Roll>
bot_whack                                : cmd      : , "sv", "cheat"  : Deliver lethal damage from player to specified bot. Usage: bot_whack <bot name>

ot_nav_wpdistance                       : 16       : , "sv", "cheat"  : Distance to a waypoint within which a bot considers as having reached it.
nav_add_to_selected_set                  : cmd      : , "sv", "cheat"  : Add current area to the selected set.
nav_add_to_selected_set_by_id            : cmd      : , "sv", "cheat"  : Add specified area id to the selected set.
nav_analyze                              : cmd      : , "sv", "cheat"  : Re-analyze the current Navigation Mesh and save it to disk.
nav_analyze_scripted                     : cmd      : , "sv", "cheat", "matsys" : commandline hook to run a nav_analyze and then quit.
nav_area_bgcolor                         : 0 0 0 30 : , "sv", "cheat"  : RGBA color to draw as the background color for nav areas while editing.
nav_area_max_size                        : 50       : , "sv", "cheat"  : Max area size created in nav generation
nav_avoid                                : cmd      : , "sv", "cheat"  : Toggles the 'avoid this area when possible' flag used by the AI system.
nav_begin_area                           : cmd      : , "sv", "cheat"  : Defines a corner of a new Area or Ladder. To complete the Area or Ladder, drag the opposite corner to the desired location and issue a 'nav_end_area' command.
nav_begin_deselecting                    : cmd      : , "sv", "cheat"  : Start continuously removing from the selected set.
nav_begin_drag_deselecting               : cmd      : , "sv", "cheat"  : Start dragging a selection area.
nav_begin_drag_selecting                 : cmd      : , "sv", "cheat"  : Start dragging a selection area.
nav_begin_selecting                      : cmd      : , "sv", "cheat"  : Start continuously adding to the selected set.
nav_begin_shift_xy                       : cmd      : , "sv", "cheat"  : Begin shifting the Selected Set.
nav_build_ladder                         : cmd      : , "sv", "cheat"  : Attempts to build a nav ladder on the climbable surface under the cursor.
nav_check_file_consistency               : cmd      : , "sv", "cheat"  : Scans the maps directory and reports any missing/out-of-date navigation files.
nav_check_floor                          : cmd      : , "sv"           : Updates the blocked/unblocked status for every nav area.
nav_check_stairs                         : cmd      : , "sv", "cheat"  : Update the nav mesh STAIRS attribute
nav_chop_selected                        : cmd      : , "sv", "cheat"  : Chops all selected areas into their component 1x1 areas
nav_clear_attribute                      : cmd      : , "sv", "cheat"  : Remove given nav attribute from all areas in the selected set.
nav_clear_selected_set                   : cmd      : , "sv", "cheat"  : Clear the selected set.
nav_clear_walkable_marks                 : cmd      : , "sv", "cheat"  : Erase any previously placed walkable positions.
nav_compress_id                          : cmd      : , "sv", "cheat"  : Re-orders area and ladder ID's so they are continuous.
nav_connect                              : cmd      : , "sv", "cheat"  : To connect two Areas, mark the first Area, highlight the second Area, then invoke the connect command. Note that this creates a ONE-WAY connection from the first to the second Area. To make a two-way connection, also connect the second area to the first.
nav_coplanar_slope_limit                 : 0.99     : , "sv", "cheat"  : 
nav_coplanar_slope_limit_displacement    : 0.7      : , "sv", "cheat"  : 
nav_corner_adjust_adjacent               : 18       : , "sv", "cheat"  : radius used to raise/lower corners in nearby areas when raising/lowering corners.
nav_corner_lower                         : cmd      : , "sv", "cheat"  : Lower the selected corner of the currently marked Area.
nav_corner_place_on_ground               : cmd      : , "sv", "cheat"  : Places the selected corner of the currently marked Area on the ground.
nav_corner_raise                         : cmd      : , "sv", "cheat"  : Raise the selected corner of the currently marked Area.
nav_corner_select                        : cmd      : , "sv", "cheat"  : Select a corner of the currently marked Area. Use multiple times to access all four corners.
nav_create_area_at_feet                  : 0        : , "sv", "cheat"  : Anchor nav_begin_area Z to editing player's feet
nav_create_place_on_ground               : 0        : , "sv", "cheat"  : If true, nav areas will be placed flush with the ground when created by hand.
nav_crouch                               : cmd      : , "sv", "cheat"  : Toggles the 'must crouch in this area' flag used by the AI system.
nav_debug_blocked                        : 0        : , "sv", "cheat"  : 
nav_delete                               : cmd      : , "sv", "cheat"  : Deletes the currently highlighted Area.
nav_delete_marked                        : cmd      : , "sv", "cheat"  : Deletes the currently marked Area (if any).
nav_disconnect                           : cmd      : , "sv", "cheat"  : To disconnect two Areas, mark an Area, highlight a second Area, then invoke the disconnect command. This will remove all connections between the two Areas.
nav_disconnect_outgoing_oneways          : cmd      : , "sv", "cheat"  : For each area in the selected set, disconnect all outgoing one-way connections.
nav_displacement_test                    : 10000    : , "sv", "cheat"  : Checks for nodes embedded in displacements (useful for in-development maps)
nav_dont_hide                            : cmd      : , "sv", "cheat"  : Toggles the 'area is not suitable for hiding spots' flag used by the AI system.
nav_drag_selection_volume_zmax_offset    : 32       : , "sv", "rep"    : The offset of the nav drag volume top from center
nav_drag_selection_volume_zmin_offset    : 32       : , "sv", "rep"    : The offset of the nav drag volume bottom from center
nav_draw_limit                           : 500      : , "sv", "cheat"  : The maximum number of areas to draw in edit mode
nav_dump_selected_set_positions          : cmd      : , "sv", "cheat"  : Write the (x,y,z) coordinates of the centers of all selected nav areas to a file.
nav_edit                                 : 0        : , "sv", "cheat"  : Set to one to interactively edit the Navigation Mesh. Set to zero to leave edit mode.
nav_end_area                             : cmd      : , "sv", "cheat"  : Defines the second corner of a new Area or Ladder and creates it.
nav_end_deselecting                      : cmd      : , "sv", "cheat"  : Stop continuously removing from the selected set.
nav_end_drag_deselecting                 : cmd      : , "sv", "cheat"  : Stop dragging a selection area.
nav_end_drag_selecting                   : cmd      : , "sv", "cheat"  : Stop dragging a selection area.
nav_end_selecting                        : cmd      : , "sv", "cheat"  : Stop continuously adding to the selected set.
nav_end_shift_xy                         : cmd      : , "sv", "cheat"  : Finish shifting the Selected Set.
nav_flood_select                         : cmd      : , "sv", "cheat"  : Selects the current Area and all Areas connected to it, recursively. To clear a selection, use this command again.
nav_gen_cliffs_approx                    : cmd      : , "sv", "cheat"  : Mark cliff areas, post-processing approximation
nav_generate                             : cmd      : , "sv", "cheat"  : Generate a Navigation Mesh for the current map and save it to disk.
nav_generate_fencetops                   : 1        : , "sv", "cheat"  : Autogenerate nav areas on fence and obstacle tops
nav_generate_fixup_jump_areas            : 1        : , "sv", "cheat"  : Convert obsolete jump areas into 2-way connections
nav_generate_incremental                 : cmd      : , "sv", "cheat"  : Generate a Navigation Mesh for the current map and save it to disk.
nav_generate_incremental_range           : 2000     : , "sv", "cheat"  : 
nav_generate_incremental_tolerance       : 0        : , "sv", "cheat"  : Z tolerance for adding new nav areas.
nav_jump                                 : cmd      : , "sv", "cheat"  : Toggles the 'traverse this area by jumping' flag used by the AI system.
nav_ladder_flip                          : cmd      : , "sv", "cheat"  : Flips the selected ladder's direction.
nav_load                                 : cmd      : , "sv", "cheat"  : Loads the Navigation Mesh for the current map.
nav_lower_drag_volume_max                : cmd      : , "sv", "cheat"  : Lower the top of the drag select volume.
nav_lower_drag_volume_min                : cmd      : , "sv", "cheat"  : Lower the bottom of the drag select volume.
nav_make_sniper_spots                    : cmd      : , "sv", "cheat"  : Chops the marked area into disconnected sub-areas suitable for sniper spots.
nav_mark                                 : cmd      : , "sv", "cheat"  : Marks the Area or Ladder under the cursor for manipulation by subsequent editing commands.
nav_mark_attribute                       : cmd      : , "sv", "cheat"  : Set nav attribute for all areas in the selected set.
nav_mark_unnamed                         : cmd      : , "sv", "cheat"  : Mark an Area with no Place name. Useful for finding stray areas missed when Place Painting.
nav_mark_walkable                        : cmd      : , "sv", "cheat"  : Mark the current location as a walkable position. These positions are used as seed locations when sampling the map to generate a Navigation Mesh.
nav_max_view_distance                    : 6000     : , "sv", "cheat"  : Maximum range for precomputed nav mesh visibility (0 = default 1500 units)
nav_max_vis_delta_list_length            : 64       : , "sv", "cheat"  : 
nav_merge                                : cmd      : , "sv", "cheat"  : To merge two Areas into one, mark the first Area, highlight the second by pointing your cursor at it, and invoke the merge command.
nav_merge_mesh                           : cmd      : , "sv", "cheat"  : Merges a saved selected set into the current mesh.
nav_no_hostages                          : cmd      : , "sv", "cheat"  : Toggles the 'hostages cannot use this area' flag used by the AI system.
nav_no_jump                              : cmd      : , "sv", "cheat"  : Toggles the 'dont jump in this area' flag used by the AI system.
nav_place_floodfill                      : cmd      : , "sv", "cheat"  : Sets the Place of the Area under the cursor to the curent Place, and 'flood-fills' the Place to all adjacent Areas. Flood-filling stops when it hits an Area with the same Place, or a different Place than that of the initial Area.
nav_place_list                           : cmd      : , "sv", "cheat"  : Lists all place names used in the map.
nav_place_pick                           : cmd      : , "sv", "cheat"  : Sets the current Place to the Place of the Area under the cursor.
nav_place_replace                        : cmd      : , "sv", "cheat"  : Replaces all instances of the first place with the second place.
nav_place_set                            : cmd      : , "sv", "cheat"  : Sets the Place of all selected areas to the current Place.
nav_potentially_visible_dot_tolerance    : 0.98     : , "sv", "cheat"  : 
nav_precise                              : cmd      : , "sv", "cheat"  : Toggles the 'dont avoid obstacles' flag used by the AI system.
nav_quicksave                            : 1        : , "sv", "cheat"  : Set to one to skip the time consuming phases of the analysis.  Useful for data collection and testing.
nav_raise_drag_volume_max                : cmd      : , "sv", "cheat"  : Raise the top of the drag select volume.
nav_raise_drag_volume_min                : cmd      : , "sv", "cheat"  : Raise the bottom of the drag select volume.
nav_recall_selected_set                  : cmd      : , "sv", "cheat"  : Re-selects the stored selected set.
nav_remove_from_selected_set             : cmd      : , "sv", "cheat"  : Remove current area from the selected set.
nav_remove_jump_areas                    : cmd      : , "sv", "cheat"  : Removes legacy jump areas, replacing them with connections.
nav_run                                  : cmd      : , "sv", "cheat"  : Toggles the 'traverse this area by running' flag used by the AI system.
nav_save                                 : cmd      : , "sv", "cheat"  : Saves the current Navigation Mesh to disk.
nav_save_selected                        : cmd      : , "sv", "cheat"  : Writes the selected set to disk for merging into another mesh via nav_merge_mesh.
nav_select_blocked_areas                 : cmd      : , "sv", "cheat"  : Adds all blocked areas to the selected set
nav_select_damaging_areas                : cmd      : , "sv", "cheat"  : Adds all damaging areas to the selected set
nav_select_half_space                    : cmd      : , "sv", "cheat"  : Selects any areas that intersect the given half-space.
nav_select_invalid_areas                 : cmd      : , "sv", "cheat"  : Adds all invalid areas to the Selected Set.
nav_select_larger_than                   : cmd      : , "sv", "cheat"  : Select nav areas where both dimensions are larger than the given size.
nav_select_obstructed_areas              : cmd      : , "sv", "cheat"  : Adds all obstructed areas to the selected set
nav_select_orphans                       : cmd      : , "sv", "cheat"  : Adds all orphan areas to the selected set (highlight a valid area first).
nav_select_overlapping                   : cmd      : , "sv"           : Selects nav areas that are overlapping others.
nav_select_radius                        : cmd      : , "sv", "cheat"  : Adds all areas in a radius to the selection set
nav_select_stairs                        : cmd      : , "sv", "cheat"  : Adds all stairway areas to the selected set
nav_selected_set_border_color            : 100 100 0 255 : , "sv", "cheat"  : Color used to draw the selected set borders while editing.
nav_selected_set_color                   : 255 255 200 96 : , "sv", "cheat"  : Color used to draw the selected set background while editing.
nav_set_place_mode                       : cmd      : , "sv", "cheat"  : Sets the editor into or out of Place mode. Place mode allows labelling of Area with Place names.
nav_shift                                : cmd      : , "sv", "cheat"  : Shifts the selected areas by the specified amount
nav_show_approach_points                 : 0        : , "sv", "cheat"  : Show Approach Points in the Navigation Mesh.
nav_show_area_info                       : 0.5      : , "sv", "cheat"  : Duration in seconds to show nav area ID and attributes while editing
nav_show_compass                         : 0        : , "sv", "cheat"  : 
nav_show_continguous                     : 0        : , "sv", "cheat"  : Highlight non-contiguous connections
nav_show_danger                          : 0        : , "sv", "cheat"  : Show current 'danger' levels.
nav_show_dumped_positions                : cmd      : , "sv", "cheat"  : Show the (x,y,z) coordinate positions of the given dump file.
nav_show_func_nav_avoid                  : 0        : , "sv", "cheat"  : Show areas of designer-placed bot avoidance due to func_nav_avoid entities
nav_show_func_nav_prefer                 : 0        : , "sv", "cheat"  : Show areas of designer-placed bot preference due to func_nav_prefer entities
nav_show_func_nav_prerequisite           : 0        : , "sv", "cheat"  : Show areas of designer-placed bot preference due to func_nav_prerequisite entities
nav_show_light_intensity                 : 0        : , "sv", "cheat"  : 
nav_show_node_grid                       : 0        : , "sv", "cheat"  : 
nav_show_node_id                         : 0        : , "sv", "cheat"  : 
nav_show_nodes                           : 0        : , "sv", "cheat"  : 
nav_show_player_counts                   : 0        : , "sv", "cheat"  : Show current player counts in each area.
nav_show_potentially_visible             : 0        : , "sv", "cheat"  : Show areas that are potentially visible from the current nav area
nav_simplify_selected                    : cmd      : , "sv", "cheat"  : Chops all selected areas into their component 1x1 areas and re-merges them together into larger areas
nav_slope_limit                          : 0.7      : , "sv", "cheat"  : The ground unit normal's Z component must be greater than this for nav areas to be generated.
nav_slope_tolerance                      : 0.1      : , "sv", "cheat"  : The ground unit normal's Z component must be this close to the nav area's Z component to be generated.
nav_snap_to_grid                         : 0        : , "sv", "cheat"  : Snap to the nav generation grid when creating new nav areas
nav_solid_props                          : 0        : , "sv", "cheat"  : Make props solid to nav generation/editing
nav_splice                               : cmd      : , "sv", "cheat"  : To splice, mark an area, highlight a second area, then invoke the splice command to create a new, connected area between them.
nav_split                                : cmd      : , "sv", "cheat"  : To split an Area into two, align the split line using your cursor and invoke the split command.
nav_split_place_on_ground                : 0        : , "sv", "cheat"  : If true, nav areas will be placed flush with the ground when split.
nav_stand                                : cmd      : , "sv", "cheat"  : Toggles the 'stand while hiding' flag used by the AI system.
nav_stop                                 : cmd      : , "sv", "cheat"  : Toggles the 'must stop when entering this area' flag used by the AI system.
nav_store_selected_set                   : cmd      : , "sv", "cheat"  : Stores the current selected set for later retrieval.
nav_strip                                : cmd      : , "sv", "cheat"  : Strips all Hiding Spots, Approach Points, and Encounter Spots from the current Area.
nav_subdivide                            : cmd      : , "sv", "cheat"  : Subdivides all selected areas.
nav_test_node                            : 0        : , "sv", "cheat"  : 
nav_test_node_crouch                     : 0        : , "sv", "cheat"  : 
nav_test_node_crouch_dir                 : 4        : , "sv", "cheat"  : 
nav_test_stairs                          : cmd      : , "sv", "cheat"  : Test the selected set for being on stairs
nav_toggle_deselecting                   : cmd      : , "sv", "cheat"  : Start or stop continuously removing from the selected set.
nav_toggle_in_selected_set               : cmd      : , "sv", "cheat"  : Remove current area from the selected set.
nav_toggle_place_mode                    : cmd      : , "sv", "cheat"  : Toggle the editor into and out of Place mode. Place mode allows labelling of Area with Place names.
nav_toggle_place_painting                : cmd      : , "sv", "cheat"  : Toggles Place Painting mode. When Place Painting, pointing at an Area will 'paint' it with the current Place.
nav_toggle_selected_set                  : cmd      : , "sv", "cheat"  : Toggles all areas into/out of the selected set.
nav_toggle_selecting                     : cmd      : , "sv", "cheat"  : Start or stop continuously adding to the selected set.
nav_transient                            : cmd      : , "sv", "cheat"  : Toggles the 'area is transient and may become blocked' flag used by the AI system.
nav_unmark                               : cmd      : , "sv", "cheat"  : Clears the marked Area or Ladder.
nav_update_blocked                       : cmd      : , "sv"           : Updates the blocked/unblocked status for every nav area.
nav_update_lighting                      : cmd      : , "sv", "cheat"  : Recomputes lighting values
nav_update_visibility_on_edit            : 0        : , "sv", "cheat"  : If nonzero editing the mesh will incrementally recompue visibility
nav_use_place                            : cmd      : , "sv", "cheat"  : If used without arguments, all available Places will be listed. If a Place argument is given, the current Place is set.
nav_walk                                 : cmd      : , "sv", "cheat"  : Toggles the 'traverse this area by walking' flag used by the AI system.
nav_warp_to_mark                         : cmd      : , "sv", "cheat"  : Warps the player to the marked area.
nav_world_center                         : cmd      : , "sv", "cheat"  : Centers the nav mesh in the world
*/


class CTFBotSquad : public INextBotEventResponder
{
public:
	CTFBotSquad();
	virtual ~CTFBotSquad();
	
	virtual INextBotEventResponder *FirstContainedResponder() const;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *) const;
	
	struct Iterator
	{
		// 0x00
		// 0x04
	};
	
	void CollectMembers(CUtlVector<CTFBot *> *) const;
	void DisbandAndDeleteSquad();
	Iterator GetFirstMember() const;
	CTFBot *GetLeader() const;
	float GetMaxSquadFormationError() const;
	int GetMemberCount() const;
	Iterator GetNextMember(CTFBotSquad::Iterator const&) const;
	float GetSlowestMemberIdealSpeed(bool) const;
	float GetSlowestMemberSpeed(bool) const;
	bool IsInFormation() const;
	void Join(CTFBot *);
	void Leave(CTFBot *);
	bool ShouldSquadLeaderWaitForFormation() const;
	
private:
	CUtlVector<CHandle<CTFBot>> m_Members; // +0x04
	CHandle<CTFBot> m_hLeader;             // +0x18
	float m_flFormationSize;               // +0x1c
	bool m_bShouldPreserveSquad;           // +0x20
};


class CTFBaseBoss : public NextBotCombatCharacter
{
public:
	// TODO
	
private:
	// TODO
	int m_iBossHealth;   // +0x9a8
	// TODO
	float m_flBossSpeed; // +0x9b4
	// TODO
};


class CTFTankBoss : public CTFBaseBoss
{
public:
	// TODO
	
private:
	// TODO
	EventInfo m_OnKilledOutput;      // +0xa48
	EventInfo m_OnBombDroppedOutput; // +0xc60
	// TODO
};


enum class TFNavAttributeType : int
{
	BLUE_SETUP_GATE             = (1 << 11),
	RED_SETUP_GATE              = (1 << 12),
	
	BLOCKED_AFTER_POINT_CAPTURE = (1 << 13),
	BLOCKED_UNTIL_POINT_CAPTURE = (1 << 14),
	
	BLUE_ONE_WAY_DOOR           = (1 << 15),
	RED_ONE_WAY_DOOR            = (1 << 16),
	
	WITH_SECOND_POINT           = (1 << 17),
	WITH_THIRD_POINT            = (1 << 18),
	WITH_FOURTH_POINT           = (1 << 19),
	WITH_FIFTH_POINT            = (1 << 20),
	
	SNIPER_SPOT                 = (1 << 21),
	SENTRY_SPOT                 = (1 << 22),
	
	NO_SPAWNING                 = (1 << 25),
	RESCUE_CLOSET               = (1 << 26),
	
	DOOR_NEVER_BLOCKS           = (1 << 28),
	DOOR_ALWAYS_BLOCKS          = (1 << 29),
	UNBLOCKABLE                 = (1 << 30),
};


class CTFNavArea : public CNavArea
{
public:
	// TODO
	
private:
	// TODO
	TFNavAttributeType m_nAttributes; // +0x1c4
	// TODO
};


class CTFGameRules : public CTeamplayRoundBasedRules
{
public:
	// TODO
	bool GameModeUsesUpgrades() { return this->m_bPlayingMannVsMachine; }
	bool IsPvEModeActive()      { return this->m_bPlayingMannVsMachine; }
	// TODO
	bool IsPvEModeControlled(CBaseEntity *ent)
	{
		return (ent != nullptr && this->m_bPlayingMannVsMachine &&
			ent->GetTeamNumber() == TF_TEAM_BLU);
	}
	// TODO
	
private:
	// TODO
	bool m_bPlayingMannVsMachine; // +0x96a
	// TODO
};
