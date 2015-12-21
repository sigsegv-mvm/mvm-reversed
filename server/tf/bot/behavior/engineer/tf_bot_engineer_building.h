/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_building.h
 * used in MvM: TODO
 */


// sizeof: 0x4870
class CTFBotEngineerBuilding : public Action<CTFBot>
{
public:
	CTFBotEngineerBuilding();
	CTFBotEngineerBuilding(CTFBotHintSentrygun *hint);
	virtual ~CTFBotEngineerBuilding();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnTerritoryCaptured(CTFBot *actor, int i1) override;
	virtual EventDesiredResult<CTFBot> OnTerritoryLost(CTFBot *actor, int i1) override;
	
private:
	bool CheckIfSentryIsOutOfPosition(CTFBot *actor) const;
	bool IsMetalSourceNearby(CTFBot *actor) const;
	void UpgradeAndMaintainBuildings(CTFBot *actor);
	
	// 0034 CountdownTimer
	// 0040 CountdownTimer
	// 004c CountdownTimer
	// 0058 CountdownTimer
	// 0064 
	// 0068 CountdownTimer
	// 0074 CountdownTimer
	PathFollower m_PathFollower; // +0x0080
	// 4854 
	// 4858 
	// 485c 
	// 4860 CountdownTimer
	// 486c 
};
