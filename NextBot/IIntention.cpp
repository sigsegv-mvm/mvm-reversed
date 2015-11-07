/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: intention component
 */


#define FOR_EACH_RESPONDER_QUERY(_func, ...) \
	FOR_EACH_RESPONDER { \
		IContextualQuery *q = dynamic_cast<IContextualQuery *>(responder); \
		if (q != nullptr) { \
			QueryResponse response = q->_func(__VA_ARGS__); \
			if (response != QueryResponse::DONTCARE) { \
				return response; \
			} \
		} \
	} \
	return QueryResponse::DONTCARE;


IIntention::IIntention(INextBot *nextbot)
	: INextBotComponent(nextbot)
{
}

IIntention::~IIntention()
{
}


void IIntention::Reset()
{
	INextBotComponent::Reset();
}

void IIntention::Update()
{
}


QueryResponse IIntention::ShouldPickUp(const INextBot *nextbot, CBaseEntity *it) const
{
	FOR_EACH_RESPONDER_QUERY(ShouldPickUp, nextbot, it);
}

QueryResponse IIntention::ShouldHurry(const INextBot *nextbot) const
{
	FOR_EACH_RESPONDER_QUERY(ShouldHurry, nextbot);
}

QueryResponse IIntention::ShouldRetreat(const INextBot *nextbot) const
{
	FOR_EACH_RESPONDER_QUERY(ShouldRetreat, nextbot);
}

QueryResponse IIntention::ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const
{
	FOR_EACH_RESPONDER_QUERY(ShouldAttack, nextbot, threat);
}

QueryResponse IIntention::IsHindrance(const INextBot *nextbot, CBaseEntity *it) const
{
	FOR_EACH_RESPONDER_QUERY(IsHindrance, nextbot, it);
}

Vector IIntention::SelectTargetPoint(const INextBot *nextbot, const CBaseCombatCharacter *them) const
{
	Vector vec;
	
	if (this->FirstContainedResponder() != nullptr) {
		FOR_EACH_RESPONDER {
			IContextualQuery *q = dynamic_cast<IContextualQuery *>(responder);
			if (q != nullptr) {
				vec = q->SelectTargetPoint(nextbot, them);
				if (vec != vec3_origin) {
					break;
				}
			}
		}
		
		return vec;
	} else {
		// TODO
	}
}

QueryResponse IIntention::IsPositionAllowed(const INextBot *nextbot, const Vector& v1) const
{
	FOR_EACH_RESPONDER_QUERY(IsPositionAllowed, nextbot, v1);
}

const CKnownEntity *IIntention::SelectMoreDangerousThreat(const INextBot *nextbot, const CBaseCombatCharacter *them, const CKnownEntity *threat1, const CKnownEntity *threat2) const
{
	// TODO
}
