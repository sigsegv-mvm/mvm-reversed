/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_build_dispenser.h
 * used in MvM: TODO
 */


// sizeof: 0x4830
class CTFBotEngineerBuildDispenser : public Action<CTFBot>
{
public:
	CTFBotEngineerBuildDispenser(/* TODO */);
	virtual ~CTFBotEngineerBuildDispenser();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
private:
	// TODO
};