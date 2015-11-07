/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: vision component
 */


class IVision : public INextBotComponent
{
public:
	class IForEachKnownEntity
	{
		// TODO
	};
	
	enum class FieldOfViewCheckType : int
	{
		// TODO
	};
	
	IVision(INextBot *nextbot);
	virtual ~IVision();
	
	virtual void Reset() override;
	virtual void Update() override;
	
	virtual bool ForEachKnownEntity(IForEachKnownEntity& functor);
	virtual void CollectKnownEntities(CUtlVector<CKnownEntity> *ents);
	virtual const CKnownEntity& GetPrimaryKnownThreat(bool b1) const;
	virtual float GetTimeSinceVisible(int i1) const;
	virtual const CKnownEntity& GetClosestKnown(int i1) const;
	virtual int GetKnownCount(int i1, bool b1, float f1) const;
	virtual const CKnownEntity& GetClosestKnown(const INextBotEntityFilter& filter) const;
	virtual const CKnownEntity& GetKnown(const CBaseEntity *ent) const;
	virtual void AddKnownEntity(CBaseEntity *ent);
	virtual void ForgetEntity(CBaseEntity *ent);
	virtual void ForgetAllKnownEntities();
	virtual void CollectPotentiallyVisibleEntities(CUtlVector<CBaseEntity *> *ents);
	virtual float GetMaxVisionRange() const;
	virtual float GetMinRecognizeTime() const;
	virtual bool IsAbleToSee(CBaseEntity *ent, FieldOfViewCheckType ctype, Vector *v1) const;
	virtual bool IsAbleToSee(const Vector& vec, FieldOfViewCheckType ctype) const;
	virtual bool IsIgnored(CBaseEntity *ent) const;
	virtual bool IsVisibleEntityNoticed(CBaseEntity *ent) const;
	virtual bool IsInFieldOfView(const Vector& vec) const;
	virtual bool IsInFieldOfView(CBaseEntity *ent) const;
	virtual float GetDefaultFieldOfView() const;
	virtual float GetFieldOfView() const;
	virtual void SetFieldOfView(float fov);
	virtual bool IsLineOfSightClear(const Vector& v1) const;
	virtual bool IsLineOfSightClearToEntity(const CBaseEntity *ent, Vector *v1) const;
	virtual bool IsLookingAt(const Vector& v1, float f1) const;
	virtual bool IsLookingAt(const CBaseCombatCharacter *who, float f1) const;
	
protected:
	// TODO
};

class IVision : public INextBotComponent
{

	
	// TODO
};


class CDisableVision : public IVision
{
	// TODO
};


// sizeof: 0xf0
class CTFBotVision : public IVision
{
	// TODO
};
