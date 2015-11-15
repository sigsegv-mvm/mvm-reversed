/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: nav entities: move to
 * used in MvM: TODO
 */


class CTFBotNavEntMoveTo : public Action<CTFBot>
{
public:
	CTFBotNavEntMoveTo(const CFuncNavPrerequisite *prereq);
	virtual ~CTFBotNavEntMoveTo();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
