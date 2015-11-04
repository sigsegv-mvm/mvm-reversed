/* reverse engineering by sigsegv
 * based on TF2 version 20151002
 * Population: item schema attributes
 */


union attribute_data_union_t
{
	// TODO
};


class ISchemaAttributeType
{
public:
	virtual ~ISchemaAttributeType();
	
	??? GetTypeUniqueIdentifier();
	??? LoadEconAttributeValue(CEconItem *, CEconItemAttributeDefinition const*, attribute_data_union_t const&);
	??? ConvertEconAttributeValueToByteStream(attribute_data_union_t const&, std::string *);
	??? BConvertStringToEconAttributeValue(CEconItemAttributeDefinition const*, const char *, attribute_data_union_t *, bool);
	??? ConvertEconAttributeValueToString(CEconItemAttributeDefinition const*, attribute_data_union_t const&, std::string *);
	??? LoadByteStreamToEconAttributeValue(CEconItem *, CEconItemAttributeDefinition const*, std::string const&);
	??? InitializeNewEconAttributeValue(attribute_data_union_t *);
	??? UnloadEconAttributeValue(attribute_data_union_t *);
	??? OnIterateAttributeValue(IEconItemAttributeIterator *, CEconItemAttributeDefinition const*, attribute_data_union_t const&);
	??? BSupportsGameplayModificationAndNetworking();
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
