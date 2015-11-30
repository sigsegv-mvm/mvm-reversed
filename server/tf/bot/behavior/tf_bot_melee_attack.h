/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_melee_attack.h
 * used in MvM: TODO
 */


// sizeof: 0x4838
class CTFBotMeleeAttack : public Action<CTFBot>
{
public:
	CTFBotMeleeAttack(float f1);
	virtual ~CTFBotMeleeAttack();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
