/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Pathfinding: path cost functor
 */


class IPathCost
{
public:
	virtual float operator()(CNavArea *area1, CNavArea *area2, const CNavLadder *ladder, const CFuncElevator *elevator, float f1) const = 0;
};

class CHeadlessHatmanPathCost : public IPathCost
{
	// TODO
};

class CMerasmusPathCost : public IPathCost
{
	// TODO
};

class CRobotPathCost : public IPathCost
{
	// TODO
};

class CSimpleBotPathCost : public IPathCost
{
	// TODO
};

class CTFBotPathCost : public IPathCost
{
public:
	// TODO: enum RouteType
	// has value 1
	// has value 2
	// may or may not have value 0
	
	CTFBotPathCost(CTFBot *actor, RouteType rtype);
	~CTFBotPathCost();
	
	virtual float operator()(CNavArea *area1, CNavArea *area2, const CNavLadder *ladder, const CFuncElevator *elevator, float f1) const override;
	
	// CTFBotPathCost ctor is only in certain versions
	// (e.g. ServerLinux 20140619a)
	
	// ctor is called by:
	// CTFBotPushToCapturePoint::Update (RouteType=1)
	// CTFBotDeliverFlag::Update (RouteType=1)
	
private:
	// 04 CTFBot *actor
	// 08 RouteType rtype
	// 0c float, result of ILocomotion::GetStepHeight
	// 10 float, result of ILocomotion::GetMaxJumpHeight
	// 14 float, result of ILocomotion::GetDeathDropHeight
	// 18 CUtlVector<CBaseObject *>
};

class CTFPlayertPathCost : public IPathCost
{
	// TODO
};

class CZombiePathCost : public IPathCost
{
	// TODO
};
