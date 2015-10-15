/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: item schema attributes
 */


/* sizeof: ~0x3c */
struct CEconItemAttributeDefinition
{
	CEconItemAttributeDefinition();
	
	bool BInitFromKV(KeyValues *kv, CUtlVector<CUtlString> *errors);
	
	
	KeyValues *m_KeyValues; // +0x00
	
	// 00 dword
	// 04 ???
	// 08 dword
	// 0c byte
	// 0d byte
	// 0e byte
	// 0f byte
	// 10 byte
	// 14 dword
	// 18 dword
	// 1c dword
	// 20 dword
	// 24 dword
	// 28 dword
	// 2c dword
	// 30 byte
	// 31 byte
	// 34 dword
	// 38 dword
};


/* sizeof: 0x8 */
struct static_attrib_t
{
	// TODO +0x00
	// TODO +0x04
	
	bool BInitFromKV_SingleLine(const char *name, KeyValues *kv, CUtlVector<CUtlString> *errors, bool/* TODO */);
};


/* sizeof: ??? */
struct CTFBot::EventChangeAttributes_t::item_attributes_t
{
	CUtlString ???
	
};
