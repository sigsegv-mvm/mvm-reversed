class ILocomotion : public INextBotComponent
{
};


class CEyeballBossLocomotion : public ILocomotion
{
};


class CMerasmusFlyingLocomotion : public ILocomotion
{
};


class NextBotGroundLocomotion : public ILocomotion
{
};


class CBotNPCDecoyLocomotion : public NextBotGroundLocomotion
{
};

class CGhostLocomotion : public NextBotGroundLocomotion
{
};

class CHeadlessHatmanLocomotion : public NextBotGroundLocomotion
{
};

class CMerasmusLocomotion : public NextBotGroundLocomotion
{
};

class CRobotLocomotion : public NextBotGroundLocomotion
{
};

class CTFBaseBossLocomotion : public NextBotGroundLocomotion
{
};

class CZombieLocomotion : public NextBotGroundLocomotion
{
};


class PlayerLocomotion : public ILocomotion
{
};

class CTFBotLocomotion : public PlayerLocomotion
{
};
