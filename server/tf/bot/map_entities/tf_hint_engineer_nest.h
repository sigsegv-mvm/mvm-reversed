/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/map_entities/tf_hint_engineer_nest.h
 */


// sizeof: 0x398
class CTFBotHintEngineerNest : public CBaseTFBotHintEntity
{
public:
	CTFBotHintEngineerNest();
	virtual ~CTFBotHintEngineerNest();
	
	virtual UNKNOWN UpdateTransmitState() override;
	
	virtual UNKNOWN Spawn() override;
	
	virtual UNKNOWN GetHintType() const;
	
	UNKNOWN DetonateStateNest();
	
	UNKNOWN GetSentryHint() const;
	UNKNOWN GetTeleporterHint() const;
	
	UNKNOWN IsStaleNest() const;
	
private:
	UNKNOWN HintThink();
	UNKNOWN HintTeleporterThink();
	
	UNKNOWN DetonateObjectsFromHints(const CUtlVector<CHandle<CBaseTFBotHintEntity>>& hints);
	UNKNOWN GetHint(const CUtlVector<CHandle<CBaseTFBotHintEntity>>& hints);
	
	// 36c dword 0
	// 370 dword 0
	// 374 dword 0
	// 378 dword 0
	// 37c dword 0
	// 380 dword 0
	// 384 dword 0
	// 388 dword 0
	// 38c dword 0
	// 390 dword 0
	// 394 byte 0
};
