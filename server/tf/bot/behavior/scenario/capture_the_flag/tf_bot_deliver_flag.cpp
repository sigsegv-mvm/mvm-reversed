/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/scenario/capture_the_flag/tf_bot_deliver_flag.cpp
 * used in MvM: TODO
 */


ConVar tf_mvm_bot_allow_flag_carrier_to_fight("tf_mvm_bot_allow_flag_carrier_to_fight", "1", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_1st_upgrade("tf_mvm_bot_flag_carrier_interval_to_1st_upgrade", "5", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_2nd_upgrade("tf_mvm_bot_flag_carrier_interval_to_2nd_upgrade", "15", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_interval_to_3rd_upgrade("tf_mvm_bot_flag_carrier_interval_to_3rd_upgrade", "15", FCVAR_CHEAT);
ConVar tf_mvm_bot_flag_carrier_health_regen("tf_mvm_bot_flag_carrier_health_regen", "45.0f", FCVAR_CHEAT);


// NOTE: CTFBotDeliverFlag::Update
// calls CTFBotPathCost::CTFBotPathCost
// which is only in certain versions (e.g. ServerLinux 20140619a)
