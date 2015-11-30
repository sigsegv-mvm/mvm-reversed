/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/tf/bot/behavior/scenario/capture_point/tf_bot_capture_point.cpp
 * used in MvM: TODO
 */


ConVar tf_bot_offense_must_push_time("tf_bot_offense_must_push_time", "120", FCVAR_CHEAT,
	"If timer is less than this, bots will push hard to cap");
ConVar tf_bot_capture_seek_and_destroy_min_duration("tf_bot_capture_seek_and_destroy_min_duration", "15", FCVAR_CHEAT,
	"If a capturing bot decides to go hunting, this is the min duration he will hunt for before reconsidering");
ConVar tf_bot_capture_seek_and_destroy_max_duration("tf_bot_capture_seek_and_destroy_max_duration", "30", FCVAR_CHEAT,
	"If a capturing bot decides to go hunting, this is the max duration he will hunt for before reconsidering");



