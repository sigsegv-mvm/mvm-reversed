/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/tf_bot.h
 */


class CTFBot : public NextBotPlayer<CTFPlayer>, public CGameEventListener
{
public:
	// sizeof: 0x1c
	class CTFBotIntention : public IIntention
	{
	public:
		CTFBotIntention(CTFBot *actor);
		virtual ~CTFBotIntention();
		
		virtual INextBotEventResponder *FirstContainedResponder() const override;
		virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *prev) const override;
		
		virtual void Reset() override;
		virtual void Update() override;
		
	private:
		Behavior<CTFBot> m_Behavior; // +0x18
	};
	
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
		// 2?
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
		// some of these can be found in CFuncNavCost::IsApplicableTo
		// in game/server/nav_entities.cpp
		
		NONE             = 0,
		// TODO: 1
		DESTROY_SENTRIES = 2,
		SNIPER           = 3,
		SPY              = 4,
		ENGINEER         = 5,
		REPROGRAMMED     = 6,
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
	
	// TODO: SuspectedSpyInfo_t
	// TODO: SniperSpotInfo
	// TODO: DelayedNoticeInfo
	
	CTFBot();
	virtual ~CTFBot();
	
	virtual int ShouldTransmit(const CCheckTransmitInfo *pInfo) override;
	virtual void Spawn() override;
	virtual void DrawDebugTextOverlays() override;
	virtual void Event_Killed(const CTakeDamageInfo& info) override;
	virtual void Touch(CBaseEntity *ent) override;
	virtual void PhysicsSimulate() override;
	virtual void UpdateOnRemove() override;
	virtual bool ShouldGib(const CTakeDamageInfo& info) override;
	virtual CNavArea *GetLastKnownArea() const override;
	virtual void ChangeTeam(int iTeamNum, bool bAutoTeam, bool bSilent) override;
	virtual int GetBotType() const override;
	virtual bool IsAllowedToPickUpFlag() const override;
	virtual int GetAllowedTauntPartnerTeam() const override;
	virtual void InitClass() override;
	
	virtual bool IsDormantWhenDead() const override;
	virtual void PressFireButton(float duration = -1.0f) override;
	virtual void PressAltFireButton(float duration = -1.0f) override;
	virtual void AvoidPlayers(CUserCmd *usercmd) override;
	
	virtual void FireGameEvent(IGameEvent *event) override;
	
	virtual ILocomotion *GetLocomotionInterface() const;
	virtual IBody *GetBodyInterface() const;
	virtual IIntention *GetIntentionInterface() const;
	virtual IVision *GetVisionInterface() const;
	virtual void OnWeaponFired(CBaseCombatCharacter *who, CBaseCombatWeapon *weapon);
	virtual bool IsDebugFilterMatch(const char *filter) const;
	
	
	// TODO: check whether member funcs are private
	
	float TransientlyConsistentRandomValue(float duration, int seed) const;
	
	bool IsWeaponRestricted(CTFWeaponBase *weapon) const;
	
	bool IsCombatWeapon(CTFWeaponBase *weapon = nullptr) const;
	bool IsQuietWeapon(CTFWeaponBase *weapon = nullptr) const;
	
	bool IsHitScanWeapon(CTFWeaponBase *weapon = nullptr) const;
	bool IsExplosiveProjectileWeapon(CTFWeaponBase *weapon = nullptr) const;
	
	bool IsContinuousFireWeapon(CTFWeaponBase *weapon = nullptr) const;
	bool IsBarrageAndReloadWeapon(CTFWeaponBase *weapon = nullptr) const;
	
	bool IsAmmoLow() const;
	bool IsAmmoFull() const;
	
	float GetMaxAttackRange() const;
	
	void DisguiseAsMemberOfEnemyTeam();
	
	Action<CTFBot> *OpportunisticallyUseWeaponAbilities();
	
	void AddEventChangeAttributes(const EventChangeAttributes_t *ecattr);
	const EventChangeAttributes_t *GetEventChangeAttributes(const char *name) const;
	void OnEventChangeAttributes(const EventChangeAttributes_t *ecattr);
	
	bool IsSquadmate(CTFPlayer *player) const;
	void JoinSquad(CTFBotSquad *squad);
	void LeaveSquad();
	void DeleteSquad();
	
	bool HasTag(const char *tag);
	void AddTag(const char *tag);
	void RemoveTag(const char *tag);
	void ClearTags();
	
	
	// AddItem
	
	// IsAttentionFocused
	// IsAttentionFocusedOn
	
	// IsSuspectedSpy
	// IsKnownSpy
	// SuspectSpy
	// RealizeSpy
	// ForgetSpy
	// DeleyedThreatNotice
	// UpdateDelayedThreatNotices
	
	// CTFBot::AddItem was previously CTFBotSpawner::AddItemToBot
	
	// functions only in certain game versions:
	// (TODO: find callers, figure out places where these were probably inlined into)
	// server.dylib
	//   CTFBot::EventChangeAttributes_t::EventChangeAttributes_t()
	//   CTFBot::EventChangeAttributes_t::operator=(CTFBot::EventChangeAttributes_t const&)
	// server_srv.so 20140619a
	//   CTFBot::EventChangeAttributes_t::item_attributes_t::~item_attributes_t()
	//   CTFBot::FindClosestReachableObject(char const*, CNavArea*, float) const
	
	// functions revealed in game/server/nav_entities.cpp:
	// HasMission
	// IsOnAnyMission
	
	// TODO: non-virtual member funcs
	
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
	// 0x0850-0x1100: CBasePlayer
	// 0x1100-0x114c: CBaseMultiplayerPlayer
	// 0x114c-0x1150: IHasAttributes
	
	// 0x1164: CTFPlayer: CAttributeManager
	// 0x11c4: CTFPlayer: CTFPlayerInventory
	// 0x1964: CTFPlayer: CTFPlayerShared
	  // 0x24c4: CTFPlayerShared: CEconItemView
	// 0x26ec: CTFPlayer: CTFPlayerClass
	
	// 0x2834: CTFPlayer: byte  true for mission-populator-spawned bots
	// (causes no money to drop, and determines when decrementing the wave class count whether flag 1 or 4 should be set)
	// 0x2836: CTFPlayer: byte  true for "Support Limited" bots
	// 0x2838: CTFPlayer: int m_nCurrency
	// 0x2840: CTFPlayer: int m_nExperienceLevel
	// 0x2844: CTFPlayer: int m_nExperienceLevelProgress
	// 0x284c: CTFPlayer: dword, probably CWaveSpawnPopulator*
	// 0x2894: CTFPlayer: CountdownTimer m_ctSapNotice
	// 0x2920: CTFPlayer: float m_flSentryDamage
	// 0x2924: CTFPlayer: int   m_nSentryKills
	
	// 0x29e0: byte INextBot+0x10
	
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
	
	WeaponRestriction m_nRestrict; // +0x2b10
	AttributeType m_nBotAttrs;     // +0x2b14
	DifficultyType m_iSkill;       // +0x2b18
	
	CTFBotSquad *m_Squad; // +0x2b2c
	
	// 0x2bb8: CTFBot: CountdownTimer
	
	bool m_bLookAroundForEnemies; // +0x2bc4
	
	enum IgnoreMask : int
	{
		/* the ordering of these is weird */
		IGNORE_SCOUTS   = (1 << 0),
		IGNORE_SOLDIERS = (1 << 1),
		IGNORE_PYROS    = (1 << 2),
		IGNORE_DEMOS    = (1 << 3),
		IGNORE_HEAVIES  = (1 << 4),
		IGNORE_MEDICS   = (1 << 5),
		IGNORE_ENGIES   = (1 << 6),
		IGNORE_SNIPERS  = (1 << 7),
		IGNORE_SPIES    = (1 << 8),
		IGNORE_SENTRIES = (1 << 9),
	};
	IgnoreMask m_nIgnoreMask; // +0x2bc8
	
	// 0x2be0: CTFBot: CHandle<T> attention focus
	
	// 0x2be8: CTFBot: CountdownTimer
	
	float m_flScale; // +0x2bf4
	
	// 0x2bf8: CTFBot: MissionType m_nMission
	// 0x2bfc: CTFBot: 
	CHandle<CBaseEntity> m_hSBTarget; // +0x2c00
	// 0x2c04: CTFBot: CUtlString
	
	// 0x2c1c: CTFBot: CountdownTimer
	
	CountdownTimer m_ctUseWeaponAbilities; // +0x2c40
	
	float m_flVisionRange; // +0x2c3c
	
	float m_flFormationError; // +0x2c50
	bool m_bIsInFormation;    // +0x2c54
	
	CUtlStringList m_TeleportWhere; // +0x2c58
	bool m_bTeleQuickBuild;         // +0x2c6c
	float m_flAutoJumpMin; // +0x2c70
	float m_flAutoJumpMax; // +0x2c74
	// 0x2c78: CTFBot: CountdownTimer
	// TODO: 0x2c84
	CUtlVector<const EventChangeAttributes_t *> m_ECAttrs; // +0x2c88 (maybe autopurge)
};


// TODO: IsPlayerClassname
// TODO: IsTeamName
// TODO: StringToDifficultyLevel
// TODO: DifficultyLevelToString
// TODO: GetRandomBotName
// TODO: CreateBotName

// TODO: CCollectReachableObjects
// TODO: CFindVantagePoint
// TODO: CCountClassMembers
