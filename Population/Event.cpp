/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: Entity IO event logic
 */


// fastcall
// eax: kv
EventInfo *ParseEvent(KeyValues *kv)
{
	EventInfo *info = new EventInfo();
	
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Target") == 0) {
				info->target.sprintf(subkey->GetString(NULL));
			} else if (V_stricmp(name, "Action") == 0) {
				info->action.sprintf(subkey->GetString(NULL));
			} else {
				Warning("Unknown field '%s' in WaveSpawn event definition.\n",
					subkey->GetString(NULL));
				delete info;
				return NULL;
			}
		}
	}
	
	return info;
}

// fastcall
// eax: info
// edx: name
void FireEvent(EventInfo *info, const char *name)
{
	if (info == NULL) {
		return;
	}
	
	const char *target = info->target.Get();
	const char *action = info->action.Get();
	
	CBaseEntity *ent = gEntList->FindEntityByName(NULL, target);
	if (ent != NULL) {
		g_EventQueue->AddEvent(ent, action, 0.0f, NULL, NULL);
	} else {
		Warning("WaveSpawnPopulator: Can't find target entity '%s' for %s\n",
			target, name);
	}
}
