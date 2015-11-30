/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/tf_bot_squad.h
 */


class CTFBotSquad : public INextBotEventResponder
{
public:
	CTFBotSquad();
	virtual ~CTFBotSquad();
	
	virtual INextBotEventResponder *FirstContainedResponder() const;
	virtual INextBotEventResponder *NextContainedResponder(INextBotEventResponder *) const;
	
	struct Iterator
	{
		// 0x00
		// 0x04
	};
	
	void CollectMembers(CUtlVector<CTFBot *> *) const;
	
	Iterator GetFirstMember() const;
	Iterator GetNextMember(CTFBotSquad::Iterator const&) const;
	
	int GetMemberCount() const;
	CTFBot *GetLeader() const;
	
	void Join(CTFBot *);
	void Leave(CTFBot *);
	
	float GetMaxSquadFormationError() const;
	float GetSlowestMemberIdealSpeed(bool) const;
	float GetSlowestMemberSpeed(bool) const;
	
	bool IsInFormation() const;
	bool ShouldSquadLeaderWaitForFormation() const;
	
private:
	void DisbandAndDeleteSquad();
	
	CUtlVector<CHandle<CTFBot>> m_Members; // +0x04
	CHandle<CTFBot> m_hLeader;             // +0x18
	float m_flFormationSize;               // +0x1c
	bool m_bShouldPreserveSquad;           // +0x20
};
