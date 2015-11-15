/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: scenario ctf: deliver flag
 * used in MvM: TODO
 */


// sizeof: 0x4834
class CTFBotDeliverFlag : public Action<CTFBot>
{
public:
	CTFBotDeliverFlag(/* TODO */);
	virtual ~CTFBotDeliverFlag();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
	bool UpgradeOverTime(CTFBot *actor);
	
private:
	// TODO
};
