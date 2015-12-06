/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/tf_bot.cpp
 */


ConVar tf_bot_force_class("tf_bot_force_class", "", FCVAR_GAMEDLL,
	"If set to a class name, all TFBots will respawn as that class");
ConVar tf_bot_notice_gunfire_range("tf_bot_notice_gunfire_range", "3000", FCVAR_GAMEDLL);
ConVar tf_bot_notice_quiet_gunfire_range("tf_bot_notice_quiet_gunfire_range", "500", FCVAR_GAMEDLL);
ConVar tf_bot_sniper_personal_space_range("tf_bot_sniper_personal_space_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_pyro_deflect_tolerance("tf_bot_pyro_deflect_tolerance", "0.5", FCVAR_CHEAT);
ConVar tf_bot_keep_class_after_death("tf_bot_keep_class_after_death", "0", FCVAR_GAMEDLL);
ConVar tf_bot_prefix_name_with_difficulty("tf_bot_prefix_name_with_difficulty", "0", FCVAR_GAMEDLL,
	"Append the skill level of the bot to the bot's name");
ConVar tf_bot_near_point_travel_distance("tf_bot_near_point_travel_distance", "750", FCVAR_CHEAT);
ConVar tf_bot_pyro_shove_away_range("tf_bot_pyro_shove_away_range", "250", FCVAR_CHEAT,
	"If a Pyro bot's target is closer than this, compression blast them away");
ConVar tf_bot_pyro_always_reflect("tf_bot_pyro_always_reflect", "0", FCVAR_CHEAT,
	"Pyro bots will always reflect projectiles fired at them. For tesing/debugging purposes.");
ConVar tf_bot_sniper_spot_min_range("tf_bot_sniper_spot_min_range", "1000", FCVAR_CHEAT);
ConVar tf_bot_sniper_spot_max_count("tf_bot_sniper_spot_max_count", "10", FCVAR_CHEAT,
	"Stop searching for sniper spots when each side has found this many");
ConVar tf_bot_sniper_spot_search_count("tf_bot_sniper_spot_search_count", "10", FCVAR_CHEAT,
	"Search this many times per behavior update frame");
ConVar tf_bot_sniper_spot_point_tolerance("tf_bot_sniper_spot_point_tolerance", "750", FCVAR_CHEAT);
ConVar tf_bot_sniper_spot_epsilon("tf_bot_sniper_spot_epsilon", "100", FCVAR_CHEAT);
ConVar tf_bot_sniper_goal_entity_move_tolerance("tf_bot_sniper_goal_entity_move_tolerance", "500", FCVAR_CHEAT);
ConVar tf_bot_suspect_spy_touch_interval("tf_bot_suspect_spy_touch_interval", "5", FCVAR_CHEAT,
	"How many seconds back to look for touches against suspicious spies");
ConVar tf_bot_suspect_spy_forced_cooldown("tf_bot_suspect_spy_forced_cooldown", "5", FCVAR_CHEAT,
	"How long to consider a suspicious spy as suspicious");
ConVar tf_bot_debug_tags("tf_bot_debug_tags", "0", FCVAR_CHEAT,
	"ent_text will only show tags on bots");

ConCommand tf_bot_add_command("tf_bot_add", &tf_bot_add,
	"Add a bot.", FCVAR_GAMEDLL);
ConCommand tf_bot_kick_command("tf_bot_kick", &tf_bot_kick,
	"Remove a TFBot by name, or all bots (\"all\").", FCVAR_GAMEDLL);
ConCommand tf_bot_kill_command("tf_bot_kill", &tf_bot_kill,
	"Kill a TFBot by name, or all bots (\"all\").", FCVAR_GAMEDLL);
ConCommand tf_bot_warp_team_to_me("tf_bot_warp_team_to_me", &CMD_BotWarpTeamToMe,
	"", FCVAR_CHEAT | FCVAR_GAMEDLL);


CTFBot::CTFBotIntention::CTFBotIntention(CTFBot *actor)
	: IIntention(actor)
{
	// TODO: verify parameters for CTFBotMainAction ctor
	this->m_Behavior = new Behavior<CTFBot>(new CTFBotMainAction());
}

CTFBot::CTFBotIntention::~CTFBotIntention()
{
	if (this->m_Behavior != nullptr) {
		delete this->m_Behavior;
	}
}


INextBotEventResponder *CTFBot::CTFBotIntention::FirstContainedResponder() const
{
	return this->m_Behavior;
}

INextBotEventResponder *CTFBot::CTFBotIntention::NextContainedResponder(INextBotEventResponder *prev) const
{
	return nullptr;
}


void CTFBot::CTFBotIntention::Reset()
{
	if (this->m_Behavior != nullptr) {
		delete this->m_Behavior;
	}
	
	// TODO: verify parameters for CTFBotMainAction ctor
	this->m_Behavior = new Behavior<CTFBot>(new CTFBotMainAction());
}

void CTFBot::CTFBotIntention::Update()
{
	this->m_Behavior->Update(this->GetBot(), this->m_flTickInterval);
}
