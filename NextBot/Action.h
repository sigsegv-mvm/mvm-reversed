/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: actions
 */


template<class T>
struct ActionResult
{
	// enum: transition type
	Action<T> *action;
	const char *reason;
};


template<class T>
class Action : public INextBotEventResponder, public IContextualQuery
{
public:
	Action(/* TODO ??? */);
	virtual ~Action();
	
	/* INextBotEventResponder overrides */
	virtual INextBotEventResponder *FirstContainedResponder() const override final;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *prev) const override final;
	
	virtual void OnLeaveGround(CBaseEntity *ent) override final;
	virtual void OnLandOnGround(CBaseEntity *ent) override final;
	
	virtual void OnContact(CBaseEntity *ent, CGameTrace *trace) override final;
	
	virtual void OnMoveToSuccess(const Path *path) override final;
	virtual void OnMoveToFailure(const Path *path, MoveToFailureType fail) override final;
	
	virtual void OnStuck() override final;
	virtual void OnUnStuck() override final;
	
	virtual void OnPostureChanged() override final;
	virtual void OnAnimationActivityComplete(int i1) override final;
	virtual void OnAnimationActivityInterrupted(int i1) override final;
	virtual void OnAnimationEvent(animevent_t *a1) override final;
	
	virtual void OnIgnite() override final;
	virtual void OnInjured(const CTakeDamageInfo& info) override final;
	virtual void OnKilled(const CTakeDamageInfo& info) override final;
	virtual void OnOtherKilled(CBaseCombatCharacter *who, const CTakeDamageInfo& info) override final;
	
	virtual void OnSight(CBaseEntity *ent) override final;
	virtual void OnLostSight(CBaseEntity *ent) override final;
	
	virtual void OnSound(CBaseEntity *ent, const Vector& v1, KeyValues *kv) override final;
	virtual void OnSpokeConcept(CBaseCombatCharacter *who, const char *s1, AI_Response *response) override final;
	virtual void OnWeaponFired(CBaseCombatCharacter *who, CBaseCombatWeapon *weapon) override final;
	
	virtual void OnNavAreaChanged(CNavArea *area1, CNavArea *area2) override final;
	virtual void OnModelChanged() override final;
	virtual void OnPickUp(CBaseEntity *ent, CBaseCombatCharacter *who) override final;
	virtual void OnDrop(CBaseEntity *ent) override final;
	virtual void OnActorEmoted(CBaseCombatCharacter *who, int i1) override final;
	
	virtual void OnCommandAttack(CBaseEntity *ent) override final;
	virtual void OnCommandApproach(const Vector& v1, float f1) override final;
	virtual void OnCommandApproach(CBaseEntity *ent) override final;
	virtual void OnCommandRetreat(CBaseEntity *ent, float f1) override final;
	virtual void OnCommandPause(float f1) override final;
	virtual void OnCommandResume() override final;
	virtual void OnCommandString(const char *cmd) override final;
	
	virtual void OnShoved(CBaseEntity *ent) override final;
	virtual void OnBlinded(CBaseEntity *ent) override final;
	
	virtual void OnTerritoryContested(int i1) override final;
	virtual void OnTerritoryCaptured(int i1) override final;
	virtual void OnTerritoryLost(int i1) override final;
	
	virtual void OnWin() override final;
	virtual void OnLose() override final;
	
	
	virtual const char *GetName() const = 0;
	virtual bool IsNamed(const char *name) const;
	virtual char *GetFullName() const;
	
	virtual ActionResult<T> OnStart(T *actor, Action<T> *);
	virtual ActionResult<T> Update(T *actor, float f1);
	virtual ActionResult<T> OnEnd(T *actor, Action<T> *);
	
	virtual ActionResult<T> OnSuspend(T *actor, Action<T> *);
	virtual ActionResult<T> OnResume(T *actor, Action<T> *);
	
	virtual ActionResult<T> InitialContainedAction(T *actor);
	
	virtual ActionResult<T> OnLeaveGround(T *actor, CBaseEntity *ent);
	virtual ActionResult<T> OnLandOnGround(T *actor, CBaseEntity *ent);
	
	virtual ActionResult<T> OnContact(T *actor, CBaseEntity *ent, CGameTrace *trace);
	
	virtual ActionResult<T> OnMoveToSuccess(T *actor, const Path *path);
	virtual ActionResult<T> OnMoveToFailure(T *actor, const Path *path, MoveToFailureType fail);
	
	virtual ActionResult<T> OnStuck(T *actor);
	virtual ActionResult<T> OnUnStuck(T *actor);
	
	virtual ActionResult<T> OnPostureChanged(T *actor);
	virtual ActionResult<T> OnAnimationActivityComplete(T *actor, int i1);
	virtual ActionResult<T> OnAnimationActivityInterrupted(T *actor, int i1);
	virtual ActionResult<T> OnAnimationEvent(T *actor, animevent_t *a1);
	
	virtual ActionResult<T> OnIgnite(T *actor);
	virtual ActionResult<T> OnInjured(T *actor, const CTakeDamageInfo& info);
	virtual ActionResult<T> OnKilled(T *actor, const CTakeDamageInfo& info);
	virtual ActionResult<T> OnOtherKilled(T *actor, CBaseCombatCharacter *who, const CTakeDamageInfo& info);
	
	virtual ActionResult<T> OnSight(T *actor, CBaseEntity *ent);
	virtual ActionResult<T> OnLostSight(T *actor, CBaseEntity *ent);
	
	virtual ActionResult<T> OnSound(T *actor, CBaseEntity *ent, const Vector& v1, KeyValues *kv);
	virtual ActionResult<T> OnSpokeConcept(T *actor, CBaseCombatCharacter *who, const char *s1, AI_Response *response);
	virtual ActionResult<T> OnWeaponFired(T *actor, CBaseCombatCharacter *who, CBaseCombatWeapon *weapon);
	
	virtual ActionResult<T> OnNavAreaChanged(T *actor, CNavArea *area1, CNavArea *area2);
	virtual ActionResult<T> OnModelChanged(T *actor);
	virtual ActionResult<T> OnPickUp(T *actor, CBaseEntity *ent, CBaseCombatCharacter *who);
	virtual ActionResult<T> OnDrop(T *actor, CBaseEntity *ent);
	virtual ActionResult<T> OnActorEmoted(T *actor, CBaseCombatCharacter *who, int i1);
	
	virtual ActionResult<T> OnCommandAttack(T *actor, CBaseEntity *ent);
	virtual ActionResult<T> OnCommandApproach(T *actor, const Vector& v1, float f1);
	virtual ActionResult<T> OnCommandApproach(T *actor, CBaseEntity *ent);
	virtual ActionResult<T> OnCommandRetreat(T *actor, CBaseEntity *ent, float f1);
	virtual ActionResult<T> OnCommandPause(T *actor, float f1);
	virtual ActionResult<T> OnCommandResume(T *actor);
	virtual ActionResult<T> OnCommandString(T *actor, const char *cmd);
	
	virtual ActionResult<T> OnShoved(T *actor, CBaseEntity *ent);
	virtual ActionResult<T> OnBlinded(T *actor, CBaseEntity *ent);
	
	virtual ActionResult<T> OnTerritoryContested(T *actor, int i1);
	virtual ActionResult<T> OnTerritoryCaptured(T *actor, int i1);
	virtual ActionResult<T> OnTerritoryLost(T *actor, int i1);
	
	virtual ActionResult<T> OnWin(T *actor);
	virtual ActionResult<T> OnLose(T *actor);
	
	virtual bool IsAbleToBlockMovementOf(const INextBot *nextbot) const;
	
	
	Action<T> *ApplyResult(T *actor, Behavior<T> *behavior, ActionResult<T> result);
	
	Action<T> *InvokeOnStart(T *actor, Behavior<T> *behavior, Action<T> *action1, Action<T> *action2);
	ActionResult<T> InvokeUpdate(T *actor, Behavior<T> *behavior, float f1);
	void InvokeOnEnd(T *actor, Behavior<T> *behavior, Action<T> *action);
	
	ActionResult<T> InvokeOnResume(T *actor, Behavior<T> *behavior, Action<T> *action);
	Action<T> *InvokeOnSuspend(T *actor, Behavior<T> *behavior, Action<T> *action);
	
	char *BuildDecoratedName(char *s1, const Action<T> *action) const;
	char *DebugString() const;
	void PrintStateToConsole() const;
	
	
	// data starts at +0x08
protected:
	// +08
	// +0c
	// +10
	// +14
	// +18
	// +1c
	// +20
	// +24
	// +28
	// +2c
	// +30
	// +34
	// +38
	// +3c
	// +40
};

template<> class Action<CBotNPCArcher>;
template<> class Action<CBotNPCDecoy>;
template<> class Action<CEyeballBoss>;
template<> class Action<CGhost>;
template<> class Action<CHeadlessHatman>;
template<> class Action<CMerasmus>;
template<> class Action<CSimpleBot>;
template<> class Action<CTFBot>;
template<> class Action<CTFRobotDestruction_Robot>;
template<> class Action<CZombie>;
