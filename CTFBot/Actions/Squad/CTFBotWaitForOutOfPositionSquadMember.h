/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: squad: wait for out of position squad member
 * used in MvM: TODO
 */


// sizeof: 0x40
class CTFBotWaitForOutOfPositionSquadMember : public Action<CTFBot>
{
public:
	CTFBotWaitForOutOfPositionSquadMember(/* TODO */);
	virtual ~CTFBotWaitForOutOfPositionSquadMember();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
