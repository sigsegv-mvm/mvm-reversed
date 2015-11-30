/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/scenario/capture_the_flag/tf_bot_fetch_flag.h
 * used in MvM: TODO
 */


// sizeof: 0x4814
class CTFBotFetchFlag : public Action<CTFBot>
{
public:
	CTFBotFetchFlag(bool b1);
	virtual ~CTFBotFetchFlag();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	
private:
	// TODO
};
