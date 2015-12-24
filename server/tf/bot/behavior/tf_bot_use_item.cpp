/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/tf_bot_use_item.cpp
 * used in MvM: TODO
 */


CTFBotUseItem::CTFBotUseItem(CTFWeaponBase *item)
{
	this->m_hItem = item;
}

CTFBotUseItem::~CTFBotUseItem()
{
}


const char *CTFBotUseItem::GetName() const
{
	return "UseItem";
}


ActionResult<CTFBot> CTFBotUseItem::OnStart(CTFBot *actor, Action<CTFBot> *action)
{
	actor->PushRequiredWeapon(this->m_hItem());
	this->m_ctInitialDelay.Start(0.25f + (this->m_hItem()->m_flNextPrimaryAttack));
	
	CONTINUE();
}

ActionResult<CTFBot> CTFBotUseItem::Update(CTFBot *actor, float dt)
{
	if (this->m_hItem() == nullptr ||
		actor->m_Shared.GetActiveTFWeapon() == nullptr) {
		DONE("NULL item");
	}
	
	if (this->m_ctInitialDelay.HasStarted()) {
		if (this->m_ctInitialDelay.IsElapsed()) {
			actor->PressFireButton();
			this->m_ctInitialDelay.Invalidate();
		}
		
		CONTINUE();
	}
	
	if (actor->m_Shared.InCond(TF_COND_TAUNTING)) {
		CONTINUE();
	}
	
	DONE("Item used");
}

void CTFBotUseItem::OnEnd(CTFBot *actor, Action<CTFBot> *action)
{
	actor->PopRequiredWeapon();
}
