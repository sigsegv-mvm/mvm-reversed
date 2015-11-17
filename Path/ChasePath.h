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
	CountdownTimer m_ctTimer1; // +0x47d4
	CountdownTimer m_ctTimer2; // +0x47e0
	CountdownTimer m_ctTimer3; // +0x47ec
	// 47f8 dword -1
	// 47fc dword 0
	CountdownTimer m_ctTimer4; // +0x4800
};

// TODO: struct and vtable in IDA

// TODO: look at DirectChasePath
