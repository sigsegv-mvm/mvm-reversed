/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_use_item.h
 * used in MvM: TODO
 */


// sizeof: 0x44
class CTFBotUseItem : public Action<CTFBot>
{
public:
	CTFBotUseItem(CTFWeaponBase *item);
	virtual ~CTFBotUseItem();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	virtual void OnEnd(CTFBot *actor, Action<CTFBot> *action) override;
	
private:
	// TODO
};
