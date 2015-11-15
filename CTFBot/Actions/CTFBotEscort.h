/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: escort
 * used in MvM: TODO
 */


class CTFBotEscort : public Action<CTFBot>
{
public:
	CTFBotEscort(CBaseEntity *ent);
	virtual ~CTFBotEscort();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnCommandApproach(CTFBot *actor, const Vector& v1, float f1) override;
	
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	
	UNKNOWN GetWho() const;
	UNKNOWN SetWho(CBaseEntity *who);
	
private:
	// TODO
};
