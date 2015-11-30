/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/player_vs_environment/tf_tank_boss.cpp
 */


ConCommand tf_mvm_tank_kill("tf_mvm_tank_kill", CMD_TankKill,
	"", FCVAR_CHEAT | FCVAR_GAMEDLL);
ConCommand tf_mvm_tank_health("tf_mvm_tank_health", CMD_TankHealth,
	"", FCVAR_CHEAT | FCVAR_GAMEDLL);


// TODO: server class init for CTFTankBoss ("tank_boss")
// TODO: server class init for CTFTankDestruction ("tank_destruction")



