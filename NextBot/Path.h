/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * NextBot: pathfinding
 */


class IPathCost
{
public:
	virtual float operator()(CNavArea *area1, CNavArea *area2, const CNavLadder *ladder, const CFuncElevator *elevator, float f1) const = 0;
};


class Path
{
public:
	class Segment // or struct?
	{
		// TODO
	};
	
	enum SeekType
	{
		// TODO
	};
	
	enum MoveCursorType
	{
		// TODO
	};
	
	enum ResultType
	{
		// TODO
	};
	
	Path();
	virtual ~Path();
	
	virtual GetLength() const;
	
	virtual GetPosition(float f1, const Segment *seg) const;
	virtual GetClosestPosition(const Vector& v1, const Segment *seg, float f1) const;
	virtual GetStartPosition() const;
	virtual GetEndPosition() const;
	
	virtual GetSubject() const;
	virtual GetCurrentGoal() const;
	virtual GetAge() const;
	
	virtual MoveCursorToClosestPosition(const Vector&, SeekType stype, float f1) const;
	virtual MoveCursorToStart();
	virtual MoveCursorToEnd();
	virtual MoveCursor(float f1, MoveCursorType mctype);
	
	virtual GetCursorPosition() const;
	virtual GetCursorData() const;
	
	virtual IsValid() const;
	virtual Invalidate();
	
	virtual Draw(const Segment *seg) const;
	virtual DrawInterpolated(float f1, float f2);
	
	virtual FirstSegment() const;
	virtual NextSegment(const Segment *seg) const;
	virtual PriorSegment(const Segment *seg) const;
	virtual LastSegment() const;
	
	virtual OnPathChanged(INextBot *nextbot, ResultType rtype);
	
	virtual Copy(INextBot *nextbot, const Path& that);
	
	virtual ComputeWithOpenGoal(INextBot *nextbot, const IPathCost& cost, const IPathOpenGoalSelector& sel, float f1);
	virtual ComputeAreaCrossing(INextBot *nextbot, const CNavArea *area1, const Vector& v1, const CNavArea *area2, NavDirType ndtype, Vector *v2) const;
	
	UNKNOWN AssemblePrecomputedPath(INextBot *nextbot, const Vector& v1, CNavArea *area);
	UNKNOWN BuildTrivialPath(INextBot *nextbot, const Vector& v1);
	UNKNOWN FindNextOccludedNode(INextBot *nextbot, int i1);
	UNKNOWN InsertSegment(Segment seg, int i1);
	UNKNOWN Optimize(INextBot *nextbot);
	UNKNOWN PostProcess();
	
	template<class T> Compute(INextBot *nextbot, const Vector& v1, T&, float f1, bool b1);
	
protected:
	// TODO
	
private:
	// TODO
};


class PathFollower : public Path
{
public:
	PathFollower(/* TODO */);
	virtual ~PathFollower();
	
	virtual UNKNOWN GetCurrentGoal() const override;
	
	virtual UNKNOWN Invalidate() override;
	
	virtual UNKNOWN Draw(const Segment *seg) const override;
	
	virtual UNKNOWN OnPathChanged(INextBot *nextbot, ResultType rtype) override;
	
	virtual UNKNOWN Update(INextBot *nextbot);
	virtual UNKNOWN SetMinLookAheadDistance(float f1);
	virtual UNKNOWN GetHindrance() const;
	virtual UNKNOWN IsDiscontinuityAhead(INextBot *nextbot, SegmentType stype, float f1) const;
	
	UNKNOWN Climbing(INextBot *nextbot, const Segment *seg, const Vector& v1, const Vector& v2, float f1);
	UNKNOWN JumpOverGaps(INextBOt *nextbot, const Segment *seg, const Vector& v1, const Vector& v2, float f1);
	
protected:
	// TODO
	
private:
	// TODO
};


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


// TODO: IPathOpenGoalSelector
// TODO: NavDirType
// TODO: CTFPathFollower
// TODO: CTFBotPathCost
// TODO: CTFPlayertPathCost
