/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: engineer mvm: idle
 * used in MvM: TODO
 */


// sizeof: 0x4868
class CTFBotMvMEngineerIdle : public Action<CTFBot>
{
public:
	CTFBotMvMEngineerIdle(/* TODO */);
	virtual ~CTFBotMvMEngineerIdle();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
	bool ShouldAdvanceNestSpot(CTFBot *actor);
	void TakeOverStaleNest(CBaseTFBotHintEntity *hint, CTFBot *actor);
	void TryToDetonateStaleNest();
	
private:
	// TODO
};
