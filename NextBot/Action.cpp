/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: actions
 */


template<class T>
Action<T>::Action(/* TODO ??? */)
{
	// TODO
}

template<class T>
Action<T>::~Action()
{
	// TODO
}


template <class T>
INextBotEventResponder *Action<T>::FirstContainedResponder() const
{
	return this->m_ActionChild;
}

template <class T>
INextBotEventResponder *Action<T>::NextContainedResponder(INextBotEventResponder *prev) const
{
	return nullptr;
}


// ...


template <class T>
ActionResult<T> Action<T>::OnStart(T *actor, Action<T> *action)
{
	// TODO
}

template <class T>
ActionResult<T> Action<T>::Update(T *actor, float f1)
{
	// TODO
}

template <class T>
void Action<T>::OnEnd(T *actor, Action<T> *action)
{
	// TODO
}


template <class T>
ActionResult<T> Action<T>::OnSuspend(T *actor, Action<T> *action)
{
	// TODO
}

template <class T>
ActionResult<T> Action<T>::OnResume(T *actor, Action<T> *action)
{
	// TODO
}


template <class T>
Action<T> *Action<T>::InitialContainedAction(T *actor)
{
	return nullptr;
}


// ...


// inline function; not inlined in L4D binary
template <class T>
void Action<T>::StorePendingEventResult(const EventDesiredResult<T>& result, const char *s1)
{
	// TODO: verify that this L4D code is still valid in TF2
	
	if (result.transition != ActionTransition::CONTINUE) {
		ResultSeverity severity = result.severity;
		
		if (severity > this->m_Result.severity ||
			(severity == this->m_Result.severity &&
			this->m_Result.transition == ActionTransition::CONTINUE2)) {
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


template <class T>
Action<T> *Action<T>::ApplyResult(T *actor, Behavior<T> *behavior, ActionResult<T> result)
{
	if (result.transition == ActionTransition::CHANGE_TO) {
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
	} else if (result.transition == ActionTransition::SUSPEND_FOR) {
		
		
		// return
	} else if (result.transition == ActionTransition::DONE) {
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
		/* ActionTransition::CONTINUE */
		return this;
	}
}


template <class T>
ActionResult<T> Action<T>::InvokeOnStart(T *actor, Behavior<T> *behavior, Action<T> *action1, Action<T> *action2)
{
	// TODO
	
	// SUSPEND_FOR:
	// action1 = action which was suspended for us
	// action2 = action which was suspended for us
	
	// SUSPEND_FOR + DONE:
	// action1 = the suspended action's previously suspended action, if any
	// action2 = the suspended action's previously suspended action, if any
	
	// CHANGE_TO:
	// action1 = action which ended for us
	// action2 = the ended action's previously suspended action, if any
}

template <class T>
ActionResult<T> Action<T>::InvokeUpdate(T *actor, Behavior<T> *behavior, float f1)
{
	// TODO
	
	// f1 = ???
}

template <class T>
void Action<T>::InvokeOnEnd(T *actor, Behavior<T> *behavior, Action<T> *action)
{
	// TODO
	
	// DONE:
	// action = the action we previously suspended, if any
	
	// CHANGE_TO:
	// action = the action we're changing to
}


template <class T>
ActionResult<T> Action<T>::InvokeOnResume(T *actor, Behavior<T> *behavior, Action<T> *action)
{
	// TODO
	
	// DONE:
	// action = the action that previously suspended us, who just ended
}

template <class T>
Action<T> *Action<T>::InvokeOnSuspend(T *actor, Behavior<T> *behavior, Action<T> *action)
{
	// TODO
	
	// SUSPEND_FOR:
	// action = the action we're suspending for
}
