/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: actions
 */


template<class T> Action<T>::Action(/* TODO ??? */)
{
	// TODO
}

template<class T> Action<T>::~Action()
{
	// TODO
}


template<class T> INextBotEventResponder *Action<T>::FirstContainedResponder() const
{
	return this->m_ActionChild;
}

template<class T> INextBotEventResponder *Action<T>::NextContainedResponder(INextBotEventResponder *prev) const
{
	return nullptr;
}


template<class T> void Action<T>::OnLeaveGround(CBaseEntity *ent)
{
	// TODO
}

template<class T> void Action<T>::OnLandOnGround(CBaseEntity *ent)
{
	// TODO
}


template<class T> void Action<T>::OnContact(CBaseEntity *ent, CGameTrace *trace)
{
	// TODO
}


template<class T> void Action<T>::OnMoveToSuccess(const Path *path)
{
	// TODO
}

template<class T> void Action<T>::OnMoveToFailure(const Path *path, MoveToFailureType fail)
{
	// TODO
}


template<class T> void Action<T>::OnStuck()
{
	// TODO
}

template<class T> void Action<T>::OnUnStuck()
{
	// TODO
}


template<class T> void Action<T>::OnPostureChanged()
{
	// TODO
}

template<class T> void Action<T>::OnAnimationActivityComplete(int i1)
{
	// TODO
}

template<class T> void Action<T>::OnAnimationActivityInterrupted(int i1)
{
	// TODO
}

template<class T> void Action<T>::OnAnimationEvent(animevent_t *a1)
{
	// TODO
}


template<class T> void Action<T>::OnIgnite()
{
	// TODO
}

template<class T> void Action<T>::OnInjured(const CTakeDamageInfo& info)
{
	// TODO
}

template<class T> void Action<T>::OnKilled(const CTakeDamageInfo& info)
{
	// TODO
}

template<class T> void Action<T>::OnOtherKilled(CBaseCombatCharacter *who, const CTakeDamageInfo& info)
{
	// TODO
}


template<class T> void Action<T>::OnSight(CBaseEntity *ent)
{
	// TODO
}

template<class T> void Action<T>::OnLostSight(CBaseEntity *ent)
{
	// TODO
}


template<class T> void Action<T>::OnSound(CBaseEntity *ent, const Vector& v1, KeyValues *kv)
{
	// TODO
}

template<class T> void Action<T>::OnSpokeConcept(CBaseCombatCharacter *who, const char *s1, AI_Response *response)
{
	// TODO
}

template<class T> void Action<T>::OnWeaponFired(CBaseCombatCharacter *who, CBaseCombatWeapon *weapon)
{
	// TODO
}


template<class T> void Action<T>::OnNavAreaChanged(CNavArea *area1, CNavArea *area2)
{
	// TODO
}

template<class T> void Action<T>::OnModelChanged()
{
	// TODO
}

template<class T> void Action<T>::OnPickUp(CBaseEntity *ent, CBaseCombatCharacter *who)
{
	// TODO
}

template<class T> void Action<T>::OnDrop(CBaseEntity *ent)
{
	// TODO
}

template<class T> void Action<T>::OnActorEmoted(CBaseCombatCharacter *who, int i1)
{
	// TODO
}


template<class T> void Action<T>::OnCommandAttack(CBaseEntity *ent)
{
	// TODO
}

template<class T> void Action<T>::OnCommandApproach(const Vector& v1, float f1)
{
	// TODO
}

template<class T> void Action<T>::OnCommandApproach(CBaseEntity *ent)
{
	// TODO
}

template<class T> void Action<T>::OnCommandRetreat(CBaseEntity *ent, float f1)
{
	// TODO
}

template<class T> void Action<T>::OnCommandPause(float f1)
{
	// TODO
}

template<class T> void Action<T>::OnCommandResume()
{
	// TODO
}

template<class T> void Action<T>::OnCommandString(const char *cmd)
{
	// TODO
}


template<class T> void Action<T>::OnShoved(CBaseEntity *ent)
{
	// TODO
}

template<class T> void Action<T>::OnBlinded(CBaseEntity *ent)
{
	// TODO
}


template<class T> void Action<T>::OnTerritoryContested(int i1)
{
	// TODO
}

template<class T> void Action<T>::OnTerritoryCaptured(int i1)
{
	// TODO
}

template<class T> void Action<T>::OnTerritoryLost(int i1)
{
	// TODO
}


template<class T> void Action<T>::OnWin()
{
	// TODO
}

template<class T> void Action<T>::OnLose()
{
	// TODO
}


template<class T> bool Action<T>::IsNamed(const char *name) const
{
	const char *my_name = this->GetName();
	return ((name == my_name) || (V_stricmp(name, my_name) == 0));
}

template<class T> char *Action<T>::GetFullName() const
{
	static char strconst[256];
	const char *names[66];
	
	strconst[0] = '\0';
	
	if (this != nullptr) {
		Action<T> *action = this;
		int count = 0;
		
		do {
			names[count++] = action->GetName();
			action = action->m_ActionParent;
		} while (i <= 63 && action != nullptr);
		
		for (int i = count - 1; i != 0; --i) {
			V_strncat(strconst, names[i], sizeof(strconst));
			V_strncat(strconst, "/", sizeof(strconst));
		}
	}
	
	V_strncat(strconst, names[0], sizeof(strconst));
	return strconst;
}


template<class T> ActionResult<T> Action<T>::OnStart(T *actor, Action<T> *action)
{
	return ActionResult<T>::Continue();
}

template<class T> ActionResult<T> Action<T>::Update(T *actor, float f1)
{
	return ActionResult<T>::Continue();
}

template<class T> void Action<T>::OnEnd(T *actor, Action<T> *action)
{
}


template<class T> ActionResult<T> Action<T>::OnSuspend(T *actor, Action<T> *action)
{
	return ActionResult<T>::Continue();
}

template<class T> ActionResult<T> Action<T>::OnResume(T *actor, Action<T> *action)
{
	return ActionResult<T>::Continue();
}


template<class T> Action<T> *Action<T>::InitialContainedAction(T *actor)
{
	return nullptr;
}


template<class T> EventDesiredResult<T> Action<T>::OnLeaveGround(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnLandOnGround(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnContact(T *actor, CBaseEntity *ent, CGameTrace *trace)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnMoveToSuccess(T *actor, const Path *path)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnMoveToFailure(T *actor, const Path *path, MoveToFailureType fail)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnStuck(T *actor)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnUnStuck(T *actor)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnPostureChanged(T *actor)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnAnimationActivityComplete(T *actor, int i1)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnAnimationActivityInterrupted(T *actor, int i1)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnAnimationEvent(T *actor, animevent_t *a1)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnIgnite(T *actor)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnInjured(T *actor, const CTakeDamageInfo& info)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnKilled(T *actor, const CTakeDamageInfo& info)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnOtherKilled(T *actor, CBaseCombatCharacter *who, const CTakeDamageInfo& info)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnSight(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnLostSight(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnSound(T *actor, CBaseEntity *ent, const Vector& v1, KeyValues *kv)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnSpokeConcept(T *actor, CBaseCombatCharacter *who, const char *s1, AI_Response *response)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnWeaponFired(T *actor, CBaseCombatCharacter *who, CBaseCombatWeapon *weapon)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnNavAreaChanged(T *actor, CNavArea *area1, CNavArea *area2)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnModelChanged(T *actor)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnPickUp(T *actor, CBaseEntity *ent, CBaseCombatCharacter *who)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnDrop(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnActorEmoted(T *actor, CBaseCombatCharacter *who, int i1)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnCommandAttack(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnCommandApproach(T *actor, const Vector& v1, float f1)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnCommandApproach(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnCommandRetreat(T *actor, CBaseEntity *ent, float f1)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnCommandPause(T *actor, float f1)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnCommandResume(T *actor)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnCommandString(T *actor, const char *cmd)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnShoved(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnBlinded(T *actor, CBaseEntity *ent)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnTerritoryContested(T *actor, int i1)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnTerritoryCaptured(T *actor, int i1)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnTerritoryLost(T *actor, int i1)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> EventDesiredResult<T> Action<T>::OnWin(T *actor)
{
	return EventDesiredResult<T>::Continue();
}

template<class T> EventDesiredResult<T> Action<T>::OnLose(T *actor)
{
	return EventDesiredResult<T>::Continue();
}


template<class T> bool Action<T>::IsAbleToBlockMovementOf(const INextBot *nextbot) const
{
	return true;
}


// inline function; not inlined in L4D binary
template<class T> void Action<T>::StorePendingEventResult(const EventDesiredResult<T>& result, const char *s1)
{
	// TODO: verify that this L4D code is still valid in TF2
	
	if (result.transition != ActionTransition<T>::CONTINUE) {
		ResultSeverity severity = result.severity;
		
		if (severity > this->m_Result.severity ||
			(severity == this->m_Result.severity &&
			this->m_Result.transition == ActionTransition<T>::CONTINUE2)) {
			if (severity != 0) {
				if (this->m_Result.action != nullptr) {
					delete this->m_Result.action;
				}
			}
			
			this->m_Result = result;
			return;
		}
		
		if (severity == ResultSeverity::CRITICAL && developer != 0) {
			DevMsg("%3.2f: WARNING: %s::%s() RESULT_CRITICAL collision\n",
				gpGlobals->curtime, this->GetName(), s1);
		}
		
		if (result.action != nullptr) {
			delete result.action;
		}
	}
}


template<class T> Action<T> *Action<T>::ApplyResult(T *actor, Behavior<T> *behavior, ActionResult<T> result)
{
	if (result.transition == ActionTransition<T>::CHANGE_TO) {
		if (result.action == nullptr) {
			DevMsg("Error: Attempted CHANGE_TO to a NULL Action\n");
			return this;
		}
		
		if (actor->IsDebugging(1) /*|| TODO */) {
			actor->DebugConColorMsg(1, COLOR_LTYELLOW, "%3.2f: %s:%s: ",
				gpGlobals->curtime, actor->GetDebugIdentifier(), behavior->m_StrUnknown());
			actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
			
			if (result.action == this) {
				actor->DebugConColorMsg(1, COLOR_RED, "START ");
				actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
			} else {
				actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
				actor->DebugConColorMsg(1, COLOR_RED, " CHANGE_TO ");
				actor->DebugConColorMsg(1, COLOR_WHITE, result.action->GetName());
			}
			
			if (result.reason != nullptr) {
				actor->DebugConColorMsg(1, COLOR_LTGREEN, "  (%s)\n",
					result.reason);
			} else {
				actor->DebugConColorMsg(1, COLOR_WHITE, "\n");
			}
		}
		
		this->InvokeOnEnd(actor, behavior, result.action);
		ActionResult<T> result2 =
			result.action->InvokeOnStart(actor, behavior, this, this->m_ActionWeSuspended);
		
		if (result.action != this) {
			behavior->m_Actions.AddToTail(this);
		}
		
		if (actor->IsDebugging(1)) {
			result.action->PrintStateToConsole();
		}
		
		return result.action->ApplyResult(actor, behavior, result2);
	} else if (result.transition == ActionTransition<T>::SUSPEND_FOR) {
		Action<T> *action = this;
		while (action->m_ActionSuspendedUs != nullptr) {
			action = action->m_ActionSuspendedUs;
		}
		
		if (actor->IsDebugging(1) /*|| TODO */) {
			actor->DebugConColorMsg(1, COLOR_LTYELLOW, "%3.2f: %s:%s: ",
				gpGlobals->curtime, actor->GetDebugIdentifier(), behavior->m_StrUnknown());
			actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
			
			actor->DebugConColorMsg(1, COLOR_MAGENTA, " caused ");
			actor->DebugConColorMsg(1, COLOR_WHITE, action->GetName());
			
			actor->DebugConColorMsg(1, COLOR_MAGENTA, " to SUSPEND_FOR ");
			actor->DebugConColorMsg(1, COLOR_WHITE, result.action->GetName());
			
			if (result.reason != nullptr) {
				actor->DebugConColorMsg(1, COLOR_LTGREEN, "  (%s)\n",
					result.reason);
			} else {
				actor->DebugConColorMsg(1, COLOR_WHITE, "\n");
			}
		}
		
		Action<T> *next = action->InvokeOnSuspend(actor, behavior, result.action);
		ActionResult<T> result2 =
			result.action->InvokeOnStart(actor, behavior, next, next);
		
		if (actor->IsDebugging(1)) {
			result.action->PrintStateToConsole();
		}
		
		return result.action->ApplyResult(actor, behavior, result2);
	} else if (result.transition == ActionTransition<T>::DONE) {
		// TODO: name for m_StrUnknown
		
		this->InvokeOnEnd(actor, behavior, this->m_ActionWeSuspended);
		
		if (actor->IsDebugging(1) /*|| TODO */) {
			actor->DebugConColorMsg(1, COLOR_LTYELLOW, "%3.2f: %s:%s: ",
				gpGlobals->curtime, actor->GetDebugIdentifier(), behavior->m_StrUnknown());
			actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
			
			if (this->m_ActionWeSuspended != nullptr) {
				actor->DebugConColorMsg(1, COLOR_GREEN, " DONE, RESUME ");
				actor->DebugConColorMsg(1, COLOR_WHITE, this->m_ActionWeSuspended->GetName());
			} else {
				actor->DebugConColorMsg(1, COLOR_GREEN, " DONE.");
			}
			
			if (result.reason != nullptr) {
				actor->DebugConColorMsg(1, COLOR_LTGREEN, "  (%s)\n",
					result.reason);
			} else {
				actor->DebugConColorMsg(1, COLOR_WHITE, "\n");
			}
		}
		
		if (this->m_ActionWeSuspended != nullptr) {
			ActionResult<T> result2 =
				this->m_ActionWeSuspended->InvokeOnResume(actor, behavior, this);
			
			if (actor->IsDebugging(1)) {
				this->m_ActionWeSuspended->PrintStateToConsole();
			}
			
			behavior->m_Actions.AddToTail(this);
			return this->m_ActionWeSuspended->ApplyResult(actor, behavior, result2);
		} else {
			behavior->m_Actions.AddToTail(this);
			return nullptr;
		}
	} else {
		/* ActionTransition<T>::CONTINUE */
		return this;
	}
}


template<class T> ActionResult<T> Action<T>::InvokeOnStart(T *actor, Behavior<T> *behavior, Action<T> *action1, Action<T> *action2)
{
	// SUSPEND_FOR:
	// action1 = action which was suspended for us
	// action2 = action which was suspended for us
	
	// SUSPEND_FOR + DONE:
	// action1 = the suspended action's previously suspended action, if any
	// action2 = the suspended action's previously suspended action, if any
	
	// CHANGE_TO:
	// action1 = action which ended for us
	// action2 = the ended action's previously suspended action, if any
	
	
	if (actor->IsDebugging(1) /*|| TODO */) {
		actor->DebugConColorMsg(1, COLOR_LTYELLOW, "%3.2f: %s:%s: ",
			gpGlobals->curtime, actor->GetDebugIdentifier(), behavior->m_StrUnknown());
		
		actor->DebugConColorMsg(1, COLOR_GREEN, " STARTING ");
		actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
		actor->DebugConColorMsg(1, COLOR_WHITE, "\n");
	}
	
	this->m_bStarted = true;
	this->m_Actor    = actor;
	this->m_Behavior = behavior;
	
	Action<T> *parent;
	if (action1 != nullptr) {
		parent = action1->m_ActionParent;
		this->m_ActionParent = parent;
	} else {
		parent = this->m_ActionParent;
	}
	
	if (parent != nullptr) {
		parent->m_ActionChild = this;
	}
	
	this->m_ActionWeSuspended = action2;
	if (action2 != nullptr) {
		action2->m_ActionSuspendedUs = this;
	}
	
	this->m_ActionSuspendedUs = nullptr;
	
	Action<T> *child = this->InitialContainedAction(actor);
	this->m_ActionChild = child;
	if (this->m_ActionChild != nullptr) {
		child->m_ActionParent = this;
		this->m_ActionChild = this->m_ActionChild->ApplyResult(actor, behavior,
			ActionResult::ChangeTo(this->m_ActionChild, "Starting child Action"));
	}
	
	return this->OnStart(actor, action1);
}

template<class T> ActionResult<T> Action<T>::InvokeUpdate(T *actor, Behavior<T> *behavior, float f1)
{
	// f1 = ???
	
	
	Action<T> *suspended = this;
	while ((suspended = suspended->m_ActionWeSuspended) != nullptr) {
		if (suspended->m_Result.transition == ActionTransition<T>::CHANGE_TO ||
			suspended->m_Result.transition == ActionTransition<T>::DONE) {
			return ActionResult<T>::Done("Out of scope");
		}
	}
	
	if (this->m_bStarted) {
		if (this->m_Result.transition > ActionTransition<T>::CONTINUE) {
			suspended = this;
			while (suspended != nullptr) {
				if (suspended->m_Result.transition == ActionTransition::SUSPEND_FOR) {
					ActionResult<T> result = suspended->m_Result;
					this->m_Result = { 0, nullptr, nullptr, 0 };
					return result;
				}
				
				suspended = suspended->m_ActionWeSuspended;
			}
			
			if (this->m_ActionChild != nullptr) {
				ActionResult<T> result = this->m_ActionChild->InvokeUpdate(actor, behavior, f1);
				this->m_ActionChild = this->m_ActionChild->ApplyResult(actor, behavior, result);
			}
			
			VPROF_BUDGET(this->GetName(), "NextBot");
			return this->Update(actor, f1);
		} else {
			ActionResult<T> result = this->m_Result;
			this->m_Result = { 0, nullptr, nullptr, 0 };
			return result;
		}
	} else {
		return ActionTransition<T>::ChangeTo(this, "Starting Action");
	}
}

template<class T> void Action<T>::InvokeOnEnd(T *actor, Behavior<T> *behavior, Action<T> *action)
{
	// DONE:
	// action = the action we previously suspended, if any
	
	// CHANGE_TO:
	// action = the action we're changing to
	
	
	if (this->m_bStarted) {
		if (actor->IsDebugging(1) /*|| TODO */) {
			actor->DebugConColorMsg(1, COLOR_LTYELLOW, "%3.2f: %s:%s: ",
				gpGlobals->curtime, actor->GetDebugIdentifier(), behavior->m_StrUnknown());
			
			actor->DebugConColorMsg(1, COLOR_MAGENTA, " ENDING ");
			actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
			actor->DebugConColorMsg(1, COLOR_WHITE, "\n");
		}
		
		this->m_bStarted = false;
		
		if (this->m_ActionChild != nullptr) {
			Action<T> *suspended = this->m_ActionChild;
			do {
				suspended->InvokeOnEnd(actor, behavior, action);
				suspended = suspended->m_ActionWeSuspended;
			} while (suspended != nullptr);
		}
		
		this->OnEnd(actor, action);
		
		if (this->m_ActionSuspendedUs != nullptr) {
			this->m_ActionSuspendedUs->InvokeOnEnd(actor, behavior, action);
		}
	}
}


template<class T> ActionResult<T> Action<T>::InvokeOnResume(T *actor, Behavior<T> *behavior, Action<T> *action)
{
	// DONE:
	// action = the action that previously suspended us, who just ended
	
	
	if (actor->IsDebugging(1) /*|| TODO */) {
		actor->DebugConColorMsg(1, COLOR_LTYELLOW, "%3.2f: %s:%s: ",
			gpGlobals->curtime, actor->GetDebugIdentifier(), behavior->m_StrUnknown());
		
		actor->DebugConColorMsg(1, COLOR_MAGENTA, " RESUMING ");
		actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
		actor->DebugConColorMsg(1, COLOR_WHITE, "\n");
	}
	
	if (this->m_bSuspended && this->m_Result.transition > ActionTransition<T>::DONE) {
		this->m_bSuspended = false;
		this->m_ActionSuspendedUs = nullptr;
		
		if (this->m_ActionParent != nullptr) {
			this->m_ActionParent->m_ActionChild = this;
		}
		
		if (this->m_ActionChild != nullptr) {
			ActionResult<T> result = this->m_ActionChild->InvokeOnResume(actor, behavior, action);
			this->m_ActionChild = this->m_ActionChild->ApplyResult(actor, behavior, result);
		}
		
		return this->OnResume(actor, action);
	} else {
		return ActionResult<T>::Continue();
	}
}

template<class T> Action<T> *Action<T>::InvokeOnSuspend(T *actor, Behavior<T> *behavior, Action<T> *action)
{
	// SUSPEND_FOR:
	// action = the action we're suspending for
	
	
	if (actor->IsDebugging(1) /*|| TODO */) {
		actor->DebugConColorMsg(1, COLOR_LTYELLOW, "%3.2f: %s:%s: ",
			gpGlobals->curtime, actor->GetDebugIdentifier(), behavior->m_StrUnknown());
		
		actor->DebugConColorMsg(1, COLOR_MAGENTA, " SUSPENDING ");
		actor->DebugConColorMsg(1, COLOR_WHITE, this->GetName());
		actor->DebugConColorMsg(1, COLOR_WHITE, "\n");
	}
	
	if (this->m_ActionChild != nullptr) {
		this->m_ActionChild = this->m_ActionChild->InvokeOnSuspend(actor, behavior, action);
	}
	
	this->m_bSuspended = true;
	
	ActionResult<T> result = this->OnSuspend(actor, action);
	if (result.transition == ActionTransition<T>::DONE) {
		this->InvokeOnEnd(actor, behavior, nullptr);
		
		this->m_Behavior->AddToTail(this);
		
		return this->m_ActionWeSuspended;
	} else {
		return this;
	}
}


template<class T> char *Action<T>::BuildDecoratedName(char buf[256], const Action<T> *action) const
{
	V_strncat(s1, action->GetName(), sizeof(buf));
	
	if (action->m_ActionChild != nullptr) {
		V_strncat(buf, "( ", sizeof(buf));
		this->BuildDecoratedName(buf, action->m_ActionChild);
		V_strncat(buf, " )", sizeof(buf));
	}
	
	if (action->m_ActionWeSuspended != nullptr) {
		V_strncat(buf, "<<", sizeof(buf));
		this->BuildDecoratedName(buf, action->m_ActionWeSuspended);
	}
	
	return buf;
}

template<class T> char *Action<T>::DebugString() const
{
	static char strconst[256];
	
	Action<T> *action = this;
	while (action->m_ActionParent != nullptr) {
		action = action->m_ActionParent;
	}
	
	return this->BuildDecoratedName(strconst, action);
}

template<class T> void Action<T>::PrintStateToConsole() const
{
	// TODO
}
