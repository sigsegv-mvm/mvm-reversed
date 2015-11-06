class INextBotEventResponder
{
};


class INextBotComponent : public INextBotEventResponder
{
};


class INextBot : public INextBotEventResponder
{
};


class NextBotCombatCharacter : public CBaseCombatCharacter, public INextBot
{
};


class INextBotPlayerInput
{
};


template<class T> class NextBotPlayer :
	public T, public INextBot, public INextBotPlayerInput
{
};
template<> class NextBotPlayer<CTFPlayer>;



class CKnownEntity
{
};


class INextBotEntityFilter
{
};


class INextBotFilter
{
};


class IPathCost
{
};


class NextBotManager
{
};


// derived from INextBotFilter:
// CHealthFilter
// CAmmoFilter (only in osx server classgraph)

// derived from INextBotEntityFilter:
// CUsefulHealTargetFilter
