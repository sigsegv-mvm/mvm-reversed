/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: behaviors
 */


template<class T>
class Behavior : public INextBotEventResponder, public IContextualQuery
{
public:
	Behavior(Action<T> *mainaction);
	virtual ~Behavior();
	
	/* INextBotEventResponder overrides */
	virtual INextBotEventResponder *FirstContainedResponder() const override final;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *prev) const override final;
	
	/* IContextualQuery overrides */
	virtual QueryResponse ShouldPickUp(const INextBot *nextbot, CBaseEntity *it) const override final;
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override final;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override final;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override final;
	virtual QueryResponse IsHindrance(const INextBot *nextbot, CBaseEntity *it) const override final;
	virtual Vector SelectTargetPoint(const INextBot *nextbot, const CBaseCombatCharacter *them) const override final;
	virtual QueryResponse IsPositionAllowed(const INextBot *nextbot, const Vector& v1) const override final;
	virtual const CKnownEntity *SelectMoreDangerousThreat(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const override final;
	
	void Update(T *actor, float f1);
	
private:
	Action<T> *m_MainAction;                    // +0x08
	CFmtStrN<32> m_StrUnknown;                  // +0x0c
	T *m_Actor;                                 // +0x38
	CUtlVectorAutoPurge<Action<T> *> m_Actions; // +0x3c
};

template<> class Behavior<CBotNPCArcher>;
template<> class Behavior<CBotNPCDecoy>;
template<> class Behavior<CEyeballBoss>;
template<> class Behavior<CGhost>;
template<> class Behavior<CHeadlessHatman>;
template<> class Behavior<CMerasmus>;
template<> class Behavior<CSimpleBot>;
template<> class Behavior<CTFBot>;
template<> class Behavior<CTFRobotDestruction_Robot>;
template<> class Behavior<CZombie>;


// before these things, we need to get a skeleton for Action<>
// TODO: dredge up the constructor from where it's been inlined (corroborate with osx server.dylib)
// TODO: take a look at the dtor to see what it's doing other than just auto-destructing stuff
