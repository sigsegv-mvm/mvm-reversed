/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: known entities
 */


CKnownEntity::CKnownEntity(CBaseEntity *ent)
{
	this->m_flTimeLastVisible       = -1.0f;
	this->m_flTimeLastBecameVisible = -1.0f;
	
	this->m_bIsVisible           = false;
	this->m_bLastKnownPosWasSeen = false;
	
	this->m_flTimeLastBecameKnown = gpGlobals->curtime;
	
	if (ent != nullptr) {
		this->m_Entity = ent->GetRefEHandle();
		this->UpdatePosition();
	}
}

CKnownEntity::~CKnownEntity()
{
}


void CKnownEntity::Destroy()
{
	this->m_Entity = nullptr;
	this->m_bIsVisible = false;
}

void CKnownEntity::UpdatePosition()
{
	CBaseEntity *ent = this->m_Entity;
	if (ent == nullptr) {
		return;
	}
	this->m_Position = ent->GetAbsOrigin();
	
	CNavArea *area = nullptr;
	if (this->m_Entity->IsCombatCharacter()) {
		CBaseCombatCharacter *cbcc = static_cast<CBaseCombatCharacter *>(this->m_Entity.Get());
		area = cbcc->GetLastKnownArea();
	}
	this->m_NavArea = area;
	
	this->m_flTimeLastKnown = gpGlobals->curtime;
}

CBaseEntity *CKnownEntity::GetEntity() const
{
	return this->m_Entity;
}

const Vector *CKnownEntity::GetLastKnownPosition() const
{
	return &this->m_Position;
}

bool CKnownEntity::HasLastKnownPositionBeenSeen() const
{
	return this->m_bLastKnownPosWasSeen;
}

void CKnownEntity::MarkLastKnownPositionAsSeen()
{
	this->m_bLastKnownPosWasSeen = true;
}

CNavArea *CKnownEntity::GetLastKnownArea() const
{
	return this->m_NavArea;
}

float CKnownEntity::GetTimeSinceLastKnown() const
{
	return (gpGlobals->curtime - this->m_flTimeLastKnown);
}

float CKnownEntity::GetTimeSinceBecameKnown() const
{
	return (gpGlobals->curtime - this->m_flTimeLastBecameKnown);
}

void CKnownEntity::UpdateVisibilityStatus(bool visible)
{
	if (visible) {
		if (!this->m_bIsVisible) {
			this->m_flTimeLastBecameVisible = gpGlobals->curtime;
		}
		this->m_flTimeLastVisible = gpGlobals->curtime;
	}
	
	this->m_bIsVisible = visible;
}

bool CKnownEntity::IsVisibleInFOVNow() const
{
	return this->m_bIsVisible;
}

bool CKnownEntity::IsVisibleRecently() const
{
	if (this->m_bIsVisible) {
		return true;
	} else {
		if (this->WasEverVisible() && this->GetTimeSinceLastSeen() < 3.0f) {
			return true;
		} else {
			return false;
		}
	}
}

float CKnownEntity::GetTimeSinceBecameVisible() const
{
	return (gpGlobals->curtime - this->m_flTimeLastBecameVisible);
}

float CKnownEntity::GetTimeWhenBecameVisible() const
{
	return this->m_flTimeLastBecameVisible;
}

float CKnownEntity::GetTimeSinceLastSeen() const
{
	return (gpGlobals->curtime - this->m_flTimeLastVisible);
}

bool CKnownEntity::WasEverVisible() const
{
	return (this->m_flTimeLastVisible > 0.0f);
}

bool CKnownEntity::IsObsolete() const
{
	return (this->GetEntity() != nullptr &&
		this->GetEntity()->IsAlive() &&
		this->GetTimeSinceLastKnown() <= 10.0f);
}

bool CKnownEntity::operator==(const CKnownEntity& that) const
{
	return (this->GetEntity() != nullptr && that.GetEntity() != nullptr &&
		this->GetEntity() == that.GetEntity());
}

bool CKnownEntity::Is(CBaseEntity *ent) const
{
	return (ent != nullptr && this->GetEntity() != nullptr &&
		ent == this->GetEntity());
}
