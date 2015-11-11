#define COLOR_WHITE    Color(255, 255, 255, 255)
#define COLOR_LTYELLOW Color(255, 255, 150, 255)
#define COLOR_LTGREEN  Color(150, 255, 150, 255)
#define COLOR_GREEN    Color(  0, 255,   0, 255)
#define COLOR_RED      Color(255,   0,   0, 255)
#define COLOR_MAGENTA  Color(255,   0, 255, 255)


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


enum class TFNavAttributeType : int
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
	bool IsPvEModeControlled(CBaseEntity *ent)
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


class CSpawnLocation
{
public:
	enum class Where : int
	{
		TEAMSPAWN = 0,
		AHEAD     = 1,
		BEHIND    = 2,
		ANYWHERE  = 3,
	};
	
	CSpawnLocation()
	{
		this->m_iWhere = Where::TEAMSPAWN;
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
	Where m_iWhere;                            // +0x00
	CUtlVector<CHandle<CBaseEntity>> m_Spawns; // +0x04
};
