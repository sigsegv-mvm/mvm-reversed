/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: core stuff
 */


enum NextBotDebugType
{
	// TODO
};


class NextBotCombatCharacter : public CBaseCombatCharacter, public INextBot
{
public:
	virtual ~NextBotCombatCharacter();
	
	/* CBaseCombatCharacter overrides */
	// TODO
	
	/* INextBot overrides */
	virtual void OnNavAreaChanged(CNavArea *area1, CNavArea *area2) override;
	virtual CBaseEntity *GetEntity() const override;
	virtual NextBotCombatCharacter *GetNextBotCombatCharacter() const override;
	
	// TODO: non-virtual functions
	
protected:
	// TODO
	
private:
	// TODO
};


class INextBotEntityFilter
{
public:
	// TODO
	
protected:
	// TODO
	
private:
	// TODO
};

class CUsefulHealTargetFilter : INextBotEntityFilter
{
public:
	// TODO
};


class INextBotFilter
{
public:
	// TODO
	
protected:
	// TODO
	
private:
	// TODO
};

class CHealthFilter : INextBotFilter
{
public:
	// TODO
};

class CAmmoFilter : INextBotFilter
{
public:
	// TODO
};


class NextBotManager
{
public:
	// TODO
	
protected:
	// TODO
	
private:
	// TODO
};
