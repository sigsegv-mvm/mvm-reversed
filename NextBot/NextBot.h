/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
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


class NextBotManager
{
public:
	// TODO
	
protected:
	// TODO
	
private:
	// TODO
};
