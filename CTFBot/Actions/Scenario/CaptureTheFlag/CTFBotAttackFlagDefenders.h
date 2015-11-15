/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: scenario ctf: attack flag defenders
 * used in MvM: TODO
 */


// sizeof: 0xd810 (sizeof base: 0x9014)
/* unusual: this is derived from CTFBotAttack, not Action<CTFBot> directly */
class CTFBotAttackFlagDefenders : public CTFBotAttack
{
public:
	CTFBotAttackFlagDefenders(float f1);
	virtual ~CTFBotAttackFlagDefenders();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
