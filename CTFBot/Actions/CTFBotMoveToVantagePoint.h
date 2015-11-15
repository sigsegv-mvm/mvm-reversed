/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: move to vantage point
 * used in MvM: TODO
 */


// sizeof: TODO
class CTFBotMoveToVantagePoint : public Action<CTFBot>
{
public:
	CTFBotMoveToVantagePoint(float f1);
	virtual ~CTFBotMoveToVantagePoint();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
private:
	// TODO
};
