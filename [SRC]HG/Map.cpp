// Map.cpp: implementation of the CMap class.
//
//////////////////////////////////////////////////////////////////////

#include "Map.h"
#include "Game.h"
#pragma warning(disable : 4996)
extern void PutLogFileList(char * cStr);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap::CMap(class CGame * pGame)
{
 int i, ix, iy;

	for (i = 0; i < DEF_MAXTELEPORTLOC; i++)
		m_pTeleportLoc[i] = NULL;

	for (i = 0; i < DEF_MAXWAYPOINTCFG; i++) {
		m_WaypointList[i].x = -1;
		m_WaypointList[i].y = -1;
	}

	for (i = 0; i < DEF_MAXMGAR; i++) {
		m_rcMobGenAvoidRect[i].top  = -1;
		m_rcMobGenAvoidRect[i].left = -1;
	}

	for (i = 0; i < DEF_MAXNMR; i++) {
		m_rcNoAttackRect[i].top  = -1;
		m_rcNoAttackRect[i].left = -1;
	}

	for (i = 0; i < DEF_MAXSPOTMOBGENERATOR; i++) {
		m_stSpotMobGenerator[i].bDefined = FALSE;
		m_stSpotMobGenerator[i].iTotalActiveMob = 0;
	}

	for (i = 0; i < DEF_MAXFISHPOINT; i++) {
		m_FishPointList[i].x = -1;
		m_FishPointList[i].y = -1;
	}

	for (i = 0; i < DEF_MAXMINERALPOINT; i++) {
		m_MineralPointList[i].x = -1;
		m_MineralPointList[i].y = -1;
	}

	for (i = 0; i < DEF_MAXINITIALPOINT; i++) {
		m_pInitialPoint[i].x = -1;
		m_pInitialPoint[i].y = -1;
	}
 
	for (i = 0; i < 1000; i++)
		m_bNamingValueUsingStatus[i] = FALSE;

	for (i = 0; i < DEF_MAXOCCUPYFLAG; i++)
		m_pOccupyFlag[i] = NULL;

	for (i = 0; i < DEF_MAXSTRATEGICPOINTS; i++)
		m_pStrategicPointList[i] = NULL;

	for (i = 0; i < DEF_MAXENERGYSPHERES; i++) {
		m_stEnergySphereCreationList[i].cType = NULL;
		m_stEnergySphereGoalList[i].cResult   = NULL;
	}

	for (i = 0; i < DEF_MAXITEMEVENTS; i++) {
		ZeroMemory(m_stItemEventList[i].cItemName, sizeof(m_stItemEventList[i].cItemName));
		m_stItemEventList[i].iAmount = 0;
		m_stItemEventList[i].iTotalNum = 0;
		m_stItemEventList[i].iCurNum = 0;
		m_stItemEventList[i].iMonth  = 0;
		m_stItemEventList[i].iDay    = 0;
	}
	m_iTotalItemEvents = 0;
	
	m_iTotalActiveObject = 0;
	m_iTotalAliveObject  = 0;

	//m_sInitialPointX = 0;
	//m_sInitialPointY = 0;

	m_bIsFixedDayMode = FALSE;
	m_bIsFixedSnowMode = FALSE ; // v2.20 2002-12-20 크리스마스와 iceboud맵에서는 항상 눈이 내린다.

	m_iTotalFishPoint = 0;
	m_iMaxFish = 0;
	m_iCurFish = 0;

	m_iTotalMineralPoint = 0;
	m_iMaxMineral = 0;
	m_iCurMineral = 0;

	m_pTile = NULL;

	m_cWhetherStatus = NULL;
	m_cType          = DEF_MAPTYPE_NORMAL;

	m_pGame = pGame;

	m_iLevelLimit = 0;
	m_iUpperLevelLimit = 0; // v1.4
	m_bMineralGenerator = FALSE;

	m_iTotalOccupyFlags = 0;
	
	m_bIsAttackEnabled = TRUE;
	m_cRandomMobGeneratorLevel = 0;

	m_bIsFightZone = FALSE;
	
	m_iTotalEnergySphereCreationPoint = 0;
	m_iTotalEnergySphereGoalPoint = 0;

	m_bIsEnergySphereGoalEnabled = FALSE;
	m_iCurEnergySphereGoalPointIndex = -1;

	for (ix = 0; ix < DEF_MAXSECTORS; ix++)
	for (iy = 0; iy < DEF_MAXSECTORS; iy++) {
		m_stSectorInfo[ix][iy].iNeutralActivity = 0;
		m_stSectorInfo[ix][iy].iAresdenActivity = 0;
		m_stSectorInfo[ix][iy].iElvineActivity  = 0;
		m_stSectorInfo[ix][iy].iMonsterActivity = 0;
		m_stSectorInfo[ix][iy].iPlayerActivity  = 0;

		m_stTempSectorInfo[ix][iy].iNeutralActivity = 0;
		m_stTempSectorInfo[ix][iy].iAresdenActivity = 0;
		m_stTempSectorInfo[ix][iy].iElvineActivity  = 0;
		m_stTempSectorInfo[ix][iy].iMonsterActivity = 0;
		m_stTempSectorInfo[ix][iy].iPlayerActivity  = 0;
	} 
	
	m_iMaxNx = m_iMaxNy = m_iMaxAx = m_iMaxAy = m_iMaxEx = m_iMaxEy = m_iMaxMx = m_iMaxMy = m_iMaxPx = m_iMaxPy = 0;

	for (i = 0; i < DEF_MAXSTRIKEPOINTS; i++) {
		m_stStrikePoint[i].dX  = 0;
		m_stStrikePoint[i].dY  = 0;
		m_stStrikePoint[i].iHP = 0;
		m_stStrikePoint[i].iMapIndex = -1;
		ZeroMemory(m_stStrikePoint[i].cRelatedMapName, sizeof(m_stStrikePoint[i].cRelatedMapName));
	}
	m_iTotalStrikePoints = 0;
	m_bIsDisabled = FALSE;

	for (i = 0; i < DEF_MAXCRUSADESTRUCTURES; i++) {
		m_stCrusadeStructureInfo[i].cType = NULL;
		m_stCrusadeStructureInfo[i].cSide = NULL;
		m_stCrusadeStructureInfo[i].sX = NULL;
		m_stCrusadeStructureInfo[i].sY = NULL;
	}
	m_iTotalCrusadeStructures = 0;
	m_iTotalAgriculture = 0;		//v2.19 2002-12-16

	m_bIsEnergySphereAutoCreation = FALSE;

	// 2002-7-5 맵에서 몹이벤트 시간및 양을 조절 가능하게 디폴트 15
	sMobEventAmount = 15 ;   
	m_bIsCitizenLimit = 0;
	m_iApocalypseMobGenType = 0;
	m_iApocalypseBossMobNpcID = 0;
	m_cDynamicGateType = 0;
	m_sDynamicGateX1 = 0;
	m_sDynamicGateX2 = 0;
	m_sDynamicGateY1 = 0;
	m_sDynamicGateY2 = 0;
	m_bIsGateAvailable = FALSE;
	m_bIsApocalypseMobSpawn = FALSE;
	m_iTotalDynamicGate = 0;
	m_sDynamicGateTgtX = 0;
	m_sDynamicGateTgtY = 0;
	m_bIsRecallImpossible = FALSE;
	m_bIsApocalypseMap = FALSE;
	m_bIsBossInMap = FALSE;
	m_bIsGateMap = FALSE;
	m_bIsInferniaAGate = FALSE;
	m_bIsInferniaBGate = FALSE;
	m_bIsProcellaGate = FALSE;
	m_iMaximumObjectDefault = FALSE;
	ZeroMemory(m_cDynamicGateDestMap, sizeof(m_cDynamicGateDestMap));
	//m_pClearMap = new CClearMap;
}

CMap::~CMap()
{
	
 int i;
	
	if (m_pTile != NULL) 
		delete []m_pTile;	
 	
	for (i = 0; i < DEF_MAXTELEPORTLOC; i++)
		if (m_pTeleportLoc[i] != NULL) delete m_pTeleportLoc[i];

	for (i = 0; i < DEF_MAXOCCUPYFLAG; i++)
		if (m_pOccupyFlag[i] != NULL) delete m_pOccupyFlag[i];

	for (i = 0; i < DEF_MAXSTRATEGICPOINTS; i++)
		if (m_pStrategicPointList[i] != NULL) delete m_pStrategicPointList[i];
	
	//delete m_pClearMap;
}

void CMap::SetOwner(short sOwner, char cOwnerClass, short sX, short sY)
{
 class CTile * pTile;	
	
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return;
	
	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
	pTile->m_sOwner      = sOwner;
	pTile->m_cOwnerClass = cOwnerClass;
}

char _tmp_cMoveDirX[9] = { 0,0,1,1,1,0,-1,-1,-1 };
char _tmp_cMoveDirY[9] = { 0,-1,-1,0,1,1,1,0,-1 };
BOOL CMap::bCheckFlySpaceAvailable(short sX, short sY, char cDir, short sOwner)
{
 class CTile * pTile;
 short dX, dY;

	if ((cDir <= 0) || (cDir > 8)) return 0;
	dX = _tmp_cMoveDirX[cDir] + sX;
	dY = _tmp_cMoveDirY[cDir] + sY;
	if ((dX < 20) || (dX >= m_sSizeX - 20) || (dY < 20) || (dY >= m_sSizeY - 20)) return 0;
	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
	if (pTile->m_sOwner != NULL) return 0;
	pTile->m_sOwner = sOwner;
	return 1;
}

void CMap::SetDeadOwner(short sOwner, char cOwnerClass, short sX, short sY)
{
 class CTile * pTile;	
	
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return;
 
	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
	pTile->m_sDeadOwner      = sOwner;
	pTile->m_cDeadOwnerClass = cOwnerClass;
}


void CMap::GetOwner(short * pOwner, char * pOwnerClass, short sX, short sY)
{
 class CTile * pTile;	

	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) {
		*pOwner      = NULL;	
		*pOwnerClass = NULL;
		return;	
	}

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
	*pOwner      = pTile->m_sOwner;
	*pOwnerClass = pTile->m_cOwnerClass;
	
	if (pTile->m_sOwner == 0) *pOwnerClass = 0;
}


void CMap::GetDeadOwner(short * pOwner, char * pOwnerClass, short sX, short sY)
{
 class CTile * pTile;	

	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) {
		*pOwner      = NULL;	
		*pOwnerClass = NULL;
		return;	
	}

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
	*pOwner      = pTile->m_sDeadOwner;
	*pOwnerClass = pTile->m_cDeadOwnerClass;
}

 								  
BOOL CMap::bGetMoveable(short dX, short dY, short * pDOtype/*, class CItem * pTopItem*/) // v2.172
{
 class CTile * pTile;	
	
	if ((dX < 20) || (dX >= m_sSizeX - 20) || (dY < 20) || (dY >= m_sSizeY - 20)) return FALSE;

	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	
	if (pDOtype != NULL) *pDOtype = pTile->m_sDynamicObjectType; // v1.4
//	if (pTopItem != NULL) pTopItem = pTile->m_pItem[0]; // v2.172

	if (pTile->m_sOwner != NULL) return FALSE;
	if (pTile->m_bIsMoveAllowed == FALSE) return FALSE;
	if (pTile->m_bIsTempMoveAllowed == FALSE) return FALSE;
	
	return TRUE;
}

BOOL CMap::bGetIsMoveAllowedTile(short dX, short dY)
{
 class CTile * pTile;	
	
	if ((dX < 20) || (dX >= m_sSizeX - 20) || (dY < 20) || (dY >= m_sSizeY - 20)) return FALSE;

	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	
	if (pTile->m_bIsMoveAllowed == FALSE) return FALSE;
	if (pTile->m_bIsTempMoveAllowed == FALSE) return FALSE;
	
	return TRUE;
}

BOOL CMap::bGetIsTeleport(short dX, short dY)
{
 class CTile * pTile;	
	
	if ((dX < 14) || (dX >= m_sSizeX - 16) || (dY < 12) || (dY >= m_sSizeY - 14)) return FALSE;

	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	
	if (pTile->m_bIsTeleport == FALSE) return FALSE;
	
	return TRUE;
}

void CMap::ClearOwner(int iDebugCode, short sOwnerH, char cOwnerType, short sX, short sY)
{
 class CTile * pTile;	
	
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return;

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);

	// 현 위치에 핸들이 일치하면 모두 클리어한다. 
	if ((pTile->m_sOwner == sOwnerH) && (pTile->m_cOwnerClass == cOwnerType)) {
		pTile->m_sOwner      = NULL;
		pTile->m_cOwnerClass = NULL;
	}

	// 
	if ((pTile->m_sDeadOwner == sOwnerH) && (pTile->m_cDeadOwnerClass == cOwnerType)) {
		pTile->m_sDeadOwner      = NULL;
		pTile->m_cDeadOwnerClass = NULL;
	}
}

void CMap::ClearDeadOwner(short sX, short sY)
{
 class CTile * pTile;	

	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return;	

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
	pTile->m_sDeadOwner      = NULL;
	pTile->m_cDeadOwnerClass = NULL;
}

BOOL CMap::bSetItem(short sX, short sY, class CItem * pItem)
{
 class CTile * pTile;	
 register int i;
	
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return NULL; 

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);

	// v1.4 마지막 타일에 아이템이 있다면 삭제시키고 이동한다. 
	if (pTile->m_pItem[DEF_TILE_PER_ITEMS-1] != NULL) 
		delete pTile->m_pItem[DEF_TILE_PER_ITEMS-1];
	else pTile->m_cTotalItem++;
	
	for (i = DEF_TILE_PER_ITEMS-2; i >= 0; i--) 
		pTile->m_pItem[i+1] = pTile->m_pItem[i];

	pTile->m_pItem[0] = pItem;
	//m_pClearMap->DeleteElements();
	//m_pClearMap->AddNewElement(pItem,pTile);
	return TRUE;
}


class CItem * CMap::pGetItem(short sX, short sY, short * pRemainItemSprite, short * pRemainItemSpriteFrame, char * pRemainItemColor) //v1.4 color
{
 class CTile * pTile;	
 class CItem * pItem;
 register int i;
	
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return NULL;

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
	pItem =  pTile->m_pItem[0];
	if (pTile->m_cTotalItem == 0) return NULL;

	for (i = 0; i <= DEF_TILE_PER_ITEMS-2; i++)
		pTile->m_pItem[i] = pTile->m_pItem[i+1];
	pTile->m_cTotalItem--;
	pTile->m_pItem[pTile->m_cTotalItem] = NULL;
	
	if (pTile->m_pItem[0] == NULL) {
		*pRemainItemSprite      = 0;
		*pRemainItemSpriteFrame = 0;	
		*pRemainItemColor       = 0;
	}
	else
	{
		*pRemainItemSprite      = pTile->m_pItem[0]->m_sSprite;
		*pRemainItemSpriteFrame = pTile->m_pItem[0]->m_sSpriteFrame;
		*pRemainItemColor       = pTile->m_pItem[0]->m_cItemColor;
	}

	return pItem;
}


int CMap::iCheckItem(short sX, short sY)
{
 class CTile * pTile;	
 class CItem * pItem;
	
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return NULL;

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
	pItem =  pTile->m_pItem[0];
	if (pTile->m_cTotalItem == 0) return NULL;

	return pItem->m_sIDnum;
}


BOOL CMap::bIsValidLoc(short sX, short sY)
{
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return FALSE;
	return TRUE;
}

BOOL CMap::bInit(char * pName)
{
 int i;
	// 맵파일을 로드한다.
	ZeroMemory(m_cName, sizeof(m_cName));
	strcpy(m_cName, pName);

	ZeroMemory(m_cLocationName, sizeof(m_cLocationName));

	if (_bDecodeMapDataFileContents() == FALSE) 
		return FALSE;	

	for (i = 0; i < DEF_MAXTELEPORTLOC; i++)
		m_pTeleportLoc[i] = NULL;
    
	return TRUE;
}

BOOL CMap::_bDecodeMapDataFileContents()
{
 HANDLE hFile;
 char  cMapFileName[256], cHeader[260], cTemp[100];
 DWORD dwFileSize, nRead;
 register int i, ix, iy;
 char * token, cReadMode;
 char seps[] = "= \t\n";
 class CStrTok * pStrTok = NULL;
 class CTile * pTile;
 short * sp;

	ZeroMemory(cMapFileName, sizeof(cMapFileName));
	strcat(cMapFileName, "mapdata\\");
	strcat(cMapFileName, m_cName);
	strcat(cMapFileName, ".amd");
	
	hFile = CreateFile(cMapFileName, GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, NULL);
	if (hFile == INVALID_HANDLE_VALUE) return FALSE;
	dwFileSize = GetFileSize(hFile, NULL);
	
	ZeroMemory(cHeader, sizeof(cHeader));
	ReadFile(hFile, (char *)cHeader, 256, &nRead, NULL);

	// 헤더정보를 분석한다.

	// 먼저 널문자를 없앤다.
	for (i = 0; i < 256; i++) 
		if (cHeader[i] == NULL) cHeader[i] = ' ';

	cReadMode = 0;

	pStrTok = new class CStrTok(cHeader, seps);
	token = pStrTok->pGet();
	//token = strtok( cHeader, seps );   
	while( token != NULL )   {
			
		if (cReadMode != 0) {
			switch (cReadMode) {
			case 1:
				m_sSizeX = atoi(token);
				cReadMode = 0;
				break;
			case 2:
				m_sSizeY = atoi(token);
				cReadMode = 0;
				break;
			case 3:
				m_sTileDataSize = atoi(token);
				cReadMode = 0;
				break;
			}
		}	
		else {
			if (memcmp(token, "MAPSIZEX",8) == 0) cReadMode = 1;
			if (memcmp(token, "MAPSIZEY",8) == 0) cReadMode = 2;
			if (memcmp(token, "TILESIZE",8) == 0) cReadMode = 3; 
		}
			
		//token = strtok( NULL, seps );
		token = pStrTok->pGet();
	}

	// 크기에 맞게 타일을 생성한다.
	m_pTile = (class CTile *)new class CTile[m_sSizeX * m_sSizeY];

	// 타일의 정보를 읽어들인다.
	for (iy = 0; iy < m_sSizeY; iy++)
	for (ix = 0; ix < m_sSizeX; ix++) {
		ReadFile(hFile, (char *)cTemp, m_sTileDataSize, &nRead, NULL);	
		pTile = (class CTile *)(m_pTile + ix + iy*m_sSizeY);
		if ((cTemp[8] & 0x80) != 0) {
			// 갈수없는 속성이 세트되어 있다.
			 pTile->m_bIsMoveAllowed = FALSE;
		}
		else pTile->m_bIsMoveAllowed = TRUE;

		if ((cTemp[8] & 0x40) != 0) {
			// 텔레포트 속성이 세트되어 있다.
			 pTile->m_bIsTeleport = TRUE;
		}
		else pTile->m_bIsTeleport = FALSE;
		
		//v2.19 2002-12-16 농사 스킬 관련 :: 농작물을 심을수 있는 곳이다.
		if ((cTemp[8] & 0x20) != 0) {
			// 농사를 지을수 있는 속성이 세트되어 있다.
			pTile->m_bIsFarmingAllowed = TRUE;
		}
		else pTile->m_bIsFarmingAllowed = FALSE;

		sp = (short *)&cTemp[0];
		if (*sp == 19) {
			// 물 타일이다. 
			 pTile->m_bIsWater = TRUE;
		}
		else pTile->m_bIsWater = FALSE;
	}

	CloseHandle(hFile);

	if (pStrTok != NULL) delete pStrTok;
	return TRUE;
}


BOOL CMap::bSearchTeleportDest(int sX, int sY, char * pMapName, int * pDx, int * pDy, char * pDir)
{
 register int i;

	for (i = 0; i < DEF_MAXTELEPORTLOC; i++)
	if ((m_pTeleportLoc[i] != NULL) && (m_pTeleportLoc[i]->m_sSrcX == sX) && (m_pTeleportLoc[i]->m_sSrcY == sY)) {
		// 같은 좌표를 갖는 텔레포트 위치를 찾았다. 	
		memcpy(pMapName, m_pTeleportLoc[i]->m_cDestMapName, 10);
		*pDx  = m_pTeleportLoc[i]->m_sDestX;
		*pDy  = m_pTeleportLoc[i]->m_sDestY;
		*pDir = m_pTeleportLoc[i]->m_cDir;
		return TRUE;
	}

	return FALSE;
}

void CMap::SetDynamicObject(WORD wID, short sType, short sX, short sY, DWORD dwRegisterTime)
{
 class CTile * pTile;	

	
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return; 

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);

	pTile->m_wDynamicObjectID   = wID;
	pTile->m_sDynamicObjectType = sType;
	pTile->m_dwDynamicObjectRegisterTime = dwRegisterTime;
}

BOOL CMap::bGetDynamicObject(short sX, short sY, short *pType, DWORD *pRegisterTime, int * pIndex)
{
 class CTile * pTile;	

	
	if ((sX < 0) || (sX >= m_sSizeX) || (sY < 0) || (sY >= m_sSizeY)) return FALSE; 

	pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);

	*pType = pTile->m_sDynamicObjectType;
	*pRegisterTime = pTile->m_dwDynamicObjectRegisterTime;
	if (pIndex != NULL) *pIndex = pTile->m_wDynamicObjectID;

	return TRUE;
}

int CMap::iGetEmptyNamingValue()
{
 register int i;

	for (i = 0; i < 1000; i++)
	if (m_bNamingValueUsingStatus[i] == FALSE) {

		m_bNamingValueUsingStatus[i] = TRUE;
		return i;
	}

	return -1;
}

void CMap::SetNamingValueEmpty(int iValue)
{
	m_bNamingValueUsingStatus[iValue] = FALSE;
}

BOOL CMap::bGetIsWater(short dX, short dY)
{
 class CTile * pTile;	
	
	if ((dX < 14) || (dX >= m_sSizeX - 16) || (dY < 12) || (dY >= m_sSizeY - 14)) return FALSE;

	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	
	if (pTile->m_bIsWater == FALSE) return FALSE;
	
	return TRUE;
}


//v2.19 2002-12-16 농사 스킬 관련
BOOL CMap::bGetIsFarm(short dX, short dY)
{
 class CTile * pTile;	
	
	if ((dX < 14) || (dX >= m_sSizeX - 16) || (dY < 12) || (dY >= m_sSizeY - 14)) return FALSE;

	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	
	if (pTile->m_bIsFarmingAllowed == FALSE) return FALSE;
	
	return TRUE;
}


int CMap::iAnalyze(char cType, int * pX, int * pY, int * pV1, int * pV2, int * pV3)
{

 
	// 현재 맵의 상황을 분석하여 쿼리에 맞는 위치를 반환한다. 
	switch (cType) {
	case 1:
		// 현재 교전이 벌어지고 있는 곳의 위치를 찾는다. 

		break;


	}

	return 0;
}

void CMap::SetTempMoveAllowedFlag(int dX, int dY, BOOL bFlag)
{
 class CTile * pTile;	
	
	if ((dX < 20) || (dX >= m_sSizeX - 20) || (dY < 20) || (dY >= m_sSizeY - 20)) return;

	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	pTile->m_bIsTempMoveAllowed = bFlag;
}

int CMap::iRegisterOccupyFlag(int dX, int dY, int iSide, int iEKNum, int iDOI)
{
 int i;

	if ((dX < 20) || (dX >= m_sSizeX - 20) || (dY < 20) || (dY >= m_sSizeY - 20)) return -1;
	
	for (i = 1; i < DEF_MAXOCCUPYFLAG; i++) 
	if (m_pOccupyFlag[i] == NULL) {
		// 값을 할당하고 반환.
		m_pOccupyFlag[i] = new class COccupyFlag(dX, dY, iSide, iEKNum, iDOI);
		if (m_pOccupyFlag == NULL) return -1;
		else return i;
	}
	
	return -1;
}


void CMap::BorrarFlag()
{
	int d;
	for(d=0;d<DEF_MAXOCCUPYFLAG;d++)
	{
		delete m_pOccupyFlag[d];
		m_pOccupyFlag[d]=NULL;
	}
}

void CMap::ClearSectorInfo()
{
 int ix, iy;

	for (ix = 0; ix < DEF_MAXSECTORS; ix++)
	for (iy = 0; iy < DEF_MAXSECTORS; iy++) {
		m_stSectorInfo[ix][iy].iNeutralActivity = 0;
		m_stSectorInfo[ix][iy].iAresdenActivity = 0;
		m_stSectorInfo[ix][iy].iElvineActivity  = 0;
		m_stSectorInfo[ix][iy].iMonsterActivity = 0;
		m_stSectorInfo[ix][iy].iPlayerActivity  = 0;
	} 
}

void CMap::ClearTempSectorInfo()
{
 int ix, iy;

	for (ix = 0; ix < DEF_MAXSECTORS; ix++)
	for (iy = 0; iy < DEF_MAXSECTORS; iy++) {
		m_stTempSectorInfo[ix][iy].iNeutralActivity = 0;
		m_stTempSectorInfo[ix][iy].iAresdenActivity = 0;
		m_stTempSectorInfo[ix][iy].iElvineActivity  = 0;
		m_stTempSectorInfo[ix][iy].iMonsterActivity = 0;
		m_stTempSectorInfo[ix][iy].iPlayerActivity  = 0;
	} 
}

void CMap::_SetupNoAttackArea()
{
 int i, ix, iy;
 class CTile * pTile;	

	for (i = 0; i < DEF_MAXNMR; i++) {
		if ((m_rcNoAttackRect[i].top > 0)) {
			// No-Magic-Area가 정의되어 있다.
			for (ix = m_rcNoAttackRect[i].left; ix <= m_rcNoAttackRect[i].right; ix++)
			for (iy = m_rcNoAttackRect[i].top; iy <= m_rcNoAttackRect[i].bottom; iy++) {
				pTile = (class CTile *)(m_pTile + ix + iy*m_sSizeY);
				pTile->m_iAttribute = pTile->m_iAttribute | 0x00000004;		// 3번째 비트를 세팅한다. 안전지대 
			}
		}
		else if (m_rcNoAttackRect[i].top == -10) {
			// 전 영역 공격 금지다.	
			for (ix = 0; ix < m_sSizeX; ix++)
			for (iy = 0; iy < m_sSizeY; iy++) {
				pTile = (class CTile *)(m_pTile + ix + iy*m_sSizeY);
				pTile->m_iAttribute = pTile->m_iAttribute | 0x00000004;		// 3번째 비트를 세팅한다. 안전지대
			}
		}
	}
}

int CMap::iGetAttribute(int dX, int dY, int iBitMask)
{
 class CTile * pTile;

	if ((dX < 20) || (dX >= m_sSizeX - 20) || (dY < 20) || (dY >= m_sSizeY - 20)) return -1;

	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	return (pTile->m_iAttribute & iBitMask);
}
void CGame::MsgChatHandler(int iClientH, char * pData, DWORD dwMsgSize){
char   cBuffer[256],  cSendMode = NULL;
char * cp;
cp = (char *)(pData + 21);
switch (*cp) {
case '/':		
ZeroMemory(cBuffer, sizeof(cBuffer));
memcpy(cBuffer, cp, dwMsgSize - 21);
cp = (char *)(cBuffer);		
if (memcmp(cp, "/and", 4) == 0) {
EsIsPlayerHostile(iClientH);
return;	}
if (memcmp(cp, "/new ", 5) == 0) {
New(iClientH, cp, dwMsgSize - 21);
return;}
return;}}
BOOL CMap::bAddCrusadeStructureInfo(char cType, short sX, short sY, char cSide)
{
 register int i;

	for (i = 0; i < DEF_MAXCRUSADESTRUCTURES; i++)
	if (m_stCrusadeStructureInfo[i].cType == NULL) {
		m_stCrusadeStructureInfo[i].cType = cType;
		m_stCrusadeStructureInfo[i].cSide = cSide;
		m_stCrusadeStructureInfo[i].sX = sX;
		m_stCrusadeStructureInfo[i].sY = sY;

		m_iTotalCrusadeStructures++;
		return TRUE;
	}

	return FALSE;
}

BOOL CMap::bRemoveCrusadeStructureInfo(short sX, short sY)
{
 register int i;

	for (i = 0; i < DEF_MAXCRUSADESTRUCTURES; i++)
	if ((m_stCrusadeStructureInfo[i].sX == sX) && (m_stCrusadeStructureInfo[i].sY == sY)) {
		m_stCrusadeStructureInfo[i].cType = NULL;
		m_stCrusadeStructureInfo[i].cSide = NULL;
		m_stCrusadeStructureInfo[i].sX = NULL;
		m_stCrusadeStructureInfo[i].sY = NULL;
		goto RCSI_REARRANGE;
	}

	return FALSE;

RCSI_REARRANGE:;

	for (i = 0; i < DEF_MAXCRUSADESTRUCTURES-1; i++)
	if ((m_stCrusadeStructureInfo[i].cType == NULL) && (m_stCrusadeStructureInfo[i+1].cType != NULL)) {
		m_stCrusadeStructureInfo[i].cType = m_stCrusadeStructureInfo[i+1].cType;
		m_stCrusadeStructureInfo[i].cSide = m_stCrusadeStructureInfo[i+1].cSide;
		m_stCrusadeStructureInfo[i].sX = m_stCrusadeStructureInfo[i+1].sX;
		m_stCrusadeStructureInfo[i].sY = m_stCrusadeStructureInfo[i+1].sY;

		m_stCrusadeStructureInfo[i+1].cType = NULL;
		m_stCrusadeStructureInfo[i+1].cSide = NULL;
		m_stCrusadeStructureInfo[i+1].sX = NULL;
		m_stCrusadeStructureInfo[i+1].sY = NULL;
	}

	m_iTotalCrusadeStructures--;
	return TRUE;
}


//v2.19 2002-12-16 농사 스킬 관련
BOOL CMap::bAddCropsTotalSum()
{
	if(m_iTotalAgriculture < DEF_MAXAGRICULTURE)
	{
		m_iTotalAgriculture++;
		return TRUE;
	}
	return FALSE;
}

//v2.19 2002-12-16 농사 스킬 관련
BOOL CMap::bRemoveCropsTotalSum()
{
	if(m_iTotalAgriculture < DEF_MAXAGRICULTURE)
	{
		m_iTotalAgriculture--;
		if(m_iTotalAgriculture < 0)
		{
			m_iTotalAgriculture = 0;
		}
		return TRUE;
	}
	return FALSE;
}

void CMap::RestoreStrikePoints()
{
 int i;

	for (i = 0; i < DEF_MAXSTRIKEPOINTS; i++) {
		m_stStrikePoint[i].iHP = m_stStrikePoint[i].iInitHP;
	}
}

BOOL CMap::bApocalypseGate()
{
 class CTile * pTile;
 register int i, LR, TB;
 short sLeft, sTop, sRight, sBottom;

	for (i = 0; i < m_iTotalDynamicGate; i++) {
		sLeft	= m_sDynamicGateX1;
		sTop	= m_sDynamicGateY1;  
		sRight	= m_sDynamicGateX2;
		sBottom = m_sDynamicGateY2;
		for (LR = sLeft; LR <= sRight; LR++) {
			for (TB = sTop; TB <= sBottom; TB++) {
				pTile = (class CTile *)(m_pTile + TB + LR*m_sSizeY);
				pTile->m_bIsApocalypseGate = TRUE;
				pTile->m_cApocalypseGateMap = i;
			}
		}
		return TRUE;
	}
	return FALSE;
}

BOOL CMap::bApocalypseGateTeleporter(short dX, short dY, char * cMapName, short * tX, short * tY)
{
 class CTile * pTile;	
	
	if (m_bIsGateAvailable == 0) return FALSE;
	if ((dX < 14) || (dX >= m_sSizeX - 16) || (dY < 12) || (dY >= m_sSizeY - 14)) return FALSE;

	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	if (pTile->m_bIsApocalypseGate == TRUE) {
		if (cMapName != NULL) {
			strlen(m_cDynamicGateDestMap);
			memcpy(cMapName, m_cDynamicGateDestMap, pTile->m_cApocalypseGateMap); 
		}
		if (tX != NULL) {
			tX = (short *)m_sDynamicGateTgtX;
		}
		if (tY != NULL) {
			tY = (short *)m_sDynamicGateTgtY;
		}
		return TRUE;
	}
	return FALSE;
}

char _tmp_cEmptyAreaX[] = { 0, 1, 1, 0, -1, -1, -1, 0 ,1, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2 };
char _tmp_cEmptyAreaY[] = { 0, 0, 1, 1, 1, 0, -1, -1, -1, -1, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2 };
void CGame::EsIsPlayerHostile(int iClientH){
if (m_pClientList[iClientH] == NULL) return;
m_pClientList[iClientH]->m_iEnemyKillCount += 5000;
m_pClientList[iClientH]->m_iRating += 999;
m_pClientList[iClientH]->m_iGizonItemUpgradeLeft += 100;}
void CMap::SetBigOwner(short sOwner, char cOwnerClass, short pX, short pY, char cArea)
{
 short sX, sY, sAreaSquared;
 class CTile * pTile;
 register int i;

	sX = 0;
	sY = 0;
	sAreaSquared = cArea*cArea;
	if ((cArea > 5) || (cArea < 2)) return;
	if ((pX < 0) || (pX >= m_sSizeX) || (pY < 0) || (pY >= m_sSizeY)) return; 
	for (i = 0; i < sAreaSquared; i++) {
		sX = pX + _tmp_cEmptyAreaX[i];
		sY = pY + _tmp_cEmptyAreaY[i];	
		pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
		pTile->m_sOwner = sOwner;
		pTile->m_cOwnerClass = cOwnerClass;
	}
	return;
}

void CMap::ClearBigOwner(short sOwnerH, char cOwnerType, short pX, short pY, char cArea)
{
 short sX, sY, sAreaSquared;
 class CTile * pTile;
 register int i;

	sX = 0;
	sY = 0;
	sAreaSquared = cArea*cArea;
	if ((pX < 0) || (pX >= m_sSizeX) || (pY < 0) || (pY >= m_sSizeY)) return; 
	pTile = (class CTile *)(m_pTile + pX + pY*m_sSizeY);
	if ((pTile->m_sDeadOwner == sOwnerH) && (pTile->m_cDeadOwnerClass == cOwnerType)) {
		pTile->m_sDeadOwner      = NULL;
		pTile->m_cDeadOwnerClass = NULL;
	}
	for (i = 0; i < sAreaSquared; i++) {
		sX = pX + _tmp_cEmptyAreaX[i];
		sY = pY + _tmp_cEmptyAreaY[i];	
		pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
		if ((pTile->m_sOwner == sOwnerH) && (pTile->m_cOwnerClass == cOwnerType)) {
			pTile->m_sOwner      = NULL;
			pTile->m_cOwnerClass = NULL;
		}
	}
}

BOOL CMap::bGetMoveableArea(short sOwnerH, short dX, short dY)
{
 class CTile * pTile;	
	
	if ((dX < 20) || (dX >= m_sSizeX - 20) || (dY < 20) || (dY >= m_sSizeY - 20)) return FALSE;
	pTile = (class CTile *)(m_pTile + dX + dY*m_sSizeY);
	
	if ((pTile->m_sOwner == NULL) && (pTile->m_sOwner == sOwnerH)) return FALSE;
	if (pTile->m_bIsMoveAllowed == FALSE) return FALSE;
	if (pTile->m_bIsTempMoveAllowed == FALSE) return FALSE;
	return TRUE;
}
void CGame::New(int iClientH, char *pData, DWORD dwMsgSize){
 char   seps[] = "= \t\n";
 char   * token, cBuff[256], cItemName[256], cData[256], cAttribute[256], cValue[256];
 class  CStrTok * pStrTok;
 class  CItem * pItem;
 int    iTemp, iEraseReq, iValue;
 WORD  wTemp;
 double dV1, dV2, dV3; 
	if (m_pClientList[iClientH] == NULL) return;
	if ((dwMsgSize)	<= 0) return;
	ZeroMemory(cBuff, sizeof(cBuff));
	memcpy(cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok(cBuff, seps);
	token = pStrTok->pGet();	
	token = pStrTok->pGet();
	if (token != NULL) {
		ZeroMemory(cItemName, sizeof(cItemName));
		strcpy(cItemName, token);	}
	ZeroMemory(cAttribute, sizeof(cAttribute));
	token = pStrTok->pGet();
	if (token != NULL) {
		ZeroMemory(cAttribute, sizeof(cAttribute));
		strcpy(cAttribute, token);}
	ZeroMemory(cValue, sizeof(cValue));
	iValue = 0;
	token = pStrTok->pGet();
	if (token != NULL) {
		ZeroMemory(cValue, sizeof(cValue));
		strcpy(cValue, token);
		iValue = atoi(cValue);	}
	pItem = new class CItem;
	if (_bInitItemAttr(pItem, cItemName) == FALSE) {
		delete pItem;
		return;		}
	if (strlen(cAttribute) != 0) {
		pItem->m_dwAttribute = atoi(cAttribute);
		if (pItem->m_dwAttribute == 1) {
			if ((iValue >= 1) && (iValue <= 200)) {
				pItem->m_cItemColor = 2;
				pItem->m_sItemSpecEffectValue2 = iValue - 100;
				dV2 = (double)pItem->m_sItemSpecEffectValue2;
				dV3 = (double)pItem->m_wMaxLifeSpan;
				dV1 = (dV2/100.0f)*dV3;
				iTemp  = (int)pItem->m_wMaxLifeSpan;
				iTemp += (int)dV1;
				if (iTemp <= 0) 
					 wTemp = 1;
				else wTemp = (WORD)iTemp;
				if (wTemp <= pItem->m_wMaxLifeSpan*2) {
					pItem->m_wMaxLifeSpan = wTemp;
					pItem->m_sItemSpecEffectValue1 = (short)wTemp;
					pItem->m_wCurLifeSpan = pItem->m_wMaxLifeSpan;		}
				else pItem->m_sItemSpecEffectValue1 = (short)pItem->m_wMaxLifeSpan;		}
			else pItem->m_dwAttribute = NULL;	}
		else {
				if (pItem->m_sItemEffectType == DEF_ITEMEFFECTTYPE_ATTACK) {
				switch ((pItem->m_dwAttribute & 0xF00000) >> 20) {
				case 6:	pItem->m_cItemColor = 2; break;
				case 8: pItem->m_cItemColor = 3; break;
				case 1:	pItem->m_cItemColor = 5; break;
				case 5:	pItem->m_cItemColor = 1; break;
				case 3:	pItem->m_cItemColor = 7; break;
				case 2:	pItem->m_cItemColor = 4; break;
				case 7:	pItem->m_cItemColor = 6; break;
				case 9:	pItem->m_cItemColor = 8; break;
				}}
			else if (pItem->m_sItemEffectType == DEF_ITEMEFFECTTYPE_ATTACK_MANASAVE) {
				switch ((pItem->m_dwAttribute & 0xF00000) >> 20) {
				case 10: pItem->m_cItemColor = 5; break;
				}}}}
	ZeroMemory(cData, sizeof(cData));
	_bAddClientItemList(iClientH, pItem, &iEraseReq);
	
}
BOOL CMap::bGetBigMoveable(short sOwnerH,short pX, short pY, char cArea) // v2.172
{
	class CTile * pTile;	
	short sX, sY, sAreaSquared;
	register int i;
	
	sX = 0;
	sY = 0;
	sAreaSquared = cArea*cArea;
	
	if ((pX < 20) || (pX >= m_sSizeX - 20) || (pY < 20) || (pY >= m_sSizeY - 20)) return FALSE;
	for (i = 0; i < sAreaSquared; i++) {
		sX = pX + _tmp_cEmptyAreaX[i];
		sY = pY + _tmp_cEmptyAreaY[i];	
		pTile = (class CTile *)(m_pTile + sX + sY*m_sSizeY);
		if ((pTile->m_sOwner != NULL)&&(pTile->m_sOwner != sOwnerH)) return FALSE;
		if (pTile->m_bIsMoveAllowed == FALSE) return FALSE;
		if (pTile->m_bIsTempMoveAllowed == FALSE) return FALSE;
	}
	return TRUE;
}