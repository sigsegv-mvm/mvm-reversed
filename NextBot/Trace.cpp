/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: trace stuff
 */


bool IgnoreActorsTraceFilterFunction(IHandleEntity *pHandleEntity, int contentsMask)
{
	CBaseEntity *ent = EntityFromEntityHandle(pHandleEntity);
	return !ent->IsCombatCharacter();
}

bool VisionTraceFilterFunction(IHandleEntity *pHandleEntity, int contentsMask)
{
	CBaseEntity *ent = EntityFromEntityHandle(pHandleEntity);
	if (ent->IsCombatCharacter()) {
		return false;
	} else {
		return ent->BlocksLOS();
	}
}
