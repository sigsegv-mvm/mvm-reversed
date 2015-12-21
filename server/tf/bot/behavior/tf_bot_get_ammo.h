/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_get_ammo.h
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
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	
	virtual EventDesiredResult<CTFBot> OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace) override;
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	
	static bool IsPossible(CTFBot *actor);
	
private:
	// 0034 PathFollower
	// 4808 CHandle<T>
	// 480c byte 0
};


class CAmmoFilter : public INextBotFilter
{
public:
	CAmmoFilter(CBaseEntity *actor);
	
	virtual bool IsSelected(const CBaseEntity *ent) const override;
	
private:
	CBaseEntity *m_Actor;
};


// TODO: CClosestTFPlayer
