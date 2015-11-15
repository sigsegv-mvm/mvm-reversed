/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: tactical monitor
 * used in MvM: TODO
 */


class CTFBotTacticalMonitor : public Action<CTFBot>
{
public:
	CTFBotTacticalMonitor(/* TODO */);
	virtual ~CTFBotTacticalMonitor();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual Action<CTFBot> *InitialContainedAction(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnOtherKilled(CTFBot *actor, CBaseCombatCharacter *who, const CTakeDamageInfo& info) override;
	
	virtual EventDesiredResult<CTFBot> OnNavAreaChanged(CTFBot *actor, CNavArea *area1, CNavArea *area2) override;
	
	virtual EventDesiredResult<CTFBot> OnCommandString(CTFBot *actor, const char *cmd) override;
	
	UNKNOWN AvoidBumpingEnemies(CTFBot *actor);
	UNKNOWN FindNearbyTeleporter(CTFBot *actor);
	UNKNOWN MonitorArmedStickybombs(CTFBot *actor);
	UNKNOWN ShouldOpportunisticallyTelport(CTFBot *actor) const;
	
private:
	// TODO
};
