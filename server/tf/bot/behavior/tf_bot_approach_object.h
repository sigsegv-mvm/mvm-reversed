/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_approach_object.h
 * used in MvM: TODO
 */


// sizeof: TODO
class CTFBotApproachObject : public Action<CTFBot>
{
public:
	CTFBotApproachObject(CBaseEntity *ent, float f1);
	virtual ~CTFBotApproachObject();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	
private:
	// TODO
};
