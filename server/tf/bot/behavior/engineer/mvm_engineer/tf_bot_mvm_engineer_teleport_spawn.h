/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_teleport_spawn.h
 * used in MvM: TODO
 */


// sizeof: 0x48
class CTFBotMvMEngineerTeleportSpawn : public Action<CTFBot>
{
public:
	CTFBotMvMEngineerTeleportSpawn(CBaseTFBotHintEntity *hint, bool b1);
	virtual ~CTFBotMvMEngineerTeleportSpawn();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
