/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: scenario monitor
 * used in MvM: TODO
 */


class CTFBotScenarioMonitor : public Action<CTFBot>
{
public:
	CTFBotScenarioMonitor(/* TODO */);
	virtual ~CTFBotScenarioMonitor();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual Action<CTFBot> *InitialContainedAction(CTFBot *actor) override;
	
	virtual UNKNOWN DesiredScenarioAndClassAction(CTFBot *actor);
	
private:
	// TODO
};
