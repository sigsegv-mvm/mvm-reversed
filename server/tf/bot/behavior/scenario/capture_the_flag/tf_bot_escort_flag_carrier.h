/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/scenario/capture_the_flag/tf_bot_escort_flag_carrier.h
 * used in MvM: TODO
 */


// sizeof: 0x904c
class CTFBotEscortFlagCarrier : public Action<CTFBot>
{
public:
	CTFBotEscortFlagCarrier();
	virtual ~CTFBotEscortFlagCarrier();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float dt) override;
	
private:
	// 0034 PathFollower
	// 4808 CountdownTimer
	// 4814 CTFBotMeleeAttack
};


UNKNOWN GetBotEscortCount(int i1);
