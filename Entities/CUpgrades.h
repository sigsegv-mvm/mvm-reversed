/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Entities: upgrade station
 */


// ===============================================
// server/tf/player_vs_environment/tf_upgrades.cpp
// ===============================================

// sizeof: 0x48
struct UpgradeAttribBlock_t
{
	// 00 char[0x44]
	// 44 dword -1, probably handle
};


// sizeof: 0x4ac
// "func_upgradestation"
class CUpgrades : public CBaseTrigger, public CGameEventListener
{
public:
	CUpgrades(/* TODO */);
	virtual ~CUpgrades();
	
	virtual void Spawn() override;
	
	virtual UNKNOWN EndTouch(CBaseEntity *ent) override;
	
	virtual UNKNOWN InputEnable(inputdata_t& data) override;
	virtual UNKNOWN InputDisable(inputdata_t& data) override;
	
	virtual void FireGameEvent(IGameEvent *event) override;
	
	UNKNOWN InputReset(inputdata_t& data);
	
	UNKNOWN UpgradeTouch(CBaseEntity *ent);
	
	UNKNOWN ApplyUpgradeToItem(CTFPlayer *player, CEconItemView *item, int i1, int i2, bool b1, bool b2);
	UNKNOWN GetUpgradeAttributeName(int i1);
	UNKNOWN PlayerPurchasingUpgrade(CTFPlayer *player, int i1, int i2, bool b1, bool b2, bool b3);
	
	UNKNOWN GrantOrRemoveAllUpgrades(CTFPlayer *player, bool b1, bool b2);
	// known to exist: CUpgrades::GrantAllUpgrades(CTFPlayer*, bool)
	// (see server.dylib 20140212a)
	
private:
	UNKNOWN ApplyUpgradeAttributeBlock(UpgradeAttribBlock_t *block, int i1, CTFPlayer *player, bool b1);
	UNKNOWN NotifyItemOnUpgrade(CTFPlayer *player, unsigned short i1, bool b1);
	UNKNOWN ReportUpgrade(CTFPlayer *player, int i1, int i2, int i3, int i4, bool b1, bool b2, bool b3);
	
	UNKNOWN RestoreItemAttributeToBaseValue(CEconItemAttributeDefinition *def, CEconItemView *item);
	UNKNOWN RestorePlayerAttributeToBaseValue(CEconItemAttributeDefinition *def, CTFPlayer *player);
	
	// TODO
};

// TODO: ApplyUpgrade_Default(const CMannVsMachineUpgrades& upgrade, CTFPlayer *player, CEconItemView *item, int i1, bool b1);

// global static g_hUpgradeEntity, probably a CHandle<T>


// ================================
// shared/tf/tf_upgrades_shared.cpp
// ================================

// sizeof: 0x15c
struct CMannVsMachineUpgrades
{
	// TODO
};


UNKNOWN GetUpgradeStepData(CTFPlayer *player, int i1, int i2, int& i3, bool& b1);


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

CMannVsMachineUpgradeManager g_MannVsMachineUpgrades;
