/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * shared/tf/tf_upgrades_shared.h
 */


// sizeof: 0x15c
struct CMannVsMachineUpgrades
{
	// TODO
};


// sizeof: 0x3c
class CMannVsMachineUpgradeManager : public CAutoGameSystem
{
public:
	CMannVsMachineUpgradeManager();
	virtual ~CMannVsMachineUpgradeManager();
	
	virtual UNKNOWN LevelInitPostEntity() override;
	virtual UNKNOWN LevelShutdownPostEntity() override;
	
	UNKNOWN LoadUpgradesFile();
	UNKNOWN LoadUpgradesFileFromPath(const char *path);
	
private:
	UNKNOWN GetAttributeIndexByName(const char *name);
	UNKNOWN ParseUpgradeBlockForUIGroup(KeyValues *kv, int ui_group);
	
	// TODO
};


UNKNOWN GetUpgradeStepData(CTFPlayer *player, int i1, int i2, int& i3, bool& b1);
