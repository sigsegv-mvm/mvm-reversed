/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: missions: destroy sentries
 * used in MvM: TODO
 */


// sizeof: TODO (>=0x38)
class CTFBotMissionDestroySentries : public Action<CTFBot>
{
public:
	CTFBotMissionDestroySentries(CObjectSentrygun *sentry);
	virtual ~CTFBotMissionDestroySentries();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
	CObjectSentrygun *SelectSentryTarget(CTFBot *actor);
	
private:
	// TODO
};
