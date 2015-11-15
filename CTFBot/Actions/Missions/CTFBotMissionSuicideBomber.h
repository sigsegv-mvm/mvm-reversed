/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: missions: suicide bomber
 * used in MvM: TODO
 */


// sizeof: 0x4850
class CTFBotMissionSuicideBomber : public Action<CTFBot>
{
public:
	CTFBotMissionSuicideBomber();
	virtual ~CTFBotMissionSuicideBomber();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnKilled(CTFBot *actor, const CTakeDamageInfo& info) override;
	
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	// TODO
};
