/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: spy: escape
 * used in MvM: TODO
 */


// sizeof: TODO
class CTFBotSpyEscape : public Action<CTFBot>
{
public:
	CTFBotSpyEscape(/* TODO */);
	virtual ~CTFBotSpyEscape();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	// TODO
};