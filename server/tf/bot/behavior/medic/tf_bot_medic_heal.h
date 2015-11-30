/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/medic/tf_bot_medic_heal.h
 * used in MvM: TODO
 */


// sizeof: 0x9058
class CTFBotMedicHeal : public Action<CTFBot>
{
public:
	CTFBotMedicHeal();
	virtual ~CTFBotMedicHeal();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	virtual ActionResult<CTFBot> OnResume(CTFBot *actor, Action<CTFBot> *action) override;
	
	virtual EventDesiredResult<CTFBot> OnMoveToSuccess(CTFBot *actor, const Path *path) override;
	virtual EventDesiredResult<CTFBot> OnMoveToFailure(CTFBot *actor, const Path *path, MoveToFailureType fail) override;
	
	virtual EventDesiredResult<CTFBot> OnStuck(CTFBot *actor) override;
	
	virtual EventDesiredResult<CTFBot> OnActorEmoted(CTFBot *actor, CBaseCombatCharacter *who, int i1) override;
	
	virtual QueryResponse ShouldHurry(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldRetreat(const INextBot *nextbot) const override;
	virtual QueryResponse ShouldAttack(const INextBot *nextbot, const CKnownEntity *threat) const override;
	
private:
	UNKNOWN ComputeFollowPosition(CTFBot *actor);
	bool IsGoodUberTarget(CTFPlayer *player) const;
	bool IsReadyToDeployUber(const CWeaponMedigun *medigun) const;
	bool IsStable(CTFPlayer *player) const;
	bool IsVisibleToEnemy(CTFBot *actor, const Vector& v1) const;
	UNKNOWN SelectPatient(CTFBot *actor, CTFPlayer *player);
	
	// 0x0034 ChasePath
	// 0x4840 CountdownTimer
	// 0x484c dword -1, possibly CHandle<T>
	// 0x4850 Vector
	// 0x485c CountdownTimer
	// 0x4868 dword
	// 0x486c CountdownTimer
	// 0x4878 PathFollower
	// 0x9050 ???
	// 0x9054 ???
};


// TODO: CFindMostInjuredNeighbor : public IVision::IForEachKnownEntity
// TODO: CSelectPrimaryPatient (also: which file is it in?)
// TODO: CKnownCollector
