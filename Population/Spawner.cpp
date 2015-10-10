/* reverse engineering by sigsegv
 * based on server_srv.so version 20151006
 * Population: spawners
 */


CMobSpawner::CMobSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	m_iCount     = 0;
	m_SubSpawner = NULL;
	
	// TODO
}

CSentryGunSpawner::CSentryGunSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	m_iLevel = 0;
}

CTankSpawner::CTankSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	m_iHealth             = 50000;
	m_flSpeed             = 75.0f;
	m_strName             = "Tank";
	m_strStartNode        = NULL;
	m_iSkin               = 0;
	m_OnKilledOutput      = NULL;
	m_OnBombDroppedOutput = NULL;
}

CTFBotSpawner::CTFBotSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	// TODO
}

CSquadSpawner::CSquadSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	// TODO
}

CRandomChoiceSpawner::CRandomChoiceSpawner(IPopulator *populator)
	: m_Populator(populator)
{
	// TODO
}


bool CMobSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			IPopulationSpawner *spawner;
			
			if (V_stricmp(name, "Count") == 0) {
				m_iCount = subkey->GetInt(NULL);
			} else if ((spawner = IPopulationSpawner::ParseSpawner(m_Populator, subkey)) != NULL) {
				if (m_SubSpawner == NULL) {
					m_SubSpawner = spawner;
				} else {
					Warning("CMobSpawner: Duplicate spawner encountered - discarding!\n");
					delete spawner;
				}
			} else {
				Warning("Unknown attribute '%s' in Mob definition.\n", name);
			}
		}
	}
	
	return true;
}

bool CSentryGunSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Level") == 0) {
				m_iLevel = subkey->GetInt(NULL);
			} else {
				Warning("Invalid attribute '%s' in SentryGun definition\n", name);
				return false;
			}
		}
	}
	
	return true;
}

bool CTankSpawner::Parse(KeyValues *kv)
{
	FOR_EACH_SUBKEY(kv, subkey) {
		const char *name = subkey->GetName();
		if (strlen(name) > 0) {
			if (V_stricmp(name, "Health") == 0) {
				m_iHealth = subkey->GetInt(NULL);
			} else if (V_stricmp(name, "Speed") == 0) {
				m_flSpeed = subkey->GetFloat(NULL);
			} else if (V_stricmp(name, "Name") == 0) {
				m_strName = subkey->GetString(NULL);
			} else if (V_stricmp(name, "Skin") == 0) {
				m_iSkin = subkey->GetInt(NULL);
			} else if (V_stricmp(name, "StartingPathTrackNode") == 0) {
				m_strStartNode = subkey->GetString(NULL);
			} else if (V_stricmp(name, "OnKilledOutput") == 0) {
				m_OnKilledOutput = ParseEvent(subkey);
			} else if (V_stricmp(name, "OnBombDroppedOutput") == 0) {
				m_OnBombDroppedOutput = ParseEvent(subkey);
			} else {
				Warning("Invalid attribute '%s' in Tank definition\n", name);
				return false;
			}
		}
	}
	
	return true;
}

bool CTFBotSpawner::Parse(KeyValues *kv)
{
	
}

bool CSquadSpawner::Parse(KeyValues *kv)
{
	// TODO
}

bool CRandomChoiceSpawner::Parse(KeyValues *kv)
{
	// TODO
}


bool CMobSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CSentryGunSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CTankSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CTFBotSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CSquadSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}

bool CRandomChoiceSpawner::Spawn(const Vector& where, CUtlVector<CHandle<CBaseEntity>> v, int i)
{
	// TODO
}


bool IPopulationSpawner::IsWhereRequired()
{
	return true;
}

bool CTankSpawner::IsWhereRequired()
{
	return false;
}


bool IPopulationSpawner::IsVarious()
{
	return false;
}

bool CSquadSpawner::IsVarious()
{
	return true;
}

bool CRandomChoiceSpawner::IsVarious()
{
	return true;
}


int IPopulationSpawner::GetClass(int index)
{
	return 0;
}

int CTFBotSpawner::GetClass(int index)
{
	// TODO
}

int CSquadSpawner::GetClass(int index)
{
	// TODO
}

int CRandomChoiceSpawner::GetClass(int index)
{
	// TODO
}


string_t IPopulationSpawner::GetClassIcon(int index)
{
	return NULL_STRING;
}

string_t CTankSpawner::GetClassIcon(int index)
{
	return MAKE_STRING("tank");
}

string_t CTFBotSpawner::GetClassIcon(int index)
{
	// TODO
}

string_t CSquadSpawner::GetClassIcon(int index)
{
	// TODO
}

string_t CRandomChoiceSpawner::GetClassIcon(int index)
{
	// TODO
}


int IPopulationSpawner::GetHealth(int index)
{
	return 0;
}

int CTankSpawner::GetHealth(int index)
{
	return m_iHealth;
}

int CTFBotSpawner::GetHealth(int index)
{
	return m_iHealth;
}

int CSquadSpawner::GetHealth(int index)
{
	// TODO
}

int CRandomChoiceSpawner::GetHealth(int index)
{
	// TODO
}


bool IPopulationSpawner::IsMiniBoss()
{
	return false;
}

bool CTankSpawner::IsMiniBoss()
{
	return true;
}

bool CTFBotSpawner::IsMiniBoss()
{
	// TODO
	// returns byte at this+0x283c (probably player->m_Shared.m_bIsMiniBoss or however that's accessed)
}

bool CSquadSpawner::IsMiniBoss()
{
	// TODO
}

bool CRandomChoiceSpawner::IsMiniBoss()
{
	// TODO
}


bool IPopulationSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	return false;
}

bool CTFBotSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	// TODO
}

bool CSquadSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	// TODO
}

bool CRandomChoiceSpawner::HasAttribute(CTFBot::AttributeType attr, int index)
{
	// TODO
}


bool CMobSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
}

bool CSentryGunSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
}

bool CTankSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
}

bool CTFBotSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
}

bool CSquadSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
}

bool CRandomChoiceSpawner::HasEventChangeAttributes(const char *name) const
{
	// TODO
}


IPopulationSpawner *IPopulationSpawner::ParseSpawner(IPopulator *populator, KeyValues *kv)
{
	// TODO
}


bool CTFBotSpawner::ParseEventChangeAttributes(KeyValues *kv)
{
	// TODO
}
