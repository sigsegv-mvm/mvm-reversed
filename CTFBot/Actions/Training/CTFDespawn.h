/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * CTFBot actions: training: despawn
 * used in MvM: TODO
 */


class CTFDespawn : public Action<CTFBot>
{
public:
	CTFDespawn(/* TODO */);
	virtual ~CTFDespawn();
	
	virtual const char *GetName() const override;
	
	virtual ActionResult<CTFBot> Update(CTFBot *actor, float f1) override;
	
private:
	// TODO
};
