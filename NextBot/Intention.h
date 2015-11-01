class IContextualQuery
{
};


class IIntention : public INextBotComponent, public IContextualQuery
{
};


class CBotNPCArcher::CBotNPCArcherIntention : public IIntention
{
};


class CBotNPCDecoy::CBotNPCDecoyIntention : public IIntention
{
};


class CEyeballBoss::CEyeballBossIntention : public IIntention
{
};


class CGhost::CGhostIntention : public IIntention
{
};


class CHeadlessHatmanIntention : public IIntention
{
};


class CMerasmusIntention : public IIntention
{
};


class CRobot::CRobotIntention : public IIntention
{
};


class CSimpleBot::CSimpleBotIntention : public IIntention
{
};


// sizeof: 0x1c
class CTFBot::CTFBotIntention : public IIntention
{
};


class CZombieIntention : public IIntention
{
};
