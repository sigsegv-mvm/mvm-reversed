/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: melee attack
 * used in MvM: TODO
 */


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
