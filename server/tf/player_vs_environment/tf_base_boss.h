/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/player_vs_environment/tf_base_boss.h
 */


class CTFBaseBoss : public NextBotCombatCharacter
{
public:
	CTFBaseBoss();
	virtual ~CTFBaseBoss();
	
	virtual ??? UpdateTransmitState(???) ??? override;
	virtual void Spawn() override;
	virtual void Precache() override;
	virtual ??? OnTakeDamage(???) ??? override;
	virtual ??? Event_Killed(???) ??? override;
	virtual ??? Touch(???) ??? override;
	virtual ??? UpdateOnRemove(???) ??? override;
	virtual ??? OnTakeDamage_Alive(???) ??? override;
	
	virtual bool IsRemovedOnReset() const override;
	virtual ILocomotion *GetLocomotionInterface() const override;
	
	virtual void UpdateCollisionBounds();
	virtual int GetCurrencyValue();
	virtual void ModifyDamage(CTakeDamageInfo *info) const;
	
	void BossThink();
	void ResolvePlayerCollision(CTFPlayer *player);
	
private:
	// 8b8 m_outputOnHealthBelow90Percent
	// 8d0 m_outputOnHealthBelow80Percent
	// 8e8 m_outputOnHealthBelow70Percent
	// 900 m_outputOnHealthBelow60Percent
	// 918 m_outputOnHealthBelow50Percent
	// 930 m_outputOnHealthBelow40Percent
	// 948 m_outputOnHealthBelow30Percent
	// 960 m_outputOnHealthBelow20Percent
	// 978 m_outputOnHealthBelow10Percent
	// 990 m_outputOnKilled
	int m_initialHealth;          // +0x9a8
	float m_lastHealthPercentage; // +0x9ac
	// 9b0 m_modelString
	float m_speed;                // +0x9b4
	// 9b8 m_startDisabled
	bool m_bEnabled;              // +0x9bc
	// 9c0 
	// ...
	// 9cc CTFBaseBossLocomotion *
};


class CTFBaseBossLocomotion : public NextBotGroundLocomotion
{
public:
	CTFBaseBossLocomotion();
	virtual ~CTFBaseBossLocomotion();
	
	virtual void FaceTowards(const Vector& v1) override;
	virtual float GetStepHeight() const override;
	virtual float GetMaxJumpHeight() const override;
	virtual float GetRunSpeed() const override;
	
private:
	// TODO
};
