/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: body component
 */


class IBody : public INextBotComponent
{
public:
	enum class LookAtPriorityType : int
	{
		// TODO
	};
	
	enum class PostureType : int
	{
		// TODO
	};
	
	enum class ArousalType : int
	{
		// TODO
	};
	
	IBody(INextBot *nextbot);
	virtual ~IBody();
	
	virtual void Reset() override;
	virtual void Update() override;
	
	virtual bool SetPosition(const Vector& v1);
	virtual Vector& GetEyePosition() const;
	virtual Vector& GetViewVector() const;
	virtual void AimHeadTowards(const Vector& v1, LookAtPriorityType priority, float duration, INextBotReply *reply, const char *s1);
	virtual void AimHeadTowards(CBaseEntity *ent, LookAtPriorityType priority, float duration, INextBotReply *reply, const char *s1);
	virtual bool IsHeadAimingOnTarget() const;
	virtual bool IsHeadSteady() const;
	virtual float GetHeadSteadyDuration() const;
	virtual float GetHeadAimSubjectLeadTime() const;
	virtual float GetHeadAimTrackingInterval() const;
	virtual void ClearPendingAimReply();
	virtual float GetMaxHeadAngularVelocity() const;
	virtual UNKNOWN StartActivity(Activity a1, unsigned int i1);
	virtual UNKNOWN SelectAnimationSequence(Activity a1) const;
	virtual UNKNOWN GetActivity() const;
	virtual bool IsActivity(Activity a1) const;
	virtual bool HasActivityType(unsigned int i1) const;
	virtual void SetDesiredPosture(PostureType posture);
	virtual PostureType GetDesiredPosture() const;
	virtual bool IsDesiredPosture(PostureType posture) const;
	virtual bool IsInDesiredPosture() const;
	virtual PostureType GetActualPosture() const;
	virtual bool IsActualPosture(PostureType posture) const;
	virtual bool IsPostureMobile() const;
	virtual bool IsPostureChanging() const;
	virtual void SetArousal(ArousalType arousal);
	virtual ArousalType GetArousal() const;
	virtual bool IsArousal(ArousalType arousal) const;
	virtual float GetHullWidth() const;
	virtual float GetHullHeight() const;
	virtual float GetStandHullHeight() const;
	virtual float GetCrouchHullHeight() const;
	virtual float& GetHullMins() const;
	virtual float& GetHullMaxs() const;
	virtual unsigned int GetSolidMask() const;
	virtual int GetCollisionGroup() const;
	
protected:
	// TODO
};


class CHeadlessHatmanBody : public IBody
{
	// TODO
};


class CMerasmusBody : public IBody
{
	// TODO
};


class CTFTankBossBody : public IBody
{
	// TODO
};


class CBotNPCBody : public IBody
{
	// TODO
};

class CEyeballBossBody : public CBotNPCBody
{
	// TODO
};


class PlayerBody : public IBody
{
	// TODO
};

// sizeof: 0xc8
class CTFBotBody : public PlayerBody
{
	// TODO
};
