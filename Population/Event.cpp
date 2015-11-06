/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * Population: entity IO event logic
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
				info->target.sprintf(subkey->GetString(nullptr));
			} else if (V_stricmp(name, "Action") == 0) {
				info->action.sprintf(subkey->GetString(nullptr));
			} else {
				Warning("Unknown field '%s' in WaveSpawn event definition.\n",
					subkey->GetString(nullptr));
				delete info;
				return nullptr;
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
	if (info == nullptr) {
		return;
	}
	
	const char *target = info->target.Get();
	const char *action = info->action.Get();
	
	CBaseEntity *ent = gEntList->FindEntityByName(nullptr, target);
	if (ent != nullptr) {
		g_EventQueue->AddEvent(ent, action, 0.0f, nullptr, nullptr);
	} else {
		Warning("WaveSpawnPopulator: Can't find target entity '%s' for %s\n",
			target, name);
	}
}
