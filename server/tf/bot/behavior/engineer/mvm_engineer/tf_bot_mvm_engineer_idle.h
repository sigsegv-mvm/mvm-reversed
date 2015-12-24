/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/mvm_engineer/tf_bot_mvm_engineer_idle.h
 * used in MvM: TODO
 */


// sizeof: 0x4868
class CTFBotMvMEngineerIdle : public Action<CTFBot>
{
public:
	CTFBotMvMEngineerIdle(/* TODO */);
	virtual ~CTFBotMvMEngineerIdle();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	bool ShouldAdvanceNestSpot(CTFBot *actor);
	void TakeOverStaleNest(CBaseTFBotHintEntity *hint, CTFBot *actor);
	void TryToDetonateStaleNest();
	
	PathFollower m_PathFollower; // +0x0034
	// 4808 CountdownTimer
	// 4814 CountdownTimer
	// 4820 CountdownTimer
	// 482c CountdownTimer
	// 4838 CountdownTimer
	// 4844 CountdownTimer
	// 4850 
	// 4854 
	// 4858 dword -1
	// 485c dword -1
	// 4860 dword -1
	// 4864 
};


class CTFBotMvMEngineerHintFinder
{
public:
	static bool FindHint(bool box_check, bool out_of_range_ok, CHandle<CTFBotHintEngineerNest> *the_hint);
};


struct BombInfo_t
{
	Vector closest_pos;
	float hatch_dist_back;
	float hatch_dist_fwd;
};


CTFBotHintEngineerNest *SelectOutOfRangeNest(const CUtlVector<CTFBotHintEngineerNest *>& nests);
bool GetBombInfo(BombInfo_t *info);
