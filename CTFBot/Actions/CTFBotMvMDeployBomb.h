/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: mvm deploy bomb
 * used in MvM: TODO
 */


// sizeof: 0x4c
class CTFBotMvMDeployBomb : public Action<CTFBot>
{
public:
	CTFBotMvMDeployBomb(/* TODO */);
	virtual ~CTFBotMvMDeployBomb();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace) override;
	
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	// TODO
};
