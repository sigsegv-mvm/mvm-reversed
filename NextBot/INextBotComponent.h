/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * NextBot: components
 */


class INextBotComponent : public INextBotEventResponder
{
public:
	INextBotComponent(INextBot *nextbot);
	virtual ~INextBotComponent();
	
	virtual void Reset();
	virtual void Update() = 0;
	virtual void Upkeep();
	virtual INextBot *GetBot() const;
	
protected:
	int m_Dword04;       // +0x04
	float m_flTime1;     // +0x08
	INextBot *m_NextBot; // +0x0c
	// 0x10 ???
};
