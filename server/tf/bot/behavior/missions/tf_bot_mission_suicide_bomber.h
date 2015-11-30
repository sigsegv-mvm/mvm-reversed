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
	void StartDetonate(CTFBot *actor, bool reached_goal, bool lost_all_health);
	void Detonate(CTFBot *actor);
	
	CHandle<CBaseEntity> m_hTarget; // +0x0034
	Vector m_vecTargetPos;          // +0x0038
	PathFollower m_PathFollower;    // +0x0044
	CountdownTimer m_ctTimer1;      // +0x4818
	CountdownTimer m_ctTimer2;      // +0x4824
	CountdownTimer m_ctTimer3;      // +0x4830, started when detonation sequence begins (duration: 2.0 seconds)
	bool m_bDetonating;             // +0x483c
	bool m_bDetReachedGoal;         // +0x483d
	bool m_bDetLostAllHealth;       // +0x483e
	int m_nConsecutivePathFailures; // +0x4840
	Vector m_vecDetonatePos;        // +0x4844
};


// offset +0x108: m_iHealth
// offset +0x10c: m_lifeState
// offset +0x10d: m_takedamage

// vcall +0x108: IsAlive()
// vcall +0x1ec: NetworkStateChanged_m_iHealth
// vcall +0x1f4: NetworkStateChanged_m_lifeState
