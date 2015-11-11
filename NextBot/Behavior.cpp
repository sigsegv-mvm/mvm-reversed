/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: behaviors
 */


template<class T> Behavior<T>::Behavior(Action<T> *mainaction)
	: m_MainAction(mainaction)
{
	this->m_Actor = nullptr;
}

template<class T> Behavior<T>::~Behavior()
{
	// TODO
}


template<class T> INextBotEventResponder *Behavior<T>::FirstContainedResponder() const
{
	// TODO
}

template<class T> INextBotEventResponder *Behavior<T>::NextContainedResponder(INextBotEventResponder *prev) const
{
	// TODO
}


template<class T> QueryResponse Behavior<T>::ShouldPickUp(const INextBot *nextbot, CBaseEntity *it) const
{
	// TODO
}

template<class T> QueryResponse Behavior<T>::ShouldHurry(const INextBot *nextbot) const
{
	// TODO
}

template<class T> QueryResponse Behavior<T>::ShouldRetreat(const INextBot *nextbot) const
{
	// TODO
}

template<class T> QueryResponse Behavior<T>::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	// TODO
}

template<class T> QueryResponse Behavior<T>::IsHindrance(const INextBot *nextbot, CBaseEntity *it) const
{
	// TODO
}

template<class T> Vector Behavior<T>::SelectTargetPoint(const INextBot *nextbot, const CBaseCombatCharacter *them) const
{
	// TODO
}

template<class T> QueryResponse Behavior<T>::IsPositionAllowed(const INextBot *nextbot, const Vector& v1) const
{
	// TODO
}

template<class T> const CKnownEntity *Behavior<T>::SelectMoreDangerousThreat(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const
{
	// TODO
}


template<class T> void Behavior<T>::Update(T *actor, float f1)
{
	// TODO
}
