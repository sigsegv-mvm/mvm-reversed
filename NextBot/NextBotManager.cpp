/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * NextBot: manager
 */


NextBotManager *TheNextBots()
{
	// TODO
}

TFBotManager *TheTFBots()
{
	// TODO
	// the game binary implements this by returning TheNextBots() and static_cast<TFBotManager *>'ing the result, I guess
	// probably a parallel implementation should work too
}
