/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot: intention component
 */


// sizeof: 0x1c
class CTFBot::CTFBotIntention : public IIntention
{
public:
	CTFBotIntention(CTFBot *actor);
	virtual ~CTFBotIntention();
	
	virtual INextBotEventResponder *FirstContainedResponder() const override;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *prev) const override;
	
	virtual void Reset() override;
	virtual void Update() override;
	
private:
	// TODO
};
