/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: contextual queries
 */


class IContextualQuery
{
public:
	enum QueryResponse
	{
		// this enum is based entirely on guesswork!
		QUERY_NO       = 0,
		QUERY_YES      = 1,
		QUERY_DONTCARE = 2,
	};
	
	virtual ~IContextualQuery();
	
	virtual QueryResponse ShouldPickUp(const INextBot *me, CBaseEntity *it) const;
	virtual QueryResponse ShouldHurry(const INextBot *me) const;
	virtual QueryResponse ShouldRetreat(const INextBot *me) const;
	virtual QueryResponse ShouldAttack(const INextBot *me, const CKnownEntity *threat) const;
	virtual QueryResponse IsHindrance(const INextBot *me, CBaseEntity *it) const;
	virtual Vector SelectTargetPoint(const INextBot *me, const CBaseCombatCharacter *them) const;
	virtual QueryResponse IsPositionAllowed(const INextBot *me, const Vector& v1) const;
	virtual const CKnownEntity *SelectMoreDangerousThreat(const INextBot *me, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const;
};
