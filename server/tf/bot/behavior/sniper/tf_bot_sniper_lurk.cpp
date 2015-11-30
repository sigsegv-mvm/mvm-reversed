/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/sniper/tf_bot_sniper_lurk.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_sniper_patience_duration("tf_bot_sniper_patience_duration", "10", FCVAR_CHEAT,
	"How long a Sniper bot will wait without seeing an enemy before picking a new spot");
ConVar tf_bot_sniper_target_linger_duration("tf_bot_sniper_target_linger_duration", "2", FCVAR_CHEAT,
	"How long a Sniper bot will keep toward at a target it just lost sight of");
ConVar tf_bot_sniper_allow_opportunistic("tf_bot_sniper_allow_opportunistic", "1", FCVAR_NONE,
	"If set, Snipers will stop on their way to their preferred lurking spot to snipe at opportunistic targets");
ConVar tf_mvm_bot_sniper_target_by_dps("tf_mvm_bot_sniper_target_by_dps", "1", FCVAR_CHEAT | FCVAR_DEVELOPMENTONLY,
	"If set, Snipers in MvM mode target the victim that has the highest DPS");



