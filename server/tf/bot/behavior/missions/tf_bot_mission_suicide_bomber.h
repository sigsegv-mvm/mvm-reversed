/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/missions/tf_bot_mission_suicide_bomber.h
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
	// 0x0034 CHandle<CBaseEntity>
	// 0x0038 Vector
	// 0x0044 PathFollower
	// 0x4818 CountdownTimer
	// 0x4824 CountdownTimer
	// 0x4830 CountdownTimer
	// 0x483c byte
	// 0x483d byte
	// 0x483e byte
	// 0x483f?
	// 0x4840 ???
	// 0x4844 ???
	// 0x4848 ???
	// 0x484c ???
};
