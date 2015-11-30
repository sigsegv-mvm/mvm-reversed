/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/nav_mesh/tf_nav_area.h
 */


// TODO: figure out if this belongs here or elsewhere
enum TFNavAttributeType : int
{
	BLUE_SETUP_GATE             = (1 << 11),
	RED_SETUP_GATE              = (1 << 12),
	
	BLOCKED_AFTER_POINT_CAPTURE = (1 << 13),
	BLOCKED_UNTIL_POINT_CAPTURE = (1 << 14),
	
	BLUE_ONE_WAY_DOOR           = (1 << 15),
	RED_ONE_WAY_DOOR            = (1 << 16),
	
	WITH_SECOND_POINT           = (1 << 17),
	WITH_THIRD_POINT            = (1 << 18),
	WITH_FOURTH_POINT           = (1 << 19),
	WITH_FIFTH_POINT            = (1 << 20),
	
	SNIPER_SPOT                 = (1 << 21),
	SENTRY_SPOT                 = (1 << 22),
	
	NO_SPAWNING                 = (1 << 25),
	RESCUE_CLOSET               = (1 << 26),
	
	DOOR_NEVER_BLOCKS           = (1 << 28),
	DOOR_ALWAYS_BLOCKS          = (1 << 29),
	UNBLOCKABLE                 = (1 << 30),
};


class CTFNavArea : public CNavArea
{
public:
	// TODO
	
private:
	// TODO
	TFNavAttributeType m_nAttributes; // +0x1c4
	// TODO
};
