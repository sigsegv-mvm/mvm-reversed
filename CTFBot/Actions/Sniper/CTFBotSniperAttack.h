/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: sniper: attack
 * used in MvM: TODO
 */


// sizeof: TODO
class CTFBotSniperAttack : public Action<CTFBot>
{
public:
	CTFBotSniperAttack(/* TODO */);
	virtual ~CTFBotSniperAttack();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual ActionResult<CTFBot> OnSuspend(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual Vector SelectTargetPoint(const INextBot *nextbot, const CBaseCombatCharacter *them) const override;
	virtual const CKnownEntity *SelectMoreDangerousThreat(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const override;
	
	static bool IsPossible(CTFBot *actor);
	
private:
	bool IsImmediateThreat(const CBaseCombatCharacter *who, const CKnownEntity *known) const;
	
	// TODO
};
