/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/map_entities/tf_hint.h
 */


// sizeof: 0x36c
class CTFBotHint : public CBaseEntity
{
public:
	CTFBotHint();
	virtual ~CTFBotHint();
	
	virtual UNKNOWN Spawn() override;
	
	virtual UNKNOWN UpdateOnRemove() override;
	
	// TODO: InputEnable
	// TODO: InputDisable
	
	UNKNOWN IsFor(CTFBot *bot) const;
	
private:
	UNKNOWN UpdateNavDecoration();
	
	// 360 
	// 364 
	// 368 byte 0
};
