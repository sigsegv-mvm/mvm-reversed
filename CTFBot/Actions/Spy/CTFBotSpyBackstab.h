/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: spy: backstab
 * used in MvM: TODO
 */


class CTFBotSpyBackstab : public Action<CTFBot>
{
public:
	CTFBotSpyBackstab(/* TODO */);
	virtual ~CTFBotSpyBackstab();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	// TODO
};
