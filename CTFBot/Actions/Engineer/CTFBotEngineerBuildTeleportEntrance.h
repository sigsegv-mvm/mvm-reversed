/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: engineer: build teleport entrance
 * used in MvM: TODO
 */


// sizeof: 0x4808
class CTFBotEngineerBuildTeleportEntrance : public Action<CTFBot>
{
public:
	CTFBotEngineerBuildTeleportEntrance(/* TODO */);
	virtual ~CTFBotEngineerBuildTeleportEntrance();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
private:
	// TODO
};
