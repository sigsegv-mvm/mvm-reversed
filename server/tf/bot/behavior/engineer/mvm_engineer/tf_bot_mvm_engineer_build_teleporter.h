/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_build_teleporter.h
 * used in MvM: TODO
 */


// sizeof: 0x4824
class CTFBotMvMEngineerBuildTeleportExit : public Action<CTFBot>
{
public:
	CTFBotMvMEngineerBuildTeleportExit(CTFBotHintTeleportExit *hint);
	virtual ~CTFBotMvMEngineerBuildTeleportExit();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
