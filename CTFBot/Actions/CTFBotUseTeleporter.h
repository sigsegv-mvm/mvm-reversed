/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: use teleporter
 * used in MvM: TODO
 */


// sizeof: 0x4820
class CTFBotUseTeleporter : public Action<CTFBot>
{
public:
	enum class UseHowType : int
	{
		// TODO
	};
	
	CTFBotUseTeleporter(CObjectTeleporter *teleporter, UseHowType how);
	virtual ~CTFBotUseTeleporter();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> OnStart(CTFBot *actor, Action<CTFBot> *action) override;
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
	bool IsTeleporterAvailable() const;
	
private:
	// TODO
};
