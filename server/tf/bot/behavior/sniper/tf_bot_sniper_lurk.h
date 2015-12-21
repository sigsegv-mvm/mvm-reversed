/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/sniper/tf_bot_sniper_lurk.h
 * used in MvM: TODO
 */


// sizeof: 0x485c
class CTFBotSniperLurk : public Action<CTFBot>
{
public:
	CTFBotSniperLurk(/* TODO */);
	virtual ~CTFBotSniperLurk();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> OnSuspend(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	virtual const CKnownEntity *SelectMoreDangerousThreat(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const override;
	
private:
	UNKNOWN FindHint(CTFBot *actor);
	UNKNOWN FindNewHome(CTFBot *actor);
	
	// 0034 CountdownTimer
	// 0040 CountdownTimer
	// 004c PathFollower
	// 4820 
	// 4824 
	// 4828 
	// 482c 
	// 4830 
	// 4834 CountdownTimer
	// 4840 
	// 4844 
	// 4848 
	// 484c 
	// 4850 
	// 4854 
	// 4858 CHandle<T>
};

