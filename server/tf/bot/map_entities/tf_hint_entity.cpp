/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/map_entities/tf_hint_entity.cpp
 */


IMPLEMENT_AUTO_LIST(ITFBotHintEntityAutoList);


CBaseTFBotHintEntity::CBaseTFBotHintEntity()
{
	this->m_bDisabled = false;
	// TODO
}

CBaseTFBotHintEntity::~CBaseTFBotHintEntity()
{
}


void CBaseTFBotHintEntity::InputEnable(inputdata_t& inputdata)
{
	this->m_bDisabled = false;
}

void CBaseTFBotHintEntity::InputDisable(inputdata_t& inputdata)
{
	this->m_bDisabled = true;
}


bool CBaseTFBotHintEntity::OwnerObjectFinishBuilding() const
{
	// TODO
}

bool CBaseTFBotHintEntity::OwnerObjectHasNoOwner() const
{
	// TODO
}
