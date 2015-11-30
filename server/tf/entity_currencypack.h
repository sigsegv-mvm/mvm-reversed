/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/entity_currencypack.h
 */


// TODO: ICurrencyPackAutoList
// TODO: IBonusPackAutoList


class CCurrencyPack : public CTFPowerup, public ICurrencyPackAutoList
{
public:
	// TODO
};

class CBonusPack : public CCurrencyPack, public IBonusPackAutoList
{
public:
	// TODO
};
