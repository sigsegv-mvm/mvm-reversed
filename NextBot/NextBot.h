/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: core stuff
 */


enum NextBotDebugType
{
	// TODO
};


class INextBot : public INextBotEventResponder
{
public:
	enum NextBotDebugLineType
	{
		// TODO
	};
	
	INextBot();
	virtual ~INextBot();
	
	/* INextBotEventResponder overrides */
	virtual INextBotEventResponder *FirstContainedResponder() const;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *prev) const;
	
	virtual UNKNOWN Reset();
	virtual UNKNOWN Update();
	virtual UNKNOWN Upkeep();
	
	virtual UNKNOWN IsRemovedOnReset() const;
	
	virtual UNKNOWN GetEntity() const = 0;
	virtual UNKNOWN GetNextBotCombatCharacter() const;
	
	virtual UNKNOWN GetLocomotionInterface() const;
	virtual UNKNOWN GetBodyInterface() const;
	virtual UNKNOWN GetIntentionInterface() const;
	virtual UNKNOWN GetVisionInterface() const;
	
	virtual UNKNOWN SetPosition(const Vector& v1);
	virtual UNKNOWN GetPosition() const;
	
	virtual UNKNOWN IsEnemy(const CBaseEntity *ent) const;
	virtual UNKNOWN IsFriend(const CBaseEntity *ent) const;
	virtual UNKNOWN IsSelf(const CBaseEntity *ent) const;
	
	virtual UNKNOWN IsAbleToClimbOnto(const CBaseEntity *ent) const;
	virtual UNKNOWN IsAbleToBreak(const CBaseEntity *ent) const;
	virtual UNKNOWN IsAbleToBlockMovementOf(const INextBot *nextbot) const;
	
	virtual UNKNOWN ShouldTouch(const CBaseEntity *ent) const;
	
	virtual UNKNOWN IsImmobile() const;
	virtual UNKNOWN GetImmobileDuration() const;
	virtual UNKNOWN ClearImmobileStatus();
	virtual UNKNOWN GetImmobileSpeedThreshold() const;
	
	virtual UNKNOWN GetCurrentPath() const;
	virtual UNKNOWN SetCurrentPath(const PathFollower *follower);
	virtual UNKNOWN NotifyPathDestruction(const PathFollower *follower);
	
	virtual UNKNOWN IsRangeLessThan(CBaseEntity *ent, float f1) const;
	virtual UNKNOWN IsRangeLessThan(const Vector& v1, float f1) const;
	virtual UNKNOWN IsRangeGreaterThan(CBaseEntity *ent, float f1) const;
	virtual UNKNOWN IsRangeGreaterThan(const Vector& v1, float f1) const;
	
	virtual UNKNOWN GetRangeTo(CBaseEntity *ent) const;
	virtual UNKNOWN GetRangeTo(const Vector& v1) const;
	virtual UNKNOWN GetRangeSquaredTo(CBaseEntity *ent) const;
	virtual UNKNOWN GetRangeSquaredTo(const Vector& v1) const;
	
	virtual UNKNOWN IsDebugging(unsigned int i1) const;
	virtual UNKNOWN GetDebugIdentifier() const;
	virtual UNKNOWN IsDebugFilterMatch(const char *s1) const;
	virtual UNKNOWN DisplayDebugText(const char *s1) const;
	
	UNKNOWN BeginUpdate();
	UNKNOWN EndUpdate();
	
	UNKNOWN DebugConColorMessage(NextBotDebugType type, const Color& color, const char *fmt, ...);
	
	UNKNOWN GetDebugHistory(unsigned int, CUtlVector<const INextBot::NextBotDebugLineType *> *) const;
	UNKNOWN ResetDebugHistory();
	
	UNKNOWN RegisterComponent(INextBotComponent *component);
	
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
	virtual void OnNavAreaChanged(CNavArea *area1, CNavArea *area2);
	virtual UNKNOWN GetEntity() const;
	virtual UNKNOWN GetNextBotCombatCharacter() const;
	
	// TODO: non-virtual functions
	
protected:
	// TODO
	
private:
	// TODO
};


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
