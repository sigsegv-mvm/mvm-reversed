/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: Entity IO event logic
 */


struct Event
{
	CFmtStrN<256> target;
	CFmtStrN<256> action;
};


Event *ParseEvent(KeyValues *kv)
{
	Event *event = new Event();
	
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Target") == 0) {
				event->target.sprintf(subkey->GetString(NULL));
			} else if (V_stricmp(name, "Action") == 0) {
				event->action.sprintf(subkey->GetString(NULL));
			} else {
				Warning("Unknown field '%s' in WaveSpawn event definition.\n",
					subkey->GetString(NULL));
				delete event;
				return NULL;
			}
		}
	}
	
	return event;
}
