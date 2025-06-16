//#define DEF_WEAPONSPEEDLIMIT	// v2.172
#define DEF_MAXCRUSADESTRUCTURES		300
#define MAX_RUSHSTRUCTURES				100
#define DEF_MAXAGRICULTURE				200		//v2.19 2002-12-16
#define DEF_V383


//#define NO_MSGSPEEDCHECK		// 클라이언트 스피드 체크 하지 않는 옵션
//#define DEF_CHECKUSERNPCNUM	// 유저 비례 몬스터 생성 옵션
//#define DEF_GUILDWARMODE		// 길드전 모드: 특정 마법을 사용할 수 없다.
//#define DEF_DBGAMESERVER      // DB 게임서버 모드
//#define DEF_NPCITEM			// NPC에서 아이템 떨어지는 확률을 config 파일을 통해서 한다.
//#define DEF_BEGINNEREVENTMODE // 초보자용 이벤트 모드 (초보용 미들에 경치 두배)

//#define DEF_TESTSERVER		// 테스트 서버 모드
//#define DEF_KOREA
//#define DEF_TAIWAN
//#define DEF_CHINESE
//#define DEF_JAPAN
//#define DEF_USA
#define DEF_INTERSERVER


// 모든 나라 공통 
//#define	DEF_WINTER	// 겨울 설정 (눈내리게 한다.)
#define DEF_V219
#define DEF_BEGINNERTOWNPROTECT	// 중립 마을내에서 공격 안됨 v2.181

#ifdef DEF_KOREA
	#define DEF_CONSULTATION		// 심의 관련
	#define DEF_DEFENCEHACKING		// 2002-12-8 World server 보안 설정을 위해
	#define DEF_CHINESECANDYEVENT	// 2002-12-12 중국 사탕이벤트  
#endif

#if defined(DEF_INTERSERVER)
	//#define DEF_MAXLEVEL150
	//#define DEF_DBGAMESERVER	// DB 게임서버 모드 
	//#define DEF_DEFENCEHACKING  // 2002-12-8 World server 보안 설정을 위해 
	#define DEF_ENGLISHITEMNAME		// v2.15 이건 나중에 다시 설정할 필요가 있음.. 현재 시간관계상 미룸
	#define DEF_LOCALNPCNAME		// v2.14 대만용 NPC 이름 중문화를 위해 
	#define DEF_BEGINNERTOWNPROTECT	// 중립 마을내에서 공격 안됨 v2.181
	
//	#define DEF_WINTER
	//#define DEF_TEST					// Admin-Security = FALSE
	//#define DEF_TESTDROP				// Drop 100%
#endif

#ifdef DEF_TESTSERVER
	#define DEF_DBGAMESERVER		// DB 게임서버 모드
	// Test 중인 사항
	// #define DEF_NPCITEM
#endif 

#ifdef DEF_USA
	#define DEF_SAMESIDETOWNPROTECT	// 같은편끼리 마을내에서 공격 안됨 v2.172
	#define DEF_MAXLEVEL150
//	#define DEF_ITEMDROPRATINGUP	1500
#endif


#ifdef DEF_TAIWAN
	#define DEF_TAIWANLOG
//	#define DEF_DEFENCEHACKING		// 2002-12-8 World server 보안 설정을 위해 
	#undef	DEF_WINTER	// 겨울 설정 (눈내리게 한다.)
//	#define DEF_BALLEVENT           // !! 주의 1월1 ~ 15 대만 소원구 이벤트 
	#define DEF_DBGAMESERVER		// DB 게임서버 모드 
	#define DEF_LOCALNPCNAME		// v2.14 대만용 NPC 이름 중문화를 위해 
	#define DEF_ENGLISHITEMNAME		// v2.15 이건 나중에 다시 설정할 필요가 있음.. 현재 시간관계상 미룸
	#define DEF_LOGTIME
#endif

#ifdef DEF_CHINESE
	#define DEF_CHINESECANDYEVENT	// 2002-12-12 중국 사탕이벤트 
	#define DEF_CHINESEGUILDLIMIT
	#define DEF_NPCITEM
	// #define DEF_ITEMDROPRATINGUP	3000	// dice(1, 10000) > (9000 - 3000)  => 아이템 발생
#endif

#if  defined(DEF_CHINESE) ||defined(DEF_JAPAN) || defined (DEF_USA)
	#define DEF_DBGAMESERVER		// DB 게임서버 모드 
	#define DEF_LOCALNPCNAME		// v2.14 대만용 NPC 이름 중문화를 위해 
	#define DEF_ENGLISHITEMNAME		// v2.15 이건 나중에 다시 설정할 필요가 있음.. 현재 시간관계상 미룸
	#define DEF_LOGTIME
	#define DEF_DEFENCEHACKING		// 2002-12-8 World server 보안 설정을 위해 
#endif



#ifdef DEF_CONSULTATION
//	#define DEF_ALLPLAYERPROTECT	// v2.19 2002-11-12 캐릭터끼리 공격 불가능한 지역 설정 
	#define DEF_PKPENALTY			// v2.19 2002-11-18 PK 하면 무조건 감옥으로 
	#define DEF_SAMESIDETOWNPROTECT	// 같은편끼리 마을내에서 공격 안됨 v2.172
	#define DEF_ITEMDROP			// v2.19 2002-11-14 아이템 드랍을 포션과 소모성 아이템만 된다.(심의관련)
#endif