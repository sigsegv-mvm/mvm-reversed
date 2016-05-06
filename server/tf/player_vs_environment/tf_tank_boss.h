/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/player_vs_environment/tf_tank_boss.h
 */


class CTFTankBoss : public CTFBaseBoss
{
public:
	CTFTankBoss();
	virtual ~CTFTankBoss();
	
	virtual void Spawn() override;
	virtual void Precache() override;
	virtual Event_Killed
	virtual UpdateOnRemove
	virtual OnTakeDamage_Alive
	
	virtual void UpdateCollisionBounds() override;
	virtual int GetCurrencyValue() override;
	virtual void ModifyDamage(CTakeDamageInfo *info) const override;
	
	// new virtuals
	SetSkin
	GetBodyInterface
	
	// non-virtual
	Explode
	FirePopFileEvent
	SetStartingPathTrackNode
	void TankBossThink();
	UpdatePingSound
	
private:
	// TODO: netprops
	// TODO: datamaps
	// TODO: everything else
	
	// 9d0 CTFTankBossBody *
	// 9d4 
	// 9d8 
	CHandle<CPathTrack> m_hCurrentNode; // +0x9dc
	CUtlVector<float> m_NodeDists;      // +0x9e0
	float m_flTotalDistance;            // +0x9f4
	int m_iCurrentNode;                 // +0x9f8
	// 9fc float
	// a00 byte
	// a04 
	int m_iSmokeAttachment; // +0xa08
	// a0c 
	int m_iLastHealth; // +0xa10
	int m_iModelIndex; // +0xa14
	// a18 
	// a1c 
	// a20 
	Vector m_vecTrackR; // +0xa24
	Vector m_vecTrackL; // +0xa30
	// a3c 
	// a40 
	// a44 
	EventInfo m_OnKilledOutput;             // +0xa48
	EventInfo m_OnBombDroppedOutput;        // +0xc60
	CHandle<CDynamicProp> m_hBombMechanism; // +0xe78
	CHandle<CDynamicProp> m_hTrackL;        // +0xe7c
	CHandle<CDynamicProp> m_hTrackR;        // +0xe80
	// e84 
	// e88 
	// e8c 
	// e90 
	Vector m_vecCollisionMins; // +0xe94
	Vector m_vecCollisionMaxs; // +0xea0
	// eac float
	// eb0 
	// eb4 
	// eb8 
	// ebc 
	// ec0 
	// ec4 
	// ec8 
};


class CTFTankDestruction : public CBaseAnimating
{
public:
	// TODO
};


// TODO: EntityHistory_t, CEntityHistoryLess (belongs in the achievement code)


// relevant for vcollide mod:
// CTFTankBoss::Spawn
// CTFTankBoss::ResolvePlayerCollision
// CTFTankBoss::TankBossThink
// CTFBaseBoss::UpdateCollisionBounds
