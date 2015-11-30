/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/spy/tf_bot_spy_hide.h
 * used in MvM: TODO
 */


// sizeof: 0x483c
class CTFBotSpyHide : public Action<CTFBot>
{
public:
	CTFBotSpyHide(CTFPlayer *player);
	virtual ~CTFBotSpyHide();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	UNKNOWN FindHidingSpot(CTFBot *actor);
	
	// TODO
};


// TODO: IncursionEntry_t
// TODO: SpyHideIncursionDistanceLess (sort functor)
