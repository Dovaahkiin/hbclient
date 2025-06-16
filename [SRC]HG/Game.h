// Game.h: interface for the CGame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_)
#define AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_
#pragma warning(disable : 4996)
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <windows.h>
#include <winbase.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <memory.h>
#include <direct.h>

#include "Winmain.h"
#include "StrTok.h"
#include "Xsocket.h"
#include "Client.h"
#include "Npc.h"
#include "Map.h"
#include "ActionID.h"
#include "UserMessages.h"
#include "NetMessages.h"
#include "MessageIndex.h"
#include "Misc.h"
#include "Msg.h"
#include "Magic.h"
#include "Skill.h"
#include "DynamicObject.h"
#include "DelayEvent.h"
#include "Version.h"
#include "Fish.h"
#include "DynamicObject.h"
#include "DynamicObjectID.h"
#include "Potion.h"
#include "Mineral.h"
#include "Quest.h"
#include "BuildItem.h"
#include "TeleportLoc.h"
#include "GlobalDef.h"
#include "englishitem.h"
#include "koreaitem.h"
#include "teleport.h"



#define DEF_SERVERSOCKETBLOCKLIMIT	300

#define DEF_MAXCLIENTS			2000
#define DEF_MAXNPCS				99999
#define DEF_MAXMAPS				100
#define DEF_MAXITEMTYPES		5000
#define DEF_MAXNPCTYPES			900
#define DEF_MAXBUILDITEMS		900
#define DEF_CLIENTTIMEOUT		1000*10		//(10��)
#define DEF_AUTOSAVETIME		600000	// �ڵ� ���� �ð����� 30�� 
#define DEF_HPUPTIME			1000*15		// HP�� �ö󰡴� �ð����� 
#define DEF_MPUPTIME			1000*20		// MP�� �ö󰡴� �ð����� 
#define DEF_SPUPTIME			1000*10		// SP�� �ö󰡴� �ð����� 

#define DEF_HUNGERTIME			1000*60		// �谡 �������� �ð����� 
#define DEF_POISONTIME			1000*12		// �ߵ� ȿ�� �ð� ���� 
#define DEF_SUMMONTIME			60000*5		// ��ȯ���� 5�а� ����ִ�
#define DEF_NOTICETIME			80000		// ���� ���� ���� �ð����� 
#define DEF_PLANTTIME			60000*5		//v2.20 2002-12-20 ���۹� ��� �ִ� �ð�.

#define DEF_EXPSTOCKTIME		1000*10		// ExpStock�� ����ϴ� �ð� ���� 
#define DEF_MSGQUENESIZE		100000		// �޽��� ť ������ 10���� 
#define DEF_AUTOEXPTIME			1000*60*6	// �ڵ����� ����ġ�� �ö󰡴� �ð����� 
#define DEF_TOTALLEVELUPPOINT	3			// �������� �Ҵ��ϴ� �� ����Ʈ �� 




#define DEF_MAXDYNAMICOBJECTS	99999
#define DEF_MAXDELAYEVENTS		99999
#define DEF_GUILDSTARTRANK		12

#define DEF_SSN_LIMIT_MULTIPLY_VALUE	2	// SSN-limit ���ϴ� �� 

#define DEF_MAXNOTIFYMSGS		1000		// �ִ� �������� �޽��� 
#define DEF_NIGHTTIME			40

#define DEF_CHARPOINTLIMIT		1000			// ������ Ư��ġ�� �ִ밪 
#define DEF_RAGPROTECTIONTIME	7000		// �� �� �̻� ������ ������ ���� ��ȣ�� �޴��� 
#define DEF_MAXREWARDGOLD		99999999	// ����� �ִ�ġ 

#define DEF_ATTACKAI_NORMAL				1	// ������ ���� 
#define DEF_ATTACKAI_EXCHANGEATTACK		2	// ��ȯ ���� - ���� 
#define DEF_ATTACKAI_TWOBYONEATTACK		3	// 2-1 ����, ���� 

#define DEF_MAXFISHS					200
#define DEF_MAXMINERALS					990
#define DEF_MAXENGAGINGFISH				30  // �� ����⿡ ���ø� �õ��� �� �ִ� �ִ� �ο� 
#define DEF_MAXPORTIONTYPES				500 // �ִ� ���� ���� ���� 

#define DEF_MOBEVENTTIME				300000 // 5�� 
#define DEF_MAXQUESTTYPE				200

#define DEF_MAXSUBLOGSOCK				10

#define DEF_ITEMLOG_GIVE				1
#define DEF_ITEMLOG_DROP				2
#define DEF_ITEMLOG_GET					3
#define DEF_ITEMLOG_DEPLETE				4
#define DEF_ITEMLOG_NEWGENDROP			5
#define DEF_ITEMLOG_DUPITEMID			6
#define DEF_ITEMLOG_BUY					7        // 12-22 ���Ĵ��߰� 
#define DEF_ITEMLOG_SELL				8     
#define DEF_ITEMLOG_RETRIEVE			9
#define DEF_ITEMLOG_DEPOSIT				10
#define DEF_ITEMLOG_EXCHANGE			11
#define DEF_ITEMLOG_MAGICLEARN			12
#define DEF_ITEMLOG_MAKE				13
#define DEF_ITEMLOG_SUMMONMONSTER		14
#define DEF_ITEMLOG_POISONED			15
#define DEF_ITEMLOG_SKILLLEARN			16
#define DEF_ITEMLOG_REPAIR				17
#define DEF_ITEMLOG_JOINGUILD           18
#define DEF_ITEMLOG_BANGUILD            19	// �ѱ��� ���� �α�
#define DEF_ITEMLOG_RESERVEFIGZONE      20	//  "
#define DEF_ITEMLOG_APPLY               21	//  "
#define DEF_ITEMLOG_SHUTUP              22	//  "
#define DEF_ITEMLOG_CLOSECONN			23	//  "
#define DEF_ITEMLOG_SPELLFIELD			24	//  "
#define DEF_ITEMLOG_CREATEGUILD			25	//  "
#define DEF_ITEMLOG_GUILDDISMISS		26	//  "
#define DEF_ITEMLOG_SUMMONPLAYER        27	//  "
#define DEF_ITEMLOG_CREATE				28	//  "
#define DEF_ITEMLOG_UPGRADEFAIL         29
#define DEF_ITEMLOG_UPGRADESUCCESS      30


// v2.15 ������ �α� ���� 
#define DEF_CRUSADELOG_ENDCRUSADE       1
#define DEF_CRUSADELOG_STARTCRUSADE     2
#define DEF_CRUSADELOG_SELECTDUTY       3
#define DEF_CRUSADELOG_GETEXP           4


#define DEF_PKLOG_BYPLAYER				1
#define DEF_PKLOG_BYPK					2
#define DEF_PKLOG_BYENERMY				3
#define DEF_PKLOG_BYNPC					4
#define DEF_PKLOG_BYOTHER				5
#define DEF_PKLOG_REDUCECRIMINAL        6


#define DEF_MAXDUPITEMID				5000

#define DEF_MAXGUILDS					1000 // ���ÿ� ������ �� �ִ� ���� 
#define DEF_MAXONESERVERUSERS			800	 // �� �������� ����� �� �ִ� �ִ� ����ڼ�. �ʰ��� ��� ��Ȱ�� Ȥ�� ���� ����, ������� ��������.

#define DEF_MAXGATESERVERSTOCKMSGSIZE	30000


#ifdef DEF_TAIWAN    // �븸�� ��� �ִ� 7���� ��������.
#define DEF_MAXCONSTRUCTNUM				7
#else
#define DEF_MAXCONSTRUCTNUM				10
#endif
#define MAX_HELDENIANTOWERARESDEN       47
#define MAX_HELDENIANTOWERELVINE        47
#define DEF_MAXSCHEDULE					10
#define MAX_HELDENIANTOWERS              100
#define DEF_TIMEFINALHELDENIAN   300000
//v1.4311-3  �������� �ִ� ����
#define DEF_MAXFIGHTZONE 10 

//============================
// #define DEF_LEVELLIMIT		130				// ü���� ���� ����ġ!!!			
#define DEF_LEVELLIMIT		20				// ü���� ���� ����ġ!!!	// adamas
//============================

//============================
#define DEF_MINIMUMHITRATIO 15				// ���� ���� Ȯ��  //v2.172 10->15% ��� 
//============================		

//============================
#define DEF_MAXIMUMHITRATIO	99				// �ִ� ���� Ȯ��
//============================

//============================
#if defined(DEF_TESTSERVER)
	// #define DEF_PLAYERMAXLEVEL	130				// �ִ� ����: Npc.cfg ���Ͽ� �����Ǿ� ���� ���� ��� m_iPlayerMaxLevel�� �Էµȴ�.
	#define DEF_PLAYERMAXLEVEL	200			// �ִ� ����: Npc.cfg ���Ͽ� �����Ǿ� ���� ���� ��� m_iPlayerMaxLevel�� �Էµȴ�.
#else
	#define DEF_PLAYERMAXLEVEL	200				// �ִ� ����: Npc.cfg ���Ͽ� �����Ǿ� ���� ���� ��� m_iPlayerMaxLevel�� �Էµȴ�.
	// #define DEF_PLAYERMAXLEVEL	140
#endif 
//============================

//============================
#define DEF_GMGMANACONSUMEUNIT	15			// Grand Magic Generator ���� ��� ����.
//============================

#define DEF_MAXCONSTRUCTIONPOINT 50000		// �ִ� ��ȯ ����Ʈ 

#define DEF_MAXWARCONTRIBUTION	 900000

#define DEF_CRUSADELOG_STARTHAPPYHOUR	17
#define DEF_CRUSADELOG_ENDHAPPYHOUR		18
//FurDay by prlucas
#define DEF_CRUSADELOG_STARTFURYDAY	90
#define DEF_CRUSADELOG_ENDFURYDAY		91

#define DEF_MAXPARTYMEMBERS		8
#define DEF_MAXPARTYNUM			5000

#define DEF_MAXGIZONPOINT		999			// adamas : �ְ� ���� ���׷��̵�

// v2.181 2002-10-24 ���� �ӵ� ����� ���� ��Ʈ�� �񱳸� ���δ�.
#define DEF_NETURAL             0
#define DEF_ARESDEN             1
#define DEF_ELVINE              2
#define DEF_BOTHSIDE			100

//v2.19 2002-11-19 
#define DEF_PK					0
#define DEF_NONPK				1
#define DEF_NEVERNONPK			2  //v2.19 2002-11-19 �ʺ� �̵� ���� ���� PK�Ұ���

// 2002-12-24 �������� ��ȯ�� �� �ִ� (�ǹ� ���� ������) NPC�� ���� �����Ѵ�.(�븸 ��û)
#ifdef DEF_TAIWAN
	#define DEF_MAX_CRUSADESUMMONMOB	5
#else
	#define DEF_MAX_CRUSADESUMMONMOB	500
#endif
//#define DEF_DBGAMESERVER
// v2.20 2002-12-31 �ΰ��� ��� ���� ���� �� �̵����� ���� �߰� 
#define DEF_LIMITHUNTERLEVEL 100
#define DEF_MAXHELDENIANSUMMONPOINT     12000
#define DEF_GUILDCOST	2000
#define DEF_CLEANTIME 600000
////////////////////////////////////
#define DEF_PASSWORD "12011339++"
#define DEF_HIGH////////////////////
//#define DEF_LOW/////////////////////
////////////////////////////////////

#define ZERK_ME_MAJESTICS		300 // Cantidad de majestics que necesita para el comando /zerkme
#define MANA_ME_MAJESTICS		300 // Cantidad de majestics que necesita para el comando /maname
#define ZERK_ME_DURATION		600 // Cantidad de segundos que dura el efecto de /zerkme
#define MANA_ME_DURATION		300 // Cantidad de segundos que dura el efecto de /maname


class CGame
{
public:
	void AVAWinnerGift(int iClientH);
	int  iTotalAVACurrentKills, iTotalAVAUsers;
	void CheckAllVsAllWinner();
	void AllVsAll(char cAction);
	BOOL bAllVsAll;
	char cStonesCounter;
	void GenerateStones();
	void StoneWinnerGift(int iClientH, int NpcID);
	BOOL m_bStones;
	void StarterEnderStonesEvents(char pAction);
	void PlayerOrder_ShowDamage(int iClientH);
	char m_cPvpEvent;
	void CityWarStarter();
	BOOL m_bCityWarStarter;
	struct {
		int iDay;
		int iHour;
		int iMinute;
	} m_stCityWarSchedule; 
	void SndCityWarGlobalMsg(short, char);
	void _CreateCityWarGUID(int);
	BOOL bReadCityWarGUIDFile(char *);
	void RequestTpCityhall(int);
	char m_cCityWarWinner;
	void EndCityWar();
	void UpdateCityWarStatus();
	int m_iCityWarAresdenDead;
	int m_iCityWarElvineDead;
	BOOL m_bCityWar;
	DWORD m_dwCityWTime;
	void BeginCityWar();
	void PlayerCommandCheckAdmins(int iClientH);
	/////////////////////////////////////////////////////////////////
	int m_iAddUser;
	BOOL bGetEmptyArea(short, char, short, short, char);
	BOOL bGetNpcMovementArea(short, short, short, char, char);
	/////////////////////////////////////////////////////////////////
	void AdminOrder_ChangeCity(int, char *, DWORD);
	/////////////////////////////////////////////////////////////////
	void ChangeNamer(int, char *, DWORD);
	/////////////////////////////////////////////////////////////////
	BOOL bReadDupeConfigFile(char *);
	/////////////////////////////////////////////////////////////////
	short m_sAutoClearCount;
	/////////////////////////////////////////////////////////////////
	void AdminOrder_Weather(int, char *, DWORD); 
	/////////////////////////////////////////////////////////////////
	void AdminOrder_Time(int, char *, DWORD);
	/////////////////////////////////////////////////////////////////
	void AngelSkills(int, char, char);
	/////////////////////////////////////////////////////////////////
	void SetAfkFlag(int, char *, DWORD);
	/////////////////////////////////////////////////////////////////
	void SetAccountMsg(int, char *, DWORD);
	BOOL bReadMessageConfigFile(char *);
	/////////////////////////////////////////////////////////////////
	void GetDkHandler(int iClientH, int iOpcion);
	/////////////////////////////////////////////////////////////////
	int m_iExtHGServerPort;
	/////////////////////////////////////////////////////////////////
	void OnRAdminSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void OnRadminRead();
	/////////////////////////////////////////////////////////////////
	DWORD m_dwMinute;
	/////////////////////////////////////////////////////////////////
	void HeldenianStarter(); 
	void ApocalypseStarter(); 
	void HeldenianFightStarter(); 
	BOOL  m_bIsHeldenianStarter; 
	BOOL  m_bIsApocalypseStarter; 
	BOOL bReadScheduleConfigFile(char *pFn);
		struct {
		int iDay;
		int iHour;
		int iMinute;
	} m_stApocalypseSchedule; 
	//////////////////////////////////////////////////////////////////
	BOOL m_bHeldSafe;
	//////////////////////////////////////////////////////////////////
	DWORD m_dwHeldenianSafeTime;
	//////////////////////////////////////////////////////////////////
	BOOL bAddMagicAngelInt(int iClientH);
	//////////////////////////////////////////////////////////////////
	BOOL bCheckAngelInt(int iClientH);
	//////////////////////////////////////////////////////////////////
	int iCheckLugar(int iClientH);
	//////////////////////////////////////////////////////////////////
	BOOL m_bClear;
	void AutoClearMap();
	//////////////////////////////////////////////////////////////////
	void AdminOrder_MonsterCount(int iClientH, char* pData, DWORD dwMsgSize);
	//////////////////////////////////////////////////////////////////
	void PreventChoreo(int iClientH);
	//////////////////////////////////////////////////////////////////
	DWORD m_dwAnuncios;
	void Anuncios();
	//////////////////////////////////////////////////////////////////
	void AdminOrder_SetZerk(int iClientH, char *pData, DWORD dwMsgSize);
	//////////////////////////////////////////////////////////////////
    void PlayerOrder_RequestDestiny(int iClientH, char * pData);
	//////////////////////////////////////////////////////////////////
	void MultiplicadorExp(WORD Client, DWORD Exp);
    //////////////////////////////////////////////////////////////////
	void NotificacionExternaForceRecall(int iClientH);
	//////////////////////////////////////////////////////////////////
	void AdminOrder_GoTo(int iClientH, char* pData, DWORD dwMsgSize);
	//////////////////////////////////////////////////////////////////
    void LoteryHandler(int iClientH);
	//////////////////////Heldenian///////////////////////////////////
	void AdminOrder_MorlearPj(int iClientH, char* pData, DWORD dwMsgSize); // MORLA 2.12 - Morlear PJ
    void Timeheldenianfinal();
	char m_sLastHeldenianWinner;
	BOOL bHFlag;
	void LimpiarNpcHeldenian(int iClientH);
	void HeldenianEnd();
	void HeldenianFight(int iClientH);
	BOOL bDecodeTeleportList(char *pFn);
	class CTeleport * m_pTeleportConfigList[DEF_MAXTELEPORTLIST];
	void RequestTeleportListHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void RequestChargedTeleportHandler(int iClientH, char *pData, DWORD dwMsgSize);
	BOOL bVarRecall;
	BOOL bHeldenianFight;
	void CreateHeldenianStructures1();
	void CreateHeldenianStructures();
	BOOL bReadHeldenianStructureConfigFile(char * cFn);
    void NotifyStartHeldenianFightMode(); 
	BOOL m_bHeldenianRunning;
	void RemoveHeldenianNpc(int iNpcH);
	void HeldenianVictoryNow(int iSide);
	BOOL bReadHeldenianGUIDFile(char * cFn);
	int m_iBTFieldMapIndex;
	int m_iHeldenianAresdenFlags, m_iHeldenianElvineFlags;
	void HeldenianEndWarNow();
	void NotifyStartHeldenianMode();
	DWORD m_dwHeldenianStartMinute;
	DWORD m_dwHeldenianStartHour;
	void SetHeldenianMode(); 
	void ManualStartHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize);
	void ManualEndHeldenianMode(int iClientH, char *pData, DWORD dwMsgSize);
	void AutomatedHeldenianTimer();
	DWORD m_dwHeldenianStartTime;
	BOOL bUpdateHeldenianStatus(int iClientH);
    void GlobalStartHeldenianMode();
	void HeldenianWarEnder();
	void LocalStartHeldenianMode(short sV1, short sV2, DWORD dwHeldenianGUID);

	struct {
		char cMapName[11];			// ��ġ�Ǵ� �� ��ġ
		char cType;					// ���๰ ����. ��� NPC ������.
		int  dX, dY;				// ��ġ�Ǵ� �ʻ��� ��ġ

	} m_stHeldenianStructures[MAX_HELDENIANTOWERS];
		struct {
		char cMapName[11];			// ��ġ�Ǵ� �� ��ġ
		char cType;					// ���๰ ����. ��� NPC ������.
		int  dX, dY;				// ��ġ�Ǵ� �ʻ��� ��ġ

	} m_stHeldenianStructuresx[MAX_HELDENIANTOWERS];
	struct 
	{	int iDay;
		int StartiHour;
		int StartiMinute;
	}  m_stHeldenianSchedule[DEF_MAXSCHEDULE];

	BOOL var_89C, var_8A0, var_88C;
	void HeldenianWarStarter();
	void CreateHeldenianGUID(DWORD dwHeldenianGUID, int iWinnerSide);
	void RemoveOccupyFlags(int iMapIndex);
	DWORD m_dwHeldenianFinishTime;
	DWORD m_dwHeldenianGUID;
	DWORD m_dwHeldenianWarStartTime;
	DWORD m_dwHeldenianWarTime;
	DWORD m_dwHeldenianWTime;
	DWORD m_dwHeldenianFTime;
    int m_iHeldenianAresdenLeftTower;
    int m_iHeldenianElvineLeftTower;
	char m_cHeldenianVictoryType;
	int m_iHeldenianAresdenDead;
	int m_iHeldenianElvineDead;
	BOOL bNotifyHeldenianWinner();
	void LocalEndHeldenianMode(int iClientH, int iSide); 
	char m_cHeldenianWinner;
	void GlobalEndHeldenianMode();
	void RequestHeldenianScroll(int iClientH, char * pData, DWORD dwMsgSize);
	BOOL m_bHeldenianInitiated;
    BOOL m_iGodHMapIndex;
	void RequestHeldenianTeleport(int iClientH, char * pData, DWORD dwMsgSize);
	BOOL m_bIsHeldenianMode;
	BOOL bCheckHeldenianMap(int sAttackerH, int iMapIndex, char cType);
	char m_cHeldenianModeType;
	void RequestNpcSpeakTeleport(int iClientH, char * pData, DWORD dwMsgSize);
    ///////////////////////////////////////////////////////////////////
    DWORD dwCreateGuildGoldCost;
	///////////////////////////////////////////////////////////////////

	////// COMANDOS //////
	void AdminOrder_SetEK (int iClientH, char *pData, DWORD dwMsgSize);
	void AdminOrder_SetMAJ (int iClientH, char *pData, DWORD dwMsgSize);
	void AdminOrder_SetRep (int iClientH, char *pData, DWORD dwMsgSize);
	void AdminOrder_SetCrit (int iClientH, char *pData, DWORD dwMsgSize);
	void AdminOrder_SetPK (int iClientH, char *pData, DWORD dwMsgSize);
//	void _TradeItem(int iClientH, char *pData, DWORD dwMsgSize); //Trade EK por comando y nombre.
	void AdminOrder_Pushplayer(int iClientH, char * pData, DWORD dwMsgSize);


	////// COMANDOS //////
	void AdminOrder_CleanMap(int iClientH, char * pData, DWORD dwMsgSize);
    ///////////////////////////////////////////////////////////////////
	void ShowClientMsg(int iClientH, char* pMsg);
	void ShowClientMsg2(int iClientH, char* pMsg, int iChatType);
	//	void ShowClientMsg(int iClientH, char* pMsg, int iChatType);
	///////////////////////////////////////////////////////////////////
	void GetDkSet(int iClientH);
    ///////////////////////////////////////////////////////////////////
    void ShowVersion(int iClientH);
		void AdminOrder_ClearNpc(int iClientH);
	///////////////////////////////////////////////////////////////////
	void SetInhibitionFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	///////////////////////////////////////////////////////////////////
	void AdminOrder_SetStatus(int iClientH, char *pData, DWORD dwMsgSize);
	void AdminOrder_Kill(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Revive(int iClientH, char * pData, DWORD dwMsgSize);
    ///////////////////////////////////////////////////////////////////
	void ReqCreateCraftingHandler(int iClientH, char *pData);
	// void PlayerOrder_GetCrits(int iClientH);
	void GetCrits(int iClientH);
	class CPortion * m_pCraftingConfigList[DEF_MAXPORTIONTYPES];
	///////////////////////////////////////////////////////////////////
	void GetAngelHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void SetAngelFlag(short sOwnerH, char cOwnerType, int iStatus, int iTemp);
	///////////////////////////////////////////////////////////////////
	void Desbug(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_banjail(int iClientH, char * pData, DWORD dwMsgSize);
    void AdminOrder_ban(int iClientH, char * pData, DWORD dwMsgSize);
	////////////////////////APOCALYPSE////////////////////////////////
	void GlobalStartApocalypseMode();
	void GlobalEndApocalypseMode();
	void LocalStartApocalypseMode(DWORD dwApocalypseGUID);
	void LocalEndApocalypseMode();
	void _CreateApocalypseGUID(DWORD dwApocalypseGUID);
	BOOL bReadApocalypseGUIDFile(char * cFn);
	void RemoveEventNpc(int);
	void AbaddonThunder();
	void SendThunder(int iClient, short sX, short sY, short sV3, short sV4);
	BOOL bApocalypseMobGenerator(int iMapIndex);
	DWORD m_dwThunderTime;
	void DoAbaddonThunderDamageHandler();
	//////////////////////////////////////////////////////////////////


	void RequestResurrectPlayer(int iClientH, BOOL bResurrect);
	void SetIllusionMovementFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetIllusionFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void GetDarkKnightItemHandler(int iClientH);
	int  iUpgradeHeroCapeRequirements(int iClientH, int iItemIndex);
	int  HeroItemChecker(int iItemID, short sEnemyKill, char cContribution, char cSide);
	BOOL bCheckMagicInt(int iClientH);	// v2.24 11/04/06 17:03
	BOOL bChangeState(char cStateChange, char* cStr, char *cVit,char *cDex,char *cInt,char *cMag,char *cChar); // v2.24 11/04/06 17:03 
	void StateChangeHandler(int iClientH, char * pData, DWORD dwMsgSize); // v2.24 11/04/06 17:03 
	void SetHeroFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetPoisonFlag(short sOwnerH, char cOwnerTpe, BOOL bStatus);
	void SetProtectionFromArrowFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetDefenseShieldFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SetMagicProtectionFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	BOOL bGetMultipleItemNamesWhenDeleteNpc(short sNpcType, int iProbability, int iMin, int iMax, 
				short sBaseX, short sBaseY, int iItemSpreadType, int iSpreadRange,
				int		*iItemIDs, POINT *BasePos, int *iNumItem); // v2.23 14/03/06 20:50
	int  iSetSide(int iClientH); // 2002-11-15 Client�� side, onTown, onShop ������ ����
	void RequestHuntmode(int iClientH); // 2002-11-14 ��ɲ� ��� �߰�
	void SetNoHunterMode(int iClientH,BOOL bSendMSG = FALSE); 	// v2.20 2002-12-31 �ΰ��� ��� ���� ���� �� �̵����� ���� �߰� 
	BOOL _bCrusadeLog(int iAction,int iClientH,int iData, char * cName);
	void SetForceRecallTime(int iClientH) ; // v2.17 2002-7-15 
	BOOL bCheckClientMoveFrequency(int iClientH, DWORD dwClientTime); // v2.171
	BOOL bCheckClientMagicFrequency(int iClientH, DWORD dwClientTime); // v2.171
	BOOL bCheckClientAttackFrequency(int iClientH, DWORD dwClientTime); // v2.171
	void RequestGuildNameHandler(int iClientH, int iObjectID, int iIndex); // v2.171
	void ArmorLifeDecrement(int iClientH, int sTargetH, char cOwnerType, int iValue);
	BOOL bCheckIsItemUpgradeSuccess(int iClientH, int iItemIndex, int iSomH,BOOL bBonus = FALSE) ;
	void RequestItemUpgradeHandler(int iClientH, int iItemIndex);
	BOOL bSerchMaster(int iNpcH);
	void GetExp(int iClientH, int iExp, BOOL bIsAttackerOwn = FALSE);
	void PartyOperationResult_Dismiss(int iClientH, char *pName, int iResult, int iPartyID);
	void RequestAcceptJoinPartyHandler(int iClientH, int iResult);
	void RequestDeletePartyHandler(int iClientH);
	void PartyOperationResult_Info(int iClientH, char * pName, int iTotal, char * pNameList);
	void GetPartyInfoHandler(int iClientH);
	void RequestDismissPartyHandler(int iClientH);
	void PartyOperationResult_Join(int iClientH, char *pName, int iResult, int iPartyID);
	void RequestJoinPartyHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void PartyOperationResult_Delete(int iPartyID);
	void PartyOperationResult_Create(int iClientH, char * pName, int iResult, int iPartyID);
	void PartyOperationResultHandler(char * pData);
	void RequestCreatePartyHandler(int iClientH);
	BOOL bCheckAndConvertPlusWeaponItem(int iClientH, int iItemIndex);
	void ResurrectPlayer(int iClientH);
	void AdminOrder_GetFightzoneTicket(int iClientH);
	void KillCrusadeObjects();

	BOOL bReadCrusadeScheduleConfigFile(char * pFn);
	void CrusadeWarStarter();
	BOOL bCopyItemContents(class CItem * pOriginal, class CItem * pCopy);

	int  iGetMapLocationSide(char * pMapName);

	void ManualEndCrusadeMode(int iWinnerSide);
	void ChatMsgHandlerGSM(int iMsgType, int iV1, char * pName, char * pData, DWORD dwMsgSize);
	BOOL bReadCrusadeGUIDFile(char * cFn);
	void _CreateCrusadeGUID(DWORD dwCrusadeGUID, int iWinnerSide);
	void RemoveClientShortCut(int iClientH);
	BOOL bAddClientShortCut(int iClientH);
	void RequestSetGuildConstructLocHandler(int iClientH, int dX, int dY, int iGuildGUID, char * pMapName);
	void GSM_SetGuildConstructLoc(int iGuildGUID, int dX, int dY, char * pMapName);
	void GSM_ConstructionPoint(int iGuildGUID, int iPoint);
	void CheckCommanderConstructionPoint(int iClientH);
	void GlobalStartCrusadeMode();
	void GSM_SetGuildTeleportLoc(int iGuildGUID, int dX, int dY, char * pMapName);
	void SyncMiddlelandMapInfo();
	void _GrandMagicLaunchMsgSend(int iType, char cAttackerSide);
	// v2.15 �ǹ��� HP�� �����ֱ� ���� ������ 
	void GrandMagicResultHandler(char * cMapName, int iCrashedStructureNum, int iStructureDamageAmount, int iCasualities, int iActiveStructure, int iSTCount,char * pData);
	void CalcMeteorStrikeEffectHandler(int iMapIndex);
	void DoMeteorStrikeDamageHandler(int iMapIndex);
	void GSM_RequestFindCharacter(WORD wReqServerID, WORD wReqClientH, char * pName,char * cCharName);
	// v2.15 2002-5-21
	void GSM_RequestShutupPlayer(char * cName,WORD wReqServerID, WORD wReqClientH, WORD wV1,char * cTemp); 
	void ServerStockMsgHandler(char * pData);
	void SendStockMsgToGateServer();
	BOOL bStockMsgToGateServer(char * pData, DWORD dwSize);
	void RequestHelpHandler(int iClientH);
	void RemoveCrusadeStructures();

	// v2.20 2002-12-28 ������ ������ �ΰ��� ������ ����
	void RecallHunterPlayer();

	void _SendMapStatus(int iClientH);
	void MapStatusHandler(int iClientH, int iMode, char * pMapName);
	void SelectCrusadeDutyHandler(int iClientH, int iDuty);
	
	void CheckConnectionHandler(int iClientH, char *pData);
	void RequestSummonWarUnitHandler(int iClientH, int dX, int dY, char cType, char cNum, char cMode);
	void RequestGuildTeleportHandler(int iClientH);
	void RequestSetGuildTeleportLocHandler(int iClientH, int dX, int dY, int iGuildGUID, char * pMapName);
	void MeteorStrikeHandler(int iMapIndex);
	void _LinkStrikePointMapIndex();
	void MeteorStrikeMsgHandler(char cAttackerSide);
	void _NpcBehavior_GrandMagicGenerator(int iNpcH);
	void CollectedManaHandler(WORD wAresdenMana, WORD wElvineMana);
	void SendCollectedMana();
	void CreateCrusadeStructures();

	BOOL bReadCrusadeStructureConfigFile(char * cFn);
	void SaveOccupyFlagData();
	void LocalEndCrusadeMode(int iWinnerSide);
	void LocalStartCrusadeMode(DWORD dwGuildGUID);
	void CheckCrusadeResultCalculation(int iClientH);
	BOOL _bNpcBehavior_Detector(int iNpcH);
	BOOL _bNpcBehavior_ManaCollector(int iNpcH);
	BOOL __bSetConstructionKit(int iMapIndex, int dX, int dY, int iType, int iTimeCost, int iClientH);
	BOOL __bSetAgricultureItem(int iMapIndex, int dX, int dY, int iType, int iSsn,int iClientH);   //v2.19 2002-12-16 ��罺ų
	BOOL bCropsItemDrop(int iClientH, short iTargetH,BOOL bMobDropPos = FALSE);												//v2.19 2002-12-16 ��罺ų
	int bProbabilityTable(int x,int y,int iTable);												//v2.19 2002-12-16 ��� ��ų ����
	void AgingMapSectorInfo();
	void UpdateMapSectorInfo();

	BOOL bGetItemNameWhenDeleteNpc(int & iItemID, short sNpcType, int iItemprobability);

	int iGetItemWeight(class CItem * pItem, int iCount);
	void CancelQuestHandler(int iClientH);
	void ActivateSpecialAbilityHandler(int iClientH);
	void EnergySphereProcessor(BOOL bIsAdminCreate = FALSE, int iClientH = NULL);
	BOOL bCheckEnergySphereDestination(int iNpcH, short sAttackerH, char cAttackerType);
	void JoinPartyHandler(int iClientH, int iV1, char * pMemberName);
	void CreateNewPartyHandler(int iClientH);
	void RequestSellItemListHandler(int iClientH, char * pData);
	void AdminOrder_CreateItem(int iClientH, char * pData, DWORD dwMsgSize);
	void RequestRestartHandler(int iClientH);
	void AdminOrder_SetObserverMode(int iClientH);
	int iRequestPanningMapDataRequest(int iClientH, char * pData);
	void GetMagicAbilityHandler(int iClientH);
	void Effect_Damage_Spot_DamageMove(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sAtkX, short sAtkY, short sV1, short sV2, short sV3, BOOL bExp, int iAttr, BOOL bFly = FALSE);
	void _TamingHandler(int iClientH, int iSkillNum, char cMapIndex, int dX, int dY);
	void RequestCheckAccountPasswordHandler(char * pData, DWORD dwMsgSize);
	int _iTalkToNpcResult_Guard(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	void SetIceFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void _bDecodeNoticementFileContents(char * pData, DWORD dwMsgSize);
	void RequestNoticementHandler(int iClientH, char * pData);
	void _AdjustRareItemValue(class CItem * pItem);
	BOOL _bCheckDupItemID(class CItem * pItem);
	BOOL _bDecodeDupItemIDFileContents(char * pData, DWORD dwMsgSize);
	void NpcDeadItemGenerator(int iNpcH, short sAttackerH, char cAttackerType);
	// int  iGetPlayerABSStatus(int iWhatH, int iRecvH);
	int  iGetPlayerABSStatus(int iWhatH, int iRecvH); // 2002-12-2
	void AdminOrder_DisconnectAll(int iClientH, char * pData, DWORD dwMsgSize);
	void CheckSpecialEvent(int iClientH);
	void CheckSpecialEventThirdYear(int iClientH); // 2002-10-25 3�ֳ� �̺�Ʈ 
	void AdminOrder_Summon(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_SummonAll(int iClientH, char * pData, DWORD dwMsgSize);
	// v2.14 ���� ��ȯ ��ɾ� �߰� 
	void AdminOrder_SummonPlayer(int iClientH, char * pData, DWORD dwMsgSize);
	// v2.15 2002-5-21
	BOOL _bDecodeWorldConfigFileContents(char * pData, DWORD dwMsgSize);
	// v2.17 2002-8-7 // 2002-09-06 #1
	BOOL _bDecodeNpcItemConfigFileContents(char * pData, DWORD dwMsgSize);
	// 2002-12-8 World server ���� ������ ���� 
	BOOL _bDecodeWLServerConfigFileContents(char * pData, DWORD dwMsgSize);
	

	char _cGetSpecialAbility(int iKindSA);
	void AdminOrder_UnsummonBoss(int iClientH);
	void AdminOrder_UnsummonAll(int iClientH);
	void AdminOrder_SetAttackMode(int iClientH, char * pData, DWORD dwMsgSize);
	// v2.17 2002-7-15 
	void AdminOrder_SetForceRecallTime(int iClientH, char * pData, DWORD dwMsgSize);
	
	void BuildItemHandler(int iClientH, char * pData);
	BOOL _bDecodeBuildItemConfigFileContents(char * pData, DWORD dwMsgSize);
	BOOL _bCheckSubLogSocketIndex();
	void _CheckGateSockConnection();

	BOOL _bItemLog(int iAction, int iGiveH, int iRecvH, class CItem * pItem, BOOL bForceItemLog = FALSE) ;
	BOOL _bItemLog(int iAction, int iClientH, char * cName, class CItem * pItem);
	// v2.14 ���Ĵ� �α� 
	BOOL _bPKLog(int iAction, int iAttackerH, int iVictumH, char * cNPC) ;
	BOOL _bCheckGoodItem( class CItem * pItem ); 

	void OnSubLogRead(int iIndex);
	void OnSubLogSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void _CheckStrategicPointOccupyStatus(char cMapIndex);
	void GetMapInitialPoint(int iMapIndex, short * pX, short * pY, char * pPlayerLocation = NULL);
	void AdminOrder_SummonDemon(int iClientH);
	int  iGetMaxHP(int iClientH);
	void _ClearQuestStatus(int iClientH);
	BOOL _bCheckItemReceiveCondition(int iClientH, class CItem * pItem);
	void SendItemNotifyMsg(int iClientH, WORD wMsgType, class CItem * pItem, int iV1);

	int m_iAdminLevelPushPlayer;//
	int _iTalkToNpcResult_WTower(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_WHouse(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_BSmith(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_GShop(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_GuildHall(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	BOOL _bCheckIsQuestCompleted(int iClientH);
	void _CheckQuestEnvironment(int iClientH);
	void _SendQuestContents(int iClientH);
	void QuestAcceptedHandler(int iClientH);
	BOOL _bDecodeQuestConfigFileContents(char * pData, DWORD dwMsgSize);
	void CancelExchangeItem(int iClientH);
	BOOL bAddItem(int iClientH, class CItem * pItem, char cMode);
	void ConfirmExchangeItem(int iClientH);
	void SetExchangeItem(int iClientH, int iItemIndex, int iAmount);
	void ExchangeItemHandler(int iClientH, short sItemIndex, int iAmount, short dX, short dY, WORD wObjectID, char * pItemName);
	void _BWM_Command_Shutup(char * pData);
	void _BWM_Init(int iClientH, char * pData);




	void CheckUniqueItemEquipment(int iClientH);
	void _SetItemPos(int iClientH, char * pData);
	void GetHeroMantleHandler(int iClientH, int iItemID); //void GetHeroMantleHandler(int iClientH);
	int  CheckHeroItemEquipHandler(int iClientH);
	BOOL _bDecodeOccupyFlagSaveFileContents(char * pData, DWORD dwMsgSize);
	void GetOccupyFlagHandler(int iClientH);
	int  _iComposeFlagStatusContents(char * pData);
	void SetSummonMobAction(int iClientH, int iMode, DWORD dwMsgSize, char * pData = NULL);
	BOOL __bSetOccupyFlag(char cMapIndex, int dX, int dY, int iSide, int iEKNum, int iClientH, BOOL bAdminFlag);
	BOOL _bDepleteDestTypeItemUseEffect(int iClientH, int dX, int dY, short sItemIndex, short sDestItemID);
	void SetDownSkillIndexHandler(int iClientH, int iSkillIndex);
	int iGetComboAttackBonus(int iSkill, int iComboCount);
	int  _iGetWeaponSkillType(int iClientH);
	void AdminOrder_GetNpcStatus(int iClientH, char * pData, DWORD dwMsgSize);
	void CheckFireBluring(char cMapIndex, int sX, int sY);
	void NpcTalkHandler(int iClientH, int iWho);
	BOOL bDeleteMineral(int iIndex);
	void _CheckMiningAction(int iClientH, int dX, int dY);
	int iCreateMineral(char cMapIndex, int tX, int tY, char cLevel);
	void MineralGenerator();
	void LocalSavePlayerData(int iClientH);
	BOOL _bDecodePortionConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReqCreatePortionHandler(int iClientH, char * pData);
	void _CheckAttackType(int iClientH, short * spType);
	BOOL bOnClose();
	void AdminOrder_SetInvi(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_Polymorph(int iClientH, char * pData, DWORD dwMsgSize);
	void ForceDisconnectAccount(char * pAccountName, WORD wCount);
	void NpcRequestAssistance(int iNpcH);
	void ToggleSafeAttackModeHandler(int iClientH);
	void AdminOrder_CheckIP(int iClientH, char * pData, DWORD dwMsgSize);
	void SetBerserkFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	void SpecialEventHandler();
	int iGetPlayerRelationship_SendEvent(int iClientH, int iOpponentH);
	int iGetNpcRelationship_SendEvent(int iNpcH, int iOpponentH);
	int _iForcePlayerDisconect();
	void AdminOrder_Teleport(int iClientH, char * pData, DWORD dwMsgSize);
	int iGetMapIndex(char * pMapName);
	//int iGetNpcRelationship(int iClientH, int iOpponentH);
	int iGetNpcRelationship(int iWhatH, int iRecvH);
	int iGetPlayerRelationship(int iClientH, int iOpponentH);
	int iGetWhetherMagicBonusEffect(short sType, char cWheatherStatus);
	void WhetherProcessor();
	int _iCalcPlayerNum(char cMapIndex, short dX, short dY, char cRadius);
	int m_iAdminLevelClearNpc;
	void FishGenerator();
	void ReqGetFishThisTimeHandler(int iClientH);
	void AdminOrder_CreateFish(int iClientH, char * pData, DWORD dwMsgSize);
	void FishProcessor();
	int iCheckFish(int iClientH, char cMapIndex, short dX, short dY);
	BOOL bDeleteFish(int iHandle, int iDelMode);
	int  iCreateFish(char cMapIndex, short sX, short sY, short sDifficulty, class CItem * pItem, int iDifficulty, DWORD dwLastTime);
	void UserCommand_DissmissGuild(int iClientH, char * pData, DWORD dwMsgSize);
	// v1.4311-3 ���� �Լ� ����  Expire -> Ban ���� 
	void UserCommand_BanGuildsman(int iClientH, char * pData, DWORD dwMsgSize);
	// v1.4311-3 �߰� �Լ� ���� �̺�Ʈ�� ����Ͽ� ��ڰ� �������� �����س��´�.
	void AdminOrder_ReserveFightzone(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CloseConn(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CallGuard(int iClientH, char * pData, DWORD dwMsgSize);
	int iGetExpLevel(int iExp);
	void ___RestorePlayerRating(int iClientH);
	void CalcExpStock(int iClientH);
	void ResponseSavePlayerDataReplyHandler(char * pData, DWORD dwMsgSize);
	void SetPlayerReputation(int iClientH, char * pMsg, char cValue, DWORD dwMsgSize);
	void ShutUpPlayer(int iClientH, char * pMsg, DWORD dwMsgSize);
	void CheckDayOrNightMode();
	BOOL bCheckBadWord(char * pString);
	BOOL bCheckResistingPoisonSuccess(short sOwnerH, char cOwnerType);
	void PoisonEffect(int iClientH, int iV1);
	void bSetNpcAttackMode(char * cName, int iTargetH, char cTargetType, BOOL bIsPermAttack);
	BOOL _bGetIsPlayerHostile(int iClientH, int sOwnerH);
	BOOL bAnalyzeCriminalAction(int iClientH, short dX, short dY, BOOL bIsCheck = FALSE);
	void RequestAdminUserMode(int iClientH, char * pData);
	int _iGetPlayerNumberOnSpot(short dX, short dY, char cMapIndex, char cRange);
	void CalcTotalItemEffect(int iClientH, int iEquipItemID, BOOL bNotify = TRUE);
	void ___RestorePlayerCharacteristics(int iClientH);
	void GetPlayerProfile(int iClientH, char * pMsg, DWORD dwMsgSize);
	void SetPlayerProfile(int iClientH, char * pMsg, DWORD dwMsgSize);
	void ToggleWhisperPlayer(int iClientH, char * pMsg, DWORD dwMsgSize);
	void CheckAndNotifyPlayerConnection(int iClientH, char * pMsg, DWORD dwSize);
	int iCalcTotalWeight(int iClientH);
	void ReqRepairItemCofirmHandler(int iClientH, char cItemID, char * pString);
	void ReqRepairItemHandler(int iClientH, char cItemID, char cRepairWhom, char * pString);
	void ReqSellItemConfirmHandler(int iClientH, char cItemID, int iNum, char * pString);
	void ReqSellItemHandler(int iClientH, char cItemID, char cSellToWhom, int iNum, char * pItemName);
	void UseSkillHandler(int iClientH, int iV1, int iV2, int iV3);
	int  iCalculateUseSkillItemEffect(int iOwnerH, char cOwnerType, char cOwnerSkill, int iSkillNum, char cMapIndex, int dX, int dY);
	void ClearSkillUsingStatus(int iClientH);
	void DynamicObjectEffectProcessor();
	int _iGetTotalClients();
	void SendObjectMotionRejectMsg(int iClientH);
	void SetInvisibilityFlag(short sOwnerH, char cOwnerType, BOOL bStatus);
	BOOL bRemoveFromDelayEventList(int iH, char cType, int iEffectType);
	void DelayEventProcessor();
	BOOL bRegisterDelayEvent(int iDelayType, int iEffectType, DWORD dwLastTime, int iTargetH, char cTargetType, char cMapIndex, int dX, int dY, int iV1, int iV2, int iV3);
	int iGetFollowerNumber(short sOwnerH, char cOwnerType);
//	void SetSkillAll(int iClientH);
	int  _iCalcSkillSSNpoint(int iLevel);
	void OnKeyUp(WPARAM wParam, LPARAM lParam);
	void OnKeyDown(WPARAM wParam, LPARAM lParam);
	BOOL bCheckTotalSkillMasteryPoints(int iClientH, int iSkill);
	BOOL bSetItemToBankItem(int iClientH, class CItem * pItem);
	void NpcMagicHandler(int iNpcH, short dX, short dY, short sType);
	BOOL bCheckResistingIceSuccess(char cAttackerDir, short sTargetH, char cTargetType, int iHitRatio);
	BOOL bCheckResistingMagicSuccess(char cAttackerDir, short sTargetH, char cTargetType, int iHitRatio, char cNpc = 0);
	void Effect_SpUp_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_SpDown_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_HpUp_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3);
	void Effect_Damage_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3, BOOL bExp, int iAttr = NULL);
	void UseItemHandler(int iClientH, short sItemIndex, short dX, short dY, short sDestItemID);
	void NpcBehavior_Stop(int iNpcH);
	// v2.15 
	void ItemDepleteHandler(int iClientH, short sItemIndex, BOOL bIsUseItemResult, BOOL bIsLog = TRUE);
	int _iGetArrowItemIndex(int iClientH);
	void RequestFullObjectData(int iClientH, char * pData);
	void DeleteNpc(int iNpcH, BOOL bHeld = TRUE);
	void CalcNextWayPointDestination(int iNpcH);
	void MobGenerator();
	//void CalculateSSN_SkillIndex(int iClientH, short sSkillIndex, int iValue);
	void CalculateSSN_ItemIndex(int iClientH, short sWeaponIndex, int iValue);
	void CheckDynamicObjectList();
	int  iAddDynamicObjectList(short sOwner, char cOwnerType, short sType, char cMapIndex, short sX, short sY, DWORD dwLastTime, int iV1 = NULL);
	int _iCalcMaxLoad(int iClientH);
	void GetRewardMoneyHandler(int iClientH);
	void _PenaltyItemDrop(int iClientH, int iTotal, BOOL bIsSAattacked = FALSE);
	void ApplyCombatKilledPenalty(int iClientH, char cPenaltyLevel, BOOL bIsSAattacked = FALSE, BOOL bItemDrop = FALSE);
	void EnemyKillRewardHandler(int iAttackerH, int iClientH);
	void PK_KillRewardHandler(short sAttackerH, short sVictumH);
	void ApplyPKpenalty(short sAttackerH, short sVictumLevel);
	BOOL bSetItemToBankItem(int iClientH, short sItemIndex);
	void RequestRetrieveItemHandler(int iClientH, char * pData);
	void RequestCivilRightHandler(int iClientH, char * pData);
	BOOL bCheckLimitedUser(int iClientH);
	void LevelUpSettingsHandler(int iClientH, char * pData, DWORD dwMsgSize);
	// v1.4311-3 ���� �Լ�  ������ ���� �Լ� ���� FightzoneReserveHandler
	void FightzoneReserveHandler(int iClientH, char * pData, DWORD dwMsgSize);
	BOOL bCheckLevelUp(int iClientH);
	int iGetLevelExp(int iLevel);
	void TimeManaPointsUp(int iClientH);
	void TimeStaminarPointsUp(int iClientH);
	void Quit();
	BOOL __bReadMapInfo(int iMapIndex);
	void CGame::CheckTitleStatus(int iClientH, char * pData, DWORD dwMsgSize);
	int  _iGetSkillNumber(char * pSkillName);
	void TrainSkillResponse(BOOL bSuccess, int iClientH, int iSkillNum, int iSkillLevel);
	int _iGetMagicNumber(char * pMagicName, int * pReqInt, int * pCost);
	void RequestStudyMagicHandler(int iClientH, char * pName, BOOL bIsPurchase = TRUE);
	BOOL _bDecodeSkillConfigFileContents(char * pData, DWORD dwMsgSize);
	BOOL _bDecodeMagicConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReleaseFollowMode(short sOwnerH, char cOwnerType);
	BOOL bSetNpcFollowMode(char * pName, char * pFollowName, char cFollowOwnerType);
	void RequestTeleportHandler(int iClientH, char * pData, char * cMapName = NULL, int dX = -1, int dY = -1);
	void PlayerMagicHandler(int iClientH, int dX, int dY, short sType, BOOL bItemEffect = FALSE, int iV1 = NULL);
	int  iClientMotion_Magic_Handler(int iClientH, short sX, short sY, char cDir);
	void SendMsgToGateServer(DWORD dwMsg, int iClientH, char * pData = NULL);
	void OnGateRead();
	void OnGateSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void ToggleCombatModeHandler(int iClientH); 
	void GuildNotifyHandler(char * pData, DWORD dwMsgSize);
	void SendGuildMsg(int iClientH, WORD wNotifyMsgType, short sV1, short sV2, char * pString);
	void DelayEventProcess();
	void TimeHitPointsUp(int iClientH);
	void CalculateGuildEffect(int iVictimH, char cVictimType, short sAttackerH);
	void OnStartGameSignal();
	int iDice(int iThrow, int iRange);
	BOOL _bInitNpcAttr(class CNpc * pNpc, char * pNpcName, short sClass, char cSA);
	BOOL _bDecodeNpcConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReleaseItemHandler(int iClientH, short sItemIndex, BOOL bNotice);
	void ClientKilledHandler(int iClientH, int iAttackerH, char cAttackerType, short sDamage);
	int  SetItemCount(int iClientH, char * pItemName, DWORD dwCount);
	int  SetItemCount(int iClientH, int iItemIndex, DWORD dwCount);
	DWORD dwGetItemCount(int iClientH, char * pName);
	void DismissGuildRejectHandler(int iClientH, char * pName);
	void DismissGuildApproveHandler(int iClientH, char * pName);
	void JoinGuildRejectHandler(int iClientH, char * pName);			    
	void JoinGuildApproveHandler(int iClientH, char * pName);
	void SendNotifyMsg(int iFromH, int iToH, WORD wMsgType, DWORD sV1, DWORD sV2, DWORD sV3, char * pString, DWORD sV4 = NULL, DWORD sV5 = NULL, DWORD sV6 = NULL, DWORD sV7 = NULL, DWORD sV8 = NULL, DWORD sV9 = NULL, char * pString2 = NULL, char cValueA = NULL);
	void GiveItemHandler(int iClientH, short sItemIndex, int iAmount, short dX, short dY, WORD wObjectID, char * pItemName);
	void RequestPurchaseItemHandler(int iClientH, char * pItemName, int iNum);
	void RequestPurchaseItemHandler2(int iClientH, char * pItemName, int iNum); // MORLA 2.4 - Para el trade items
	void ResponseDisbandGuildHandler(char * pData, DWORD dwMsgSize);
	void RequestDisbandGuildHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void RequestCreateNewGuildHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void ResponseCreateNewGuildHandler(char * pData, DWORD dwMsgSize);
	int  iClientMotion_Stop_Handler(int iClientH, short sX, short sY, char cDir);
	
	BOOL bEquipItemHandler(int iClientH, short sItemIndex, BOOL bNotify = TRUE);
	BOOL _bAddClientItemList(int iClientH, class CItem * pItem, int * pDelReq);
	int  iClientMotion_GetItem_Handler(int iClientH, short sX, short sY, char cDir);
	void DropItemHandler(int iClientH, short sItemIndex, int iAmount, char * pItemName, BOOL bByPlayer = FALSE);
	void ClientCommonHandler(int iClientH, char * pData);
	BOOL __fastcall bGetMsgQuene(char * pFrom, char * pData, DWORD * pMsgSize, int * pIndex, char * pKey);
	void MsgProcess();
	void RequestDestiny(int iClientH, bool vSelect);
	BOOL __fastcall bPutMsgQuene(char cFrom, char * pData, DWORD dwMsgSize, int iIndex, char cKey);
	void NpcBehavior_Flee(int iNpcH);
	int iGetDangerValue(int iNpcH, short dX, short dY);
	void NpcBehavior_Dead(int iNpcH);
	void NpcKilledHandler(short sAttackerH, char cAttackerType, int iNpcH, short sDamage, BOOL bHeld = TRUE);
	int  iCalculateAttackEffect(short sTargetH, char cTargetType, short sAttackerH, char cAttackerType, int tdX, int tdY, int iAttackMode, BOOL bNearAttack = FALSE, BOOL bIsDash = FALSE, BOOL bArrowDirection = FALSE);
	void RemoveFromTarget(short sTargetH, char cTargetType, int iCode = NULL);
	void NpcBehavior_Attack(int iNpcH);
	void TargetSearch(int iNpcH, short * pTarget, char * pTargetType);
	void NpcBehavior_Move(int iNpcH);
	BOOL bGetEmptyPosition(short * pX, short * pY, char cMapIndex);
	char cGetNextMoveDir(short sX, short sY, short dstX, short dstY, char cMapIndex, char cTurn, int * pError, char cArea = 0, short sOwnerH = 0);
	int  iClientMotion_Attack_Handler(int iClientH, short sX, short sY, short dX, short dY, short wType, char cDir, WORD wTargetObjectID, BOOL bRespose = TRUE, BOOL bIsDash = FALSE);
	void ChatMsgHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void NpcProcess();
	BOOL bCreateNewNpc(char * pNpcName, char * pName, char * pMapName, short sClass, char cSA, char cMoveType, int * poX, int * poY, char * pWaypointList, RECT * pArea, int iSpotMobIndex, char cChangeSide, BOOL bHideGenMode, BOOL bIsSummoned = FALSE, BOOL bFirmBerserk = FALSE, BOOL bIsMaster = FALSE, int iGuildGUID = NULL);
	//BOOL bCreateNewNpc(char * pNpcName, char * pName, char * pMapName, short sX, short sY);
	BOOL _bReadMapInfoFiles(int iMapIndex);
	
	BOOL _bGetIsStringIsNumber(char * pStr);
	BOOL _bInitItemAttr(class CItem * pItem, char * pItemName);
	// v2.17 2002-7-31 �������� ������ ������ȣ�� ������ �� �ְ� �Ѵ�.
	BOOL _bInitItemAttr(class CItem * pItem, int iItemID);
	BOOL bReadProgramConfigFile(char * cFn);
	void GameProcess();
	void InitPlayerData(int iClientH, char * pData, DWORD dwSize);
	void ResponsePlayerDataHandler(char * pData, DWORD dwSize);
	void CheckDenialServiceAttack(int iClientH, DWORD dwClientTime);
	// v2.14 GM Log �� ���� ������ ������ ���� ������ .
	void AdminOrder_VerIP(int iClientH, char * pMsg, DWORD dwSize);
	void PlayerOrder_reset_stats(int iClientH);
	BOOL bSendMsgToLS(DWORD dwMsg, int iClientH, BOOL bFlag = TRUE,char * pData = NULL );
	void OnMainLogRead();
	void New(int iClientH, char *pData, DWORD dwMsgSize);
	void OnMainLogSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	void CheckClientResponseTime();
	void OnTimer(char cType);	
	void MsgChatHandler(int iClientH, char * pData, DWORD dwMsgSize);
	void AdminOrder_CheckPl(int iClientH, char* pData, DWORD dwMsgSize);
	int iComposeMoveMapData(short sX, short sY, int iClientH, char cDir, char * pData);
	void SendEventToNearClient_TypeB(DWORD dwMsgID, WORD wMsgType, char cMapIndex, short sX, short sY, short sV1 = 0, short sV2 = 0, short sV3 = 0, short sV4 = 0);
	void SendEventToNearClient_TypeA(short sOwnerH, char cOwnerType, DWORD dwMsgID, WORD wMsgType, short sV1, short sV2, short sV3);
	void DeleteClient(int iClientH, BOOL bSave, BOOL bNotify, BOOL bCountLogout = TRUE, BOOL bForceCloseConn = FALSE);
	int  iComposeInitMapData(short sX, short sY, int iClientH, char * pData);
	void RequestInitDataHandler(int iClientH, char * pData, char cKey, BOOL bIsNoNameCheck = FALSE);
	void RequestInitPlayerHandler(int iClientH, char * pData, char cKey);
	int  iClientMotion_Move_Handler(int iClientH, short sX, short sY, char cDir, BOOL bIsRun);
	void EsIsPlayerHostile(int iClientH);
	void ClientMotionHandler(int iClientH, char * pData);
	void DisplayInfo(HDC hdc);
	void OnClientRead(int iClientH);
	BOOL bInit();
	void OnClientSocketEvent(UINT message, WPARAM wParam, LPARAM lParam);
	BOOL bAccept(class XSocket * pXSock);
	void GetFightzoneTicketHandler(int iClientH);
	void FightzoneReserveProcessor();
	void AutoSkill(int iClientH);
	BOOL NpcDeadItemGeneratorWithItemEvent(int iNpcH, short sAttackerH, char cAttackerType);
	BOOL bCheckInItemEventList(int iItemID, int iNpcH);
	BOOL _bDecodeTeleportListConfigFileContents(char * pData, DWORD dwMsgSize);
	void ReqCreateSlateHandler(int iClientH, char* pData);
	void SetSlateFlag(int iClientH, short sType, bool bFlag);
	CGame(HWND hWnd);
	virtual ~CGame();
	char m_cServerName[12];
	char m_cGameServerAddr[16];
	char m_cLogServerAddr[16];
	char m_cGateServerAddr[16];
	int  m_iGameServerPort;
	int  m_iLogServerPort;
	int  m_iGateServerPort;
	int  m_iWorldLogServerPort;
	int  m_iLimitedUserExp, m_iLevelExp20;
	
	//private:
	BOOL _bDecodeItemConfigFileContents(char * pData, DWORD dwMsgSize);
	int _iComposePlayerDataFileContents(int iClientH, char * pData);
	BOOL _bDecodePlayerDatafileContents(int iClientH, char * pData, DWORD dwSize);
	BOOL _bRegisterMap(char * pName);

	class CClient * m_pClientList[DEF_MAXCLIENTS];
	class CNpc    * m_pNpcList[DEF_MAXNPCS];
	class CMap    * m_pMapList[DEF_MAXMAPS];
	class CDynamicObject * m_pDynamicObjectList[DEF_MAXDYNAMICOBJECTS];
	class CDelayEvent    * m_pDelayEventList[DEF_MAXDELAYEVENTS];

	class CMsg    * m_pMsgQuene[DEF_MSGQUENESIZE];
	int             m_iQueneHead, m_iQueneTail;
	int             m_iTotalMaps;
	class XSocket * m_pMainLogSock, * m_pGateSock, * m_pRAdminSock;
	int				m_iGateSockConnRetryTimes;
	class CMisc     m_Misc;
	BOOL			m_bIsGameStarted;
	BOOL            m_bIsLogSockAvailable, m_bIsGateSockAvailable;
	BOOL			m_bIsItemAvailable, m_bIsBuildItemAvailable, m_bIsNpcAvailable, m_bIsMagicAvailable;
	BOOL			m_bIsSkillAvailable, m_bIsPortionAvailable, m_bIsQuestAvailable, m_bIsWLServerAvailable;
	BOOL 			m_bIsOnlyClientAvailable;
	class CItem   * m_pItemConfigList[DEF_MAXITEMTYPES];
	class CNpc    * m_pNpcConfigList[DEF_MAXNPCTYPES];
	class CMagic  * m_pMagicConfigList[DEF_MAXMAGICTYPE];
	class CSkill  * m_pSkillConfigList[DEF_MAXSKILLTYPE];
	class CQuest  * m_pQuestConfigList[DEF_MAXQUESTTYPE];
	char            m_pMsgBuffer[DEF_MSGBUFFERSIZE+1];


	HWND  m_hWnd;
	int   m_iTotalClients, m_iMaxClients, m_iTotalGameServerClients, m_iTotalGameServerMaxClients;
	SYSTEMTIME m_MaxUserSysTime;

	BOOL  m_bF1pressed, m_bF4pressed, m_bF12pressed;
	BOOL  m_bOnExitProcess;
	DWORD m_dwExitProcessTime;

	DWORD m_dwWhetherTime, m_dwGameTime1, m_dwGameTime2, m_dwGameTime3, m_dwGameTime4, m_dwGameTime5, m_dwGameTime6, m_dwGameTime8, m_dwFishTime;

	

	BOOL  m_cDayOrNight;
 	int   m_iSkillSSNpoint[102];

	DWORD m_dwSpecialEventTime;
	BOOL  m_bIsSpecialEventTime;
	char  m_cSpecialEventType;

	int   m_iLevelExpTable[300];
 	class CFish * m_pFish[DEF_MAXFISHS];
	class CPortion * m_pPortionConfigList[DEF_MAXPORTIONTYPES];

	BOOL  m_bIsServerShutdowned;
	char  m_cShutDownCode;
	class CMineral * m_pMineral[DEF_MAXMINERALS];
    int   m_iFenixVipMapIndex;
	int   m_iMiddlelandMapIndex;	// �������� �̵鷣�� �� �ε���: �� ���� -1�̸� �̵鷣�� ���� ������ �ǹ� 
	int   m_iAresdenMapIndex;		// �Ʒ����� �� �ε��� 
	int	  m_iElvineMapIndex;		// ������ �� �ε���
	int   m_iAresdenOccupyTiles;
	int   m_iElvineOccupyTiles;
	int   m_iCurMsgs, m_iMaxMsgs;

	// v1.4311-3 ���� ����  ����� �ð��� ������ ���� DWORD m_dwCanFightzoneReserveTime 
	DWORD m_dwCanFightzoneReserveTime ;
	// v1.4311-3 ���� ���� �� �������� ���� ���θ� ���� int  m_iFightZoneReserve[DEF_MAXFIGHTZONE];
	int  m_iFightZoneReserve[DEF_MAXFIGHTZONE] ;
	// v1.4311-3 ���� ���� �����忡 ������ ��� ��ɾ�� ���� �ʵǰ� ��.
	int  m_iFightzoneNoForceRecall  ;

	struct {
		__int64 iFunds;
		__int64 iCrimes;
		__int64 iWins;

	} m_stCityStatus[3];
	
	int	  m_iStrategicStatus;
	
	class XSocket * m_pSubLogSock[DEF_MAXSUBLOGSOCK];
	int   m_iSubLogSockInitIndex;
	BOOL  m_bIsSubLogSockAvailable[DEF_MAXSUBLOGSOCK];
	int	  m_iCurSubLogSockIndex;
	int   m_iSubLogSockFailCount;
	int   m_iSubLogSockActiveCount;	// v1.5 ���� ���� ���°� �����ǰ� �ִ� sub-log-socket ����
	int   m_iAutoRebootingCount;	// v1.5 �ڵ� ����� �� Ƚ�� 

	class CBuildItem * m_pBuildItemList[DEF_MAXBUILDITEMS];
	class CItem * m_pDupItemIDList[DEF_MAXDUPITEMID];

	char * m_pNoticementData;
	DWORD  m_dwNoticementDataSize;

	DWORD  m_dwMapSectorInfoTime;
	int    m_iMapSectorInfoUpdateCount;

	// Crusade ó����
	int	   m_iCrusadeCount;			// 0�̸� ������ ������. 1�̸� ī��Ʈ �ٿ� ����. 
	BOOL   m_bIsCrusadeMode;		// ũ�缼�̵� ���

	struct {
		char cMapName[11];			// ��ġ�Ǵ� �� ��ġ
		char cType;					// ���๰ ����. ��� NPC ������.
		int  dX, dY;				// ��ġ�Ǵ� �ʻ��� ��ġ

	} m_stCrusadeStructures[DEF_MAXCRUSADESTRUCTURES];
	
	//////////// Apocalypse ////////////
	BOOL	m_bIsApocalypseMode;
	DWORD m_dwApocalypseGUID;
	////////////////////////////////////

	
	int m_iCollectedMana[3];
	int m_iAresdenMana, m_iElvineMana;

	class CTeleportLoc m_pGuildTeleportLoc[DEF_MAXGUILDS];
	//

	WORD  m_wServerID_GSS;
	char  m_cGateServerStockMsg[DEF_MAXGATESERVERSTOCKMSGSIZE];
	int   m_iIndexGSS;

	struct {
		int iCrashedStructureNum;
		int iStructureDamageAmount;
		int iCasualties;
	} m_stMeteorStrikeResult;

	// �̵鷣���� ������ �����ϴ� ����ü. �̵鷣�带 ������� �ʴ� ���������� �� ������ �޾� �����Ѵ�.
	struct {
		char cType;			// �̰� NULL�̸� ���ǵ��� �������� �ǹ�.
		char cSide;			// ���̵�
		short sX, sY;		// ��ġ�� ��ġ 
	} m_stMiddleCrusadeStructureInfo[DEF_MAXCRUSADESTRUCTURES];
	int m_iTotalMiddleCrusadeStructures;
 
	// �� ���� �ȿ��� ���� ������ Ŭ���̾�Ʈ�� �ε����� ������� ����Ǿ� �ִ�. 0�� ������ ����Ʈ�� ���̶�� �ǹ�
	int m_iClientShortCut[DEF_MAXCLIENTS+1];

	int m_iNpcConstructionPoint[DEF_MAXNPCTYPES];
	DWORD m_dwCrusadeGUID;
	int   m_iCrusadeWinnerSide;   
	int	  m_iWinnerSide;		//v2.19 2002-11-15 
	int	  m_iNonAttackArea;		//v2.19 2002-11-19 �ʺ� �̵� ���� ���� �Ұ��� �ϱ����� �߰�.

	// v2.15 2002-5-21
	int   m_iWorldMaxUser;

	// v2.17 2002-7-15
	short m_sForceRecallTime;

	BOOL  m_bIsCrusadeWarStarter;
	int   m_iFinalShutdownCount;

	struct {
		int iDay;
		int iHour;
		int iMinute;
	} m_stCrusadeWarSchedule[DEF_MAXSCHEDULE];

	struct {
		int iTotalMembers;
		int iIndex[DEF_MAXPARTYMEMBERS];
	} m_stPartyInfo[DEF_MAXPARTYNUM];

	class CItem * m_pGold;

	// 2002-09-09 #1
	// NPCITEM List���� ITEM List�� ���� ���� �ߴ��� �˻��ϴ� ����
	bool	m_bReceivedItemList;
	
	BOOL  m_bAdminSecurity;
	
	char m_cMsg1[101];
	BOOL m_bAnunciosActivo;
	
private:
	int __iSearchForQuest(int iClientH, int iWho, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	int _iTalkToNpcResult_Cityhall(int iClientH, int * pQuestType, int * pMode, int * pRewardType, int * pRewardAmount, int * pContribution, char * pTargetName, int * pTargetType, int * pTargetCount, int * pX, int * pY, int * pRange);
	void _ClearExchangeStatus(int iClientH);
	int _iGetItemSpaceLeft(int iClientH);
	/*webdata*/
	short vWebTotalUser, vWebMapAresden, vWebMapElvine, vWebMapMiddleland, vWebLocAresden, 
	vWebLocElvine, vWebLocAreHunter, vWebLocElvHunter, vWebUserParty, vWebUserGuildmaster,
	vWebUserMen, vWebUserWoman, vWebUser5000eks, vWebUser3000eks, vWebUserGuildmember, 
	vWebUser1000eks, vWebUser500eks, vWebUser300eks, vWebUser100eks, vWebUser500rep, vWebUserInactive, 
	vWebUser300rep, vWebUser100rep, vWebUser50rep, vWebUser30rep, vWebUser10rep, vWebMapOther, MaxPlayers, GMsOnline;
	void AdminOrder_SummonGuild(int iClientH, char *pData, DWORD dwMsgSize);
	/**/
	void ManualStartHappyHour(int iClientH, char *pData, DWORD dwMsgSize);
	void closeHappyHour();
	void openHappyHour();
	//FurDay by prlucas
	void ManualStartFuryDay(int iClientH, char *pData, DWORD dwMsgSize);
	void closeFuryDay();
	void openFuryDay();


public:
	//News Addons - ZeroEoyPnk
	void RefreshPartyStatus(int iClientH);
	void RefreshPartyCoords(int iClientH);

	DWORD m_dwCleanMap;

	//Settings.cfg
	BOOL bReadSettingsConfigFile(char * cFn);

	int m_iEnemyKillAdjust;
	int m_iGoldProbability;
	int m_iGoldProbMin;
	int m_iGoldProbMax;
	short m_sCharStatLimit;
	short m_sCharSkillLimit;
	char m_cRepDropModifier;
	int m_iPlayerMaxLevel;
	BOOL m_bLogChatOption;
	int	 m_iPrimaryDropRate, m_iSecondaryDropRate;
	short m_sMedidorExp79;
	short m_sMedidorExp139;
	short m_sMedidorExp159;
	short m_sMedidorExp179;
	short m_sMedidorExp249;
	short m_sMedidorExp250;
	short m_sSlateSuccessRate;
	BOOL m_bPartyEkPerLevel140;
	int m_iPartyEk140_1, m_iPartyEk140_2, m_iPartyEk140_3;
	BOOL m_bPartyEkPerLevel180;
	int m_iPartyEk180_1, m_iPartyEk180_2, m_iPartyEk180_3;
	BOOL m_b100skill;

	void GMUpdateConfigs();

	//RushNet - ZeroEoyPnk
	void LocalStartRushNetMode();
	void LocalEndRushNetMode(int Loser);
	void RemoveRushNetStructures();
	void UpdateRushNet(int Structures);
	void SendHpReliquia();
	BOOL m_bIsRushNetMode;
	BOOL RushPrice;
	int RushWinner;
	DWORD EndRushPrice_Min;
	DWORD EndRushPrice_Hour;
	void CheckRushPrice();
	BOOL bReadRushStructureConfigFile(char * cFn);
	void CreateRushStructures();
	DWORD m_dwRushGUID;
	void CreateRushGUID(int iWinnerSide);
	BOOL bReadRushGUIDFile(char * cFn);
	int LastRushWinnerSide;

	int HeldenianType2;

	struct {
		char cMapName[11];			
		char cType;					
		int  dX, dY;				

	} m_stRushStructures[MAX_RUSHSTRUCTURES];

	//New NPC Bar (Bassed in morla code's) - ZeroEoyPnk
	void ResquestHPNPC(int iClientH, int iV1);

	void GoldPorLevel(int iClientH);

	//New Command Portal - ZeroEoyPnk
	void AdminOrder_Portal(int iClientH, char * pData, DWORD dwMsgSize);
	void ClosePortal(int PortalNum);
	int dest_dx_portal[3], ini_dx_portal[3];
	int dest_dy_portal[3], ini_dy_portal[3];
	int LevelLimit_portal[3], MaxPlayer_portal[3], PortalPlayers[3];
	DWORD dw_TimeOpenPortal[3], dw_TimePortal[3];
	char Portal_MapName[3][256], Portal_Init[3][11];
	BOOL PortalAbility[3];
	
	int LastPortal;


	void HandleRequestMemoryTopEK(int iClientH);
	struct EKPosition
	{
		char Name[11];
		Citizenship Side;
		int EKCount;
	};

	//Trade TOTAL hbnet 22/12
	void CGame::GetTradeEkItemsHandler(int iClientH,int iItemID,char * pString);
	void ZerkMe(int iClientH);
	void ManaMe(int iClientH);
	//Rep command
	void AdminOrder_TradeMajesticPoints(int iClientH);
	void PlayerOrder_ChangeCity(int iClientH);

	void NetBoxLotery(int iClientH, int ItemType);
	void Resultado1(int iClientH, int ItemType);
	void Resultado2(int iClientH, int ItemType);
	void Resultado3(int iClientH, int ItemType);
	void Resultado4(int iClientH, int ItemType);
	void Resultado5(int iClientH, int ItemType);

	void openDeathmach();
	void closeDeathmach();
	void topdeathmach(int iAttackerH, int iClientH);
	void RefreshDeathmach(int iClientH);
	void calcularTop15Deathmach(int iClientH);
	void ordenarTop15Deathmach();
	void CGame::echepiola_clearmap(int iClientH, char * pData, DWORD dwMsgSize);
	

	int  iDGtop[15];
	int  aDGTopKills[16];
	int  aDGTopDeaths[16];
	char  aDGTopClientH[15][11];
	BOOL DeathMatch;
	int iLastKill;
	DWORD  dwTimeLastKill;
	int iTotalKills;
	BOOL bManualDeathmach;
	BOOL ServerActivated;



};

#endif // !defined(AFX_GAME_H__C3D29FC5_755B_11D2_A8E6_00001C7030A6__INCLUDED_)
