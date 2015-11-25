/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * NextBot: manager
 */


// TODO: NextBotManager::DebugFilter
// is it a typedef'd int? is it a structure? probably not a class though

class NextBotManager
{
public:
	NextBotManager();
	virtual ~NextBotManager();
	
	virtual UNKNOWN Update();
	virtual UNKNOWN OnMapLoaded();
	virtual UNKNOWN OnRoundRestart();
	virtual UNKNOWN OnBeginChangeLevel();
	virtual UNKNOWN OnKill(CBaseCombatCharacter *who, const CTakeDamageInfo& info);
	virtual UNKNOWN OnSound(CBaseEntity *ent, const Vector& where, KeyValues *kv);
	virtual UNKNOWN OnSpokeConcept(CBaseCombatCharacter *who, const char *s1, AI_Response *a1);
	virtual UNKNOWN OnWeaponFired(CBaseCombatCharacter *who1, CBaseCombatCharacter *who2);
	
	UNKNOWN CollectAllBots(CUtlVector<INextBot *> *nextbots);
	
	UNKNOWN OnKilled(CBaseCombatCharacter* who, const CTakeDamageInfo& info);
	UNKNOWN GetBotUnderCrosshair(CBasePlayer *player);
	
	UNKNOWN DebugFilterAdd(const char *s1);
	UNKNOWN DebugFilterAdd(int i1);
	UNKNOWN DebugFilterClear();
	UNKNOWN DebugFilterRemove(const char *s1);
	UNKNOWN DebugFilterRemove(int i1);
	UNKNOWN IsDebugFilterMatch(const INextBot *nextbot) const;
	
	UNKNOWN ShouldUpdate(INextBot *nextbot);
	UNKNOWN NotifyBeginUpdate(INextBot *nextbot);
	UNKNOWN NotifyEndUpdate(INextBot *nextbot);
	
	UNKNOWN Register(INextBot *nextbot);
	UNKNOWN UnRegister(INextBot *nextbot);
	
	static UNKNOWN sInstance;
	
protected:
	UNKNOWN Reset();
	
	// TODO
};

class TFBotManager : public NextBotManager
{
public:
	// TODO
	
private:
	// TODO
};


NextBotManager *TheNextBots();
TFBotManager   *TheTFBots();
