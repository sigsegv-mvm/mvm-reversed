/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: engineer: building
 * used in MvM: TODO
 */


// sizeof: 0x4870
class CTFBotEngineerBuilding : public Action<CTFBot>
{
public:
	CTFBotEngineerBuilding(CTFBotHintSentrygun *hint);
	virtual ~CTFBotEngineerBuilding();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnTerritoryCaptured(CTFBot *actor, int i1) override;
	virtual EventDesiredResult<CTFBot> OnTerritoryLost(CTFBot *actor, int i1) override;
	
	bool CheckIfSentryIsOutOfPosition(CTFBot *actor) const;
	bool IsMetalSourceNearby(CTFBot *actor) const;
	void UpgradeAndMaintainBuildings(CTFBot *actor);
	
private:
	// TODO
};
