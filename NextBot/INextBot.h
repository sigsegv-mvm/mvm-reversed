/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * NextBot: main interface
 */


class INextBot : public INextBotEventResponder
{
public:
	enum NextBotDebugLineType
	{
		// TODO
	};
	
	INextBot();
	virtual ~INextBot();
	
	virtual INextBotEventResponder *FirstContainedResponder() const override;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *prev) const override;
	
	virtual void Reset();
	virtual void Update();
	virtual void Upkeep();
	
	virtual bool IsRemovedOnReset() const;
	
	virtual CBaseEntity *GetEntity() const = 0;
	virtual NextBotCombatCharacter *GetNextBotCombatCharacter() const;
	
	virtual ILocomotion *GetLocomotionInterface() const;
	virtual IBody *GetBodyInterface() const;
	virtual IIntention *GetIntentionInterface() const;
	virtual IVision *GetVisionInterface() const;
	
	virtual bool SetPosition(const Vector& v1);
	virtual Vector& GetPosition() const;
	
	virtual bool IsEnemy(const CBaseEntity *ent) const;
	virtual bool IsFriend(const CBaseEntity *ent) const;
	virtual bool IsSelf(const CBaseEntity *ent) const;
	
	virtual bool IsAbleToClimbOnto(const CBaseEntity *ent) const;
	virtual bool IsAbleToBreak(const CBaseEntity *ent) const;
	virtual bool IsAbleToBlockMovementOf(const INextBot *nextbot) const;
	
	virtual bool ShouldTouch(const CBaseEntity *ent) const;
	
	virtual bool IsImmobile() const;
	virtual float GetImmobileDuration() const;
	virtual void ClearImmobileStatus();
	virtual float GetImmobileSpeedThreshold() const;
	
	virtual PathFollower *GetCurrentPath() const;
	virtual void SetCurrentPath(const PathFollower *follower);
	virtual void NotifyPathDestruction(const PathFollower *follower);
	
	virtual bool IsRangeLessThan(CBaseEntity *ent, float f1) const;
	virtual bool IsRangeLessThan(const Vector& v1, float f1) const;
	virtual bool IsRangeGreaterThan(CBaseEntity *ent, float f1) const;
	virtual bool IsRangeGreaterThan(const Vector& v1, float f1) const;
	
	virtual float GetRangeTo(CBaseEntity *ent) const;
	virtual float GetRangeTo(const Vector& v1) const;
	virtual float GetRangeSquaredTo(CBaseEntity *ent) const;
	virtual float GetRangeSquaredTo(const Vector& v1) const;
	
	virtual bool IsDebugging(unsigned int i1) const;
	virtual char *GetDebugIdentifier() const;
	virtual bool IsDebugFilterMatch(const char *s1) const;
	virtual void DisplayDebugText(const char *s1) const;
	
	bool BeginUpdate();
	void EndUpdate();
	
	void DebugConColorMessage(NextBotDebugType type, const Color& color, const char *fmt, ...);
	
	void GetDebugHistory(unsigned int i1, CUtlVector<const NextBotDebugLineType *> *v1) const;
	void ResetDebugHistory();
	
	void RegisterComponent(INextBotComponent *component);
	
protected:
	// TODO
};


// TODO: for IsDebugging(): enum
// 1   BEHAVIOR
// 128 EVENTS
