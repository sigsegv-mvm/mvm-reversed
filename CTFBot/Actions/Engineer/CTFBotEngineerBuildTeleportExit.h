/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: engineer: build teleport exit
 * used in MvM: TODO
 */


// sizeof: 0x484c
class CTFBotEngineerBuildTeleportExit : public Action<CTFBot>
{
public:
	CTFBotEngineerBuildTeleportExit();
	CTFBotEngineerBuildTeleportExit(const Vector& v1, float f1);
	virtual ~CTFBotEngineerBuildTeleportExit();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
private:
	// TODO
};
