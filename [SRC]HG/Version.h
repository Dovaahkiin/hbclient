//version update
#define _UpdateVersion			8

#define DEF_UPPERVERSION		"3"
#define DEF_BUILD               "503"
#if		defined(DEF_INTERSERVER)

	#define DEF_LOWERVERSION 		"82"
	#define DEF_BUILDDATE			2012

#elif		defined(DEF_USA)

	#define DEF_LOWERVERSION 		"20"
	#define DEF_BUILDDATE			2012

#elif		defined(DEF_KOREA)

	#define DEF_LOWERVERSION 		"20"
	#define DEF_BUILDDATE			2012

#elif		defined(DEF_CHINESE)

	#define DEF_LOWERVERSION 		"19"
	#define DEF_BUILDDATE			2012		// 310


#else	// 다른 국가들

	#define DEF_LOWERVERSION 		"19"
	#define DEF_BUILDDATE			2012


#endif