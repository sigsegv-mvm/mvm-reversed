/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/map_entities/tf_hint_entity.h
 */


// TODO: ITFBotHintEntityAutoList


// sizeof: 0x36c
class CBaseTFBotHintEntity : public CPointEntity, public ITFBotHintEntityAutoList
{
public:
	CBaseTFBotHintEntity();
	virtual ~CBaseTFBotHintEntity();
	
	// TODO: InputEnable
	// TODO: InputDisable
	
	UNKNOWN OwnerObjectFinishBuilding() const;
	UNKNOWN OwnerObjectHasNoOwner() const;
	
protected:
	// 364 byte 0
	// 368 dword -1
};
