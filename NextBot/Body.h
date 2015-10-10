class IBody : public INextBotComponent
{
};


class CHeadlessHatmanBody : public IBody
{
};


class CMerasmusBody : public IBody
{
};


class CTFTankBossBody : public IBody
{
};


class CBotNPCBody : public IBody
{
};

class CEyeballBossBody : public CBotNPCBody
{
};


class PlayerBody : public IBody
{
};

class CTFBotBody : public PlayerBody
{
};
