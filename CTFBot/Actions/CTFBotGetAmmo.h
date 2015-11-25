/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: get ammo
 * used in MvM: TODO
 */


// sizeof: 0x4810
class CTFBotGetAmmo : public Action<CTFBot>
{
public:
	CTFBotGetAmmo();
	virtual ~CTFBotGetAmmo();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual EventDesiredResult<CTFBot> OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace) override;
	
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	
	static bool IsPossible(CTFBot *actor);
	
private:
	// TODO
};
