/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/map_entities/tf_sentrygun.cpp
 */


// sizeof: 0x390
class CTFBotHintSentrygun : public CBaseTFBotHintEntity
{
public:
	CTFBotHintSentrygun();
	virtual ~CTFBotHintSentrygun();
	
	virtual UNKNOWN GetHintType() const;
	
	UNKNOWN IsAvailableForSelection(CTFPlayer *player) const;
	
	UNKNOWN OnSentryGunDestroyed(CBaseEntity *ent);
	
private:
	// 36c byte 0
	// 370 dword 0
	// 374 dword 0
	// 378 
	// 37c 
	// 380 dword -1
	// 384 dword 0
	// 388 
	// 38c dword -1
};
