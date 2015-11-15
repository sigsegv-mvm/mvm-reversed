/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Pathfinding: chase path
 */


class ChasePath : public PathFollower
{
public:
	ChasePath(/* TODO */);
	virtual ~ChasePath();
	
	virtual UNKNOWN Invalidate() override;
	
	virtual UNKNOWN Update(INextBot *nextbot, CBaseEntity *ent, const IPathCost& cost, Vector *v1);
	virtual UNKNOWN GetLeadRadius() const;
	virtual UNKNOWN GetMaxPathLength() const;
	virtual UNKNOWN PredictSubjectPosition(INextBot *nextbot, CBaseEntity *ent) const;
	virtual UNKNOWN IsRepathNeeded(INextBot *nextbot, CBaseEntity *ent) const;
	virtual UNKNOWN GetLifetime() const;
	
	UNKNOWN RefreshPath(INextBot *nextbot, CBaseEntity *ent, const IPathCost& cost, Vector *v1);
	
protected:
	// TODO
	
private:
	// TODO
};


// TODO: look at DirectChasePath
