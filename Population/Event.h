/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Population: entity IO event logic
 */


struct EventInfo
{
	CFmtStrN<256> target; // +0x000
	CFmtStrN<256> action; // +0x10c
};


EventInfo *ParseEvent(KeyValues *kv);
void FireEvent(EventInfo *info, const char *name);
