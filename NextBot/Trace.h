/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: trace stuff
 */


bool IgnoreActorsTraceFilterFunction(IHandleEntity *pHandleEntity, int contentsMask);

class NextBotTraceFilterIgnoreActors : public CTraceFilterSimple
{
public:
	NextBotTraceFilterIgnoreActors(CBaseEntity *ent)
		: CTraceFilterSimple(ent, COLLISION_GROUP_NONE,
			IgnoreActorsTraceFilterFunction)
	{
	}
};


class NextBotTraceFilterOnlyActors : public CTraceFilterSimple
{
	// TODO
};


class NextBotTraversableTraceFilter : public CTraceFilterSimple
{
	// TODO
};


bool VisionTraceFilterFunction(IHandleEntity *pHandleEntity, int contentsMask);

class NextBotVisionTraceFilter : public CTraceFilterSimple
{
public:
	NextBotVisionTraceFilter(CBaseEntity *ent)
		: CTraceFilterSimple(ent, COLLISION_GROUP_NONE,
			VisionTraceFilterFunction)
	{
	}
};


class GroundLocomotionCollisionTraceFilter : public CTraceFilterSimple
{
	// TODO
};
