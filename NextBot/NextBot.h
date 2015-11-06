/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: core stuff
 */


// TODO: enum MoveToFailureType


class INextBotEventResponder
{
public:
	virtual ~INextBotEventResponder();
	
	virtual INextBotEventResponder *FirstContainedResponder() const;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *prev) const;
	
	virtual ??? OnLeaveGround(CBaseEntity *ent);
	virtual ??? OnLandOnGround(CBaseEntity *ent);
	
	virtual ??? OnContact(CBaseEntity *ent, CGameTrace *trace);
	
	virtual ??? OnMoveToSuccess(const Path *path);
	virtual ??? OnMoveToFailure(const Path *path, MoveToFailureType fail);
	
	virtual ??? OnStuck();
	virtual ??? OnUnStuck();
	
	virtual ??? OnPostureChanged();
	virtual ??? OnAnimationActivityComplete(int i1);
	virtual ??? OnAnimationActivityInterrupted(int i1);
	virtual ??? OnAnimationEvent(animevent_t *a1);
	
	virtual ??? OnIgnite();
	virtual ??? OnInjured(const CTakeDamageInfo& info);
	virtual ??? OnKilled(const CTakeDamageInfo& info);
	virtual ??? OnOtherKilled(CBaseCombatCharacter *who, const CTakeDamageInfo& info);
	
	virtual ??? OnSight(CBaseEntity *ent);
	virtual ??? OnLostSight(CBaseEntity *ent);
	
	virtual ??? OnSound(CBaseEntity *ent, const Vector& v1, KeyValues *kv);
	virtual ??? OnSpokeConcept(CBaseCombatCharacter *who, const char *s1, AI_Response *response);
	virtual ??? OnWeaponFired(CBaseCombatCharacter *who, CBaseCombatWeapon *weapon);
	
	virtual ??? OnNavAreaChanged(CNavArea *area1, CNavArea *area2);
	virtual ??? OnModelChanged();
	virtual ??? OnPickUp(CBaseEntity *ent, CBaseCombatCharacter *who);
	virtual ??? OnDrop(CBaseEntity *ent);
	virtual ??? OnActorEmoted(CBaseCombatCharacter *who, int i1);
	
	virtual ??? OnCommandAttack(CBaseEntity *ent);
	virtual ??? OnCommandApproach(const Vector& v1, float f1);
	virtual ??? OnCommandApproach(CBaseEntity *ent);
	virtual ??? OnCommandRetreat(CBaseEntity *ent, float f1);
	virtual ??? OnCommandPause(float f1);
	virtual ??? OnCommandResume();
	virtual ??? OnCommandString(const char *cmd);
	
	virtual ??? OnShoved(CBaseEntity *ent);
	virtual ??? OnBlinded(CBaseEntity *ent);
	
	virtual ??? OnTerritoryContested(int i1);
	virtual ??? OnTerritoryCaptured(int i1);
	virtual ??? OnTerritoryLost(int i1);
	
	virtual ??? OnWin();
	virtual ??? OnLose();
	
protected:
	// TODO
	
private:
	// TODO
};


class INextBotComponent : public INextBotEventResponder
{
public:
	virtual ~INextBotComponent();
	
	virtual ??? Reset();
	virtual ??? Update() = 0;
	virtual ??? Upkeep();
	virtual ??? GetBot() const;
	
protected:
	// TODO
	
private:
	// TODO
};


// TODO: enum NextBotDebugType
// TODO: INextBot::NextBotDebugLineType


class INextBot : public INextBotEventResponder
{
public:
	INextBot();
	virtual ~INextBot();
	
	/* INextBotEventResponder overrides */
	virtual INextBotEventResponder *FirstContainedResponder() const;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *prev) const;
	
	virtual ??? Reset();
	virtual ??? Update();
	virtual ??? Upkeep();
	
	virtual ??? IsRemovedOnReset() const;
	
	virtual ??? GetEntity() const = 0;
	virtual ??? GetNextBotCombatCharacter() const;
	
	virtual ??? GetLocomotionInterface() const;
	virtual ??? GetBodyInterface() const;
	virtual ??? GetIntentionInterface() const;
	virtual ??? GetVisionInterface() const;
	
	virtual ??? SetPosition(const Vector& v1);
	virtual ??? GetPosition() const;
	
	virtual ??? IsEnemy(const CBaseEntity *ent) const;
	virtual ??? IsFriend(const CBaseEntity *ent) const;
	virtual ??? IsSelf(const CBaseEntity *ent) const;
	
	virtual ??? IsAbleToClimbOnto(const CBaseEntity *ent) const;
	virtual ??? IsAbleToBreak(const CBaseEntity *ent) const;
	virtual ??? IsAbleToBlockMovementOf(const INextBot *nextbot) const;
	
	virtual ??? ShouldTouch(const CBaseEntity *ent) const;
	
	virtual ??? IsImmobile() const;
	virtual ??? GetImmobileDuration() const;
	virtual ??? ClearImmobileStatus();
	virtual ??? GetImmobileSpeedThreshold() const;
	
	virtual ??? GetCurrentPath() const;
	virtual ??? SetCurrentPath(const PathFollower *follower);
	virtual ??? NotifyPathDestruction(const PathFollower *follower);
	
	virtual ??? IsRangeLessThan(CBaseEntity *ent, float f1) const;
	virtual ??? IsRangeLessThan(const Vector& v1, float f1) const;
	virtual ??? IsRangeGreaterThan(CBaseEntity *ent, float f1) const;
	virtual ??? IsRangeGreaterThan(const Vector& v1, float f1) const;
	
	virtual ??? GetRangeTo(CBaseEntity *ent) const;
	virtual ??? GetRangeTo(const Vector& v1) const;
	virtual ??? GetRangeSquaredTo(CBaseEntity *ent) const;
	virtual ??? GetRangeSquaredTo(const Vector& v1) const;
	
	virtual ??? IsDebugging(unsigned int i1) const;
	virtual ??? GetDebugIdentifier() const;
	virtual ??? IsDebugFilterMatch(const char *s1) const;
	virtual ??? DisplayDebugText(const char *s1) const;
	
	??? BeginUpdate();
	??? EndUpdate();
	
	??? DebugConColorMessage(NextBotDebugType type, const Color& color, const char *fmt, ...);
	
	??? GetDebugHistory(unsigned int, CUtlVector<const INextBot::NextBotDebugLineType *> *) const;
	??? ResetDebugHistory();
	
	??? RegisterComponent(INextBotComponent *component);
	
protected:
	// TODO
	
private:
	// TODO
};


class NextBotCombatCharacter : public CBaseCombatCharacter, public INextBot
{
public:
	virtual ~NextBotCombatCharacter();
	
	/* CBaseCombatCharacter overrides */
	// TODO
	
	/* INextBot overrides */
	virtual ??? OnNavAreaChanged(CNavArea *area1, CNavArea *area2);
	virtual ??? GetEntity() const;
	virtual ??? GetNextBotCombatCharacter() const;
	
	// TODO: non-virtual functions
	
protected:
	// TODO
	
private:
	// TODO
};


class INextBotPlayerInput
{
public:
	virtual ??? PressFireButton(float f1) = 0;
	virtual ??? ReleaseFireButton() = 0;
	virtual ??? PressAltFireButton(float f1) = 0;
	virtual ??? ReleaseAltFireButton() = 0;
	virtual ??? PressMeleeButton(float f1) = 0;
	virtual ??? ReleaseMeleeButton() = 0;
	virtual ??? PressUseButton(float f1) = 0;
	virtual ??? ReleaseUseButton() = 0;
	virtual ??? PressReloadButton(float f1) = 0;
	virtual ??? ReleaseReloadButton() = 0;
	virtual ??? PressForwardButton(float f1) = 0;
	virtual ??? ReleaseForwardButton() = 0;
	virtual ??? PressBackwardButton(float f1) = 0;
	virtual ??? ReleaseBackwardButton() = 0;
	virtual ??? PressLeftButton(float f1) = 0;
	virtual ??? ReleaseLeftButton() = 0;
	virtual ??? PressRightButton(float f1) = 0;
	virtual ??? ReleaseRightButton() = 0;
	virtual ??? PressJumpButton(float f1) = 0;
	virtual ??? ReleaseJumpButton() = 0;
	virtual ??? PressCrouchButton(float f1) = 0;
	virtual ??? ReleaseCrouchButton() = 0;
	virtual ??? PressWalkButton(float f1) = 0;
	virtual ??? ReleaseWalkButton() = 0;
	virtual ??? SetButtonScale(float f1, float f2) = 0;
	
protected:
	// TODO
	
private:
	// TODO
};


template<class T> class NextBotPlayer : public T, public INextBot, public INextBotPlayerInput
{
public:
	virtual ~NextBotPlayer();
	
	/* T overrides */
	// TODO
	
	/* INextBot overrides */
	virtual ??? OnNavAreaChanged(CNavArea *area1, CNavArea *area2);
	virtual ??? Update();
	virtual ??? IsRemovedOnReset() const;
	virtual ??? GetEntity() const;
	
	/* INextBotPlayerInput overrides */
	virtual ??? PressFireButton(float f1);
	virtual ??? ReleaseFireButton();
	virtual ??? PressAltFireButton(float f1);
	virtual ??? ReleaseAltFireButton();
	virtual ??? PressMeleeButton(float f1);
	virtual ??? ReleaseMeleeButton();
	virtual ??? PressUseButton(float f1);
	virtual ??? ReleaseUseButton();
	virtual ??? PressReloadButton(float f1);
	virtual ??? ReleaseReloadButton();
	virtual ??? PressForwardButton(float f1);
	virtual ??? ReleaseForwardButton();
	virtual ??? PressBackwardButton(float f1);
	virtual ??? ReleaseBackwardButton();
	virtual ??? PressLeftButton(float f1);
	virtual ??? ReleaseLeftButton();
	virtual ??? PressRightButton(float f1);
	virtual ??? ReleaseRightButton();
	virtual ??? PressJumpButton(float f1);
	virtual ??? ReleaseJumpButton();
	virtual ??? PressCrouchButton(float f1);
	virtual ??? ReleaseCrouchButton();
	virtual ??? PressWalkButton(float f1);
	virtual ??? ReleaseWalkButton();
	virtual ??? SetButtonScale(float f1, float f2);
	
	// TODO: non-virtual functions
	
protected:
	// TODO
	
private:
	// TODO
};
template<> class NextBotPlayer<CTFPlayer>;


class INextBotEntityFilter
{
public:
	// TODO
	
protected:
	// TODO
	
private:
	// TODO
};


class INextBotFilter
{
public:
	// TODO
	
protected:
	// TODO
	
private:
	// TODO
};


class NextBotManager
{
public:
	// TODO
	
protected:
	// TODO
	
private:
	// TODO
};


// derived from INextBotFilter:
// CHealthFilter
// CAmmoFilter (only in osx server classgraph)

// derived from INextBotEntityFilter:
// CUsefulHealTargetFilter


struct ActionResults
{
	// result enum code
	// next action (if any)
	// descriptive message
};
