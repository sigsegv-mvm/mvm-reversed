/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_destroy_enemy_sentry.h
 * used in MvM: TODO
 */


// sizeof: 0x482c
class CTFBotDestroyEnemySentry : public Action<CTFBot>
{
public:
	CTFBotDestroyEnemySentry(/* TODO */);
	virtual ~CTFBotDestroyEnemySentry();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
	static bool IsPossible(CTFBot *actor);
	
private:
	void ComputeCornerAttackSpot(CTFBot *actor);
	void ComputeSafeAttackSpot(CTFBot *actor);
	
	// TODO
};


// sizeof: 0x4818
class CTFBotUberAttackEnemySentry : public Action<CTFBot>
{
public:
	CTFBotUberAttackEnemySentry(CObjectSentrygun *sentry);
	virtual ~CTFBotUberAttackEnemySentry();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	// TODO
};


UNKNOWN FindGrenadeAim(CTFBot *bot, CBaseEntity *ent, float *f1, float *f2);
UNKNOWN FindStickybombAim(CTFBot *bot, CBaseEntity *ent, float *f1, float *f2, float *f3);


// TODO: FindSafeSentryApproachAreaScan
