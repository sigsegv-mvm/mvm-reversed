/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: spawners
 */


// TODO: type name for this?
enum {
	BOT_ATTRIBUTES_REMOVEONDEATH           = (1 << 0),
	BOT_ATTRIBUTES_AGGRESSIVE              = (1 << 1),
	// 4?
	BOT_ATTRIBUTES_SUPPRESSFIRE            = (1 << 3),
	BOT_ATTRIBUTES_DISABLEDODGE            = (1 << 4),
	BOT_ATTRIBUTES_BECOMESPECTATORONDEATH  = (1 << 5),
	// 6?
	BOT_ATTRIBUTES_RETAINBUILDINGS         = (1 << 7),
	BOT_ATTRIBUTES_SPAWNWITHFULLCHARGE     = (1 << 8),
	BOT_ATTRIBUTES_ALWAYSCRIT              = (1 << 9),
	BOT_ATTRIBUTES_IGNOREENEMIES           = (1 << 10),
	BOT_ATTRIBUTES_HOLDFIREUNTILFULLRELOAD = (1 << 11),
	// 12?
	BOT_ATTRIBUTES_ALWAYSFIREWEAPON        = (1 << 13),
	BOT_ATTRIBUTES_TELEPORTTOHINT          = (1 << 14),
	BOT_ATTRIBUTES_MINIBOSS                = (1 << 15),
	BOT_ATTRIBUTES_USEBOSSHEALTHBAR        = (1 << 16),
	BOT_ATTRIBUTES_IGNOREFLAG              = (1 << 17),
	BOT_ATTRIBUTES_AUTOJUMP                = (1 << 18),
	BOT_ATTRIBUTES_AIRCHARGEONLY           = (1 << 19),
	BOT_ATTRIBUTES_VACCINATORBULLETS       = (1 << 20),
	BOT_ATTRIBUTES_VACCINATORBLAST         = (1 << 21),
	BOT_ATTRIBUTES_VACCINATORFIRE          = (1 << 22),
	BOT_ATTRIBUTES_BULLETIMMUNE            = (1 << 23),
	BOT_ATTRIBUTES_BLASTIMMUNE             = (1 << 24),
	BOT_ATTRIBUTES_FIREIMMUNE              = (1 << 25),
	
	
	BOT_RESTRICT_NONE          = 0,
	BOT_RESTRICT_MELEEONLY     = (1 << 0),
	BOT_RESTRICT_PRIMARYONLY   = (1 << 1),
	BOT_RESTRICT_SECONDARYONLY = (1 << 2),
	
	
	BOT_SKILL_EASY   = 0,
	BOT_SKILL_NORMAL = 1,
	BOT_SKILL_HARD   = 2,
	BOT_SKILL_EXPERT = 3,
};


struct CTFBot::EventChangeAttributes_t
{
	CTFBot::EventChangeAttributes_t(const char *name = "default")
	{
		this->Reset(name);
	}
	
	void Reset(const char *name = "default")
	{
		this->m_strName = name;
		
		this->m_iSkill          = BOT_SKILL_EASY;
		this->m_nWeaponRestrict = BOT_RESTRICT_NONE;
		// TODO: 0x0c
		// TODO: 0x10
		this->m_nBotAttrs       = 0;
		this->m_flVisionRange   = -1.0f;
		
		this->m_ItemNames.RemoveAll();
		this->m_ItemAttrs.RemoveAll();
		this->m_CharAttrs.RemoveAll();
		this->m_Tags.RemoveAll();
	}
	
	CUtlString m_strName;       // +0x00
	int m_iSkill;               // +0x04
	int m_nWeaponRestrict;      // +0x08
	// TODO: 0x0c
	// TODO: 0x10
	int m_nBotAttrs;            // +0x14
	float m_flVisionRange;      // +0x18
	CUtlStringList m_ItemNames; // +0x1c
	CUtlVector<CTFBot::EventChangeAttributes_t::item_attributes_t> m_ItemAttrs; // +0x30
	CUtlVector<static_attrib_t> m_CharAttrs; // +0x44
	CUtlStringList m_Tags;  // +0x58
};

struct CTFBot::EventChangeAttributes_t::item_attributes_t
{
	CUtlString m_strItemName;                    // +0x00
	CCopyableUtlVector<static_attrib_t> m_Attrs; // +0x04
};


class IPopulationSpawner
{
public:
	virtual ~IPopulationSpawner() {}
	
	virtual bool Parse(KeyValues *kv) = 0;
	virtual bool Spawn(const Vector&, CUtlVector<CHandle<CBaseEntity>>, int) = 0;
	virtual bool IsWhereRequired();
	virtual bool IsVarious();
	virtual int GetClass(int index);
	virtual string_t GetClassIcon(int);
	virtual int GetHealth(int);
	virtual bool IsMiniBoss(int);
	virtual bool HasAttribute(CTFBot::AttributeType attr, int index);
	virtual bool HasEventChangeAttributes(const char *name) const = 0;
	
	static IPopulationSpawner *ParseSpawner(IPopulator *populator, KeyValues *kv);
	
protected:
	IPopulator *m_Populator; // +0x04
};


class CMobSpawner : public IPopulationSpawner
{
public:
	CMobSpawner(IPopulator *populator);
	virtual ~CMobSpawner();
	
	virtual bool Parse(KeyValues *kv);
	virtual bool Spawn(const Vector&, CUtlVector<CHandle<CBaseEntity>>, int);
	virtual bool HasEventChangeAttributes(const char *name) const;
	
private:
	int                 m_iCount;     // +0x08
	IPopulationSpawner *m_SubSpawner; // +0x0c
	// TODO 0x10 CountdownTimer
	// TODO 0x1c CountdownTimer
	// TODO 0x28 dword 0
	// TODO 0x2c dword 0
};


class CSentryGunSpawner : public IPopulationSpawner
{
public:
	CSentryGunSpawner(IPopulator *populator);
	virtual ~CSentryGunSpawner();
	
	virtual bool Parse(KeyValues *kv);
	virtual bool Spawn(const Vector&, CUtlVector<CHandle<CBaseEntity>>, int);
	virtual bool HasEventChangeAttributes(const char *name) const;
	
private:
	int m_iLevel; // +0x08
};


class CTankSpawner : public IPopulationSpawner
{
public:
	CTankSpawner(IPopulator *populator);
	virtual ~CTankSpawner();
	
	virtual bool Parse(KeyValues *kv);
	virtual bool Spawn(const Vector&, CUtlVector<CHandle<CBaseEntity>>, int);
	virtual bool IsWhereRequired();
	virtual string_t GetClassIcon(int);
	virtual int GetHealth(int);
	virtual bool IsMiniBoss();
	virtual bool HasEventChangeAttributes(const char *name) const;
	
private:
	int        m_iHealth;             // +0x08
	float      m_flSpeed;             // +0x0c
	CUtlString m_strName;             // +0x10
	CUtlString m_strStartNode;        // +0x14
	int        m_iSkin;               // +0x18
	EventInfo *m_OnKilledOutput;      // +0x1c
	EventInfo *m_OnBombDroppedOutput; // +0x20
};


class CTFBotSpawner : public IPopulationSpawner
{
public:
	CTFBotSpawner(IPopulator *populator);
	virtual ~CTFBotSpawner();
	
	virtual bool Parse(KeyValues *kv);
	virtual bool Spawn(const Vector&, CUtlVector<CHandle<CBaseEntity>>, int);
	virtual int GetClass(int index);
	virtual string_t GetClassIcon(int);
	virtual int GetHealth(int);
	virtual bool IsMiniBoss();
	virtual bool HasAttribute(CTFBot::AttributeType attr, int index);
	virtual bool HasEventChangeAttributes(const char *name) const;
	
	bool ParseEventChangeAttributes(KeyValues *kv);
	
private:
	int m_iClass;                                          // +0x08
	string_t m_strClassIcon;                               // +0x0c
	int m_iHealth;                                         // +0x10
	float m_flScale;                                       // +0x14
	float m_flAutoJumpMin;                                 // +0x18
	float m_flAutoJumpMax;                                 // +0x1c
	CUtlString m_strName;                                  // +0x20
	CUtlVectorAutoPurge<char *> m_TeleportWhere;           // +0x24
	CTFBot::EventChangeAttributes_t m_DefaultAttrs;        // +0x38
	CUtlVector<CTFBot::EventChangeAttributes_t> m_ECAttrs; // +0xa4
};


class CSquadSpawner : public IPopulationSpawner
{
public:
	CSquadSpawner(IPopulator *populator);
	virtual ~CSquadSpawner();
	
	virtual bool Parse(KeyValues *kv);
	virtual bool Spawn(const Vector&, CUtlVector<CHandle<CBaseEntity>>, int);
	virtual bool IsVarious();
	virtual int GetClass(int index);
	virtual string_t GetClassIcon(int);
	virtual int GetHealth(int);
	virtual bool IsMiniBoss();
	virtual bool HasAttribute(CTFBot::AttributeType attr, int index);
	virtual bool HasEventChangeAttributes(const char *name) const;
	
private:
	CUtlVector<IPopulationSpawner *> m_SubSpawners; // +0x08
	float m_flFormationSize;                        // +0x1c
	bool m_bShouldPreserveSquad;                    // +0x20
};


class CRandomChoiceSpawner : public IPopulationSpawner
{
public:
	CRandomChoiceSpawner(IPopulator *populator);
	virtual ~CRandomChoiceSpawner();
	
	virtual bool Parse(KeyValues *kv);
	virtual bool Spawn(const Vector&, CUtlVector<CHandle<CBaseEntity>>, int);
	virtual bool IsVarious();
	virtual int GetClass(int index);
	virtual string_t GetClassIcon(int);
	virtual int GetHealth(int);
	virtual bool IsMiniBoss();
	virtual bool HasAttribute(CTFBot::AttributeType attr, int index);
	virtual bool HasEventChangeAttributes(const char *name) const;
	
private:
	CUtlVector<IPopulationSpawner *> m_SubSpawners; // +0x08
	// 0x1c CUtlVector<int> spawn history perhaps
	// 0x30 dword seed or something
};


bool ParseDynamicAttributes(CTFBot::EventChangeAttributes_t& ecattr, KeyValues *kv);
