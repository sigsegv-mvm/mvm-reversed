/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * NextBot: manager
 */


CTFBotManager sTFBotManager;


NextBotManager *TheNextBots()
{
	static NextBotManager manager;
	return manager;
}

CTFBotManager *TheTFBots()
{
	/* uh... yeah... this isn't valid at all, since the pointer returned by
	 * TheNextBots() is not actually a CTFBotManager!
	 * (why the hell doesn't this return sTFBotManager, which is a valid
	 * CTFBotManager that is completely unused?) */
	return static_cast<CTFBotManager *>(TheNextBots());
}
