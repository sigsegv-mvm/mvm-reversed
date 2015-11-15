/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: scenario ctf: escort flag carrier
 * used in MvM: TODO
 */


// sizeof: 0x904c
class CTFBotEscortFlagCarrier : public Action<CTFBot>
{
public:
	CTFBotEscortFlagCarrier(/* TODO */);
	virtual ~CTFBotEscortFlagCarrier();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
