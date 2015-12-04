/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/NextBot/Player/NextBotPlayerLocomotion.h
 */


class PlayerLocomotion : public ILocomotion
{
public:
	PlayerLocomotion(INextBot *nextbot);
	virtual ~PlayerLocomotion();
	
	virtual void Reset() override;
	
	virtual void Approach(const Vector& v1, float f1) override;
	virtual void DriveTo(const Vector& v1) override;
	virtual bool ClimbUpToLedge(const Vector& v1, const Vector& v2, const CBaseEntity *ent) override;
	virtual void JumpAcrossGap(const Vector& v1, const Vector& v2) override;
	virtual void Jump() override;
	virtual bool IsClimbingOrJumping() const override;
	virtual bool IsClimbingUpToLedge() const override;
	virtual bool IsJumpingAcrossGap() const override;
	virtual void Run() override;
	virtual void Walk() override;
	virtual void Stop() override;
	virtual bool IsRunning() const override;
	virtual void SetDesiredSpeed(float speed) override;
	virtual float GetDesiredSpeed() const override;
	virtual bool IsOnGround() const override;
	virtual CBaseEntity *GetGround() const override;
	virtual Vector& GetGroundNormal() const override;
	virtual void ClimbLadder(const CNavLadder *ladder, const CNavArea *area) override;
	virtual void DescendLadder(const CNavLadder *ladder, const CNavArea *area) override;
	virtual bool IsUsingLadder() const override;
	virtual bool IsAscendingOrDescendingLadder() const override;
	virtual bool IsAbleToAutoCenterOnLadder() const override;
	virtual void FaceTowards(const Vector& v1) override;
	virtual void SetDesiredLean(const QAngle& q1) override;
	virtual QAngle& GetDesiredLean() const override;
	virtual Vector& GetFeet() const override;
	virtual float GetStepHeight() const override;
	virtual float GetMaxJumpHeight() const override;
	virtual float GetDeathDropHeight() const override;
	virtual float GetRunSpeed() const override;
	virtual float GetWalkSpeed() const override;
	virtual float GetMaxAcceleration() const override;
	virtual float GetMaxDeceleration() const override;
	virtual Vector& GetVelocity() const override;
	virtual void AdjustPosture(const Vector& v1) override;
	
	virtual void SetMinimumSpeedLimit(float speed);
	virtual void SetMaximumSpeedLimit(float speed);
	
protected:
	// TODO
	// 58 dword 0
	// 5c 
	// 60 CountdownTimer
	// 6c 
	// ...
	// 84 float minimum speed limit
	// 88 float maximum speed limit
	// ...
	// 98 CountdownTimer
};
