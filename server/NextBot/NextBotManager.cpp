/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * server/NextBot/NextBotManager.cpp
 */


/* global static */
int g_nBlockedSlides = 0;
int g_nSlid = 0;
int g_nRun = 0;


NextBotManager *TheNextBots()
{
	static NextBotManager manager;
	return manager;
}
