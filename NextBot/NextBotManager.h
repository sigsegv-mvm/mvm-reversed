/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * NextBot: manager
 */


// TODO: CStuckBotEvent (sizeof: 0x4)

struct CStuckBot
{
	// TODO
	// sizeof: 0x118
	// CUtlVectorAutoPurge<CStuckBotEvent *> @ 0x104
};


class NextBotManager
{
public:
	struct DebugFilter
	{
		// TODO
		// sizeof: 0x84
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

class CTFBotManager : public NextBotManager
{
public:
	// TODO: class/struct/typedef CTFBotManager::ArcherAssignmentInfo
	
	CTFBotManager();
	virtual ~CTFBotManager();
	
	virtual void Update() override;
	virtual void OnMapLoaded() override;
	virtual void OnRoundRestart() override;
	
	void LevelShutdown();
	
	void ClearStuckBotData();
	void DrawStuckBotData(float f1);
	
	bool IsInOfflinePractice() const;
	void SetIsInOfflinePractice(bool b1);
	
	CTFBot *GetAvailableBotFromPool();
	bool RemoveBotFromTeamAndKick(int i1);
	
	void OnForceAddedBots(int i1);
	void OnForceKickedBots(int i1);
	
	CStuckBot *FindOrCreateStuckBot(int i1, const char *s1);
	bool IsAllBotTeam(int i1);
	bool IsMeleeOnly() const;
	
private:
	void MaintainBotQuota();
	void RevertOfflinePracticeConvars();
	
	// TODO
	// 50 
	// 54 
	// 58 CUtlVector<CBaseEntity *>
	// 6c CUtlVector<ArcherAssignmentInfo>
	// 80 
	// 84 
	// 88 
	// 8c CUtlVector<CStuckBot *>
	// a0 
	// a4 
	// a8 
};


NextBotManager *TheNextBots();
CTFBotManager  *TheTFBots();


/* global static */
int g_nBlockedSlides = 0;
int g_nSlid = 0;
int g_nRun = 0;
