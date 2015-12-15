class IPathCost
{
public:
	virtual float operator()(CNavArea *area1, CNavArea *area2, const CNavLadder *ladder, const CFuncElevator *elevator, float f1) const = 0;
};

class CHeadlessHatmanPathCost : public IPathCost
{
	// TODO
};

class CMerasmusPathCost : public IPathCost
{
	// TODO
};

class CRobotPathCost : public IPathCost
{
	// TODO
};

class CTFBotPathCost : public IPathCost
{
public:
	// TODO: enum RouteType (at base scope, from public server/nav_pathfind.h)
	
	CTFBotPathCost(CTFBot *actor, RouteType rtype);
	~CTFBotPathCost();
	
	virtual float operator()(CNavArea *area1, CNavArea *area2, const CNavLadder *ladder, const CFuncElevator *elevator, float f1) const override;
	
	// CTFBotPathCost ctor is only in certain versions
	// (e.g. ServerLinux 20140619a)
	
	// ctor is called by:
	// CTFBotPushToCapturePoint::Update (RouteType=1)
	// CTFBotDeliverFlag::Update (RouteType=1)
	
private:
	CTFBot *m_Actor;                          // +0x04
	RouteType m_iRouteType;                   // +0x08
	float m_flStepHeight;                     // +0x0c
	float m_flMaxJumpHeight;                  // +0x10
	float m_flDeathDropHeight;                // +0x14
	CUtlVector<CBaseObject *> m_EnemyObjects; // +0x18
};

CTFBotPathCost(CTFBot *actor, RouteType rtype)
	: m_Actor(actor), m_iRouteType(rtype)
{
	this->m_flStepHeight      = actor->GetLocomotionInterface()->GetStepHeight();
	this->m_flMaxJumpHeight   = actor->GetLocomotionInterface()->GetMaxJumpHeight();
	this->m_flDeathDropHeight = actor->GetLocomotionInterface()->GetDeathDropHeight();
	
	if (actor->IsPlayerClass(TF_CLASS_SPY)) {
		TheNavMesh()->CollectBuiltObjects(&this->m_EnemyObjects,
			GetEnemyTeam(actor));
	} else {
		this->m_EnemyObjects.RemoveAll();
	}
}


class CTFPlayertPathCost : public IPathCost
{
	// TODO
};

class CZombiePathCost : public IPathCost
{
	// TODO
};


inline CBasePlayer *ToBasePlayer(CBaseEntity *pEntity)
{
	if (pEntity == nullptr || !pEntity->IsPlayer()) {
		return nullptr;
	}
	
	return static_cast<CBasePlayer *>(pEntity);
}

inline CTFPlayer *ToTFPlayer(CBaseEntity *pEntity)
{
	if (pEntity == nullptr || !pEntity->IsPlayer()) {
		return nullptr;
	}
	
	return static_cast<CTFPlayer *>(pEntity);
}

inline CTFBot *ToTFBot(CBaseEntity *pEntity)
{
	CBasePlayer *player = ToBasePlayer(pEntity);
	
	if (player == nullptr || !player->IsBotOfType(1337)) {
		return nullptr;
	}
	
	return static_cast<CTFBot *>(player);
}


// TODO: GetBombInfo(BombInfo_t *)
// TODO: BombInfo_t


class CHeadlessHatmanBody : public IBody
{
	// TODO
};


class CMerasmusBody : public IBody
{
	// TODO
};


class CBotNPCBody : public IBody
{
	// TODO
};

class CEyeballBossBody : public CBotNPCBody
{
	// TODO
};


class CBotNPCArcher::CBotNPCArcherIntention : public IIntention
{
	// TODO
};


class CBotNPCDecoy::CBotNPCDecoyIntention : public IIntention
{
	// TODO
};


class CEyeballBoss::CEyeballBossIntention : public IIntention
{
	// TODO
};


class CGhost::CGhostIntention : public IIntention
{
	// TODO
};


class CHeadlessHatmanIntention : public IIntention
{
	// TODO
};


class CMerasmusIntention : public IIntention
{
	// TODO
};


class CRobot::CRobotIntention : public IIntention
{
	// TODO
};


class CZombieIntention : public IIntention
{
	// TODO
};


class CEyeballBossLocomotion : public ILocomotion
{
	// TODO
};


class CMerasmusFlyingLocomotion : public ILocomotion
{
	// TODO
};


class CBotNPCDecoyLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CGhostLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CHeadlessHatmanLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CMerasmusLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CRobotLocomotion : public NextBotGroundLocomotion
{
	// TODO
};

class CZombieLocomotion : public NextBotGroundLocomotion
{
	// TODO
};


class CDisableVision : public IVision
{
	// TODO
};


union attribute_data_union_t
{
	// TODO
};


class ISchemaAttributeType
{
public:
	virtual ~ISchemaAttributeType();
	
	UNKNOWN GetTypeUniqueIdentifier();
	UNKNOWN LoadEconAttributeValue(CEconItem *, CEconItemAttributeDefinition const*, attribute_data_union_t const&);
	UNKNOWN ConvertEconAttributeValueToByteStream(attribute_data_union_t const&, std::string *);
	UNKNOWN BConvertStringToEconAttributeValue(CEconItemAttributeDefinition const*, const char *, attribute_data_union_t *, bool);
	UNKNOWN ConvertEconAttributeValueToString(CEconItemAttributeDefinition const*, attribute_data_union_t const&, std::string *);
	UNKNOWN LoadByteStreamToEconAttributeValue(CEconItem *, CEconItemAttributeDefinition const*, std::string const&);
	UNKNOWN InitializeNewEconAttributeValue(attribute_data_union_t *);
	UNKNOWN UnloadEconAttributeValue(attribute_data_union_t *);
	UNKNOWN OnIterateAttributeValue(IEconItemAttributeIterator *, CEconItemAttributeDefinition const*, attribute_data_union_t const&);
	UNKNOWN BSupportsGameplayModificationAndNetworking();
};


struct CEconItemAttributeDefinition
{
	CEconItemAttributeDefinition();
	
	bool BInitFromKV(KeyValues *kv, CUtlVector<CUtlString> *errors);
	
	KeyValues *m_KeyValues;                // +0x00
	unsigned short m_iIndex;               // +0x04
	ISchemaAttributeType *m_AttributeType; // +0x08
	bool m_bHidden;                        // +0x0c
	bool m_bForceOutputDescription;        // +0x0d
	bool m_bStoreAsInteger;                // +0x0e
	bool m_bInstanceData;                  // +0x0f
	bool m_bIsSetBonus;                    // +0x10
	int m_iIsUserGenerated;                // +0x14
	int m_iEffectType;                     // +0x18
	int m_iDescriptionFormat;              // +0x1c
	char *m_pszDescriptionString;          // +0x20
	char *m_pszArmoryDesc;                 // +0x24
	char *m_pszName;                       // +0x28
	char *m_pszAttributeClass;             // +0x2c
	bool m_bCanAffectMarketName;           // +0x30
	bool m_bCanAffectRecipeCompName;       // +0x31
	int m_nTagHandle;                      // +0x34
	// 0x38 dword ???
};


struct static_attrib_t
{
	bool BInitFromKV_SingleLine(const char *context, KeyValues *kv, CUtlVector<CUtlString> *errors, bool integer);
	
	unsigned short m_iAttrIndex;    // +0x00
	attribute_data_union_t m_Value; // +0x04
};


// TODO: fix these to not conflict with the definitions in shareddefs.h
#define COLOR_WHITE    Color(255, 255, 255, 255)
#define COLOR_GRAY100  Color(100, 100, 100, 255)
#define COLOR_RED      Color(255,   0,   0, 255)
#define COLOR_ORANGE   Color(255, 100,   0, 255)
#define COLOR_LTYELLOW Color(255, 255, 150, 255)
#define COLOR_GREEN    Color(  0, 255,   0, 255)
#define COLOR_LTGREEN  Color(150, 255, 150, 255)
#define COLOR_MAGENTA  Color(255,   0, 255, 255)

#define COLOR32_WHITE { .r = 255, .g = 255, .b = 255, .a = 255, }

#define RGB_GRAY100  100, 100, 100
#define RGB_YELLOW   255, 255,   0
#define RGB_LTYELLOW 255, 255, 100

#define RGBA_WHITE   255, 255, 255, 255
#define RGBA_RED     255,   0,   0, 255
#define RGBA_GREEN     0, 255,   0, 255
#define RGBA_CYAN      0, 255, 255, 255
#define RGBA_MAGENTA 255,   0, 255, 255


class INextBotEntityFilter
{
public:
	virtual bool IsAllowed(CBaseEntity *ent) const = 0;
};

class CUsefulHealTargetFilter : public INextBotEntityFilter
{
public:
	CUsefulHealTargetFilter(int teamnum);
	
	virtual bool IsAllowed(CBaseEntity *ent) const override;
	
private:
	int m_iTeamNum; // +0x04
};


class INextBotFilter
{
public:
	virtual bool IsSelected(const CBaseEntity *ent) const = 0;
};


CUsefulHealTargetFilter::CUsefulHealTargetFilter(int teamnum)
	: m_iTeamNum(teamnum)
{
}


bool CUsefulHealTargetFilter::IsAllowed(CBaseEntity *ent) const
{
	if (ent == nullptr || !ent->IsPlayer() ||
		ent->GetTeamNumber() != this->m_iTeamNum) {
		return false;
	}
	
	if (ToTFPlayer(ent)->IsPlayerClass(TF_CLASS_MEDIC) ||
		ToTFPlayer(ent)->IsPlayerClass(TF_CLASS_SNIPER)) {
		return false;
	}
	
	return true;
}


class INextBotReply
{
public:
	enum class FailureReason : int
	{
		REJECTED  = 0, // AimHeadTowards denied the aim
		PREEMPTED = 1, // a higher priority aim preempted our aim
	};
	
	virtual void OnSuccess(INextBot *nextbot);
	virtual void OnFail(INextBot *nextbot, FailureReason reason);
};


class PressFireButtonReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
};

class PressAltFireButtonReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
};

class PressFireButtonIfValidBuildPositionReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
};

class PressJumpButtonReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
};

class PlaceStickyBombReply : public INextBotReply
{
public:
	virtual void OnSuccess(INextBot *nextbot) override;
	virtual void OnFail(INextBot *nextbot, FailureReason reason) override;
};


bool IgnoreActorsTraceFilterFunction(IHandleEntity *pHandleEntity, int contentsMask);

class NextBotTraceFilterIgnoreActors : public CTraceFilterSimple
{
public:
	NextBotTraceFilterIgnoreActors(CBaseEntity *ent)
		: CTraceFilterSimple(ent, COLLISION_GROUP_NONE,
			IgnoreActorsTraceFilterFunction)
	{
	}
};


class NextBotTraceFilterOnlyActors : public CTraceFilterSimple
{
	// TODO
};


class NextBotTraversableTraceFilter : public CTraceFilterSimple
{
	// TODO
};


bool VisionTraceFilterFunction(IHandleEntity *pHandleEntity, int contentsMask);

class NextBotVisionTraceFilter : public CTraceFilterSimple
{
public:
	NextBotVisionTraceFilter(CBaseEntity *ent)
		: CTraceFilterSimple(ent, COLLISION_GROUP_NONE,
			VisionTraceFilterFunction)
	{
	}
};


class GroundLocomotionCollisionTraceFilter : public CTraceFilterSimple
{
	// TODO
};


bool IgnoreActorsTraceFilterFunction(IHandleEntity *pHandleEntity, int contentsMask)
{
	CBaseEntity *ent = EntityFromEntityHandle(pHandleEntity);
	return !ent->IsCombatCharacter();
}

bool VisionTraceFilterFunction(IHandleEntity *pHandleEntity, int contentsMask)
{
	CBaseEntity *ent = EntityFromEntityHandle(pHandleEntity);
	if (ent->IsCombatCharacter()) {
		return false;
	} else {
		return ent->BlocksLOS();
	}
}


/* I invented this function, because this particular idiom comes up frequently;
 * I can't seem to actually find it anywhere in the 2013 SDK or the 2007 leak,
 * so I don't know if it actually is an inlined function or just a copypasta */
inline int GetEnemyTeam(CBaseEntity *ent)
{
	int enemy_team = ent->GetTeamNumber();
	
	switch (enemy_team) {
	case TF_TEAM_RED:
		enemy_team = TF_TEAM_BLUE;
		break;
	case TF_TEAM_BLUE:
		enemy_team = TF_TEAM_RED;
		break;
	}
	
	return enemy_team;
}
