/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: replies
 */


class INextBotReply
{
public:
	enum class FailureReason : int
	{
		// TODO
	};
	
	virtual void OnSuccess(INextBot *nextbot);
	virtual void OnFail(INextBot *nextbot, FailureReason reason);
};


class PressFireButtonReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
};

class PressAltFireButtonReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
};

class PressFireButtonIfValidBuildPositionReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
};

class PressJumpButtonReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
};

class PlaceStickyBombReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
	virtual void OnFail(INextBot *nextbot, FailureReason reason) override;
};
