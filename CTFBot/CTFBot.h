/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot
 */


// TODO:
// INextBotPlayerInput


class CTFPlayer : public CBaseMultiplayerPlayer, public IHasAttributes,
	public IInventoryUpdateListener
{
public:
	// TODO
	
private:
	// TODO
	int m_nCurrency;          // +0x2838 NETPROP DT_TFLocalPlayerExclusive
	bool m_bIsMiniBoss;       // +0x283c NETPROP DT_TFPlayer
	// TODO
	bool m_bUseBossHealthBar; // +0x296c NETPROP DT_TFPlayer
	// TODO
};


class CTFBot : public NextBotPlayer<CTFPlayer>, public CGameEventListener
{
public:
	enum class DifficultyType : int
	{
		EASY   = 0,
		NORMAL = 1,
		HARD   = 2,
		EXPERT = 3,
	};
	
	enum class AttributeType : int
	{
		NONE                    = 0,
		
		REMOVEONDEATH           = (1 << 0),
		AGGRESSIVE              = (1 << 1),
		// 4?
		SUPPRESSFIRE            = (1 << 3),
		DISABLEDODGE            = (1 << 4),
		BECOMESPECTATORONDEATH  = (1 << 5),
		// 6?
		RETAINBUILDINGS         = (1 << 7),
		SPAWNWITHFULLCHARGE     = (1 << 8),
		ALWAYSCRIT              = (1 << 9),
		IGNOREENEMIES           = (1 << 10),
		HOLDFIREUNTILFULLRELOAD = (1 << 11),
		// 12?
		ALWAYSFIREWEAPON        = (1 << 13),
		TELEPORTTOHINT          = (1 << 14),
		MINIBOSS                = (1 << 15),
		USEBOSSHEALTHBAR        = (1 << 16),
		IGNOREFLAG              = (1 << 17),
		AUTOJUMP                = (1 << 18),
		AIRCHARGEONLY           = (1 << 19),
		VACCINATORBULLETS       = (1 << 20),
		VACCINATORBLAST         = (1 << 21),
		VACCINATORFIRE          = (1 << 22),
		BULLETIMMUNE            = (1 << 23),
		BLASTIMMUNE             = (1 << 24),
		FIREIMMUNE              = (1 << 25),
	};
	
	enum class MissionType : int
	{
		// TODO: 0
		// TODO: 1
		DESTROY_SENTRIES = 2,
		SNIPER           = 3,
		SPY              = 4,
		ENGINEER         = 5,
		// TODO: 6
	};
	
	// TODO: type name for this?
	enum class WeaponRestriction : int
	{
		UNRESTRICTED  = 0,
		MELEEONLY     = (1 << 0),
		PRIMARYONLY   = (1 << 1),
		SECONDARYONLY = (1 << 2),
	};
	
	struct EventChangeAttributes_t
	{
		struct item_attributes_t
		{
			CUtlString m_strItemName;                    // +0x00
			CCopyableUtlVector<static_attrib_t> m_Attrs; // +0x04
		};
		
		
		EventChangeAttributes_t(const char *name = "default")
		{
			this->Reset(name);
		}
		
		void Reset(const char *name = "default")
		{
			this->m_strName = name;
			
			this->m_iSkill          = DifficultyType::EASY;
			this->m_nWeaponRestrict = WeaponRestriction::UNRESTRICTED;
			// TODO: 0x0c
			// TODO: 0x10
			this->m_nBotAttrs       = AttributeType::NONE;
			this->m_flVisionRange   = -1.0f;
			
			this->m_ItemNames.RemoveAll();
			this->m_ItemAttrs.RemoveAll();
			this->m_CharAttrs.RemoveAll();
			this->m_Tags.RemoveAll();
		}
		
		CUtlString m_strName;                // +0x00
		DifficultyType m_iSkill;             // +0x04
		WeaponRestriction m_nWeaponRestrict; // +0x08
		// TODO: 0x0c
		// TODO: 0x10
		AttributeType m_nBotAttrs;  // +0x14
		float m_flVisionRange;      // +0x18
		CUtlStringList m_ItemNames; // +0x1c
		CUtlVector<item_attributes_t> m_ItemAttrs; // +0x30
		CUtlVector<static_attrib_t> m_CharAttrs; // +0x44
		CUtlStringList m_Tags;  // +0x58
	};
	
	// TODO
	
private:
	// base class layout
	// +0x0000 - NextBotPlayer<CTFPlayer>
	// +0x0000   - CTFPlayer
	// +0x0000     - CBaseMultiplayerPlayer
	// +0x0000       - CAI_ExpresserHost<CBasePlayer>
	// +0x0000         - CBasePlayer
	// +0x0000           - CBaseCombatCharacter
	// +0x0000             - CBaseFlex
	// +0x0000               - CBaseAnimatingOverlay
	// +0x0000                 - CBaseAnimating
	// +0x0000                   - CBaseEntity
	// +0x0000                     - IServerEntity
	// +0x0000                       - IServerUnknown
	// +0x0000                         - IHandleEntity
	// +0x1100         - CAI_ExpresserSink
	// +0x114c     - IHasAttributes
	// +0x1150     - IInventoryUpdateListener
	// +0x1150       - GCSDK::ISharedObjectListener
	// +0x29d0   - INextBot
	// +0x29d0     - INextBotEventResponder
	// +0x2a30 - INextBotPlayerInput
	// +0x2adc - CGameEventListener
	
	// 0x0000-0x0014: IHandleEntity/IServerUnknown/IServerEntity
	// 0x0014-0x0368: CBaseEntity
	// 0x0368-0x0488: CBaseAnimating/CBaseAnimatingOverlay
	// 0x0488-0x067c: CBaseFlex
	// 0x0680-0x0850: CBaseCombatCharacter
	// 0x0858-0x1100: CBasePlayer
	// 0x1100-0x114c: CBaseMultiplayerPlayer
	// 0x114c-0x1150: IHasAttributes
	
	// 0x1164: CTFPlayer: CAttributeManager
	// 0x11c4: CTFPlayer: CTFPlayerInventory
	// 0x1964: CTFPlayer: CTFPlayerShared
	// 0x24c4: CTFPlayer: CEconItemView
	// 0x26ec: CTFPlayer: CTFPlayerClass
	
	// 0x2a3c: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2a54: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2a60: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2a6c: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2a78: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2a84: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2a90: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2a9c: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2aa8: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2ab4: NextBotPlayer<CTFPlayer>: CountdownTimer
	// 0x2ac0: NextBotPlayer<CTFPlayer>: CountdownTimer
	
	// 0x2ae4: CTFBot: CTFBot::CTFBotIntention*
	// 0x2ae8: CTFBot: CTFBotLocomotion*
	// 0x2aec: CTFBot: CTFBotBody*
	// 0x2af0: CTFBot: CTFBotVision*
	
	// 0x2af4: CTFBot: CountdownTimer
	// 0x2b04: CTFBot: CountdownTimer
	
	AttributeType m_nBotAttrs; // +0x2b14
	
	// 0x2bb8: CTFBot: CountdownTimer
	// 0x2be8: CTFBot: CountdownTimer
	
	float m_flScale; // +0x2bf4
	
	// 0x2c04: CTFBot: CUtlString
	
	// TODO: 0x2c54
	CUtlStringList m_TeleportWhere; // +0x2c58
	// TODO: 0x2c6c
	float m_flAutoJumpMin; // +0x2c70
	float m_flAutoJumpMax; // +0x2c74
	// TODO: 0x2c78
	// TODO: 0x2c7c
	// TODO: 0x2c80
	// TODO: 0x2c84
	CUtlVector<EventChangeAttributes_t> m_ECAttrs; // +0x2c88
	// TODO: 0x2c9c
	
	// 0x2c1c: CTFBot: CountdownTimer
	// 0x2c40: CTFBot: CountdownTimer
	
	
	// 0x2c78: CTFBot: CountdownTimer
	
	// TODO
};
