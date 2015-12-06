/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/NextBot/Player/NextBotPlayerBody.cpp
 */


ConVar nb_saccade_time("nb_saccade_time", "0.1", FCVAR_CHEAT);
ConVar nb_saccade_speed("nb_saccade_speed", "1000", FCVAR_CHEAT);
ConVar nb_head_aim_steady_max_rate("nb_head_aim_steady_max_rate", "100", FCVAR_CHEAT);
ConVar nb_head_aim_settle_duration("nb_head_aim_settle_duration", "0.3", FCVAR_CHEAT);
ConVar nb_head_aim_resettle_angle("nb_head_aim_resettle_angle", "100", FCVAR_CHEAT,
	"After rotating through this angle, the bot pauses to 'recenter' its virtual mouse on its virtual mousepad");
ConVar nb_head_aim_resettle_time("nb_head_aim_resettle_time", "0.3", FCVAR_CHEAT,
	"How long the bot pauses to 'recenter' its virtual mouse on its virtual mousepad");
ConVar bot_mimic("bot_mimic", "0", FCVAR_NONE,
	"Bot uses usercmd of player by index.");


PlayerBody::PlayerBody(INextBot *nextbot)
	: IBody(nextbot)
{
	// TODO
}

PlayerBody::~PlayerBody()
{
}


void PlayerBody::Reset()
{
	// TODO
}

void PlayerBody::Upkeep()
{
	// TODO
}


bool PlayerBody::SetPosition(const Vector& pos)
{
	this->m_Player->SetAbsOrigin(pos);
	return true;
}

Vector& PlayerBody::GetEyePosition() const
{
	this->m_vecEyePosition = this->m_Player->EyePosition();
	return this->m_vecEyePosition;
}

Vector& PlayerBody::GetViewVector() const
{
	this->m_Player->EyeVectors(&this->m_vecEyeVectors);
	return this->m_vecEyeVectors;
}

void PlayerBody::AimHeadTowards(const Vector& vec, LookAtPriorityType priority, float duration, INextBotReply *reply, const char *reason)
{
	if (duration <= 0.0f) {
		duration = 0.1f;
	}
	
	if (priority == this->m_iAimPriority &&
		(!this->IsHeadSteady() || this->GetHeadSteadyDuration() <
		nb_head_aim_settle_duration.GetFloat())) {
		if (reply != nullptr) {
			reply->OnFail(this->GetBot(),
				INextBotReply::FailureReason::REJECTED);
		}
		
		if (this->GetBot()->IsDebugging(NextBotDebugType::LOOK_AT)) {
			ConColorMsg(COLOR_RED, "%3.2f: %s Look At '%s' rejected - "
				"previous aim not %s\n",
				gpGlobals->curtime, this->m_Player->GetPlayerName(), reason,
				(this->IsHeadSteady() ? "settled long enough" : "head-steady"));
		}
	}
	
	if (priority > this->m_iAimPriority || this->m_ctAimDuration.IsElapsed()) {
		if (this->m_AimReply != nullptr) {
			this->m_AimReply->OnFail(this->GetBot(),
				INextBotReply::FailureReason::PREEMPTED);
		}
		this->m_AimReply = reply;
		
		this->m_ctAimDuration.Start(duration);
		this->m_iAimPriority = priority;
		
		/* ignore tiny changes to our aim target */
		if (vec->DistTo(this->m_vecAimTarget) >= 1.0f) {
			// TODO: dword @ +0x5c = -1
			this->m_vecAimTarget = vec;
			this->m_itAimStart.Start();
			// TODO: bool @ +0x90 = false
			
			if (this->GetBot()->IsDebugging(NextBotDebugType::LOOK_AT)) {
				NDebugOverlay::Cross3D(vec, 2.0f, 255, 255, 100, true, 2 * duration);
				
				const char *pri_str = "";
				switch (priority) {
				case IBody::PriorityType::BORING:
					pri_str = "Boring";
					break;
				case IBody::PriorityType::INTERESTING:
					pri_str = "Interesting";
					break;
				case IBody::PriorityType::IMPORTANT:
					pri_str = "Important";
					break;
				case IBody::PriorityType::CRITICAL:
					pri_str = "Critical";
					break;
				}
				
				ConColorMsg(COLOR_ORANGE, "%3.2f: %s Look At ( %g, %g, %g ) "
					"for %3.2f s, Pri = %s, Reason = %s\n",
					gpGlobals->curtime, this->m_Player->GetPlayerName(),
					vec.x, vec.y, vec.z, duration, pri_str,
					(reason != nullptr ? reason : ""));
			}
		}
	} else {
		if (reply != nullptr) {
			reply->OnFail(this->GetBot(),
				INextBotReply::FailureReason::REJECTED);
		}
		
		if (this->GetBot()->IsDebugging(NextBotDebugType::LOOK_AT)) {
			ConColorMsg(COLOR_RED, "%3.2f: %s Look At '%s' rejected - "
				"higher priority aim in progress\n",
				gpGlobals->curtime, this->m_Player->GetPlayerName(), reason);
		}
	}
}

void PlayerBody::AimHeadTowards(CBaseEntity *ent, LookAtPriorityType priority, float duration, INextBotReply *reply, const char *reason)
{
	// TODO
}

bool PlayerBody::IsHeadAimingOnTarget() const
{
	// TODO
}

bool PlayerBody::IsHeadSteady() const
{
	return this->m_itHeadSteady.HasStarted();
}

float PlayerBody::GetHeadSteadyDuration() const
{
	if (!this->m_itHeadSteady.HasStarted()) {
		return 0.0f;
	}
	
	return this->m_itHeadSteady.GetElapsedTime();
}

void PlayerBody::ClearPendingAimReply()
{
	this->m_AimReply = nullptr;
}

float PlayerBody::GetMaxHeadAngularVelocity() const
{
	return nb_saccade_speed.GetFloat();
}

bool PlayerBody::StartActivity(Activity a1, unsigned int i1)
{
	return false;
}

Activity PlayerBody::GetActivity() const
{
	return ACT_INVALID;
}

bool PlayerBody::IsActivity(Activity a1) const
{
	return false;
}

bool PlayerBody::HasActivityType(unsigned int i1) const
{
	return false;
}

void PlayerBody::SetDesiredPosture(PostureType posture)
{
	this->m_iPosture = posture;
}

PostureType PlayerBody::GetDesiredPosture() const
{
	return this->m_iPosture;
}

bool PlayerBody::IsDesiredPosture(PostureType posture) const
{
	return (posture == this->m_iPosture);
}

bool PlayerBody::IsInDesiredPosture() const
{
	return true;
}

PostureType PlayerBody::GetActualPosture() const
{
	return this->m_iPosture;
}

bool PlayerBody::IsActualPosture(PostureType posture) const
{
	return (posture == this->m_iPosture);
}

bool PlayerBody::IsPostureMobile() const
{
	return true;
}

bool PlayerBody::IsPostureChanging() const
{
	return false;
}

void PlayerBody::SetArousal(ArousalType arousal)
{
	this->m_iArousal = arousal;
}

ArousalType PlayerBody::GetArousal() const
{
	return this->m_iArousal;
}

bool PlayerBody::IsArousal(ArousalType arousal) const
{
	return (arousal == this->m_iArousal);
}

float PlayerBody::GetHullWidth() const
{
	return (VEC_HULL_MAX_SCALED(this->m_Player).x -
		VEC_HULL_MIN_SCALED(this->m_Player).x);
}

float PlayerBody::GetHullHeight() const
{
	if (this->m_iPosture == IBody::PostureType::CROUCH) {
		return this->GetCrouchHullHeight();
	} else {
		return this->GetStandHullHeight();
	}
}

float PlayerBody::GetStandHullHeight() const
{
	return (VEC_HULL_MAX_SCALED(this->m_Player).z -
		VEC_HULL_MIN_SCALED(this->m_Player).z);
}

float PlayerBody::GetCrouchHullHeight() const
{
	/* BUG: should be using the _SCALED versions of these macros! */
	return (VEC_DUCK_HULL_MAX.z - VEC_DUCK_HULL_MIN.z);
}

Vector& PlayerBody::GetHullMins() const
{
	if (this->m_iPosture == IBody::PostureType::CROUCH) {
		this->m_vecHullMaxs = VEC_DUCK_HULL_MIN_SCALED(this->m_Player);
	} else {
		this->m_vecHullMaxs = VEC_HULL_MIN_SCALED(this->m_Player);
	}
	
	return this->m_vecHullMins;
}

Vector& PlayerBody::GetHullMaxs() const
{
	if (this->m_iPosture == IBody::PostureType::CROUCH) {
		this->m_vecHullMaxs = VEC_DUCK_HULL_MAX_SCALED(this->m_Player);
	} else {
		this->m_vecHullMaxs = VEC_HULL_MAX_SCALED(this->m_Player);
	}
	
	return this->m_vecHullMaxs;
}

unsigned int PlayerBody::GetSolidMask() const
{
	if (this->m_Player == nullptr) {
		return MASK_PLAYERSOLID;
	}
	
	return this->m_Player->PlayerSolidMask();
}


CBaseEntity *PlayerBody::GetEntity()
{
	return this->m_Player;
}
