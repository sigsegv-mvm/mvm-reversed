/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: dead
 * used in MvM: TODO
 */


// sizeof: 0x38
class CTFBotDead : public Action<CTFBot>
{
public:
	CTFBotDead(/* TODO */);
	virtual ~CTFBotDead();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
