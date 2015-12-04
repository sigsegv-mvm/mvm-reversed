/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/tf_bot_vision.h
 */


class CTFBotVision : public IVision
{
public:
	CTFBotVision(INextBot *nextbot);
	virtual ~CTFBotVision();
	
	virtual void Update() override;
	
	virtual void CollectPotentiallyVisibleEntities(CUtlVector<CBaseEntity *> *ents) override;
	virtual float GetMaxVisionRange() const override;
	virtual float GetMinRecognizeTime() const override;
	virtual bool IsIgnored(CBaseEntity *ent) const override;
	virtual bool IsVisibleEntityNoticed(CBaseEntity *ent) const override;
	
private:
	void UpdatePotentiallyVisibleNPCVector();
	
	// TODO
	// 64 
	// 68 
	// 6c 
	// 70 
	// 74 
	// 78 
	// 7c 
	// 80 
	// 84 
	// 88 
	// 8c 
	// 90 
	// 94 
	// 98 
	// 9c 
	// a0 
	// a4 
	// a8 
	// ac 
	// b0 
	// b4 
	// b8 
	// bc 
	// c0 
	// c4 CUtlVector<CHandle<CBaseCombatCharacter>>
	// d8 CountdownTimer
	// e4 CountdownTimer
};
