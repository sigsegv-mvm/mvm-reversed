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
	// TODO
};

class CTFPlayertPathCost : public IPathCost
{
	// TODO
};

class CZombiePathCost : public IPathCost
{
	// TODO
};
