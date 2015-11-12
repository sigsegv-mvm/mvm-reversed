/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: vision component
 */


IVision::IVision(INextBot *nextbot)
{
	// TODO
}

IVision::~IVision()
{
	// TODO
}


void IVision::Reset()
{
	// TODO
	
	this->m_KnownEntities.RemoveAll();
	
	// TODO
}

void IVision::Update()
{
	// TODO
}


bool IVision::ForEachKnownEntity(IForEachKnownEntity& functor)
{
	FOR_EACH_VEC(this->m_KnownEntities, i) {
		CKnownEntity& known = this->m_KnownEntities[i];
		
		if (!known.IsObsolete() &&
			known->GetTimeSinceBecameKnown() >= this->GetMinRecognizeTime()) {
			if (!functor->Inspect(known)) {
				return false;
			}
		}
	}
	
	return true;
}

void IVision::CollectKnownEntities(CUtlVector<CKnownEntity> *knowns)
{
	if (knowns == nullptr) {
		return;
	}
	
	knowns->RemoveAll();
	knowns->AddVectorToTail(this->m_KnownEntities);
}

const CKnownEntity *IVision::GetPrimaryKnownThreat(bool b1) const
{
	// TODO
}

float IVision::GetTimeSinceVisible(int index) const
{
	if (index == -2) {
		// TODO
	} else if (index < 32) {
		return this->m_Timers[index].GetElapsedTime();
	} else {
		return 0.0f;
	}
}

const CKnownEntity *IVision::GetClosestKnown(int i1) const
{
	// TODO
}

int IVision::GetKnownCount(int i1, bool b1, float f1) const
{
	// TODO
}

const CKnownEntity *IVision::GetClosestKnown(const INextBotEntityFilter& filter) const
{
	// TODO
}

const CKnownEntity *IVision::GetKnown(const CBaseEntity *ent) const
{
	if (ent == nullptr) {
		return nullptr;
	}
	
	FOR_EACH_VEC(this->m_KnownEntities, i) {
		CKnownEntity& known = this->m_KnownEntities[i];
		
		if (known.GetEntity() != nullptr) {
			CBaseEntity *k_ent = known.GetEntity();
			if (k_ent == ent && !known.IsObsolete()) {
				return &known;
			}
		}
	}
	
	return nullptr;
}

void IVision::AddKnownEntity(CBaseEntity *ent)
{
	CKnownEntity known(ent);
	
	if (!this->m_KnownEntities.HasElement(known)) {
		this->m_KnownEntities.AddToTail(known);
	}
}

void IVision::ForgetEntity(CBaseEntity *ent)
{
	if (ent == nullptr) {
		return;
	}
	
	FOR_EACH_VEC(this->m_KnownEntities, i) {
		CKnownEntity& known = this->m_KnownEntities[i];
		
		if (known.GetEntity() != nullptr) {
			CBaseEntity *k_ent = known.GetEntity();
			if (k_ent == ent && !known.IsObsolete()) {
				this->m_KnownEntities.Remove(i);
				break;
			}
		}
	}
}

void IVision::ForgetAllKnownEntities()
{
	this->m_KnownEntities.RemoveAll();
}

void IVision::CollectPotentiallyVisibleEntities(CUtlVector<CBaseEntity *> *ents)
{
	ForEachActor([&](CBaseCombatCharacter *them) {
			ents->AddToTail(them);
		});
}

float IVision::GetMaxVisionRange() const
{
	return 2000.0f;
}

float IVision::GetMinRecognizeTime() const
{
	return 0.0f;
}

bool IVision::IsAbleToSee(CBaseEntity *ent, FieldOfViewCheckType ctype, Vector *v1) const
{
	VPROF_BUDGET("IVision::IsAbleToSee", "NextBotExpensive");
	
	if (this->GetBot()->IsRangeGreaterThan(ent, this->GetMaxVisionRange()) ||
		this->GetBot()->GetEntity()->IsHiddenByFog(ent)) {
		return false;
	}
	
	if (ctype == FieldOfViewCheckType::USE_FOV && !this->IsInFieldOfView(ent)) {
		return false;
	}
	
	CBaseCombatCharacter *ent_cc = ent->MyCombatCharacterPointer();
	if (ent_cc != nullptr) {
		CTFNavArea *lastknown_ent  = ent_cc->GetLastKnownArea();
		CTFNavArea *lastknown_this =
			this->GetBot()->GetEntity()->GetLastKnownArea();
			
		if (lastknown_ent != nullptr && lastknown_this != nullptr &&
			!lastknown_this->IsPotentiallyVisible(lastknown_ent)) {
			return false;
		}
	}
	
	return (this->IsLineOfSightClearToEntity(ent, nullptr) &&
		this->IsVisibleEntityNoticed(ent));
}

bool IVision::IsAbleToSee(const Vector& vec, FieldOfViewCheckType ctype) const
{
	VPROF_BUDGET("IVision::IsAbleToSee", "NextBotExpensive");
	
	if (this->GetBot()->IsRangeGreaterThan(vec, this->GetMaxVisionRange()) ||
		this->GetBot()->GetEntity()->IsHiddenByFog(vec)) {
		return false;
	}
	
	if (ctype == FieldOfViewCheckType::USE_FOV && !this->IsInFieldOfView(vec)) {
		return false;
	}
	
	return this->IsLineOfSightClear(vec);
}

bool IVision::IsIgnored(CBaseEntity *ent) const
{
	return false;
}

bool IVision::IsVisibleEntityNoticed(CBaseEntity *ent) const
{
	return true;
}

bool IVision::IsInFieldOfView(const Vector& vec) const
{
	Vector *view_vec = this->GetBot()->GetBodyInterface()->GetViewVector();
	Vector *eye_pos  = this->GetBot()->GetBodyInterface()->GetEyePosition();
	
	return PointWithinViewAngle(eye_pos, vec, view_vec, this->m_flCosHalfFOV);
}

bool IVision::IsInFieldOfView(CBaseEntity *ent) const
{
	return (this->IsInFieldOfView(ent->WorldSpaceCenter()) ||
		this->IsInFieldOfView(ent->EyePosition())); 
}

float IVision::GetDefaultFieldOfView() const
{
	return 90.0f;
}

float IVision::GetFieldOfView() const
{
	return this->m_flFOV;
}

void IVision::SetFieldOfView(float fov)
{
	this->m_flFOV = fov;
	this->m_flCosHalfFOV = cosf(RAD2DEG(fov * 0.5f));
}

bool IVision::IsLineOfSightClear(const Vector& v1) const
{
	VPROF_BUDGET("IVision::IsLineOfSightClear", "NextBot");
	VPROF_INCREMENT_COUNTER("IVision::IsLineOfSightClear", 1);
	
	NextBotVisionTraceFilter filter(this->GetBot()->GetEntity());
	trace_t trace;
	
	UTIL_TraceLine(this->GetBot()->GetBodyInterface->GetEyePosition(),
		v1, MASK_VISIBLE_AND_NPCS, &filter, &trace);
	
	return (trace.fraction >= 1.0f && !trace.startsolid);
}

bool IVision::IsLineOfSightClearToEntity(const CBaseEntity *ent, Vector *v1) const
{
	VPROF_BUDGET("IVision::IsLineOfSightClearToEntity", "NextBot");
	
	NextBotTraceFilterIgnoreActors filter(ent);
	trace_t trace;
	
	UTIL_TraceLine(this->GetBot()->GetBodyInterface()->GetEyePosition(),
		ent->WorldSpaceCenter(), MASK_VISIBLE_AND_NPCS, &filter, &trace);
	
	if (trace.fraction < 1.0f || trace.allsolid || trace.startsolid) {
		UTIL_TraceLine(this->GetBot()->GetBodyInterface()->GetEyePosition(),
			ent->EyePosition(), MASK_VISIBLE_AND_NPCS, &filter, &trace);
		
		if (trace.fraction < 1.0f || trace.allsolid || trace.startsolid) {
			UTIL_TraceLine(this->GetBot()->GetBodyInterface()->GetEyePosition(),
				ent->GetAbsOrigin(), MASK_VISIBLE_AND_NPCS, &filter, &trace);
		}
	}
	
	if (v1 != nullptr) {
		v1 = trace.endpos;
	}
	
	return (trace.fraction >= 1.0f && !trace.startsolid);
}

bool IVision::IsLookingAt(const Vector& v1, float cos_half_fov) const
{
	Vector *view_vec = this->GetBot()->GetBodyInterface()->GetViewVector();
	Vector *eye_pos  = this->GetBot()->GetBodyInterface()->GetEyePosition();
	
	return PointWithinViewAngle(eye_pos, v1, view_vec, cos_half_fov);
}

bool IVision::IsLookingAt(const CBaseCombatCharacter *who, float cos_half_fov) const
{
	return this->IsLookingAt(who->EyePosition(), cos_half_fov);
}
