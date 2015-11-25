/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot: squad
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
	void DisbandAndDeleteSquad();
	Iterator GetFirstMember() const;
	CTFBot *GetLeader() const;
	float GetMaxSquadFormationError() const;
	int GetMemberCount() const;
	Iterator GetNextMember(CTFBotSquad::Iterator const&) const;
	float GetSlowestMemberIdealSpeed(bool) const;
	float GetSlowestMemberSpeed(bool) const;
	bool IsInFormation() const;
	void Join(CTFBot *);
	void Leave(CTFBot *);
	bool ShouldSquadLeaderWaitForFormation() const;
	
private:
	CUtlVector<CHandle<CTFBot>> m_Members; // +0x04
	CHandle<CTFBot> m_hLeader;             // +0x18
	float m_flFormationSize;               // +0x1c
	bool m_bShouldPreserveSquad;           // +0x20
};
