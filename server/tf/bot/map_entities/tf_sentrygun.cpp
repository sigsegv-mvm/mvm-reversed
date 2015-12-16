/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/map_entities/tf_sentrygun.cpp
 */


CTFBotHintSentrygun::CTFBotHintSentrygun()
{
	// TODO
}

CTFBotHintSentrygun::~CTFBotHintSentrygun()
{
}


CBaseTFBotHintEntity::HintType CTFBotHintSentrygun::GetHintType() const
{
	return CBaseTFBotHintEntity::HintType::SENTRY_GUN;
}


bool CTFBotHintSentrygun::IsAvailableForSelection(CTFPlayer *player) const
{
	// TODO
}


void CTFBotHintSentrygun::OnSentryGunDestroyed(CBaseEntity *ent)
{
	this->m_OnSentryGunDestroyed->FireOutput(ent, ent);
}
