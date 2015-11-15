/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: training: goto action point
 * used in MvM: TODO
 */


class CTFGotoActionPoint : public Action<CTFBot>
{
public:
	CTFGotoActionPoint(/* TODO */);
	virtual ~CTFGotoActionPoint();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
