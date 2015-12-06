/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/engineer/tf_bot_engineer_build_sentrygun.h
 * used in MvM: TODO
 */


// sizeof: 0x486c
class CTFBotEngineerBuildSentryGun : public Action<CTFBot>
{
public:
	CTFBotEngineerBuildSentryGun(CTFBotHintSentrygun *hint);
	virtual ~CTFBotEngineerBuildSentryGun();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
private:
	// TODO
};
