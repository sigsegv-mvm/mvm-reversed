/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: Entity IO event logic
 */


struct EventInfo
{
	CFmtStrN<256> target; // +0x000
	CFmtStrN<256> action; // +0x10c
};


EventInfo *ParseEvent(KeyValues *kv);
void FireEvent(EventInfo *info, const char *name);
