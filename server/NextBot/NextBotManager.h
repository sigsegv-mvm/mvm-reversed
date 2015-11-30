/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/NextBot/NextBotManager.h
 */


class NextBotManager
{
public:
	struct DebugFilter
	{
		// TODO
		// sizeof: 0x84
		
		// seems to have:
		// 00 int
		// 04 char[0x80]
	};
	
	NextBotManager();
	virtual ~NextBotManager();
	
	virtual void Update(); // has static int iCurFrame = -1
	virtual void OnMapLoaded();
	virtual void OnRoundRestart();
	virtual void OnBeginChangeLevel();
	virtual void OnKilled(CBaseCombatCharacter *who, const CTakeDamageInfo& info);
	virtual void OnSound(CBaseEntity *ent, const Vector& where, KeyValues *kv);
	virtual void OnSpokeConcept(CBaseCombatCharacter *who, const char *s1, AI_Response *a1);
	virtual void OnWeaponFired(CBaseCombatCharacter *who1, CBaseCombatCharacter *who2);
	
	void CollectAllBots(CUtlVector<INextBot *> *nextbots);
	
	INextBot *GetBotUnderCrosshair(CBasePlayer *player);
	
	void DebugFilterAdd(const char *s1);
	void DebugFilterAdd(int i1);
	void DebugFilterClear();
	void DebugFilterRemove(const char *s1);
	void DebugFilterRemove(int i1);
	bool IsDebugFilterMatch(const INextBot *nextbot) const;
	
	bool ShouldUpdate(INextBot *nextbot);
	void NotifyBeginUpdate(INextBot *nextbot);
	void NotifyEndUpdate(INextBot *nextbot);
	
	unsigned int Register(INextBot *nextbot);
	void UnRegister(INextBot *nextbot);
	
	static NextBotManager *sInstance = nullptr;
	
protected:
	void Reset();
	
	// TODO
	// 04 CUtlLinkedList<INextBot *> (sizeof: 0x1c)
	// 20 
	// ...
	// 34 
	// 38 CUtlVector<DebugFilter>
	// 4c 
};


NextBotManager *TheNextBots();


// TODO: TargetScan
