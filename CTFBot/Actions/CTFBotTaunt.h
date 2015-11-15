/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: taunt
 * used in MvM: TODO
 */


// sizeof: 0x50
class CTFBotTaunt : public Action<CTFBot>
{
public:
	CTFBotTaunt(/* TODO */);
	virtual ~CTFBotTaunt();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
