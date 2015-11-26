/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot: vision component
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
	UNKNOWN UpdatePotentiallyVisibleNPCVector();
	
	// TODO
	// 64 
	// ...
	// c4 CUtlVector<CHandle<CBaseCombatCharacter>>
	// ...
	// ec
};
