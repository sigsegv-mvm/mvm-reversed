/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/nav_entities/tf_bot_nav_ent_destroy_entity.h
 * used in MvM: TODO
 */


// sizeof: TODO (>=0x4818)
class CTFBotNavEntDestroyEntity : public Action<CTFBot>
{
public:
	CTFBotNavEntDestroyEntity(const CFuncNavPrerequisite *prereq);
	virtual ~CTFBotNavEntDestroyEntity();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
private:
	void DetonateStickiesWhenSet(CTFBot *actor, CTFPipebombLauncher *launcher) const;
	
	// TODO
};
