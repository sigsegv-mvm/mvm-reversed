/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * NextBot: locomotion component
 */


ILocomotion::ILocomotion(INextBot *nextbot)
	: INextBotComponent(nextbot);
{
	// TODO
	
	this->Reset();
}

ILocomotion::~ILocomotion()
{
	// TODO
}


void ILocomotion::OnLeaveGround(CBaseEntity *ent)
{
}

void ILocomotion::OnLandOnGround(CBaseEntity *ent)
{
}


void ILocomotion::Reset()
{
	INextBotComponent::Reset();
	
	// TODO
}

void ILocomotion::Update()
{
	// TODO
}


float ILocomotion::Approach(const Vector& v1, float f1)
{
	// TODO
}

float ILocomotion::DriveTo(const Vector& v1)
{
	// TODO
}

bool ILocomotion::ClimbUpToLedge(const Vector& v1, const Vector& v2, const CBaseEntity *ent)
{
	return true;
}

void ILocomotion::JumpAcrossGap(const Vector& v1, const Vector& v2)
{
}

void ILocomotion::Jump()
{
}

bool ILocomotion::IsClimbingOrJumping() const
{
	return false;
}

bool ILocomotion::IsClimbingUpToLedge() const
{
	return false;
}

bool ILocomotion::IsJumpingAcrossGap() const
{
	return false;
}

bool ILocomotion::IsScrambling() const
{
	if (!this->IsOnGround() || this->IsClimbingOrJumping()) {
		return true;
	} else {
		return this->IsAscendingOrDescendingLadder();
	}
}

void ILocomotion::Run()
{
}

void ILocomotion::Walk()
{
}

void ILocomotion::Stop()
{
}

bool ILocomotion::IsRunning() const
{
	return false;
}

void ILocomotion::SetDesiredSpeed(float speed)
{
}

float ILocomotion::GetDesiredSpeed() const
{
	return 0.0f;
}

void ILocomotion::SetSpeedLimit(float limit)
{
}

float ILocomotion::GetSpeedLimit() const
{
	return 1000.0f;
}

bool ILocomotion::IsOnGround() const
{
	return false;
}

CBaseEntity *ILocomotion::GetGround() const
{
	return nullptr;
}

Vector& ILocomotion::GetGroundNormal() const
{
	return vec3_origin;
}

float ILocomotion::GetGroundSpeed() const
{
	// TODO
}

Vector& ILocomotion::GetGroundMotionVector() const
{
	// TODO
}

void ILocomotion::ClimbLadder(const CNavLadder *ladder, const CNavArea *area)
{
}

void ILocomotion::DescendLadder(const CNavLadder *ladder, const CNavArea *area)
{
}

bool ILocomotion::IsUsingLadder() const
{
	return false;
}

bool ILocomotion::IsAscendingOrDescendingLadder() const
{
	return false;
}

bool ILocomotion::IsAbleToAutoCenterOnLadder() const
{
	return false;
}

void ILocomotion::FaceTowards(const Vector& v1)
{
}

void ILocomotion::SetDesiredLean(const QAngle& q1)
{
}

QAngle& ILocomotion::GetDesiredLean() const
{
	return vec3_angle;
}

bool ILocomotion::IsAbleToJumpAcrossGaps() const
{
	return true;
}

bool ILocomotion::IsAbleToClimb() const
{
	return true;
}

Vector& ILocomotion::GetFeet() const
{
	return this->GetBot()->GetEntity()->GetAbsOrigin();
}

float ILocomotion::GetStepHeight() const
{
	return 0.0f;
}

float ILocomotion::GetMaxJumpHeight() const
{
	return 0.0f;
}

float ILocomotion::GetDeathDropHeight() const
{
	return 0.0f;
}

float ILocomotion::GetRunSpeed() const
{
	return 0.0f;
}

float ILocomotion::GetWalkSpeed() const
{
	return 0.0f;
}

float ILocomotion::GetMaxAcceleration() const
{
	return 0.0f;
}

float ILocomotion::GetMaxDeceleration() const
{
	return 0.0f;
}

Vector& ILocomotion::GetVelocity() const
{
	return vec3_origin;
}

float ILocomotion::GetSpeed() const
{
	// TODO
}

Vector& ILocomotion::GetMotionVector() const
{
	// TODO
}

bool ILocomotion::IsAreaTraversable(const CNavArea *area) const
{
	// TODO
}

float ILocomotion::GetTraversableSlopeLimit() const
{
	return 0.6f;
}

bool ILocomotion::IsPotentiallyTraversable(const Vector& v1, const Vector& v2, TraverseWhenType ttype, float *f1) const
{
	// TODO
}

bool ILocomotion::HasPotentialGap(const Vector& v1, const Vector& v2, float *f1) const
{
	// TODO
}

bool ILocomotion::IsGap(const Vector& v1, const Vector& v2) const
{
	// TODO
}

bool ILocomotion::IsEntityTraversable(CBaseEntity *ent, TraverseWhenType ttype) const
{
	// TODO
}

bool ILocomotion::IsStuck() const
{
	// TODO
}

float ILocomotion::GetStuckDuration() const
{
	// TODO
}

void ILocomotion::ClearStuckStatus(char const *s1)
{
	// TODO
}

bool ILocomotion::IsAttemptingToMove() const
{
	// TODO
}

bool ILocomotion::ShouldCollideWith(const CBaseEntity *ent) const
{
	return true;
}

void ILocomotion::AdjustPosture(const Vector& v1)
{
	// TODO
}

void ILocomotion::StuckMonitor()
{
	// TODO
}
