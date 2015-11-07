



class INextBotPlayerInput
{
public:
	virtual UNKNOWN PressFireButton(float f1) = 0;
	virtual UNKNOWN ReleaseFireButton() = 0;
	virtual UNKNOWN PressAltFireButton(float f1) = 0;
	virtual UNKNOWN ReleaseAltFireButton() = 0;
	virtual UNKNOWN PressMeleeButton(float f1) = 0;
	virtual UNKNOWN ReleaseMeleeButton() = 0;
	virtual UNKNOWN PressUseButton(float f1) = 0;
	virtual UNKNOWN ReleaseUseButton() = 0;
	virtual UNKNOWN PressReloadButton(float f1) = 0;
	virtual UNKNOWN ReleaseReloadButton() = 0;
	virtual UNKNOWN PressForwardButton(float f1) = 0;
	virtual UNKNOWN ReleaseForwardButton() = 0;
	virtual UNKNOWN PressBackwardButton(float f1) = 0;
	virtual UNKNOWN ReleaseBackwardButton() = 0;
	virtual UNKNOWN PressLeftButton(float f1) = 0;
	virtual UNKNOWN ReleaseLeftButton() = 0;
	virtual UNKNOWN PressRightButton(float f1) = 0;
	virtual UNKNOWN ReleaseRightButton() = 0;
	virtual UNKNOWN PressJumpButton(float f1) = 0;
	virtual UNKNOWN ReleaseJumpButton() = 0;
	virtual UNKNOWN PressCrouchButton(float f1) = 0;
	virtual UNKNOWN ReleaseCrouchButton() = 0;
	virtual UNKNOWN PressWalkButton(float f1) = 0;
	virtual UNKNOWN ReleaseWalkButton() = 0;
	virtual UNKNOWN SetButtonScale(float f1, float f2) = 0;
	
protected:
	// TODO
	
private:
	// TODO
};


template<class T>
class NextBotPlayer : public T, public INextBot, public INextBotPlayerInput
{
public:
	virtual ~NextBotPlayer();
	
	/* T overrides */
	// TODO
	
	/* INextBot overrides */
	virtual void OnNavAreaChanged(CNavArea *area1, CNavArea *area2);
	virtual UNKNOWN Update();
	virtual UNKNOWN IsRemovedOnReset() const;
	virtual UNKNOWN GetEntity() const;
	
	/* INextBotPlayerInput overrides */
	virtual UNKNOWN PressFireButton(float f1);
	virtual UNKNOWN ReleaseFireButton();
	virtual UNKNOWN PressAltFireButton(float f1);
	virtual UNKNOWN ReleaseAltFireButton();
	virtual UNKNOWN PressMeleeButton(float f1);
	virtual UNKNOWN ReleaseMeleeButton();
	virtual UNKNOWN PressUseButton(float f1);
	virtual UNKNOWN ReleaseUseButton();
	virtual UNKNOWN PressReloadButton(float f1);
	virtual UNKNOWN ReleaseReloadButton();
	virtual UNKNOWN PressForwardButton(float f1);
	virtual UNKNOWN ReleaseForwardButton();
	virtual UNKNOWN PressBackwardButton(float f1);
	virtual UNKNOWN ReleaseBackwardButton();
	virtual UNKNOWN PressLeftButton(float f1);
	virtual UNKNOWN ReleaseLeftButton();
	virtual UNKNOWN PressRightButton(float f1);
	virtual UNKNOWN ReleaseRightButton();
	virtual UNKNOWN PressJumpButton(float f1);
	virtual UNKNOWN ReleaseJumpButton();
	virtual UNKNOWN PressCrouchButton(float f1);
	virtual UNKNOWN ReleaseCrouchButton();
	virtual UNKNOWN PressWalkButton(float f1);
	virtual UNKNOWN ReleaseWalkButton();
	virtual UNKNOWN SetButtonScale(float f1, float f2);
	
	// TODO: non-virtual functions
	
protected:
	// TODO
	
private:
	// TODO
};
//template<> class NextBotPlayer<CTFPlayer>;
