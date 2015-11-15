/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: engineer: build dispenser
 * used in MvM: TODO
 */


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
