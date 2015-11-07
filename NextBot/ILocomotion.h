/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: locomotion component
 */


class ILocomotion : public INextBotComponent
{
public:
	enum class TraverseWhenType : int
	{
		// TODO
	};
	
	ILocomotion(INextBot *nextbot);
	virtual ~ILocomotion();
	
	virtual void Reset() override;
	virtual void Update() override;
	
	virtual float Approach(const Vector& v1, float f1);
	virtual float DriveTo(const Vector& v1);
	virtual bool ClimbUpToLedge(const Vector& v1, const Vector& v2, const CBaseEntity *ent);
	virtual void JumpAcrossGap(const Vector& v1, const Vector& v2);
	virtual void Jump();
	virtual bool IsClimbingOrJumping() const;
	virtual bool IsClimbingUpToLedge() const;
	virtual bool IsJumpingAcrossGap() const;
	virtual bool IsScrambling() const;
	virtual void Run();
	virtual void Walk();
	virtual void Stop();
	virtual bool IsRunning() const;
	virtual void SetDesiredSpeed(float speed);
	virtual float GetDesiredSpeed() const;
	virtual void SetSpeedLimit(float limit);
	virtual float GetSpeedLimit() const;
	virtual bool IsOnGround() const;
	virtual UNKNOWN GetGround() const;
	virtual Vector& GetGroundNormal() const;
	virtual float GetGroundSpeed() const;
	virtual Vector& GetGroundMotionVector() const;
	virtual void ClimbLadder(const CNavLadder *ladder, const CNavArea *area);
	virtual void DescendLadder(const CNavLadder *ladder, const CNavArea *area);
	virtual bool IsUsingLadder() const;
	virtual bool IsAscendingOrDescendingLadder() const;
	virtual bool IsAbleToAutoCenterOnLadder() const;
	virtual void FaceTowards(const Vector& v1);
	virtual void SetDesiredLean(const QAngle& q1);
	virtual QAngle& GetDesiredLean() const;
	virtual bool IsAbleToJumpAcrossGaps() const;
	virtual bool IsAbleToClimb() const;
	virtual UNKNOWN GetFeet() const;
	virtual float GetStepHeight() const;
	virtual float GetMaxJumpHeight() const;
	virtual float GetDeathDropHeight() const;
	virtual float GetRunSpeed() const;
	virtual float GetWalkSpeed() const;
	virtual float GetMaxAcceleration() const;
	virtual float GetMaxDeceleration() const;
	virtual Vector& GetVelocity() const;
	virtual float GetSpeed() const;
	virtual Vector& GetMotionVector() const;
	virtual bool IsAreaTraversable(const CNavArea *area) const;
	virtual float GetTraversableSlopeLimit() const;
	virtual bool IsPotentiallyTraversable(const Vector& v1, const Vector& v2, TraverseWhenType ttype, float *f1) const;
	virtual bool HasPotentialGap(const Vector& v1, const Vector& v2, float *f1) const;
	virtual bool IsGap(const Vector& v1, const Vector& v2) const;
	virtual bool IsEntityTraversable(CBaseEntity *ent, TraverseWhenType ttype) const;
	virtual bool IsStuck() const;
	virtual float GetStuckDuration() const;
	virtual void ClearStuckStatus(char const *s1);
	virtual bool IsAttemptingToMove() const;
	virtual bool ShouldCollideWith(const CBaseEntity *ent) const;
	virtual void AdjustPosture(const Vector& v1);
	virtual void StuckMonitor();
	
protected:
	// TODO
};


class CEyeballBossLocomotion : public ILocomotion
{
	// TODO
};


class CMerasmusFlyingLocomotion : public ILocomotion
{
	// TODO
};


class NextBotGroundLocomotion : public ILocomotion
{
	// TODO
};


class CBotNPCDecoyLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CGhostLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CHeadlessHatmanLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CMerasmusLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CRobotLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CTFBaseBossLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CZombieLocomotion : public NextBotGroundLocomotion
{
	// TODO
};


class PlayerLocomotion : public ILocomotion
{
	// TODO
};

// sizeof: 0xa4
class CTFBotLocomotion : public PlayerLocomotion
{
	// TODO
};
