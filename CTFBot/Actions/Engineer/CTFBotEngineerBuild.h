/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: engineer: build
 * used in MvM: TODO
 */


class CTFBotEngineerBuild : public Action<CTFBot>
{
public:
	CTFBotEngineerBuild(/* TODO */);
	virtual ~CTFBotEngineerBuild();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual Action<CTFBot> *InitialContainedAction(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnTerritoryLost(CTFBot *actor, int i1) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	// TODO
};
