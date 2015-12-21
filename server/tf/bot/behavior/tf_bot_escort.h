/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_escort.h
 * used in MvM: TODO
 */


// sizeof: TODO (>=0x4824)
class CTFBotEscort : public Action<CTFBot>
{
public:
	CTFBotEscort(CBaseEntity *ent);
	virtual ~CTFBotEscort();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	virtual EventDesiredResult<CTFBot> OnCommandApproach(CTFBot *actor, const Vector& v1, float f1) override;
	
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	
	CBaseEntity *GetWho() const;
	void SetWho(CBaseEntity *who);
	
private:
	// 0034 CHandle<T>
	// 0038 PathFollower
	// 480c CountdownTimer
	// 4818 CountdownTimer
	// ...?
};
