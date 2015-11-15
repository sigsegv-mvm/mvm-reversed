/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * NextBot: behaviors
 */


template<class T> Behavior<T>::Behavior(Action<T> *mainaction)
	: m_MainAction(mainaction), m_strName("%s", "")
{
	this->m_Actor = nullptr;
}

template<class T> Behavior<T>::~Behavior()
{
	if (this->m_MainAction != nullptr) {
		if (this->m_Actor != nullptr) {
			this->m_MainAction->InvokeOnEnd(actor, this, nullptr);
			this->m_Actor = nullptr;
		}
		
		Action<T> *action = this->m_MainAction->m_ActionWeSuspended;
		if (action != nullptr) {
			while (action->m_ActionWeSuspended != nullptr) {
				action = action->m_ActionWeSuspended;
			}
		} else {
			action = this->m_MainAction;
		}
		
		delete action;
	}
}


template<class T> INextBotEventResponder *Behavior<T>::FirstContainedResponder() const
{
	return this->m_MainAction;
}

template<class T> INextBotEventResponder *Behavior<T>::NextContainedResponder(INextBotEventResponder *prev) const
{
	return nullptr;
}


template<class T> QueryResponse Behavior<T>::ShouldPickUp(const INextBot *nextbot, CBaseEntity *it) const
{
	if (this->m_MainAction == nullptr) {
		return QueryResponse::DONTCARE;
	}
	
	Action<T> *action = this->m_MainAction;
	while (action->m_ActionChild != nullptr) {
		action = action->m_ActionChild;
	}
	
	do {
		Action<T> *parent = action->m_ParentAction;
		
		while (action != nullptr) {
			QueryResponse response = action->ShouldPickUp(nextbot, it);
			if (response != QueryResponse::DONTCARE) {
				return response;
			}
			
			action = action->m_ActionWeSuspended;
		}
		
		action = parent;
	} while (action != nullptr);
	
	return QueryResponse::DONTCARE;
}

template<class T> QueryResponse Behavior<T>::ShouldHurry(const INextBot *nextbot) const
{
	if (this->m_MainAction == nullptr) {
		return QueryResponse::DONTCARE;
	}
	
	Action<T> *action = this->m_MainAction;
	while (action->m_ActionChild != nullptr) {
		action = action->m_ActionChild;
	}
	
	do {
		Action<T> *parent = action->m_ParentAction;
		
		while (action != nullptr) {
			QueryResponse response = action->ShouldHurry(nextbot);
			if (response != QueryResponse::DONTCARE) {
				return response;
			}
			
			action = action->m_ActionWeSuspended;
		}
		
		action = parent;
	} while (action != nullptr);
	
	return QueryResponse::DONTCARE;
}

template<class T> QueryResponse Behavior<T>::ShouldRetreat(const INextBot *nextbot) const
{
	if (this->m_MainAction == nullptr) {
		return QueryResponse::DONTCARE;
	}
	
	Action<T> *action = this->m_MainAction;
	while (action->m_ActionChild != nullptr) {
		action = action->m_ActionChild;
	}
	
	do {
		Action<T> *parent = action->m_ParentAction;
		
		while (action != nullptr) {
			QueryResponse response = action->ShouldRetreat(nextbot);
			if (response != QueryResponse::DONTCARE) {
				return response;
			}
			
			action = action->m_ActionWeSuspended;
		}
		
		action = parent;
	} while (action != nullptr);
	
	return QueryResponse::DONTCARE;
}

template<class T> QueryResponse Behavior<T>::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	if (this->m_MainAction == nullptr) {
		return QueryResponse::DONTCARE;
	}
	
	Action<T> *action = this->m_MainAction;
	while (action->m_ActionChild != nullptr) {
		action = action->m_ActionChild;
	}
	
	do {
		Action<T> *parent = action->m_ParentAction;
		
		while (action != nullptr) {
			QueryResponse response = action->ShouldAttack(nextbot, threat);
			if (response != QueryResponse::DONTCARE) {
				return response;
			}
			
			action = action->m_ActionWeSuspended;
		}
		
		action = parent;
	} while (action != nullptr);
	
	return QueryResponse::DONTCARE;
}

template<class T> QueryResponse Behavior<T>::IsHindrance(const INextBot *nextbot, CBaseEntity *it) const
{
	if (this->m_MainAction == nullptr) {
		return QueryResponse::DONTCARE;
	}
	
	Action<T> *action = this->m_MainAction;
	while (action->m_ActionChild != nullptr) {
		action = action->m_ActionChild;
	}
	
	do {
		Action<T> *parent = action->m_ParentAction;
		
		while (action != nullptr) {
			QueryResponse response = action->IsHindrance(nextbot, it);
			if (response != QueryResponse::DONTCARE) {
				return response;
			}
			
			action = action->m_ActionWeSuspended;
		}
		
		action = parent;
	} while (action != nullptr);
	
	return QueryResponse::DONTCARE;
}

template<class T> Vector Behavior<T>::SelectTargetPoint(const INextBot *nextbot, const CBaseCombatCharacter *them) const
{
	if (this->m_MainAction == nullptr) {
		return vec3_origin;
	}
	
	Action<T> *action = this->m_MainAction;
	while (action->m_ActionChild != nullptr) {
		action = action->m_ActionChild;
	}
	
	do {
		Action<T> *parent = action->m_ParentAction;
		
		while (action != nullptr) {
			Vector v = action->SelectTargetPoint(nextbot, them);
			if (v != vec3_origin) {
				return v;
			}
			
			action = action->m_ActionWeSuspended;
		}
		
		action = parent;
	} while (action != nullptr);
	
	return vec3_origin;
}

template<class T> QueryResponse Behavior<T>::IsPositionAllowed(const INextBot *nextbot, const Vector& v1) const
{
	if (this->m_MainAction == nullptr) {
		return QueryResponse::DONTCARE;
	}
	
	Action<T> *action = this->m_MainAction;
	while (action->m_ActionChild != nullptr) {
		action = action->m_ActionChild;
	}
	
	do {
		Action<T> *parent = action->m_ParentAction;
		
		while (action != nullptr) {
			QueryResponse response = action->IsPositionAllowed(nextbot, v1);
			if (response != QueryResponse::DONTCARE) {
				return response;
			}
			
			action = action->m_ActionWeSuspended;
		}
		
		action = parent;
	} while (action != nullptr);
	
	return QueryResponse::DONTCARE;
}

template<class T> const CKnownEntity *Behavior<T>::SelectMoreDangerousThreat(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const
{
	if (this->m_MainAction == nullptr) {
		return nullptr;
	}
	
	Action<T> *action = this->m_MainAction;
	while (action->m_ActionChild != nullptr) {
		action = action->m_ActionChild;
	}
	
	do {
		Action<T> *parent = action->m_ParentAction;
		
		while (action != nullptr) {
			const CKnownEntity *known = action->SelectMoreDangerousThreat(nextbot, them, threat1, threat2);
			if (known != nullptr) {
				return known;
			}
			
			action = action->m_ActionWeSuspended;
		}
		
		action = parent;
	} while (action != nullptr);
	
	return QueryResponse::DONTCARE;
}


template<class T> void Behavior<T>::Update(T *actor, float f1)
{
	if (actor == nullptr || this->m_MainAction == nullptr) {
		return;
	}
	
	this->m_Actor = actor;
	
	ActionResult<T> result = this->m_MainAction->InvokeUpdate(actor, this, f1);
	this->m_MainAction = this->m_MainAction->ApplyResult(actor, this, result);
	
	if (this->m_MainAction != nullptr && actor->IsDebugging(1)) {
		CFmtStrN<256> fmtstr;
		actor->DisplayDebugText(fmtstr.sprintf("%s: %s",
			this->m_strName.m_szBuf, this->m_MainAction->DebugString()))
	}
	
	this->m_Actions.PurgeAndDeleteElements();
}
