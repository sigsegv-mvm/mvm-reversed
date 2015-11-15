/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: destroy enemy sentry
 * used in MvM: TODO
 */


// sizeof: 0x482c
class CTFBotDestroyEnemySentry : public Action<CTFBot>
{
public:
	CTFBotDestroyEnemySentry(/* TODO */);
	virtual ~CTFBotDestroyEnemySentry();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
	void ComputeCornerAttackSpot(CTFBot *actor);
	void ComputeSafeAttackSpot(CTFBot *actor);
	bool IsPossible(CTFBot *actor);
	
private:
	// TODO
};
