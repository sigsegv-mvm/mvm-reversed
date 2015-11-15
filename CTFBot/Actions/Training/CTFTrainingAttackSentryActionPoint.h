/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: training: attack sentry action point
 * used in MvM: TODO
 */


class CTFTrainingAttackSentryActionPoint : public Action<CTFBot>
{
public:
	CTFTrainingAttackSentryActionPoint(/* TODO */);
	virtual ~CTFTrainingAttackSentryActionPoint();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
