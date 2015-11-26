#define COLOR_WHITE    Color(255, 255, 255, 255)
#define COLOR_LTYELLOW Color(255, 255, 150, 255)
#define COLOR_LTGREEN  Color(150, 255, 150, 255)
#define COLOR_GREEN    Color(  0, 255,   0, 255)
#define COLOR_RED      Color(255,   0,   0, 255)
#define COLOR_MAGENTA  Color(255,   0, 255, 255)
#define COLOR_GRAY100  Color(100, 100, 100, 255)


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


// void CTFGameRules::DistributeCurrencyAmount(int, CTFPlayer *, bool, bool, bool)
// - int amount
// - CTFPlayer *player (whose credit balance should be increased)
// - bool give_to_all
// - bool b2: whether to call CMannVsMachineStats::RoundEvent_CreditsDropped
// - bool b3: whether the credits are bonus credits (I think)
// callers:
// - CCaptureFlag::Capture:
//   (amount, player, true, false, false)
// - CTFGameRules::FireGameEvent("teamplay_point_capture", heavyweapons only):
//   (100, player, false, false, false)
// - CTFGameRules::FireGameEvent("player_escort_score"):
//   (amount, player, false, false, false)
// - CCurrencyPack::ComeToReset(trigger_hurt):
//   (amount, nullptr, true, false, false)
// - CCurrencyPack::MyTouch:
//   (amount, player, true, false, false)
// - CCurrencyPack::DistributedBy:
//   (amount, nullptr, true, false, false)
// - CWaveSpawnPopulator::OnNonSupportWavesDone:
//   (amount, nullptr, true, true, false)
// - CWave::WaveIntermissionUpdate:
//   (amount, nullptr, true, false, true)
// - CTFPlayer::AddExperiencePoints:
//   (amount, player, false, false, false)
// - CTFPlayer::Event_Killed:
//   (amount, nullptr, true, true, false)


// int CTFGameRules::CalculateCurrencyAmountByType(CurrencyRewards_t)
// int CTFGameRules::CalculateCurrencyAmount_CustomPack(int)
enum CurrencyRewards_t : int
{
	// TODO
	
	// 0x0 40   
	// 0x1 40   
	// 0x2 20   
	// 0x3 1    
	// 0x4 100  used for "teamplay_point_capture"
	// 0x5 10   
	// 0x6 5    CCurrencyPackSmall::GetPackSize()
	// 0x7 10   CCurrencyPackMedium::GetPackSize()
	// 0x8 25   CCurrencyPack::GetPackSize()
	// 0x9 0    CCurrencyPackCustom::GetPackSize()
	// 0xA 5    
	// 0xB 100  used for wave credit bonus
};
