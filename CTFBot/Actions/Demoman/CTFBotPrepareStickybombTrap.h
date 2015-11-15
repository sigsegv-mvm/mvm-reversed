/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: demoman: prepare stickybomb trap
 * used in MvM: TODO
 */


class CTFBotPrepareStickybombTrap : public Action<CTFBot>
{
public:
	CTFBotPrepareStickybombTrap();
	virtual ~CTFBotPrepareStickybombTrap();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual ActionResult<CTFBot> OnSuspend(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnInjured(CTFBot *actor, const CTakeDamageInfo& info) override;
	
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
	UNKNOWN InitBombTargetAreas(CTFBot *actor);
	UNKNOWN IsPossible(CTFBot *actor);
	
private:
	// TODO
};
