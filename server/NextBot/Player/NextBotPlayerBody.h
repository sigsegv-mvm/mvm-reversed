/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/NextBot/Player/NextBotPlayerBody.h
 */


class PlayerBody : public IBody
{
public:
	PlayerBody(INextBot *nextbot);
	virtual ~PlayerBody();
	
	virtual void Reset() override;
	virtual void Upkeep() override;
	
	virtual bool SetPosition(const Vector& pos) override;
	virtual Vector& GetEyePosition() const override;
	virtual Vector& GetViewVector() const override;
	virtual void AimHeadTowards(const Vector& vec, LookAtPriorityType priority, float duration, INextBotReply *reply, const char *s1) override;
	virtual void AimHeadTowards(CBaseEntity *ent, LookAtPriorityType priority, float duration, INextBotReply *reply, const char *s1) override;
	virtual bool IsHeadAimingOnTarget() const override;
	virtual bool IsHeadSteady() const override;
	virtual float GetHeadSteadyDuration() const override;
	virtual void ClearPendingAimReply() override;
	virtual float GetMaxHeadAngularVelocity() const override;
	virtual bool StartActivity(Activity a1, unsigned int i1) override;
	virtual Activity GetActivity() const override;
	virtual bool IsActivity(Activity a1) const override;
	virtual bool HasActivityType(unsigned int i1) const override;
	virtual void SetDesiredPosture(PostureType posture) override;
	virtual PostureType GetDesiredPosture() const override;
	virtual bool IsDesiredPosture(PostureType posture) const override;
	virtual bool IsInDesiredPosture() const override;
	virtual PostureType GetActualPosture() const override;
	virtual bool IsActualPosture(PostureType posture) const override;
	virtual bool IsPostureMobile() const override;
	virtual bool IsPostureChanging() const override;
	virtual void SetArousal(ArousalType arousal) override;
	virtual ArousalType GetArousal() const override;
	virtual bool IsArousal(ArousalType arousal) const override;
	virtual float GetHullWidth() const override;
	virtual float GetHullHeight() const override;
	virtual float GetStandHullHeight() const override;
	virtual float GetCrouchHullHeight() const override;
	virtual Vector& GetHullMins() const override;
	virtual Vector& GetHullMaxs() const override;
	virtual unsigned int GetSolidMask() const override;
	
	virtual CBaseEntity *GetEntity();
	
protected:
	// TODO
	// 14 CBaseEntity* (from nextbot->GetEntity(), for GetEntity)
	// ...
	// 5c dword -1
	// ...
	// 6c CountdownTimer
	// 78 
	// 7c CountdownTimer
	// 88 float -1
	// ...
	// 94 float -1
	// ...
	// b0 CountdownTimer
	// bc 
	// c0 
	// c4 
};
