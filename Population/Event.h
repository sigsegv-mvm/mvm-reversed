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
	// TODO
}
