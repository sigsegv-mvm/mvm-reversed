/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Pathfinding: path follower
 */


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

class CTFPathFollower : public PathFollower
{
	// TODO
};
