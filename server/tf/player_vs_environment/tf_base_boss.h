/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/player_vs_environment/tf_base_boss.h
 */


class CTFBaseBoss : public NextBotCombatCharacter, public INextBot
{
public:
	// TODO
	
protected:
	// TODO
	int m_initialHealth;          // +0x9a8
	float m_lastHealthPercentage; // +0x9ac
	// TODO 0x9b0 m_modelString
	float m_speed;                // +0x9b4
	// TODO 0x9b8 m_startDisabled
	// TODO
};


class CTFBaseBossLocomotion : public NextBotGroundLocomotion
{
	// TODO
};
