//#define DEF_TESTOFICIAL
//#define DEF_LOCAL
#define DEF_OFICIAL

#ifdef DEF_OFICIAL
//#define DEF_SERVER_IP	 		"hbreurn.no-ip.info"
#define DEF_SERVER_IP	 		"45.43.18.75"
#define DEF_SERVER_PORT			1847  //8471
#define NAME_WORLDNAME1			"return" 
#define MSG_WORLDNAME1			"Helbreath Return"
#define MSG_HOMEPAGE			"https://helbreathreturn.github.io/hbReturn"
#define MSG_FORUMPAGE			"https://helbreathreturn.github.io/hbReturn"
#define DEF_UPPERVERSION		3
#define DEF_LOWERVERSION		02
#define DEF_STATS_LIMIT         200
#define DEF_UPPERVERSION_FANTASMA    1
#define DEF_LOWERVERSION_FANTASMA    00

#define MSG_UPDATEPAGE			"https://helbreathreturn.github.io/hbReturn" //dp cambia

//version update
#define _UpdateVersion			8
//#define DEF_USE_DNS dale gato
#define DEF_SERVER_DNS 
//#define DEF_USE_LOGIN			// Login.cfg option
//#define  _DEBUGS 
#endif
//#define DEF_USING_WIN_IME		// Used for unicode characters (unchecked)
#define DEF_MAKE_ACCOUNT		// Enable acc creation. Missing sprites, fixed!

#ifdef _DEBUGS
	#define DEF_WINDOWED_MODE
#endif
