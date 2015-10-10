/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: spawners
 */


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
	// TODO
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
	Event     *m_OnKilledOutput;      // +0x1c
	Event     *m_OnBombDroppedOutput; // +0x20
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
	// TODO
	int m_iHealth; // +0x10
	// TODO
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
	// TODO
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
	// TODO
};
