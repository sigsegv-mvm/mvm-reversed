/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: spy: infiltrate
 * used in MvM: TODO
 */


// sizeof: 0x4834
class CTFBotInfiltrate : public Action<CTFBot>
{
public:
	CTFBotInfiltrate(/* TODO */);
	virtual ~CTFBotInfiltrate();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual ActionResult<CTFBot> OnSuspend(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	virtual EventDesiredResult<CTFBot> OnTerritoryCaptured(CTFBot *actor, int i1) override;
	virtual EventDesiredResult<CTFBot> OnTerritoryLost(CTFBot *actor, int i1) override;
	
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	UNKNOWN FindHidingSpot(CTFBot *actor);
	
	// TODO
};
