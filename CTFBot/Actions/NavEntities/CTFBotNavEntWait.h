/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: nav entities: wait
 * used in MvM: TODO
 */


// sizeof: 0x44
class CTFBotNavEntWait : public Action<CTFBot>
{
public:
	CTFBotNavEntWait(const CFuncNavPrerequisite *prereq);
	virtual ~CTFBotNavEntWait();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
