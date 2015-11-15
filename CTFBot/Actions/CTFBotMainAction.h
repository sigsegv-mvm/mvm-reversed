/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: main action
 * used in MvM: TODO
 */


class CTFBotMainAction : public Action<CTFBot>
{
public:
	CTFBotMainAction(/* TODO */);
	virtual ~CTFBotMainAction();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual Action<CTFBot> *InitialContainedAction(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnContact(CTFBot *actor, CBaseEntity *ent, CGameTrace *trace) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnInjured(CTFBot *actor, const CTakeDamageInfo& info) override;
	virtual EventDesiredResult<CTFBot> OnOtherKilled(CTFBot *actor, CBaseCombatCharacter *who, const CTakeDamageInfo& info) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	virtual Vector SelectTargetPoint(const INextBot *nextbot, const CBaseCombatCharacter *them) const override;
	virtual QueryResponse IsPositionAllowed(const INextBot *nextbot, const Vector& v1) const override;
	virtual const CKnownEntity *SelectMoreDangerousThreat(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const override;
	
	UNKNOWN Dodge(CTFBot *actor);
	UNKNOWN FireWeaponAtEnemy(CTFBot *actor);
	UNKNOWN GetHealerOfThreat(const CKnownEntity *known) const;
	UNKNOWN IsImmediateThreat(const CBaseCombatCharacter *who, const CKnownEntity *known) const;
	UNKNOWN SelectCloserThreat(CTFBot *actor, const CKnownEntity *known1, const CKnownEntity *known2) const;
	UNKNOWN SelectMoreDangerousThreatInternal(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const;
	
private:
	// TODO
};
