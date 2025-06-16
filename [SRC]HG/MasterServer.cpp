//HELBREATH RETURN HGServer Sources

#include "Game.h"
extern char G_cTxt[512];
extern void PutLogFileList(char * cStr);


void CGame::GetTradeEkItemsHandler(int iClientH,int iItemID,char * pString) 
{ 
 int   i, iNum, iRet, iEraseReq; 
 char  * cp, cData[256], cItemName[21]; 
 class CItem * pItem; 
 DWORD * dwp; 
 short * sp;  
 WORD  * wp; 

	if (m_pClientList[iClientH] == NULL) return; 
	if (m_pClientList[iClientH]->m_cSide == 0) return; 
	if (_iGetItemSpaceLeft(iClientH) == 0) {
		SendItemNotifyMsg(iClientH,	DEF_NOTIFY_CANNOTCARRYMOREITEM, NULL, NULL);
		return;
	}

	//Prevents a crash if item dosent exist
	if (m_pItemConfigList[iItemID] == NULL)  return;
 
	switch(iItemID) 
	{ 

	case 846: // The_Devastator
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 180000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 180000; 
		break;
	case 845: // StormBringer
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 160000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 160000; 
		break;
	case 847: // DemonSlayer
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 30000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 30000; 
		break;
	case 848: // LightingBlade
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 80000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 80000; 
		break; 

	case 620: // MerienShield
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 70000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 70000; 
		break;

	case 621: // MerienPlateMailM
	case 622: // MerienPlateMailW
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 20000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 20000; 
		break;

	case 631: // RingofAbaddon
		if(this->m_pClientList[iClientH]->m_iEnemyKillCount < 5500) return; 
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 5500; 
		break;

	case 641: // KnecklaceOfMedusa
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 25000) return; 
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 25000; 
		break;

	case 646: // BeholderNeck
		if (this->m_pClientList[iClientH]->m_iEnemyKillCount < 50000) return; 
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 50000;
		break;

	case 650: // ZemstoneofSacrifice
	case 656: // StoneOfMerien 
	case 657: // StoneOfXelima
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 250) return; 
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 250; 
		break;

	case 734: // RingofArcMage
		if(this->m_pClientList[iClientH]->m_iEnemyKillCount < 5500) return; 
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 5500; 
		break;

	case 762: // Giant Battle Hammer
		if (this->m_pClientList[iClientH]->m_iEnemyKillCount < 100000) return;
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 100000;
		break;

	case 849: //KlonessBlade
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 55000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 90000; 
		break;
	case 850: // KlonessAxe  
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 50000) return; 
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 50000; 
		break;

	case 851: // KlonessEsterk 
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 25000) return; 
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 25000; 
		break; 

	case 857: // I.M.C Manual
		if (this->m_pClientList[iClientH]->m_iEnemyKillCount < 50000) return;
		this->m_pClientList[iClientH]->m_iEnemyKillCount -= 50000;
		break;
	/*
	case 4966: // NeckPower(MS.30
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 4000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 4000000; 
		break;

	case 4967: // NeckPowerMerien
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 5000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 5000000; 
		break;

	case 4968: // NeckPowerXelima
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 5000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 5000000; 
		break;

	case 861: // BerserkWand(MS.30)
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 90000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 90000; 
		break;

	*/case 863: // KlonessWand(MS.30) 
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 60000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 60000; 
		break;

	case 865: // ResurWand(MS.30)
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 10000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 10000; 
		break; 
/*
	case 4957: // AresdenStormBringer
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 20000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 200000000; 
		break; 

	case 4958: // ElvineStormBringer
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 20000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 20000000; 
		break; 

	case 4913: // BlackDevastator
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 25000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 25000000; 
		break;

	case 4905: // BlackHammer
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 18000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 18000000; 
		break;

	case 4908: // BlackAxe
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 9000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 9000000; 
		break;

	case 4962: // BlackTowerShield
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 5000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 5000000; 
		break;

	case 4959: // AresElfBow
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 8000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 8000000; 
		break;

	case 4960: // ElvinElfBow
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 8000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 8000000; 
		break;

	case 2090: //PowerWand
	case 890: //PowerSword
		if(m_pClientList[iClientH]->m_iEnemyKillCount < 30000000) return; 
		m_pClientList[iClientH]->m_iEnemyKillCount -= 30000000; 
		break;
*/
	case 2600: //NetBox(Big)
		if(m_pClientList[iClientH]->m_iGizonItemUpgradeLeft < 500) return; 
			m_pClientList[iClientH]->m_iGizonItemUpgradeLeft -= 500; 
		break;

	case 2601: //NetBox(Medium)
		if(m_pClientList[iClientH]->m_iGizonItemUpgradeLeft < 250) return; 
			m_pClientList[iClientH]->m_iGizonItemUpgradeLeft -= 250; 
		break;

	case 2602: //NetBox(Small)
		if(m_pClientList[iClientH]->m_iGizonItemUpgradeLeft < 100) return; 
			m_pClientList[iClientH]->m_iGizonItemUpgradeLeft -= 100; 
		break;

//necks

  default: 
     return; 
     break; 
  } 

  ZeroMemory(cItemName, sizeof(cItemName)); 
  memcpy(cItemName,m_pItemConfigList[iItemID]->m_cName,20); 
  // ReqPurchaseItemHandler
  iNum = 1; 
  for (i = 1; i <= iNum; i++) 
  { 
     pItem = new class CItem; 
     if (_bInitItemAttr(pItem, cItemName) == FALSE) 
     { 
        delete pItem; 
     } 
     else { 
                                 
        if (_bAddClientItemList(iClientH, pItem, &iEraseReq) == TRUE) { 
           if (m_pClientList[iClientH]->m_iCurWeightLoad < 0) m_pClientList[iClientH]->m_iCurWeightLoad = 0; 
            
           wsprintf(G_cTxt, "(*) Get Item on Trade List: Char(%s) Player-EK(%d) Item Obtained(%s)", m_pClientList[iClientH]->m_cCharName, m_pClientList[iClientH]->m_iEnemyKillCount, cItemName); 
          PutLogFileList(G_cTxt); 

           /*pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER; 
           pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1; 
           pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2; 
           pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3; */

           dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID); 
           *dwp = MSGID_NOTIFY; 
           wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE); 
           *wp  = DEF_NOTIFY_ITEMOBTAINED; 
           cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2); 

           *cp = 1; 
           cp++; 
            
           memcpy(cp, pItem->m_cName, 20); 
           cp += 20; 
            
           dwp  = (DWORD *)cp; 
           *dwp = pItem->m_dwCount; 
           cp += 4; 
            
           *cp = pItem->m_cItemType; 
           cp++; 
            
           *cp = pItem->m_cEquipPos; 
           cp++; 
            
           *cp = (char)0;
           cp++; 
            
           sp  = (short *)cp; 
           *sp = pItem->m_sLevelLimit; 
           cp += 2; 
            
           *cp = pItem->m_cGenderLimit; 
           cp++; 
            
           wp = (WORD *)cp; 
           *wp = pItem->m_wCurLifeSpan; 
           cp += 2; 
            
           wp = (WORD *)cp; 
           *wp = pItem->m_wWeight; 
           cp += 2; 
            
           sp  = (short *)cp; 
           *sp = pItem->m_sSprite; 
           cp += 2; 
            
           sp  = (short *)cp; 
           *sp = pItem->m_sSpriteFrame; 
           cp += 2; 

           *cp = pItem->m_cItemColor; 
           cp++; 

           *cp = (char)pItem->m_sItemSpecEffectValue2; // v1.41 
           cp++; 
            
           dwp = (DWORD *)cp; 
           *dwp = pItem->m_dwAttribute; 
           cp += 4; 
           /* 
           *cp = (char)(pItem->m_dwAttribute & 0x00000001); // Custom-Item??? ?? 
           cp++; 
           */ 
                                 
           if (iEraseReq == 1) delete pItem; 
            
           iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 53); 
            
           iCalcTotalWeight(iClientH); 
            
           switch (iRet) { 
           case DEF_XSOCKEVENT_QUENEFULL: 
           case DEF_XSOCKEVENT_SOCKETERROR: 
           case DEF_XSOCKEVENT_CRITICALERROR: 
           case DEF_XSOCKEVENT_SOCKETCLOSED: 
			   PutLogList("DeleteClient75");
              DeleteClient(iClientH, TRUE, TRUE); 
              return; 
           } 
		   SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
           SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ENEMYKILLS, m_pClientList[iClientH]->m_iEnemyKillCount, NULL, NULL, NULL); 
        } 
        else 
        { 
           delete pItem; 

           iCalcTotalWeight(iClientH); 

           dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID); 
           *dwp = MSGID_NOTIFY; 
           wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE); 
           *wp  = DEF_NOTIFY_CANNOTCARRYMOREITEM; 
            
           iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 6); 
           switch (iRet) { 
           case DEF_XSOCKEVENT_QUENEFULL: 
           case DEF_XSOCKEVENT_SOCKETERROR: 
           case DEF_XSOCKEVENT_CRITICALERROR: 
           case DEF_XSOCKEVENT_SOCKETCLOSED: 
				PutLogList("DeleteClient76");
              DeleteClient(iClientH, TRUE, TRUE); 
              return; 
           } 
        } 
     } 
   } 
}

void CGame::ZerkMe(int iClientH)
{
	char ErrorText[64];
	if (this->m_pClientList[iClientH] == NULL) return;

	if (this->m_pClientList[iClientH]->m_iGizonItemUpgradeLeft < ZERK_ME_MAJESTICS)
	{
		wsprintf(ErrorText, "Necesitas %d para conseguir el efecto", ZERK_ME_MAJESTICS);
		this->ShowClientMsg(iClientH, ErrorText);

		return;
	}

	this->m_pClientList[iClientH]->m_cMagicEffectStatus[DEF_MAGICTYPE_BERSERK] = (char)1;
	SetBerserkFlag(iClientH, DEF_OWNERTYPE_PLAYER, TRUE);

	bRegisterDelayEvent(DEF_DELAYEVENTTYPE_MAGICRELEASE, 
		DEF_MAGICTYPE_BERSERK, 
		timeGetTime() + ZERK_ME_DURATION * 1000, 
		iClientH, DEF_OWNERTYPE_PLAYER, NULL, NULL, NULL, 
		1, NULL, NULL);

	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_MAGICEFFECTON, 
		DEF_MAGICTYPE_BERSERK, 1, 
		NULL, NULL);

	this->m_pClientList[iClientH]->m_iGizonItemUpgradeLeft -= ZERK_ME_MAJESTICS;
	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, 
		m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, 
		NULL, NULL, NULL);

	this->ShowClientMsg(iClientH, "Te sientes un guerrero heroico!");
}

void CGame::ManaMe(int iClientH)
{
	char ErrorText[64];
	if (this->m_pClientList[iClientH] == NULL) return;

	if (this->m_pClientList[iClientH]->m_iGizonItemUpgradeLeft < MANA_ME_MAJESTICS)
	{
		wsprintf(ErrorText, "Necesitas %d para conseguir el efecto", MANA_ME_MAJESTICS);
		this->ShowClientMsg(iClientH, ErrorText);

		return;
	}

	this->m_pClientList[iClientH]->m_bManaMe = TRUE;
	this->m_pClientList[iClientH]->m_dwManaMe = timeGetTime();

	this->m_pClientList[iClientH]->m_iGizonItemUpgradeLeft -= MANA_ME_MAJESTICS;
	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, 
		m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, 
		NULL, NULL, NULL);

	this->ShowClientMsg(iClientH, "Te sientes un experto en magia!");
}

//Repme!
/*void CGame::AdminOrder_TradeMajesticPoints(int iClientH)
	{
	 
	if (m_pClientList[iClientH] == NULL) return;
	if ((m_pClientList[iClientH]->m_iRating) > 9999) return;
	if ((m_pClientList[iClientH]->m_iGizonItemUpgradeLeft) < 25) return;
		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_NOTICEMSG, NULL, NULL, NULL, "Imposible, posees menos de 25 MajesticsPoints.");
		return;
	}
	m_pClientList[iClientH]->m_iGizonItemUpgradeLeft -= 25;
	m_pClientList[iClientH]->m_iRating += 5;
	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_NOTICEMSG, NULL, NULL, NULL, "Se ha aÒadido 5 puntos de rep.");
	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
}
*/
// Lo hizo 50cent
void CGame::PlayerOrder_ChangeCity(int iClientH)
{
    class CItem * pItem;
    int i, iEraseReq;
    int iCape, iCape1, iHelm, iBerk, iPlate, iLegs, iRobe, iCap;
    iCape = iCape1 = iHelm = iBerk = iPlate = iLegs = iRobe = iCap = 0;
    if(m_pClientList[iClientH] == NULL) return;
	if(m_pClientList[iClientH]->m_iLevel < DEF_PLAYERMAXLEVEL) return;
    if(m_pClientList[iClientH]->m_iGizonItemUpgradeLeft >= 800)
    {
        for(i = 0; i < DEF_MAXITEMS; i++)
        {
            if(m_pClientList[iClientH]->m_pItemList[i] != NULL)
            {
                switch(m_pClientList[iClientH]->m_pItemList[i]->m_sIDnum)
                {
                    case 400://AresdenHeroCape-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iCape = 1;
                        break;
                    case 401://ElvineHeroCape-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iCape = 2;
                        break;
                    case 403://aHeroHelm(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iHelm = 1;
                        break;
                    case 404://aHeroHelm(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iHelm = 2;
                        break;
                    case 405://eHeroHelm(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iHelm = 3;
                        break;
                    case 406://eHeroHelm(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iHelm = 4;
                        break;
                    case 407://aHeroCap(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iCap = 1;
                        break;
                    case 408://aHeroCap(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iCap = 2;
                        break;
                    case 409://eHeroCap(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iCap = 3;
                        break;
                    case 410://eHeroCap(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iCap = 4;
                        break;
                    case 411://aHeroArmor(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iPlate = 1;
                        break;
                    case 412://aHeroArmor(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iPlate = 2;
                        break;
                    case 413://eHeroArmor(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iPlate = 3;
                        break;
                    case 414://eHeroArmor(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iPlate = 4;
                        break;
                    case 415://aHeroRobe(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iRobe = 1;
                        break;
                    case 416://aHeroRobe(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iRobe = 2;
                        break;
                    case 417://eHeroRobe(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iRobe = 3;
                        break;
                    case 418://eHeroRobe(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iRobe = 4;
                        break;
                    case 419://aHeroHauberk(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iBerk = 1;
                        break;
                    case 420://aHeroHauberk(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iBerk = 2;
                        break;
                    case 421://eHeroHauberk(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iBerk = 3;
                        break;
                    case 422://eHeroHauberk(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iBerk = 4;
                        break;
                    case 423://aHeroLeggings(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iLegs = 1;
                        break;
                    case 424://aHeroLeggings(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iLegs = 2;
                        break;
                    case 425://eHeroLeggings(M)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iLegs = 3;
                        break;
                    case 426://eHeroLeggings(W)-
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iLegs = 4;
                        break;
                    case 427://AresdenHeroCape+1
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iCape1 = 1;
                        break;
                    case 428://ElvineHeroCape+1
                        ItemDepleteHandler(iClientH, i, TRUE, TRUE);
                        iCape1 = 2;
                        break;
                }
            }
        }
        if(iCape != 0)
        {
            pItem = new class CItem;
            if(iCape == 1) _bInitItemAttr(pItem, 401);
            else if(iCape == 2) _bInitItemAttr(pItem, 400);
            pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
            pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
            pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
            pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
            _bAddClientItemList(iClientH, pItem, &iEraseReq);
            SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
        }
        if(iHelm != 0)
        {
            pItem = new class CItem;
            if(iHelm == 1) _bInitItemAttr(pItem, 405);
            else if(iHelm == 2) _bInitItemAttr(pItem, 406);
            else if(iHelm == 3) _bInitItemAttr(pItem, 403);
            else if(iHelm == 4) _bInitItemAttr(pItem, 404);
            pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
            pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
            pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
            pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
            _bAddClientItemList(iClientH, pItem, &iEraseReq);
            SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
        }
        if(iCap != 0)
        {
            pItem = new class CItem;
            if(iCap == 1) _bInitItemAttr(pItem, 409);
            else if(iCap == 2) _bInitItemAttr(pItem, 410);
            else if(iCap == 3) _bInitItemAttr(pItem, 407);
            else if(iCap == 4) _bInitItemAttr(pItem, 408);
            pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
            pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
            pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
            pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
            _bAddClientItemList(iClientH, pItem, &iEraseReq);
            SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
        }
        if(iPlate != 0)
        {
            pItem = new class CItem;
            if(iPlate == 1) _bInitItemAttr(pItem, 413);
            else if(iPlate == 2) _bInitItemAttr(pItem, 414);
            else if(iPlate == 3) _bInitItemAttr(pItem, 411);
            else if(iPlate == 4) _bInitItemAttr(pItem, 412);
            pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
            pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
            pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
            pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
            _bAddClientItemList(iClientH, pItem, &iEraseReq);
            SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
        }
        if(iRobe != 0)
        {
            pItem = new class CItem;
            if(iRobe == 1) _bInitItemAttr(pItem, 417);
            else if(iRobe == 2) _bInitItemAttr(pItem, 418);
            else if(iRobe == 3) _bInitItemAttr(pItem, 415);
            else if(iRobe == 4) _bInitItemAttr(pItem, 416);
            pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
            pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
            pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
            pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
            _bAddClientItemList(iClientH, pItem, &iEraseReq);
            SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
        }
        if(iBerk != 0)
        {
            pItem = new class CItem;
            if(iBerk == 1) _bInitItemAttr(pItem, 421);
            else if(iBerk == 2) _bInitItemAttr(pItem, 422);
            else if(iBerk == 3) _bInitItemAttr(pItem, 419);
            else if(iBerk == 4) _bInitItemAttr(pItem, 420);
            pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
            pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
            pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
            pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
            _bAddClientItemList(iClientH, pItem, &iEraseReq);
            SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
        }
        if(iLegs != 0)
        {
            pItem = new class CItem;
            if(iLegs == 1) _bInitItemAttr(pItem, 425);
            else if(iLegs == 2) _bInitItemAttr(pItem, 426);
            else if(iLegs == 3) _bInitItemAttr(pItem, 423);
            else if(iLegs == 4) _bInitItemAttr(pItem, 424);
            pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
            pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
            pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
            pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
            _bAddClientItemList(iClientH, pItem, &iEraseReq);
            SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
        }
        if(iCape1 != 0)
        {
            pItem = new class CItem;
            if(iCape1 == 1) _bInitItemAttr(pItem, 428);
            else if(iCape1 == 2) _bInitItemAttr(pItem, 427);
            pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
            pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
            pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
            pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
            _bAddClientItemList(iClientH, pItem, &iEraseReq);
            SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
        }
        m_pClientList[iClientH]->m_iGizonItemUpgradeLeft -= 800;
        SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
        if(memcmp(m_pClientList[iClientH]->m_cLocation, "aresden",7) == 0 ) strcpy(m_pClientList[iClientH]->m_cLocation,"elvine");
        else if (memcmp(m_pClientList[iClientH]->m_cLocation, "elvine",6) == 0 ) strcpy(m_pClientList[iClientH]->m_cLocation,"aresden");
        if(m_pClientList[iClientH]->m_iGuildRank != -1)
        {
            m_pClientList[iClientH]->m_iGuildRank = -1;
            m_pClientList[iClientH]->m_iGuildGUID = -1;
            strcpy(m_pClientList[iClientH]->m_cGuildName,"NONE");
        }
		bSendMsgToLS(MSGID_REQUEST_SAVEPLAYERDATA, iClientH);
        SendNotifyMsg(NULL,iClientH,DEF_NOTIFY_CHANGEPLAYMODE,NULL,NULL,NULL,m_pClientList[iClientH]->m_cLocation);
        ShowClientMsg(iClientH, "Has adquirido una nueva ciudadanÌa");
        wsprintf(G_cTxt, "(!) Player(%s) Request ChangeCity: C(%d) - H(%d) - C(%d) - P(%d) - R(%d) - B(%d) - L(%d) - C(%d)", m_pClientList[iClientH]->m_cCharName, iCape, iHelm, iCap, iPlate, iRobe, iBerk, iLegs, iCape1);
        PutLogList(G_cTxt);
    }
    else
    {
        ShowClientMsg(iClientH, "Necesitas 800 majestic!");
    }
}
void CGame::DeleteNpc(int iNpcH, BOOL bHeld)
{
 int  i, iNamingValue, iItemID, iNumItem, iItemIDs[MAX_NPCITEMDROP];
 char cTmp[21], cItemName[21], cTemp[256];
 class CItem * pItem;
 DWORD dwCount, dwTime;
 POINT	ItemPositions[MAX_NPCITEMDROP];
 SYSTEMTIME SysTime;
 
	if (m_pNpcList[iNpcH] == NULL) return;

	iItemID = 0;
	iNumItem = 0;

	dwTime = timeGetTime();

	//¡◊æÓ¿÷¥¯ ¿ßƒ°ø°º≠ ªË¡¶ 
	SendEventToNearClient_TypeA(iNpcH, DEF_OWNERTYPE_NPC, MSGID_EVENT_LOG, DEF_MSGTYPE_REJECT, NULL, NULL, NULL);
	if (m_pNpcList[iNpcH]->m_sAreaSize == 0) {
		m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->ClearOwner(11, iNpcH, DEF_OWNERTYPE_NPC, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY);
	}
	else {
		m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->ClearBigOwner(iNpcH, DEF_OWNERTYPE_NPC, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, m_pNpcList[iNpcH]->m_sAreaSize);
	}
	ZeroMemory(cTmp, sizeof(cTmp));
	strcpy(cTmp, (char *)(m_pNpcList[iNpcH]->m_cName + 2));
	// NPC¿« NamigValue∏¶ æÚæÓøÕ ªÁøÎ¡ﬂ¿Œ «•Ω√∏¶ «ÿ¡ˆ«—¥Ÿ.
	iNamingValue = atoi(cTmp);

	// NamingValue∏¶ ∫ÒøÏ∞Ì µø¿€¡ﬂ¿Œ ∞≥√º ºˆ∏¶ ∞®º“Ω√≈≤¥Ÿ.
	m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->SetNamingValueEmpty(iNamingValue);
	m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_iTotalActiveObject--;

	// Spot-mob-generator¡§∫∏ 
	if ( m_pNpcList[iNpcH]->m_iSpotMobIndex != NULL )
		m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->m_stSpotMobGenerator[m_pNpcList[iNpcH]->m_iSpotMobIndex].iCurMobs--;

	RemoveFromTarget(iNpcH, DEF_OWNERTYPE_NPC);
	
	switch (m_pNpcList[iNpcH]->m_sType) {
	case 36:
	case 37:
	case 38:
	case 39:
	case 42:
		m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->bRemoveCrusadeStructureInfo(m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY);
		for (i = 0; i < DEF_MAXGUILDS; i++) 
		if (m_pGuildTeleportLoc[i].m_iV1 == m_pNpcList[iNpcH]->m_iGuildGUID) {
			m_pGuildTeleportLoc[i].m_dwTime = dwTime;
			m_pGuildTeleportLoc[i].m_iV2--;
			if (m_pGuildTeleportLoc[i].m_iV2 < 0) m_pGuildTeleportLoc[i].m_iV2 = 0;
			break;	
		}
		break;

	// 2002-12-24 ¿¸∏È¿¸Ω√ º“»Ø«“ ºˆ ¿÷¥¬ (∞«π∞ ºˆ∏¶ ¡¶ø‹«—) NPC¿« ºˆ∏¶ ¡¶«—«—¥Ÿ.(¥Î∏∏ ø‰√ª)
	case 43:
	case 44:
	case 45:
	case 46:
	case 47:
	case 51:
		for (i = 0; i < DEF_MAXGUILDS; i++) 
		if (m_pGuildTeleportLoc[i].m_iV1 == m_pNpcList[iNpcH]->m_iGuildGUID) {
			m_pGuildTeleportLoc[i].m_iNumSummonNpc--;
			if (m_pGuildTeleportLoc[i].m_iNumSummonNpc < 0) m_pGuildTeleportLoc[i].m_iNumSummonNpc = 0;
			break;
		}
		break;

	case 64:	//v2.19 2002-12-16 ≥ÛªÁ Ω∫≈≥ ∞¸∑√
		m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->bRemoveCropsTotalSum();
		break;
	}

	// DelayEvent∏¶ ªË¡¶ 
	bRemoveFromDelayEventList(iNpcH, DEF_OWNERTYPE_NPC, NULL);

	int iItemprobability = 65 ;

	if((m_iMiddlelandMapIndex == m_pNpcList[iNpcH]->m_cMapIndex) && (m_iMiddlelandMapIndex != -1))
	{
		iItemprobability = 55 ;
	}
#ifdef DEF_HIGH
	if(m_iFenixVipMapIndex == m_pNpcList[iNpcH]->m_cMapIndex)
	{
    iItemprobability = 15;
	}
#endif
	if (m_pNpcList[iNpcH]->m_bIsSummoned == FALSE) {
		pItem = new class CItem;
		ZeroMemory(cItemName, sizeof(cItemName));

		switch (m_pNpcList[iNpcH]->m_sType) {
		case 10: 
			if (iDice(1,25) == 1) iItemID = 220 ;				 // "SlimeJelly"	1/16
			break;
		case 16:
			switch (iDice(1,3)) {
			case 1: if (iDice(1,9) == 1)  iItemID = 192 ; break; // "AntLeg"	// 1/18
			case 2: if (iDice(1,10) == 1) iItemID = 193 ; break; // "AntFeeler"	// 1/20
			case 3: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			default: break;
			}
			break;
		case 22:
			switch (iDice(1,5)) {
			case 1: if (iDice(1,15) == 1) iItemID = 188 ; break; // "SnakeMeat"	// 1/20
			case 2: if (iDice(1,16) == 1) iItemID = 189 ; break; // "SnakeSkin"	// 1/24
			case 3: if (iDice(1,16) == 1) iItemID = 190 ; break; // "SnakeTeeth"	// 1/24
			case 4: if (iDice(1,17) == 1) iItemID = 191 ; break; // "SnakeTounge"		// 1/28
			case 5: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}	
			default: break;
			}
			break;
		case 14:
			switch (iDice(1,4)) {
			case 1: if (iDice(1,11) == 1) iItemID = 206 ; break; // "OrcMeat"	// 1/21
			case 2: if (iDice(1,20) == 1) iItemID = 207 ; break; // "OrcLeather"	// 1/30
			case 3: if (iDice(1,21) == 1) iItemID = 208 ; break; // "OrcTeeth"	// 1/33
			case 4: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			default: break;
			}
			break;
		case 17:
			switch (iDice(1,5)) {
			case 1: if (iDice(1,40) == 1) iItemID = 215 ; break; // "ScorpionPincers"	// 1/28
			case 2: if (iDice(1,20) == 1) iItemID = 216 ; break; // "ScorpionMeat"	// 1/28
			case 3: if (iDice(1,40) == 1) iItemID = 217 ; break; // "ScorpionSting"	// 1/36
			case 4: if (iDice(1,40) == 1) iItemID = 218 ; break; // "ScorpionSkin"	// 1/32
			case 5: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			default: break;
			}
			break;

		case 18: // Zombie
			switch (iDice(1,1)) {
			case 1: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
		 	}
			break;

		case 11:
			switch (iDice(1,2)) {
			case 1: if (iDice(1,20) == 1) iItemID = 219 ; break; // "SkeletonBones"	// 1/30
			case 2: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			}
			break;
		case 23:
			switch (iDice(1,2)) {
			case 1: if (iDice(1,30) == 1) iItemID = 205 ; break; // "LumpOfClay"		// 1/30
			case 2: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			}
			break;
		case 12:
			switch (iDice(1,2)) {
			case 1: if (iDice(1,30) == 1) iItemID = 221 ; break; // "StoneGolemPiece"	// 1/30  
			case 2: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			}
			break;
		case 27:
			switch (iDice(1,7)) {
			case 1: if (iDice(1,40) == 1) iItemID = 199 ; break; // "HelhoundHeart"	// 1/60
			case 2: if (iDice(1,30) == 1) iItemID = 200 ; break; // "HelhoundLeather"	// 1/48
			case 3: if (iDice(1,30) == 1) iItemID = 201 ; break; // "HelhoundTail"	// 1/48
			case 4: if (iDice(1,30) == 1) iItemID = 202 ; break; // "HelhoundTeeth"	// 1/36
			case 5: if (iDice(1,30) == 1) iItemID = 203 ; break; // "HelhoundClaw"	// 1/36
			case 6: if (iDice(1,50) == 1) iItemID = 204 ; break; // "HelhoundTounge"	// 1/60
			case 7: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			default: break;
			}
			break;
		case 13:
			switch (iDice(1,6)) {
			case 1: if (iDice(1,30) == 1) iItemID = 194 ; break; // "CyclopsEye"	// 1/80
			case 2: if (iDice(1,40) == 1) iItemID = 195 ; break; // "CyclopsHandEdge"	// 1/100
			case 3: if (iDice(1,30) == 1) iItemID = 196 ; break; // "CyclopsHeart"	// 1/100
			case 4: if (iDice(1,20) == 1) iItemID = 197 ; break; // "CyclopsMeat"	// 1/60
			case 5: if (iDice(1,40) == 1) iItemID = 198 ; break; // "CyclopsLeather"	// 1/90
			case 6: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			default: break;
			}
			break;
		case 28:
			switch (iDice(1,5)) {
			case 1: if (iDice(1,35) == 1) iItemID = 222 ; break; // "TrollHeart"	// 1/60
			case 2: if (iDice(1,23) == 1) iItemID = 223 ; break; // "TrollMeat"	// 1/52
			case 3: if (iDice(1,25) == 1) iItemID = 224 ; break; // "TrollLeather"	// 1/60
			case 4: if (iDice(1,27) == 1) iItemID = 225 ; break; // "TrollClaw"	// 1/68
			case 5: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			default: break;
			}
			break;
		case 29:
			switch (iDice(1,7)) {
			case 1: if (iDice(1,20) == 1) iItemID = 209 ; break; // "OgreHair"	// 1/120
			case 2: if (iDice(1,22) == 1) iItemID = 210 ; break; // "OgreHeart"		// 1/132
			case 3: if (iDice(1,25) == 1) iItemID = 211 ; break; // "OgreMeat"		// 1/90
			case 4: if (iDice(1,25) == 1) iItemID = 212 ; break; // "OgreLeather"	// 1/90
			case 5: if (iDice(1,25) == 1) iItemID = 213 ; break; // "OgreTeeth"		// 1/108
			case 6: if (iDice(1,25) == 1) iItemID = 214 ; break; // "OgreClaw"		// 1/108
			case 7: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			default: break;
			}
			break;
		case 30:
			if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			break;

		case 31:
			switch (iDice(1,5)) {
			case 1: if (iDice(1,15) == 12) iItemID = 541 ; break; // "DemonHeart"
			case 2:	if (iDice(1,5) == 2) iItemID = 542 ; break; // "DemonMeat"
			case 3:	if (iDice(1,10) == 5) iItemID = 543 ; break; // "DemonLeather"
			case 4:	if (iDice(1,15) == 7) iItemID = 540 ; break; // "DemonEye"
			case 5: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			}
			break;

			case 32:case 99:
			// Unicorn
			switch (iDice(1,5)) {
			case 1: if (iDice(1,40) == 3) iItemID = 544 ; break; // "UnicornHeart"
			case 2: if (iDice(1,25) == 3)    iItemID = 545 ; break; // "UnicornHorn"	
			case 3: if (iDice(1,5) == 3)    iItemID = 546 ; break; // "UnicornMeat"	
			case 4: if (iDice(1,15) == 3)    iItemID = 547 ; break; // "UnicornLeather"	
			case 5: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			}
			break;

		case 33:
			switch (iDice(1,8)) {
			case 1: if (iDice(1,30) == 3) iItemID = 551 ; break; // "WerewolfTail"	    // 1/120
			case 2: if (iDice(1,25) == 3) iItemID = 548 ; break; // "WerewolfHeart"		// 1/132
			case 3: if (iDice(1,25) == 3) iItemID = 550 ; break; // "WerewolfMeat"		// 1/90
			case 4: if (iDice(1,35) == 3) iItemID = 553 ; break; // "WerewolfLeather"		// 1/90
			case 5: if (iDice(1,25) == 3) iItemID = 552 ; break; // "WerewolfTeeth"		// 1/108
			case 6: if (iDice(1,25) == 3) iItemID = 554 ; break; // "WerewolfClaw"		// 1/108
			case 7: if (iDice(1,35) == 3) iItemID = 549 ; break; // "WerewolfNail"		// 1/108
			case 8: if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					}
			default: break;
			}
			break;

		case 48: // Stalker
		case 49: // Hellclaw
		case 50: // Tigerworm
		case 52: // Gagoyle
		case 53: // Beholder
		case 54: // Dark-Elf
		case 55: // Rabbit
		case 56: // Cat
		case 57: // Giant-Frog
		case 58: // Mountain Giant
		case 59: // Ettin
		case 61: // Rudolph
		case 63: // Frost
		case 70: // Spider
		case 71: // Spectre
		case 72: // Yeti
		case 75: // Giant-Lizard
		case 77: // DoomDemon
		case 78: // PitLord
		case 79: // Nizie
			if (bHeld == TRUE) { 
				bGetItemNameWhenDeleteNpc(iItemID, m_pNpcList[iNpcH]->m_sType, iItemprobability);
					} break;
			break;
		
		// v2.23 14/03/06 20:47
		case 66: // Wyvern 
			if (bHeld == TRUE) {
			bGetMultipleItemNamesWhenDeleteNpc(m_pNpcList[iNpcH]->m_sType, iItemprobability,
				5, 15, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, DEF_ITEMSPREAD_FIXED, 4, 
				iItemIDs, ItemPositions, &iNumItem);
			}
			break;
			
		case 73: // Fire-Wyvern
			if (bHeld == TRUE) {
			bGetMultipleItemNamesWhenDeleteNpc(m_pNpcList[iNpcH]->m_sType, iItemprobability,
				5, 15, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, DEF_ITEMSPREAD_FIXED, 4,
				iItemIDs, ItemPositions, &iNumItem);
			}
			break;
			
		case 81:
			if (bHeld == TRUE) {
			bGetMultipleItemNamesWhenDeleteNpc( m_pNpcList[iNpcH]->m_sType,	iItemprobability, 
				12, 20, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, DEF_ITEMSPREAD_FIXED, 65,
				iItemIDs, ItemPositions, &iNumItem);
			}
			break;
		}

		dwCount = 1;

		if (iItemID == 0) {
			switch (m_pNpcList[iNpcH]->m_sType) {
			case 30:
			case 31:
			case 32:case 99:
				iItemID = 90 ;
				dwCount = (DWORD)(iDice(1, m_pNpcList[iNpcH]->m_iExpDice * 4) + m_pNpcList[iNpcH]->m_iExpDice);
				dwCount = dwCount - (dwCount/3);
				break;
			}
		}
		
		// v2.23 14/03/06 21:09
		if (iNumItem > 0) {
			GetLocalTime(&SysTime);
			wsprintf(cTemp, "%d%02d%", SysTime.wMonth, SysTime.wDay);
			for (int j = 0; j < iNumItem; j++) {
				if (pItem == NULL) {
					pItem = new class CItem;
				}
				//testing
				if (_bInitItemAttr(pItem, iItemIDs[j]) == FALSE ||
					m_pMapList[m_pNpcList[iNpcH]->m_cMapIndex]->bGetIsMoveAllowedTile((short)ItemPositions[j].x, (short)ItemPositions[j].y) == FALSE) {
					delete pItem;
					pItem = NULL;
				}
				else {
					if (iItemIDs[j] == 90) // Gold
						pItem->m_dwCount = iDice(10, 15000);
					else
						pItem->m_dwCount = dwCount;
					
					pItem->m_sTouchEffectType   = DEF_ITET_ID;
					pItem->m_sTouchEffectValue1 = iDice(1,100000);
					pItem->m_sTouchEffectValue2 = iDice(1,100000);
					pItem->m_sTouchEffectValue3 = timeGetTime();
					
					m_pMapList[ m_pNpcList[iNpcH]->m_cMapIndex ]->bSetItem((short)ItemPositions[j].x, (short)ItemPositions[j].y, pItem);
					SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pNpcList[iNpcH]->m_cMapIndex,
												(short)ItemPositions[j].x, (short)ItemPositions[j].y,	pItem->m_sSprite, pItem->m_sSpriteFrame, pItem->m_cItemColor);
					_bItemLog(DEF_ITEMLOG_NEWGENDROP, NULL, m_pNpcList[iNpcH]->m_cNpcName, pItem);
					pItem = NULL;
				}
			}
		}
		else {
			if (_bInitItemAttr(pItem, iItemID) == FALSE) {
				delete pItem;
				pItem = NULL;
			}
			else {
				// æ∆¿Ã≈€ ºˆ∑Æ ¿‘∑¬ 
				pItem->m_dwCount = dwCount;
			
				// æ∆¿Ã≈€ø° ∞Ì¿Ø ƒ⁄µÂ ¿‘∑¬ 
				pItem->m_sTouchEffectType   = DEF_ITET_ID;
				pItem->m_sTouchEffectValue1 = iDice(1,100000);
				pItem->m_sTouchEffectValue2 = iDice(1,100000);
#ifdef DEF_LOGTIME
				pItem->m_sTouchEffectValue3 = timeGetTime();
#else 
				// ∏∂¡ˆ∏∑ º˝¿⁄¥¬ æ∆¿Ã≈€ ª˝º∫ ø˘, ¿œ	
				//SYSTEMTIME SysTime;
				//char cTemp[256];
				GetLocalTime(&SysTime);
				ZeroMemory(cTemp, sizeof(cTemp));
//				wsprintf(cTemp, "%d%02d%02d",  (short)SysTime.wMonth, (short)SysTime.wDay,(short) SysTime.wHour);
				wsprintf(cTemp, "%d%02d%",  (short)SysTime.wMonth, (short)SysTime.wDay);

				pItem->m_sTouchEffectValue3 = atoi(cTemp);
#endif
			
				// æ∆¿Ã≈€¿ª º≠¿÷¥¬ ¿ßƒ°ø° ∂≥æÓ∂ﬂ∏∞¥Ÿ. 
				m_pMapList[ m_pNpcList[iNpcH]->m_cMapIndex ]->bSetItem(m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, pItem);
						
				// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
				SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pNpcList[iNpcH]->m_cMapIndex,
				    	                m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY,
						                pItem->m_sSprite, pItem->m_sSpriteFrame, pItem->m_cItemColor); // v1.4 color

				// ∑Œ±◊ ≥≤±‰¥Ÿ.
				_bItemLog(DEF_ITEMLOG_NEWGENDROP, 0, m_pNpcList[iNpcH]->m_cNpcName, pItem);
			}
		}
	/*	if (iDice(1, 100000) < 10) {//1
			pItem2 = new class CItem;
			switch(iDice(1,4)){//2
				case 1:	iSlateID = 868; break;
				case 2: iSlateID = 869; break;
				case 3: iSlateID = 870; break;
				case 4: iSlateID = 871; break;
			}//2
			if (_bInitItemAttr(pItem2, iSlateID) == FALSE) {//3
					delete pItem2;
					pItem2 = NULL;
				}//1
			else {//4
				pItem2->m_dwCount = 1;

				pItem2->m_sTouchEffectType   = DEF_ITET_ID;
				pItem2->m_sTouchEffectValue1 = iDice(1,100000);
				pItem2->m_sTouchEffectValue2 = iDice(1,100000);
				pItem2->m_sTouchEffectValue3 = (short)timeGetTime();

				m_pMapList[ m_pNpcList[iNpcH]->m_cMapIndex ]->bSetItem(m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, pItem2);
				SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pNpcList[iNpcH]->m_cMapIndex,
					m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, pItem2->m_sSprite, pItem2->m_sSpriteFrame, pItem2->m_cItemColor);
				_bItemLog(DEF_ITEMLOG_NEWGENDROP, 0, m_pNpcList[iNpcH]->m_cNpcName, pItem2);
			}//4
		}*///3
	}

	delete m_pNpcList[iNpcH];
	m_pNpcList[iNpcH] = NULL;
}

void CGame::RequestFullObjectData(int iClientH, char *pData)
{
 DWORD * dwp;
 WORD  * wp, wObjectID;
 char  * cp, cData[100];
 short * sp, sX, sY;
 int   iTemp, iTemp2;
 int   * ip, iRet;

	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;

	wp = (WORD *)(pData + DEF_INDEX2_MSGTYPE);
	wObjectID = *wp;
	
	ZeroMemory(cData, sizeof(cData));
	dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
	*dwp = MSGID_EVENT_MOTION;
	wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
	*wp  = DEF_OBJECTSTOP;
	
	cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);
    //6
	if (wObjectID < 10000) {
		// ƒ≥∏Ø≈Õ¿« ¡§∫∏∏¶ ø¯«—¥Ÿ. 
		// ¿ﬂ∏¯µ» ¿Œµ¶Ω∫∞™¿Ã∞≈≥™ ¡∏¿Á«œ¡ˆ æ ¥¬ «√∑π¿ÃæÓ∂Û∏È π´Ω√.
		if ( (wObjectID == 0) || (wObjectID >= DEF_MAXCLIENTS) ) return;
		if (m_pClientList[wObjectID] == NULL) return;
		
		wp  = (WORD *)cp;
		*wp = wObjectID;			// ObjectID
		cp += 2;
		//8
		sp  = (short *)cp;
		sX  = m_pClientList[wObjectID]->m_sX;
		*sp = sX;
		cp += 2;
        //10
		sp  = (short *)cp;
		sY  = m_pClientList[wObjectID]->m_sY;
		*sp = sY;
		cp += 2;
		//12
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sType;
		cp += 2;
		//14
		*cp = m_pClientList[wObjectID]->m_cDir;
		cp++;
		//15
		memcpy(cp, m_pClientList[wObjectID]->m_cCharName, 10);
		cp += 10;
		//25
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sAppr1;
		cp += 2;
		//27
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sAppr2;
		cp += 2;
		//29
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sAppr3;
		cp += 2;
		//31
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sAppr4;
		cp += 2;
		//33
		//v1.4 ApprColor
		ip = (int *)cp;
		*ip = m_pClientList[wObjectID]->m_iApprColor;
		cp += 4;
		//37
		ip  = (int *)cp;
		
		// m_pClientList[i]øÕ m_pClientList[sOwnerH]¿« ∞¸∞Ë∏¶ ¿‘∑¬«—¥Ÿ.
		// sStatus¿« ªÛ¿ß 4∫Ò∆Æ∞° FOE ∞¸∞Ë∏¶ ≥™≈∏≥Ω¥Ÿ. 
		iTemp = m_pClientList[wObjectID]->m_iStatus;
		iTemp = 0x0FFFFFFF & iTemp; // ªÛ¿ß 4∫Ò∆Æ ≈¨∏ÆæÓ
		iTemp2 = iGetPlayerABSStatus(wObjectID, iClientH);
		iTemp  = (iTemp | (iTemp2 << 28));
		
		*ip = iTemp;
		cp += 4;
		//41
		
		if (m_pClientList[wObjectID]->m_bIsKilled == TRUE) // v1.4
			 *cp = 1;
		else *cp = 0;
		cp++;
//42
		iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 42); // v1.4  //dimencion
	}
	else {
		// NPC¿« ¡§∫∏∏¶ ø¯«—¥Ÿ.
		// ¿ﬂ∏¯µ» ¿Œµ¶Ω∫ ∞™¿Ã∞≈≥™ ª˝º∫µ«¡ˆ æ ¿∫ NPC∂Û∏È π´Ω√ 
		if ( ((wObjectID - 10000) == 0) || ((wObjectID - 10000) >= DEF_MAXNPCS) ) return;
		if (m_pNpcList[wObjectID - 10000] == NULL) return;
		
		wp  = (WORD *)cp;
		*wp = wObjectID;			
		cp += 2;
        //8
		wObjectID -= 10000;

		sp  = (short *)cp;
		sX  = m_pNpcList[wObjectID]->m_sX;
		*sp = sX;
		cp += 2;
		//10
		sp  = (short *)cp;
		sY  = m_pNpcList[wObjectID]->m_sY;
		*sp = sY;
		cp += 2;
		//12
		sp  = (short *)cp;
		*sp = m_pNpcList[wObjectID]->m_sType;
		cp += 2;
		//14
		*cp = m_pNpcList[wObjectID]->m_cDir;
		cp++;
		//15
		memcpy(cp, m_pNpcList[wObjectID]->m_cName, 5);
		cp += 5;
		//20
		sp  = (short *)cp;
		*sp = m_pNpcList[wObjectID]->m_sAppr2;
		cp += 2;
		//22
		ip  = (int *)cp;
	
		iTemp = m_pNpcList[wObjectID]->m_iStatus;
		iTemp = 0x0FFFFFFF & iTemp; // ªÛ¿ß 4∫Ò∆Æ ≈¨∏ÆæÓ
		
		iTemp2 = iGetNpcRelationship(wObjectID, iClientH);
		iTemp  = (iTemp | (iTemp2 << 28));	
		*ip = iTemp;
		cp += 4;
//26
		if (m_pNpcList[wObjectID]->m_bIsKilled == TRUE) // v1.4
			 *cp = 1;
		else *cp = 0;
		cp++;
//27
		iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 27); // v2.23 // v1.4
	}

	switch (iRet) {
	case DEF_XSOCKEVENT_QUENEFULL:
	case DEF_XSOCKEVENT_SOCKETERROR:
	case DEF_XSOCKEVENT_CRITICALERROR:
	case DEF_XSOCKEVENT_SOCKETCLOSED:
		// ∏ﬁΩ√¡ˆ∏¶ ∫∏≥æ∂ß ø°∑Ø∞° πﬂª˝«ﬂ¥Ÿ∏È ¡¶∞≈«—¥Ÿ.
		DeleteClient(iClientH, TRUE, TRUE);
		return;
	}
}

int CGame::_iGetArrowItemIndex(int iClientH)
{
 register int i;

	if (m_pClientList[iClientH] == NULL) return -1;

	for (i = 0; i < DEF_MAXITEMS; i++)
	if (m_pClientList[iClientH]->m_pItemList[i] != NULL) {

		// Arrow æ∆¿Ã≈€¿Ã 1∞≥ ¿ÃªÛ ¿÷¿∏∏È ¿Œµ¶Ω∫ ∞™¿ª π›»Ø«—¥Ÿ.
		if ( (m_pClientList[iClientH]->m_pItemList[i]->m_cItemType == DEF_ITEMTYPE_ARROW) &&
			 (m_pClientList[iClientH]->m_pItemList[i]->m_dwCount > 0) )
			return i;	
	}

	return -1;
}

void CGame::ItemDepleteHandler(int iClientH, short sItemIndex, BOOL bIsUseItemResult, BOOL bIsLog)
{
	// º“∏º∫ æ∆¿Ã≈€¿« ƒ´øÓ∆Æ∞° 0¿Ã∏È ªË¡¶«—¥Ÿ. »§¿∫ ¡ﬂ∞Ì æ∆¿Ã≈€¿ª ∆»æ∆πˆ∏∞ ∞œøÏ  
 
	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;
	if ((sItemIndex < 0) || (sItemIndex >= DEF_MAXITEMS)) return;
	if (m_pClientList[iClientH]->m_pItemList[sItemIndex] == NULL) return;
	
	// v2.15 ∫“« ø‰«— Deplete ∑Œ±◊∏¶ ≥≤±‚¡ˆ æ ¥¬¥Ÿ.
	if ((bIsLog == TRUE) && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType != DEF_ITEMTYPE_CONSUME) 
		                 && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType != DEF_ITEMTYPE_EAT) 
						 && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType != DEF_ITEMTYPE_USE_DEPLETE) 
						 && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType != DEF_ITEMTYPE_USE_DEPLETE_DEST)
						 && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType != DEF_ITEMTYPE_MATERIAL)
						 && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 380)
						 && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 381)
						 && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 382) // ∏∂π˝ Ω∫≈©∑—¡ˆ¥¬ ∑Œ±◊ø° ≥≤æ∆æﬂ «—¥Ÿ.
						 )
		_bItemLog(DEF_ITEMLOG_DEPLETE, iClientH,(int) -1, m_pClientList[iClientH]->m_pItemList[sItemIndex]);
	// ∏’¿˙ ¿Â¬¯µ«æÓ ¿÷¥Ÿ∏È «ÿ¡¶Ω√≈≤¥Ÿ. ¿Ã∑± ∞ÊøÏ¥¬ ∞≈¿« æ¯¿ª µÌ 
	ReleaseItemHandler(iClientH, sItemIndex, TRUE);
	
	// ¿Ã¡¶ æ∆¿Ã≈€¿ª ∏ÆΩ∫∆Æø°º≠ ªË¡¶«“∞Õ¿ª ≈Î∫∏«—¥Ÿ.
	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ITEMDEPLETED_ERASEITEM, sItemIndex, (int)bIsUseItemResult, NULL, NULL);

	// æ∆¿Ã≈€¿ª ∏ﬁ∏∏Æø°º≠ ªË¡¶ 
	delete m_pClientList[iClientH]->m_pItemList[sItemIndex];
	m_pClientList[iClientH]->m_pItemList[sItemIndex] = NULL;

	m_pClientList[iClientH]->m_bIsItemEquipped[sItemIndex] = FALSE;
	
	// !!! BUG POINT
	// æ∆¿Ã≈€¿« ¿Œµ¶Ω∫∞° πŸ≤Ô ªÛ»≤¿Ã¥Ÿ. ArrowIndexøÕ ∞∞¿∫ ∞Õ¿∫ ¥ŸΩ√ «“¥Á«ÿæﬂ «—¥Ÿ. 
	m_pClientList[iClientH]->m_cArrowIndex = _iGetArrowItemIndex(iClientH);

	// º“¡ˆ«∞ √— ¡ﬂ∑Æ ¿Á ∞ËªÍ 
	iCalcTotalWeight(iClientH);
}

void CGame::NpcBehavior_Stop(int iNpcH)
{
 char  cTargetType;
 short sTarget = NULL;
 BOOL  bFlag;
	if (m_pNpcList[iNpcH] == NULL) return; 
	m_pNpcList[iNpcH]->m_sBehaviorTurnCount++;
	switch (m_pNpcList[iNpcH]->m_cActionLimit) {
	case 5:
		
		switch (m_pNpcList[iNpcH]->m_sType) {
		case 38:
			if (m_pNpcList[iNpcH]->m_sBehaviorTurnCount >= 3) {
				m_pNpcList[iNpcH]->m_sBehaviorTurnCount = 0;
				bFlag = _bNpcBehavior_ManaCollector(iNpcH);

				if (bFlag == TRUE) {
					SendEventToNearClient_TypeA(iNpcH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTATTACK, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, 1); 
				}
			}
			break;

		case 39: // Detector
			if (m_pNpcList[iNpcH]->m_sBehaviorTurnCount >= 3) {
				m_pNpcList[iNpcH]->m_sBehaviorTurnCount = 0;
				bFlag = _bNpcBehavior_Detector(iNpcH);
				
				if (bFlag == TRUE) {
					// ¿˚¿ª πﬂ∞ﬂ«ﬂ¥Ÿ. ∞¯∞› µø¿€¿∏∑Œ æÀ∑¡æﬂ «—¥Ÿ.	
					SendEventToNearClient_TypeA(iNpcH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTATTACK, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, 1); 
				}
			}
			break;

		case 40: // Energy Shield Generator
			break;

		case 41: // Grand Magic Generator
			if (m_pNpcList[iNpcH]->m_sBehaviorTurnCount >= 3) {
				m_pNpcList[iNpcH]->m_sBehaviorTurnCount = 0;
				_NpcBehavior_GrandMagicGenerator(iNpcH);
			}
			break;

		case 42:
		case 96:
		case 98:
		case 94:
			m_pNpcList[iNpcH]->m_sBehaviorTurnCount = 0;
			m_pNpcList[iNpcH]->m_iV1 += 5;
			if (m_pNpcList[iNpcH]->m_iV1 >= 5) m_pNpcList[iNpcH]->m_iV1 = 5;
			break;

		case 89: // AGC (Ancient Grand Cannon)	will turn as detectors	
			if (   (m_bIsHeldenianMode == TRUE) 
				&& (m_cHeldenianModeType == 1))
			{	if (m_pNpcList[iNpcH]->m_sBehaviorTurnCount >= 3) 
				{	m_pNpcList[iNpcH]->m_sBehaviorTurnCount = 0;
					bFlag = _bNpcBehavior_Detector(iNpcH);				
					if (bFlag == TRUE) 
					{	SendEventToNearClient_TypeA(iNpcH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTATTACK, m_pNpcList[iNpcH]->m_sX, m_pNpcList[iNpcH]->m_sY, 1); 
			}	}	}
			break;
		default: 
			TargetSearch(iNpcH, &sTarget, &cTargetType);				
			break;
		}
		break;
	}
	
	if ((sTarget != NULL)) {

		// ∞¯∞›∏Ò«• πﬂ∞ﬂ. 
		m_pNpcList[iNpcH]->m_cBehavior          = DEF_BEHAVIOR_ATTACK;
		m_pNpcList[iNpcH]->m_sBehaviorTurnCount = 0;		
		m_pNpcList[iNpcH]->m_iTargetIndex = sTarget;
		m_pNpcList[iNpcH]->m_cTargetType  = cTargetType;
		// ø©±‚º≠ «•»ø µø¿€∞∞¿∫∞Õ¿ª ¿ß«— ∏ﬁΩ√¡ˆ πﬂº€. 
		return;
	}
}

void CGame::UseItemHandler(int iClientH, short sItemIndex, short dX, short dY, short sDestItemID)
{
 int iTemp, iMax, iV1, iV2, iV3, iSEV1, iEffectResult, i = 0;
 DWORD dwTime;
 short sTemp, sTmpType, sTmpAppr1;
 char cSlateType[20], cTxt[512];
 SYSTEMTIME SysTime;
 GetLocalTime(&SysTime);
	dwTime = timeGetTime();
	ZeroMemory(cSlateType,sizeof(cSlateType));
	ZeroMemory(cTxt,sizeof(cTxt));
	

	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsKilled == TRUE) return;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;

	if ((sItemIndex < 0) || (sItemIndex >= DEF_MAXITEMS)) return;
	if (m_pClientList[iClientH]->m_pItemList[sItemIndex] == NULL) return;

	if ( (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_USE_DEPLETE) ||
		 (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_USE_PERM) ||
		 (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_ARROW) || 
		 (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_EAT) ||
		 (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_USE_SKILL) ||
		 (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_USE_DEPLETE_DEST) ) {
	}
	else return;
 	
	if ( (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_USE_DEPLETE) ||
		 (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_EAT) ) {
				
		// æ∆¿Ã≈€¿« »ø∞˙ø° ∏¬¥¬ √≥∏Æ∏¶ «—¥Ÿ. 
		switch (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectType) {
		case DEF_ITEMEFFECTTYPE_WARM: // v2.172 2002-7-5 «ÿµø Ω√æ‡. 

			// ≥√µø ªÛ≈¬¿Œ ∞ÊøÏ «ÿµø µ«æ˙¥Ÿ¥¬ ∏ﬁºº¡ˆ∏¶ ∫∏≥ª¡ÿ¥Ÿ. 
			if (m_pClientList[iClientH]->m_cMagicEffectStatus[ DEF_MAGICTYPE_ICE ] == 1) {
			//	SetIceFlag(iClientH, DEF_OWNERTYPE_PLAYER, FALSE);

				bRemoveFromDelayEventList(iClientH, DEF_OWNERTYPE_PLAYER, DEF_MAGICTYPE_ICE);

				// »ø∞˙∞° «ÿ¡¶µ… ∂ß πﬂª˝«“ µÙ∑π¿Ã ¿Ã∫•∆Æ∏¶ µÓ∑œ«—¥Ÿ.
				bRegisterDelayEvent(DEF_DELAYEVENTTYPE_MAGICRELEASE, DEF_MAGICTYPE_ICE, dwTime + (1*1000), 
							                iClientH, DEF_OWNERTYPE_PLAYER, NULL, NULL, NULL, 1, NULL, NULL);

								
//				SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_MAGICEFFECTOFF, DEF_MAGICTYPE_ICE, NULL, NULL, NULL);
			}

			m_pClientList[iClientH]->m_dwWarmEffectTime = dwTime;
			break;
		
		case DEF_ITEMEFFECTTYPE_LOTTERY:
			// ∫π±« æ∆¿Ã≈€ EV1(»Æ∑¸: √÷¿˙ 100) EV2(ªÛ«∞ ¡æ∑˘) EV3(ªÛ«∞ ºˆ∑Æ)
			iTemp = iDice(1, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1);
			if (iTemp == iDice(1, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1)) {
				// ¥Á√∑!

			}
			else {
				// ≤Œ!
				
			}
			break;
			
		case DEF_ITEMEFFECTTYPE_SLATES:
			if (m_pClientList[iClientH]->m_pItemList[sItemIndex] != NULL) {
				// Full Ancient Slate ??
				if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum == 867) {
					// Slates dont work on Heldenian Map
						if ((m_bIsHeldenianMode == TRUE) && (m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_bIsHeldenianMap == TRUE)) {
					    ItemDepleteHandler(iClientH, sItemIndex, TRUE, FALSE);
						return;
						}
					switch (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2){
						case 2: // Bezerk slate
							m_pClientList[iClientH]->m_cMagicEffectStatus[ DEF_MAGICTYPE_BERSERK ] = TRUE;
							SetBerserkFlag(iClientH, DEF_OWNERTYPE_PLAYER, TRUE);
							bRegisterDelayEvent(DEF_DELAYEVENTTYPE_MAGICRELEASE, DEF_MAGICTYPE_BERSERK, dwTime + (1000 * 600),
								iClientH, DEF_OWNERTYPE_PLAYER, NULL, NULL, NULL, 1, NULL, NULL);
							SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_MAGICEFFECTON, DEF_MAGICTYPE_BERSERK, 1, NULL, NULL);
							strcpy(cSlateType, "Berserk");
							break;

						case 1: // Invincible slate
							if (strlen(cSlateType) == 0) {
								strcpy(cSlateType, "Invincible");
							}
						case 3: // Mana slate
							if (strlen(cSlateType) == 0) {
								strcpy(cSlateType, "Mana");
							}
						case 4: // Exp slate
							if (strlen(cSlateType) == 0) {
								strcpy(cSlateType, "Exp");
							}
							SetSlateFlag(iClientH, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2, TRUE);
							bRegisterDelayEvent(DEF_DELAYEVENTTYPE_ANCIENT_TABLET, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2, 
												dwTime + (1000 * 600), iClientH, DEF_OWNERTYPE_PLAYER, NULL, NULL, NULL, 1, NULL, NULL);
							switch(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2) {
							case 1:
								iEffectResult = 4;
								break;
							case 3:
								iEffectResult = 5;
								break;
							case 4:
								iEffectResult = 6;
								break;
							}
					}
				}
			}
			break;
		
		case DEF_ITEMEFFECTTYPE_HP:
			iMax = iGetMaxHP(iClientH);
			if (m_pClientList[iClientH]->m_iHP < iMax) {
				
				if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1 == 0) {
					iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
					iV2 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue2;
					iV3 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue3;
				}
				else {
					iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1;
					iV2 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2;
					if ((m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 908)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 909)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 910)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 911))
						iV3 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue3; //corregir para angel
					else
						iV3 = 0;
				}

				m_pClientList[iClientH]->m_iHP += (iDice(iV1, iV2) + iV3); 
				if (m_pClientList[iClientH]->m_iHP > iMax) m_pClientList[iClientH]->m_iHP = iMax;
				if (m_pClientList[iClientH]->m_iHP <= 0)   m_pClientList[iClientH]->m_iHP = 1;

				iEffectResult = 1;
			}
			break;

		case DEF_ITEMEFFECTTYPE_MP:
			iMax = (2*(m_pClientList[iClientH]->m_iMag+m_pClientList[iClientH]->m_iAngelicMag)) + (2*m_pClientList[iClientH]->m_iLevel) + ((m_pClientList[iClientH]->m_iInt+m_pClientList[iClientH]->m_iAngelicInt)/2);
		
			if (m_pClientList[iClientH]->m_iMP < iMax) {
				
				if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1 == 0) {
					iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
					iV2 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue2;
					iV3 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue3;
				}
				else 
				{
					iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1;
					iV2 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2;
					if ((m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 908)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 909)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 910)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 911))
						iV3 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue3; //corregir para angel
					else
						iV3 = 0;
				}

				m_pClientList[iClientH]->m_iMP += (iDice(iV1, iV2) + iV3); 
				if (m_pClientList[iClientH]->m_iMP > iMax) 
					m_pClientList[iClientH]->m_iMP = iMax;

				iEffectResult = 2;
			}
			break;

		case DEF_ITEMEFFECTTYPE_SP:
			iMax = (2*(m_pClientList[iClientH]->m_iStr+m_pClientList[iClientH]->m_iAngelicStr)) + (2*m_pClientList[iClientH]->m_iLevel);
		
			if (m_pClientList[iClientH]->m_iSP < iMax) {
				
				if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1 == 0) {
					iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
					iV2 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue2;
					iV3 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue3;
				}
				else {
					iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1;
					iV2 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2;
					if ((m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 908)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 909)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 910)&&(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum != 911))
						iV3 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue3; //corregir para angel
					else
						iV3 = 0;
				}

				m_pClientList[iClientH]->m_iSP += (iDice(iV1, iV2) + iV3); 
				if (m_pClientList[iClientH]->m_iSP > iMax) 
					m_pClientList[iClientH]->m_iSP = iMax;

				iEffectResult = 3;
			}

			if (m_pClientList[iClientH]->m_bIsPoisoned == TRUE) {
				// ¡ﬂµ∂µ» ªÛ≈¬ø¥¥Ÿ∏È ¡ﬂµ∂¿ª «¨¥Ÿ.
				m_pClientList[iClientH]->m_bIsPoisoned = FALSE;
				// ¡ﬂµ∂¿Ã «Æ∑»¿Ω¿ª æÀ∏∞¥Ÿ. 
				// v2.23
				SetPoisonFlag(iClientH, DEF_OWNERTYPE_PLAYER, FALSE);
				SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_MAGICEFFECTOFF, DEF_MAGICTYPE_POISON, NULL, NULL, NULL);
			}
			break;
	
		case DEF_ITEMEFFECTTYPE_HPSTOCK:
			iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
			iV2 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue2;
			iV3 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue3;
		
			m_pClientList[iClientH]->m_iHPstock += iDice(iV1, iV2) + iV3;
			if (m_pClientList[iClientH]->m_iHPstock < 0)   m_pClientList[iClientH]->m_iHPstock = 0;
			if (m_pClientList[iClientH]->m_iHPstock > 500) m_pClientList[iClientH]->m_iHPstock = 500;

			// πË∞Ì«ƒ¿ª «ÿ∞·«—¥Ÿ. 
			m_pClientList[iClientH]->m_iHungerStatus += iDice(iV1, iV2) + iV3;
			if (m_pClientList[iClientH]->m_iHungerStatus > 100) m_pClientList[iClientH]->m_iHungerStatus = 100;
			if (m_pClientList[iClientH]->m_iHungerStatus < 0)   m_pClientList[iClientH]->m_iHungerStatus = 0;
			break;

		case DEF_ITEMEFFECTTYPE_STUDYSKILL:
			// ±‚º˙¿ª πËøÓ¥Ÿ.	
			iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
			iV2 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue2;
			iSEV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue1;
			// iV1¿∫ πËøÔ Skill π¯»£. iV2¥¬ ±‚º˙ ºˆ¡ÿ, iSEV1¿∫ ªÁøÎ¿⁄ ¡§¿« ±‚º˙ ºˆ¡ÿ(øÏº±º¯¿ß) 
			if (iSEV1 == 0) {
				// ªÁøÎ¿⁄ ¡§¿« ±‚º˙ºˆ¡ÿ¿Ã 0¿Ã∂Û∏È «•¡ÿ ±‚º˙ºˆ¡ÿø° µ˚∂Û ±‚º˙¿ª πËøÏ∞‘ µ»¥Ÿ. 
				TrainSkillResponse(TRUE, iClientH, iV1, iV2);
			}
			else {
		   		TrainSkillResponse(TRUE, iClientH, iV1, iSEV1);
			}
			break;

		case DEF_ITEMEFFECTTYPE_STUDYMAGIC:
			// iV1¿∫ πËøÔ ∏∂π˝ π¯»£.
			iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
			if (m_pMagicConfigList[iV1] != NULL) 
				RequestStudyMagicHandler(iClientH, m_pMagicConfigList[iV1]->m_cName, FALSE);
			break;

		case DEF_ITEMEFFECTTYPE_MAGIC:
			// ≈ı∏Ì ∏µÂø¥¥Ÿ∏È ∏∂π˝ »ø∞˙ æ∆¿Ã≈€ ªÁøÎΩ√ø° «ÿ¡¶µ»¥Ÿ.
			if ( (m_pClientList[iClientH]->m_iStatus & 0x10) != 0 ) {
				SetInvisibilityFlag(iClientH, DEF_OWNERTYPE_PLAYER, FALSE);
			
				bRemoveFromDelayEventList(iClientH, DEF_OWNERTYPE_PLAYER, DEF_MAGICTYPE_INVISIBILITY);
				m_pClientList[ iClientH ]->m_cMagicEffectStatus[ DEF_MAGICTYPE_INVISIBILITY ] = NULL;
			}

			switch (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1) {
			case 1:
				if ((m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_bIsRecallImpossible == TRUE) && (m_pClientList[iClientH]->m_iAdminUserLevel == 0) &&
					(m_pClientList[iClientH]->m_bIsKilled == FALSE) && (m_bIsApocalypseMode == TRUE)  && (m_pClientList[iClientH]->m_iHP > 0)) {
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_NORECALL, NULL, NULL, NULL, NULL);
				}
				else {
					RequestTeleportHandler(iClientH, "1   ");
				}
				break;

			case 2:
				// ≈ı∏Ì ∏∂π˝»ø∞˙∞° ¿÷¥¬ æ∆¿Ã≈€. 
				PlayerMagicHandler(iClientH, m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY, 32, TRUE);
				break;

			case 3:
				// ≈ı∏Ì ∏∂π˝ √£±‚. ªÁ≈ı¿Â ≥ª∫Œ∏È º“øÎæ¯¥Ÿ. 
				if (m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_bIsFightZone == FALSE)
					PlayerMagicHandler(iClientH, m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY, 34, TRUE);
				break;

		
			case 4:
				int z;
				z = 0;
				switch (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue2) {
				case 1:
					// ¬∫√≠¬∏¬Æ¬µ√π ¬æ√Ü√Ä√è¬∑√é ¬∞¬£¬¥√ô 
					if (memcmp(m_pClientList[iClientH]->m_cMapName, "bisle", 5) != 0) {
						//v1.42
						ItemDepleteHandler(iClientH, sItemIndex, TRUE, TRUE);
						RequestTeleportHandler(iClientH, "2   ", "bisle", -1, -1);
					}
					break;

				//NetBox(Big) - ZeroEoyPnk
				case 2:
					if (_iGetItemSpaceLeft(iClientH) == 0) {
						SendItemNotifyMsg(iClientH,	DEF_NOTIFY_CANNOTCARRYMOREITEM, NULL, NULL);
						SendItemNotifyMsg(iClientH,	DEF_NOTIFY_REPAIRBOX, NULL, sItemIndex);						
						return;
					}
					NetBoxLotery(iClientH, 1);
					break;

				//NetBox(Medium) - ZeroEoyPnk
				case 3:
					if (_iGetItemSpaceLeft(iClientH) == 0) {
						SendItemNotifyMsg(iClientH,	DEF_NOTIFY_CANNOTCARRYMOREITEM, NULL, NULL);
						SendItemNotifyMsg(iClientH,	DEF_NOTIFY_REPAIRBOX, NULL, sItemIndex);	
						return;
					}
					NetBoxLotery(iClientH, 2);
					break;

				//NetBox(Small) - ZeroEoyPnk
				case 4:
					if (_iGetItemSpaceLeft(iClientH) == 0) {
						SendItemNotifyMsg(iClientH,	DEF_NOTIFY_CANNOTCARRYMOREITEM, NULL, NULL);
						SendItemNotifyMsg(iClientH,	DEF_NOTIFY_REPAIRBOX, NULL, sItemIndex);	
						return;
					}
					NetBoxLotery(iClientH, 3);
					break;

				case 11:	
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
				case 17:
				case 18:
				case 19:
					// v1.4311-3 ∫Ø∞Ê ¿‘¿Â±« √º≈© ¥ﬁ/≥Ø¬•/Ω√∞£¿∏∑Œ √º≈©«—¥Ÿ. 
					// ¿‘¿Â ∞°¥…«— Ω√∞£∫∏¥Ÿ ¿€∞≈≥™ ∞∞¿∏∏È ¿‘¿Â±«¿Ã ªÁ∂Û¡¯¥Ÿ.
					if ((m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sTouchEffectValue1 != SysTime.wMonth) |
						(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sTouchEffectValue2 != SysTime.wDay) ||
						(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sTouchEffectValue3 <= SysTime.wHour) ) {
						// ≥Ø¬•∞° ¡§»Æ«œ¡ˆ æ ¥Ÿ. æ∆π´∑± »ø∞˙∞° æ¯∞Ì ¿‘¿Â±«¿∫ ªÁ∂Û¡¯¥Ÿ.
					}
					else {
						char cDestMapName[11];
						ZeroMemory(cDestMapName, sizeof(cDestMapName));
						wsprintf(cDestMapName, "fightzone%d", m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue2 - 10);
						if (memcmp(m_pClientList[iClientH]->m_cMapName, cDestMapName, 10) != 0) {
							//v1.42
							ItemDepleteHandler(iClientH, sItemIndex, TRUE);
							// v2.16 2002-6-2 ¿‘¿Â±«µµ ¿˚∏∂¿ªø°º≠ ªÁøÎ ∫“∞°¥…«œ∞‘ «œ±‚¿ß«ÿ
							RequestTeleportHandler(iClientH, "3   ", cDestMapName, -1, -1);
						}
					}
					break;
				}
				break;

			case 5:
				// º“»Ø»ø∞˙∞° ¿÷¥¬ æ∆¿Ã≈€ 
				PlayerMagicHandler(iClientH, m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY, 31, TRUE,
					               m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue2); 	         
				break;
			}
			break;

		case DEF_ITEMEFFECTTYPE_FIRMSTAMINAR:
			m_pClientList[iClientH]->m_iTimeLeft_FirmStaminar += m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
			if (m_pClientList[iClientH]->m_iTimeLeft_FirmStaminar > 20*30) m_pClientList[iClientH]->m_iTimeLeft_FirmStaminar = 20*30; // √÷¥Î 30∫–∞£ 
			break;

		case DEF_ITEMEFFECTTYPE_ADDREPUTATION:
			if ((m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1 == 0) && (m_pClientList[iClientH]->m_iRating < 0))
				m_pClientList[iClientH]->m_iRating = 0;
			else m_pClientList[iClientH]->m_iRating += m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
			SendNotifyMsg(NULL, iClientH, DEF_REPONSE_PLAYERREP, m_pClientList[iClientH]->m_iRating, NULL, NULL, NULL);
			break;

			//code maj ball
			case DEF_ITEMEFFECTTYPE_GIZONPOINT:
			iMax = 9999999; 
			if ((m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1 == 0) && (m_pClientList[iClientH]->m_iGizonItemUpgradeLeft < 0))
				m_pClientList[iClientH]->m_iGizonItemUpgradeLeft = 0;
			else m_pClientList[iClientH]->m_iGizonItemUpgradeLeft += m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
			break;


			//code ek ball
			case DEF_ITEMEFFECTTYPE_ENEMYKILLCOUNT:
			iMax = 9999999; 
			if ((m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1 == 0) && (m_pClientList[iClientH]->m_iEnemyKillCount < 0))
				m_pClientList[iClientH]->m_iEnemyKillCount = 0;
			else m_pClientList[iClientH]->m_iEnemyKillCount += m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ENEMYKILLS, m_pClientList[iClientH]->m_iEnemyKillCount, NULL, NULL, NULL);
			break;

			//code contrib 
		case DEF_ITEMEFFECTTYPE_CONTRIBUTION:  
            iMax = 999999;  
            if (m_pClientList[iClientH]->m_iContribution < iMax)
			{	switch (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1)
				{	case 1:
						m_pClientList[iClientH]->m_iContribution += 700;  //la cantidad que quieras
						break;
					case 2:
						m_pClientList[iClientH]->m_iContribution += 10000;  //la cantidad que quieras
						break;
					case 3:
						m_pClientList[iClientH]->m_iContribution += 20000;  //la cantidad que quieras
						break;
					case 14:
						m_pClientList[iClientH]->m_iContribution += 50000;  //la cantidad que quieras
						break;
					case 15:
						m_pClientList[iClientH]->m_iContribution += 100000;  //la cantidad que quieras
						break;

					default:
						break;
			}	}
			else m_pClientList[iClientH]->m_iContribution += (iMax - m_pClientList[iClientH]->m_iContribution);
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CONTRIBUTION, m_pClientList[iClientH]->m_iContribution, NULL, NULL, NULL);
			break;


		case DEF_ITEMEFFECTTYPE_CONTRIBUTION2:  
            iMax = 999999;
            if (m_pClientList[iClientH]->m_iContribution < iMax)			
				m_pClientList[iClientH]->m_iContribution += iDice(10000, 50000);
			else m_pClientList[iClientH]->m_iContribution += (iMax - m_pClientList[iClientH]->m_iContribution);
            iEffectResult = 8;  
            break;

		case DEF_ITEMEFFECTTYPE_CHANGEATTR:
			switch (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1) {
			case 1:
				m_pClientList[iClientH]->m_cHairColor++;
				if (m_pClientList[iClientH]->m_cHairColor > 15) m_pClientList[iClientH]->m_cHairColor = 0;

				sTemp = (m_pClientList[iClientH]->m_cHairStyle << 8) | (m_pClientList[iClientH]->m_cHairColor << 4) | (m_pClientList[iClientH]->m_cUnderwear);
				m_pClientList[iClientH]->m_sAppr1 = sTemp;
				break;

			case 2:
				m_pClientList[iClientH]->m_cHairStyle++;
				if (m_pClientList[iClientH]->m_cHairStyle > 7) m_pClientList[iClientH]->m_cHairStyle = 0;

				sTemp = (m_pClientList[iClientH]->m_cHairStyle << 8) | (m_pClientList[iClientH]->m_cHairColor << 4) | (m_pClientList[iClientH]->m_cUnderwear);
				m_pClientList[iClientH]->m_sAppr1 = sTemp;
				break;

			case 3:
				m_pClientList[iClientH]->m_cSkin++;
				if (m_pClientList[iClientH]->m_cSkin > 3)
					m_pClientList[iClientH]->m_cSkin = 1;
				
				if (m_pClientList[iClientH]->m_cSex == 1)      sTemp = 1;
				else if (m_pClientList[iClientH]->m_cSex == 2) sTemp = 4; 
				
				switch (m_pClientList[iClientH]->m_cSkin) {
				case 2:	sTemp += 1; break;
				case 3:	sTemp += 2; break;
				}
				m_pClientList[iClientH]->m_sType  = sTemp;
				break;

			case 4:
				sTemp = m_pClientList[iClientH]->m_sAppr3 & 0xFF0F;
				if (sTemp == 0) {
					if (m_pClientList[iClientH]->m_cSex == 1) 
						 m_pClientList[iClientH]->m_cSex = 2;
					else m_pClientList[iClientH]->m_cSex = 1;

					if (m_pClientList[iClientH]->m_cSex == 1) {
						sTmpType = 1;
					}
					else if (m_pClientList[iClientH]->m_cSex == 2) {
						sTmpType = 4; 
					}

					switch (m_pClientList[iClientH]->m_cSkin) {
					case 1:
						break;
					case 2:
						sTmpType += 1;
						break;
					case 3:
						sTmpType += 2;
						break;
					}

					sTmpAppr1 = (m_pClientList[iClientH]->m_cHairStyle << 8) | (m_pClientList[iClientH]->m_cHairColor << 4) | (m_pClientList[iClientH]->m_cUnderwear);
					m_pClientList[iClientH]->m_sType  = sTmpType;
					m_pClientList[iClientH]->m_sAppr1 = sTmpAppr1; 
					//
				}
				break;
			
			case 5:
				m_pClientList[iClientH]->m_cUnderwear++;
				if (m_pClientList[iClientH]->m_cUnderwear > 7) m_pClientList[iClientH]->m_cUnderwear = 0;

				sTemp = (m_pClientList[iClientH]->m_cHairStyle << 8) | (m_pClientList[iClientH]->m_cHairColor << 4) | (m_pClientList[iClientH]->m_cUnderwear);
				m_pClientList[iClientH]->m_sAppr1 = sTemp;
				break;
			}

			SendEventToNearClient_TypeA(iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
			break;
		}
		ItemDepleteHandler(iClientH, sItemIndex, TRUE);
		
		switch (iEffectResult) {
		case 1:
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_HP, NULL, NULL, NULL, NULL);
			break;
		case 2:
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_MP, NULL, NULL, NULL, NULL);
			break;
		case 3:
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SP, NULL, NULL, NULL, NULL);
			break;
		case 4: // Invincible
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SLATE_INVINCIBLE, NULL, NULL, NULL, NULL);
			break;
		case 5: // Mana
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SLATE_MANA, NULL, NULL, NULL, NULL);
			break;
		case 6: // EXP
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SLATE_EXP, NULL, NULL, NULL, NULL);
			break;
		case 8: //conbrib
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_IPACCOUNTINFO, NULL, NULL, NULL, "You have Earned Contrib Points,You Must Relogin");
			break;

		default:
			break;
		}
	}
	else if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_USE_DEPLETE_DEST) {
		// ªÁøÎ«œ∏Èº≠ ∏Ò«•¡ˆ¡°¿ª ¡ˆ¡§«œ¥¬ æ∆¿Ã≈€.
		// dX, dY¿« ¡¬«•∞° ¿Ø»ø π¸¿ß ≥ªø° ¿÷¥¬¡ˆ »Æ¿Œ«ÿæﬂ «—¥Ÿ.
		if (_bDepleteDestTypeItemUseEffect(iClientH, dX, dY, sItemIndex, sDestItemID) == TRUE) 
			ItemDepleteHandler(iClientH, sItemIndex, TRUE); 
	}
	else if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_ARROW) {
		// »≠ªÏ¿ª «“¥Á«—¥Ÿ. 
		m_pClientList[iClientH]->m_cArrowIndex = _iGetArrowItemIndex(iClientH);
	}
	else if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_USE_PERM) {
		// øµ±∏»˜ æµ ºˆ ¿÷¥¬ æ∆¿Ã≈€. ¡Ô æ≤∞Ì≥™µµ æ¯æÓ¡ˆ¡ˆ æ ¥¬ æ∆¿Ã≈€. (ex: ¡ˆµµ) 
		switch (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectType) {
		case DEF_ITEMEFFECTTYPE_SHOWLOCATION:
			iV1 = m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemEffectValue1;
			switch (iV1) {
			case 1:
				// «ˆ¿Á ¿⁄Ω≈¿« ¿ßƒ°∏¶ ∫∏ø©¡ÿ¥Ÿ. 
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "aresden") == 0)
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 1, NULL, NULL);
				else 
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "elvine") == 0)
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 2, NULL, NULL);
				else 
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "middleland") == 0)
					 SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 3, NULL, NULL);
				else
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "default") == 0)
					 SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 4, NULL, NULL);	
				else
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "huntzone2") == 0)
					 SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 5, NULL, NULL);
				else
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "huntzone1") == 0)
					 SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 6, NULL, NULL);
				else
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "huntzone4") == 0)
					 SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 7, NULL, NULL);
				else
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "huntzone3") == 0)
					 SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 8, NULL, NULL);
				else
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "arefarm") == 0)
					 SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 9, NULL, NULL);
				else
				if (strcmp(m_pClientList[iClientH]->m_cMapName, "elvfarm") == 0)
					 SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 10, NULL, NULL);
				else SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SHOWMAP, iV1, 0, NULL, NULL);
				break;
				break;
			}
			break;
		}
	}
	else if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_USE_SKILL) {
		// ±‚º˙∞˙ ∞¸∑√µ» æ∆¿Ã≈€¿ª ªÁøÎ«—¥Ÿ. æ∆¿Ã≈€¿« ºˆ∏Ì¿ª ≥∑√ﬂ∞Ì µÙ∑π¿Ã ¿Ã∫•∆Æø° µÓ∑œ«—¥Ÿ. 
		
		if ( (m_pClientList[iClientH]->m_pItemList[sItemIndex] == NULL) || 
			 (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_wCurLifeSpan <= 0) ||
			 (m_pClientList[iClientH]->m_bSkillUsingStatus[ m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sRelatedSkill ] == TRUE) ) {
			// æ∆¿Ã≈€¿« ºˆ∏Ì¿Ã ¥Ÿ «ﬂ∞≈≥™ æ¯∞≈≥™ ∞¸∑√ Ω∫≈≥¿ª ªÁøÎ¡ﬂ¿Ã∂Û∏È π´Ω√ 
			return;
		}
		else {
			if ( m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_wMaxLifeSpan != 0 ) {
				// √÷¥Î ºˆ∏Ì¿Ã 0¿Ã∏È ªÁøÎ«ÿµµ ºˆ∏Ì¿Ã ¡Ÿ¡ˆ æ ¥¬¥Ÿ.
				m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_wCurLifeSpan--;
				if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_wCurLifeSpan <= 0) {
					// æ∆¿Ã≈€¿« ºˆ∏Ì¿Ã ¥Ÿ µ«æ˙¥Ÿ.
					// æ∆¿Ã≈€¿Ã ∏¡∞°¡≥¥Ÿ¥¬ ∏ﬁΩ√¡ˆ <- ¿Ã∞… πﬁ¿∏∏È ¿Â¬¯»≠∏Èø°º≠ «ÿ¡¶Ω√ƒ—æﬂ «—¥Ÿ.
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ITEMLIFESPANEND, DEF_EQUIPPOS_NONE, sItemIndex, NULL, NULL);
				}
				else {
					// ±‚º˙ ªÁøÎ Ω√∞£ ID∞™¿ª ±∏«—¥Ÿ. v1.12
					int iSkillUsingTimeID = (int)timeGetTime();
					
					bRegisterDelayEvent(DEF_DELAYEVENTTYPE_USEITEM_SKILL, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sRelatedSkill, 
			                     dwTime + m_pSkillConfigList[ m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sRelatedSkill ]->m_sValue2*1000, 
								 iClientH, DEF_OWNERTYPE_PLAYER, m_pClientList[iClientH]->m_cMapIndex, dX, dY, 
								 m_pClientList[iClientH]->m_cSkillMastery[ m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sRelatedSkill ], iSkillUsingTimeID, NULL);
					
					// ±‚º˙ ªÁøÎ¡ﬂ 
					m_pClientList[iClientH]->m_bSkillUsingStatus[ m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sRelatedSkill ] = TRUE;
					m_pClientList[iClientH]->m_iSkillUsingTimeID[ m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sRelatedSkill ] = iSkillUsingTimeID; //v1.12
		 		}
			}
		}
	}
}
void CGame::GoldPorLevel(int iClientH)		    
{
 int iRet, iEraseReq, iWeightLeft;
 DWORD * dwp;
 WORD  * wp;
 char  * cp, cData[100], cItemName[21];
 class CItem * pItem;
 short * sp;

	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;

	iWeightLeft = _iCalcMaxLoad(iClientH) - iCalcTotalWeight(iClientH);
		
	if (iWeightLeft <= 0) return;
	iWeightLeft = iWeightLeft / 2;
	if (iWeightLeft <= 0) return;

	pItem = new class CItem;
	ZeroMemory(cItemName, sizeof(cItemName));
	wsprintf(cItemName, "Gold");
	_bInitItemAttr(pItem, cItemName);
	if ((iWeightLeft / iGetItemWeight(pItem, 1)) >= 300) {
		pItem->m_dwCount = 300;
	}

	if (_bAddClientItemList(iClientH, pItem, &iEraseReq) == TRUE) {
		
		dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
		*dwp = MSGID_NOTIFY;
		wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
		*wp  = DEF_NOTIFY_ITEMOBTAINED;
		
		cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);

		*cp = 1;
		cp++;

		memcpy(cp, pItem->m_cName, 20);
		cp += 20;

		dwp  = (DWORD *)cp;
		*dwp = pItem->m_dwCount;
		cp += 4;

		*cp = pItem->m_cItemType;
		cp++;

		*cp = pItem->m_cEquipPos;
		cp++;

		*cp = (char)0; 
		cp++;

		sp  = (short *)cp;
		*sp = pItem->m_sLevelLimit;
		cp += 2;

		*cp = pItem->m_cGenderLimit;
		cp++;

		wp = (WORD *)cp;
		*wp = pItem->m_wCurLifeSpan;
		cp += 2;

		wp = (WORD *)cp;
		*wp = pItem->m_wWeight;
		cp += 2;

		sp  = (short *)cp;
		*sp = pItem->m_sSprite;
		cp += 2;

		sp  = (short *)cp;
		*sp = pItem->m_sSpriteFrame;
		cp += 2;

		*cp = pItem->m_cItemColor;
		cp++;

		*cp = (char)pItem->m_sItemSpecEffectValue2; // v1.41 
		cp++;
		
		dwp = (DWORD *)cp;
		*dwp = pItem->m_dwAttribute;
		cp += 4;
		
		if (iEraseReq == 1) delete pItem;
		
		iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 53);
						
		switch (iRet) {
		case DEF_XSOCKEVENT_QUENEFULL:
		case DEF_XSOCKEVENT_SOCKETERROR:
		case DEF_XSOCKEVENT_CRITICALERROR:
			PutLogList("DeleteClient77");
			DeleteClient(iClientH, TRUE, TRUE);
			return;
		}

		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ITEMOBTAINED, NULL, NULL, NULL, NULL);
	}
}

void CGame::CheckRushPrice()
{
	SYSTEMTIME SystemTime;

	GetLocalTime(&SystemTime);

	if (RushPrice == FALSE) return;
	
	if (SystemTime.wHour != EndRushPrice_Hour + 1) return;
	if (SystemTime.wMinute != EndRushPrice_Min)  return;	
		RushPrice = FALSE;
}

void CGame::GMUpdateConfigs()
{
	bReadSettingsConfigFile("..\\GameConfigs\\Settings.cfg");
	PutLogList("(!!!) Settings.cfg updated successfully!");
	
	/*bReadAdminListConfigFile("..\\GameConfigs\\AdminList.cfg");
	PutLogList("(!!!) AdminList.cfg updated successfully!");
	
	bReadBannedListConfigFile("..\\GameConfigs\\BannedList.cfg");
	PutLogList("(!!!) BannedList.cfg updated successfully!");
	
	bReadAdminSetConfigFile("..\\GameConfigs\\AdminSettings.cfg");
	PutLogList("(!!!) AdminSettings.cfg updated successfully!");*/
}

BOOL CGame::bReadSettingsConfigFile(char * cFn) 
{ 
   FILE * pFile; 
   HANDLE hFile; 
   DWORD  dwFileSize; 
   char * cp, * token, cReadMode, cTxt[120], cGSMode[16] = ""; 
   char seps[] = "= \t\n"; 
   class CStrTok * pStrTok; 

   cReadMode = 0; 

   hFile = CreateFile(cFn, GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, NULL); 
   dwFileSize = GetFileSize(hFile, NULL); 
   if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile); 

   pFile = fopen(cFn, "rt"); 
   if (pFile == NULL) { 
      // ¬∞√î√Ä√ì¬º¬≠¬π√∂√Ä√á √É√ä¬±√¢√à¬≠ √Ü√Ñ√Ä√è√Ä¬ª √Ä√ê√Ä¬ª ¬º√∂ ¬æ√∏¬¥√ô. 
      //   PutLogList("(!) Cannot open configuration file."); 
      return FALSE; 
   } 
   else { 
      PutLogList("(!) Reading settings file..."); 
      cp = new char[dwFileSize+2]; 
      ZeroMemory(cp, dwFileSize+2); 
      fread(cp, dwFileSize, 1, pFile); 

      pStrTok = new class CStrTok(cp, seps); 
      token = pStrTok->pGet(); 
      //token = strtok( cp, seps );    
      while( token != NULL )   { 

         if (cReadMode != 0) { 
            switch (cReadMode) { 

            case 1: 
               if ((strlen(token) != 0) && (strlen(token) <= 10000) && (strlen(token) >= 1)) 
               { 
                  m_iPrimaryDropRate = atoi(token); 
               } 
               else 
               { 
                  wsprintf(cTxt, "(!!!) Primary drop rate(%s) invalid must be between 1 to 10000", token); 
                  PutLogList(cTxt); 
               } 
               wsprintf(cTxt, "(*) Primary drop rate: (%d)", m_iPrimaryDropRate); 
               PutLogList(cTxt); 
               cReadMode = 0; 
               break; 

            case 2: 
               if ((strlen(token) != 0) && (strlen(token) <= 10000) && (strlen(token) >= 1)) 
               { 
                  m_iSecondaryDropRate = atoi(token); 
               } 
               else 
               { 
                  wsprintf(cTxt, "(!!!) Secondary drop rate(%s) invalid must be between 1 to 10000", token); 
                  PutLogList(cTxt); 
               } 
               wsprintf(cTxt, "(*) Secondary drop rate: (%d)", m_iSecondaryDropRate); 
               PutLogList(cTxt); 
               cReadMode = 0; 
               break; 

			case 3: 
               if ((strlen(token) != 0) && (strlen(token) <= 11000) && (strlen(token) >= 1)) 
               { 
                  m_iGoldProbability = atoi(token); 
               } 
               else 
               { 
                  wsprintf(cTxt, "(!!!) Gold drop rate(%s) invalid must be between 1 to 11000", token); 
                  PutLogList(cTxt); 
               } 
               wsprintf(cTxt, "(*) Gold drop rate: (%d)", m_iGoldProbability); 
               PutLogList(cTxt); 
               cReadMode = 0; 
               break; 

			case 4:
			   if ((strlen(token) != 0) && (strlen(token) <= 11000) && (strlen(token) >= 1)) 
               { 
                  m_iGoldProbMin = atoi(token); 
               } 
               else 
               { 
                  wsprintf(cTxt, "(!!!) Gold prob min rate (%s) invalid must be between 1 to 11000", token); 
                  PutLogList(cTxt); 
               } 
               wsprintf(cTxt, "(*) Gold prob min rate: (%d)", m_iGoldProbMin); 
               PutLogList(cTxt); 
               cReadMode = 0; 
               break; 

			case 5:
			   if ((strlen(token) != 0) && (strlen(token) <= 11000) && (strlen(token) >= 1)) 
               { 
                  m_iGoldProbMax = atoi(token); 
               } 
               else 
               { 
                  wsprintf(cTxt, "(!!!) Gold prob max rate (%s) invalid must be between 1 to 11000", token); 
                  PutLogList(cTxt); 
               } 
               wsprintf(cTxt, "(*) Gold prob max rate: (%d)", m_iGoldProbMax); 
               PutLogList(cTxt); 
               cReadMode = 0; 
               break; 

            case 6: 
               if ((strlen(token) != 0) && (strlen(token) <= 100) && (strlen(token) >= 1)) 
               { 
                  m_iEnemyKillAdjust = atoi(token); 
               } 
               else 
               { 
                  wsprintf(cTxt, "(!!!) ENEMY-KILL-ADJUST: (%s) invalid must be between 1 to 100", token); 
                  PutLogList(cTxt); 
               } 
               wsprintf(cTxt, "(*) Player gains (%d) EK per enemy kill.", m_iEnemyKillAdjust); 
               PutLogList(cTxt); 
               cReadMode = 0; 
               break; 

			case 7:
				if ((memcmp(token, "player", 6) == 0) || (memcmp(token, "PLAYER", 6) == 0))
				{
					m_bLogChatOption = 1;
					wsprintf(cTxt, "(*) Logging Player Chat.");
					PutLogList(cTxt);
				}
				if ((memcmp(token, "gm", 2) == 0) || (memcmp(token, "GM", 2) == 0))
				{
					m_bLogChatOption = 2;
					wsprintf(cTxt, "(*) Logging GM Chat.");
					PutLogList(cTxt);
				}
				if ((memcmp(token, "all", 3) == 0) || (memcmp(token, "ALL", 3) == 0))
				{
					m_bLogChatOption = 3;
					wsprintf(cTxt, "(*) Logging All Chat.");
					PutLogList(cTxt);
				}
				if ((memcmp(token, "none", 4) == 0) || (memcmp(token, "NONE", 4) == 0))
				{
					m_bLogChatOption = 4;
					wsprintf(cTxt, "(*) Not Logging Any Chat.");
					PutLogList(cTxt);
				}
				cReadMode = 0;
				break;

            case 8: 
               m_sSlateSuccessRate = atoi(token); 
               wsprintf(cTxt, "(*) Slate Success Rate (%d) percent", m_sSlateSuccessRate); 
               PutLogList(cTxt); 
			   if (m_sSlateSuccessRate == 0) m_sSlateSuccessRate = 14; 
               cReadMode = 0; 
               break;

			case 9: 
               m_sCharStatLimit = atoi(token); 
               if (m_sCharStatLimit == 0) m_sCharStatLimit = 200; 
               cReadMode = 0;
               break;

			case 10: 
               m_sCharSkillLimit = atoi(token); 
               if (m_sCharSkillLimit == 0) m_sCharSkillLimit = 700; 
               cReadMode = 0;
               break;

			case 11: 
               m_cRepDropModifier = atoi(token); 
               wsprintf(cTxt, "(*) Rep<->Drop modifier: (%d)", m_cRepDropModifier); 
               PutLogList(cTxt); 
               if (m_cRepDropModifier < 0) m_cRepDropModifier = 0;
               cReadMode = 0; 
               break;

			case 12: 
               m_iPlayerMaxLevel = atoi(token); 
               if (m_iPlayerMaxLevel == 0) m_iPlayerMaxLevel = 180; 
               cReadMode = 0;
               break;

			case 13: 
               m_sMedidorExp79 = atoi(token); 
               if (m_sMedidorExp79 == 0) m_sMedidorExp79 = 1; 
               cReadMode = 0;
               break;

			case 14: 
               m_sMedidorExp139 = atoi(token); 
               if (m_sMedidorExp139 == 0) m_sMedidorExp139 = 1; 
               cReadMode = 0;
               break;

			case 15: 
               m_sMedidorExp159 = atoi(token); 
               if (m_sMedidorExp159 == 0) m_sMedidorExp159 = 1; 
               cReadMode = 0;
               break;

			case 16: 
               m_sMedidorExp179 = atoi(token); 
               if (m_sMedidorExp179 == 0) m_sMedidorExp179 = 1; 
               cReadMode = 0;
               break;

			case 17:
			   m_sMedidorExp249 = atoi(token); 
			   if (m_sMedidorExp249 == 0) m_sMedidorExp249 = 1; 
               cReadMode = 0;
               break;

			case 18:
			   m_sMedidorExp250 = atoi(token); 
			   if (m_sMedidorExp250 == 0) m_sMedidorExp250 = 1; 
               cReadMode = 0;
               break;

			//New Addon - Party EK  Setting.cfg - ZeroEoyPnk
			case 19:
				if ((memcmp(token, "ON", 2) == 0) || (memcmp(token, "on", 2) == 0)) 
				{ 
					m_bPartyEkPerLevel140 = TRUE; 
					
				} 
				else if ((memcmp(token, "OFF", 3) == 0) || (memcmp(token, "off", 3) == 0)) 
				{
                  m_bPartyEkPerLevel140 = FALSE; 
				} 
				else 
				{ 
                  wsprintf(cTxt, "(!!!) Party-Ek-Level-140: (%s) must be either ON or OFF", token); 
                  PutLogList(cTxt); 
                  return FALSE; 
				}
				cReadMode = 0; 
				break; 

			case 20:
				m_iPartyEk140_1 = atoi(token);
				if (m_iPartyEk140_1 == 0) m_iPartyEk140_1 = 0; 
				cReadMode = 0;
				break;

			case 21:
				m_iPartyEk140_2 = atoi(token);
				if (m_iPartyEk140_2 == 0) m_iPartyEk140_2 = 0; 
				cReadMode = 0;
				break;

			case 22:
				m_iPartyEk140_3 = atoi(token);
				if (m_iPartyEk140_3 == 0) m_iPartyEk140_3 = 0; 
				cReadMode = 0;
				break;

			case 23:
				if ((memcmp(token, "ON", 2) == 0) || (memcmp(token, "on", 2) == 0)) 
				{ 
					m_bPartyEkPerLevel180 = TRUE; 
					
				} 
				else if ((memcmp(token, "OFF", 3) == 0) || (memcmp(token, "off", 3) == 0)) 
				{
                  m_bPartyEkPerLevel180 = FALSE; 
				} 
				else 
				{ 
                  wsprintf(cTxt, "(!!!) Party-Ek-Level-180: (%s) must be either ON or OFF", token); 
                  PutLogList(cTxt); 
                  return FALSE; 
				}
				cReadMode = 0; 
				break;

			case 24:
				m_iPartyEk180_1 = atoi(token);
				if (m_iPartyEk180_1 == 0) m_iPartyEk180_1 = 0; 
				cReadMode = 0;
				break;

			case 25:
				m_iPartyEk180_2 = atoi(token);
				if (m_iPartyEk180_2 == 0) m_iPartyEk180_2 = 0; 
				cReadMode = 0;
				break;

			case 26:
				m_iPartyEk180_3 = atoi(token);
				if (m_iPartyEk180_3 == 0) m_iPartyEk180_3 = 0; 
				cReadMode = 0;
				break;
				
			case 27:
				if ((memcmp(token, "ON", 2) == 0) || (memcmp(token, "on", 2) == 0)) 
				{ 
					m_b100skill = TRUE; 
				} 
				else if ((memcmp(token, "OFF", 3) == 0) || (memcmp(token, "off", 3) == 0)) 
				{
					m_b100skill = FALSE; 
				} 
				else 
				{ 
                  wsprintf(cTxt, "(!!!) 100% skill: (%s) must be either ON or OFF", token); 
                  PutLogList(cTxt); 
                  return FALSE; 
				}
				cReadMode = 0; 
				break;
			}
         } 
         else { 
            if (memcmp(token, "primary-drop-rate",				17) == 0)   cReadMode = 1; 
            if (memcmp(token, "secondary-drop-rate",			19) == 0)   cReadMode = 2; 
            if (memcmp(token, "gold-drop-rate",					14) == 0)   cReadMode = 3; 
			if (memcmp(token, "min-gold-drop",					13) == 0)   cReadMode = 4; 
			if (memcmp(token, "max-gold-drop",					13) == 0)   cReadMode = 5; 
            if (memcmp(token, "enemy-kill-adjust",				17) == 0)   cReadMode = 6; 
            if (memcmp(token, "log-chat-settings",				17) == 0)   cReadMode = 7; 
            if (memcmp(token, "slate-success-rate",				18) == 0)   cReadMode = 8; 
            if (memcmp(token, "character-stat-limit",			20) == 0)   cReadMode = 9; 
            if (memcmp(token, "character-skill-limit",			21) == 0)   cReadMode = 10; 
            if (memcmp(token, "rep-drop-modifier",				17) == 0)   cReadMode = 11;
			if (memcmp(token, "max-player-level",				16) == 0)	cReadMode = 12;
			if (memcmp(token, "Multiplicador-Exp-0~79",			22) == 0)	cReadMode = 13;
			if (memcmp(token, "Multiplicador-Exp-80~139",		24) == 0)	cReadMode = 14;
			if (memcmp(token, "Multiplicador-Exp-140~159",		25) == 0)	cReadMode = 15;
			if (memcmp(token, "Multiplicador-Exp-160~179",		25) == 0)	cReadMode = 16;
			if (memcmp(token, "Multiplicador-Exp-180~249",		25) == 0)	cReadMode = 17;
			if (memcmp(token, "Multiplicador-Exp-250-or-more",	29) == 0)	cReadMode = 18;
			if (memcmp(token, "Party-Ek-Level-140",				18) == 0)	cReadMode = 19;
			if (memcmp(token, "Party-Ek-Level140-2~4",			21) == 0)	cReadMode = 20;
			if (memcmp(token, "Party-Ek-Level140-5~6",			21) == 0)	cReadMode = 21;
			if (memcmp(token, "Party-Ek-Level140-7~8",			21) == 0)	cReadMode = 22;
			if (memcmp(token, "Party-Ek-Level-180",				18) == 0)	cReadMode = 23;
			if (memcmp(token, "Party-Ek-Level180-2~4",			21) == 0)	cReadMode = 24;
			if (memcmp(token, "Party-Ek-Level180-5~6",			21) == 0)	cReadMode = 25;
			if (memcmp(token, "Party-Ek-Level180-7~8",			21) == 0)	cReadMode = 26;
			if (memcmp(token, "100%-skills",					11) == 0)	cReadMode = 27;
			
         } 

         token = pStrTok->pGet(); 
      } 
      delete pStrTok; 
      delete cp; 
   } 
   if (pFile != NULL) fclose(pFile); 

   return TRUE; 
} 


void CGame::ExchangeItemHandler(int iClientH, short sItemIndex, int iAmount, short dX, short dY, WORD wObjectID, char *pItemName)
{
 short sOwnerH;
 char  cOwnerType;
 
	if (m_pClientList[iClientH] == NULL) return;
	if ((sItemIndex < 0) || (sItemIndex >= DEF_MAXITEMS)) return;
   	if ((m_pClientList[iClientH]->m_iAdminUserLevel > 0) && (m_pClientList[iClientH]->m_iAdminUserLevel < 3)) return;
	if (m_pClientList[iClientH]->m_pItemList[sItemIndex] == NULL) return;
	if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwCount < iAmount) return;
	if (m_pClientList[iClientH]->m_bIsOnServerChange == TRUE) return;
	if (m_pClientList[iClientH]->m_bIsExchangeMode == TRUE) return;
	if (wObjectID >= DEF_MAXCLIENTS) return;

	// æ|??ª ¥©±∏ø?±≥??∞?? ∏?a?µµ¯?¥? ª???∞?æ?Æ∞?? ∏??±≥?‚; ø≠µµ∑??¥? 
	//Lf dX, dYø° V¥ ø:?Tø°∞?º???æ|??ª ∞???? 
	m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->GetOwner(&sOwnerH, &cOwnerType, dX, dY);
	

	if ((sOwnerH != NULL) && (cOwnerType == DEF_OWNERTYPE_PLAYER)) {

		// v1.4 ?∞? ? ∞¥¸ø?∏¥¡?¥???
		if (wObjectID != NULL) { 
			if (wObjectID < 10000) {
				// ?∑πLæ?
				if (m_pClientList[wObjectID] != NULL) {
					if ((WORD)sOwnerH != wObjectID) sOwnerH = NULL;
				}
			}
			else sOwnerH = NULL;
		}
		
		if ((sOwnerH == NULL) || (m_pClientList[sOwnerH] == NULL)) {
			//æ∆¿Ã≈€ ±≥»Ø¿ª ø‰√ª«— «√∑π¿ÃæÓø°∞‘ «ÿ¥Á ¿ßƒ°ø° «√∑π¿ÃæÓ∞° æ¯¿Ω¿ª æÀ∏∞¥Ÿ. 
			_ClearExchangeStatus(iClientH); 
		}
		else {
			if ((m_pClientList[sOwnerH]->m_bIsExchangeMode == TRUE) || (m_pClientList[sOwnerH]->m_sAppr2 & 0xF000) ||
				(m_pMapList[m_pClientList[sOwnerH]->m_cMapIndex]->m_bIsFightZone == TRUE)) {
				// ªÛ¥ÎπÊ¿Ã ¿ÃπÃ ±≥»Ø ¡ﬂ¿Ã∞≈≥™ ¿¸≈ı∏µÂ, »§¿∫ ªÁ≈ı¿Â¿Ã¥Ÿ. ±≥»Ø∏µÂ∑Œ µÈæÓ∞• ºˆ æ¯¥Ÿ. 
				_ClearExchangeStatus(iClientH);
			}
			else {
				// ±≥»Ø∏µÂ∞° Ω√¿€µ«æ˙¥Ÿ. ¿Œµ¶Ω∫, ¿Ã∏ß ¿˙¿Â  
				m_pClientList[iClientH]->m_bIsExchangeMode = TRUE;
				m_pClientList[iClientH]->m_iExchangeH = sOwnerH;
				ZeroMemory(m_pClientList[iClientH]->m_cExchangeName, sizeof(m_pClientList[iClientH]->m_cExchangeName));
				strcpy(m_pClientList[iClientH]->m_cExchangeName, m_pClientList[sOwnerH]->m_cCharName);


				//Clear items in the list
				m_pClientList[iClientH]->iExchangeCount = 0;
				m_pClientList[sOwnerH]->iExchangeCount = 0;
				for(int i=0; i<4 ; i++){
					//Clear the trader
					ZeroMemory(m_pClientList[iClientH]->m_cExchangeItemName[i], sizeof(m_pClientList[iClientH]->m_cExchangeItemName[i]));
					m_pClientList[iClientH]->m_cExchangeItemIndex[i] = -1;
					m_pClientList[iClientH]->m_iExchangeItemAmount[i] = 0;
					//Clear the guy we're trading with
					ZeroMemory(m_pClientList[sOwnerH]->m_cExchangeItemName[i], sizeof(m_pClientList[sOwnerH]->m_cExchangeItemName[i]));
					m_pClientList[sOwnerH]->m_cExchangeItemIndex[i] = -1;
					m_pClientList[sOwnerH]->m_iExchangeItemAmount[i] = 0;
				}

				// ±≥»Ø«œ∞Ì¿⁄ «œ¥¬ æ∆¿Ã≈€ ¿Œµ¶Ω∫, ºˆ∑Æ ¿˙¿Â 
				m_pClientList[iClientH]->m_cExchangeItemIndex[m_pClientList[iClientH]->iExchangeCount]  = (char)sItemIndex;
				m_pClientList[iClientH]->m_iExchangeItemAmount[m_pClientList[iClientH]->iExchangeCount] = iAmount;

				//ZeroMemory(m_pClientList[iClientH]->m_cExchangeItemName, sizeof(m_pClientList[iClientH]->m_cExchangeItemName));
				memcpy(m_pClientList[iClientH]->m_cExchangeItemName[m_pClientList[iClientH]->iExchangeCount], m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cName, 20);
				
				m_pClientList[sOwnerH]->m_bIsExchangeMode  = TRUE;
				m_pClientList[sOwnerH]->m_iExchangeH = iClientH;
				ZeroMemory(m_pClientList[sOwnerH]->m_cExchangeName, sizeof(m_pClientList[sOwnerH]->m_cExchangeName));
				strcpy(m_pClientList[sOwnerH]->m_cExchangeName, m_pClientList[iClientH]->m_cCharName);

				m_pClientList[iClientH]->iExchangeCount++;
				SendNotifyMsg(iClientH, iClientH, DEF_NOTIFY_OPENEXCHANGEWINDOW, sItemIndex+1000, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSprite, 
				              m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSpriteFrame, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cName, iAmount, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemColor,
							  m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_wCurLifeSpan,
							  m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_wMaxLifeSpan,
							  m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2 +100,
							  m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwAttribute, FALSE, (char)m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue3);

				SendNotifyMsg(iClientH, sOwnerH, DEF_NOTIFY_OPENEXCHANGEWINDOW, sItemIndex, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSprite, 
				              m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSpriteFrame, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cName, iAmount, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemColor,
							  m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_wCurLifeSpan,
							  m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_wMaxLifeSpan,
							  m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue2 +100,
							  m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwAttribute, FALSE, (char)m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sItemSpecEffectValue3);
			}
		}
	}
	else {
		// NPCøÕ¥¬ π∞∞«¿ª ±≥»Ø«“ ºˆ æ¯¥Ÿ.
		_ClearExchangeStatus(iClientH);

	}
}

void CGame::SetExchangeItem(int iClientH, int iItemIndex, int iAmount)
{
 int iExH;

	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsOnServerChange == TRUE) return;
	if (m_pClientList[iClientH]->iExchangeCount > 4) return;	//only 4 items trade

	//no admin trade
	   	if (m_pClientList[iClientH]->m_iAdminUserLevel > 0&&m_pClientList[iClientH]->m_iAdminUserLevel < 3) {
		_ClearExchangeStatus(m_pClientList[iClientH]->m_iExchangeH);
		_ClearExchangeStatus(iClientH);
	}


	if ((m_pClientList[iClientH]->m_bIsExchangeMode == TRUE) && (m_pClientList[iClientH]->m_iExchangeH != NULL)) {
		iExH = m_pClientList[iClientH]->m_iExchangeH;
		if ( (m_pClientList[iExH] == NULL) || (memcmp(m_pClientList[iClientH]->m_cExchangeName, m_pClientList[iExH]->m_cCharName, 10) != 0) ) {
			// ±≥?? ª??? æ? ±≥??∞? ?¥??∏Ø?∞° æ??? 	

		}
		else {
			// ±≥??∞? ?¥ ª???∞?æ|??ª æ?Å?? 
			// ?¥?|???xg?¥¡???∏¥¡?u?¥? 
			if ((iItemIndex < 0) || (iItemIndex >= DEF_MAXITEMS)) return;
			if (m_pClientList[iClientH]->m_pItemList[iItemIndex] == NULL) return;
			if (m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_dwCount < iAmount) return;

			//No Duplicate items
			for(int i=0; i<m_pClientList[iClientH]->iExchangeCount;i++){
				if (m_pClientList[iClientH]->m_cExchangeItemIndex[i] == (char)iItemIndex) {
					_ClearExchangeStatus(iExH);
					_ClearExchangeStatus(iClientH);
					return;
				}
			}

			// ±≥??∞? ?¥ æ|??Nµ¶Ω∫, º?ze 
			m_pClientList[iClientH]->m_cExchangeItemIndex[m_pClientList[iClientH]->iExchangeCount]  = (char)iItemIndex;
			m_pClientList[iClientH]->m_iExchangeItemAmount[m_pClientList[iClientH]->iExchangeCount] = iAmount;

			//ZeroMemory(m_pClientList[iClientH]->m_cExchangeItemName, sizeof(m_pClientList[iClientH]->m_cExchangeItemName));
			memcpy(m_pClientList[iClientH]->m_cExchangeItemName[m_pClientList[iClientH]->iExchangeCount], m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_cName, 20);

			//m_pClientList[iClientH]->m_cExchangeItemIndex  = iItemIndex;
			//m_pClientList[iClientH]->m_iExchangeItemAmount = iAmount;
			//ZeroMemory(m_pClientList[iClientH]->m_cExchangeItemName, sizeof(m_pClientList[iClientH]->m_cExchangeItemName));
			//memcpy(m_pClientList[iClientH]->m_cExchangeItemName, m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_cName, 20);
			
			m_pClientList[iClientH]->iExchangeCount++;
			SendNotifyMsg(iClientH, iClientH, DEF_NOTIFY_SETEXCHANGEITEM, iItemIndex+1000, m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sSprite,
				          m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sSpriteFrame, m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_cName, iAmount, m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_cItemColor,
						  m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_wCurLifeSpan,
						  m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_wMaxLifeSpan,
						  m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sItemSpecEffectValue2 +100,
						  m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_dwAttribute, FALSE, (char)m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sItemSpecEffectValue3); 

			SendNotifyMsg(iClientH, iExH, DEF_NOTIFY_SETEXCHANGEITEM, iItemIndex, m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sSprite,
				          m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sSpriteFrame, m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_cName, iAmount, m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_cItemColor,
						  m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_wCurLifeSpan,
						  m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_wMaxLifeSpan,
						  m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sItemSpecEffectValue2 +100,
						  m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_dwAttribute, FALSE, (char)m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sItemSpecEffectValue3);
		}
	}
	else {
		// ±≥? ∏??° æ????
	}
}

void CGame::ConfirmExchangeItem(int iClientH)
{
 int iExH,i;
 int iItemWeightA, iItemWeightB, iWeightLeftA, iWeightLeftB, iAmountLeft;
 class CItem * pItemA[4], * pItemB[4], * pItemAcopy[4], * pItemBcopy[4];
 
	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsOnServerChange == TRUE) return;
   	if (m_pClientList[iClientH]->m_iAdminUserLevel > 0&&m_pClientList[iClientH]->m_iAdminUserLevel < 3) return;
		

	if ((m_pClientList[iClientH]->m_bIsExchangeMode == TRUE) && (m_pClientList[iClientH]->m_iExchangeH != NULL)) {
		iExH = m_pClientList[iClientH]->m_iExchangeH;
	
		// v1.42 º≥∏∂ L∑± ∞?∞°?
		if (iClientH == iExH) return;

		if (m_pClientList[iExH] != NULL) {
			if ( (memcmp(m_pClientList[iClientH]->m_cExchangeName, m_pClientList[iExH]->m_cCharName, 10) != 0) ||
			     (m_pClientList[iExH]->m_bIsExchangeMode != TRUE) ||
				 (memcmp(m_pClientList[iExH]->m_cExchangeName, m_pClientList[iClientH]->m_cCharName, 10) != 0) ) {
				// ±≥??∞? ?¥??∏Ø?∞° æ??? ±≥? ª?? iº?
				_ClearExchangeStatus(iClientH);
				_ClearExchangeStatus(iExH);
				return;
			}
			else {
				m_pClientList[iClientH]->m_bIsExchangeConfirm = TRUE;
				if (m_pClientList[iExH]->m_bIsExchangeConfirm == TRUE) {
					// ª??? ±≥?Gª? π?¥? ±≥?L º∫∏≥? º?¥¡?ª?¥? æ|??∞πº?´∞?f?; ?¥?
					
					//Check all items
					for(i=0; i<m_pClientList[iClientH]->iExchangeCount; i++){
						if ((m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]] == NULL) ||
							(memcmp(m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_cName, m_pClientList[iClientH]->m_cExchangeItemName[i], 20) != 0)) {
							_ClearExchangeStatus(iClientH);
							_ClearExchangeStatus(iExH);
							return;
						}
					}
					for(i=0; i<m_pClientList[iExH]->iExchangeCount; i++){
						if ((m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]] == NULL) ||
							(memcmp(m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_cName, m_pClientList[iExH]->m_cExchangeItemName[i], 20) != 0)) {
								_ClearExchangeStatus(iClientH);
								_ClearExchangeStatus(iExH);
								return;
							}
					}

					iWeightLeftA = _iCalcMaxLoad(iClientH) - iCalcTotalWeight(iClientH);
					iWeightLeftB = _iCalcMaxLoad(iExH) - iCalcTotalWeight(iExH);

					//Calculate weight for items
					iItemWeightA = 0;
					for(i=0; i<m_pClientList[iClientH]->iExchangeCount; i++){
						iItemWeightA = iGetItemWeight(m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]],
							m_pClientList[iClientH]->m_iExchangeItemAmount[i]);
					}
					iItemWeightB = 0;
					for(i=0; i<m_pClientList[iExH]->iExchangeCount; i++){
						iItemWeightB = iGetItemWeight(m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]],
							m_pClientList[iExH]->m_iExchangeItemAmount[i]);
					}

					//See if the other person can take the item weightload
					if ((iWeightLeftA < iItemWeightB) || (iWeightLeftB < iItemWeightA)) {
						// ±≥??∞? ?¥ æ|??ª π?ª π´∞?? æ?±≥? ∫?°¥? 
						_ClearExchangeStatus(iClientH);
						_ClearExchangeStatus(iExH);
						return;
					}

					for(i=0; i<m_pClientList[iClientH]->iExchangeCount; i++){
						// º??ß∞° V¥ æ|??ä∞?¥ ª?ª?ΩA??≥™¥≠º?¥?
						if ( (m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_cItemType == DEF_ITEMTYPE_CONSUME) ||
							(m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_cItemType == DEF_ITEMTYPE_ARROW) ) {

								if (m_pClientList[iClientH]->m_iExchangeItemAmount[i] > m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_dwCount) {
									// ±≥??∞? ?¥?Æ∫∏¥?æ|???{¥? ±?øæO?æ?æ?
									_ClearExchangeStatus(iClientH);
									_ClearExchangeStatus(iExH);
									return;		
								}
								pItemA[i] = new class CItem;
								_bInitItemAttr(pItemA[i], m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_cName);
								pItemA[i]->m_dwCount = m_pClientList[iClientH]->m_iExchangeItemAmount[i];

								// ∑a?¶ ≥≤±? '? æ|??∫πª? 
								pItemAcopy[i] = new class CItem;
								_bInitItemAttr(pItemAcopy[i], m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_cName);
								bCopyItemContents(pItemAcopy[i], pItemA[i]);
								pItemAcopy[i]->m_dwCount = m_pClientList[iClientH]->m_iExchangeItemAmount[i];
							}
						else {
							pItemA[i] = (class CItem *)m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]];
							pItemA[i]->m_dwCount = m_pClientList[iClientH]->m_iExchangeItemAmount[i];

							// ∑a?¶ ≥≤±? '? æ|??∫πª? 
							pItemAcopy[i] = new class CItem;
							_bInitItemAttr(pItemAcopy[i], m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_cName);
							bCopyItemContents(pItemAcopy[i], pItemA[i]);
							pItemAcopy[i]->m_dwCount = m_pClientList[iClientH]->m_iExchangeItemAmount[i];
						}
					}

					for(i=0; i<m_pClientList[iExH]->iExchangeCount; i++){
						if ( (m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_cItemType == DEF_ITEMTYPE_CONSUME) ||
							(m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_cItemType == DEF_ITEMTYPE_ARROW) ) {

								if (m_pClientList[iExH]->m_iExchangeItemAmount[i] > m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_dwCount) {
									// ±≥??∞? ?¥?Æ∫∏¥?æ|???{¥? ±?øæO?æ?æ?
									_ClearExchangeStatus(iClientH);
									_ClearExchangeStatus(iExH);
									return;		
								}
								pItemB[i] = new class CItem;
								_bInitItemAttr(pItemB[i], m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_cName);
								pItemB[i]->m_dwCount = m_pClientList[iExH]->m_iExchangeItemAmount[i];

								// ∑a?¶ ≥≤±? '? æ|??∫πª? 
								pItemBcopy[i] = new class CItem;
								_bInitItemAttr(pItemBcopy[i], m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_cName);
								bCopyItemContents(pItemBcopy[i], pItemB[i]);
								pItemBcopy[i]->m_dwCount = m_pClientList[iExH]->m_iExchangeItemAmount[i];
							}
						else {
							pItemB[i] = (class CItem *)m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]];
							pItemB[i]->m_dwCount = m_pClientList[iExH]->m_iExchangeItemAmount[i];

							// ∑a?¶ ≥≤±? '? æ|??∫πª? 
							pItemBcopy[i] = new class CItem;
							_bInitItemAttr(pItemBcopy[i], m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_cName);
							bCopyItemContents(pItemBcopy[i], pItemB[i]);
							pItemBcopy[i]->m_dwCount = m_pClientList[iExH]->m_iExchangeItemAmount[i];
						}
					}

					// ∏????ª ≥?∫ ? 
					for(i=0; i<m_pClientList[iExH]->iExchangeCount; i++){
						bAddItem(iClientH, pItemB[i], NULL);
						_bItemLog(DEF_ITEMLOG_EXCHANGE, iExH, iClientH, pItemBcopy[i]);
						delete pItemBcopy[i];
						pItemBcopy[i] = NULL;
						if ( (m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_cItemType == DEF_ITEMTYPE_CONSUME) ||
							(m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_cItemType == DEF_ITEMTYPE_ARROW) ) {
								//
								iAmountLeft = (int)m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]]->m_dwCount - m_pClientList[iExH]->m_iExchangeItemAmount[i];
								if (iAmountLeft < 0) iAmountLeft = 0;	  
								// v1.41 !!!
								SetItemCount(iExH, m_pClientList[iExH]->m_cExchangeItemIndex[i], iAmountLeft);
								// m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex]->m_cName, iAmountLeft);
								//
							}
						else {
							// ∏∏æ??µOæ|??????f?¥?
							ReleaseItemHandler(iExH, m_pClientList[iExH]->m_cExchangeItemIndex[i], TRUE);
							SendNotifyMsg(NULL, iExH, DEF_NOTIFY_GIVEITEMFIN_ERASEITEM, m_pClientList[iExH]->m_cExchangeItemIndex[i], m_pClientList[iExH]->m_iExchangeItemAmount[i], NULL, m_pClientList[iClientH]->m_cCharName);
							m_pClientList[iExH]->m_pItemList[m_pClientList[iExH]->m_cExchangeItemIndex[i]] = NULL;
						}
					}

					for(i=0; i<m_pClientList[iClientH]->iExchangeCount; i++){
						bAddItem(iExH, pItemA[i], NULL);
						_bItemLog(DEF_ITEMLOG_EXCHANGE, iClientH, iExH, pItemAcopy[i]);
						delete pItemAcopy[i];
						pItemAcopy[i] = NULL;

						if ( (m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_cItemType == DEF_ITEMTYPE_CONSUME) ||
							(m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_cItemType == DEF_ITEMTYPE_ARROW) ) {
								//
								iAmountLeft = (int)m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]]->m_dwCount - m_pClientList[iClientH]->m_iExchangeItemAmount[i];
								if (iAmountLeft < 0) iAmountLeft = 0;	 
								// v1.41 !!!
								SetItemCount(iClientH, m_pClientList[iClientH]->m_cExchangeItemIndex[i], iAmountLeft);
								// m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex]->m_cName, iAmountLeft);
								//
							}
						else {
							// ∏∏æ??µOæ|??????f?¥?
							ReleaseItemHandler(iClientH, m_pClientList[iClientH]->m_cExchangeItemIndex[i], TRUE);
							SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIVEITEMFIN_ERASEITEM, m_pClientList[iClientH]->m_cExchangeItemIndex[i], m_pClientList[iClientH]->m_iExchangeItemAmount[i], NULL, m_pClientList[iExH]->m_cCharName);
							m_pClientList[iClientH]->m_pItemList[m_pClientList[iClientH]->m_cExchangeItemIndex[i]] = NULL;
						}
					}

					m_pClientList[iClientH]->m_bIsExchangeMode = FALSE;
					m_pClientList[iClientH]->m_bIsExchangeConfirm = FALSE;
					ZeroMemory(m_pClientList[iClientH]->m_cExchangeName, sizeof(m_pClientList[iClientH]->m_cExchangeName));
					m_pClientList[iClientH]->m_iExchangeH = NULL;
					m_pClientList[iClientH]->iExchangeCount = 0;

					m_pClientList[iExH]->m_bIsExchangeMode = FALSE;
					m_pClientList[iExH]->m_bIsExchangeConfirm = FALSE;
					ZeroMemory(m_pClientList[iExH]->m_cExchangeName, sizeof(m_pClientList[iExH]->m_cExchangeName));
					m_pClientList[iExH]->m_iExchangeH = NULL;
					m_pClientList[iExH]->iExchangeCount = 0;

					for(i=0;i<4;i++){
						m_pClientList[iClientH]->m_cExchangeItemIndex[i] = -1;
						m_pClientList[iExH]->m_cExchangeItemIndex[i] = -1;
					}

					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_EXCHANGEITEMCOMPLETE, NULL, NULL, NULL, NULL);
					SendNotifyMsg(NULL, iExH,     DEF_NOTIFY_EXCHANGEITEMCOMPLETE, NULL, NULL, NULL, NULL);

					// π´∞?gº≥d
					iCalcTotalWeight(iClientH);
					iCalcTotalWeight(iExH);
					return;
				}
			}
		}
		else {
			// ±≥?? ª??? æ?±≥?: iº?µ??
			_ClearExchangeStatus(iClientH);
			return;
		}
	}
}
void CGame::AdminOrder_SetMAJ (int iClientH, char *pData, DWORD dwMsgSize)
{
	char seps[] = "= \t\n";
	char *token, cBuff[256];
	class CStrTok *pStrTok;
	char *pk;
	char cNick[21];
	char cPK[6];
	char notice[100];
	int oldpk;
	int i;

	if (m_pClientList[iClientH] == NULL) return;
	if ((dwMsgSize) <= 0) return;

	if (m_pClientList[iClientH]->m_iAdminUserLevel < 2) {
		SendNotifyMsg (NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
		return; 
	}
	
	ZeroMemory (cBuff, sizeof (cBuff));
	ZeroMemory(cNick,sizeof(cNick));
	ZeroMemory(cPK, sizeof(cPK));
	memcpy (cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok (cBuff, seps);
	token = pStrTok->pGet ();
	token = pStrTok->pGet ();
	
	if (token == NULL)	{
		delete pStrTok;
		return;
	}

	memcpy (cNick, token,20);
	pk = pStrTok->pGet ();
	if (pk == NULL){
		delete pStrTok;
		return;
	}
	
	memcpy (cPK, pk,5);
	for (i = 0; i < DEF_MAXCLIENTS; i++){
		if ((m_pClientList[i] != NULL) && (memcmp (m_pClientList[i]->m_cCharName, cNick, strlen (cNick)) == 0)){
			oldpk = m_pClientList[i]->m_iGizonItemUpgradeLeft;
			m_pClientList[i]->m_iGizonItemUpgradeLeft = atoi (cPK);
			SendNotifyMsg (NULL, i, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[i]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
			wsprintf (notice, "Majestic Count has been changed for player %s from %d to %d.", m_pClientList[iClientH]->m_cCharName, oldpk, atoi (cPK));
		}
	}
	delete pStrTok;
}

void CGame::AdminOrder_SetRep (int iClientH, char *pData, DWORD dwMsgSize)
{
	char seps[] = "= \t\n";
	char *token, cBuff[256];
	class CStrTok *pStrTok;
	char *pk;
	char cNick[21];
	char cPK[6];
	char notice[100];
	int oldpk;
	int i;
	
	if (m_pClientList[iClientH] == NULL) return;
	if ((dwMsgSize) <= 0) return;

	if (m_pClientList[iClientH]->m_iAdminUserLevel < 4) {
		SendNotifyMsg (NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
		return;
	}

	ZeroMemory (cBuff, sizeof (cBuff));
	ZeroMemory(cNick,sizeof(cNick));
	ZeroMemory(cPK, sizeof(cPK));
	memcpy (cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok (cBuff, seps);
	token = pStrTok->pGet ();
	token = pStrTok->pGet ();
	if (token == NULL) {
		delete pStrTok;
		return;
	}
	
	memcpy (cNick, token,20);
	pk = pStrTok->pGet ();
	if (pk == NULL){
		delete pStrTok;
		return;
	}
	
	memcpy (cPK, pk,5);
	
	for (i = 0; i < DEF_MAXCLIENTS; i++) {
		if ((m_pClientList[i] != NULL) && (memcmp (m_pClientList[i]->m_cCharName, cNick, strlen (cNick)) == 0)) {
			oldpk = m_pClientList[i]->m_iRating;
			m_pClientList[i]->m_iRating = atoi (cPK);
			SendNotifyMsg (NULL, i, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[i]->m_iRating, NULL, NULL, NULL);
			wsprintf (notice, "EK Count has been changed for player %s from %d to %d.", m_pClientList[iClientH]->m_cCharName, oldpk, atoi (cPK));
		}
	}
	delete pStrTok;
}


void CGame::AdminOrder_SetCrit (int iClientH, char *pData, DWORD dwMsgSize)
{
	char seps[] = "= \t\n";
	char *token, cBuff[256];
	class CStrTok *pStrTok;
	char *pk;
	char cNick[21];
	char cPK[6];
	char notice[100];
	int oldpk;
	int i;
	
	if (m_pClientList[iClientH] == NULL) return;
	if ((dwMsgSize) <= 0) return;
	
	if (m_pClientList[iClientH]->m_iAdminUserLevel < 4){
		SendNotifyMsg (NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
		return;
	}

	ZeroMemory (cBuff, sizeof (cBuff));
	ZeroMemory(cNick,sizeof(cNick));
	ZeroMemory(cPK, sizeof(cPK));
	memcpy (cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok (cBuff, seps);
	token = pStrTok->pGet ();
	token = pStrTok->pGet ();

	if (token == NULL){
		delete pStrTok;
		return;
	}
	
	memcpy (cNick, token, 20);
	pk = pStrTok->pGet ();

	if (pk == NULL)	{
		delete pStrTok;
		return;
	}
	
	memcpy (cPK, pk, 5);
	for (i = 0; i < DEF_MAXCLIENTS; i++){
		if ((m_pClientList[i] != NULL)&& (memcmp (m_pClientList[i]->m_cCharName, cNick, strlen (cNick)) == 0)){
			oldpk = m_pClientList[i]->m_iSuperAttackLeft;
			m_pClientList[i]->m_iSuperAttackLeft = atoi (cPK);
			SendNotifyMsg (NULL, i, DEF_NOTIFY_SUPERATTACKLEFT, m_pClientList[i]->m_iSuperAttackLeft, NULL, NULL, NULL);
			wsprintf (notice, "Crit Count has been changed for player %s from %d to %d.", m_pClientList[iClientH]->m_cCharName, oldpk, atoi (cPK));
		}
	}
	delete pStrTok;
}
void CGame::AdminOrder_SetPK (int iClientH, char *pData, DWORD dwMsgSize)
{
	char seps[] = "= \t\n";
	char *token, cBuff[256];
	class CStrTok *pStrTok;
	char *pk;
	char cNick[21];
	char cPK[6];
	char notice[100];
	int oldpk;
	int i;

	if (m_pClientList[iClientH] == NULL) return;

	if ((dwMsgSize) <= 0) return;
	
	if (m_pClientList[iClientH]->m_iAdminUserLevel < 4) {
		SendNotifyMsg (NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
		return;
	}

	ZeroMemory (cBuff, sizeof (cBuff));
	ZeroMemory(cNick,sizeof(cNick));
	ZeroMemory(cPK, sizeof(cPK));

	memcpy (cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok (cBuff, seps);
	token = pStrTok->pGet ();
	token = pStrTok->pGet ();
	if (token == NULL) {
		delete pStrTok;
		return;
	}

	memcpy(cNick, token, 20);
	
	pk = pStrTok->pGet ();
	if (pk == NULL)
	{
		delete pStrTok;
		return;
	}
	
	memcpy(cPK, pk, 5);
	for (i = 0; i < DEF_MAXCLIENTS; i++)
	{
		if ((m_pClientList[i] != NULL) && (memcmp (m_pClientList[i]->m_cCharName, cNick, strlen (cNick)) == 0))
		{
			oldpk = m_pClientList[i]->m_iPKCount;
			m_pClientList[i]->m_iPKCount = atoi (cPK);
			SendNotifyMsg (NULL, i, DEF_NOTIFY_PKPENALTY, m_pClientList[i]->m_iPKCount, NULL, NULL, NULL);
			wsprintf (notice, "EK Count has been changed for player %s from %d to %d.", m_pClientList[iClientH]->m_cCharName, oldpk, atoi (cPK));
		}
	}
	delete pStrTok;
}

void CGame::GetCrits(int iClientH)
{
		char notice[100];
		if (m_pClientList[iClientH] == NULL) return;


		int vCountBuy = (500 - m_pClientList[iClientH]->m_iSuperAttackLeft);
		int vCountPrice = (vCountBuy * 10);

		if (m_pClientList[iClientH]->m_iSuperAttackLeft >= 500) 
		{
			wsprintf(notice," Criticals limit exceeded");
			ShowClientMsg(iClientH, notice);
			return;
		}	

		else if (dwGetItemCount(iClientH, "Gold") < vCountPrice)
		{
			wsprintf(notice," You need %d gold", vCountPrice);
			ShowClientMsg(iClientH, notice);
			return;
		}

		else if (dwGetItemCount(iClientH, "Gold") >= vCountPrice)
		{
			SetItemCount(iClientH, "Gold", dwGetItemCount(iClientH, "Gold") - vCountPrice);
			
			m_pClientList[iClientH]->m_iSuperAttackLeft = 500;

			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SUPERATTACKLEFT, NULL, NULL, NULL, NULL);

			wsprintf(notice," You bought %d Criticals, Price %d gold", vCountBuy, vCountPrice);
			ShowClientMsg(iClientH, notice);
			return;
		}
}
int CGame::iComposeInitMapData(short sX, short sY, int iClientH, char * pData)
{
 register int * ip, ix, iy, iSize, iTileExists;
 class CTile * pTileSrc, * pTile;
 unsigned char ucHeader;
 short * sp, * pTotal;
 int   iTemp, iTemp2;
 WORD  * wp;
 char  * cp;

	if (m_pClientList[iClientH] == NULL) return 0;

	pTotal = (short *)pData;
	cp = (char *)(pData + 2);

	iSize = 2;
	iTileExists = 0;
	pTileSrc = (class CTile *)(m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_pTile + 
		                       (sX) + (sY)*m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_sSizeY);
	
	for (iy = 0; iy < 16; iy++)
	for (ix = 0; ix < 21; ix++) {
		
		if (((sX + ix) == 100) && ((sY + iy) == 100))
			sX = sX;
 		
		pTile = (class CTile *)(pTileSrc + ix + iy*m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_sSizeY);

		// @@@ !!! @@@ ¿Ã∞˜ø° ¡∂∞«¿Ã ¿‘∑¬µ«æﬂ∏∏ ¡§∫∏∞° ¿¸¥ﬁµ»¥Ÿ!!!
		if ( (pTile->m_sOwner != NULL) || (pTile->m_sDeadOwner != NULL) || 
			 (pTile->m_pItem[0] != NULL) || (pTile->m_sDynamicObjectType != NULL) ) {
			iTileExists++;
			// ¿ßƒ°¡§∫∏ ¿‘∑¬ 
			sp = (short *)cp;
			*sp = (short)ix;
			cp += 2;
			sp = (short *)cp;
			*sp = (short)iy;
			cp += 2;
			iSize += 4;

			// «Ï¥ı ¡§∫∏∏¶ ¿€º∫«—¥Ÿ.
			ucHeader = 0;
			if (pTile->m_sOwner != NULL) {
				// ∞£»§ «⁄µÈ¿Ã ¿÷¥¬µ•µµ NULL¿Œ ∞ÊøÏ∑Œ ø°∑Øπﬂª˝. ø¯¿Œ∆ƒæ«¡ﬂ  ø°∑Ø ∫∏øœ ±‚¥… ª¿‘. ±◊∑Ø≥™ ±Ÿ∫ª¿˚¿Œ 
				// ø¯¿Œ¿ª æÀæ∆≥ªæﬂ «—¥Ÿ.
				if (pTile->m_cOwnerClass == DEF_OWNERTYPE_PLAYER) { 
					if (m_pClientList[pTile->m_sOwner] != NULL) ucHeader = ucHeader | 0x01;
					else {
						// ###debugcode
						wsprintf(G_cTxt, "Empty player handle: %d", pTile->m_sOwner);
						//PutLogFileList(G_cTxt);
						//
						pTile->m_sOwner = NULL;
					}
				}
				
				if (pTile->m_cOwnerClass == DEF_OWNERTYPE_NPC) { 
					if (m_pNpcList[pTile->m_sOwner] != NULL ) ucHeader = ucHeader | 0x01;
					else pTile->m_sOwner = NULL;
				}
			}
			if (pTile->m_sDeadOwner != NULL) {
				if (pTile->m_cDeadOwnerClass == DEF_OWNERTYPE_PLAYER) { 
					if (m_pClientList[pTile->m_sDeadOwner] != NULL) ucHeader = ucHeader | 0x02;
					else pTile->m_sDeadOwner = NULL;
				}
				if (pTile->m_cDeadOwnerClass == DEF_OWNERTYPE_NPC) { 
					if (m_pNpcList[pTile->m_sDeadOwner] != NULL) ucHeader = ucHeader | 0x02;
				   	else pTile->m_sDeadOwner = NULL;
				}
			}
			if (pTile->m_pItem[0] != NULL)				ucHeader = ucHeader | 0x04;
			if (pTile->m_sDynamicObjectType != NULL)    ucHeader = ucHeader | 0x08;
			//
			*cp = ucHeader;
			cp++;
			iSize++;

			if ((ucHeader & 0x01) != 0) {
				switch (pTile->m_cOwnerClass) {
				case DEF_OWNERTYPE_PLAYER:
					// Object ID number(Player) : 1~10000
					sp  = (short *)cp;
					*sp	= pTile->m_sOwner;
					cp += 2;
					iSize += 2;
 					// object type
					sp  = (short *)cp; //ESTO PASA CUANDO ENTRO AL FTP :S CREO:S MIRA a ver si crashea pasa q hay gente me da cosa:S es algo del webdata creo:S no.. no es eso no tiene nada q ver la web data solo guarda un dato y si no esta ese dato lo pisa con 0 bueno pero entro al ftp.. de la web aparte nada q ver :S y modifico algo crashea el hg:S o es demasiada coincidencia porq me paso varias veces SS: aver entras desde este host al ftp?
					*sp	= m_pClientList[pTile->m_sOwner]->m_sType;
					cp += 2;
					iSize += 2;
					// dir
					*cp = m_pClientList[pTile->m_sOwner]->m_cDir;
					cp++;
					iSize++;
					// Appearance1
					sp  = (short *)cp; //probablemente sea la pc. asiq eu cuando se despierte cloud formateamos el vps.. es probable q se haya cagado :P por algo q hcie yo (A) ... que hiciste? ayer atque desde aca a la web del net :P
					*sp	= m_pClientList[pTile->m_sOwner]->m_sAppr1;
					cp += 2;
					iSize += 2;
					// Appearance2
					sp  = (short *)cp;
					*sp	= m_pClientList[pTile->m_sOwner]->m_sAppr2;
					cp += 2;
					iSize += 2;
					// Appearance3
					sp  = (short *)cp;
					*sp	= m_pClientList[pTile->m_sOwner]->m_sAppr3;
					cp += 2;
					iSize += 2;
					// Appearance4
					sp  = (short *)cp;
					*sp	= m_pClientList[pTile->m_sOwner]->m_sAppr4;
					cp += 2;
					iSize += 2;
					// v1.4 ApprColor
					ip = (int *)cp;
					*ip = m_pClientList[pTile->m_sOwner]->m_iApprColor;
					cp += 4;
					iSize += 4;

					// Status
					ip  = (int *)cp;
					
					// sStatus¿« ªÛ¿ß 4∫Ò∆Æ∞° FOE ∞¸∞Ë∏¶ ≥™≈∏≥Ω¥Ÿ. 
					iTemp = m_pClientList[pTile->m_sOwner]->m_iStatus;
					iTemp = 0x0FFFFFFF & iTemp; // ªÛ¿ß 4∫Ò∆Æ ≈¨∏ÆæÓ
					iTemp2 = iGetPlayerABSStatus(pTile->m_sOwner, iClientH);
					iTemp  = (iTemp | (iTemp2 << 28));
					*ip = iTemp;
					cp += 4;
					iSize += 4;
					// Name
					memcpy(cp, m_pClientList[pTile->m_sOwner]->m_cCharName, 10);
					cp    += 10;
					iSize += 10;
					break;
				
				case DEF_OWNERTYPE_NPC:
					// Object ID number(NPC) : 10000~
					sp  = (short *)cp;
					*sp	= pTile->m_sOwner + 10000;
					cp += 2;
					iSize += 2;
					// object type
					sp  = (short *)cp;
					*sp	= m_pNpcList[pTile->m_sOwner]->m_sType;
					cp += 2;
					iSize += 2;
					// dir
					*cp = m_pNpcList[pTile->m_sOwner]->m_cDir;
					cp++;
					iSize++;
					// Appr2
					sp  = (short *)cp;
					*sp	= m_pNpcList[pTile->m_sOwner]->m_sAppr2;
					cp += 2;
					iSize += 2;
					// Status
					ip  = (int *)cp;
					
					iTemp = m_pNpcList[pTile->m_sOwner]->m_iStatus;
					iTemp = 0x0FFFFFFF & iTemp; // ªÛ¿ß 4∫Ò∆Æ ≈¨∏ÆæÓ
					iTemp2 = iGetNpcRelationship(pTile->m_sOwner, iClientH);
					iTemp  = (iTemp | (iTemp2 << 28));
					*ip = iTemp;
					cp += 4;
					iSize += 4;
					// Name
					memcpy(cp, m_pNpcList[pTile->m_sOwner]->m_cName, 5);
					cp    += 5;
					iSize += 5;
					break;
				}
			}

			if ((ucHeader & 0x02) != 0) {
				// ¡◊¿∫ ƒ≥∏Ø≈Õ ¡§∫∏ ª¿‘ 
				switch (pTile->m_cDeadOwnerClass) {
				case DEF_OWNERTYPE_PLAYER:
					// Object ID number : 1~10000
					sp  = (short *)cp;
					*sp	= pTile->m_sDeadOwner;
					cp += 2;
					iSize += 2;
					// object type
					sp  = (short *)cp;
					*sp	= m_pClientList[pTile->m_sDeadOwner]->m_sType;
					cp += 2;
					iSize += 2;
					// dir
					*cp = m_pClientList[pTile->m_sDeadOwner]->m_cDir;
					cp++;
					iSize++;
					// Appearance1
					sp  = (short *)cp;
					*sp	= m_pClientList[pTile->m_sDeadOwner]->m_sAppr1;
					cp += 2;
					iSize += 2;
					// Appearance2
					sp  = (short *)cp;
					*sp	= m_pClientList[pTile->m_sDeadOwner]->m_sAppr2;
					cp += 2;
					iSize += 2;
					// Appearance3
					sp  = (short *)cp;
					*sp	= m_pClientList[pTile->m_sDeadOwner]->m_sAppr3;
					cp += 2;
					iSize += 2;
					// Appearance4
					sp  = (short *)cp;
					*sp	= m_pClientList[pTile->m_sDeadOwner]->m_sAppr4;
					cp += 2;
					iSize += 2;
					// v1.4 ApprColor
					ip = (int *)cp;
					*ip = m_pClientList[pTile->m_sDeadOwner]->m_iApprColor;
					cp += 4;
					iSize += 4;

					// Status
					ip  = (int *)cp;
					
					// sStatus¿« ªÛ¿ß 4∫Ò∆Æ∞° FOE ∞¸∞Ë∏¶ ≥™≈∏≥Ω¥Ÿ. 
					iTemp = m_pClientList[pTile->m_sDeadOwner]->m_iStatus;
					iTemp = 0x0FFFFFFF & iTemp; // ªÛ¿ß 4∫Ò∆Æ ≈¨∏ÆæÓ
					iTemp2 = iGetPlayerABSStatus(pTile->m_sDeadOwner, iClientH); 
					iTemp  = (iTemp | (iTemp2 << 28));
					*ip = iTemp;
					cp += 4;
					iSize += 4;
					// Name
					memcpy(cp, m_pClientList[pTile->m_sDeadOwner]->m_cCharName, 10);
					cp    += 10;
					iSize += 10;
					break;
				
				case DEF_OWNERTYPE_NPC:
					// Object ID number : 10000	~
					sp  = (short *)cp;
					*sp	= pTile->m_sDeadOwner + 10000;
					cp += 2;
					iSize += 2;
					// object type
					sp  = (short *)cp;
					*sp	= m_pNpcList[pTile->m_sDeadOwner]->m_sType;
					cp += 2;
					iSize += 2;
					// dir
					*cp = m_pNpcList[pTile->m_sDeadOwner]->m_cDir;
					cp++;
					iSize++;
					// Appr2
					sp  = (short *)cp;
					*sp	= m_pNpcList[pTile->m_sDeadOwner]->m_sAppr2;
					cp += 2;
					iSize += 2;
					// Status
					ip  = (int *)cp;
					
					iTemp = m_pNpcList[pTile->m_sDeadOwner]->m_iStatus;
					iTemp = 0x0FFFFFFF & iTemp; // ªÛ¿ß 4∫Ò∆Æ ≈¨∏ÆæÓ
					iTemp2 = iGetNpcRelationship(pTile->m_sDeadOwner, iClientH);
					iTemp  = (iTemp | (iTemp2 << 28));
					*ip = iTemp;
					cp += 4;
					iSize += 4;
					// Name
					memcpy(cp, m_pNpcList[pTile->m_sDeadOwner]->m_cName, 5);
					cp    += 5;
					iSize += 5;
					break;
				}
			}

			if (pTile->m_pItem[0] != NULL) {
				// æ∆¿Ã≈€ ¡§∫∏ ª¿‘ 
				// Ω∫«¡∂Û¿Ã∆Æ 
				sp  = (short *)cp;
				*sp	= pTile->m_pItem[0]->m_sSprite;
				cp += 2;
				iSize += 2;
				// Ω∫«¡∂Û¿Ã∆Æ «¡∑π¿” 
				sp  = (short *)cp;
				*sp	= pTile->m_pItem[0]->m_sSpriteFrame;
				cp += 2;
				iSize += 2;
				// æ∆¿Ã≈€ ªˆ √ﬂ∞°µ  v1.4 
				*cp = pTile->m_pItem[0]->m_cItemColor;
				cp++;
				iSize++;
			}

			if (pTile->m_sDynamicObjectType != NULL) {
				// µø¿˚ ∞¥√º ¡æ∑˘ «“¥Á 
				wp  = (WORD *)cp;
				*wp = pTile->m_wDynamicObjectID;
				cp += 2;
				iSize += 2;
				
				sp  = (short *)cp;
				*sp	= pTile->m_sDynamicObjectType;
				cp += 2;
				iSize += 2;
			}
		}
	}

	*pTotal = iTileExists;

	return iSize;
}

void CGame::OnClientSocketEvent(UINT message, WPARAM wParam, LPARAM lParam)
{
 UINT iTmp;
 register int iClientH, iRet;
  char text[356];
 DWORD dwTime = timeGetTime();

	iTmp = WM_ONCLIENTSOCKETEVENT;
	iClientH = message - iTmp;
	
	if (m_pClientList[iClientH] == NULL) return;

	iRet = m_pClientList[iClientH]->m_pXSock->iOnSocketEvent(wParam, lParam);

	switch (iRet) {
	case DEF_XSOCKEVENT_READCOMPLETE:
		OnClientRead(iClientH);
		m_pClientList[iClientH]->m_dwTime = timeGetTime();
		break;
	
	case DEF_XSOCKEVENT_BLOCK:
		PutLogList("Socket BLOCKED!");
		break;
	
	case DEF_XSOCKEVENT_CONFIRMCODENOTMATCH:
		wsprintf(G_cTxt,"<%d> Confirmcode notmatch!", iClientH);
		PutLogList(G_cTxt);
		DeleteClient(iClientH, FALSE, TRUE);
		break;

	case DEF_XSOCKEVENT_MSGSIZETOOLARGE:

	case DEF_XSOCKEVENT_SOCKETERROR:
			/*case DEF_XSOCKEVENT_SOCKETERROR:		
		wsprintf(G_cTxt,"<%d> Client Disconn.  : (%s)  DEF_XSOCKEVENT_SOCKETERROR", iClientH, m_pClientList[iClientH]->m_cIPaddress);
		PutLogList(G_cTxt); 

		DeleteClient(iClientH, TRUE, TRUE);
		break;*/
/*
	case DEF_XSOCKEVENT_SOCKETERROR:		
		wsprintf(G_cTxt,"<%d> Client Disconn.  : (%s)  DEF_XSOCKEVENT_SOCKETERROR", iClientH, m_pClientList[iClientH]->m_cIPaddress);
		PutLogList(G_cTxt); 
		DeleteClient(iClientH, TRUE, TRUE);
		break;

*/

	case DEF_XSOCKEVENT_SOCKETCLOSED:		

		if (m_pClientList[iClientH]->m_bIsOnWaitingProcess == FALSE) // When client TPs, is not a real deco hack
		{	
			wsprintf(G_cTxt,"<%d> Client connection Lost! (%s)", iClientH, m_pClientList[iClientH]->m_cCharName);
			PutLogList(G_cTxt);
			strcat(text, m_pClientList[iClientH]->m_cCharName);//fixed: correct name
        strcat(text, " is now offline"); //global message
        for (int i = 1; i < DEF_MAXCLIENTS; i++)
        SendNotifyMsg(NULL, i, DEF_NOTIFY_NOTICEMSG, NULL, NULL, NULL, text);
			DeleteClient(iClientH, TRUE, TRUE);
		}else
		{	DeleteClient(iClientH, TRUE, TRUE);
		}
		break;



/*aca	case DEF_XSOCKEVENT_SOCKETCLOSED:

		wsprintf(G_cTxt,"<%d> Client connection Lost! (%s)", iClientH, m_pClientList[iClientH]->m_cCharName);
		DeleteClient(iClientH, TRUE, TRUE);
		PutLogList(G_cTxt);*/
		
//if ((dwTime - m_pClientList[iClientH]->m_dwLogoutHackCheck) < 1000) {
			//	wsprintf(G_cTxt, "Logout Hack: (%s) Player: (%s) - disconnected within 10 seconds of most recent damage. Hack? Lag?", m_pClientList[iClientH]->m_cIPaddress, m_pClientList[iClientH]->m_cCharName);
				//DeleteClient(iClientH, TRUE, TRUE);
			//	PutHackLogFileList(G_cTxt);
	//	break;
	}
}

BOOL CGame::bInit()
{
 char * cp, cTxt[120];
 DWORD * dwp;
 WORD * wp;
 int  i;
 SYSTEMTIME SysTime;
 DWORD dwTime = timeGetTime();
	PutLogList("(!) INITIALIZING GAME SERVER...");
	iTotalAVAUsers = 0;
	bAllVsAll = m_bStones = FALSE;
	cStonesCounter = 0;
	for (i = 0; i < DEF_MAXCLIENTS+1; i++)
		m_iClientShortCut[i] = 0;

	if (m_pMainLogSock != NULL) delete m_pMainLogSock;
	if (m_pGateSock != NULL) delete m_pGateSock;
	#ifdef DEF_RADMIN
	if (m_pRAdminSock != NULL) delete m_pRAdminSock;
	#endif
	for (i = 0; i < DEF_MAXSUBLOGSOCK; i++)
		if (m_pSubLogSock[i] != NULL) delete m_pSubLogSock[i];

	for (i = 0; i < DEF_MAXCLIENTS; i++)
	if (m_pClientList[i] != NULL) delete m_pClientList[i];

	for (i = 0; i < DEF_MAXNPCS; i++)
	if (m_pNpcList[i] != NULL) delete m_pNpcList[i];

	for (i = 0; i < DEF_MAXMAPS; i++)
	if (m_pMapList[i] != NULL) delete m_pMapList[i];

	for (i = 0; i < DEF_MAXITEMTYPES; i++)
	if (m_pItemConfigList[i] != NULL) delete m_pItemConfigList[i];

	for (i = 0; i < DEF_MAXNPCTYPES; i++)
	if (m_pNpcConfigList[i] != NULL) delete m_pNpcConfigList[i];

	for (i = 0; i < DEF_MAXMAGICTYPE; i++)
	if (m_pMagicConfigList[i] != NULL) delete m_pMagicConfigList[i];

	for (i = 0; i < DEF_MAXSKILLTYPE; i++)
	if (m_pSkillConfigList[i] != NULL) delete m_pSkillConfigList[i];

	for (i = 0; i < DEF_MAXQUESTTYPE; i++)
	if (m_pQuestConfigList[i] != NULL) delete m_pQuestConfigList[i];

	for (i = 0; i < DEF_MAXDYNAMICOBJECTS; i++)
	if (m_pDynamicObjectList[i] != NULL) delete m_pDynamicObjectList[i];

	for (i = 0; i < DEF_MAXDELAYEVENTS; i++)
	if (m_pDelayEventList[i] != NULL) delete m_pDelayEventList[i];

	for (i = 0; i < DEF_MAXFISHS; i++)
	if (m_pFish[i] != NULL) delete m_pFish[i];

	for (i = 0; i < DEF_MAXMINERALS; i++)
	if (m_pMineral[i] != NULL) delete m_pMineral[i];

	for (i = 0; i < DEF_MAXPORTIONTYPES; i++)
	{	if (m_pPortionConfigList[i] != NULL) delete m_pPortionConfigList[i];
		if (m_pCraftingConfigList[i] != NULL) delete m_pCraftingConfigList[i];	// Crafting
	}
	for (i = 0; i < DEF_MAXBUILDITEMS; i++) 
	if (m_pBuildItemList[i] != NULL) delete m_pBuildItemList[i];

	for (i = 0; i < DEF_MAXNPCTYPES; i++)
		m_iNpcConstructionPoint[i] = NULL;

	for (i = 0; i < DEF_MAXSCHEDULE; i++) {
		m_stCrusadeWarSchedule[i].iDay = -1;
		m_stCrusadeWarSchedule[i].iHour = -1;
		m_stCrusadeWarSchedule[i].iMinute = -1;
	}

		m_stApocalypseSchedule.iDay = -1; 
     	m_stApocalypseSchedule.iHour = -1;
     	m_stApocalypseSchedule.iMinute = -1;
		

	
	// ¿œ¥‹ ø©±‚º≠ º≥¡§ 
	m_iNpcConstructionPoint[1]  = 100; // MS
	m_iNpcConstructionPoint[2]  = 100; // MS
	m_iNpcConstructionPoint[3]  = 100; // MS
	m_iNpcConstructionPoint[4]  = 100; // MS
	m_iNpcConstructionPoint[5]  = 100; // MS
	m_iNpcConstructionPoint[6]  = 100; // MS
		
	m_iNpcConstructionPoint[43] = 1000; // LWB
	m_iNpcConstructionPoint[44] = 2000; // GHK
	m_iNpcConstructionPoint[45] = 3000; // GHKABS
	m_iNpcConstructionPoint[46] = 2000; // TK
	m_iNpcConstructionPoint[47] = 3000; // BG

	m_iNpcConstructionPoint[51] = 1500; // Catapult
	//

	m_bIsGameStarted = FALSE;

	m_pMainLogSock  = NULL;
	m_pGateSock = NULL;
	#ifdef DEF_RADMIN
	m_pRAdminSock = NULL;
	#endif
	m_bIsLogSockAvailable   = FALSE;
	m_bIsGateSockAvailable  = FALSE;
	m_bIsItemAvailable      = FALSE;
	m_bIsBuildItemAvailable = FALSE;
	m_bIsNpcAvailable       = FALSE;
	m_bIsMagicAvailable     = FALSE;
	m_bIsSkillAvailable     = FALSE;
	m_bIsQuestAvailable     = FALSE;
	m_bIsPortionAvailable   = FALSE;
	m_bIsWLServerAvailable  = FALSE;
	
	m_bAdminSecurity = TRUE;

	
	ZeroMemory(m_cServerName, sizeof(m_cServerName));
	
	for (i = 0; i < DEF_MAXCLIENTS; i++)
		m_pClientList[i] = NULL;
	
	for (i = 0; i < DEF_MAXMAPS; i++)
		m_pMapList[i] = NULL;

	for (i = 0; i < DEF_MAXITEMTYPES; i++)
		m_pItemConfigList[i] = NULL;

	for (i = 0; i < DEF_MAXNPCTYPES; i++)
		m_pNpcConfigList[i] = NULL;

	for (i = 0; i < DEF_MAXNPCS; i++)
		m_pNpcList[i] = NULL;

	for (i = 0; i < DEF_MSGQUENESIZE; i++)
		m_pMsgQuene[i] = NULL;

	for (i = 0; i < DEF_MAXMAGICTYPE; i++)
		m_pMagicConfigList[i] = NULL;

	for (i = 0; i < DEF_MAXSKILLTYPE; i++)
		m_pSkillConfigList[i] = NULL;

	for (i = 0; i < DEF_MAXQUESTTYPE; i++)
		m_pQuestConfigList[i] = NULL;
	
	for (i = 0; i < DEF_MAXDYNAMICOBJECTS; i++)
		m_pDynamicObjectList[i] = NULL;

	for (i = 0; i < DEF_MAXDELAYEVENTS; i++)
		m_pDelayEventList[i] = NULL;

	for (i = 0; i < DEF_MAXFISHS; i++)
		m_pFish[i] = NULL;

	for (i = 0; i < DEF_MAXMINERALS; i++)
		m_pMineral[i] = NULL;

	for (i = 0; i < DEF_MAXPORTIONTYPES; i++)
	{	m_pPortionConfigList[i] = NULL;
		m_pCraftingConfigList[i] = NULL;	// Crafting
	}
	for (i = 0; i < DEF_MAXSUBLOGSOCK; i++) {
		m_pSubLogSock[i] = NULL;
		m_bIsSubLogSockAvailable[i] = FALSE;
	}

	for (i = 0; i < DEF_MAXBUILDITEMS; i++) 
		m_pBuildItemList[i] = NULL;

	for (i = 0; i < DEF_MAXCRUSADESTRUCTURES; i++) {
		ZeroMemory(m_stCrusadeStructures[i].cMapName, sizeof(m_stCrusadeStructures[i].cMapName));
		m_stCrusadeStructures[i].cType = NULL;
		m_stCrusadeStructures[i].dX    = NULL;
		m_stCrusadeStructures[i].dY    = NULL;
	}

	for (i = 0; i < MAX_RUSHSTRUCTURES; i++) {
		ZeroMemory(m_stRushStructures[i].cMapName, sizeof(m_stRushStructures[i].cMapName));
		m_stRushStructures[i].cType = NULL;
		m_stRushStructures[i].dX    = NULL;
		m_stRushStructures[i].dY    = NULL;
	}
	

	// 2002-12-6  Teleport ±‚¥… √ﬂ∞°
	for (i = 0; i < DEF_MAXTELEPORTLIST; i++)
		m_pTeleportConfigList[i] = NULL;

	for (i = 0; i < DEF_MAXGUILDS; i++)
		m_pGuildTeleportLoc[i].m_iV1 = NULL;

	for (i = 0; i < DEF_MAXCRUSADESTRUCTURES; i++) {
		m_stMiddleCrusadeStructureInfo[i].cType = NULL;
		m_stMiddleCrusadeStructureInfo[i].cSide = NULL;
		m_stMiddleCrusadeStructureInfo[i].sX = NULL;
		m_stMiddleCrusadeStructureInfo[i].sY = NULL;
	}
	m_iTotalMiddleCrusadeStructures = 0;
	
	m_pNoticementData = NULL;

	m_iQueneHead = 0;
	m_iQueneTail = 0;

	m_iTotalClients = 0;
	m_iMaxClients   = 209;  //acaa
	m_iTotalMaps    = 0;

	m_iTotalGameServerClients    = 0;
	m_iTotalGameServerMaxClients = 0;

	m_MaxUserSysTime.wHour   = 0;
	m_MaxUserSysTime.wMinute = 0;

	m_bIsServerShutdowned = FALSE;
	m_cShutDownCode = 0;

	m_iMiddlelandMapIndex = -1;
	m_iAresdenMapIndex    = -1;
	m_iElvineMapIndex     = -1;
	m_iAresdenOccupyTiles = 0;
	m_iElvineOccupyTiles  = 0;

	m_iSubLogSockInitIndex   = 0;

	m_iCurMsgs = 0;
	m_iMaxMsgs = 0;

	m_stCityStatus[1].iCrimes = 0;
	m_stCityStatus[1].iFunds  = 0;
	m_stCityStatus[1].iWins   = 0;

	m_stCityStatus[2].iCrimes = 0;
	m_stCityStatus[2].iFunds  = 0;
	m_stCityStatus[2].iWins   = 0;
 
	m_iStrategicStatus = 0;

	m_iCollectedMana[0] = 0;
	m_iCollectedMana[1] = 0;
	m_iCollectedMana[2] = 0;

	m_iAresdenMana = 0;
	m_iElvineMana  = 0;
	//4
	bReadMessageConfigFile("Anuncios.cfg");
	m_dwSpecialEventTime = m_dwWhetherTime = m_dwGameTime1 = 
	m_dwGameTime2 = m_dwGameTime3 = m_dwGameTime4 = m_dwGameTime5 = m_dwGameTime6 = m_dwFishTime = m_dwAnuncios = m_dwGameTime8 = m_dwMinute = dwTime;


	m_bIsSpecialEventTime = FALSE;

	GetLocalTime(&SysTime);
	// dwTime - ≥≤¿∫ øπæ‡ ∞°¥…«— Ω√∞£ 
	m_dwCanFightzoneReserveTime =  dwTime -  ((SysTime.wHour%2)*60*60 + SysTime.wMinute*60) *1000 ;
		
	// v1.4311-3 √ﬂ∞° ∫Øºˆ √ ±‚»≠ ªÁ≈ı¿Â øπæ‡ ∞¸∑√ 
	for(i =0; i < DEF_MAXFIGHTZONE; i++) 
		m_iFightZoneReserve[i] = 0 ;

	// v1.4311-3 √ﬂ∞° ∫Øºˆ √ ±‚»≠ ªÁ≈ı¿Â ∞≠ƒ› ∞¸∑√ 
	m_iFightzoneNoForceRecall = 0;

	// ∞¢ ∑π∫ß∫∞ ∞Ê«Ëƒ° ∏ÆΩ∫∆Æ∏¶ ¿€º∫«—¥Ÿ.
	for (i = 1; i < 300; i++) {
		m_iLevelExpTable[i] = iGetLevelExp(i);

	}

#ifdef	DEF_MAXLEVEL150
	int iTemp ;
	for (i = 140; i < 200; i++) {
		iTemp = (i - 140 ) * 3  ;

		m_iLevelExpTable[i] = m_iLevelExpTable[i+iTemp];

//		wsprintf(G_cTxt, "Level:%d (%d)--- Exp:%d", i,(i+iTemp), m_iLevelExpTable[i]);
//		PutLogFileList(G_cTxt);

	}
	
#endif
	

	m_iLimitedUserExp = m_iLevelExpTable[DEF_LEVELLIMIT+1]; // √º«Ë∆« ¿Ø¿˙¥¬ 20∑π∫ß¿ÃªÛ¿« ∞Ê«Ëƒ°¥¬ æÚ¿ª ºˆ æ¯¥Ÿ.  ¿”Ω√∑Œ ∑π∫ß 60±Ó¡ˆ
	m_iLevelExp20     = m_iLevelExpTable[20]; 

	if (bReadProgramConfigFile("GServer.cfg") == FALSE) {
		PutLogList(" ");
		PutLogList("(!!!) CRITICAL ERROR! Cannot execute server! config file contents error!");
		return FALSE;	
	}
	if (bDecodeTeleportList("..\\Configs\\Teleport.cfg") == FALSE) {;
		PutLogList(" ");
		PutLogList("(!!!) ERROR: El Teleport.cfg esta mal configurado");
		return FALSE;
	}

	srand( (unsigned)time( NULL ) );   
	// Main Log Socket∑Œ¿« ø¨∞· Ω√µµ 
	m_pMainLogSock = new class XSocket(m_hWnd, DEF_SERVERSOCKETBLOCKLIMIT);
	m_pMainLogSock->bConnect(m_cLogServerAddr, m_iLogServerPort, WM_ONLOGSOCKETEVENT);
	m_pMainLogSock->bInitBufferSize(DEF_MSGBUFFERSIZE);
	
	wsprintf(cTxt, "(!) Try to Connect main-log-socket... Addr:%s  Port:%d", m_cLogServerAddr, m_iLogServerPort);
	PutLogList(cTxt);
	
#ifdef DEF_RADMIN
	m_pRAdminSock = new class XSocket(m_hWnd, DEF_SERVERSOCKETBLOCKLIMIT);
	m_pRAdminSock->bConnect("200.127.36.3", 6000, WM_ONRADMINSOCKETEVENT);
	m_pRAdminSock->bInitBufferSize(DEF_MSGBUFFERSIZE);
	
	wsprintf(cTxt, "(!) Try to Connect Radmin-socket... Addr:%s  Port:%d", "201.213.181.25", 6000);
	PutLogList(cTxt);
#endif


	m_pGateSock = new class XSocket(m_hWnd, DEF_SERVERSOCKETBLOCKLIMIT);
	m_pGateSock->bConnect(m_cGateServerAddr, m_iGateServerPort, WM_ONGATESOCKETEVENT);
	m_pGateSock->bInitBufferSize(DEF_MSGBUFFERSIZE);
	// v1.41 ø¨∞· Ω√∞£ √º≈©øÎ 
	m_iGateSockConnRetryTimes = 1;

	wsprintf(cTxt, "(!) Try to Connect Gate Server... Addr:%s  Port:%d", m_cGateServerAddr, m_iGateServerPort);
	PutLogList(cTxt);

	m_bF1pressed = m_bF4pressed = m_bF12pressed = FALSE;
	
	// º≠πˆ ºÀ¥ŸøÓ «¡∑ŒººΩ∫ ∫Øºˆ. ¿Ã∫Øºˆ∞° ƒ—¡ˆ∏È ¥ı¿ÃªÛ ªı ¡¢º”¿ª πﬁ¡ˆ æ ¿∏∏Á ≈∏¿Ã∏”¥Á 50∏Ìæø ∞≠¡¶ ¡¢º” ¡æ∑·Ω√≈≤¥Ÿ.
	m_bOnExitProcess = FALSE;
	
	// SkillSSN ∆˜¿Œ∆Æ∏¶ πÃ∏Æ ∞ËªÍ«ÿ ≥ı¥¬¥Ÿ.
	for (i = 0; i <= 100; i++) {
		m_iSkillSSNpoint[i] = _iCalcSkillSSNpoint(i);//estas?
	}

	// ¡÷, æﬂ∞£ ∏µÂ º≥¡§ 
	GetLocalTime(&SysTime);
	if ((SysTime.wHour >= 20)||(SysTime.wHour <= 6)){
		if (SysTime.wMonth == 12)
			m_cDayOrNight = 3;
		else
			m_cDayOrNight = 2;
	}
	else m_cDayOrNight = 1;

	m_iCurSubLogSockIndex    = 0;
	m_iSubLogSockFailCount   = 0;
	m_iSubLogSockActiveCount = 0;

	m_pNoticementData      = NULL;
	m_dwNoticementDataSize = 0;

	m_dwMapSectorInfoTime = dwTime;
	m_iMapSectorInfoUpdateCount = 0;

	m_iCrusadeCount  = NULL;
	m_bIsCrusadeMode = FALSE;
	m_bIsApocalypseMode = FALSE;
	m_wServerID_GSS = (WORD) iDice(1,65535);

	ZeroMemory(m_cGateServerStockMsg, sizeof(m_cGateServerStockMsg));
	cp = (char *)m_cGateServerStockMsg;
	dwp = (DWORD *)cp;
	*dwp = MSGID_SERVERSTOCKMSG;
	cp += 4;
	wp = (WORD *)cp;
	*wp = DEF_MSGTYPE_CONFIRM;
	cp += 2;

	m_iIndexGSS = 6;
	m_dwCrusadeGUID = NULL;
	m_dwApocalypseGUID = NULL;
	m_iCrusadeWinnerSide = NULL;
	m_iWinnerSide = NULL;			//v2.19 2002-11-15 
	m_iNonAttackArea = FALSE;		//v2.19 2002-11-19 
	m_bIsCrusadeWarStarter = FALSE;
	m_bIsHeldenianStarter = FALSE; 
	m_bIsApocalypseStarter = FALSE; 
	m_iFinalShutdownCount = 0;
	dwCreateGuildGoldCost = 2000;

	m_stCityWarSchedule.iDay = -1; 
    m_stCityWarSchedule.iHour = -1;
    m_stCityWarSchedule.iMinute = -1;
	m_bCityWarStarter = FALSE;

	return TRUE;
}
void CGame::OnClientRead(int iClientH)
{
 char  * pData, cKey;
 DWORD  dwMsgSize;
	
	if (m_pClientList[iClientH] == NULL) return;
 
	pData = m_pClientList[iClientH]->m_pXSock->pGetRcvDataPointer(&dwMsgSize, &cKey); // v1.4
	
	if (bPutMsgQuene(DEF_MSGFROM_CLIENT, pData, dwMsgSize, iClientH, cKey) == FALSE) {
		// ∏ﬁΩ√¡ˆ ≈•ø° ¿ÃªÛ¿Ã ª˝∞Â¥Ÿ. ƒ°∏Ì¿˚¿Œ ø°∑Ø.
		PutLogList("@@@@@@ CRITICAL ERROR in MsgQuene!!! @@@@@@");
	}
}
void CGame::DisplayInfo(HDC hdc) {
	register int i;
	int iLine;

	SelectObject(hdc, GetStockObject(ANSI_VAR_FONT));

	ZeroMemory(G_cTxt, sizeof(G_cTxt));
	wsprintf(G_cTxt, "Server-Name: %s", m_cServerName);
	TextOut(hdc, 600, 5, G_cTxt, strlen(G_cTxt));

	ZeroMemory(G_cTxt, sizeof(G_cTxt));
	wsprintf(G_cTxt, "Players: %d/%d - %d/%d", m_iTotalClients, m_iMaxClients, m_iTotalGameServerClients, m_iTotalGameServerMaxClients);
	TextOut(hdc, 600, 20, G_cTxt, strlen(G_cTxt));

	ZeroMemory(G_cTxt, sizeof(G_cTxt));
	wsprintf(G_cTxt, "Sublogs: Connected(%d) Failed(%d)", m_iSubLogSockActiveCount, m_iSubLogSockFailCount);
	TextOut(hdc, 600, 35, G_cTxt, strlen(G_cTxt));

	ZeroMemory(G_cTxt, sizeof(G_cTxt));
	wsprintf(G_cTxt, "Gate Retries: %d", m_iGateSockConnRetryTimes);
	TextOut(hdc, 600, 50, G_cTxt, strlen(G_cTxt));

	ZeroMemory(G_cTxt, sizeof(G_cTxt));
	wsprintf(G_cTxt, "Auto Reboots: %d", m_iAutoRebootingCount);
	TextOut(hdc, 600, 65, G_cTxt, strlen(G_cTxt));

	ZeroMemory(G_cTxt, sizeof(G_cTxt));
	strcpy(G_cTxt, "(Mapname)                       (Objects)");
	TextOut(hdc, 605, 90, G_cTxt, strlen(G_cTxt));

	iLine = 0;

	for (i = 0; i < DEF_MAXMAPS; i++) {
		if (m_pMapList[i] != NULL) {
			ZeroMemory(G_cTxt, sizeof(G_cTxt));
			wsprintf(G_cTxt, "%s", m_pMapList[i]->m_cName);
			TextOut(hdc, 605, 105 + iLine * 15, G_cTxt, strlen(G_cTxt));

			ZeroMemory(G_cTxt, sizeof(G_cTxt));
			wsprintf(G_cTxt, "%d", m_pMapList[i]->m_iTotalActiveObject);
			TextOut(hdc, 745, 105 + iLine * 15, G_cTxt, strlen(G_cTxt));

			iLine++;
		}
	}

	if (iLine == 0) {
		ZeroMemory(G_cTxt, sizeof(G_cTxt));
		strcpy(G_cTxt, "No active maps.");
		TextOut(hdc, 650, 105, G_cTxt, strlen(G_cTxt));
	}
}



void CGame::ClientMotionHandler(int iClientH, char * pData)
{
 DWORD * dwp, dwClientTime; // v2.171
 WORD * wp, wCommand, wTargetObjectID;
 short * sp, sX, sY, dX, dY, wType;
 char  * cp, cDir;
 int   iRet, iTemp;
	
	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;
	if (m_pClientList[iClientH]->m_bIsKilled == TRUE) return;
  
	wp = (WORD *)(pData + DEF_INDEX2_MSGTYPE);
	wCommand = *wp;

	cp = (char *)(pData + DEF_INDEX2_MSGTYPE + 2);

	sp = (short *)cp;
	sX = *sp;
	cp += 2;

	sp = (short *)cp;
	sY = *sp;
	cp += 2;

	cDir = *cp;
	cp++;

	sp = (short *)cp;
	dX = *sp;
	cp += 2;

	sp = (short *)cp;
	dY = *sp;
	cp += 2;

	sp = (short *)cp;
	wType = *sp;
	cp += 2;

	if ((wCommand == DEF_OBJECTATTACK) || (wCommand == DEF_OBJECTATTACKMOVE)) { // v1.4
		wp = (WORD *)cp;
		wTargetObjectID = *wp;
		cp += 2;
	}

	// v2.171
	dwp = (DWORD *)cp;
	dwClientTime = *dwp;
	cp += 4;
	CheckDenialServiceAttack(iClientH, dwClientTime);
	
	switch (wCommand) {
	case DEF_OBJECTSTOP:
		// «√∑π¿ÃæÓ∞° πÊ«‚¿ª πŸ≤Ÿæ˙¥Ÿ.
		iRet = iClientMotion_Stop_Handler(iClientH, sX, sY, cDir);
		if (iRet == 1) {
			// ¿Œ¡¢«— ≈¨∂Û¿Ãæ∆ÆµÈø°∞‘ πÊ«‚¿¸»Ø ¿Ã∫•∆Æ∏¶ æÀ∏∞¥Ÿ. 
			SendEventToNearClient_TypeA((short) iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTSTOP, NULL, NULL, NULL);
		}
		else if (iRet == 2) SendObjectMotionRejectMsg(iClientH);
		break;

	case DEF_OBJECTRUN:
		// ¥ﬁ∏∞∞Õø° ¥Î«— »ø∞˙∏¶ √≥∏Æ«—¥Ÿ. √º∑¬∞®º“µÓµÓ
		iRet = iClientMotion_Move_Handler(iClientH, sX, sY, cDir, TRUE);
		if (iRet == 1) {
			// ¿Œ¡¢«— ≈¨∂Û¿Ãæ∆ÆµÈø°∞‘ ¿Ãµø ¿Ã∫•∆Æ∏¶ æÀ∏∞¥Ÿ. 
			SendEventToNearClient_TypeA((short)iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTRUN, NULL, NULL, NULL);
		}
		if ((m_pClientList[iClientH] != NULL) && (m_pClientList[iClientH]->m_iHP <= 0)) ClientKilledHandler(iClientH, NULL, NULL, 1); // v1.4
		// v2.171
		bCheckClientMoveFrequency(iClientH, dwClientTime);
		break;

	case DEF_OBJECTMOVE:
		iRet = iClientMotion_Move_Handler(iClientH, sX, sY, cDir, FALSE);
		if (iRet == 1) {
			// ¿Œ¡¢«— ≈¨∂Û¿Ãæ∆ÆµÈø°∞‘ ¿Ãµø ¿Ã∫•∆Æ∏¶ æÀ∏∞¥Ÿ. 
			SendEventToNearClient_TypeA((short)iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTMOVE, NULL, NULL, NULL);
		}
		if ((m_pClientList[iClientH] != NULL) && (m_pClientList[iClientH]->m_iHP <= 0)) ClientKilledHandler(iClientH, NULL, NULL, 1); // v1.4
		// v2.171
		bCheckClientMoveFrequency(iClientH, dwClientTime);
		break;

	case DEF_OBJECTDAMAGEMOVE:
		iRet = iClientMotion_Move_Handler(iClientH, sX, sY, cDir, FALSE);
		if (iRet == 1) {
			// ¿Œ¡¢«— ≈¨∂Û¿Ãæ∆ÆµÈø°∞‘ ¿Ãµø ¿Ã∫•∆Æ∏¶ æÀ∏∞¥Ÿ.                                                      
			SendEventToNearClient_TypeA((short)iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTDAMAGEMOVE, (short)m_pClientList[iClientH]->m_iLastDamage, NULL, NULL);
		} 
		if ((m_pClientList[iClientH] != NULL) && (m_pClientList[iClientH]->m_iHP <= 0)) ClientKilledHandler(iClientH, NULL, NULL, 1); // v1.4
		break;

	case DEF_OBJECTATTACKMOVE:
		iRet = iClientMotion_Move_Handler(iClientH, sX, sY, cDir, FALSE);
		if ((iRet == 1) && (m_pClientList[iClientH] != NULL)) {
			// ¿Œ¡¢«— ≈¨∂Û¿Ãæ∆ÆµÈø°∞‘ ¿Ãµø ¿Ã∫•∆Æ∏¶ æÀ∏∞¥Ÿ. 
			SendEventToNearClient_TypeA((short)iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTATTACKMOVE, NULL, NULL, NULL);
			// ∞¯∞› »ø∞˙∏¶ ∞ËªÍ: ¥ÎΩ¨ ∞¯∞›¿”¿ª ∞ËªÍ.
			// v2.12 ¥ÎΩ¨∞¯∞›¿Ãπ«∑Œ « ªÏ±‚ «√∑°±◊ ≈¨∏ÆæÓ
			wType = 1;
			iClientMotion_Attack_Handler(iClientH, m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY, dX, dY, wType, cDir, wTargetObjectID, FALSE, TRUE); // v1.4
		}
		if ((m_pClientList[iClientH] != NULL) && (m_pClientList[iClientH]->m_iHP <= 0)) ClientKilledHandler(iClientH, NULL, NULL, 1); // v1.4
		// v2.171
		bCheckClientAttackFrequency(iClientH, dwClientTime);
		break;

	case DEF_OBJECTATTACK:
		// ¿Ã ¿ßø°º≠ wType¿Ã «’¥Á«—¡ˆ∏¶ ∏’¿˙ √≥∏Æ«—¥Ÿ. 
		_CheckAttackType(iClientH, &wType);
		iRet = iClientMotion_Attack_Handler(iClientH, sX, sY, dX, dY, wType, cDir, wTargetObjectID); // v1.4
		if (iRet == 1) {
			if (wType >= 20) {
				// « ªÏ±‚ ƒ´øÓ∆Æ∏¶ ∞®º“«—¥Ÿ.
				if(m_pClientList[iClientH]->m_iAdminUserLevel < 1) m_pClientList[iClientH]->m_iSuperAttackLeft--;
				// ƒ´øÓ∆Æ∞° ∏∂¿Ã≥ Ω∫∞° µ… ¿œ¿∫ æ¯∞⁄¡ˆ∏∏ ø°∑Ø πÊ¡ˆøÎ
				if (m_pClientList[iClientH]->m_iSuperAttackLeft < 0) m_pClientList[iClientH]->m_iSuperAttackLeft = 0;
			}

			SendEventToNearClient_TypeA((short)iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTATTACK, dX, dY, wType);
		}
		else if (iRet == 2) SendObjectMotionRejectMsg(iClientH);
		// v2.171
		bCheckClientAttackFrequency(iClientH, dwClientTime);
		break;

	case DEF_OBJECTGETITEM:
		iRet = iClientMotion_GetItem_Handler(iClientH, sX, sY, cDir);
		if (iRet == 1) {
			SendEventToNearClient_TypeA((short)iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTGETITEM, NULL, NULL, NULL);
		}
		else if (iRet == 2) SendObjectMotionRejectMsg(iClientH);
		break;

	case DEF_OBJECTMAGIC:
		iRet = iClientMotion_Magic_Handler(iClientH, sX, sY, cDir);
		if (iRet == 1) {
			// Casting«— ∏∂π˝ π¯»£(dX)∏¶ «‘≤≤ ∫∏≥Ω¥Ÿ.
			// v1.41 Casting«— «√∑π¿ÃæÓ¿« ∏∂π˝¥…∑¬ ºˆ¡ÿ¿ª «‘≤≤ ∫∏≥Ω¥Ÿ. 
			iTemp = 10;
			SendEventToNearClient_TypeA((short)iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTMAGIC, dX,(short) iTemp, NULL);
		}
		else if (iRet == 2) SendObjectMotionRejectMsg(iClientH);
	//	MagicEffect(iClientH);
		//bCheckClientMagicFrequency(iClientH, dwClientTime);
		break;

	default:
		break;
	}
}

int CGame::iClientMotion_Move_Handler(int iClientH, short sX, short sY, char cDir, BOOL bIsRun)
{
 char  * cp, cData[3000];
 class CTile * pTile;
 DWORD * dwp, dwTime;
 WORD  * wp, wObjectID;
 short * sp, dX, dY, sDOtype;
 int   * ip, iRet, iSize, iDamage, iTemp, iTemp2;
 BOOL  bRet;

	if (m_pClientList[iClientH] == NULL) return 0;
	if ((cDir <= 0) || (cDir > 8))       return 0;
	if (m_pClientList[iClientH]->m_bIsKilled == TRUE) return 0;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return 0;
	
	// ¡À«•∞° ¿œƒ°«œ¡ˆ æ ¥¬ ∏Ì∑…¿∫ π´Ω√«—¥Ÿ. Reject∏ﬁΩ√¡ˆ∏¶ πﬁ±‚ ¿Ã¿¸ø° ¿¸º€µ» ∏ﬁΩ√¡ˆµÈ¿Ã¥Ÿ.
	if ((sX != m_pClientList[iClientH]->m_sX) || (sY != m_pClientList[iClientH]->m_sY)) return 2;
	
	dwTime = timeGetTime();
	m_pClientList[iClientH]->m_dwLastActionTime = dwTime;
	
#ifndef NO_MSGSPEEDCHECK
	if (bIsRun == FALSE) {
		m_pClientList[iClientH]->m_iMoveMsgRecvCount++;
		// Crusade º”µµ ¡∂¿€ √º≈©
		if (m_pClientList[iClientH]->m_iMoveMsgRecvCount >= 7) {
			if (m_pClientList[iClientH]->m_dwMoveLAT != 0) {
				// 7π¯ øÚ¡˜¿Œ ∞ÊøÏ √÷º“ º“ø‰ Ω√∞£¿∫ 72*8*7 = 4032ms. «„øÎ ø¿¬˜ 3000ms
				if ((dwTime - m_pClientList[iClientH]->m_dwMoveLAT) < (72*8*7 -3000)) {
					DeleteClient(iClientH, TRUE, TRUE);
					return 0;
				}
			}
			m_pClientList[iClientH]->m_dwMoveLAT = dwTime;
			m_pClientList[iClientH]->m_iMoveMsgRecvCount = 0;
		}
	}
	else {
		m_pClientList[iClientH]->m_iRunMsgRecvCount++;
		// Crusade º”µµ ¡∂¿€ √º≈©
		if (m_pClientList[iClientH]->m_iRunMsgRecvCount >= 7) {
			if (m_pClientList[iClientH]->m_dwRunLAT != 0) {
				// 7π¯ ¥ﬁ∏∞ ∞ÊøÏ √÷º“ º“ø‰ Ω√∞£¿∫ 43*8*7 = 2408ms. «„øÎ ø¿¬˜ 1500ms
				if ((dwTime - m_pClientList[iClientH]->m_dwRunLAT) < (43*8*7 -1500)) {
					DeleteClient(iClientH, TRUE, TRUE);
					return 0;
				}
			}
			m_pClientList[iClientH]->m_dwRunLAT	= dwTime;
			m_pClientList[iClientH]->m_iRunMsgRecvCount = 0;
		}
	}
#endif
	
	// v1.432-2 ∏  ºΩ≈Õ ¡§∫∏∏¶ ∞ªΩ≈«—¥Ÿ. 
	int iStX, iStY;
	if (m_pMapList[m_pClientList[iClientH]->m_cMapIndex] != NULL) {
		iStX = m_pClientList[iClientH]->m_sX / 20;
		iStY = m_pClientList[iClientH]->m_sY / 20;
		m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_stTempSectorInfo[iStX][iStY].iPlayerActivity++;
		
		switch (m_pClientList[iClientH]->m_cSide) {
		case 0: m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_stTempSectorInfo[iStX][iStY].iNeutralActivity++; break;
		case 1: m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_stTempSectorInfo[iStX][iStY].iAresdenActivity++; break;
		case 2: m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_stTempSectorInfo[iStX][iStY].iElvineActivity++;  break;
		}
	}
	
	// Ω∫≈≥¿« ªÁøÎªÛ≈¬∏¶ ∏µŒ π´»ø»≠ «—¥Ÿ.
	ClearSkillUsingStatus(iClientH);
	
	dX = m_pClientList[iClientH]->m_sX;
	dY = m_pClientList[iClientH]->m_sY;

	switch (cDir) {
	case 1:	dY--; break;
	case 2:	dX++; dY--;	break;
	case 3:	dX++; break;
	case 4:	dX++; dY++;	break;
	case 5: dY++; break;
	case 6:	dX--; dY++;	break;
	case 7:	dX--; break;
	case 8:	dX--; dY--;	break;
	}

/*	class CItem * pTopItem; // 2.172
	//pTopItem = 0;
	pTopItem = new class CItem;
*/
	bRet = m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->bGetMoveable(dX, dY, &sDOtype/*, pTopItem*/); // v2.172
	
	// ¿Ãµø ∫“¥… ªÛ≈¬∂Û∏È
	if (m_pClientList[iClientH]->m_cMagicEffectStatus[ DEF_MAGICTYPE_HOLDOBJECT ] != 0)
		bRet = FALSE;
  
	if (bRet == TRUE) {

		// Quest ø©∫Œ∏¶ ∆«¥‹«—¥Ÿ.
		if (m_pClientList[iClientH]->m_iQuest != NULL) _bCheckIsQuestCompleted(iClientH);

		// ¿Ãµø¿Ã ∞°¥…«œ¥Ÿ. ∞˙∞≈¿« ¿ßƒ°ø°º≠ ¡ˆøÓ¥Ÿ.
		// «⁄µÈ∞™¿Ã ¿œƒ°«œ∏È ClearOwnerø°º≠ DeadOwnerµµ ªË¡¶«—¥Ÿ.
		m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->ClearOwner(1, iClientH, DEF_OWNERTYPE_PLAYER, m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY);

		m_pClientList[iClientH]->m_sX   = dX;
		m_pClientList[iClientH]->m_sY   = dY;
		m_pClientList[iClientH]->m_cDir = cDir;
		// ªı ¿ßƒ°ø° «•Ω√«—¥Ÿ. 
		m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->SetOwner((short)iClientH,
			                                                       DEF_OWNERTYPE_PLAYER,
																   dX, dY);

		//v1.4 πŸ¥⁄ø° Ω∫∆ƒ¿Ã≈©∞° ±Ú∑¡ ¿÷¥Ÿ∏È »ø∞˙∏¶ ∞ËªÍ«—¥Ÿ. 
		if (sDOtype == DEF_DYNAMICOBJECT_SPIKE) {
			if ((m_pClientList[iClientH]->m_bIsNeutral == TRUE) && ((m_pClientList[iClientH]->m_sAppr2 & 0xF000) == 0)) {
				// ¡ﬂ∏≥¿Ã∞Ì ∆Ú»≠∏µÂ∏È ¥ÎπÃ¡ˆ∏¶ æÚ¡ˆ æ ¥¬¥Ÿ.
			}
			else {
				iDamage = iDice(2,4);
				// v2.17 2002-8-2 øÓøµ¿⁄∞° æ∆¥œ∏È Ω∫∆ƒ¿Ã≈©∑˘ø° ø°≥ ¡ˆ∞° ¥‹¥Ÿ.
				if (m_pClientList[iClientH]->m_iAdminUserLevel == 0 )
					m_pClientList[iClientH]->m_iHP -= iDamage;
			}
		}

		if (m_pClientList[iClientH]->m_iHP <= 0) m_pClientList[iClientH]->m_iHP = 0;
		
		dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
		*dwp = MSGID_RESPONSE_MOTION;
		wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
		*wp  = DEF_OBJECTMOVE_CONFIRM;
		
		cp = (char *)(cData + DEF_INDEX2_MSGTYPE+2);
		
		sp  = (short *)cp;
		*sp = (short)(dX - 10); 
		cp += 2;
		
		sp  = (short *)cp;
		*sp = (short)(dY - 7); 
		cp += 2;
		
		*cp = cDir;
		cp++;
		
		if (bIsRun == TRUE) {// Staminar ∞®º“ƒ° ¿‘∑¬ 
			if (m_pClientList[iClientH]->m_iSP > 0) {
				*cp = 0; // 1
				//v1.42 
				if (m_pClientList[iClientH]->m_iTimeLeft_FirmStaminar == 0) {
					m_pClientList[iClientH]->m_iSP--;
					*cp = 1;
				}
			}
			else {
				*cp = 0; // 1
				//v1.42 
				if (m_pClientList[iClientH]->m_iTimeLeft_FirmStaminar == 0) {
					m_pClientList[iClientH]->m_iSP--;
					*cp = 1;
				}
				if (m_pClientList[iClientH]->m_iSP < -10) {
					// HACKINGø° ¿««ÿ ≈¨∂Û¿Ãæ∆Æ¿« Staminar point∞° ∞Ì¡§µ«æÓ ∞Ëº” ∂€ºˆ ¿÷¥¬ ªÛ≈¬¿Œ µÌ«œ¥Ÿ. 
					// æÓ∂≤ ¡æ∑˘¿« ∆‰≥Œ∆º∞° « ø‰«œ¥Ÿ.
					m_pClientList[iClientH]->m_iSP = 0;
					DeleteClient(iClientH, TRUE, TRUE);
					return 0;
				}
			}
		}
		else *cp = 0;
		cp++;
		
		//v1.3 «ˆ¿Á µÛ∞Ì ¿÷¥¬ ∫Œ∫–¿« ¡°∑…ø©∫Œ∏¶ ∫∏≥ª¡ÿ¥Ÿ.
		pTile = (class CTile *)(m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_pTile + dX + dY*m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_sSizeY);
		*cp = (char)pTile->m_iOccupyStatus;
		cp++;
		
		// v1.4 ¿ÃµøΩ√ø° HP∞° ∂≥æÓ¡ˆ¥¬ ¡ˆø™ø° ¥Î∫Ò«ÿº≠ HP∞™¿ª ∫∏≥ª¡ÿ¥Ÿ.
		ip = (int *)cp;
		*ip = m_pClientList[iClientH]->m_iHP;
		cp += 4;
		
		iSize = iComposeMoveMapData((short)(dX - 10), (short)(dY - 7), iClientH, cDir, cp);
		
		iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, iSize + 12 + 1 + 4);
		switch (iRet) {
		case DEF_XSOCKEVENT_QUENEFULL:
		case DEF_XSOCKEVENT_SOCKETERROR:
		case DEF_XSOCKEVENT_CRITICALERROR:
		case DEF_XSOCKEVENT_SOCKETCLOSED:
			// ∏ﬁΩ√¡ˆ∏¶ ∫∏≥æ∂ß ø°∑Ø∞° πﬂª˝«ﬂ¥Ÿ∏È ¡¶∞≈«—¥Ÿ.
			DeleteClient(iClientH, TRUE, TRUE);
			return 0;
		}
	}
	else {
		m_pClientList[iClientH]->m_bIsMoveBlocked = TRUE; // v2.171
		// ¿Ãµø¿Ã ∫“∞°¥…«œ¥Ÿ. 
		dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
		*dwp = MSGID_RESPONSE_MOTION;
		wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
		*wp  = DEF_OBJECTMOVE_REJECT;

		wObjectID = (WORD) iClientH;

		cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);

		wp  = (WORD *)cp;
		*wp = wObjectID;			// ObjectID
		cp += 2;
		sp  = (short *)cp;
		sX  = m_pClientList[wObjectID]->m_sX;
		*sp = sX;
		cp += 2;
		sp  = (short *)cp;
		sY  = m_pClientList[wObjectID]->m_sY;
		*sp = sY;
		cp += 2;
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sType;
		cp += 2;
		*cp = m_pClientList[wObjectID]->m_cDir;
		cp++;
		memcpy(cp, m_pClientList[wObjectID]->m_cCharName, 10);
		cp += 10;
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sAppr1;
		cp += 2;
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sAppr2;
		cp += 2;
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sAppr3;
		cp += 2;
		sp  = (short *)cp;
		*sp = m_pClientList[wObjectID]->m_sAppr4;
		cp += 2;
		ip  = (int *)cp; // v1.4
		*ip = m_pClientList[wObjectID]->m_iApprColor;
		cp+= 4;

		// Status
		ip  = (int *)cp;
		iTemp = m_pClientList[wObjectID]->m_iStatus;
		iTemp = 0x0FFFFFFF & iTemp;
		iTemp2 = iGetPlayerABSStatus(wObjectID, iClientH);
		iTemp  = (iTemp | (iTemp2 << 28));
		*ip = iTemp;
		cp += 4;

		iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 42); // v2.23 // v1.4 
		
		switch (iRet) {
		case DEF_XSOCKEVENT_QUENEFULL:
		case DEF_XSOCKEVENT_SOCKETERROR:
		case DEF_XSOCKEVENT_CRITICALERROR:
		case DEF_XSOCKEVENT_SOCKETCLOSED:
			DeleteClient(iClientH, TRUE, TRUE);
			return 0;
		}
		return 0;
	}
	RefreshPartyCoords(iClientH);
	return 1;
}
void CGame::HeldenianStarter() 
{
 SYSTEMTIME SysTime;
 int i;

	if (m_bIsCrusadeMode == TRUE) return;
	if (m_bIsHeldenianMode == TRUE) return;
	if (m_bIsHeldenianStarter == FALSE) return;
	if (m_bIsApocalypseMode == TRUE) GlobalEndApocalypseMode();

	GetLocalTime(&SysTime);
	
	for (i = 0; i < DEF_MAXSCHEDULE; i++)
	if (m_stCrusadeWarSchedule[i].iDay == SysTime.wDayOfWeek) {	
		m_cHeldenianModeType = i+1;
		bUpdateHeldenianStatus(-1);		
		GlobalStartHeldenianMode();
		return;
	
	}
}

void CGame::ApocalypseStarter() 
{
 SYSTEMTIME SysTime;


	if (m_bIsCrusadeMode == TRUE) return;
	if (m_bIsHeldenianMode == TRUE) return;
	if (m_bIsApocalypseMode == TRUE) return;
	if (m_bIsApocalypseStarter == FALSE) return;

	GetLocalTime(&SysTime);
	
	if ((m_stApocalypseSchedule.iDay <= SysTime.wDayOfWeek)){
		if ((m_stApocalypseSchedule.iDay == SysTime.wDayOfWeek)&&(m_stApocalypseSchedule.iHour <= SysTime.wHour) && 
            (m_stApocalypseSchedule.iMinute <= SysTime.wMinute)) {
			// ∏ÆΩ∫∆Æø°º≠ √£æ“¥Ÿ. ¿¸∏È¿¸ Ω√¿€ 			
			GlobalStartApocalypseMode();
			return;
		}
		}
	}
void CGame::HeldenianFightStarter() 
{
	
	if (m_bIsHeldenianStarter == FALSE) return;
	if (m_bIsHeldenianMode == FALSE) return;
	if (bHeldenianFight == TRUE) return;
	if (m_dwHeldenianFTime == -1) return;
	
	if (m_dwHeldenianFTime <= timeGetTime()) HeldenianFight(-1);

	
	
}
void CGame::KillCrusadeObjects()
{
 int i;
	for (i = 1; i < DEF_MAXNPCS; i++)
	if (m_pNpcList[i] != NULL) {
		switch (m_pNpcList[i]->m_sType) {
		case 43:
		case 44:
		case 45:
		case 46:
		case 47:
		case 51:
			NpcKilledHandler(NULL, NULL, i, 0);
			break;
		}
	}
}
void CGame::AdminOrder_Portal(int iClientH, char * pData, DWORD dwMsgSize)
{
 char   seps[] = "= \t\n";
 char   * token, cBuff[256];
 class  CStrTok * pStrTok;
 BOOL   bFlag;
 DWORD dwTime = timeGetTime();
 int PortalNum = 1;

	if (m_pClientList[iClientH] == NULL) return;
	if ((dwMsgSize)	<= 0) return;

	if (m_pClientList[iClientH]->m_iAdminUserLevel < 3) {
		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
		return;
	}

	if (PortalAbility[1] == TRUE)
	{
		if (PortalAbility[2] == TRUE)
		{
			if (LastPortal == 2)
				PortalNum = 1;
			else
				PortalNum = 2;
		}
		else
			PortalNum = 2;
	}
	else
		PortalNum = 1;

	LastPortal = PortalNum;

	ZeroMemory(cBuff, sizeof(cBuff));
	memcpy(cBuff, pData, dwMsgSize);

	pStrTok = new class CStrTok(cBuff, seps);
	token = pStrTok->pGet();
	
	//Indico el nombre del mapa
	token = pStrTok->pGet();
	if (token != NULL) {
		ZeroMemory(Portal_MapName[PortalNum], sizeof(Portal_MapName[PortalNum]));
		strcpy(Portal_MapName[PortalNum], token);
	}

	//Indico las coords de destino
	token = pStrTok->pGet();
	if (token != NULL) {
		dest_dx_portal[PortalNum] = atoi(token);
	}
	else dest_dx_portal[PortalNum] = NULL;

	token = pStrTok->pGet();
	if (token != NULL) {
		dest_dy_portal[PortalNum] = atoi(token);
	}
	else dest_dy_portal[PortalNum] = NULL;

	//Indico El tiempo de apertura del portal
	token = pStrTok->pGet();
	if (token != NULL) {
		dw_TimeOpenPortal[PortalNum] = atoi(token);
		if (dw_TimeOpenPortal[PortalNum] < 60)
			dw_TimeOpenPortal[PortalNum] *= 60000;
		else
			dw_TimeOpenPortal[PortalNum] *= 1000;
	}
	else dw_TimeOpenPortal[PortalNum] = 1000000;

	//Indico el nivel max del portal
	token = pStrTok->pGet();
	if (token != NULL) {
		LevelLimit_portal[PortalNum] = atoi(token);
	}
	else LevelLimit_portal[PortalNum] = 999;

	//Indico la cantidad maxima de players
	token = pStrTok->pGet();
	if (token != NULL) {
		MaxPlayer_portal[PortalNum] = atoi(token);
	}
	else MaxPlayer_portal[PortalNum] = 2000;

	bFlag = FALSE;
	if (strcmp("2ndmiddle", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("abaddon", Portal_MapName[PortalNum]) == 0) bFlag = TRUE; 
	if (strcmp("arebrk11", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("arebrk12", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("arebrk21", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("arebrk22", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("arefarm", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("arejail", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("aremidl", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("aremidr", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("aresden", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("aresdend1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("areuni", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("arewrhus", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("bisle", Portal_MapName[PortalNum]) == 0)   bFlag = TRUE;
	if (strcmp("bsmith_1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("bsmith_1f", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("bsmith_2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("bsmith_2f", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("BtField", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("cath_1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("cath_2", Portal_MapName[PortalNum]) == 0)      bFlag = TRUE;
	if (strcmp("cityhall_1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("cityhall_2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("CmdHall_1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("CmdHall_2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("default", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("dglv2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("dglv3", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("dglv4", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("druncncity", Portal_MapName[PortalNum]) == 0) bFlag = TRUE; 
	if (strcmp("elvbrk11", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("elvbrk12", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("elvbrk21", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("elvbrk22", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("elvfarm", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("elvine", Portal_MapName[PortalNum]) == 0)  bFlag = TRUE;
	if (strcmp("elvined1", Portal_MapName[PortalNum]) == 0)    bFlag = TRUE;
	if (strcmp("elvjail", Portal_MapName[PortalNum]) == 0)    bFlag = TRUE;
	if (strcmp("elvmidl", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("elvmidr", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("elvuni", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("elvwrhus", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone3", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone4", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone5", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone6", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone7", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone8", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone9", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("fightzone10", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("gldhall_1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("gldhall_2", Portal_MapName[PortalNum]) == 0)   bFlag = TRUE;
	if (strcmp("GodH", Portal_MapName[PortalNum]) == 0)   bFlag = TRUE;
	if (strcmp("gshop_1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("gshop_1f", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("gshop_2", Portal_MapName[PortalNum]) == 0)     bFlag = TRUE;
	if (strcmp("gshop_2f", Portal_MapName[PortalNum]) == 0)     bFlag = TRUE;
	if (strcmp("HRampart", Portal_MapName[PortalNum]) == 0)     bFlag = TRUE;
	if (strcmp("huntzone1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("huntzone2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("huntzone3", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("huntzone4", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("icebound", Portal_MapName[PortalNum]) == 0) bFlag = TRUE; 
	if (strcmp("inferniaA", Portal_MapName[PortalNum]) == 0) bFlag = TRUE; 
	if (strcmp("inferniaB", Portal_MapName[PortalNum]) == 0) bFlag = TRUE; 
	if (strcmp("maze", Portal_MapName[PortalNum]) == 0) bFlag = TRUE; 
	if (strcmp("middled1n", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("middled1x", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("middleland", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("penalty", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("procella", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("resurr1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("resurr2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("toh1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("toh2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("toh3", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("wrhus_1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("wrhus_1f", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("wrhus_2", Portal_MapName[PortalNum]) == 0)     bFlag = TRUE;
	if (strcmp("wrhus_2f", Portal_MapName[PortalNum]) == 0)     bFlag = TRUE;
	if (strcmp("wzdtwr_1", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("wzdtwr_2", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("Test", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("GMMap", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("Whouse", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("dv", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	if (strcmp("Volcano", Portal_MapName[PortalNum]) == 0) bFlag = TRUE;
	
	//si el mapa es correcto
	if (bFlag == TRUE)
	{	
		if ((dest_dx_portal[PortalNum] != NULL) && (dest_dy_portal[PortalNum] != NULL))
		{
			//Verifico las coords del GM y le agrego +2 de la posicion X, para que quede al lado
			ini_dx_portal[PortalNum] = m_pClientList[iClientH]->m_sX +2;
			ini_dy_portal[PortalNum] = m_pClientList[iClientH]->m_sY;
			ZeroMemory(Portal_Init[PortalNum], sizeof(Portal_Init[PortalNum]));
			strcpy(Portal_Init[PortalNum], m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cName);
			PortalPlayers[PortalNum] = 0;

			dw_TimePortal[PortalNum] = dwTime;
			PortalAbility[PortalNum] = TRUE;

			char cMsg[40];

			wsprintf(cMsg, "Portal N™ %d abierto", PortalNum);
			ShowClientMsg(iClientH, cMsg);
		}
	}	
   	
	delete pStrTok;
	return;
}
void CGame::ClosePortal(int PortalNum)
{
	int i;
	
	PortalAbility[PortalNum] = FALSE;

	if (PortalNum == 1)
	{
		for (i = 0; i < DEF_MAXCLIENTS; i++)
			SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATECLOSE, ini_dx_portal[PortalNum], ini_dy_portal[PortalNum], NULL, m_pClientList[i]->m_cMapName);
	}
	else
	{
		for (i = 0; i < DEF_MAXCLIENTS; i++)
			SendNotifyMsg(NULL, i, DEF_NOTIFY_APOCGATECLOSE2, ini_dx_portal[PortalNum], ini_dy_portal[PortalNum], NULL, m_pClientList[i]->m_cMapName);
	}
}

void CGame::LocalStartRushNetMode()
{
 int i;

	if (m_bIsRushNetMode == TRUE) return;
	m_bIsRushNetMode = TRUE;

	m_iHeldenianElvineLeftTower = 0;
	m_iHeldenianAresdenLeftTower = 0;
	RushWinner = 0;

	for (i = 0; i < DEF_MAXMAPS; i++)
	{	
		if (m_pMapList[i] != NULL) 
		{
			if (strcmp(m_pMapList[i]->m_cName,"elvine") == 0)
				m_pMapList[i]->m_iMaximumObject = 0; 
			if (strcmp(m_pMapList[i]->m_cName,"aresden") == 0) 
				m_pMapList[i]->m_iMaximumObject = 0;	
		}	
	}

	for (i = 1; i < DEF_MAXCLIENTS; i++)
	{
		if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE))
			SendNotifyMsg(NULL, i, DEF_NOTIFY_RUSH, 10, NULL, NULL, NULL, NULL);
	}

	CreateRushStructures();
	
	PutLogList("(!)Rush Net Mode ON.");
}

void CGame::LocalEndRushNetMode(int Loser)
{
	int i;
	SYSTEMTIME SystemTime;
	GetLocalTime(&SystemTime);

 	if (m_bIsRushNetMode == FALSE) return;
	m_bIsRushNetMode = FALSE;

	PutLogList("(!)Rush Mode OFF.");

	RemoveRushNetStructures();

	m_iHeldenianAresdenLeftTower = -1;
	m_iHeldenianElvineLeftTower = -1;

	UpdateRushNet(0);

	for (i = 0; i < DEF_MAXMAPS; i++)
	{	
		if (m_pMapList[i] != NULL) 
		{
			if (strcmp(m_pMapList[i]->m_cName,"elvine") == 0)
				m_pMapList[i]->m_iMaximumObject = 900; 
			if (strcmp(m_pMapList[i]->m_cName,"aresden") == 0) 
				m_pMapList[i]->m_iMaximumObject = 900;	
		}	
	}
	
	if (Loser == 1)
		RushWinner = 2;
	else RushWinner = 1;

	for (i = 1; i < DEF_MAXCLIENTS; i++)
	{
		if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE)) 
			SendNotifyMsg(NULL, i, DEF_NOTIFY_RUSH, Loser, NULL, NULL, NULL, NULL);
	}
	CreateRushGUID(RushWinner);
	HeldenianType2 = 0;
	CreateHeldenianGUID(0, RushWinner);
	bReadHeldenianGUIDFile("GameData\\HeldenianGUID.txt");
	
}

void CGame::UpdateRushNet(int Structure)
{
	int i, z;
	
	if (Structure == 1)
		z = 3;
	else if (Structure == 2)
		z = 4;

	if (Structure != 0)
		for (i = 1; i < DEF_MAXCLIENTS; i++)
			if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE)) 
				SendNotifyMsg(NULL, i, DEF_NOTIFY_RUSH, z, NULL, NULL, NULL, NULL);

	for (i = 1; i < DEF_MAXCLIENTS; i++)
		if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE)) 
				SendNotifyMsg(NULL, i, DEF_NOTIFY_HELDENIANCOUNT, m_iHeldenianAresdenLeftTower, m_iHeldenianElvineLeftTower, NULL, NULL, NULL, NULL);
}
void CGame::RemoveRushNetStructures()
{
	register int i;
	for (i = 0 ; i < DEF_MAXNPCS; i++)
	if (m_pNpcList[i] != NULL) {
		switch (m_pNpcList[i]->m_sType) {
			case 35:
			case 39:
			case 87:
			case 89:
			case 92:
				NpcBehavior_Dead(i);
				break;
		}
	}	
}

void CGame::SendHpReliquia()
{
	int i, z, ReliquiaAresden2, ReliquiaElvine2, ReliquiaAresden, ReliquiaElvine;

	for (z = 1; z < DEF_MAXNPCS; z++) 
		if (m_pNpcList[z] != NULL) 
		{
			if (memcmp(m_pNpcList[z]->m_cNpcName, "Reliquia-a", 11) == 0) 
				ReliquiaAresden2 = m_pNpcList[z]->m_iHP;
			else if (memcmp(m_pNpcList[z]->m_cNpcName, "Reliquia-e", 10) == 0) 
				ReliquiaElvine2 = m_pNpcList[z]->m_iHP;
		}
							
	ReliquiaAresden = (ReliquiaAresden2*100)/50000;
	ReliquiaElvine = (ReliquiaElvine2*100)/50000;

	if ((ReliquiaAresden > 0) && (ReliquiaElvine > 0))
		for (i = 1; i < DEF_MAXCLIENTS; i++)
			if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE)) 
				SendNotifyMsg(NULL, i, DEF_SEND_HPRELIQUIA, ReliquiaAresden, ReliquiaElvine, NULL, NULL, NULL, NULL);
}

BOOL CGame::bReadRushStructureConfigFile(char * cFn)
{
 FILE * pFile;
 HANDLE hFile;
 DWORD  dwFileSize;
 char * cp, * token, cReadModeA, cReadModeB;
 char seps[] = "= \t\n";
 int   iIndex;
 class CStrTok * pStrTok;

	cReadModeA = 0;
	cReadModeB = 0;

	hFile = CreateFile(cFn, GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, NULL);
	dwFileSize = GetFileSize(hFile, NULL);
	if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);

	pFile = fopen(cFn, "rt");
	if (pFile == NULL) {
		return FALSE;
	}
	else {
		PutLogList("(!) Reading rush configuration file...");
		cp = new char[dwFileSize+2];
		ZeroMemory(cp, dwFileSize+2);
		fread(cp, dwFileSize, 1, pFile);

		iIndex = 0;
		pStrTok = new class CStrTok(cp, seps);
		token = pStrTok->pGet();
		while( token != NULL ) {
			if (cReadModeA != 0) {
				switch (cReadModeA) {
				case 1:
					switch (cReadModeB) {
					case 1:
						if (_bGetIsStringIsNumber(token) == FALSE) {
							PutLogList("(!!!) CRITICAL ERROR!  rush configuration file error - Wrong Data format(1).");
							delete cp;
							delete pStrTok;
							return FALSE;
						}
						iIndex = atoi(token);

						if (m_stRushStructures[iIndex].cType != NULL) {
							PutLogList("(!!!) CRITICAL ERROR!  rush configuration file error - Duplicate potion number.");
							delete cp;
							delete pStrTok;
							return FALSE;
						}
						
						cReadModeB = 2;
						break;

					case 2:
						ZeroMemory(m_stRushStructures[iIndex].cMapName, sizeof(m_stRushStructures[iIndex].cMapName));
						memcpy(m_stRushStructures[iIndex].cMapName, token, strlen(token));
						cReadModeB = 3;
						break;

					
					case 3:
						if (_bGetIsStringIsNumber(token) == FALSE) {
							PutLogList("(!!!) CRITICAL ERROR!  rush configuration file error - Wrong Data format.");
							delete cp;
							delete pStrTok;
							return FALSE;
						}
						m_stRushStructures[iIndex].cType = atoi(token);
						cReadModeB = 4;
						break; 

					case 4:
						if (_bGetIsStringIsNumber(token) == FALSE) {
							PutLogList("(!!!) CRITICAL ERROR!  rush configuration file error - Wrong Data format.");
							delete cp;
							delete pStrTok;
							return FALSE;
						}
						m_stRushStructures[iIndex].dX = atoi(token);
						cReadModeB = 5;
						break;
	
					case 5:
						if (_bGetIsStringIsNumber(token) == FALSE) {
							PutLogList("(!!!) CRITICAL ERROR!  rush configuration file error - Wrong Data format.");
							delete cp;
							delete pStrTok;
							return FALSE;
						}
						m_stRushStructures[iIndex].dY = atoi(token);
						cReadModeA = 0;
						cReadModeB = 0;
						break;
					}
					break;

				default: 
					break;
				}
			}
			else {
				if (memcmp(token, "rush-structure", 14) == 0) {
					cReadModeA = 1;
					cReadModeB = 1;
				}
			}
			token = pStrTok->pGet();
		}	

		delete pStrTok;
		delete []cp;

		if ((cReadModeA != 0) || (cReadModeB != 0)) {
			PutLogList("(!!!) CRITICAL ERROR! Rush Structure configuration file contents error!");
			return FALSE;
		}
	}
	
	if (pFile != NULL) fclose(pFile);
	return TRUE;
}

void CGame::CreateRushStructures()
{
 int i, z, tX, tY, iNamingValue;
 char cName[6], cNpcName[21], cNpcWayPoint[11];

	ZeroMemory(cName, sizeof(cName));
	ZeroMemory(cNpcName, sizeof(cNpcName));
	ZeroMemory(cNpcWayPoint, sizeof(cNpcWayPoint));

	for (i = 0; i < MAX_RUSHSTRUCTURES; i++) 
		if (m_stRushStructures[i].cType != NULL) {
		for (z = 0; z < DEF_MAXMAPS; z++)
		if ((m_pMapList[z] != NULL) && (strcmp(m_pMapList[z]->m_cName, m_stRushStructures[i].cMapName) == 0)) {
			iNamingValue = m_pMapList[z]->iGetEmptyNamingValue();
			if (iNamingValue == -1) {
			}
			else {
				wsprintf(cName, "XX%d", iNamingValue);
				cName[0] = '_';
				cName[1] = z+65;
				
				switch (m_stRushStructures[i].cType) {
					case 39:
						if (strcmp(m_pMapList[z]->m_cName, "aresden") == 0)
							strcpy(cNpcName, "DT-Aresden");
						else if (strcmp(m_pMapList[z]->m_cName, "elvine") == 0)
							strcpy(cNpcName, "DT-Elvine");
						break;

					case 87:
						if (strcmp(m_pMapList[z]->m_cName, "aresden") == 0)
							strcpy(cNpcName, "CT-Aresden");
						else if (strcmp(m_pMapList[z]->m_cName, "elvine") == 0)
							strcpy(cNpcName, "CT-Elvine");
						break;

					case 89:
						if (strcmp(m_pMapList[z]->m_cName, "aresden") == 0)
							strcpy(cNpcName, "AGC-Aresden");
						else if (strcmp(m_pMapList[z]->m_cName, "elvine") == 0)
							strcpy(cNpcName, "AGC-Elvine");
						break;

					case 92:
						if (strcmp(m_pMapList[z]->m_cName, "aresden") == 0)
							strcpy(cNpcName, "Reliquia-a");
						else if (strcmp(m_pMapList[z]->m_cName, "elvine") == 0)
							strcpy(cNpcName, "Reliquia-e");
						break;

					default: 
						strcpy(cNpcName, m_pNpcConfigList[m_stRushStructures[i].cType]->m_cNpcName); 
						break;
				}

				tX = (int)m_stRushStructures[i].dX;
				tY = (int)m_stRushStructures[i].dY;
				if (bCreateNewNpc(cNpcName, cName, m_pMapList[z]->m_cName, 0, 0, DEF_MOVETYPE_RANDOM, &tX, &tY, cNpcWayPoint, NULL, NULL, -1, FALSE) == FALSE) {
					m_pMapList[z]->SetNamingValueEmpty(iNamingValue);
				} 
				else {
					if ((memcmp(cNpcName, "AGC-Aresden", 11) == 0) || (memcmp(cNpcName, "CT-Aresden", 10) == 0) || (memcmp(cNpcName, "DT-Aresden", 10) == 0))
						m_iHeldenianAresdenLeftTower += 1;
					else if ((memcmp(cNpcName, "AGC-Elvine", 10) == 0) || (memcmp(cNpcName, "CT-Elvine", 9) == 0) || (memcmp(cNpcName, "DT-Elvine", 9) == 0))
						m_iHeldenianElvineLeftTower += 1;

					wsprintf(G_cTxt, "(!) Creating Rush Structure(%s) at %s(%d, %d)", cNpcName, m_stRushStructures[i].cMapName, tX, tY);
					PutLogList(G_cTxt);
				}
			}
		}
	}
	UpdateRushNet(0);
}

void CGame::CreateRushGUID(int iWinnerSide) 
{ 
	char * cp, cTxt[256], cFn[256], cTemp[1024]; 
	FILE * pFile; 

	_mkdir("GameData"); 
	ZeroMemory(cFn, sizeof(cFn)); 
	strcat(cFn,"GameData"); 
	strcat(cFn,"\\"); 
	strcat(cFn,"\\"); 
	strcat(cFn,"RushGUID.Txt"); 

	pFile = fopen(cFn, "wt"); 
	if (pFile == NULL) { 
		wsprintf(cTxt, "(!) Cannot create RushGUID(%d) file", m_dwRushGUID); 
		PutLogList(cTxt); 
	} 
	else { 
		ZeroMemory(cTemp, sizeof(cTemp)); 

		ZeroMemory(cTxt, sizeof(cTxt)); 
		wsprintf(cTxt, "winner-side = %d\n", iWinnerSide); 
		strcat(cTemp, cTxt); 

		cp = (char *)cTemp; 
		fwrite(cp, strlen(cp), 1, pFile); 

		wsprintf(G_cTxt, "(_) file created - RushGUID. (Winner %d)", iWinnerSide); 
		PutLogList(G_cTxt); 
	} 
	if (pFile != NULL) fclose(pFile); 
} 

BOOL CGame::bReadRushGUIDFile(char * cFn) 
{ 
	FILE * pFile; 
	HANDLE hFile; 
	DWORD dwFileSize; 
	char * cp, * token, cReadMode; 
	char seps[] = "= \t\n"; 
	class CStrTok * pStrTok; 

	cReadMode = 0; 

	hFile = CreateFile(cFn, GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, NULL); 
	dwFileSize = GetFileSize(hFile, NULL); 
	if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile); 

	pFile = fopen(cFn, "rt"); 
	if (pFile == NULL) { 
		PutLogList("(!) Cannot open RushGUID file."); 
		return FALSE; 
	} 
	else { 
		PutLogList("(!) Reading RushGUID file..."); 
		cp = new char[dwFileSize+2]; 
		ZeroMemory(cp, dwFileSize+2); 
		fread(cp, dwFileSize, 1, pFile); 

		pStrTok = new class CStrTok(cp, seps); 
		token = pStrTok->pGet(); 

		while( token != NULL ) { 
			if (cReadMode != 0) { 
				switch (cReadMode) {
					case 1: 
						m_sLastHeldenianWinner = atoi(token); 
						wsprintf(G_cTxt, "(!) RushWinnerSide = %d", m_sLastHeldenianWinner); 
						PutLogList(G_cTxt); 
						cReadMode = 0; 
					break; 
				} 
			} 
			else { 
				if (memcmp(token, "winner-side", 11) == 0) cReadMode = 1; 
			} 
			token = pStrTok->pGet(); 
		} 

		delete pStrTok; 
		delete []cp; 
	} 
	if (pFile != NULL) fclose(pFile); 

	return TRUE; 
}
void CGame::AdminOrder_GetFightzoneTicket(int iClientH)
{
 int iReserveTime, iFightzoneTN, iFightzoneN;
 char cTemp[21];
 SYSTEMTIME SysTime;

	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bActivarComandos == FALSE) return;
	if (memcmp(m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cName, "fightzone", 9) == 0) {
		
		iReserveTime = m_pClientList[iClientH]->m_iReserveTime;
		GetLocalTime(&SysTime);
		m_pClientList[iClientH]->m_iReserveTime = SysTime.wMonth*10000 + SysTime.wDay*100 + (SysTime.wHour +3);  
		
		ZeroMemory(cTemp, sizeof(cTemp));
		strcpy(cTemp, (m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cName +9));
		iFightzoneN  = m_pClientList[iClientH]->m_iFightzoneNumber;
		iFightzoneTN = m_pClientList[iClientH]->m_iFightZoneTicketNumber;
		m_pClientList[iClientH]->m_iFightZoneTicketNumber = 10;
		m_pClientList[iClientH]->m_iFightzoneNumber = atoi(cTemp);
		
		GetFightzoneTicketHandler(iClientH);
		GetFightzoneTicketHandler(iClientH);
		GetFightzoneTicketHandler(iClientH);
		
		m_pClientList[iClientH]->m_iFightzoneNumber = iFightzoneN;
		m_pClientList[iClientH]->m_iFightZoneTicketNumber = iFightzoneTN;
		m_pClientList[iClientH]->m_iReserveTime = iReserveTime;
	}
	else {
		iReserveTime = m_pClientList[iClientH]->m_iReserveTime;
		GetLocalTime(&SysTime);
		m_pClientList[iClientH]->m_iReserveTime = SysTime.wMonth*10000 + SysTime.wDay*100 + (SysTime.wHour +2);  
		
		ZeroMemory(cTemp, sizeof(cTemp));
		strcpy(cTemp, (m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cName +9));
		iFightzoneN  = m_pClientList[iClientH]->m_iFightzoneNumber;
		iFightzoneTN = m_pClientList[iClientH]->m_iFightZoneTicketNumber;
		m_pClientList[iClientH]->m_iFightZoneTicketNumber = 10;
		m_pClientList[iClientH]->m_iFightzoneNumber = 1;
		
		GetFightzoneTicketHandler(iClientH);
		GetFightzoneTicketHandler(iClientH);
		GetFightzoneTicketHandler(iClientH);

		m_pClientList[iClientH]->m_iFightzoneNumber = iFightzoneN;
		m_pClientList[iClientH]->m_iFightZoneTicketNumber = iFightzoneTN;
		m_pClientList[iClientH]->m_iReserveTime = iReserveTime;
	}
}




BOOL CGame::bCheckAndConvertPlusWeaponItem(int iClientH, int iItemIndex)
{
	// ¿Ã æ∆¿Ã≈€¿Ã +1, +2 ¿Ã∏ß¿Ã ∫Ÿ¿∫ æ∆¿Ã≈€¿Ã∂Û∏È Attribute «√∑°±◊∑Œ ∆Øº∫ƒ°∏¶ ¿ÃµøΩ√≈∞∞Ì ¿œπ› æ∆¿Ã≈€¿∏∑Œ ∫Ø«¸Ω√≈≤¥Ÿ.
	if (m_pClientList[iClientH] == NULL) return FALSE;
	if (m_pClientList[iClientH]->m_pItemList[iItemIndex] == NULL) return FALSE;

	switch (m_pClientList[iClientH]->m_pItemList[iItemIndex]->m_sIDnum) {
	case 4:  // ¥‹∞À +1
	case 9:  // ºÓ∆Æ º“µÂ +1
	case 13: // ∏¡∞ÌΩ¥ +1
	case 16: // ±◊∂ÛµøÏΩ∫ +1
	case 18: // ∑’º“µÂ +1
	case 19: // ∑’º“µÂ +2
	case 21: // ø¢Ω∫ƒÆ∏Æπˆ +1
	case 24: // ºº¿Ãπˆ +1
	case 26: // Ω√πÃ≈∏ +1
	case 27: // Ω√πÃ≈∏ +2
	case 29: // ∆»ƒ°ø¬ +1
	case 30: // ∆»ƒ°ø¬ +2
	case 32: // ø°Ω∫≈Õ≈© +1
	case 33: // ø°Ω∫≈Õ≈© +2
	case 35: // ∑π¿Ã««æÓ +1
	case 36: // ∑π¿Ã««æÓ +2
	case 39: // ∫Í∑ŒµÂ º“µÂ +1
	case 40: // ∫Í∑ŒµÂ º“µÂ +2
	case 43: // πŸΩ∫≈∏µÂ º“µÂ +1
	case 44: // πŸΩ∫≈∏µÂ º“µÂ +2
	case 47: // ≈¨∑π¿Ã∏æÓ +1
	case 48: // ≈¨∑π¿Ã∏æÓ +2
	case 51: // ±◊∑π¿Ã∆Æ º“µÂ +1
	case 52: // ±◊∑π¿Ã∆Æ º“µÂ +2
	case 55: // «√∑•πˆ±◊ +1
	case 56: // «√∑•πˆ±◊ +2
	case 60: // ∂Û¿Ã∆Æ æ◊Ω∫ +1
	case 61: // ∂Û¿Ã∆Æ æ◊Ω∫ +2
	case 63: // ≈‰∏∂»£≈© +1
	case 64: // ≈‰∏∂»£≈© +2
	case 66: // ªˆΩºæ◊Ω∫ +1
	case 67: // ªˆΩºæ◊Ω∫ +2
	case 69: // ¥ı∫Ìæ◊Ω∫ +1
	case 70: // ¥ı∫Ìæ◊Ω∫ +2
	case 72: // øˆæ◊Ω∫ +1
	case 73: // øˆæ◊Ω∫ +2
	
	case 580: // πË∆≤æ◊Ω∫ +1
	case 581: // πË∆≤æ◊Ω∫ +2
	case 582: // ºº¿Ãπˆ +2
		break;
	}
	return TRUE;
}

void CGame::RequestCreatePartyHandler(int iClientH)
{
 char *cp, cData[120];
 DWORD * dwp;
 WORD * wp;

	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;
	   	if (m_pClientList[iClientH]->m_iAdminUserLevel > 0&&m_pClientList[iClientH]->m_iAdminUserLevel < 3) return; // v2.23 22/04/06 15:24 AdminSecurity 
	
	if (m_pClientList[iClientH]->m_iPartyStatus != DEF_PARTYSTATUS_NULL) {
		// ∆ƒ∆º ªÛ≈¬∞° ¿ÃπÃ ¡∏¿Á«œ∏È ∆ƒ∆º∏¶ ∏∏µÈ ºˆ æ¯¥Ÿ.
		return;
	}

	m_pClientList[iClientH]->m_iPartyStatus = DEF_PARTYSTATUS_PROCESSING;

	// Gate Serverø° ∆ƒ∆º ª˝º∫»ƒ PartyID∏¶ æÀ∑¡¡Ÿ ∞Õ¿ª ø‰√ª«—¥Ÿ. 
	ZeroMemory(cData, sizeof(cData));
	cp = (char *)cData;

	dwp = (DWORD *)cp;
	*dwp = MSGID_PARTYOPERATION;
	cp += 4;
	wp = (WORD*)cp;
	*wp = 1; // 1, request
	cp += 2;

	wp = (WORD *)cp;
	*wp = iClientH;
	cp += 2;

	memcpy(cp, m_pClientList[iClientH]->m_cCharName, 10);
	cp += 10;

	SendMsgToGateServer(MSGID_PARTYOPERATION, iClientH, cData);

}



void CGame::PartyOperationResultHandler(char *pData)
{
 char * cp, cResult, cName[12];
 WORD * wp;
 int i, iClientH, iPartyID, iTotal;

	cp = (char *)(pData + 4);
	wp = (WORD *)cp;
	cp += 2;

	// ¿¿¥‰ ¡æ∑˘ø° µ˚∂Û √≥∏Æ 
	switch (*wp) {
	case 1: // ∆ƒ∆º ª˝º∫ ø‰√ªø° ¥Î«— ¿¿¥‰ 
		cResult = *cp;
		cp++;
		wp = (WORD *)cp;
		iClientH = (int)*wp;
		cp += 2;
		ZeroMemory(cName, sizeof(cName));
		memcpy(cName, cp, 10);
		cp += 10;
		wp = (WORD *)cp;
		iPartyID = (int)*wp;
		cp += 2;
		PartyOperationResult_Create(iClientH, cName, cResult, iPartyID);
		break;

	case 2: // ∆ƒ∆º∞° «ÿªÍµ«æ˙¥Ÿ.
		wp = (WORD *)cp;
		iPartyID = *wp;
		cp += 2;
		PartyOperationResult_Delete(iPartyID);
		break;

	case 3: // ƒ≥∏Ø≈Õ¿« ∆ƒ∆º ªÛ≈¬∏¶ ≈¨∏ÆæÓ«—¥Ÿ.
		wp = (WORD *)cp;
		iClientH = *wp;
		cp += 2;
		ZeroMemory(cName, sizeof(cName));
		memcpy(cName, cp, 10);
		cp += 10;

		if ((iClientH < 0) && (iClientH > DEF_MAXCLIENTS)) return;
		if (m_pClientList[iClientH] == NULL) return;
		if (strcmp(m_pClientList[iClientH]->m_cCharName, cName) != 0) return;
		
		// ∞‘¿” º≠πˆ¿« ∆ƒ∆º ∏ÆΩ∫∆Æø°º≠ µÓ∑œ«ÿ¡¶.
		for (i = 0; i < DEF_MAXPARTYMEMBERS; i++)
		if (m_stPartyInfo[m_pClientList[iClientH]->m_iPartyID].iIndex[i] == iClientH) {
			m_stPartyInfo[m_pClientList[iClientH]->m_iPartyID].iIndex[i] = 0;
			m_stPartyInfo[m_pClientList[iClientH]->m_iPartyID].iTotalMembers--;
			goto PORH_LOOPBREAK1;
		}
PORH_LOOPBREAK1:;
		// ∏ÆΩ∫∆Æ ¿Œµ¶Ω∫¿« ∫Û∞¯∞£¿ª ¡¶∞≈«—¥Ÿ.
		for (i = 0; i < DEF_MAXPARTYMEMBERS-1; i++)
		if ((m_stPartyInfo[m_pClientList[iClientH]->m_iPartyID].iIndex[i] == 0) && (m_stPartyInfo[m_pClientList[iClientH]->m_iPartyID].iIndex[i+1] != 0)) {
			m_stPartyInfo[m_pClientList[iClientH]->m_iPartyID].iIndex[i]   = m_stPartyInfo[m_pClientList[iClientH]->m_iPartyID].iIndex[i+1];
			m_stPartyInfo[m_pClientList[iClientH]->m_iPartyID].iIndex[i+1] = 0;
		}

		m_pClientList[iClientH]->m_iPartyID = NULL;
		m_pClientList[iClientH]->m_iPartyStatus = DEF_PARTYSTATUS_NULL;

		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_PARTY, 8, 0, NULL, NULL);
		break;

	case 4: // ∆ƒ∆º ∞°¿‘ ø‰√ªø° ¥Î«— ¿¿¥‰
		cResult = *cp;
		cp++;
		wp = (WORD *)cp;
		iClientH = (int)*wp;
		cp += 2;
		ZeroMemory(cName, sizeof(cName));
		memcpy(cName, cp, 10);
		cp += 10;
		wp = (WORD *)cp;
		iPartyID = (int)*wp;
		cp += 2;
		PartyOperationResult_Join(iClientH, cName, cResult, iPartyID);
		break;

	case 5: // ∆ƒ∆º ¡§∫∏ 
		wp = (WORD *)cp;
		iClientH = (int)*wp;
		cp += 2;
		ZeroMemory(cName, sizeof(cName));
		memcpy(cName, cp, 10);
		cp += 10;
		wp = (WORD *)cp;
		iTotal = (int)*wp;
		cp += 2;
		PartyOperationResult_Info(iClientH, cName, iTotal, cp);
		break;

	case 6: // ∆ƒ∆º ∏‚πˆ ¡¶∞≈µ  
		cResult = *cp;
		cp++;
		wp = (WORD *)cp;
		iClientH = (int)*wp;
		cp += 2;
		ZeroMemory(cName, sizeof(cName));
		memcpy(cName, cp, 10);
		cp += 10;
		wp = (WORD *)cp;
		iPartyID = (int)*wp;
		cp += 2;
		PartyOperationResult_Dismiss(iClientH, cName, cResult, iPartyID);
		break;
	}
}
void CGame::Resultado4(int iClientH, int ItemType)
{
	class  CItem * pItem;
	int iItemID, iResult,iEraseReq;
	char cMsg[120];
	if (m_pClientList[iClientH] == NULL) return;

	switch(ItemType)
	{
		case 1:
			iResult = iDice(1,8);
			switch(iResult)
			{
				case 1:
					m_pClientList[iClientH]->m_iEnemyKillCount += 1000;
					wsprintf(cMsg, "You got 1000 Enemy Kill Points");
					ShowClientMsg(iClientH, cMsg);
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ENEMYKILLS, m_pClientList[iClientH]->m_iEnemyKillCount, NULL, NULL, NULL);
					break;
				case 2:
					m_pClientList[iClientH]->m_iRating += 1000;
					wsprintf(cMsg, "You got 1000 Reputation Points");
					ShowClientMsg(iClientH, cMsg);
					break;
				case 3:
					iItemID = 612; // XelimaRapier
					break;
				case 4:
					iItemID = 650; // ZemstoneofSacrifice 
					break;
				case 5:
					iItemID = 656; // StoneOfXelima 
					break;
				case 6:
					iItemID = 657; // StoneOfMerien
				case 7:
					Resultado3(iClientH, ItemType);
					break;
				case 8:
					Resultado5(iClientH, ItemType);
					break;
			}
			break;
		case 2:
			iResult = iDice(1,7);
			switch(iResult)
			{
				case 1:
					m_pClientList[iClientH]->m_iEnemyKillCount += 500;
					wsprintf(cMsg, "You got 500 Enemy Kill Points");
					ShowClientMsg(iClientH, cMsg);
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ENEMYKILLS, m_pClientList[iClientH]->m_iEnemyKillCount, NULL, NULL, NULL);
					break;
				case 2:
					m_pClientList[iClientH]->m_iRating += 500;
					wsprintf(cMsg, "You got 500 Reputation Points");
					ShowClientMsg(iClientH, cMsg);
					break;
				case 3:
					iItemID = 20; // Excaliber 
					break;
				case 4:
					m_pClientList[iClientH]->m_iGizonItemUpgradeLeft += 200;
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
					wsprintf(cMsg, "You got 200 Magestics Points");
					ShowClientMsg(iClientH, cMsg);
					break;
				case 5:
					iItemID = 882; // ArmorDye(CrimsonRed)
					break;
				case 6:
					Resultado3(iClientH, ItemType);
					break;
				case 7:
					Resultado5(iClientH, ItemType);
					break;
			}
			break;
		case 3:
			iResult = iDice(1,7);
			switch(iResult)
			{
				case 1:
					m_pClientList[iClientH]->m_iEnemyKillCount += 200;
					wsprintf(cMsg, "You got 200 Enemy Kill Points");
					ShowClientMsg(iClientH, cMsg);
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ENEMYKILLS, m_pClientList[iClientH]->m_iEnemyKillCount, NULL, NULL, NULL);
					break;
				case 2:
					m_pClientList[iClientH]->m_iRating += 200;
					wsprintf(cMsg, "You got 200 Reputation Points");
					ShowClientMsg(iClientH, cMsg);
					break;
				case 3:
					iItemID = 642; // KnecklaceOfIcePro
					break;
				case 4:
					m_pClientList[iClientH]->m_iGizonItemUpgradeLeft += 100;
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIZONITEMUPGRADELEFT, m_pClientList[iClientH]->m_iGizonItemUpgradeLeft, NULL, NULL, NULL);
					wsprintf(cMsg, "You got 100 Magestics Points");
					ShowClientMsg(iClientH, cMsg);
					break;
				case 5:
					iItemID = 883; // ArmorDye(Gold)
					break;
				case 6:
					Resultado3(iClientH, ItemType);
					break;
				case 7:
					Resultado5(iClientH, ItemType);
					break;
			}
			break;
	}

	pItem = new class CItem;
	if (_bInitItemAttr(pItem, iItemID) == FALSE) {
		delete pItem;
	}
	else {
		_bAddClientItemList(iClientH, pItem, &iEraseReq);
		SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
	}
}

void CGame::Resultado5(int iClientH, int ItemType)
{
	class  CItem * pItem;
	int iItemID, iResult,iEraseReq;
	if (m_pClientList[iClientH] == NULL) return;

	switch(ItemType)
	{
		case 1:
			iResult = iDice(1,8);
			switch(iResult)
			{
				case 1:
					iItemID = 861; // ContrbBall50000 
					break;
				case 2:
					iItemID = 610; // XelimaBlade  
					break;
				case 3:
					iItemID = 3081; // ContrbBall100000
					break;
				case 4:
					iItemID = 865; // ResurWand(MS.20)
				case 5:
					Resultado4(iClientH, ItemType);
					break;
				case 6:
					Resultado3(iClientH, ItemType);
					break;
				case 7:
					Resultado2(iClientH, ItemType);
					break;
				case 8:
					Resultado1(iClientH, ItemType);
					break;
			}
			break;
		case 2:
			iResult = iDice(1,7);
			switch(iResult)
			{
				case 1:
					iItemID = 612; //XelimaRapier 
					break;
				case 2:
					iItemID = 858; // GiantBattleHammer   
					break;
				case 3:
					iItemID = 3081; // ContrbBall100000
					break;
				case 4:
					Resultado4(iClientH, ItemType);
					break;
				case 5:
					Resultado3(iClientH, ItemType);
					break;
				case 6:
					Resultado2(iClientH, ItemType);
					break;
				case 7:
					Resultado1(iClientH, ItemType);
					break;
			}
			break;
		case 3:
			iResult = iDice(1,7);
			switch(iResult)
			{
				case 1:
					iItemID = 858; //NecklaceOfMerien 
					break;
				case 2:
					iItemID = 761; // NecklaceOfXelima    
					break;
				case 3:
					iItemID = 866; // ResurWand(MS.10)
					break;
				case 4:
					Resultado4(iClientH, ItemType);
					break;
				case 5:
					Resultado3(iClientH, ItemType);
					break;
				case 6:
					Resultado2(iClientH, ItemType);
					break;
				case 7:
					Resultado1(iClientH, ItemType);
					break;
			}
			break;
	}

	pItem = new class CItem;
	if (_bInitItemAttr(pItem, iItemID) == FALSE) {
		delete pItem;
	}
	else {
		_bAddClientItemList(iClientH, pItem, &iEraseReq);
		SendItemNotifyMsg(iClientH, DEF_NOTIFY_ITEMOBTAINED, pItem, NULL);
	}
}
void CGame::AdminOrder_SummonPlayer(int iClientH, char *pData, DWORD dwMsgSize)
{
 char   seps[] = "= \t\n";
 char   * cp, * token, cName[11], cBuff[256];
 class  CStrTok * pStrTok;
 WORD   * wp;
 register int i;

	if (m_pClientList[iClientH] == NULL) return;
	if ((dwMsgSize)	<= 0) return;
	
	if (m_pClientList[iClientH]->m_iAdminUserLevel < 4) {
		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
		return;
	}
	if (m_pClientList[iClientH]->m_bActivarComandos == FALSE) return;


	ZeroMemory(cName, sizeof(cName));
	ZeroMemory(cBuff, sizeof(cBuff));
	memcpy(cBuff, pData, dwMsgSize);

	pStrTok = new class CStrTok(cBuff, seps);
	token = pStrTok->pGet();
	token = pStrTok->pGet();

	if (token != NULL) {
		if (strlen(token) > 10)	
			 memcpy(cName, token, 10);
		else memcpy(cName, token, strlen(token));

		// ∞∞¿∫ º≠πˆø° ¿÷¥¬ «√∑π¿ÃæÓ ¡ﬂ 
		for (i = 1; i < DEF_MAXCLIENTS; i++) 
		if ((m_pClientList[i] != NULL) && (memcmp(m_pClientList[i]->m_cCharName, cName, 10) == 0)) {
			// ∞∞¿∫ ¿Ã∏ß¿ª ∞°¡¯ «√∑π¿ÃæÓ∏¶ √£æ“¥Ÿ. 
			// ¿⁄±‚ ¿⁄Ω≈¿Ã∂Û∏È «“¥Á«œ¡ˆ æ ¥¬¥Ÿ.
			if (i == iClientH) {
				delete pStrTok;
				return;
			}

#ifdef DEF_TAIWANLOG
			short sX = 0,sY = 0 ;
			char cMapName[22] ; 

			ZeroMemory(cMapName,sizeof(cMapName)) ;

			sX = m_pClientList[i]->m_sX ;
			sY = m_pClientList[i]->m_sY ;
			strcpy(cMapName, m_pClientList[i]->m_cMapName) ;

			m_pClientList[i]->m_sX = m_pClientList[iClientH]->m_sX;
			m_pClientList[i]->m_sY = m_pClientList[iClientH]->m_sY;
			strcpy(m_pClientList[i]->m_cMapName, m_pClientList[iClientH]->m_cMapName) ;

			_bItemLog(DEF_ITEMLOG_SUMMONPLAYER, i, m_pClientList[iClientH]->m_cCharName,NULL) ;

			m_pClientList[i]->m_sY = sY ; 
			m_pClientList[i]->m_sX = sX ;

			strcpy(m_pClientList[i]->m_cMapName,cMapName) ;

#endif 

			RequestTeleportHandler(i, "2   ", m_pClientList[iClientH]->m_cMapName ,m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY);
			delete pStrTok;
			return;
		}


		wsprintf(G_cTxt, "GM Order(%s): PC(%s) Summoned to (%s)",m_pClientList[iClientH]->m_cCharName, cName,m_pClientList[iClientH]->m_cMapName);
		bSendMsgToLS(MSGID_GAMEMASTERLOG,iClientH, FALSE,G_cTxt);


		// v2.12 ¥Ÿ∏• º≠πˆø° ¿÷¥¬ ƒ≥∏Ø≈Õø°∞‘ ∏ﬁΩ√¡ˆ∏¶ ∫∏≥ª±‚ ¿ß«‘ 
		// «ˆ¿Á º≠πˆø° æ¯¥Ÿ. ¥Ÿ∏• º≠πˆø° ¿÷¥¬¡ˆ ∞ÀªÁ«ÿæﬂ «—¥Ÿ.
		ZeroMemory(cBuff, sizeof(cBuff));
		cp = (char *)cBuff;
		*cp = GSM_REQUEST_SUMMONPLAYER;
		cp++;

		memcpy(cp, cName, 10);
		cp += 10;

		memcpy(cp, m_pClientList[iClientH]->m_cMapName, 10);
		cp += 10;


		wp = (WORD *)cp;
		*wp = m_pClientList[iClientH]->m_sX ;
		cp += 2;

		wp = (WORD *)cp;
		*wp = m_pClientList[iClientH]->m_sY;
		cp += 2;


		bStockMsgToGateServer(cBuff, 25);

		delete pStrTok;
		return;
	}
 
	delete pStrTok;
}

void CGame::CheckSpecialEvent(int iClientH)
{
 class CItem * pItem;
 char  cItemName[21];
 int   iEraseReq;

	if (m_pClientList[iClientH] == NULL) return;
	// 2002-8-6 ¿œ¡÷≥‚ π›¡ˆ ¥ı ¿ÃªÛ ¡÷¡ˆ æ ¥¬¥Ÿ. 
	return ;

	//v1.42 ¿Ã∫•∆Æ æ∆¿Ã≈€¿ª ¡ÿ¥Ÿ. 2000.8.1¿œ 1¡÷≥‚ π›¡ˆ ºˆø© 
	if (m_pClientList[iClientH]->m_iSpecialEventID == 200081) {
		
		// ¿˙∑æ¿∫ ¡÷¡ˆ æ ¥¬¥Ÿ.
		if (m_pClientList[iClientH]->m_iLevel < 11) {
			m_pClientList[iClientH]->m_iSpecialEventID = 0;
			return;
		}


		ZeroMemory(cItemName, sizeof(cItemName));
		strcpy(cItemName, DEF_ITEMNAME_MEMORIALRING); 
		
		pItem = new class CItem;
		if (_bInitItemAttr(pItem, cItemName) == FALSE) {
			// ±∏¿‘«œ∞Ì¿⁄ «œ¥¬ æ∆¿Ã≈€¿Ã æ∆¿Ã≈€ ∏ÆΩ∫∆ÆªÛø° æ¯¥Ÿ. ±∏¿‘¿Ã ∫“∞°¥…«œ¥Ÿ.
			delete pItem;
			pItem = NULL;
		}
		else {
			if (_bAddClientItemList(iClientH, pItem, &iEraseReq) == TRUE) {
				// ø°∑Ø πÊ¡ˆøÎ ƒ⁄µÂ
				if (m_pClientList[iClientH]->m_iCurWeightLoad < 0) m_pClientList[iClientH]->m_iCurWeightLoad = 0;
				
				//testcode ∑Œ±◊∆ƒ¿œø° ±‚∑œ«—¥Ÿ.
				wsprintf(G_cTxt, "(*) Get 1¡÷≥‚±‚≥‰π›¡ˆ : Char(%s)", m_pClientList[iClientH]->m_cCharName);
				PutLogFileList(G_cTxt);

				// æ∆¿Ã≈€ø° ªÁøÎ¿⁄ ∞Ì¿Ø π¯»£∏¶ ¿‘∑¬«—¥Ÿ. ¥Ÿ∏• ƒ≥∏Ø≈Õ¥¬ ¿Ã æ∆¿Ã≈€¿ª ªÁøÎ«“ ºˆ∞° æ¯¥Ÿ.
				pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER;
				pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1;
				pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2;
				pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3;
				pItem->m_cItemColor         = 9;

				// æ∆¿Ã≈€ πﬁæ“¿∏π«∑Œ ≈¨∏ÆæÓ.
				m_pClientList[iClientH]->m_iSpecialEventID = 0;
			}
		}
	}
}
void CGame::TrainSkillResponse(BOOL bSuccess, int iClientH, int iSkillNum, int iSkillLevel)
{
 char  * cp, cData[100];
 DWORD * dwp;
 WORD  * wp;
 int   iRet;

	if (m_pClientList[ iClientH ] == NULL) return;
	if (m_pClientList[ iClientH ]->m_bIsInitComplete == FALSE) return;
	if ((iSkillNum < 0)	|| (iSkillNum > 100)) return;
	if ((iSkillLevel < 0) || (iSkillLevel > 100)) return;

	if (bSuccess == TRUE) {
		if (m_pClientList[ iClientH ]->m_cSkillMastery[iSkillNum] != 0) return;
		
		m_pClientList[ iClientH ]->m_cSkillMastery[iSkillNum] = iSkillLevel;
		bCheckTotalSkillMasteryPoints(iClientH, iSkillNum);

		dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
		*dwp = MSGID_NOTIFY;
		wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
		*wp  = DEF_NOTIFY_SKILLTRAINSUCCESS;
		
		cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);
		
		*cp = iSkillNum;
		cp++;
		
		*cp = iSkillLevel;
		cp++;
	 
		if (m_pSkillConfigList[iSkillNum]->m_cName != NULL) 
			_bItemLog(DEF_ITEMLOG_SKILLLEARN,iClientH,m_pSkillConfigList[iSkillNum]->m_cName,NULL);

		iRet = m_pClientList[ iClientH ]->m_pXSock->iSendMsg(cData, 8);
		switch (iRet) {
		case DEF_XSOCKEVENT_QUENEFULL:
		case DEF_XSOCKEVENT_SOCKETERROR:
		case DEF_XSOCKEVENT_CRITICALERROR:
		case DEF_XSOCKEVENT_SOCKETCLOSED:
			DeleteClient(iClientH, TRUE, TRUE);
			return;
		}
	}
	else {


	}
}
void CGame::PlayerOrder_RequestDestiny(int iClientH, char * pData)	{
 char * cp;
 int * ip;
 int iType = -1;
	if (m_pClientList[iClientH] == NULL) return;

	cp = (char *)(pData + DEF_INDEX2_MSGTYPE + 2);
	ip = (int *)cp;
	iType = *ip;
	cp += 4;

	switch (iType)	{//1 = aresden
	case 1:
			m_pClientList[iClientH]->m_cSide = 1;
			RequestTeleportHandler(iClientH,"2   ", "gshop_1", -1, -1);
			m_pClientList[iClientH]->m_bIsNeutral = TRUE;
			m_pClientList[iClientH]->m_bIsPlayerCivil = TRUE;
			strcpy(m_pClientList[iClientH]->m_cLocation, "arehunter");
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CIVILCHANGED, NULL, NULL, NULL, m_pClientList[iClientH]->m_cLocation); 


		break;

	case 2:
			m_pClientList[iClientH]->m_cSide = 2;
			RequestTeleportHandler(iClientH,"2   ", "gshop_2", -1, -1);
			m_pClientList[iClientH]->m_bIsNeutral = TRUE;
			m_pClientList[iClientH]->m_bIsPlayerCivil = TRUE;
			strcpy(m_pClientList[iClientH]->m_cLocation, "elvhunter");
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CIVILCHANGED, NULL, NULL, NULL, m_pClientList[iClientH]->m_cLocation);
		break;
	}
	

}

void CGame::HandleRequestMemoryTopEK(int iClientH)
{
	if (iClientH < 0) return;
	if (m_pClientList[iClientH] == NULL) return;
	
	EKPosition TopEK[10];
	int TopIndex = 0, ShortCutIndex = 0;
	bool bFlag = true;

	for (int i = 0; i < 10; i++)
	{
		TopEK[i].EKCount = 0;
		ZeroMemory(TopEK[i].Name, sizeof(TopEK[i].Name));
		TopEK[i].Side = Neutral;
	}

	while (i > 0 && ShortCutIndex < DEF_MAXCLIENTS)
	{
		i = m_iClientShortCut[ShortCutIndex];
		ShortCutIndex++;

		if (i >= 0 && i < DEF_MAXCLIENTS
			&& m_pClientList[i] != NULL
			&& m_pClientList[i]->m_bIsInitComplete == TRUE
			&& m_pClientList[i]->m_iAdminUserLevel == 0)
		{
			for (int x = 0; x <  10; x++)
			{
				if (this->m_pClientList[i]->m_iEnemyKillCount > TopEK[x].EKCount)
				{
					for (int y = 0; y < 10; y++)
						if (strcmp(TopEK[y].Name, m_pClientList[i]->m_cCharName) == 0)
							bFlag = false; // No deja poner el mismo personaje en el top

					if (bFlag == true)
					{
						if (TopEK[x].EKCount > 0) // Hay otro cliente en la lista
						{
							for (int y = 8; y >= x; y--)							
								TopEK[y + 1] = TopEK[y];							

							TopEK[x].EKCount = m_pClientList[i]->m_iEnemyKillCount;
							strcpy(TopEK[x].Name, m_pClientList[i]->m_cCharName);
							TopEK[x].Side = (Citizenship)m_pClientList[i]->m_cSide;
						}

						else
						{
							TopEK[x].EKCount = m_pClientList[i]->m_iEnemyKillCount;
							strcpy(TopEK[x].Name, m_pClientList[i]->m_cCharName);
							TopEK[x].Side = (Citizenship)m_pClientList[i]->m_cSide;
						}
					}

					bFlag = true;
				}
			}
		}
	}

	char cData[512];
	int *ip, Size;
	char *cp;
	DWORD *dwp;
	WORD *wp;

	ZeroMemory(cData, sizeof(cData));
	
	dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
	*dwp = MSGID_NOTIFY;
	wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);			   
	*wp  = RESPONSE_TOPMEMORY_EK;

	cp = (char *)(cData + 6);
	Size = 6;

	for (i = 0; i < 10; i++)
	{
		memcpy(cp, TopEK[i].Name, strlen(TopEK[i].Name));
		cp += 11;

		*cp = (char)TopEK[i].Side;
		cp++;

		ip = (int *)cp;
		*ip = TopEK[i].EKCount;
		cp += 4;

		Size += 16;
	}

	m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, Size);

	//this->ShowClientMsg(iClientH, "Top EK momentaneamente DESACTIVADO");
}
void CGame::AdminOrder_MorlearPj(int iClientH, char* pData, DWORD dwMsgSize) // MORLA 2.12 - Morlear PJ
{
	char   seps[] = "= \t\n";
	char   * token, cBuff[256], cPlayerName[11];
	class  CStrTok * pStrTok;


	if (m_pClientList[iClientH] == NULL) return;
	if ((dwMsgSize)	<= 0) return;

	ZeroMemory(cPlayerName, sizeof(cPlayerName));
	ZeroMemory(cBuff, sizeof(cBuff));
	memcpy(cBuff, pData, dwMsgSize);

	pStrTok = new class CStrTok(cBuff, seps);
	token = pStrTok->pGet();

	token = pStrTok->pGet();
	if (token == NULL) {
		delete pStrTok;
		return;
	}

	if (strlen(token) > 10) {
		memcpy(cPlayerName,token,10);
	}
	else{
		memcpy(cPlayerName,token,strlen(token));
	}

	for(int i = 1; i < DEF_MAXCLIENTS; i++){
		if (m_pClientList[i] != NULL) {
			if (memcmp(cPlayerName,m_pClientList[i]->m_cCharName, 10) == 0) {
				if (m_pClientList[iClientH]->m_iAdminUserLevel > 0) {
					wsprintf(cBuff,"GM Order(%s): MORLEAR PJ (%s)",m_pClientList[iClientH]->m_cCharName,m_pClientList[i]->m_cCharName);					
					SendNotifyMsg(NULL, i, DEF_NOTIFY_MORLEARPJ, NULL, NULL, NULL, NULL); 
				}
				delete pStrTok;
				return;
			}
		}
	}
	delete pStrTok;
}
void CGame::AutoSkill(int iClientH)
{
	int i;
	if (m_pClientList[iClientH] == NULL) return;
	
	for (i = 0; i <= 23; i++) {
       m_pClientList[iClientH]->m_cSkillMastery[i] = 100;
       SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SKILL, i, m_pClientList[iClientH]->m_cSkillMastery[i], NULL, NULL);

	}
}
void CGame::AdminOrder_SetEK (int iClientH, char *pData, DWORD dwMsgSize) 
{
	char seps[] = "= \t\n";
	char *token, cBuff[256];
	class CStrTok *pStrTok;
	char *pk;
	char cNick[21];
	char cPK[6];
	char notice[100];
	int oldpk;
	int i;

	if (m_pClientList[iClientH] == NULL) return;
	if ((dwMsgSize) <= 0) return;

	if (m_pClientList[iClientH]->m_iAdminUserLevel < 4){
		SendNotifyMsg (NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
		return;
	}

	ZeroMemory (cBuff, sizeof (cBuff));
	ZeroMemory(cNick,sizeof(cNick));
	ZeroMemory(cPK, sizeof(cPK));
	memcpy (cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok (cBuff, seps);
	token = pStrTok->pGet ();
	token = pStrTok->pGet ();

	if (token == NULL) {
		delete pStrTok;
		return;
	}
	memcpy (cNick, token, 20);
	pk = pStrTok->pGet ();
	if (pk == NULL) {
		delete pStrTok;
		return;
	}
	memcpy (cPK, pk,5);
	for (i = 0; i < DEF_MAXCLIENTS; i++){
		if ((m_pClientList[i] != NULL)&& (memcmp (m_pClientList[i]->m_cCharName, cNick, strlen (cNick)) == 0)){
			oldpk = m_pClientList[i]->m_iEnemyKillCount;
			m_pClientList[i]->m_iEnemyKillCount = atoi (cPK);
			SendNotifyMsg (NULL, i, DEF_NOTIFY_ENEMYKILLS, m_pClientList[i]->m_iEnemyKillCount, NULL, NULL, NULL);
			wsprintf (notice, "EK Count has been changed for player %s from %d to %d.", m_pClientList[iClientH]->m_cCharName, oldpk, atoi (cPK));
		}
	}
	delete pStrTok;
}



void CGame::PlayerCommandCheckAdmins(int iClientH)
{
	char cNotifyMessage[256],cNotifyMessage2[256], cGMName[12];
	int i,x;
	cGMName[12];
	ZeroMemory(cNotifyMessage, sizeof(cNotifyMessage));
	ZeroMemory(cNotifyMessage2, sizeof(cNotifyMessage2));
	x = 0;
	for (i = 0; i < DEF_MAXCLIENTS; i++)
		if (m_pClientList[i] != NULL) {
			if (m_pClientList[i]->m_iAdminUserLevel > 0) {
				wsprintf(cNotifyMessage, "Admins: %s", m_pClientList[i]->m_cCharName);
				ShowClientMsg(iClientH, cNotifyMessage);
				x++;
			}
		}
}

void CGame::RequestPurchaseItemHandler2(int iClientH, char * pItemName, int iNum)
{
 class CItem * pItem;
 char  * cp, cItemName[21], cData[100];
 short * sp;
 DWORD * dwp, dwItemCount;
 WORD  * wp, wTempPrice;
 int iIDADD = FALSE;
 int   i, iRet, iEraseReq;
 int iEKCost = 0, iCPCost = 0;
 
	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;

	if (memcmp(m_pClientList[iClientH]->m_cLocation, "NONE", 4) != 0) {
		if (memcmp(m_pClientList[iClientH]->m_cLocation, "are", 3) == 0) {
			if ((memcmp(m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cLocationName, "aresden", 7) == 0) ||
				(memcmp(m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cLocationName, "arefarm", 7) == 0)) {

			}
			else return;
		}

		if (memcmp(m_pClientList[iClientH]->m_cLocation, "elv", 3) == 0) {
			if ((memcmp(m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cLocationName, "elvine", 6) == 0) ||
				(memcmp(m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->m_cLocationName, "elvfarm", 7) == 0)) {

			}
			else return;
		}
	}
	
	
	ZeroMemory(cData, sizeof(cData));	
	ZeroMemory(cItemName, sizeof(cItemName));
		
//trade x contrib
	//contrib balls
	if (memcmp(pItemName, "ContribBall(+500)", 17) == 0) { iCPCost = 500; iEKCost = 0; }
	if (memcmp(pItemName, "ContribBall(+700)", 17) == 0) { iCPCost = 700; iEKCost = 0; }
	if (memcmp(pItemName, "ContribBall(+10000)", 19) == 0) { iCPCost = 10000; iEKCost = 0; }
	if (memcmp(pItemName, "ContribBall(+20000)", 19) == 0) { iCPCost = 20000; iEKCost = 0; }
	if (memcmp(pItemName, "ContribBall(+50000)", 19) == 0) { iCPCost = 50000; iEKCost = 0; }
	if (memcmp(pItemName, "ContribBall(+100000)", 20) == 0) { iCPCost = 100000; iEKCost = 0; }

	//ek balls x eks
	/*if (memcmp(pItemName, "EkBall(+100)", 12) == 0) { iCPCost = 0; iEKCost = 100; }
	if (memcmp(pItemName, "EkBall(+200)", 12) == 0) { iCPCost = 0; iEKCost = 200; }
	if (memcmp(pItemName, "EkBall(+10000)", 12) == 0) { iCPCost = 0; iEKCost = 10000; }
	*/
	//por contrib
	if (memcmp(pItemName, "ZemstoneofSacrifice", 19) == 0) { iCPCost = 5000; iEKCost = 0; }
	if (memcmp(pItemName, "NecklaceOfXelima", 16) == 0) { iCPCost = 80000; iEKCost = 0; }
	if (memcmp(pItemName, "NecklaceOfMerien", 16) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "RingofArcmage", 13) == 0) { iCPCost = 50000; iEKCost = 0; }
	if (memcmp(pItemName, "RingoftheAbaddon", 16) == 0) { iCPCost = 50000; iEKCost = 0; }
	if (memcmp(pItemName, "NpcKillHammer", 15) == 0) { iCPCost = 200000; iEKCost = 0; }

	//Especial items ek trade
	if (memcmp(pItemName, "TintaMagica(Rosa)", 17) == 0) { iCPCost = 0; iEKCost = 10000; }
	if (memcmp(pItemName, "TintaMagica(Verde)", 18) == 0) { iCPCost = 0; iEKCost = 10000; }
	if (memcmp(pItemName, "TintaMagica(Azul)", 17) == 0) { iCPCost = 0; iEKCost = 10000; }
	/*if (memcmp(pItemName, "SwordofMedusa", 13) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "XelimaBlade ", 11) == 0) { iCPCost = 0; iEKCost = 30000; }
	if (memcmp(pItemName, "WhiteMWand(MS.60)", 17) == 0) { iCPCost = 90000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteWingsHelm(M)", 17) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteWingsHelm(W)", 17) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageHat(M)", 15) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageHat(W)", 15) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhitePlateMail(M)", 17) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhitePlateMail(W)", 17) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageChain(M)", 17) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageChain(W)", 17) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteHauberk(M)", 15) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteHauberk(W)", 15) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteLeggings(M)", 16) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteLeggings(W)", 16) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageHauberk(M)", 19) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageHauberk(W)", 19) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageLeggs(M)", 17) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageLeggs(W)", 17) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageRobe(M)", 16) == 0) { iCPCost = 30000; iEKCost = 0; }
	if (memcmp(pItemName, "WhiteMageRobe(W)", 16) == 0) { iCPCost = 30000; iEKCost = 0; }
	*/
	if (memcmp(pItemName, "aAncHeroHelm(M)", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroHelm(W)", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroHelm(M)", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroHelm(W)", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroCap(M)", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroCap(W)", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroCap(M)", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroCap(W)", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroArmor(M)", 18) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroArmor(W)", 18) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroArmor(M)", 18) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroArmor(W)", 18) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroRobe(M)", 14) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroRobe(W)", 14) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroRobe(M)", 14) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroRobe(W)", 14) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroHauberk(M)", 20) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroHauberk(W)", 20) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroHauberk(M)", 20) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroHauberk(W)", 20) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroLeggs(M)", 18) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "aAncHeroLeggs(W)", 18) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroLeggs(M)", 18) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "eAncHeroLeggs(W)", 18) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "AncientAresHeroCape", 17) == 0) { iCPCost = 300; iEKCost = 3000; }
	if (memcmp(pItemName, "AncientElvHeroCape", 16) == 0) { iCPCost = 300; iEKCost = 3000; }
	/*
	//Extreme Items por ek
	if (memcmp(pItemName, "ExtremeHelm(M)", 14) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeHelm(W)", 14) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "ExtremeHat(M)", 13) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeHat(W)", 13) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "ExtremeArmor(M)", 15) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeArmor(W)", 15) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "ExtremeChain(M)", 15) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeChain(W)", 15) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "ExtremeHauberk(M)", 17) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeHauberk(W)", 17) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "ExtremeLeggs(M)", 15) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeLeggs(W)", 15) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "ExtremeMHauberk(M)", 18) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeMHauberk(W)", 18) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "ExtremeRobe(M)", 14) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeRobe(W)", 14) == 0) { iCPCost = 0; iEKCost = 50000; }
	if (memcmp(pItemName, "ExtremeMLeggs(M)", 16) == 0) { iCPCost = 0; iEKCost = 50000; }
    if (memcmp(pItemName, "ExtremeMLeggs(W)", 16) == 0) { iCPCost = 0; iEKCost = 50000; }
	//FIERROS extreme
	if (memcmp(pItemName, "ExtremeDemonSlayer", 18) == 0) { iCPCost = 0; iEKCost = 80000; }
    if (memcmp(pItemName, "ExtremeKlonessBlade", 19) == 0) { iCPCost = 0; iEKCost = 180000; }
	if (memcmp(pItemName, "ExtremeDevastator", 17) == 0) { iCPCost = 0; iEKCost = 350000; }
    if (memcmp(pItemName, "ExtremePowerSword", 17) == 0) { iCPCost = 0; iEKCost = 500000; }
	if (memcmp(pItemName, "ExtremePowerWand", 16) == 0) { iCPCost = 0; iEKCost = 400000; }
    if (memcmp(pItemName, "ExtremeZWand(MS.60)", 19) == 0) { iCPCost = 0; iEKCost = 350000; }
	if (memcmp(pItemName, "ExtremeBattleHammer", 19) == 0) { iCPCost = 0; iEKCost = 300000; }
	if (memcmp(pItemName, "ExtremeKWand(MS.60)", 19) == 0) { iCPCost = 0; iEKCost = 100000; }
	//armaduras legendary
	if (memcmp(pItemName, "LegendaryHelm(M)", 16) == 0) { iCPCost = 0; iEKCost = 100000; }
    if (memcmp(pItemName, "LegendaryHelm(W)", 16) == 0) { iCPCost = 0; iEKCost = 100000; }
	if (memcmp(pItemName, "LegendaryHat(M)", 15) == 0) { iCPCost = 0; iEKCost = 100000; }
    if (memcmp(pItemName, "LegendaryHat(W)", 15) == 0) { iCPCost = 0; iEKCost = 100000; }
	if (memcmp(pItemName, "LegendaryArmor(M)", 17) == 0) { iCPCost = 0; iEKCost = 100000; }
    if (memcmp(pItemName, "LegendaryArmor(W)", 17) == 0) { iCPCost = 0; iEKCost = 100000; }
	if (memcmp(pItemName, "LegendaryChain(M)", 17) == 0) { iCPCost = 0; iEKCost = 100000; }
    if (memcmp(pItemName, "LegendaryChain(W)", 17) == 0) { iCPCost = 0; iEKCost = 100000; }
	if (memcmp(pItemName, "LegendaryHauberk(M)", 18) == 0) { iCPCost = 0; iEKCost = 100000; }
    if (memcmp(pItemName, "LegendaryHauberk(W)", 18) == 0) { iCPCost = 0; iEKCost = 100000; }
	if (memcmp(pItemName, "LegendaryLeggs(M)", 17) == 0) { iCPCost = 0; iEKCost = 100000; }
    if (memcmp(pItemName, "LegendaryLeggs(W)", 17) == 0) { iCPCost = 0; iEKCost = 100000; }
	if (memcmp(pItemName, "LegendaryRobe(M)", 16) == 0) { iCPCost = 0; iEKCost = 100000; }
    if (memcmp(pItemName, "LegendaryRobe(W)", 16) == 0) { iCPCost = 0; iEKCost = 100000; }
	//fierros legendary
	if (memcmp(pItemName, "LegendaryHammer", 15) == 0) { iCPCost = 0; iEKCost = 700000; }
    if (memcmp(pItemName, "LegendarySword", 14) == 0) { iCPCost = 0; iEKCost = 700000; }
	if (memcmp(pItemName, "LegendaryWand", 13) == 0) { iCPCost = 0; iEKCost = 600000; }
    if (memcmp(pItemName, "LegendaryShield", 15) == 0) { iCPCost = 0; iEKCost = 500000; }
	//necks
	if (memcmp(pItemName, "PowerHP_Neck", 12) == 0) { iCPCost = 0; iEKCost = 200000; }
	if (memcmp(pItemName, "PowerMP_Neck", 12) == 0) { iCPCost = 0; iEKCost = 100000; }
	if (memcmp(pItemName, "S.O.T.G.Manual", 14) == 0) { iCPCost = 0; iEKCost = 150000; }
	*/
	if ((m_pClientList[iClientH]->m_iEnemyKillCount < iEKCost)
		|| (m_pClientList[iClientH]->m_iContribution < iCPCost))
		return;
	if ((iCPCost == 0) && (iEKCost == 0)) return;

		memcpy(cItemName, pItemName, 20);
		dwItemCount = 1;

	for (i = 1; i <= iNum; i++) {

		pItem = new class CItem;
		if (_bInitItemAttr(pItem, cItemName) == FALSE) {
			delete pItem;
		}
		else {
			
			if (_bAddClientItemList(iClientH, pItem, &iEraseReq) == TRUE) {
				if (m_pClientList[iClientH]->m_iCurWeightLoad < 0) m_pClientList[iClientH]->m_iCurWeightLoad = 0;
				

		/*	if (iIDADD == TRUE)
			{
				pItem->m_sTouchEffectType = DEF_ITET_UNIQUE_OWNER; 
				pItem->m_sTouchEffectValue1 = m_pClientList[iClientH]->m_sCharIDnum1; 
				pItem->m_sTouchEffectValue2 = m_pClientList[iClientH]->m_sCharIDnum2; 
				pItem->m_sTouchEffectValue3 = m_pClientList[iClientH]->m_sCharIDnum3; 
			}*/



				dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
				*dwp = MSGID_NOTIFY;
				wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
				*wp  = DEF_NOTIFY_ITEMTRADE;
				
				cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);
				*cp = 1;
				cp++;
				
				memcpy(cp, pItem->m_cName, 20);
				cp += 20;
				
				dwp  = (DWORD *)cp;
				*dwp = pItem->m_dwCount;
				cp += 4;
				
				*cp = pItem->m_cItemType;
				cp++;
				
				*cp = pItem->m_cEquipPos;
				cp++;
				
				*cp = (char)0;
				cp++;
				
				sp  = (short *)cp;
				*sp = pItem->m_sLevelLimit;
				cp += 2;
				
				*cp = pItem->m_cGenderLimit;
				cp++;
				
				wp = (WORD *)cp;
				*wp = pItem->m_wCurLifeSpan;
				cp += 2;
				
				wp = (WORD *)cp;
				*wp = pItem->m_wWeight;
				cp += 2;
				
				sp  = (short *)cp;
				*sp = pItem->m_sSprite;
				cp += 2;
				
				sp  = (short *)cp;
				*sp = pItem->m_sSpriteFrame;
				cp += 2;

				*cp = pItem->m_cItemColor;
				cp++;
				
				wp  = (WORD *)cp;
				*wp = iCPCost+iEKCost;
				wTempPrice = iCPCost+iEKCost;
				cp += 2;
				
				if (iEraseReq == 1) delete pItem;

				
				m_pClientList[iClientH]->m_iEnemyKillCount -= iEKCost;
				m_pClientList[iClientH]->m_iContribution -= iCPCost;
			    SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ENEMYKILLS, m_pClientList[iClientH]->m_iEnemyKillCount, NULL, NULL, NULL); 
				//SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_REPDGDEATHS, m_pClientList[iClientH]->m_iContribution, m_pClientList[iClientH]->m_iDeaths, m_pClientList[iClientH]->m_iRating, NULL);
				
				iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 48);
				
				iCalcTotalWeight(iClientH);
					
				switch (iRet) {
				case DEF_XSOCKEVENT_QUENEFULL:
				case DEF_XSOCKEVENT_SOCKETERROR:
				case DEF_XSOCKEVENT_CRITICALERROR:
				case DEF_XSOCKEVENT_SOCKETCLOSED:
					DeleteClient(iClientH, TRUE, TRUE);
					return;
				}
			}
			else 
			{
				delete pItem;

				iCalcTotalWeight(iClientH);

				dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
				*dwp = MSGID_NOTIFY;
				wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
				*wp  = DEF_NOTIFY_CANNOTCARRYMOREITEM;
				
				iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 6);
				switch (iRet) {
				case DEF_XSOCKEVENT_QUENEFULL:
				case DEF_XSOCKEVENT_SOCKETERROR:
				case DEF_XSOCKEVENT_CRITICALERROR:
				case DEF_XSOCKEVENT_SOCKETCLOSED:
					DeleteClient(iClientH, TRUE, TRUE);
					return;
				}
			}
		}
 	}
}
void CGame::GiveItemHandler(int iClientH, short sItemIndex, int iAmount, short dX, short dY, WORD wObjectID, char * pItemName)
{
 register int iRet, iEraseReq;
 short * sp, sOwnerH;
 char  * cp, cOwnerType, cData[100], cCharName[21];
 DWORD * dwp;
 WORD  * wp;
 class CItem * pItem;
  
	if (m_pClientList[iClientH] == NULL) return;
	if (m_pClientList[iClientH]->m_bIsOnWaitingProcess == TRUE) return;	//DEBUG
	if (m_pClientList[iClientH]->m_bIsInitComplete == FALSE) return;
	if (m_pClientList[iClientH]->m_pItemList[sItemIndex] == NULL) return;
	if ((sItemIndex < 0) || (sItemIndex >= DEF_MAXITEMS)) return;
	if (iAmount <= 0) return;
   	if (m_pClientList[iClientH]->m_iAdminUserLevel > 0&&m_pClientList[iClientH]->m_iAdminUserLevel < 3) return;

	// æ∆¿Ã≈€ ¿Ã∏ß¿Ã ¿œƒ°«œ¡ˆ æ æ∆µµ π´Ω√µ»¥Ÿ.
	if (memcmp(m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cName, pItemName, 20) != 0) {
		PutLogList("GiveItemHandler - Not matching Item name");
		return;
	}

	ZeroMemory(cCharName, sizeof(cCharName));

	if ( ( (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_CONSUME) ||
		   (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_ARROW) ) &&
		 (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwCount > (DWORD)iAmount) ) {
		// º“∫Òº∫ æ∆¿Ã≈€¿Ãæ˙∞Ì ºˆ∑Æ∏∏≈≠ ∞®º“Ω√≈∞∞Ì ≥≤¿∫ ∞‘ ¿÷¥Ÿ∏È 
		
		pItem = new class CItem;
		if (_bInitItemAttr(pItem, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cName) == FALSE) {
			// ∫–«“«œ∞Ì¿⁄ «œ¥¬ æ∆¿Ã≈€¿Ã ∏ÆΩ∫∆Æø° æ¯¥¬ ∞≈¥Ÿ. ¿Ã∑± ¿œ¿∫ ¿œæÓ≥Ø ºˆ∞° æ¯¡ˆ∏∏ 
			delete pItem;
			return;
		}
		else {
			pItem->m_dwCount = iAmount;
		}

		// ºˆ∑Æ ∞®º“: 0∫∏¥Ÿ ≈©¥Ÿ.
		m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwCount -= iAmount;

		// ∫Ø∞Êµ» ºˆ∑Æ¿ª º≥¡§«œ∞Ì æÀ∏∞¥Ÿ.
		// v1.41 !!! æ∆¿Ã≈€ ¿Ã∏ßø°º≠ ¿Œµ¶Ω∫∑Œ ∫Ø∞Êµ«æ˙¥Ÿ. 
		SetItemCount(iClientH, sItemIndex, m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwCount);
		
		//¿Ã¡¶ dX, dYø° ¿÷¥¬ ø¿∫Í¡ß∆Æø°∞‘ º“∫Òº∫ æ∆¿Ã≈€¿ª ∞«≥◊¡ÿ¥Ÿ. 
		m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->GetOwner(&sOwnerH, &cOwnerType, dX, dY);
		
		// v1.4 ¡÷∞Ì¿⁄ «— ∞¥√ºøÕ ∏¬¥¬¡ˆ ∆«¥‹«—¥Ÿ.
		if (wObjectID != NULL) { 
			if (wObjectID < 10000) {
				// «√∑π¿ÃæÓ 
				if ((wObjectID > 0) && (wObjectID < DEF_MAXCLIENTS)) {
					if (m_pClientList[wObjectID] != NULL) {
						if ((WORD)sOwnerH != wObjectID) sOwnerH = NULL;
					}
				}
			}
			else {
				// NPC
				if ((wObjectID - 10000 > 0) && (wObjectID - 10000 < DEF_MAXNPCS)) {
					if (m_pNpcList[wObjectID - 10000] != NULL) {
						if ((WORD)sOwnerH != (wObjectID - 10000)) sOwnerH = NULL;
					}
				}
			}
		}

		if (sOwnerH == NULL) {
			// ¡÷∞Ì¿⁄ «œ¥¬ ¿ßƒ°ø° æ∆π´µµ æ¯¥Ÿ.
			// æ∆¿Ã≈€¿ª º≠¿÷¥¬ ¿ßƒ°ø° πˆ∏∞¥Ÿ. 
			m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY, pItem);
			
			// v1.411  
			_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, pItem);
	
			// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
			SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
				                        m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
				                        pItem->m_sSprite, pItem->m_sSpriteFrame, pItem->m_cItemColor); //v1.4 color
		}
		else {
			// æ∆¿Ã≈€¿ª ¡ÿ¥Ÿ.
			if (cOwnerType == DEF_OWNERTYPE_PLAYER) {
				// «√∑π¿ÃæÓø°∞‘ ¡÷æ˙¥Ÿ.
				memcpy(cCharName, m_pClientList[sOwnerH]->m_cCharName, 10);

				if (sOwnerH == iClientH) {
					// ∏∏æ‡ ¿⁄±‚ ¿⁄Ω≈ø°∞‘ ¡÷¥¬ ∞≈∂Û∏È π´Ω√«—¥Ÿ. «ÿ≈∑¿« º“¡ˆ∞° ¿÷¥Ÿ.
					delete pItem;
					return;
				}
				
				if (_bAddClientItemList(sOwnerH, pItem, &iEraseReq) == TRUE) {
					// æ∆¿Ã≈€¿ª »πµÊ«ﬂ¥Ÿ.
					dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
					*dwp = MSGID_NOTIFY;
					wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
					*wp  = DEF_NOTIFY_ITEMOBTAINED;
				
					cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);

					_bItemLog(DEF_ITEMLOG_GIVE, iClientH, sOwnerH, pItem);

					// 1∞≥ »πµÊ«ﬂ¥Ÿ. Amount∞° æ∆¥œ¥Ÿ!
					*cp = 1;
					cp++;

					memcpy(cp, pItem->m_cName, 20);
					cp += 20;

					dwp  = (DWORD *)cp;
					*dwp = pItem->m_dwCount;	// ºˆ∑Æ¿ª ¿‘∑¬ 
					cp += 4;

					*cp = pItem->m_cItemType;
					cp++;

					*cp = pItem->m_cEquipPos;
					cp++;

					*cp = (char)0; // æÚ¿∫ æ∆¿Ã≈€¿Ãπ«∑Œ ¿Â¬¯µ«¡ˆ æ æ“¥Ÿ.
					cp++;

					sp  = (short *)cp;
					*sp = pItem->m_sLevelLimit;
					cp += 2;
	
					*cp = pItem->m_cGenderLimit;
					cp++;

					wp = (WORD *)cp;
					*wp = pItem->m_wCurLifeSpan;
					cp += 2;
		
					wp = (WORD *)cp;
					*wp = pItem->m_wWeight;
					cp += 2;

					sp  = (short *)cp;
					*sp = pItem->m_sSprite;
					cp += 2;

					sp  = (short *)cp;
					*sp = pItem->m_sSpriteFrame;
					cp += 2;

					*cp = pItem->m_cItemColor;
					cp++;

					*cp = (char)pItem->m_sItemSpecEffectValue2; // v1.41 
					cp++;
					
					dwp = (DWORD *)cp;
					*dwp = pItem->m_dwAttribute;
					cp += 4;
					
					*cp = (char)pItem->m_sItemSpecEffectValue3;
					cp++;
					/*
					*cp = (char)(pItem->m_dwAttribute & 0x00000001); // Custom-Item¿Œ¡ˆ¿« ø©∫Œ 
					cp++;
					*/

					if (iEraseReq == 1) delete pItem;

					// æ∆¿Ã≈€ ¡§∫∏ ¿¸º€ 
					iRet = m_pClientList[sOwnerH]->m_pXSock->iSendMsg(cData, 54);
					switch (iRet) {
					case DEF_XSOCKEVENT_QUENEFULL:
					case DEF_XSOCKEVENT_SOCKETERROR:
					case DEF_XSOCKEVENT_CRITICALERROR:
					case DEF_XSOCKEVENT_SOCKETCLOSED:
						// ∏ﬁΩ√¡ˆ∏¶ ∫∏≥æ∂ß ø°∑Ø∞° πﬂª˝«ﬂ¥Ÿ∏È ¡¶∞≈«—¥Ÿ.
						DeleteClient(sOwnerH, TRUE, TRUE);
						break;
					}

					// v1.4 ºˆ∑Æ¥‹¿ß¿« æ∆¿Ã≈€¿ª ¿¸¥ﬁ«— ∞Õ¿ª æÀ∑¡¡ÿ¥Ÿ. 
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIVEITEMFIN_COUNTCHANGED, sItemIndex, iAmount, NULL, cCharName);
				}
				else {
					// æ∆¿Ã≈€¿ª ¿¸¥ﬁπﬁ¿∫ ƒ≥∏Ø≈Õ∞° ¥ı¿ÃªÛ æ∆¿Ã≈€¿ª ∫∏∞¸«“ ºˆ æ¯¥¬ ªÛ≈¬¿Ã¥Ÿ.
					// æ∆¿Ã≈€¿ª º≠¿÷¥¬ ¿ßƒ°ø° πˆ∏∞¥Ÿ. 
					m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, 
							                                                     m_pClientList[iClientH]->m_sY, 
																			     pItem);

					// v1.411  
					_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, pItem);
	
					// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
					SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
							                    m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
								                pItem->m_sSprite, pItem->m_sSpriteFrame, pItem->m_cItemColor); //v1.4 color

					// ¥ı¿ÃªÛ ∞°¡˙ºˆ æ¯¥Ÿ¥¬ ∏ﬁΩ√¡ˆ∏¶ ∫∏≥Ω¥Ÿ.
					dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
					*dwp = MSGID_NOTIFY;
					wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
					*wp  = DEF_NOTIFY_CANNOTCARRYMOREITEM;
			
					iRet = m_pClientList[sOwnerH]->m_pXSock->iSendMsg(cData, 6);
					switch (iRet) {
					case DEF_XSOCKEVENT_QUENEFULL:
					case DEF_XSOCKEVENT_SOCKETERROR:
					case DEF_XSOCKEVENT_CRITICALERROR:
					case DEF_XSOCKEVENT_SOCKETCLOSED:
						// ∏ﬁΩ√¡ˆ∏¶ ∫∏≥æ∂ß ø°∑Ø∞° πﬂª˝«ﬂ¥Ÿ∏È ¡¶∞≈«—¥Ÿ.
						DeleteClient(sOwnerH, TRUE, TRUE);
						break;
					}

					// v1.4 ºˆ∑Æ¥‹¿ß¿« æ∆¿Ã≈€¿ª ¿¸¥ﬁø° Ω«∆–«ﬂ¿Ω¿ª æÀ∏∞¥Ÿ.
					SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CANNOTGIVEITEM, sItemIndex, iAmount, NULL, cCharName);
				}

			}
			else {
				// NPCø°∞‘ æ∆¿Ã≈€¿ª ¡÷æ˙¥Ÿ.
				memcpy(cCharName, m_pNpcList[sOwnerH]->m_cNpcName, 20);

				if (memcmp(m_pNpcList[sOwnerH]->m_cNpcName, "Howard", 6) == 0) {
					// NPC∞° √¢∞Ì ¡÷¿Œ¿Ãæ˙¥Ÿ∏È π∞∞«¿ª ∫∏∞¸«œ∞⁄¥Ÿ¥¬ ¿«πÃ¿Ã¥Ÿ. 
					if (bSetItemToBankItem(iClientH, pItem) == FALSE) {
						// π∞∞«¿ª ∏√±‚¥¬µ• Ω«∆–«œø¥¥Ÿ.	
						SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CANNOTITEMTOBANK, NULL, NULL, NULL, NULL);

						// Ω«∆–«ﬂ¿∏π«∑Œ πŸ¥⁄ø° ∂≥±∫¥Ÿ.
						m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY, pItem);

						// v1.411  
						_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, pItem);
	
						// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
						SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
								                    m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
									                pItem->m_sSprite, pItem->m_sSpriteFrame, pItem->m_cItemColor); // v1.4 color
					}
		   		}
				else {
					// ¿œπ› NPCø°∞‘ æ∆¿Ã≈€¿ª ¡÷∏È æ∆¿Ã≈€¿ª º≠¿÷¥¬ ¿ßƒ°ø° πˆ∑¡æﬂ «—¥Ÿ. 
					m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY, pItem);

					// v1.411  
					_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, pItem);
	
					// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
					SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
							                    m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
								                pItem->m_sSprite, pItem->m_sSpriteFrame, pItem->m_cItemColor); // v1.4 color
				}
			}
		}
	}
	else {
		// æ∆¿Ã≈€ ¿¸∫Œ∏¶ ¡÷æ˙¥Ÿ.
		
		// ¿Â¬¯¡ﬂ¿Œ æ∆¿Ã≈€¿ª ¡÷æ˙¥Ÿ∏È æ∆¿Ã≈€ ¿Â¬¯»ø∞˙∏¶ «ÿ¡¶«ÿæﬂ «œπ«∑Œ.
		ReleaseItemHandler(iClientH, sItemIndex, TRUE);

		// √≥∏Æµµ¡ﬂ ø°∑Ø∞° πﬂª˝«“∂ß∏¶ ¥Î∫Ò«ÿº≠ -1∑Œ «“¥Á«ÿ ≥ı¥¬¥Ÿ.
		if (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemType == DEF_ITEMTYPE_ARROW) 
			m_pClientList[iClientH]->m_cArrowIndex = -1;
		
		//¿Ã¡¶ dX, dYø° ¿÷¥¬ ø¿∫Í¡ß∆Æø°∞‘ º“∫Òº∫ æ∆¿Ã≈€¿ª ∞«≥◊¡ÿ¥Ÿ. 
		m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->GetOwner(&sOwnerH, &cOwnerType, dX, dY); // æ∆¿Ã≈€¿ª dX, dYø° ¿÷¥¬ ƒ≥∏Ø≈Õø°∞‘ ¡ÿ¥Ÿ. ∏∏æ‡ πﬁ¿ª ƒ≥∏Ø≈Õ∞° æ∆¿Ã≈€¿ª πﬁ¡ˆ ∏¯«“ ªÛ»≤¿Ã∂Û∏È ∂•ø° ∂≥æÓ¡¯¥Ÿ.  
		
		// v1.4 ¡÷∞Ì¿⁄ «— ∞¥√ºøÕ ∏¬¥¬¡ˆ ∆«¥‹«—¥Ÿ.
		if (wObjectID != NULL) { 
			if (wObjectID < 10000) {
				// «√∑π¿ÃæÓ 
				if ((wObjectID > 0) && (wObjectID < DEF_MAXCLIENTS)) {
					if (m_pClientList[wObjectID] != NULL) {
						if ((WORD)sOwnerH != wObjectID) sOwnerH = NULL;
					}
				}
			}
			else {
				// NPC
				if ((wObjectID - 10000 > 0) && (wObjectID - 10000 < DEF_MAXNPCS)) {
					if (m_pNpcList[wObjectID - 10000] != NULL) {
						if ((WORD)sOwnerH != (wObjectID - 10000)) sOwnerH = NULL;
					}
				}
			}
		}
	
		if (sOwnerH == NULL) {
			// æ∆¿Ã≈€¿ª ¡÷∞Ì¿⁄ «œ¥¬ ¿Âº“ø° ƒ≥∏Ø≈Õ∞° æ¯¥Ÿ. 
			// æ∆¿Ã≈€¿ª º≠¿÷¥¬ ¿ßƒ°ø° πˆ∏∞¥Ÿ. 
			m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, 
			                                                             m_pClientList[iClientH]->m_sY, 
																	     m_pClientList[iClientH]->m_pItemList[sItemIndex]);
			// v1.411  
			_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, m_pClientList[iClientH]->m_pItemList[sItemIndex]);
	
			// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
			SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
				                        m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
				                        m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSprite, 
								        m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSpriteFrame, 
										m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemColor); // v1.4 color
		
			// ¿Ã¡¶ æ∆¿Ã≈€¿Ã ∂≥æÓ¡≥¿∏π«∑Œ ∏ÆΩ∫∆Æø°º≠ ªË¡¶«“∞Õ¿ª ≈Î∫∏«—¥Ÿ.
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_DROPITEMFIN_ERASEITEM, sItemIndex, iAmount, NULL, NULL);
		}
		else {
			// æ∆¿Ã≈€¿ª ¥Ÿ∏• ƒ≥∏Ø≈Õø°∞‘ ¡ÿ¥Ÿ. @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		
			if (cOwnerType == DEF_OWNERTYPE_PLAYER) {
				// ƒ≥∏Ø≈Õø°∞‘ æ∆¿Ã≈€¿ª ¡÷æ˙¥Ÿ.	
				memcpy(cCharName, m_pClientList[sOwnerH]->m_cCharName, 10);
				pItem = m_pClientList[iClientH]->m_pItemList[sItemIndex];
				
				// v2.03 ≈©∑Áºº¿ÃµÂ ∏µÂ¿Œ∞ÊøÏµµ ±ÊµÂ ∞°¿‘¿∫ ∞°¥…«œ¥Ÿ.

				// v2.17 2002-7-31 æ∆¿Ã≈€¿ª æ∆¿Ã≈€ ∞Ì¿Øπ¯»£∑Œ ª˝º∫«“ ºˆ ¿÷∞‘ «—¥Ÿ.
				if (pItem->m_sIDnum == 88) {

					// «√∑π¿ÃæÓ iClientH ∞° sOwnerHø°∞‘ ±ÊµÂ∞°¿‘ Ω≈√ªº≠∏¶ ¡÷æ˙¥Ÿ. ∏∏æ‡ 
					// sOwnerH∞° ±ÊµÂ∏∂Ω∫≈Õ∂Û∏È æ∆¿Ã≈€¿ª πﬁ¥¬ ∞Õ¿Ã æ∆¥œ∂Û »Æ¿Œ¿ª «ÿ ¡÷æÓæﬂ «—¥Ÿ.
				
					if ((m_pClientList[iClientH]->m_iGuildRank == -1) && 
						(m_pClientList[iClientH]->m_cSide != DEF_NETURAL) &&
						(m_pClientList[iClientH]->m_cSide == m_pClientList[sOwnerH]->m_cSide) &&
						(m_pClientList[sOwnerH]->m_iGuildRank == 0) ) {
						// ±ÊµÂ ∏∂Ω∫≈Õ¿Ã¥Ÿ.	±ÊµÂ ∏∂Ω∫≈Õø°∞‘¥¬ ∞°¿‘»Æ¿Œ ø‰√ª ∏ﬁΩ√¡ˆ∏¶ ¿¸º€«—¥Ÿ.
						SendNotifyMsg(iClientH, sOwnerH, DEF_NOTIFY_QUERY_JOINGUILDREQPERMISSION, NULL, NULL, NULL, NULL);
						// ¿Ã¡¶ æ∆¿Ã≈€¿ª ¡ÿ ∫ª¿Œø°∞‘ æ∆¿Ã≈€¿ª ¡÷æ˙¿∏π«∑Œ ∏ÆΩ∫∆Æø°º≠ ªË¡¶«“∞Õ¿ª ≈Î∫∏«—¥Ÿ.
						SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIVEITEMFIN_ERASEITEM, sItemIndex, 1, NULL, cCharName);

						_bItemLog(DEF_ITEMLOG_DEPLETE, iClientH,(int) -1, pItem);
					
						goto REMOVE_ITEM_PROCEDURE;
					}
				}

				// v2.17 2002-7-31 æ∆¿Ã≈€¿ª æ∆¿Ã≈€ ∞Ì¿Øπ¯»£∑Œ ª˝º∫«“ ºˆ ¿÷∞‘ «—¥Ÿ.
				if ((m_bIsCrusadeMode == FALSE) && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum == 89)) {

					// «√∑π¿ÃæÓ iClientH ∞° sOwnerHø°∞‘ ±ÊµÂ≈ª≈ Ω≈√ªº≠∏¶ ¡÷æ˙¥Ÿ. ∏∏æ‡ 
					// sOwnerH∞° ±ÊµÂ∏∂Ω∫≈Õ¿Ã∞Ì iClientHøÕ ±ÊµÂ ¿Ã∏ß¿Ã ∞∞∞Ì iClientH∞° ±ÊµÂø¯¿Ã∂Û∏È 
					// æ∆¿Ã≈€¿ª πﬁ¥¬ ∞Õ¿Ã æ∆¥œ∂Û »Æ¿Œ¿ª «ÿ ¡÷æÓæﬂ «—¥Ÿ.
					if ( (memcmp(m_pClientList[iClientH]->m_cGuildName, m_pClientList[sOwnerH]->m_cGuildName, 20) == 0) && 
						 (m_pClientList[iClientH]->m_iGuildRank != -1) && 
						 (m_pClientList[sOwnerH]->m_iGuildRank == 0) ) {
						// ±ÊµÂ ∏∂Ω∫≈Õ¿Ã¥Ÿ.	±ÊµÂ ∏∂Ω∫≈Õø°∞‘¥¬ ≈ª≈»Æ¿Œ ø‰√ª ∏ﬁΩ√¡ˆ∏¶ ¿¸º€«—¥Ÿ.
						SendNotifyMsg(iClientH, sOwnerH, DEF_NOTIFY_QUERY_DISMISSGUILDREQPERMISSION, NULL, NULL, NULL, NULL);
						// ¿Ã¡¶ æ∆¿Ã≈€¿ª ¡ÿ ∫ª¿Œø°∞‘ æ∆¿Ã≈€¿ª ¡÷æ˙¿∏π«∑Œ ∏ÆΩ∫∆Æø°º≠ ªË¡¶«“∞Õ¿ª ≈Î∫∏«—¥Ÿ.
						SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIVEITEMFIN_ERASEITEM, sItemIndex, 1, NULL, cCharName);

						_bItemLog(DEF_ITEMLOG_DEPLETE, iClientH,(int) -1, pItem);
					
						goto REMOVE_ITEM_PROCEDURE;
					}
				}

				// ¿œπ›¿˚¿Œ ∞ÊøÏ æ∆¿Ã≈€¿ª ±◊¿˙ πﬁ¿ª ª”...
				if (_bAddClientItemList(sOwnerH, pItem, &iEraseReq) == TRUE) {
					
					// v1.41 »Ò±Õ æ∆¿Ã≈€¿ª ¿¸¥ﬁ«— ∞Õ¿Ã∂Û∏È ∑Œ±◊∏¶ ≥≤±‰¥Ÿ. 
					_bItemLog(DEF_ITEMLOG_GIVE, iClientH, sOwnerH, pItem);

					// æ∆¿Ã≈€¿ª »πµÊ«ﬂ¥Ÿ.
					dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
					*dwp = MSGID_NOTIFY;
					wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
					*wp  = DEF_NOTIFY_ITEMOBTAINED;
				
					cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);

					// 1∞≥ »πµÊ«ﬂ¥Ÿ.
					*cp = 1;
					cp++;

					memcpy(cp, pItem->m_cName, 20);
					cp += 20;

					dwp  = (DWORD *)cp;
					*dwp = pItem->m_dwCount;
					cp += 4;

					*cp = pItem->m_cItemType;
					cp++;

					*cp = pItem->m_cEquipPos;
					cp++;

					*cp = (char)0; // æÚ¿∫ æ∆¿Ã≈€¿Ãπ«∑Œ ¿Â¬¯µ«¡ˆ æ æ“¥Ÿ.
					cp++;

					sp  = (short *)cp;
					*sp = pItem->m_sLevelLimit;
					cp += 2;
	
					*cp = pItem->m_cGenderLimit;
					cp++;

					wp = (WORD *)cp;
					*wp = pItem->m_wCurLifeSpan;
					cp += 2;
		
					wp = (WORD *)cp;
					*wp = pItem->m_wWeight;
					cp += 2;

					sp  = (short *)cp;
					*sp = pItem->m_sSprite;
					cp += 2;

					sp  = (short *)cp;
					*sp = pItem->m_sSpriteFrame;
					cp += 2;

					*cp = pItem->m_cItemColor;
					cp++;

					*cp = (char)pItem->m_sItemSpecEffectValue2; // v1.41 
					cp++;
					
					dwp = (DWORD *)cp;
					*dwp = pItem->m_dwAttribute;
					cp += 4;

					*cp = (char)pItem->m_sItemSpecEffectValue3;
					cp++;
					/*
					*cp = (char)(pItem->m_dwAttribute & 0x00000001); // Custom-Item¿Œ¡ˆ¿« ø©∫Œ 
					cp++;
					*/

					if (iEraseReq == 1) delete pItem;

					// æ∆¿Ã≈€ ¡§∫∏ ¿¸º€ 
					iRet = m_pClientList[sOwnerH]->m_pXSock->iSendMsg(cData, 54);
					switch (iRet) {
					case DEF_XSOCKEVENT_QUENEFULL:
					case DEF_XSOCKEVENT_SOCKETERROR:
					case DEF_XSOCKEVENT_CRITICALERROR:
					case DEF_XSOCKEVENT_SOCKETCLOSED:
						// ∏ﬁΩ√¡ˆ∏¶ ∫∏≥æ∂ß ø°∑Ø∞° πﬂª˝«ﬂ¥Ÿ∏È ¡¶∞≈«—¥Ÿ.
						DeleteClient(sOwnerH, TRUE, TRUE);
						break;
					}
				}
				else {
					// æ∆¿Ã≈€¿ª ¿¸¥ﬁπﬁ¿∫ ƒ≥∏Ø≈Õ∞° ¥ı¿ÃªÛ æ∆¿Ã≈€¿ª ∫∏∞¸«“ ºˆ æ¯¥¬ ªÛ≈¬¿Ã¥Ÿ.
					// æ∆¿Ã≈€¿ª º≠¿÷¥¬ ¿ßƒ°ø° πˆ∏∞¥Ÿ. 
					m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, 
							                                                     m_pClientList[iClientH]->m_sY, 
																			     m_pClientList[iClientH]->m_pItemList[sItemIndex]);
					// v1.41 »Ò±Õ æ∆¿Ã≈€¿ª ∂≥æÓ∂ﬂ∏∞ ∞Õ¿Ã∂Û∏È ∑Œ±◊∏¶ ≥≤±‰¥Ÿ. 
					_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, m_pClientList[iClientH]->m_pItemList[sItemIndex]);
					
					// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
					SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
							                    m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
								                m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSprite, 
										        m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSpriteFrame, 
												m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemColor); // v1.4 color

					// ¥ı¿ÃªÛ ∞°¡˙ºˆ æ¯¥Ÿ¥¬ ∏ﬁΩ√¡ˆ∏¶ ∫∏≥Ω¥Ÿ.
					dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
					*dwp = MSGID_NOTIFY;
					wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
					*wp  = DEF_NOTIFY_CANNOTCARRYMOREITEM;
			
					iRet = m_pClientList[sOwnerH]->m_pXSock->iSendMsg(cData, 6);
					switch (iRet) {
					case DEF_XSOCKEVENT_QUENEFULL:
					case DEF_XSOCKEVENT_SOCKETERROR:
					case DEF_XSOCKEVENT_CRITICALERROR:
					case DEF_XSOCKEVENT_SOCKETCLOSED:
						// ∏ﬁΩ√¡ˆ∏¶ ∫∏≥æ∂ß ø°∑Ø∞° πﬂª˝«ﬂ¥Ÿ∏È ¡¶∞≈«—¥Ÿ.
						DeleteClient(sOwnerH, TRUE, TRUE);
						break;
					}

					// v1.4 æ∆¿Ã≈€ ¿¸¥ﬁ¿Ã Ω«∆–«ﬂ¿Ω¿ª æÀ∏Æ¥¬ πÊπ˝ 
					ZeroMemory(cCharName, sizeof(cCharName));
				}
			}
			else {
				// NPCø°∞‘ æ∆¿Ã≈€¿ª ¡÷æ˙¥Ÿ.
				memcpy(cCharName, m_pNpcList[sOwnerH]->m_cNpcName, 20);

				if (memcmp(m_pNpcList[sOwnerH]->m_cNpcName, "Howard", 6) == 0) {
					// NPC∞° √¢∞Ì ¡÷¿Œ¿Ãæ˙¥Ÿ∏È π∞∞«¿ª ∫∏∞¸«œ∞⁄¥Ÿ¥¬ ¿«πÃ¿Ã¥Ÿ. 
					if (bSetItemToBankItem(iClientH, sItemIndex) == FALSE) {
						// æ∆¿Ã≈€¿ª ∫∏∞¸«œ¥¬µ• Ω«∆–«œø© πŸ¥⁄ø° ∂≥æÓ¡≥¥Ÿ.
						SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_CANNOTITEMTOBANK, NULL, NULL, NULL, NULL);
						
						// Ω«∆–«ﬂ¿∏π«∑Œ πŸ¥⁄ø° ∂≥±∫¥Ÿ.
						m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, 
						                                                         	 m_pClientList[iClientH]->m_sY, 
							                                                         m_pClientList[iClientH]->m_pItemList[sItemIndex]);
						
						// v1.41 »Ò±Õ æ∆¿Ã≈€¿ª ∂≥æÓ∂ﬂ∏∞ ∞Õ¿Ã∂Û∏È ∑Œ±◊∏¶ ≥≤±‰¥Ÿ. 
						_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, m_pClientList[iClientH]->m_pItemList[sItemIndex]);
						
						// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
						SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
							                        m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
							                        m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSprite, 
							                        m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSpriteFrame, 
													m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemColor); // v1.4 color
					}
				}
				else if (memcmp(m_pNpcList[sOwnerH]->m_cNpcName, "Kennedy", 7) == 0) {
					// ±ÊµÂ ªÁπ´¿Âø°∞‘ ±ÊµÂ ≈ª≈ Ω≈√ªº≠∏¶ ¡÷æ˙¥Ÿ∏È ±ÊµÂ∏¶ ≈ª≈«—¥Ÿ. 

					// v2.17 2002-7-31 æ∆¿Ã≈€¿ª æ∆¿Ã≈€ ∞Ì¿Øπ¯»£∑Œ ª˝º∫«“ ºˆ ¿÷∞‘ «—¥Ÿ.
					if ((m_bIsCrusadeMode == FALSE) && (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sIDnum == 89)) {
						if ((m_pClientList[iClientH]->m_iGuildRank != 0) && (m_pClientList[iClientH]->m_iGuildRank != -1)) {
							// ≈ª≈ Ω≈√ª¿⁄ø°∞‘ ≈ª≈ º∫∞¯«ﬂ¿Ω¿ª æÀ∏Æ¥¬ ∏ﬁΩ√¡ˆ∏¶ ∫∏≥ª¡ÿ¥Ÿ.
							SendNotifyMsg(iClientH, iClientH, DEF_COMMONTYPE_DISMISSGUILDAPPROVE, NULL, NULL, NULL, NULL);

#ifdef DEF_TAIWANLOG
							_bItemLog(DEF_ITEMLOG_BANGUILD,iClientH,(char *)NULL,NULL) ;
#endif
							// ±ÊµÂ ≈ª≈. 
							ZeroMemory(m_pClientList[iClientH]->m_cGuildName, sizeof(m_pClientList[iClientH]->m_cGuildName));
							memcpy(m_pClientList[iClientH]->m_cGuildName, "NONE", 4);
							m_pClientList[iClientH]->m_iGuildRank = -1;
							m_pClientList[iClientH]->m_iGuildGUID = -1;

							// ∆Øº∫¿Ã πŸ≤Óπ«∑Œ ø‹æÁ¿ª ªı∑Œ ∫∏≥Ω¥Ÿ. 
							SendEventToNearClient_TypeA(iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);

							// æ‡∞£¿« ∞Ê«Ëƒ°∞° «œ∂Ù«—¥Ÿ.
							m_pClientList[iClientH]->m_iExp -= 300;
							if (m_pClientList[iClientH]->m_iExp < 0) m_pClientList[iClientH]->m_iExp = 0;
							SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_EXP, NULL, NULL, NULL, NULL);
						}

						// ¿Ã æ∆¿Ã≈€¿∫ ªË¡¶Ω√ƒ—æﬂ «—¥Ÿ. 
						delete m_pClientList[iClientH]->m_pItemList[sItemIndex];
					} 
					else {
						// ±ÊµÂ ≈ª≈ Ω≈√ªº≠∞° æ∆¥œ∂Û∏È πŸ¥⁄ø° ∂≥±∫¥Ÿ. ≈©∑Áºº¿ÃµÂ ∏µÂ¿œ∂ßµµ ±ÊµÂ ∞¸∑√ ø¨ªÍ ∫“∞° 
						m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, 
							                                                     m_pClientList[iClientH]->m_sY, 
																			     m_pClientList[iClientH]->m_pItemList[sItemIndex]);

						// v1.41 »Ò±Õ æ∆¿Ã≈€¿ª ∂≥æÓ∂ﬂ∏∞ ∞Õ¿Ã∂Û∏È ∑Œ±◊∏¶ ≥≤±‰¥Ÿ. 
						_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, m_pClientList[iClientH]->m_pItemList[sItemIndex]);
					
						// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
						SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
							                    m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
								                m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSprite, 
										        m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSpriteFrame, 
												m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemColor); // v1.4 color

						// v1.4 æ∆¿Ã≈€ ¿¸¥ﬁ¿Ã Ω«∆–«ﬂ¿Ω¿ª æÀ∏Æ¥¬ πÊπ˝ 
						ZeroMemory(cCharName, sizeof(cCharName));

					}
				}
				else {
					// ¿œπ› NPCø°∞‘ æ∆¿Ã≈€¿ª ¡÷∏È æ∆¿Ã≈€¿ª º≠¿÷¥¬ ¿ßƒ°ø° πˆ∑¡æﬂ «—¥Ÿ. 

					m_pMapList[ m_pClientList[iClientH]->m_cMapIndex ]->bSetItem(m_pClientList[iClientH]->m_sX, 
							                                                     m_pClientList[iClientH]->m_sY, 
																			     m_pClientList[iClientH]->m_pItemList[sItemIndex]);

					// v1.41 »Ò±Õ æ∆¿Ã≈€¿ª ∂≥æÓ∂ﬂ∏∞ ∞Õ¿Ã∂Û∏È ∑Œ±◊∏¶ ≥≤±‰¥Ÿ. 
					_bItemLog(DEF_ITEMLOG_DROP, iClientH, (int) -1, m_pClientList[iClientH]->m_pItemList[sItemIndex]);
					
					// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆Æø°∞‘ æ∆¿Ã≈€¿Ã ∂≥æÓ¡¯ ∞Õ¿ª æÀ∏∞¥Ÿ. 
					SendEventToNearClient_TypeB(MSGID_EVENT_COMMON, DEF_COMMONTYPE_ITEMDROP, m_pClientList[iClientH]->m_cMapIndex,
							                    m_pClientList[iClientH]->m_sX, m_pClientList[iClientH]->m_sY,  
								                m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSprite, 
										        m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_sSpriteFrame, 
												m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cItemColor); // v1.4 color

					// v1.4 æ∆¿Ã≈€ ¿¸¥ﬁ¿Ã Ω«∆–«ﬂ¿Ω¿ª æÀ∏Æ¥¬ πÊπ˝ 
					ZeroMemory(cCharName, sizeof(cCharName));
				}
			}

			// ¿Ã¡¶ æ∆¿Ã≈€¿ª ¡ÿ ∫ª¿Œø°∞‘ æ∆¿Ã≈€¿ª ¡÷æ˙¿∏π«∑Œ ∏ÆΩ∫∆Æø°º≠ ªË¡¶«“∞Õ¿ª ≈Î∫∏«—¥Ÿ.
			SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_GIVEITEMFIN_ERASEITEM, sItemIndex, iAmount, NULL, cCharName);
		}

REMOVE_ITEM_PROCEDURE:;

		// ≥◊∆Æøˆ≈© ø¿∑˘∑Œ √≥∏Æµµ¡ﬂ ≈¨∂Û¿Ãæ∆Æ∞° ¡¶∞≈µ«æ˙¥Ÿ∏È ¥ı¿ÃªÛ ¡¯«‡«“ ºˆ æ¯¥Ÿ. 
		if (m_pClientList[iClientH] == NULL) return;

		// æ∆¿Ã≈€¿ª ¡÷∞≈≥™ πˆ∑»¿∏π«∑Œ ¡ˆøÓ¥Ÿ. delete«ÿº≠¥¬ æ»µ»¥Ÿ! 
		m_pClientList[iClientH]->m_pItemList[sItemIndex] = NULL;
		m_pClientList[iClientH]->m_bIsItemEquipped[sItemIndex] = FALSE;
		
		// »≠ªÏ ¿Œµ¶Ω∫∏¶ ¿Á «“¥Á
		m_pClientList[iClientH]->m_cArrowIndex = _iGetArrowItemIndex(iClientH);
	}

	// º“¡ˆ«∞ √— ¡ﬂ∑Æ ¿Á ∞ËªÍ 
	iCalcTotalWeight(iClientH);
	
}
void CGame::Effect_SpUp_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3)
{
 int iSP, iMaxSP;
 DWORD dwTime = timeGetTime();

	if (cAttackerType == DEF_OWNERTYPE_PLAYER)
		if (m_pClientList[sAttackerH] == NULL) return;

	// «ÿ¥Á ≈∏ƒœ¿« Sp∏¶ ø√∏∞¥Ÿ.
	iSP = iDice(sV1, sV2) + sV3;
	
	switch (cTargetType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sTargetH] == NULL) return;
		if (m_pClientList[sTargetH]->m_bIsKilled == TRUE) return;
	
		iMaxSP = (2*(m_pClientList[sTargetH]->m_iStr+m_pClientList[sTargetH]->m_iAngelicStr)) + (2*m_pClientList[sTargetH]->m_iLevel);
		if (m_pClientList[sTargetH]->m_iSP < iMaxSP) {
			m_pClientList[sTargetH]->m_iSP += iSP;
			
			if (m_pClientList[sTargetH]->m_iSP > iMaxSP) 
				m_pClientList[sTargetH]->m_iSP = iMaxSP;

			SendNotifyMsg(NULL, sTargetH, DEF_NOTIFY_SP, NULL, NULL, NULL, NULL);
		}
		break;

	case DEF_OWNERTYPE_NPC:
		// NPC¥¬ Ω∫≈¬πÃ≥  ∞≥≥‰¿Ã æ¯¥Ÿ.
		break;
	}
}



BOOL CGame::bCheckResistingMagicSuccess(char cAttackerDir, short sTargetH, char cTargetType, int iHitRatio, char cNpc)
{
 double dTmp1, dTmp2, dTmp3;
 int    iTargetMagicResistRatio, iDestHitRatio, iResult;
 char   cTargetDir, cProtect;								 

	switch (cTargetType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sTargetH] == NULL) return FALSE;
        if (m_pClientList[sTargetH]->m_iAdminUserLevel > 0) return TRUE;
		if ((m_pClientList[sTargetH]->m_iStatus & 0x400000) != 0) return TRUE; 
		if (cNpc == 65) return FALSE;

		cTargetDir = m_pClientList[sTargetH]->m_cDir;
		iTargetMagicResistRatio = m_pClientList[sTargetH]->m_cSkillMastery[3] +m_pClientList[sTargetH]->m_iAddMR; // 3π¯ Resisting Magic

		if ((m_pClientList[sTargetH]->m_iMag+m_pClientList[sTargetH]->m_iAngelicMag) > 50) 
			iTargetMagicResistRatio += ((m_pClientList[sTargetH]->m_iMag+m_pClientList[sTargetH]->m_iAngelicMag) - 50);
		// √ﬂ∞° ∏∂π˝ πÊæÓ∑¸ ¥ı«‘ 
		iTargetMagicResistRatio += m_pClientList[sTargetH]->m_iAddResistMagic;
		cProtect = m_pClientList[sTargetH]->m_cMagicEffectStatus[ DEF_MAGICTYPE_PROTECT ]; 
		break;

	case DEF_OWNERTYPE_NPC:
		if (m_pNpcList[sTargetH] == NULL) return FALSE;
		cTargetDir = m_pNpcList[sTargetH]->m_cDir;
		iTargetMagicResistRatio = m_pNpcList[sTargetH]->m_cResistMagic;
		cProtect = m_pNpcList[sTargetH]->m_cMagicEffectStatus[ DEF_MAGICTYPE_PROTECT ]; 
		break;
	}

	//v2.16 2002-5-23 ∞Ì±§«ˆºˆ¡§
	// Absolute Magic Protection
	if (cProtect == 5) return TRUE;

	// ∏Ì¡ﬂ∑¸ ¿Ã¿¸ø° ∏∂π˝∫∏»£∞° ∞…∑¡¿÷¥Ÿ∏È π´¡∂∞« º∫∞¯: ¥‹ ∏Ì¡ﬂ∑¸¿Ã 1000∫∏¥Ÿ ≈©∏È ∞Ì∑¡«—¥Ÿ.
	if ((iHitRatio < 1000) && (cProtect == 2)) return TRUE;
	// ∏∏æ‡ ∏Ì¡ﬂ∑¸¿Ã 10000 ¿ÃªÛ¿Ã∂Û∏È 9Ω·≈¨ ¿ÃªÛ¿« ∏∂π˝¿Ã∂ı ¿«πÃ. ¥ŸΩ√ 10000¿ª ª©º≠ ¡¶ ∏Ì¡ﬂ∑¸¿ª ∞ËªÍ«—¥Ÿ.
	if (iHitRatio >= 10000) iHitRatio -= 10000;

	if (iTargetMagicResistRatio < 1) iTargetMagicResistRatio = 1;
	
	// v2.23 18/02/06 17:45 
	if ((cAttackerDir != 0) && (m_pClientList[sTargetH] != NULL) && (m_pClientList[sTargetH]->m_cHeroBonus == 2)) {
		iHitRatio += 50;
	}
		
	// √÷¡æ ∞¯∞› ∏Ì¡ﬂ∑¸¿ª ±∏«—¥Ÿ. 
	dTmp1 = (double)(iHitRatio);
	dTmp2 = (double)(iTargetMagicResistRatio);

	dTmp3 = (dTmp1 / dTmp2)*50.0f;
	iDestHitRatio = (int)(dTmp3); 
	
	// √÷º“ ∞¯∞› ∏Ì¡ﬂ∑¸¿ª ∫∏¿Â«—¥Ÿ. 
	if (iDestHitRatio < DEF_MINIMUMHITRATIO) iDestHitRatio = DEF_MINIMUMHITRATIO;
	// √÷¥Î ∞¯∞› ∏Ì¡ﬂ∑¸¿ª ¡¶«—«—¥Ÿ.
	if (iDestHitRatio > DEF_MAXIMUMHITRATIO) iDestHitRatio = DEF_MAXIMUMHITRATIO;
	
	if (iDestHitRatio >= 100) return FALSE; // ∏∂π˝¿∫ ∏Ì¡ﬂ«ﬂ¥Ÿ.

	iResult = iDice(1, 100);
	if (iResult <= iDestHitRatio) return FALSE;

	// ∏∂π˝ ¿˙«◊¿Ã º∫∞¯«ﬂ¿∏π«∑Œ Resisting Magic¿« SSN¿ª ¡ı∞°Ω√≈≤¥Ÿ.
/*	if (cTargetType == DEF_OWNERTYPE_PLAYER)
		CalculateSSN_SkillIndex(sTargetH, 3, 1);*/

	return TRUE;
}


BOOL CGame::bCheckResistingIceSuccess(char cAttackerDir, short sTargetH, char cTargetType, int iHitRatio)
{
 // ≥√µøµ… ∞Õ¿Œ∞°¿« »Æ∑¸ ∞ËªÍ.
 int    iTargetIceResistRatio, iResult;

	switch (cTargetType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sTargetH] == NULL) return FALSE;
		// v1.4 øÓøµ¿⁄ø° ¥Î«— ≥√µø∞¯∞›¿∫ π´¿«πÃ 
		if (m_pClientList[sTargetH]->m_iAdminUserLevel > 0) return TRUE;
		
//		if ( m_pClientList[sTargetH]->m_pItemList[sItemIndex]->m_sIDnum == 770 
//			|| m_pClientList[sTargetH]->m_pItemList[sItemIndex]->m_sIDnum == 771 )
//			return TRUE;

		iTargetIceResistRatio = m_pClientList[sTargetH]->m_iAddAbsWater*2; 
		// v2.172 «ÿµø ∆˜º«¿ª ∏‘∞Ì 30√ ∞£¿∫ æÛ¡ˆ æ ¥¬¥Ÿ.
		if (m_pClientList[sTargetH]->m_dwWarmEffectTime == NULL) {
		}
		else if ((timeGetTime() - m_pClientList[sTargetH]->m_dwWarmEffectTime) < 1000*30) return TRUE;
		break;

	case DEF_OWNERTYPE_NPC:
		if (m_pNpcList[sTargetH] == NULL) return FALSE;
		if (m_pNpcList[sTargetH]->m_cAttribute == DEF_ATTRIBUTE_WATER) return TRUE; // 2002-12-20 π∞ º”º∫¿ª ∞°¡¯ NPC¥¬ ICE ∞Ëø≠ø° µ•πÃ¡ˆ∏¶ πﬁ¡ˆ æ ¥¬¥Ÿ.
		iTargetIceResistRatio = (m_pNpcList[sTargetH]->m_cResistMagic) - (m_pNpcList[sTargetH]->m_cResistMagic/3); // ø©±‚ø° æÛ¿Ω πÊæÓ ºˆƒ° ¿‘∑¬. NPC¿« ∞ÊøÏ ∏∂π˝ ¿˙«◊¿« 70% ºˆ¡ÿ 
		break;
	}
	
	if (iTargetIceResistRatio < 1) iTargetIceResistRatio = 1;
	
	iResult = iDice(1, 100);
	if (iResult <= iTargetIceResistRatio) return TRUE;
	
	return FALSE;
}


BOOL CGame::bSetItemToBankItem(int iClientH, class CItem * pItem)
{
 register int i, iRet;
 DWORD * dwp;
 WORD  * wp;
 char  * cp;
 short * sp;
 char cData[100];		   
	
	// º“¡ˆ«œ∞Ì ¿÷¥¬ æ∆¿Ã≈€¿ª ∫∏∞¸«—¥Ÿ.
	if (m_pClientList[iClientH] == NULL) return FALSE;
	if (pItem == NULL) return FALSE;

	// v2.20 2002-12-23 √¢∞Ì¿Œ¡ˆ √º≈© «—¥Ÿ.
	if (m_pClientList[iClientH]->m_bIsOnWarehouse == FALSE) return FALSE;


	for (i = 0; i < DEF_MAXBANKITEMS; i++)
	if (m_pClientList[iClientH]->m_pItemInBankList[i] == NULL) {
		// ∫ÒæÓ¿÷¥¬ ¿ßƒ°∏¶ √£æ“¥Ÿ.
		
		// º“¡ˆ«∞ π´∞‘∏¶ ª¨ « ø‰¥¬ æ¯¥Ÿ.
		
		m_pClientList[iClientH]->m_pItemInBankList[i] = pItem;
		
		dwp  = (DWORD *)(cData + DEF_INDEX4_MSGID);
		*dwp = MSGID_NOTIFY;
		wp   = (WORD *)(cData + DEF_INDEX2_MSGTYPE);
		*wp  = DEF_NOTIFY_ITEMTOBANK;
				
		cp = (char *)(cData + DEF_INDEX2_MSGTYPE + 2);

		*cp = i; // ¿ßƒ° ¿˙¿Â 
		cp++;

		// 1∞≥.
		*cp = 1;
		cp++;

		memcpy(cp, pItem->m_cName, 20);
		cp += 20;

		dwp  = (DWORD *)cp;
		*dwp = pItem->m_dwCount;
		cp += 4;

		*cp = pItem->m_cItemType;
		cp++;

		*cp = pItem->m_cEquipPos;
		cp++;

		*cp = (char)0; 
		cp++;

		sp  = (short *)cp;
		*sp = pItem->m_sLevelLimit;
		cp += 2;
	
		*cp = pItem->m_cGenderLimit;
		cp++;
		
		wp = (WORD *)cp;
		*wp = pItem->m_wCurLifeSpan;
		cp += 2;

		wp = (WORD *)cp;
		*wp = pItem->m_wWeight;
		cp += 2;

		sp  = (short *)cp;
		*sp = pItem->m_sSprite;
		cp += 2;

		sp  = (short *)cp;
		*sp = pItem->m_sSpriteFrame;
		cp += 2;

		*cp = pItem->m_cItemColor;
		cp++;

		// v1.432
		sp = (short *)cp;
		*sp = pItem->m_sItemEffectValue2;
		cp += 2;

		// v1.42
		dwp = (DWORD *)cp;
		*dwp = pItem->m_dwAttribute;
		cp += 4;

		// v2.14 √¢∞Ìø°º≠ æ∆¿Ã≈€¿ª ∞°¿˙ø¿∏È º¯µµ∞° ¿ÃªÛ«ÿ¡ˆ¥¬ πˆ±◊ ºˆ¡§ 
		*cp = (char) pItem->m_sItemSpecEffectValue2 ;
		cp ++ ;

		*cp = (char) pItem->m_sItemSpecEffectValue3;
		cp ++ ;

		// æ∆¿Ã≈€ ¡§∫∏ ¿¸º€ 
		iRet = m_pClientList[iClientH]->m_pXSock->iSendMsg(cData, 57);

#ifdef DEF_TAIWANLOG
		_bItemLog(DEF_ITEMLOG_DEPOSIT, iClientH, (int) -1, pItem);
#endif

		// v2.13 º∫»ƒ¥œ √ﬂ∞° DB ∫Œ«œ∏¶ ¡Ÿ¿Ã±‚ ¿ß«— ∫Øºˆ
		m_pClientList[iClientH]->m_bIsBankModified = TRUE ;

		switch (iRet) {
		case DEF_XSOCKEVENT_QUENEFULL:
		case DEF_XSOCKEVENT_SOCKETERROR:
		case DEF_XSOCKEVENT_CRITICALERROR:
		case DEF_XSOCKEVENT_SOCKETCLOSED:
			// ∏ﬁΩ√¡ˆ∏¶ ∫∏≥æ∂ß ø°∑Ø∞° πﬂª˝«ﬂ¥Ÿ∏È ¡¶∞≈«—¥Ÿ. v1.41 ¡¶∞≈«œ¡ˆ æ ¥¬¥Ÿ.
			// DeleteClient(iClientH, TRUE, TRUE);
			return TRUE; // v1.41 FALSE∏¶ π›»Ø«œ∏È æ∆¿Ã≈€¿Ã πŸ¥⁄ø° ∫πªÁµ»¥Ÿ.
		}

		return TRUE;
	}

	// æ∆¿Ã≈€¿ª ∫∏∞¸«“ ø©¿Ø∞¯∞£¿Ã æ¯¥Ÿ.
	return FALSE;
}

BOOL CGame::bCheckTotalSkillMasteryPoints(int iClientH, int iSkill)
{
 register int i;
 int iRemainPoint, iTotalPoints, iWeaponIndex, iDownSkillSSN, iDownPoint;
 short sDownSkillIndex;

	if (m_b100skill == TRUE) return FALSE;
	if (m_pClientList[iClientH] == NULL) return FALSE;

	iTotalPoints = 0;
	for (i = 0; i <	DEF_MAXSKILLTYPE; i++) 
		iTotalPoints += m_pClientList[iClientH]->m_cSkillMastery[i];

	iRemainPoint = iTotalPoints - m_sCharSkillLimit;

	if (iRemainPoint > 0) {
		// ¬Ω¬∫√¬≥√√ √√∑√√√¬Æ¬∞¬° √√¬∞√∫¬µ√¬æ√∫¬¥√. √√¬∞√∫¬µ√ √√∑√√√¬Æ ¬∏¬∏√¬≠ ¬∑√ß√√¬∏¬¶ ¬µ¬π¬∏√ß SSN√√ ¬∞¬°√√• ¬≥¬∑√¬∫ ¬Ω¬∫√¬≥√¬ª ¬≥¬ª¬∏¬∞¬¥√.	
		while (iRemainPoint > 0) {
			
			sDownSkillIndex = -1; // v1.4
			if (m_pClientList[iClientH]->m_iDownSkillIndex != -1) { 
				// √√∂√¬§¬µ√ ¬Ω¬∫√¬≥√√ √√¬¥√. 
				switch (m_pClientList[iClientH]->m_iDownSkillIndex) {
				case 3: // ¬∏¬∂¬π√Ω √√∫√√

				/* √√ ¬Ω¬∫√¬≥¬µ¬µ 0√¬∏¬∑√ ¬µ√¬¥√.
				case 4:
				case 5:
				case 7:
					// 20√√√√¬∑√¬¥√ ¬∂¬≥¬æ√Æ√√∫ ¬º√∂ ¬æ√∏¬¥√ ¬±√¢¬∫¬ª¬Ω¬∫√¬≥
					if (m_pClientList[iClientH]->m_cSkillMastery[m_pClientList[iClientH]->m_iDownSkillIndex] > 20) {
						sDownSkillIndex = m_pClientList[iClientH]->m_iDownSkillIndex;
					}
					else {
						// ¬¥√¬∏¬• ¬Ω¬∫√¬≥√¬ª ¬∞√¬ª√∂√√¬¥√.
						iDownSkillSSN = 99999999;
						for (i = 0; i < DEF_MAXSKILLTYPE; i++)
						if ((m_pClientList[iClientH]->m_cSkillMastery[i] >= 21) && (i != iSkill) && 
							(m_pClientList[iClientH]->m_iSkillSSN[i] <= iDownSkillSSN)) {
							// V1.22 ¬¥√¬ø√Æ ¬Ω√√¬≥ ¬Ω¬∫√¬≥√¬∫ √√¬º√ 20 √√√√¬∑√¬¥√ ¬∂¬≥¬æ√Æ√√∫ ¬º√∂ ¬æ√∏¬¥√. 
							iDownSkillSSN = m_pClientList[iClientH]->m_iSkillSSN[i];
							sDownSkillIndex = i;
						}
					}
					break;
				*/

				default:
					// ¬Ω¬∫√¬≥√√ 20 √√√√√√ ¬ª√≥√√¬∂√≥¬∏√© ¬±√¬¥√´¬∑√ 0√¬∏¬∑√ ¬∂¬≥¬æ√Æ ¬∂√¬∏¬∞¬¥√.
					if (m_pClientList[iClientH]->m_cSkillMastery[m_pClientList[iClientH]->m_iDownSkillIndex] > 0) {
						sDownSkillIndex = m_pClientList[iClientH]->m_iDownSkillIndex;
					}
					else {
						// ¬¥√¬∏¬• ¬Ω¬∫√¬≥√¬ª ¬∞√¬ª√∂√√¬¥√.
						// ¬¥√¬∏¬• ¬Ω¬∫√¬≥√¬ª ¬∞√¬ª√∂√√¬¥√.
						iDownSkillSSN = 99999999;
						for (i = 0; i < DEF_MAXSKILLTYPE; i++)
						if ((m_pClientList[iClientH]->m_cSkillMastery[i] >= 21) && (i != iSkill) && 
							(m_pClientList[iClientH]->m_iSkillSSN[i] <= iDownSkillSSN)) {
							// V1.22 ¬¥√¬ø√Æ ¬Ω√√¬≥ ¬Ω¬∫√¬≥√¬∫ √√¬º√ 20 √√√√¬∑√¬¥√ ¬∂¬≥¬æ√Æ√√∫ ¬º√∂ ¬æ√∏¬¥√. 
							iDownSkillSSN = m_pClientList[iClientH]->m_iSkillSSN[i];
							sDownSkillIndex = i;
						}
					}
					break;
				}
			}
			// √√∂√√ß 1¬∫¬∏¬¥√ √¬´ ¬Ω¬∫√¬≥ √√¬ø¬°¬º¬≠ ¬∞¬°√√• √√√¬∫ SSN√¬ª ¬∞¬Æ¬¥√ ¬Ω¬∫√¬≥√¬∫ sDownSkillIndex 
			
			if (sDownSkillIndex != -1) {
				
				if (m_pClientList[iClientH]->m_cSkillMastery[sDownSkillIndex] <= 20) // v1.4
				 	 iDownPoint = m_pClientList[iClientH]->m_cSkillMastery[sDownSkillIndex];
				else iDownPoint = 1;

				m_pClientList[iClientH]->m_cSkillMastery[sDownSkillIndex] -= iDownPoint; // v1.4
				m_pClientList[iClientH]->m_iSkillSSN[sDownSkillIndex] = m_iSkillSSNpoint[m_pClientList[iClientH]->m_cSkillMastery[sDownSkillIndex]+1] - 1;
				iRemainPoint -= iDownPoint; // v1.4
				
				// ¬∏¬∏¬æ√† ¬≥¬∑¬æ√√√∏ ¬Ω¬∫√¬≥√√ √√∂√√ß ¬ª√ß¬ø√´√√√√ ¬π¬´¬±√¢¬ø√ ¬∞√º¬∑√√√ √√¬¥√¬∏√© ¬∏√≠√√¬∑√º√¬ª ¬≥¬∑√√¬æ√Æ¬æ√ √√¬¥√. 
				if (m_pClientList[iClientH]->m_sItemEquipmentStatus[ DEF_EQUIPPOS_TWOHAND ] != -1) {
					// ¬æ√ß¬º√¬π¬´¬±√¢¬∞¬° √√•√√∏¬µ√¬æ√Æ √√¬æ√∫¬¥√. 
					iWeaponIndex = m_pClientList[iClientH]->m_sItemEquipmentStatus[ DEF_EQUIPPOS_TWOHAND ];
					if (m_pClientList[iClientH]->m_pItemList[iWeaponIndex]->m_sRelatedSkill == sDownSkillIndex) {
						// √¬∞¬∑√π√√ ¬ª√ß¬ø√´¬ø¬° √√√√ ¬Ω¬∫√¬≥√√ √√¬∂√¥√√¬æ√∫¬¥√. ¬∏√≠√√¬∑√º√¬ª ¬≥¬∑√√°¬¥√. 
						m_pClientList[iClientH]->m_iHitRatio -= iDownPoint; // v1.4
						if (m_pClientList[iClientH]->m_iHitRatio < 0) m_pClientList[iClientH]->m_iHitRatio = 0;
					}
				}

				if (m_pClientList[iClientH]->m_sItemEquipmentStatus[ DEF_EQUIPPOS_RHAND ] != -1) {
					iWeaponIndex = m_pClientList[iClientH]->m_sItemEquipmentStatus[ DEF_EQUIPPOS_RHAND ];
					if (m_pClientList[iClientH]->m_pItemList[iWeaponIndex]->m_sRelatedSkill == sDownSkillIndex) {
						m_pClientList[iClientH]->m_iHitRatio -= iDownPoint; // v1.4
						if (m_pClientList[iClientH]->m_iHitRatio < 0) m_pClientList[iClientH]->m_iHitRatio = 0;
					}
				}
				SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SKILL, sDownSkillIndex, m_pClientList[iClientH]->m_cSkillMastery[sDownSkillIndex], NULL, NULL);
			}
			else {
				return FALSE;
			}
		}
		return TRUE;
	}

	return FALSE;
}

void CGame::Effect_SpDown_Spot(short sAttackerH, char cAttackerType, short sTargetH, char cTargetType, short sV1, short sV2, short sV3)
{
 int iSP, iMaxSP, iSideCondition;
 DWORD dwTime = timeGetTime();

	if (cAttackerType == DEF_OWNERTYPE_PLAYER)
		if (m_pClientList[sAttackerH] == NULL) return;

	// «ÿ¥Á ≈∏ƒœ¿« Sp∏¶ ≥ª∏∞¥Ÿ.
	iSP = iDice(sV1, sV2) + sV3;
	
	switch (cTargetType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sTargetH] == NULL) return;
		if (m_pClientList[sTargetH]->m_bIsKilled == TRUE) return;
		if ((m_pClientList[sTargetH]->m_iStatus & 0x400000) != 0) return;
			
		// v2.13 ∏∏æ‡ ∞¯∞›¿⁄∞° «√∑π¿ÃæÓ¿Ã∞Ì ∞¯∞›¿⁄∞° æ»¿¸ ∞¯∞› ∏µÂ∂Û∏È ∞¯∞›¿« ¿«πÃ∞° æ¯¥Ÿ. 
		if ((cAttackerType == DEF_OWNERTYPE_PLAYER) && (m_pClientList[sAttackerH] != NULL)) { 
			// v2.13
			if ((m_pClientList[sTargetH]->m_iPartyID != NULL) && (m_pClientList[sAttackerH]->m_iPartyID == m_pClientList[sTargetH]->m_iPartyID)) return;
		
			if (m_pClientList[sAttackerH]->m_bIsSafeAttackMode == TRUE) {
				iSideCondition = iGetPlayerRelationship(sAttackerH, sTargetH);
				if ((iSideCondition == 7) || (iSideCondition == 2) || (iSideCondition == 6)) {
					// ¿˚
				}
				else {
					// ∞∞¿∫ ∆Ì¿Ã¡ˆ∏∏ ∏∏æ‡ ªÁ≈ı¿Â ≥ªø°º≠ ∆Ì¿Ã ¥Ÿ∏£¥Ÿ∏È ∞¯∞› √≥∏Æ∏¶ «ÿæﬂ«—¥Ÿ.
					if (m_pMapList[m_pClientList[sAttackerH]->m_cMapIndex]->m_bIsFightZone == TRUE) {
						if (m_pClientList[sAttackerH]->m_iGuildGUID != m_pClientList[sTargetH]->m_iGuildGUID) {
							// ªÁ≈ı¿Â ≥ªø°º≠ ¥Ÿ∏• ±ÊµÂ¥Ÿ. ∞¯∞›¿Ã ∞°¥…«œ¥Ÿ. 
						}
						else return;
					}
					else return;
				}
			}
		}

		iMaxSP = (2*(m_pClientList[sTargetH]->m_iStr+m_pClientList[sTargetH]->m_iAngelicStr)) + (2*m_pClientList[sTargetH]->m_iLevel);
		if (m_pClientList[sTargetH]->m_iSP > 0) {
			
			//v1.42 
			if (m_pClientList[sTargetH]->m_iTimeLeft_FirmStaminar == 0) {
				m_pClientList[sTargetH]->m_iSP -= iSP;
				if (m_pClientList[sTargetH]->m_iSP < 0) m_pClientList[sTargetH]->m_iSP = 0;
				SendNotifyMsg(NULL, sTargetH, DEF_NOTIFY_SP, NULL, NULL, NULL, NULL);
			}
		}
		break;

	case DEF_OWNERTYPE_NPC:
		// NPC¥¬ Ω∫≈¬πÃ≥  ∞≥≥‰¿Ã æ¯¥Ÿ.
		break;
	}
}


void CGame::OnKeyDown(WPARAM wParam, LPARAM lParam)
{
	switch (wParam) {
	case VK_F1:
		m_bF1pressed = TRUE;
		break;
	case VK_F4:
		m_bF4pressed = TRUE;
		break;
	case VK_F12:
		m_bF12pressed = TRUE;
		break;
	}
}

void CGame::OnKeyUp(WPARAM wParam, LPARAM lParam)
{
 int i;
	switch (wParam) {
	
	case VK_F1:
		m_bF1pressed = FALSE;
		break;
	case VK_F4:
		m_bF4pressed = FALSE;
		break;
	case VK_F12:
		m_bF12pressed = FALSE;
		break;

	case VK_F6:
		if (m_bF1pressed == TRUE) {
			PutLogList("(!) Send server shutdown announcement1...");
			for (i = 1; i < DEF_MAXCLIENTS; i++)
			if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE)) {
				SendNotifyMsg(NULL, i, DEF_NOTIFY_SERVERSHUTDOWN, 1, NULL, NULL, NULL);
			}
		}
		break;

	case VK_F7:
		if (m_bF1pressed == TRUE) {
			PutLogList("(!) Send server shutdown announcement2...");
			for (i = 1; i < DEF_MAXCLIENTS; i++)
			if ((m_pClientList[i] != NULL) && (m_pClientList[i]->m_bIsInitComplete == TRUE)) {
				SendNotifyMsg(NULL, i, DEF_NOTIFY_SERVERSHUTDOWN, 2, NULL, NULL, NULL);
			}
		}
		break;
		

	case VK_F9:
		if ((m_bF1pressed == TRUE)) {
			PutLogList("(!!!) Resume Crusade Mode...");
			LocalStartCrusadeMode(NULL);
		}
		break;

	case VK_F11:
		if ((m_bF1pressed == TRUE)) {
			PutLogList("(!!!) ManualEndCrusadeMode: side 0");
			ManualEndCrusadeMode(0);
		}
		break;

	//Crusade Testcode
	case VK_HOME:
		if ((m_bF1pressed == TRUE)) {
			GlobalStartCrusadeMode();
		}
		break;

	case VK_END:
		//LocalEndCrusadeMode();
		break;

	case VK_INSERT:
		_GrandMagicLaunchMsgSend(1, 1);
		MeteorStrikeMsgHandler(1);
		break;

	case VK_DELETE:
		_GrandMagicLaunchMsgSend(1, 2);
		MeteorStrikeMsgHandler(2);
		break;
	}
}

int CGame::iGetFollowerNumber(short sOwnerH, char cOwnerType)
{
 register int i, iTotal;

	iTotal = 0;

	for (i = 1; i < DEF_MAXNPCS; i++) 
	if ( (m_pNpcList[i] != NULL) && (m_pNpcList[i]->m_cMoveType == DEF_MOVETYPE_FOLLOW) ) {

		if ((m_pNpcList[i]->m_iFollowOwnerIndex == sOwnerH) && (m_pNpcList[i]->m_cFollowOwnerType == cOwnerType))
			iTotal++;
	}

	return iTotal;
}

BOOL CGame::bRegisterDelayEvent(int iDelayType, int iEffectType, DWORD dwLastTime, int iTargetH, char cTargetType, char cMapIndex, int dX, int dY, int iV1, int iV2, int iV3)
{
 register int i;

	for (i = 0; i < DEF_MAXDELAYEVENTS; i++) 
	if (m_pDelayEventList[i] == NULL) {
		
		m_pDelayEventList[i] = new class CDelayEvent;

		m_pDelayEventList[i]->m_iDelayType = iDelayType;
		m_pDelayEventList[i]->m_iEffectType = iEffectType;

		m_pDelayEventList[i]->m_cMapIndex = cMapIndex;
		m_pDelayEventList[i]->m_dX = dX;
		m_pDelayEventList[i]->m_dY = dY;

		m_pDelayEventList[i]->m_iTargetH    = iTargetH;
		m_pDelayEventList[i]->m_cTargetType = cTargetType;
		m_pDelayEventList[i]->m_iV1         = iV1;
		m_pDelayEventList[i]->m_iV2         = iV2;
		m_pDelayEventList[i]->m_iV3         = iV3; 

		m_pDelayEventList[i]->m_dwTriggerTime = dwLastTime;

		return TRUE;
	}

	return FALSE;
}

void CGame::DelayEventProcessor()
{
 register int i, iSkillNum, iResult, iTemp;
 DWORD dwTime = timeGetTime();



	for (i = 0; i < DEF_MAXDELAYEVENTS; i++) 
	if ((m_pDelayEventList[i] != NULL) && (m_pDelayEventList[i]->m_dwTriggerTime < dwTime)) {

		// ¿Ã∫•∆Æ∞° µø¿€«“ Ω√∞£¿Ã µ∆¥Ÿ. µø¿€»ƒ ªË¡¶µ»¥Ÿ.
		switch (m_pDelayEventList[i]->m_iDelayType) {
		case DEF_DELAYEVENTTYPE_ANCIENT_TABLET:
			if ((m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_iStatus & 0x400000) != 0) {
				iTemp = 1;
			}
			else if ((m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_iStatus & 0x800000) != 0) {
				iTemp = 3;
			}
			else if ((m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_iStatus & 0x10000) != 0) {
				iTemp = 4;
			}

			SendNotifyMsg(NULL, m_pDelayEventList[i]->m_iTargetH, DEF_NOTIFY_SLATE_STATUS, iTemp, NULL, NULL, NULL);
			SetSlateFlag(m_pDelayEventList[i]->m_iTargetH, iTemp, FALSE);
			break;
			
		case DEF_DELAYEVENTTYPE_CALCMETEORSTRIKEEFFECT:
			CalcMeteorStrikeEffectHandler(m_pDelayEventList[i]->m_cMapIndex);
			break;

		case DEF_DELAYEVENTTYPE_DOMETEORSTRIKEDAMAGE:
			DoMeteorStrikeDamageHandler(m_pDelayEventList[i]->m_cMapIndex);
			break;
		
		case DEF_DELAYEVENTTYPE_METEORSTRIKE:
			MeteorStrikeHandler(m_pDelayEventList[i]->m_cMapIndex);
			break;
		
		case DEF_DELAYEVENTTYPE_USEITEM_SKILL:
			// æ∆¿Ã≈€ ªÁøÎø° µ˚∏• ∞·∞˙ ∞ËªÍ, ≈Î∫∏ 
			switch (m_pDelayEventList[i]->m_cTargetType) {
			case DEF_OWNERTYPE_PLAYER:
				iSkillNum = m_pDelayEventList[i]->m_iEffectType;
				
				if ( m_pClientList[m_pDelayEventList[i]->m_iTargetH] == NULL ) break;
				// ±‚º˙ ªÁøÎ¿Ã π´»ø»≠ µ«æ˙¥Ÿ∏È π´Ω√. 
				if ( m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_bSkillUsingStatus[iSkillNum] == FALSE ) break;
				// ±‚º˙ ªÁøÎ Ω√∞£ ID∞° ¥ﬁ∂Ûµµ π´Ω√ v1.12
				if ( m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_iSkillUsingTimeID[iSkillNum] != m_pDelayEventList[i]->m_iV2) break;
				
				// ±‚º˙ ªÁøÎ ªÛ≈¬ «ÿ¡¶ 
				m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_bSkillUsingStatus[iSkillNum] = FALSE;
				m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_iSkillUsingTimeID[iSkillNum] = NULL;
				
				// ¿Ã¡¶ Skill¿« »ø∞˙ø° µ˚∏• ∞ËªÍ¿ª «—¥Ÿ. 
				iResult = iCalculateUseSkillItemEffect(m_pDelayEventList[i]->m_iTargetH, m_pDelayEventList[i]->m_cTargetType,
				 	                                   m_pDelayEventList[i]->m_iV1, iSkillNum, m_pDelayEventList[i]->m_cMapIndex, m_pDelayEventList[i]->m_dX, m_pDelayEventList[i]->m_dY);

				// ±‚º˙ ªÁøÎ¿Ã ¡ﬂ¡ˆ µ«æ˙¿Ω¿ª æÀ∏∞¥Ÿ.
				SendNotifyMsg(NULL, m_pDelayEventList[i]->m_iTargetH, DEF_NOTIFY_SKILLUSINGEND, iResult, NULL, NULL, NULL);
				break;
			}
			break;
		
		case DEF_DELAYEVENTTYPE_DAMAGEOBJECT:
			break;

		case DEF_DELAYEVENTTYPE_MAGICRELEASE:
			// «“¥Áµ«æ˙¥¯ ∏∂π˝»ø∞˙ ∫Øºˆ∏¶ ≈¨∏ÆæÓ«—¥Ÿ.
			switch (m_pDelayEventList[i]->m_cTargetType) {
			case DEF_OWNERTYPE_PLAYER:
				if (m_pClientList[ m_pDelayEventList[i]->m_iTargetH ] == NULL) break;
				
				SendNotifyMsg(NULL, m_pDelayEventList[i]->m_iTargetH, DEF_NOTIFY_MAGICEFFECTOFF, 
					          m_pDelayEventList[i]->m_iEffectType, m_pClientList[ m_pDelayEventList[i]->m_iTargetH ]->m_cMagicEffectStatus[ m_pDelayEventList[i]->m_iEffectType ], NULL, NULL);
				
				m_pClientList[ m_pDelayEventList[i]->m_iTargetH ]->m_cMagicEffectStatus[ m_pDelayEventList[i]->m_iEffectType ] = NULL;
				
				// Inbitition casting 
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_INHIBITION)
					m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_bInhibition = FALSE;
				
				// Invisibility »ø∞˙ «ÿ¡¶ 
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_INVISIBILITY)
					SetInvisibilityFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, FALSE);

				// Berserk »ø∞˙ «ÿ¡¶
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_BERSERK)
					SetBerserkFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, FALSE);

				// polymorph »ø∞˙ «ÿ¡¶ 
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_POLYMORPH) {
					m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_sType = m_pClientList[m_pDelayEventList[i]->m_iTargetH]->m_sOriginalType;
					SendEventToNearClient_TypeA(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
				}
				
				// Confusion
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_CONFUSE)
					switch(m_pDelayEventList[i]->m_iV1){
						case 3: SetIllusionFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, FALSE); break;
						case 4: SetIllusionMovementFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, FALSE); break;
					}	

				// Ice »ø∞˙ «ÿ¡¶ 
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_ICE)
					SetIceFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, FALSE);
					
				// v2.23 Protection Magic
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_PROTECT) {
					switch(m_pDelayEventList[i]->m_iV1){
						case 1:
							SetProtectionFromArrowFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, FALSE);
							break;
						case 2:
						case 5:
							SetMagicProtectionFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, FALSE);
							break;
						case 3:
						case 4:
							SetDefenseShieldFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_PLAYER, FALSE);
							break;
					}
				}
					
				break;
			
			case DEF_OWNERTYPE_NPC:
				if (m_pNpcList[ m_pDelayEventList[i]->m_iTargetH ] == NULL) break;
				
				m_pNpcList[ m_pDelayEventList[i]->m_iTargetH ]->m_cMagicEffectStatus[ m_pDelayEventList[i]->m_iEffectType ] = NULL;
				
				// Invisibility »ø∞˙ «ÿ¡¶ 
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_INVISIBILITY)
					SetInvisibilityFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_NPC, FALSE);

				// Berserk »ø∞˙ «ÿ¡¶
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_BERSERK)
					SetBerserkFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_NPC, FALSE);

				// polymorph »ø∞˙ «ÿ¡¶ 
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_POLYMORPH) {
					m_pNpcList[m_pDelayEventList[i]->m_iTargetH]->m_sType = m_pNpcList[m_pDelayEventList[i]->m_iTargetH]->m_sOriginalType;
					SendEventToNearClient_TypeA(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
				}

				// Ice »ø∞˙ «ÿ¡¶ 
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_ICE)
					SetIceFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_NPC, FALSE);
					
				// Illusion
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_CONFUSE)
					SetIllusionFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_NPC, FALSE);
					
				// Protection Magic
				if (m_pDelayEventList[i]->m_iEffectType == DEF_MAGICTYPE_PROTECT) {
					switch(m_pDelayEventList[i]->m_iV1){
						case 1:
							SetProtectionFromArrowFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_NPC, FALSE);
							break;
						case 2:
						case 5:
							SetMagicProtectionFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_NPC, FALSE);
							break;
						case 3:
						case 4:
							SetDefenseShieldFlag(m_pDelayEventList[i]->m_iTargetH, DEF_OWNERTYPE_NPC, FALSE);
							break;
						}
					}
				break;
			}
			break;
		}
		
		delete m_pDelayEventList[i];
		m_pDelayEventList[i] = NULL;
	}
}

BOOL CGame::bRemoveFromDelayEventList(int iH, char cType, int iEffectType)
{
 register int i;

	for (i = 0; i < DEF_MAXDELAYEVENTS; i++) 
	if (m_pDelayEventList[i] != NULL) {
		
		if (iEffectType == NULL) {
			// Effect ¡æ∑˘ø° ªÛ∞¸æ¯¿Ã ∏µŒ ªË¡¶ 	
			if ( (m_pDelayEventList[i]->m_iTargetH == iH) && (m_pDelayEventList[i]->m_cTargetType == cType) ) {
				delete m_pDelayEventList[i];
				m_pDelayEventList[i] = NULL;
			}
		}
		else {
			// «ÿ¥Á Effect∏∏ ªË¡¶.
			if ( (m_pDelayEventList[i]->m_iTargetH == iH) && (m_pDelayEventList[i]->m_cTargetType == cType) &&
				 (m_pDelayEventList[i]->m_iEffectType == iEffectType) ) {
				delete m_pDelayEventList[i];
				m_pDelayEventList[i] = NULL;
			}
		}
	}
	
	return TRUE;
}

void CGame::SetInvisibilityFlag(short sOwnerH, char cOwnerType, BOOL bStatus)
{
	switch (cOwnerType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus | 0x00000010;
		else m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus & 0xFFFFFFEF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;

	case DEF_OWNERTYPE_NPC:
		if (m_pNpcList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus | 0x00000010;
		else m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus & 0xFFFFFFEF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;
	}
}

void CGame::SetBerserkFlag(short sOwnerH, char cOwnerType, BOOL bStatus)
{
	switch (cOwnerType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus | 0x00000020;
		else m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus & 0xFFFFFFDF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;

	case DEF_OWNERTYPE_NPC:
		if (m_pNpcList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus | 0x00000020;
		else m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus & 0xFFFFFFDF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;
	}
}


void CGame::SetIceFlag(short sOwnerH, char cOwnerType, BOOL bStatus)
{
	switch (cOwnerType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus | 0x00000040;
		else m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus & 0xFFFFFFBF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;

	case DEF_OWNERTYPE_NPC:
		if (m_pNpcList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus | 0x00000040;
		else m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus & 0xFFFFFFBF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;
	}
}

void CGame::SetMagicProtectionFlag(short sOwnerH, char cOwnerType, BOOL bStatus)
{
	switch (cOwnerType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus | 0x04000000;
		else m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus & 0xFBFFFFFF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;

	case DEF_OWNERTYPE_NPC:
		if (m_pNpcList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus | 0x04000000;
		else m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus & 0xFBFFFFFF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;
	}
}

void CGame::SetProtectionFromArrowFlag(short sOwnerH, char cOwnerType, BOOL bStatus)
{
	switch (cOwnerType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus | 0x08000000;
		else m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus & 0xF7FFFFFF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;

	case DEF_OWNERTYPE_NPC:
		if (m_pNpcList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus | 0x08000000;
		else m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus & 0xF7FFFFFF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;
	}
}

void CGame::SetDefenseShieldFlag(short sOwnerH, char cOwnerType, BOOL bStatus)
{
	switch (cOwnerType) {
	case DEF_OWNERTYPE_PLAYER:
		if (m_pClientList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus | 0x02000000;
		else m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus & 0xFDFFFFFF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;

	case DEF_OWNERTYPE_NPC:
		if (m_pNpcList[sOwnerH] == NULL) return;
		if (bStatus == TRUE) 
			 m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus | 0x02000000;
		else m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus & 0xFDFFFFFF;
		// ø‹«¸¿Ã πŸ≤Ô∞Õ¿ª ≈Î∫∏ 
		SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		break;
	}
}

void CGame::SetPoisonFlag(short sOwnerH, char cOwnerType, BOOL bStatus) 
{ 
  	switch (cOwnerType) {
		case DEF_OWNERTYPE_PLAYER:
			if (m_pClientList[sOwnerH] == NULL) return;
			if (bStatus == TRUE) 
				 m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus | 0x00000080;
			else m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus & 0xFFFFFF7F;
			SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
			break;

		case DEF_OWNERTYPE_NPC:
			if (m_pNpcList[sOwnerH] == NULL) return;
			if (bStatus == TRUE) 
				 m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus | 0x00000080;
			else m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus & 0xFFFFFF7F;
			SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
			break;
	}    
}

void CGame::SetHeroFlag(short sOwnerH, char cOwnerType, BOOL bStatus) 
{ 
  	switch (cOwnerType) {
		case DEF_OWNERTYPE_PLAYER:
			if (m_pClientList[sOwnerH] == NULL) return;
			if (bStatus == TRUE) 
				 m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus | 0x00020000;
			else m_pClientList[sOwnerH]->m_iStatus = m_pClientList[sOwnerH]->m_iStatus & 0xFFFDFFFF;
			SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
			break;

		case DEF_OWNERTYPE_NPC:
			if (m_pNpcList[sOwnerH] == NULL) return;
			if (bStatus == TRUE) 
				 m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus | 0x00020000;
			else m_pNpcList[sOwnerH]->m_iStatus = m_pNpcList[sOwnerH]->m_iStatus & 0xFFFDFFFF;
			SendEventToNearClient_TypeA(sOwnerH, DEF_OWNERTYPE_NPC, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
			break;
	}    
}
void CGame::ResurrectPlayer(int iClientH)
{
	//testcode
	PutLogList("(*) Resurrect Player!");

	// ƒ≥∏Ø≈Õ∏¶ ∫Œ»∞Ω√≈≤¥Ÿ.
	// «ˆ¿Á ¿Ã «√∑π¿ÃæÓ∏¶ ∏Ò«•∑Œ ªÔ∞Ì ¿÷¥¬ ∏˜µÈ¿« ∞¯∞›«‡µø¿ª ∏ÿ√ﬂ∞‘ «—¥Ÿ. 
	RemoveFromTarget(iClientH, DEF_OWNERTYPE_PLAYER);
	// «ˆ¿Á ∏  ¿ßƒ°ø°º≠ ¡ˆøÓ¥Ÿ.
	m_pMapList[m_pClientList[iClientH]->m_cMapIndex]->ClearOwner(13, iClientH, DEF_OWNERTYPE_PLAYER, m_pClientList[iClientH]->m_sX,  m_pClientList[iClientH]->m_sY);
	// ¥Ÿ∏• ≈¨∂Û¿Ãæ∆ÆµÈø°∞‘ «√∑π¿ÃæÓ∞° «ˆ ¿ßƒ°ø°º≠ ªÁ∂Û¡¸¿ª æÀ∏∞¥Ÿ. 
	SendEventToNearClient_TypeA(iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_LOG, DEF_MSGTYPE_REJECT, NULL, NULL, NULL);

	// «√∑π¿ÃæÓ¿« ¿ßƒ°∏¶ »Æ¡§«—¥Ÿ. ∏ ¿« µ∆˙∆Æ ¿ßƒ°∑Œ ¿Ãµø 
	GetMapInitialPoint(m_pClientList[iClientH]->m_cMapIndex, &m_pClientList[iClientH]->m_sX, &m_pClientList[iClientH]->m_sY);

	m_pClientList[iClientH]->m_iHP = iGetMaxHP(iClientH);
	m_pClientList[iClientH]->m_iMP = (2*(m_pClientList[iClientH]->m_iMag+m_pClientList[iClientH]->m_iAngelicMag)) + (2*m_pClientList[iClientH]->m_iLevel) + ((m_pClientList[iClientH]->m_iInt+m_pClientList[iClientH]->m_iAngelicInt)/2);
	m_pClientList[iClientH]->m_iSP = (2*m_pClientList[iClientH]->m_iStr) + (2*m_pClientList[iClientH]->m_iLevel);
	m_pClientList[iClientH]->m_bIsKilled = FALSE;

	RequestInitDataHandler(iClientH, NULL, NULL, TRUE);
	return;
}

void CGame::openDeathmach() // MORLA 2.10 - Cerrar Deathmatch
{
	int i;
	
	for (i = 1; i < DEF_MAXCLIENTS; i++) // Check all clients
	{
		if ((m_pClientList[i] != NULL)) {
			SendNotifyMsg(NULL, i, DEF_NOTIFY_DEATHMACHSTAR, NULL, NULL, NULL, NULL); 					
		} 
	}	

	for (i = 0; i < 16; i++)
	{
		iDGtop[i] = -1;
		aDGTopKills[i] = -1;
		aDGTopDeaths[i] = -1;
		ZeroMemory(aDGTopClientH[i], sizeof(aDGTopClientH[i]));
	}
	iLastKill = -1;
	dwTimeLastKill = timeGetTime();
	iTotalKills = 0;
	DeathMatch = TRUE;
}

void CGame::closeDeathmach() // MORLA 2.10 - Cerrar Deathmatch
{
	int i;
	
	for (i = 1; i < DEF_MAXCLIENTS; i++) // Check all clients
	{
		if ((m_pClientList[i] != NULL)) {
			SendNotifyMsg(NULL, i, DEF_NOTIFY_DEATHMACHEND, NULL, NULL, NULL, NULL);
			if (memcmp(m_pClientList[i]->m_cMapName, "deathmach", 9) == 0)
				RequestTeleportHandler(i, "1   ");
		}
	}	
	DeathMatch = FALSE;
}

void CGame::topdeathmach(int iAttackerH, int iClientH)
{
	int i;
	if  (memcmp(m_pClientList[iClientH]->m_cMapName, "deathmach", 9) == 0) // MORLA2.2 - Revive en Deathmach Map
	{
		m_pClientList[iClientH]->m_bIsBeingResurrected = TRUE;
		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_RESURRECTPLAYER, NULL, NULL, NULL, NULL);
		if (m_pClientList[iClientH]->m_iAdminUserLevel < 2) 
		{
			m_pClientList[iClientH]->m_bIsSpecialAbilityEnabled = TRUE;
			m_pClientList[iClientH]->m_iSpecialAbilityLastSec = 0;
		}
									
		SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_SPECIALABILITYSTATUS, 1, m_pClientList[iClientH]->m_iSpecialAbilityType, m_pClientList[iClientH]->m_iSpecialAbilityLastSec, NULL);
		SendEventToNearClient_TypeA(iClientH, DEF_OWNERTYPE_PLAYER, MSGID_EVENT_MOTION, DEF_OBJECTNULLACTION, NULL, NULL, NULL);
		char cScanMessage[256];
		//MORLA 2.2 - Deathmach Game completo:
									

		m_pClientList[iAttackerH]->m_iDGKills++;
		m_pClientList[iClientH]->m_iDGDeaths++;
		m_pClientList[iAttackerH]->m_iTotalDGKills++;
		m_pClientList[iClientH]->m_iTotalDGDeaths++;
		
		m_pClientList[iAttackerH]->m_iMP = (2*(m_pClientList[iClientH]->m_iMag+m_pClientList[iClientH]->m_iAngelicMag)) + (2*m_pClientList[iClientH]->m_iLevel) + ((m_pClientList[iClientH]->m_iInt+m_pClientList[iClientH]->m_iAngelicInt)/2);
		SendNotifyMsg(NULL, iAttackerH, DEF_NOTIFY_MP, NULL, NULL, NULL, NULL); 
		m_pClientList[iAttackerH]->m_iSuperAttackLeft = (m_pClientList[iAttackerH]->m_iLevel / 10)*2;
		SendNotifyMsg(NULL, iAttackerH, DEF_NOTIFY_SUPERATTACKLEFT, NULL, NULL, NULL, NULL);

		calcularTop15Deathmach(iAttackerH);
		calcularTop15Deathmach(iClientH);
									
		DWORD  dwTimeThisKill = timeGetTime();
		if (iLastKill == iAttackerH) 
		{
			if (dwTimeLastKill > dwTimeThisKill)
			{
				iTotalKills++;
				for (i = 1; i < DEF_MAXCLIENTS; i++) // Check all clients
				{
					if ((m_pClientList[i] != NULL)) {
						if ((iTotalKills == 1) && (memcmp(m_pClientList[i]->m_cMapName, "deathmach", 9) == 0))
							SendNotifyMsg(NULL, i, DEF_NOTIFY_DOUBLEKILL, NULL, NULL, NULL, NULL);
						else if ((iTotalKills == 2) && (memcmp(m_pClientList[i]->m_cMapName, "deathmach", 9) == 0))
							SendNotifyMsg(NULL, i, DEF_NOTIFY_KILLSPRING, NULL, NULL, NULL, NULL);
						else if ((iTotalKills == 3) && (memcmp(m_pClientList[i]->m_cMapName, "deathmach", 9) == 0))
							SendNotifyMsg(NULL, i, DEF_NOTIFY_MONSTERKILL, NULL, NULL, NULL, NULL);
						else if ((iTotalKills >= 4) && (memcmp(m_pClientList[i]->m_cMapName, "deathmach", 9) == 0))
							SendNotifyMsg(NULL, i, DEF_NOTIFY_HOLYSHIT, NULL, NULL, NULL, NULL); 
					}
				}
			}
			else
			{
				iTotalKills = 0;
				iLastKill = iAttackerH;
				dwTimeLastKill = (timeGetTime()+ 30*1000);
			}
		}
		else {
			iTotalKills = 0;
			iLastKill = iAttackerH;
			dwTimeLastKill = (timeGetTime()+ 30*1000);
		}
		for (i=1; i<5000; i+=1) 
		{
			if (m_pClientList[iAttackerH]->m_iDGKills == i)
			{
				m_pClientList[iAttackerH]->m_iEnemyKillCount++;
				ZeroMemory(cScanMessage, sizeof(cScanMessage));
				wsprintf(cScanMessage, "°Get a EK Count! Total: %d", m_pClientList[iAttackerH]->m_iEnemyKillCount);
				ShowClientMsg(iAttackerH, cScanMessage);
				SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ENEMYKILLS, m_pClientList[iClientH]->m_iEnemyKillCount, NULL, NULL, NULL);
			}
		}
	}
	RefreshDeathmach(0);
}

void CGame::RefreshDeathmach(int iClientH) // MORLA 2.3 - Actualiza los pjs del Deathmach
{
	int i, p;
	if (m_pClientList[iClientH] != NULL) 
	{
		for (i = 1; i < 15; i++) // Check all clients
		{
			if (iClientH != 0)
			{
				if (iClientH == iDGtop[i]) 
				{ 
					iDGtop[i] = iDGtop[i+1]; 
					m_pClientList[iClientH]->m_iDGKills = 0; 
					m_pClientList[iClientH]->m_iDGDeaths = 0; 
				}
			}
		}
	}

	for (i = 0; i < DEF_MAXCLIENTS; i++) // Check all clients
	{
		if (m_pClientList[i] != NULL) 
		{
			for (p = 1; p < 15; p++) // Check all clients
			{
				if ((iDGtop[p] != NULL) && (iDGtop[p] != -1))
					SendNotifyMsg(NULL, i, DEF_NOTIFY_DGKILL, p, aDGTopKills[p], aDGTopDeaths[p], aDGTopClientH[p]);
			}
		}
	}
}

void CGame::calcularTop15Deathmach(int iClientH) // MORLA 2.4 - Calcular si tiene mas Deaths
{
	int p;
	bool bExiste = false;
	if (m_pClientList[iClientH] == NULL) return;
	
	if (m_pClientList[iClientH]->m_iTotalDGKills > 0)
	{
		for (p=1; p<=15; p++)
		{
			if (strcmp(aDGTopClientH[p], m_pClientList[iClientH]->m_cCharName) == 0)
			{
				iDGtop[p] = iClientH;
				aDGTopKills[p] = m_pClientList[iClientH]->m_iTotalDGKills;
				aDGTopDeaths[p] = m_pClientList[iClientH]->m_iTotalDGDeaths;
				ZeroMemory(aDGTopClientH[p], sizeof(aDGTopClientH[p]));
				memcpy(aDGTopClientH[p], m_pClientList[iClientH]->m_cCharName, 10);
				bExiste = true;
				ordenarTop15Deathmach();
			}		
			
			if ((iDGtop[p] == -1) && (bExiste == false))
			{
				iDGtop[p] = iClientH;
				aDGTopKills[p] = m_pClientList[iClientH]->m_iTotalDGKills;
				aDGTopDeaths[p] = m_pClientList[iClientH]->m_iTotalDGDeaths;
				ZeroMemory(aDGTopClientH[p], sizeof(aDGTopClientH[p]));
				memcpy(aDGTopClientH[p], m_pClientList[iClientH]->m_cCharName, 10);
				bExiste = true;
				ordenarTop15Deathmach();
			}		
		}
		if (bExiste == false)
		{
			if(aDGTopKills[15] < m_pClientList[iClientH]->m_iTotalDGKills)
			{
				iDGtop[15] = iClientH;
				aDGTopKills[15] = m_pClientList[iClientH]->m_iTotalDGKills;
				aDGTopDeaths[15] = m_pClientList[iClientH]->m_iTotalDGDeaths;
				ZeroMemory(aDGTopClientH[15], sizeof(aDGTopClientH[15]));
				memcpy(aDGTopClientH[15], m_pClientList[iClientH]->m_cCharName, 10);
				ordenarTop15Deathmach();
			}
		}
	}
}	

void CGame::ordenarTop15Deathmach() // MORLA 2.4 - Calcular si tiene mas Deaths
{
	int aux1, aux2, aux4, p, q;
	char aux3[11];

	for (p=1; p<=14; p++)
	{
		for (q=p+1; q<=15; q++)
		{
			if (aDGTopKills[p] < aDGTopKills[q])
			{
				aux4 = iDGtop[p];
				aux1 = aDGTopKills[p];
				aux2 = aDGTopDeaths[p];
				ZeroMemory(aux3, sizeof(aux3));
				memcpy(aux3, aDGTopClientH[p], 10);
				
				iDGtop[p] = iDGtop[q];
				aDGTopKills[p] = aDGTopKills[q];
				aDGTopDeaths[p] = aDGTopDeaths[q];
				ZeroMemory(aDGTopClientH[p], sizeof(aDGTopClientH[p]));
				memcpy(aDGTopClientH[p], aDGTopClientH[q], 10);

				iDGtop[q] = aux4;
				aDGTopKills[q] = aux1;
				aDGTopDeaths[q] = aux2;
				ZeroMemory(aDGTopClientH[q], sizeof(aDGTopClientH[q]));
				memcpy(aDGTopClientH[q], aux3, 10);
			}
		}
	}
}

void CGame::AdminOrder_CheckPl(int iClientH, char* pData, DWORD dwMsgSize)
	{
	class CStrTok * pStrTok;
	short m_iRating;
	char * token, cName[11], cTargetName[11], cPlayerInfoMessage[256], seps[] = "= \t\n", cBuff[256];
	register int i;
	if (m_pClientList[iClientH]->m_iAdminUserLevel < 3) {
	SendNotifyMsg(NULL, iClientH, DEF_NOTIFY_ADMINUSERLEVELLOW, NULL, NULL, NULL, NULL);
	return;
	}
	if ((dwMsgSize) <= 0) return;
	ZeroMemory(cTargetName, sizeof(cTargetName));
	ZeroMemory(cBuff, sizeof(cBuff));
	memcpy(cBuff, pData, dwMsgSize);
	pStrTok = new class CStrTok(cBuff, seps);
	token = pStrTok->pGet();
	token = pStrTok->pGet();
	if (token != NULL) {
	ZeroMemory(cName, sizeof(cName));
	strcpy(cName, token);
	}
	else {
	ZeroMemory(cName, sizeof(cName));
	strcpy(cName, "null");
	}
	token = pStrTok->pGet();
	if (token != NULL) {
	m_iRating = atoi(token);
	}
	if (token == NULL) {
	token = "null";
	}
	if (cName != NULL) {
	token = cName;
	if (strlen(token) > 10)
	memcpy(cTargetName, token, 10);
	else memcpy(cTargetName, token, strlen(token));

	for (i = 1; i < DEF_MAXCLIENTS; i++)
	if ((m_pClientList[i] != NULL) && (memcmp(m_pClientList[i]->m_cCharName, cTargetName, 10) == 0)) {
	wsprintf(cPlayerInfoMessage, "Player %s Acc: %s Pass: %s EKs: %i IP: %s  Level: %i Str: %i Dex: %i Vit: %i Int: %i Mag: %i Chr: %i Exp: %i ",  m_pClientList[i]->m_cCharName, m_pClientList[i]->m_cAccountName,  m_pClientList[i]->m_cAccountPassword,m_pClientList[i]->m_iEnemyKillCount,m_pClientList[i]->m_cIPaddress,m_pClientList[i]->m_iLevel,   m_pClientList[i]->m_iStr,m_pClientList[i]->m_iDex,m_pClientList[i]->m_iVit,m_pClientList[i]->m_iInt,m_pClientList[i]->m_iMag,m_pClientList[i]->m_iCharisma,  m_pClientList[i]->m_iExpStock );
	ShowClientMsg(iClientH, cPlayerInfoMessage);
		}
	}
}
void CGame::CheckDenialServiceAttack(int iClientH, DWORD dwClientTime){DWORD dwTime = timeGetTime();
if (m_pClientList[iClientH] == NULL) return;
// Find a Denial of service attack by packet sent time
if (m_pClientList[iClientH]->m_dwDSLAT == 0)
// Start with 1st msg
{ m_pClientList[iClientH]->m_dwDSLAT = dwClientTime;
m_pClientList[iClientH]->m_dwDSLATOld = dwClientTime;
m_pClientList[iClientH]->m_dwDSLATS = dwTime;
m_pClientList[iClientH]->m_iDSCount = 0;
}else
{ if (dwClientTime >= m_pClientList[iClientH]->m_dwDSLAT)
// current message was sent later than previous (normal case)
{ m_pClientList[iClientH]->m_dwDSLAT = dwClientTime;
}else
// current message was sent before previous
{ if (m_pClientList[iClientH]->m_dwDSLATOld == dwClientTime)
// If we receive more late msg with same time
{ m_pClientList[iClientH]->m_iDSCount++;
if (((dwTime - m_pClientList[iClientH]->m_dwDSLATS) > 10*1000)
&& (m_pClientList[iClientH]->m_iDSCount > 5))
// Receiving a "late" msg more than 10 sec after !
// This is an attack!
{ wsprintf(G_cTxt, "DS check: PC(%s) - Denial of service attack! (Disc.) \tIP(%s)"
, m_pClientList[iClientH]->m_cCharName
, m_pClientList[iClientH]->m_cIPaddress);
PutLogList(G_cTxt);
return;
}
}else
// else this message become late msg
{ m_pClientList[iClientH]->m_dwDSLATOld = dwClientTime;
m_pClientList[iClientH]->m_iDSCount = 1;
m_pClientList[iClientH]->m_dwDSLATS = dwTime;
} } }
}

