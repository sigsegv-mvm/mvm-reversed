/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: filters
 */


class INextBotEntityFilter
{
public:
	virtual bool IsAllowed(CBaseEntity *ent) const = 0;
};

class CUsefulHealTargetFilter : public INextBotEntityFilter
{
public:
	CUsefulHealTargetFilter(int teamnum);
	
	virtual bool IsAllowed(CBaseEntity *ent) const override;
	
private:
	int m_iTeamNum; // +0x04
};


class INextBotFilter
{
public:
	virtual bool IsSelected(const CBaseEntity *ent) const = 0;
};

class CHealthFilter : public INextBotFilter
{
public:
	CHealthFilter(CBaseEntity *actor);
	
	virtual bool IsSelected(const CBaseEntity *ent) const override;
	
private:
	CBaseEntity *m_Actor;
};

class CAmmoFilter : public INextBotFilter
{
public:
	CAmmoFilter(CBaseEntity *actor);
	
	virtual bool IsSelected(const CBaseEntity *ent) const override;
	
private:
	CBaseEntity *m_Actor;
};
