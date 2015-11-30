/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_move_to_build.h
 * used in MvM: TODO
 */


// sizeof: 0x4848
class CTFBotEngineerMoveToBuild : public Action<CTFBot>
{
public:
	CTFBotEngineerMoveToBuild(/* TODO */);
	virtual ~CTFBotEngineerMoveToBuild();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnTerritoryLost(CTFBot *actor, int i1) override;
	
private:
	void CollectBuildAreas(CTFBot *actor);
	void SelectBuildLocation(CTFBot *actor);
	
	// TODO
};


// TODO: CompareRangeToPoint(CTFNavArea *const *, CTFNavArea *const *)
