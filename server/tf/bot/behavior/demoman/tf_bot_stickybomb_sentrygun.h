/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/demoman/tf_bot_stickybomb_sentrygun.h
 * used in MvM: TODO
 */


// sizeof: 0x7c
class CTFBotStickybombSentrygun : public Action<CTFBot>
{
public:
	CTFBotStickybombSentrygun(CObjectSentrygun *sentry);
	virtual ~CTFBotStickybombSentrygun();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual ActionResult<CTFBot> OnSuspend(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnInjured(CTFBot *actor, const CTakeDamageInfo& info) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	bool IsAimOnTarget(CTFBot *actor, float f1, float f2, float f3);
	
	// TODO
};
