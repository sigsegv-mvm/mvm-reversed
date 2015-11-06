

class CTFBotSquad : public INextBotEventResponder
{
public:
	CTFBotSquad();
	virtual ~CTFBotSquad();
	
	virtual INextBotEventResponder *FirstContainedResponder() const;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *) const;
	
	struct Iterator
	{
		// 0x00
		// 0x04
	};
	
	void CollectMembers(CUtlVector<CTFBot *> *) const;
	void DisbandAndDeleteSquad();
	Iterator GetFirstMember() const;
	CTFBot *GetLeader() const;
	float GetMaxSquadFormationError() const;
	int GetMemberCount() const;
	Iterator GetNextMember(CTFBotSquad::Iterator const&) const;
	float GetSlowestMemberIdealSpeed(bool) const;
	float GetSlowestMemberSpeed(bool) const;
	bool IsInFormation() const;
	void Join(CTFBot *);
	void Leave(CTFBot *);
	bool ShouldSquadLeaderWaitForFormation() const;
	
private:
	CUtlVector<CHandle<CTFBot>> m_Members; // +0x04
	CHandle<CTFBot> m_hLeader;             // +0x18
	float m_flFormationSize;               // +0x1c
	bool m_bShouldPreserveSquad;           // +0x20
};


class CTFBaseBoss : public NextBotCombatCharacter
{
public:
	// TODO
	
private:
	// TODO
	int m_iBossHealth;   // +0x9a8
	// TODO
	float m_flBossSpeed; // +0x9b4
	// TODO
};


class CTFTankBoss : public CTFBaseBoss
{
public:
	// TODO
	
private:
	// TODO
	EventInfo m_OnKilledOutput;      // +0xa48
	EventInfo m_OnBombDroppedOutput; // +0xc60
	// TODO
};


enum TFNavAttributeType
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


class CTFGameRules : public CTeamplayRoundBasedRules
{
public:
	// TODO
	bool GameModeUsesUpgrades() { return this->m_bPlayingMannVsMachine; }
	bool IsPvEModeActive()      { return this->m_bPlayingMannVsMachine; }
	// TODO
	bool IsPveModeControlled(CBaseEntity *ent)
	{
		return (ent != nullptr && this->m_bPlayingMannVsMachine &&
			ent->GetTeamNumber() == TF_TEAM_BLU);
	}
	// TODO
	
private:
	// TODO
	bool m_bPlayingMannVsMachine; // +0x96a
	// TODO
};


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


template <class T>
class NextBotPlayer : public T, public INextBot, public INextBotPlayerInput
{
public:
	// TODO
	
private:
	// TODO
};


class CTFBot : public NextBotPlayer<CTFPlayer>, public CGameEventListener
{
public:
	enum MissionType
	{
		// TODO: 0
		// TODO: 1
		MISSION_DESTROY_SENTRIES = 2,
		MISSION_SNIPER           = 3,
		MISSION_SPY              = 4,
		MISSION_ENGINEER         = 5,
		// TODO: 6
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
	
	CTFBot::AttributeType m_nBotAttrs; // +0x2b14
	
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
	CUtlVector<CTFBot::EventChangeAttributes_t> m_ECAttrs; // +0x2c88
	// TODO: 0x2c9c
	
	// 0x2c1c: CTFBot: CountdownTimer
	// 0x2c40: CTFBot: CountdownTimer
	
	
	// 0x2c78: CTFBot: CountdownTimer
	
	// TODO
};


class CSpawnLocation
{
public:
	enum // TODO: name?
	{
		WHERE_TEAMSPAWN = 0,
		WHERE_AHEAD     = 1,
		WHERE_BEHIND    = 2,
		WHERE_ANYWHERE  = 3,
	};
	
	CSpawnLocation()
	{
		this->m_iWhere = WHERE_TEAMSPAWN;
	}
	
	bool Parse(KeyValues *kv)
	{
		
	}
	
	CTFNavArea *SelectSpawnArea()
	{
		
	}
	
	bool FindSpawnLocation(Vector& vec)
	{
		
	}
	
private:
	int m_iWhere;                              // +0x00
	CUtlVector<CHandle<CBaseEntity>> m_Spawns; // +0x04
};
