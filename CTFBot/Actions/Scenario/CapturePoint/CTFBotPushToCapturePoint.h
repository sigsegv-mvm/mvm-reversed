/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: scenario cp: push to capture point
 * used in MvM: TODO
 */


// sizeof: 0x4818
class CTFBotPushToCapturePoint : public Action<CTFBot>
{
public:
	CTFBotPushToCapturePoint(Action<CTFBot> *action);
	virtual ~CTFBotPushToCapturePoint();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual EventDesiredResult<CTFBot> OnNavAreaChanged(CTFBot *actor, CNavArea *area1, CNavArea *area2) override;
	
private:
	// TODO
};
