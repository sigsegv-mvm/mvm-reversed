/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Pathfinding: path
 */


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
	
	virtual UNKNOWN GetLength() const;
	
	virtual UNKNOWN GetPosition(float f1, const Segment *seg) const;
	virtual UNKNOWN GetClosestPosition(const Vector& v1, const Segment *seg, float f1) const;
	virtual UNKNOWN GetStartPosition() const;
	virtual UNKNOWN GetEndPosition() const;
	
	virtual UNKNOWN GetSubject() const;
	virtual UNKNOWN GetCurrentGoal() const;
	virtual UNKNOWN GetAge() const;
	
	virtual UNKNOWN MoveCursorToClosestPosition(const Vector&, SeekType stype, float f1) const;
	virtual UNKNOWN MoveCursorToStart();
	virtual UNKNOWN MoveCursorToEnd();
	virtual UNKNOWN MoveCursor(float f1, MoveCursorType mctype);
	
	virtual UNKNOWN GetCursorPosition() const;
	virtual UNKNOWN GetCursorData() const;
	
	virtual UNKNOWN IsValid() const;
	virtual UNKNOWN Invalidate();
	
	virtual UNKNOWN Draw(const Segment *seg) const;
	virtual UNKNOWN DrawInterpolated(float f1, float f2);
	
	virtual UNKNOWN FirstSegment() const;
	virtual UNKNOWN NextSegment(const Segment *seg) const;
	virtual UNKNOWN PriorSegment(const Segment *seg) const;
	virtual UNKNOWN LastSegment() const;
	
	virtual UNKNOWN OnPathChanged(INextBot *nextbot, ResultType rtype);
	
	virtual UNKNOWN Copy(INextBot *nextbot, const Path& that);
	
	virtual UNKNOWN ComputeWithOpenGoal(INextBot *nextbot, const IPathCost& cost, const IPathOpenGoalSelector& sel, float f1);
	virtual UNKNOWN ComputeAreaCrossing(INextBot *nextbot, const CNavArea *area1, const Vector& v1, const CNavArea *area2, NavDirType ndtype, Vector *v2) const;
	
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
