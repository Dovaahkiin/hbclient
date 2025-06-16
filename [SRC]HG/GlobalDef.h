//#define DEF_WEAPONSPEEDLIMIT	// v2.172
#define DEF_MAXCRUSADESTRUCTURES		300
#define MAX_RUSHSTRUCTURES				100
#define DEF_MAXAGRICULTURE				200		//v2.19 2002-12-16
#define DEF_V383


//#define NO_MSGSPEEDCHECK		// Ŭ���̾�Ʈ ���ǵ� üũ ���� �ʴ� �ɼ�
//#define DEF_CHECKUSERNPCNUM	// ���� ��� ���� ���� �ɼ�
//#define DEF_GUILDWARMODE		// ����� ���: Ư�� ������ ����� �� ����.
//#define DEF_DBGAMESERVER      // DB ���Ӽ��� ���
//#define DEF_NPCITEM			// NPC���� ������ �������� Ȯ���� config ������ ���ؼ� �Ѵ�.
//#define DEF_BEGINNEREVENTMODE // �ʺ��ڿ� �̺�Ʈ ��� (�ʺ��� �̵鿡 ��ġ �ι�)

//#define DEF_TESTSERVER		// �׽�Ʈ ���� ���
//#define DEF_KOREA
//#define DEF_TAIWAN
//#define DEF_CHINESE
//#define DEF_JAPAN
//#define DEF_USA
#define DEF_INTERSERVER


// ��� ���� ���� 
//#define	DEF_WINTER	// �ܿ� ���� (�������� �Ѵ�.)
#define DEF_V219
#define DEF_BEGINNERTOWNPROTECT	// �߸� ���������� ���� �ȵ� v2.181

#ifdef DEF_KOREA
	#define DEF_CONSULTATION		// ���� ����
	#define DEF_DEFENCEHACKING		// 2002-12-8 World server ���� ������ ����
	#define DEF_CHINESECANDYEVENT	// 2002-12-12 �߱� �����̺�Ʈ  
#endif

#if defined(DEF_INTERSERVER)
	//#define DEF_MAXLEVEL150
	//#define DEF_DBGAMESERVER	// DB ���Ӽ��� ��� 
	//#define DEF_DEFENCEHACKING  // 2002-12-8 World server ���� ������ ���� 
	#define DEF_ENGLISHITEMNAME		// v2.15 �̰� ���߿� �ٽ� ������ �ʿ䰡 ����.. ���� �ð������ �̷�
	#define DEF_LOCALNPCNAME		// v2.14 �븸�� NPC �̸� �߹�ȭ�� ���� 
	#define DEF_BEGINNERTOWNPROTECT	// �߸� ���������� ���� �ȵ� v2.181
	
//	#define DEF_WINTER
	//#define DEF_TEST					// Admin-Security = FALSE
	//#define DEF_TESTDROP				// Drop 100%
#endif

#ifdef DEF_TESTSERVER
	#define DEF_DBGAMESERVER		// DB ���Ӽ��� ���
	// Test ���� ����
	// #define DEF_NPCITEM
#endif 

#ifdef DEF_USA
	#define DEF_SAMESIDETOWNPROTECT	// �������� ���������� ���� �ȵ� v2.172
	#define DEF_MAXLEVEL150
//	#define DEF_ITEMDROPRATINGUP	1500
#endif


#ifdef DEF_TAIWAN
	#define DEF_TAIWANLOG
//	#define DEF_DEFENCEHACKING		// 2002-12-8 World server ���� ������ ���� 
	#undef	DEF_WINTER	// �ܿ� ���� (�������� �Ѵ�.)
//	#define DEF_BALLEVENT           // !! ���� 1��1 ~ 15 �븸 �ҿ��� �̺�Ʈ 
	#define DEF_DBGAMESERVER		// DB ���Ӽ��� ��� 
	#define DEF_LOCALNPCNAME		// v2.14 �븸�� NPC �̸� �߹�ȭ�� ���� 
	#define DEF_ENGLISHITEMNAME		// v2.15 �̰� ���߿� �ٽ� ������ �ʿ䰡 ����.. ���� �ð������ �̷�
	#define DEF_LOGTIME
#endif

#ifdef DEF_CHINESE
	#define DEF_CHINESECANDYEVENT	// 2002-12-12 �߱� �����̺�Ʈ 
	#define DEF_CHINESEGUILDLIMIT
	#define DEF_NPCITEM
	// #define DEF_ITEMDROPRATINGUP	3000	// dice(1, 10000) > (9000 - 3000)  => ������ �߻�
#endif

#if  defined(DEF_CHINESE) ||defined(DEF_JAPAN) || defined (DEF_USA)
	#define DEF_DBGAMESERVER		// DB ���Ӽ��� ��� 
	#define DEF_LOCALNPCNAME		// v2.14 �븸�� NPC �̸� �߹�ȭ�� ���� 
	#define DEF_ENGLISHITEMNAME		// v2.15 �̰� ���߿� �ٽ� ������ �ʿ䰡 ����.. ���� �ð������ �̷�
	#define DEF_LOGTIME
	#define DEF_DEFENCEHACKING		// 2002-12-8 World server ���� ������ ���� 
#endif



#ifdef DEF_CONSULTATION
//	#define DEF_ALLPLAYERPROTECT	// v2.19 2002-11-12 ĳ���ͳ��� ���� �Ұ����� ���� ���� 
	#define DEF_PKPENALTY			// v2.19 2002-11-18 PK �ϸ� ������ �������� 
	#define DEF_SAMESIDETOWNPROTECT	// �������� ���������� ���� �ȵ� v2.172
	#define DEF_ITEMDROP			// v2.19 2002-11-14 ������ ����� ���ǰ� �Ҹ� �����۸� �ȴ�.(���ǰ���)
#endif