#include "Game.h"
#include "lan_eng.h"

void CGame::DlgBoxClick_NetPanelConfirmation(short msX, short msY)
{
	short sX, sY;
	sX = m_stDialogBoxInfo[53].sX;
	sY = m_stDialogBoxInfo[53].sY;
	
	if (m_stDialogBoxInfo[53].sV1 > 0)
	{
		switch (m_stDialogBoxInfo[53].sV1)
		{
			/* Command Items */
			//DkSet command
			/*case 1:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					ZeroMemory(m_cChatMsg, sizeof(m_cChatMsg) );
					strcpy(m_cChatMsg, "/dkset");
					bSendCommand(MSGID_COMMAND_CHATMSG, NULL, NULL, NULL, NULL, NULL, m_cChatMsg);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;*/
			//maname command
			case 2:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					ZeroMemory(m_cChatMsg, sizeof(m_cChatMsg) );
					strcpy(m_cChatMsg, "/maname");
					bSendCommand(MSGID_COMMAND_CHATMSG, NULL, NULL, NULL, NULL, NULL, m_cChatMsg);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//zerkme command
			case 3:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					ZeroMemory(m_cChatMsg, sizeof(m_cChatMsg) );
					strcpy(m_cChatMsg, "/zerkme");
					bSendCommand(MSGID_COMMAND_CHATMSG, NULL, NULL, NULL, NULL, NULL, m_cChatMsg);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//repme command
		/*	case 4:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					ZeroMemory(m_cChatMsg, sizeof(m_cChatMsg) );
					strcpy(m_cChatMsg, "/repme");
					bSendCommand(MSGID_COMMAND_CHATMSG, NULL, NULL, NULL, NULL, NULL, m_cChatMsg);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;*/
			//changecity command
			case 5:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					ZeroMemory(m_cChatMsg, sizeof(m_cChatMsg) );
					strcpy(m_cChatMsg, "/changecity");
					bSendCommand(MSGID_COMMAND_CHATMSG, NULL, NULL, NULL, NULL, NULL, m_cChatMsg);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;

			/* Trade Ek Items */
			//The_Devastator
			case 846:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//DemonSlayer
			case 847:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//LightingBlade
			case 848:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//MerienShield
			case 620:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//MerienPlateMailM
			case 621:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//MerienPlateMailW
			case 622:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//RingoftheAbaddon for RingofPowerWar
			case 4964:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//KnecklaceOfMedusa
			case 641:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//NecklaceOfBeholder
			case 646:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//ZemstoneofSacrifice
			case 650:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//StoneOfXelima
			case 656:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//StoneOfMerien
			case 657:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//RingofArcmage for RingofPowerMage
			case 4965:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//GiantBattleHammer
			case 762:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//StormBringer
			case 845:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//KlonessBlade
			case 849:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//KlonessAxe
			case 850:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//KlonessEsterk
			case 851:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//Inhibition Casting Manual
			case 857:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//NecklaceofMerien for NeckPower(MS.30)
			case 4966:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//NecklaceofKloness for NeckPowerMerien
			case 4967:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//NecklaceofXelima for NeckPowerXelima
			case 4968:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//BerserkWand(MS.20)
			case 861:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//KlonessWand(MS.20)
			case 863:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//ResurWand(MS.20)
			case 865:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//BlackAxe
			case 4908:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//BlackHammer
			case 4905:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//BlackDevastator
			case 4913:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//BlackTowerShield
			case 4962:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//AresElfBow
			case 4959:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//ElvinElfBow
			case 4960:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//AresdenStormBringer
			case 4957:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//ElvineStormBringer
			case 4958:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//MagicNecklace(DF+30)
			case 889:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//MagicNecklace(DM+5)
			case 893:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//MagicNecklace(MS18)
			case 897:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//MagicNecklace(RM30)
			case 901:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//ChaosSword
			case 890:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//ChaosWand
			case 2090:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//NetBox(Big)
			case 2600:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//NetBox(Medium)
			case 2601:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			//NetBox(Small)
			case 2602:
				if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
				{   // yes
					bSendCommand(MSGID_COMMAND_COMMON, DEF_COMMONTYPE_REQ_GETTRADEEKITEMS, NULL, m_stDialogBoxInfo[53].sV1, NULL, NULL, NULL);
					DisableDialogBox(53);
				}else if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
				{	// no
					DisableDialogBox(53);
				}
				break;
			default:
				break;
		}
	}
}

void CGame::ChargeTopEkList(char *pData)
{
	char *cp;
	int *ip, i = 0;

	cp = (char *)(pData + 6);
	for (i; i < 10; i++)
	{
		ZeroMemory(TopEkList[i].Name, sizeof(TopEkList[i].Name));
		memcpy(TopEkList[i].Name, cp, 11);
		cp += 11;

		TopEkList[i].side = *cp;
		cp++;

		ip = (int *) cp;
		TopEkList[i].EkCount = *ip;
		cp += 4;
	}
}

void CGame::OpenNoticement()
{
 DWORD  dwFileSize;
 HANDLE hFile;

	hFile = CreateFile("contents\\contents1000.txt", GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		dwFileSize = 0;
	else
	{
		dwFileSize = GetFileSize(hFile, NULL);
		CloseHandle(hFile);
	}
	bSendCommand(MSGID_REQUEST_NOTICEMENT, NULL, NULL, (int)dwFileSize, NULL, NULL, NULL);
}
void CGame::DlgBoxClick_NetPanel(short msX, short msY)
{
	short sX, sY, szX;
	DWORD dwTime = m_dwCurTime;
	int Commando = 0;
	
	sX = m_stDialogBoxInfo[52].sX;
	sY = m_stDialogBoxInfo[52].sY;
	szX = m_stDialogBoxInfo[52].sSizeX;

	DisableDialogBox(53);

	switch (m_stDialogBoxInfo[52].cMode) {
    case 0:	//Principal
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_stDialogBoxInfo[52].cMode = 2;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;
	case 1:	//Noticias
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_stDialogBoxInfo[52].cMode = 2;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;
	case 2:	//TradeEk
		//Trade list
		//ventana normal donde haces el click para qe se abra la otra ventana
		// Amors and Weapons
		if ((msX > sX + 171) && (msX < sX + 332) && (msY > sY + 115) && (msY < sY + 130))
		{
			m_stDialogBoxInfo[52].cMode = 7;
		  	PlaySound('E', 14, 5);
		}
		//Magics Manuals
		if ((msX > sX + 171) && (msX < sX + 332) && (msY > sY + 155) && (msY < sY + 170))
		{
			m_stDialogBoxInfo[52].cMode = 12;
		  	PlaySound('E', 14, 5);
		}
		//Rings And Necks
		if ((msX > sX + 171) && (msX < sX + 332) && (msY > sY + 195) && (msY < sY + 210))
		{
			m_stDialogBoxInfo[52].cMode = 9;
		  	PlaySound('E', 14, 5);
		}
		//Stones and armor dyes
		if ((msX > sX + 171) && (msX < sX + 332) && (msY > sY + 235) && (msY < sY + 250))
		{
			m_stDialogBoxInfo[52].cMode = 10;
		  	PlaySound('E', 14, 5);
		}
		
		//Botones - NetPanel
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;
	case 3:	//TopEk
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_stDialogBoxInfo[52].cMode = 2;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;
	case 4:	// Eventos
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_stDialogBoxInfo[52].cMode = 2;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;
	case 5:	//Comandos
	/*	//Command dkset
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 102) && (msY < sY + 111))
		{
			if (m_iLevel >= 200)
			{
				EnableDialogBox(53, 1, NULL, NULL);
				PlaySound('E', 14, 5);
			}
		}

/*		//Command repme
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 117) && (msY < sY + 126))
		{
			if (m_iGizonItemUpgradeLeft >= 25)
			{
				EnableDialogBox(53, 4, NULL, NULL);
				PlaySound('E', 14, 5);
			}
		}*/

		//Command maname
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 132) && (msY < sY + 141))
		{
			if (m_iGizonItemUpgradeLeft >= 300)
			{
				EnableDialogBox(53, 2, NULL, NULL);
				PlaySound('E', 14, 5);
			}
		}

		//Command zerkme
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 147) && (msY < sY + 156))
		{
			if (m_iGizonItemUpgradeLeft >= 300)
			{
				EnableDialogBox(53, 3, NULL, NULL);
				PlaySound('E', 14, 5);
			}
		}
		
		//Command changecity
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 162) && (msY < sY + 171))
		{
			if (m_iGizonItemUpgradeLeft >= 800)
			{
				EnableDialogBox(53, 5, NULL, NULL);
				PlaySound('E', 14, 5);
			}
		}

		//Command NetBox(Small)
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 192) && (msY < sY + 201))
		{    
			if (m_iGizonItemUpgradeLeft >= 100)
			{
				EnableDialogBox(53, 2602, NULL, NULL);
				PlaySound('E', 14, 5);
			}
		}

		//Command NetBox(Medium)
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 207) && (msY < sY + 216))
		{    
			if (m_iGizonItemUpgradeLeft >= 250)
			{
				EnableDialogBox(53, 2601, NULL, NULL);
				PlaySound('E', 14, 5);
			}
		}

		//Command NetBox(Big)
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 222) && (msY < sY + 231))
		{    
			if (m_iGizonItemUpgradeLeft >= 500)
			{
				EnableDialogBox(53, 2600, NULL, NULL);
				PlaySound('E', 14, 5);
			}
		}

		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_stDialogBoxInfo[52].cMode = 2;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;
	case 6:
		PlaySound('E', 14, 5);
		DisableDialogBox(52);
		DisableDialogBox(53);
		break;

	//Trade EK
	case 7: //Trade Ek List - Armors and Weapons page 1
		//KlonessWand(MS.20)
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))
		{
			if(m_iEnemyKillCount < 4500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 863, NULL, NULL);
		}
		//ResurWand(MS.20)
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
		{
			if(m_iEnemyKillCount < 2500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 865, NULL, NULL);
		}		
		//BerserkWand(MS.20)
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
		{
			if(m_iEnemyKillCount < 6000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 861, NULL, NULL);
		}
		//DemonSlayer
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 148) && (msY < sY + 157))
		{
			if(m_iEnemyKillCount < 4500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 847, NULL, NULL);
		}
		//XelimaRapier
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 163) && (msY < sY + 172))
		{
			if(m_iEnemyKillCount < 4500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 848, NULL, NULL);
		}
		//XelimaBlade
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 178) && (msY < sY + 187))
		{
			if(m_iEnemyKillCount < 4500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 846, NULL, NULL);
		}
		//KlonessAxe
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 193) && (msY < sY + 202))
		{
			if(m_iEnemyKillCount < 4200) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 850, NULL, NULL);
		}	
		//KlonessEsterk
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 208) && (msY < sY + 217))
		{
			if(m_iEnemyKillCount < 4000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 851, NULL, NULL);
		}
		//KlonessBlade
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 223) && (msY < sY + 232))
		{
			if(m_iEnemyKillCount < 4500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 849, NULL, NULL);
		}
		//StormBringer
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 238) && (msY < sY + 247))
		{
			if(m_iEnemyKillCount < 5000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 845, NULL, NULL);
		}
		//AresdenHeroBlade
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 253) && (msY < sY + 262))
		{
			if(m_iEnemyKillCount < 10000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 890, NULL, NULL);
		}
		//ElvineHeroBlade
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 268) && (msY < sY + 277))
		{
			if(m_iEnemyKillCount < 10000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 2090, NULL, NULL);
		}

		//"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
		{
			m_stDialogBoxInfo[52].cMode = 2;
		  	PlaySound('E', 14, 5);
		}
		// "Nex Page" Button
		if ((msX > sX + 268) && (msX < sX + 350) && (msY > sY + 300) && (msY < sY + 315))
		{
			m_stDialogBoxInfo[52].cMode = 8;
			PlaySound('E', 14, 5);
		}
		
		//Botones - NetPanel
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;

	case 8: //Trade Ek List - Armors and Weapons page 2	
		//GiantBattleHammer
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))
		{
			if(m_iEnemyKillCount < 8000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 762, NULL, NULL);
		}		
		//MerienShield
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
		{
			if(m_iEnemyKillCount < 7000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 620, NULL, NULL);
		}		
		//MerienPlateMailM
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
		{
			if(m_iEnemyKillCount < 6000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 621, NULL, NULL);
		}
		//MerienPlateMailW
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 148) && (msY < sY + 157))
		{
			if(m_iEnemyKillCount < 6000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 622, NULL, NULL);
		}
		//BlackAxe
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 163) && (msY < sY + 172))
		{
			if(m_iEnemyKillCount < 4500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4908, NULL, NULL);
		}
		//BlackHammer
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 178) && (msY < sY + 187))
		{
			if(m_iEnemyKillCount < 4500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4905, NULL, NULL);
		}
		//BlackDevastator
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 193) && (msY < sY + 202))
		{
			if(m_iEnemyKillCount < 4200) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4913, NULL, NULL);
		}	
		//BlackTowerShield
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 208) && (msY < sY + 217))
		{
			if(m_iEnemyKillCount < 4000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4962, NULL, NULL);
		}
		//AresElfBow
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 223) && (msY < sY + 232))
		{
			if(m_iEnemyKillCount < 4500) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4959, NULL, NULL);
		}
		//ElvinElfBow
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 238) && (msY < sY + 247))
		{
			if(m_iEnemyKillCount < 5000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4960, NULL, NULL);
		}
		//AresdenStormBringer
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 253) && (msY < sY + 262))
		{
			if(m_iEnemyKillCount < 10000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4957, NULL, NULL);
		}
		//ElvineStormBringer
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 268) && (msY < sY + 277))
		{
			if(m_iEnemyKillCount < 10000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4958, NULL, NULL);
		}
		// "Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
		{
			m_stDialogBoxInfo[52].cMode = 2;
			PlaySound('E', 14, 5);
		}
		// "Back Page" Button
		if ((msX > sX + 268) && (msX < sX + 350) && (msY > sY + 300) && (msY < sY + 315))
		{
			m_stDialogBoxInfo[52].cMode = 7;
		  	PlaySound('E', 14, 5);
		}

		//Botones - NetPanel
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;

	case 9: //Trade Ek List- Ring and Necks
		//RingofArcmage for RingofPowerMage
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))
		{
			if(m_iEnemyKillCount < 1700) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4965, NULL, NULL);
		}
		// RingoftheAbaddon for RingofPowerWar
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
		{
			if(m_iEnemyKillCount < 1700) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4964, NULL, NULL);
		}
		// NecklaceofMerien for NeckPower(MS.30)
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
		{
			if(m_iEnemyKillCount < 2600) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4966, NULL, NULL);
		}
		// NecklaceofKloness for NeckPowerMerien
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 148) && (msY < sY + 157))
		{
			if(m_iEnemyKillCount < 4000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4967, NULL, NULL);
		}
		// NecklaceofXelima for NeckPowerXelima
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 163) && (msY < sY + 172))
		{
			if(m_iEnemyKillCount < 8000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 4968, NULL, NULL);
		}
		// KnecklaceOfMedusa
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 178) && (msY < sY + 187))
		{
			if(m_iEnemyKillCount < 12000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 641, NULL, NULL);
		}
		// MagicNecklace(MS18) for KnecklceOfBeholder
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 193) && (msY < sY + 202)) //pt
		{
			if(m_iEnemyKillCount < 1000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 646, NULL, NULL);
		}
		/* MagicNecklace(RM30)
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 208) && (msY < sY + 217))
		{
			if(m_iEnemyKillCount < 1000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 901, NULL, NULL);
		}
		// MagicNecklace(DM+5)
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 223) && (msY < sY + 232))
		{
			if(m_iEnemyKillCount < 1000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 893, NULL, NULL);
		}
		// MagicNecklace(DF+30)
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 238) && (msY < sY + 247))
		{
			if(m_iEnemyKillCount < 1000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 889, NULL, NULL);
		}
		//BeholderNeck
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 253) && (msY < sY + 262))
		{
			if(m_iEnemyKillCount < 1000) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 646, NULL, NULL);
		}*/

		//"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
		{
			m_stDialogBoxInfo[52].cMode = 2;
		  	PlaySound('E', 14, 5);
		}

		//Botones - NetPanel
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;

	case 10: //Trade Ek List - Stones and DyeArmors
		//StoneOfXelimad
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))
		{
			if(m_iEnemyKillCount < 50) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 656, NULL, NULL);
		}
		//StoneOfMerien
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
		{
			if(m_iEnemyKillCount < 50) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 657, NULL, NULL);
		}
		//ZemstoneofSacrifice
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
		{
			if(m_iEnemyKillCount < 100) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 650, NULL, NULL);
		}		
		
		//"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
		{
			m_stDialogBoxInfo[52].cMode = 2;
		  	PlaySound('E', 14, 5);
		}

		//Botones - NetPanel
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;

	case 12: //Trade Ek List - Magics Manuals
		//Inhibition Casting
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))
		{
			if(m_iEnemyKillCount < 800) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 857, NULL, NULL);
		}
		/*//StoneOfMerien
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
		{
			if(m_iEnemyKillCount < 50) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 657, NULL, NULL);
		}
		//ZemstoneofSacrifice
		if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
		{
			if(m_iEnemyKillCount < 100) return;
			PlaySound('E', 14, 5);
			EnableDialogBox(53, 650, NULL, NULL);
		}*/		
		
		//"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
		{
			m_stDialogBoxInfo[52].cMode = 2;
		  	PlaySound('E', 14, 5);
		}

		//Botones - NetPanel
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			//Notice - Contents15.txt
			OpenNoticement();
			m_stDialogBoxInfo[52].cMode = 1;
			PlaySound('E', 14, 5);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_stDialogBoxInfo[52].cMode = 3;
			PlaySound('E', 14, 5);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_stDialogBoxInfo[52].cMode = 4;
			PlaySound('E', 14, 5);	
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_stDialogBoxInfo[52].cMode = 5;
			PlaySound('E', 14, 5);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			PlaySound('E', 14, 5);
			DisableDialogBox(52);
			DisableDialogBox(53);
		}
		break;
	}
}

void CGame::LoadTextNetPanel(short sX, short sY, short msX, short msY, short msZ, char cLB)
{
	int i, iTotalLines, iPointerLoc, iMaxLines, FinScroll;
	double d1,d2,d3;

	iMaxLines = 19;

	sX = m_stDialogBoxInfo[52].sX + 128;
	sY = m_stDialogBoxInfo[52].sY - 25;

	iTotalLines = 0;
	for (i = 0; i < DEF_TEXTDLGMAXLINES; i++)
	if (m_pMsgTextList[i] != NULL) iTotalLines++;
	if( iTotalLines > iMaxLines ) DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 237, sY + 93, 8);
	
	if( iGetTopDialogBoxIndex() == 52 && msZ != 0 )
	{
		m_stDialogBoxInfo[52].sView = m_stDialogBoxInfo[52].sView - msZ/60;
		m_DInput.m_sZ = 0;
	}
	if( m_stDialogBoxInfo[52].sView < 0 ) m_stDialogBoxInfo[52].sView = 0;
	if( iTotalLines>iMaxLines && m_stDialogBoxInfo[52].sView > iTotalLines-iMaxLines ) m_stDialogBoxInfo[52].sView = iTotalLines-iMaxLines;
		if (iTotalLines > iMaxLines) {
		d1 = (double)m_stDialogBoxInfo[52].sView;
		d2 = (double)(iTotalLines-iMaxLines);
		d3 = (248.0f * d1)/d2;
		iPointerLoc = (int)(d3+0.5);
		if( iTotalLines > iMaxLines ) DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 237, sY + 93, 8);
		DrawNewDialogBox(DEF_SPRID_INTERFACE_ND_GAME2, sX + 242, sY + 98 + iPointerLoc, 7);
	}
	else iPointerLoc = 0;
	for (i = 0; i < iMaxLines; i++)
	if (m_pMsgTextList[i + m_stDialogBoxInfo[52].sView] != NULL) {
		if (m_bDialogTrans == FALSE) { // v2.173
			switch (m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg[0]) {
			//Blanco
			case '-': PutAlignedString(sX, sX +250, sY + 100 +i*13, (m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg+1), 255,255,255); break;
			//Amarillo
			case ';': PutAlignedString(sX, sX +250, sY + 100 +i*13, (m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg+1), 244, 173, 1); break;
			//Rojo
			case '@': PutAlignedString(sX, sX +250, sY + 100 +i*13, (m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg+1), 218, 43, 43); break;
			//Azul
			case '&': PutAlignedString(sX, sX +250, sY + 100 +i*13, (m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg+1), 23, 132, 163); break;
			//Verde
			case '$': PutAlignedString(sX, sX +250, sY + 100 +i*13, (m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg+1), 92, 163, 23); break;
			//Marron
			case '<': PutAlignedString(sX, sX +250, sY + 100 +i*13, (m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg+1), 161, 120, 66); break;
			default: PutAlignedString(sX, sX +250, sY + 100 +i*13, m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg, 203,197,197); break;
			}
		}
		else PutAlignedString(sX, sX +250, sY + 100 +i*13, m_pMsgTextList[i + m_stDialogBoxInfo[52].sView]->m_pMsg, 203,197,197);
	}
	if (cLB != 0 && iTotalLines > iMaxLines) {
		if ((iGetTopDialogBoxIndex() == 52)) {
			FinScroll = 360;
			if ((msX >= sX + 242) && (msX <= sX + 254) && (msY >= sY + 98) && (msY <= sY + FinScroll)) {
				d1 = (double)(msY -(sY+98));
				d2 = (double)(iTotalLines-iMaxLines);
				d3 = (d1 * d2)/248.0f;
				iPointerLoc = (int)d3;
				if (iPointerLoc > iTotalLines-iMaxLines) iPointerLoc = iTotalLines-iMaxLines;
				m_stDialogBoxInfo[52].sView = iPointerLoc;
			}
		}
	}
	else m_stDialogBoxInfo[52].bIsScrollSelected = FALSE;
}

void CGame::DrawDialogBox_NetPanelConfirmation(short msX, short msY)
{
	short sX, sY;
	sX = m_stDialogBoxInfo[53].sX;
	sY = m_stDialogBoxInfo[53].sY;
	DrawNewDialogBox(DEF_SPRID_INTERFACE_ND_GAME1, sX, sY, 2);

	if (m_stDialogBoxInfo[53].sV1 > 0)
	{
		switch (m_stDialogBoxInfo[53].sV1)
		{
			/* Command Items */
		/*	//DkSet command
			case 1:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres", RGB(4,0,50));
				PutString(sX + 60, sY + 35, "usar el comando dkset?", RGB(4,0,50));
				break;*/
			//maname command
			case 2:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres", RGB(4,0,50));
				PutString(sX + 60, sY + 35, "usar el comando maname?", RGB(4,0,50));
				break;
			//zerkme command
			case 3:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres", RGB(4,0,50));
				PutString(sX + 60, sY + 35, "usar el comando zerkme?", RGB(4,0,50));
				break;
			//repme command
		/*	case 4:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres", RGB(4,0,50));
				PutString(sX + 66, sY + 35, "usar el comando repme?", RGB(4,0,50));
				break;*/
			//changecity command
			case 5:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres", RGB(4,0,50));
				PutString(sX + 54, sY + 35, "usar el comando changecity?", RGB(4,0,50));
				break;

					/* Trade Ek Items */
			//The_Devastator //acordate del f1 y el panel en f10
			case 846:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 104, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM6 "?", RGB(4,0,50));
				break;
			//DemonSlayer
			case 847:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 100, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM4 "?", RGB(4,0,50));
				break;
			//LightingBlade
			case 848:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 99, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM5 "?", RGB(4,0,50));
				break;
			//MerienShield
			case 620:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 95, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM13 "?", RGB(4,0,50));
				break;
			//MerienPlateMailM
			case 621:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 79, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM14 "?", RGB(4,0,50));
				break;
			//MerienPlateMailW
			case 622:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 83, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM15 "?", RGB(4,0,50));
				break;
	
			//ZemstoneofSacrifice
			case 650:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 70, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM28 "?", RGB(4,0,50));
				break;
			//StoneOfXelima
			case 656:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 90, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM26 "?", RGB(4,0,50));
				break;
			//StoneOfMerien
			case 657:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 90, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM27 "?", RGB(4,0,50));
				break;
		
			//GiantBattleHammer
			case 762:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 84, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM29 "?", RGB(4,0,50));
				break;
			//StormBringer
			case 845:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 92, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM10 "?", RGB(4,0,50));
				break;
			//KlonessBlade
			case 849:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 94, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM9 "?", RGB(4,0,50));
				break;
			//KlonessAxe
			case 850:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 87, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM7 "?", RGB(4,0,50));
				break;
			//KlonessEsterk
			case 851:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 89, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM8 "?", RGB(4,0,50));
				break;
			//Inhibition Casting Manual
			case 857:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 60, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM40 "?", RGB(4,0,50));
				break;
		
			//BerserkWand(MS.20)
			case 861:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 73, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM3 "?", RGB(4,0,50));
				break;
			//KlonessWand(MS.20)
			case 863:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 76, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM1 "?", RGB(4,0,50));
				break;
			//ResurWand(MS.20)
			case 865:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres el", RGB(4,0,50));
				PutString(sX + 83, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM2 "?", RGB(4,0,50));
				break;
		
			//ChaosWand
		/*	case 2090:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 87, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM12 "?", RGB(4,0,50));
				break;
			//ChaoSword
			case 890:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 82, sY + 35, DRAW_DIALOGBOX_TRADEEKITEM11 "?", RGB(4,0,50));
				break;
				*/
			//NetBox(Big)
			case 2600:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 100, sY + 35, "NetBox(Big)?", RGB(4,0,50));
				break;
			//NetBox(Medium)
			case 2601:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 92, sY + 35, "NetBox(Medium)?", RGB(4,0,50));
				break;
			//NetBox(Small)
			case 2602:
				PutString(sX + 60, sY + 20, "¿Estas seguro que quieres la", RGB(4,0,50));
				PutString(sX + 93, sY + 35, "NetBox(Small)?", RGB(4,0,50));
				break;
			default:
				break;
		}
	}
	if ((msX >= sX + 30) && (msX <= sX + 30 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY))
			 DrawNewDialogBox(DEF_SPRID_INTERFACE_ND_BUTTON, sX + 30, sY + 55 ,19);
	else DrawNewDialogBox(DEF_SPRID_INTERFACE_ND_BUTTON, sX + 30, sY + 55 , 18);

	if ((msX >= sX + 170 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY))
			 DrawNewDialogBox(DEF_SPRID_INTERFACE_ND_BUTTON, sX + 170 , sY + 55 , 3);
	else DrawNewDialogBox(DEF_SPRID_INTERFACE_ND_BUTTON, sX + 170, sY + 55 , 2);
}

//NetPanel 
void CGame::DrawDialogBox_NetPanel(short msX, short msY, short msZ, char cLB)
{
	short sX, sY, szX;
	DWORD dwTime = m_dwCurTime;
	int m_iRep = 1, m_iTopEkPosition = 248, m_iTotalDefense = 35;
	BOOL TopEkRanking;
	int z = 0, len = 0, i, TopEkPos = 0;
	short sY1=0, sY2 = 0;
	
	sX = m_stDialogBoxInfo[52].sX;
	sY = m_stDialogBoxInfo[52].sY;
	szX = m_stDialogBoxInfo[52].sSizeX;

	bSendCommand(MSGID_COMMAND_COMMON, DEF_RESQUEST_PLAYERREP, NULL, NULL, NULL, NULL, NULL);

	DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL, sX, sY, 6);

	TopEkRanking = FALSE;

	for (i = 0; i < 10; i++)
	{
		if (m_cPlayerName == TopEkList[i].Name)
		{
			TopEkRanking = TRUE;
			TopEkPos = i;
		}
	}

	//Player Info - NetPanel
	wsprintf(G_cTxt, "Name:"); // Nombre
	PutString( sX + 20, sY + 20, G_cTxt, RGB(146, 126, 104));
	wsprintf(G_cTxt, "%s", m_cPlayerName); // Nombre
	PutString( sX + 55, sY + 20, G_cTxt, RGB(255, 255, 255));
	if (TopEkRanking == TRUE)
	{
		PutString( sX + 20, sY + 66, G_cTxt, RGB(255, 255, 255));
		wsprintf(G_cTxt, "Top Ek Pos.:"); // TopEkPos.
		PutString( sX + 53, sY + 66, G_cTxt, RGB(146, 126, 104));
		wsprintf(G_cTxt, "%d", TopEkPos); // TopEkPos.
	}	
	wsprintf(G_cTxt, "Level:"); // Level
	PutString( sX + 20, sY + 80, G_cTxt, RGB(146, 126, 104));
	wsprintf(G_cTxt, "%d", m_iLevel); // Level
	PutString( sX + 53, sY + 80, G_cTxt, RGB(255, 255, 255));
	wsprintf(G_cTxt, "Reputation:"); // Reputation
	PutString( sX + 20, sY + 94, G_cTxt, RGB(146, 126, 104));
	wsprintf(G_cTxt, "%d", m_iReputation); // Reputation
	PutString( sX + 81, sY + 94, G_cTxt, RGB(255, 255, 255));
	wsprintf(G_cTxt, "Magesitics:"); // Magesitics
	PutString( sX + 20, sY + 108, G_cTxt, RGB(146, 126, 104));
	wsprintf(G_cTxt, "%d", m_iGizonItemUpgradeLeft); // Magesitics
	PutString( sX + 82, sY + 108, G_cTxt, RGB(255, 255, 255));
	wsprintf(G_cTxt, "Eks:"); // Eks
	PutString( sX + 20, sY + 122, G_cTxt, RGB(146, 126, 104));
	wsprintf(G_cTxt, "%d", m_iEnemyKillCount); // Eks
	PutString( sX + 44, sY + 122, G_cTxt, RGB(255, 255, 255));
	wsprintf(G_cTxt, "Event:"); // Event
	PutString( sX + 20, sY + 135, G_cTxt, RGB(146, 126, 104));
	if (m_iHeldenianAresdenLeftTower != -1)
	{	
		wsprintf(G_cTxt, "RushNet"); // Event
		PutString( sX + 55, sY + 135, G_cTxt, RGB(200, 255, 32));
	}
	else if (FuryDayMode == TRUE)
	{
		wsprintf(G_cTxt, "FuryDay"); // Event
		PutString( sX + 55, sY + 135, G_cTxt, RGB(200, 255, 32));
	}
	/*else if (HeldenianEvent == TRUE)
	{
		wsprintf(G_cTxt, "Heldenian"); // Event
		PutString( sX + 55, sY + 135, G_cTxt, RGB(200, 255, 32));
	}*/
	else
	{	
		wsprintf(G_cTxt, "NONE"); // Total Defense
		PutString( sX + 55, sY + 135, G_cTxt, RGB(255, 255, 255));
	}
	
	switch (m_stDialogBoxInfo[52].cMode) {
	case 0: //Principal
		/*wsprintf(G_cTxt, "Principal");
		PutString_SprFont2(sX+219, sY+51, G_cTxt, 250, 250, 0);
		_LoadTextDlgContents(m_stDialogBoxInfo[52].cMode + 16);
		LoadTextNetPanel(sX, sY, msX, msY, msZ, cLB);*/
		wsprintf(G_cTxt, "Principal");
		PutString_SprFont(sX+223, sY+51, G_cTxt, 250, 250, 0);
		_LoadTextDlgContents(3000);
		LoadTextNetPanel(sX, sY, msX, msY, msZ, cLB);
		//Botones - NetPanel
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 192, 1, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
		break;
	case 1: //Noticias
		wsprintf(G_cTxt, "Noticias");
		PutString_SprFont(sX+223, sY+51, G_cTxt, 250, 250, 0);
		_LoadTextDlgContents(1000);
		LoadTextNetPanel(sX, sY, msX, msY, msZ, cLB);

		if (NewNotices == TRUE)
		{
			NewNotices = FALSE;
		}

		//Botones - NetPanel
		//Notice Activado
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 163, 0);
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 192, 1, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
		break;
	case 2: //TradeEk
		//Trade Ek List - saintcrow
		PutString_SprFont(sX + 193, sY + 51, DRAW_DIALOGBOX_CITYHALL_MENU79, 250, 250, 0);
		
		/*if ((G_dwGlobalTime % 2000) < 968) {
			PutString_SprFont(sX + 193, sY + 51, DRAW_DIALOGBOX_CITYHALL_MENU79, 250,250,250);
		}*/
		PutAlignedString(sX, sX + 125 + szX, sY + 85, DRAW_DIALOGBOX_CITYHALL_MENU80, 250,250,250);//"Please select..."

		//Item Category
		// Armors and weapons
		if ((msX > sX + 171) && (msX < sX + 332) && (msY > sY + 115) && (msY < sY + 130))
			PutAlignedString(sX, sX + 120 + szX, sY + 115, DRAW_DIALOGBOX_CITYHALL_MENU81, 255,255,255);	//"
		else PutAlignedString(sX, sX + 120 + szX, sY + 115, DRAW_DIALOGBOX_CITYHALL_MENU81, 249,255,45);		//"

		//Magics Manuals
		if ((msX > sX + 171) && (msX < sX + 332) && (msY > sY + 155) && (msY < sY + 170))
			 PutAlignedString(sX, sX + 120 + szX, sY + 155, DRAW_DIALOGBOX_CITYHALL_MENU84, 255,255,255);	//"
		else PutAlignedString(sX, sX + 120 + szX, sY + 155, DRAW_DIALOGBOX_CITYHALL_MENU84, 249,255,45);

		//Rings and necks
		if ((msX > sX + 171) && (msX < sX + 332) && (msY > sY + 195) && (msY < sY + 210))
			 PutAlignedString(sX, sX + 120 + szX, sY + 195, DRAW_DIALOGBOX_CITYHALL_MENU82, 255,255,255);	//"
		else PutAlignedString(sX, sX + 120 + szX, sY + 195, DRAW_DIALOGBOX_CITYHALL_MENU82, 249,255,45);			//"

		//Stones and armor dyes
		if ((msX > sX + 171) && (msX < sX + 332) && (msY > sY + 235) && (msY < sY + 250))
			 PutAlignedString(sX, sX + 120 + szX, sY + 235, DRAW_DIALOGBOX_CITYHALL_MENU83, 255,255,255);	//"
		else PutAlignedString(sX, sX + 120 + szX, sY + 235, DRAW_DIALOGBOX_CITYHALL_MENU83, 249,255,45);		//"
		
		//Botones - NetPanel
		//Trade Ek Activado
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 192, 1);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
		break;

	case 3: //TopEk
		int k;
		wsprintf(G_cTxt, "Top Ek");
		PutString_SprFont(sX+221, sY+51, G_cTxt, 250, 250, 0);
		wsprintf(G_cTxt, "(solo players online)");
		PutString(sX + 200, sY + 70, G_cTxt, RGB(255,255,255));

		PutString(sX + 152, sY + 105, DRAW_DIALOGBOX_TOPEKLITS0, RGB(92,163,23)); // "Pos."
		PutString(sX + 190, sY + 105, DRAW_DIALOGBOX_TOPEKLITS1, RGB(92,163,23)); // "Nombre"
		PutString(sX + 260, sY + 105, DRAW_DIALOGBOX_TOPEKLITS2, RGB(92,163,23)); // "Ciudad"
		PutString(sX + 320, sY + 105, DRAW_DIALOGBOX_TOPEKLITS3, RGB(92,163,23)); // "Eks"
		
		sY1 = sY + 110;

		for (k = 0; k < 10; k++)
		{
			if (TopEkList[k].Name != NULL)
			{
				sY1 = sY1 + 15;
				
				if (TopEkList[k].side == 1)
					strcpy(TopEkList[k].City, "Aresden");
				else if (TopEkList[k].side == 2)
					strcpy(TopEkList[k].City, "Elvine");
				else strcpy (TopEkList[k].City, "NONE");

				if(k == 0)
				{
					wsprintf(G_cTxt, "%d", k+1); // Position
					PutString(sX + 154, sY1, G_cTxt, RGB(249,255,45));
					PutString(sX + 190, sY1, TopEkList[k].Name, RGB(249,255,45)); // CharName
					PutString(sX + 260, sY1, TopEkList[k].City, RGB(249,255,45)); // City
					wsprintf(G_cTxt, "%d", TopEkList[k].EkCount); // Eks
					PutString(sX + 320, sY1, G_cTxt, RGB(249,255,45)); // Eks
				}
				else
				{
					wsprintf(G_cTxt, "%d", k+1); // Position
					PutString(sX + 154, sY1, G_cTxt, RGB(255,255,255));
					PutString(sX + 190, sY1, TopEkList[k].Name, RGB(255,255,255)); // CharName
					PutString(sX + 260, sY1, TopEkList[k].City, RGB(255,255,255)); // City
					wsprintf(G_cTxt, "%d", TopEkList[k].EkCount); // Eks
					PutString(sX + 320, sY1, G_cTxt, RGB(255,255,255)); // Eks
				}
			}
		}
		
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 221, 2);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 192, 1, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
		break;
	case 4: //Eventos
		/*wsprintf(G_cTxt, "Eventos");
		PutString_SprFont(sX+223, sY+51, G_cTxt, 250, 250, 0);
		_LoadTextDlgContents(m_stDialogBoxInfo[52].cMode + 14);
		LoadTextNetPanel(sX, sY, msX, msY, msZ, cLB);*/
		wsprintf(G_cTxt, "Eventos");
		PutString_SprFont(sX+223, sY+51, G_cTxt, 250, 250, 0);
		_LoadTextDlgContents(2000);
		LoadTextNetPanel(sX, sY, msX, msY, msZ, cLB);
	/*	if (NewEventos == TRUE)
		{
			NewEventos = FALSE;
		}*/
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 250, 3);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 192, 1, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
		break;
	case 5: //Comandos
		wsprintf(G_cTxt, "Magestics Points Trade");
		PutString_SprFont(sX+170, sY+51, G_cTxt, 250, 250, 0);//217

		//ListCommand
		PutString(sX + 155, sY + 75, "Item                               Costo", RGB(255,255,255));

		//EspaceBar N° 1
		PutString(sX + 145, sY + 65, "-----------------------------------------------------", RGB(255,255,255));
		
		//EspaceBar N° 2
		PutString(sX + 145, sY + 84, "-----------------------------------------------------", RGB(255,255,255));

		//EspaceBar N° 3
		PutString(sX + 145, sY + 175, "-----------------------------------------------------", RGB(255,255,255));

		PutString(sX + 153, sY + 252, "Descripcion:", RGB(255,255,255));

		//DescripcionBox
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 148, sY + 268, 11);

		//Command DkSet
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 102) && (msY < sY + 111))
		{
			PutString(sX + 153, sY + 269, "Con este comando obtendras tu set", RGB(255,255,255));
			PutString(sX + 153, sY + 286, "DarkKnigth siendo del nivel 200. Ve", RGB(255,255,255));
			PutString(sX + 153, sY + 303, "al Shop para recibirlo.", RGB(255,255,255));
			if (m_iLevel >= 200)
				PutString(sX + 155, sY + 100, "dkset                            NONE", RGB(249,255,45));
			else PutString(sX + 155, sY + 100, "dkset                            NONE", RGB(165,165,165));	
		}
		else {
			if (m_iLevel >= 200)
				PutString(sX + 155, sY + 100, "dkset                            NONE", RGB(255,255,255));
			else PutString(sX + 155, sY + 100, "dkset                            NONE", RGB(165,165,165));
		}

/*		//Command repme
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 117) && (msY < sY + 126))
		{    
			PutString(sX + 153, sY + 269, "repme: Con este comando obtendras", RGB(255,255,255));
			PutString(sX + 153, sY + 286, "5 puntos de reputacion, a cambio", RGB(255,255,255));
			PutString(sX + 153, sY + 303, "de 25 magestics points.", RGB(255,255,255));
			if (m_iGizonItemUpgradeLeft >= 25)
				PutString(sX + 155, sY + 115, "repme                       25 Magestics", RGB(249,255,45));
			else PutString(sX + 155, sY + 115, "repme                       25 Magestics", RGB(165,165,165));
		}
		else {
			if (m_iGizonItemUpgradeLeft >= 25)
				PutString(sX + 155, sY + 115, "repme                       25 Magestics", RGB(255,255,255));
			else PutString(sX + 155, sY + 115, "repme                       25 Magestics", RGB(165,165,165));
		}
		*/
		//Command maname
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 132) && (msY < sY + 141))
		{
			PutString(sX + 153, sY + 269, "maname: Con este comando tendras", RGB(255,255,255));
			PutString(sX + 153, sY + 286, "mana ilimitado por 5 minutos, a", RGB(255,255,255));
			PutString(sX + 153, sY + 303, "cambio de 300 magestics points.", RGB(255,255,255));
			if (m_iGizonItemUpgradeLeft >= 300)
				PutString(sX + 155, sY + 130, "maname                  300 Magestics", RGB(249,255,45));
			else PutString(sX + 155, sY + 130, "maname                  300 Magestics", RGB(165,165,165));	
		}
		else {
			if (m_iGizonItemUpgradeLeft >= 300)
				PutString(sX + 155, sY + 130, "maname                  300 Magestics", RGB(255,255,255));
			else PutString(sX + 155, sY + 130, "maname                  300 Magestics", RGB(165,165,165));
		}
		//Command zerkme
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 147) && (msY < sY + 156))
		{    
			PutString(sX + 153, sY + 269, "zerkme: Con este comando tendras", RGB(255,255,255));
			PutString(sX + 153, sY + 286, "berserk por 10 minutos, a cambio", RGB(255,255,255));
			PutString(sX + 153, sY + 303, "de 300 magestics points.", RGB(255,255,255));
			if (m_iGizonItemUpgradeLeft >= 300)
				PutString(sX + 155, sY + 145, "zerkme                   300 Magestics", RGB(249,255,45));
			else PutString(sX + 155, sY + 145, "zerkme                   300 Magestics", RGB(165,165,165));
		}
		else {
			if (m_iGizonItemUpgradeLeft >= 300)
				PutString(sX + 155, sY + 145, "zerkme                   300 Magestics", RGB(255,255,255));
			else PutString(sX + 155, sY + 145, "zerkme                   300 Magestics", RGB(165,165,165));
		}
		//Command changecity
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 162) && (msY < sY + 171))
		{    
			PutString(sX + 153, sY + 269, "changecity: Con este comando", RGB(255,255,255));
			PutString(sX + 153, sY + 286, "podras cambiar de ciudad, a", RGB(255,255,255));
			PutString(sX + 153, sY + 303, "cambio de 800 magestics points.", RGB(255,255,255));
			if (m_iGizonItemUpgradeLeft >= 800)
				PutString(sX + 155, sY + 160, "changecity             800 Magestics", RGB(249,255,45));
			else PutString(sX + 155, sY + 160, "changecity             800 Magestics", RGB(165,165,165));
		}
		else
		{
			if (m_iGizonItemUpgradeLeft >= 800)
				PutString(sX + 155, sY + 160, "changecity             800 Magestics", RGB(255,255,255));
			else PutString(sX + 155, sY + 160, "changecity             800 Magestics", RGB(165,165,165));
		}

		//--------------------------------------------------------------

		//Command NetBox(Small)
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 192) && (msY < sY + 201))
		{    
			PutString(sX + 153, sY + 269, "Con esta caja obtendras un ", RGB(255,255,255));
			PutString(sX + 153, sY + 286, "item totalmente al azar.", RGB(255,255,255));
			PutString(sX + 153, sY + 303, "", RGB(255,255,255));
			if (m_iGizonItemUpgradeLeft >= 100)
				PutString(sX + 155, sY + 190, "PandoraBox(Small)       100 Magestics", RGB(249,255,45));
			else PutString(sX + 155, sY + 190, "PandoraBox(Small)       100 Magestics", RGB(165,165,165));
		}
		else
		{
			if (m_iGizonItemUpgradeLeft >= 100)
				PutString(sX + 155, sY + 190, "PandoraBox(Small)       100 Magestics", RGB(255,255,255));
			else PutString(sX + 155, sY + 190, "PandoraBox(Small)       100 Magestics", RGB(165,165,165));
		}

		//Command NetBox(Medium)
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 207) && (msY < sY + 216))
		{    
			PutString(sX + 153, sY + 269, "Con esta caja obtendras un ", RGB(255,255,255));
			PutString(sX + 153, sY + 286, "item totalmente al azar.", RGB(255,255,255));
			PutString(sX + 153, sY + 303, "", RGB(255,255,255));
			if (m_iGizonItemUpgradeLeft >= 250)
				PutString(sX + 155, sY + 205, "PandoraBox(Medium)   250 Magestics", RGB(249,255,45));
			else PutString(sX + 155, sY + 205, "PandoraBox(Medium)   250 Magestics", RGB(165,165,165));
		}
		else
		{
			if (m_iGizonItemUpgradeLeft >= 250)
				PutString(sX + 155, sY + 205, "PandoraBox(Medium)   250 Magestics", RGB(255,255,255));
			else PutString(sX + 155, sY + 205, "PandoraBox(Medium)   250 Magestics", RGB(165,165,165));
		}

		//Command NetBox(Big)
		if ((msX > sX + 154) && (msX < sX + 328) && (msY > sY + 222) && (msY < sY + 231))
		{    
			PutString(sX + 153, sY + 269, "Con esta caja obtendras un ", RGB(255,255,255));
			PutString(sX + 153, sY + 286, "item totalmente al azar.", RGB(255,255,255));
			PutString(sX + 153, sY + 303, "", RGB(255,255,255));
			if (m_iGizonItemUpgradeLeft >= 500)
				PutString(sX + 155, sY + 220, "PandoraBox(Big)           500 Magestics", RGB(249,255,45));
			else PutString(sX + 155, sY + 220, "PandoraBox(Big)           500 Magestics", RGB(165,165,165));
		}
		else
		{
			if (m_iGizonItemUpgradeLeft >= 500)
				PutString(sX + 155, sY + 220, "PandoraBox(Big)           500 Magestics", RGB(255,255,255));
			else PutString(sX + 155, sY + 220, "PandoraBox(Big)           500 Magestics", RGB(165,165,165));
		}

		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 279, 4);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Trade Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 194) && (msY < sY + 217)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 192, 1, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
		break;

	case 7:	//Armor and weapons Page 1
		PutString_SprFont(sX + 170, sY + 51, DRAW_DIALOGBOX_CITYHALL_MENU81, 250, 250, 0);
		
		//EspaceBar N° 1
		PutString(sX + 145, sY + 65, "-----------------------------------------------------", RGB(255,255,255));
		
		//EspaceBar N° 2
		PutString(sX + 145, sY + 84, "-----------------------------------------------------", RGB(255,255,255));

		PutString(sX + 155, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0, RGB(255,255,255));
		PutString(sX + 305, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0a, RGB(255,255,255));
		
		if (m_iEnemyKillCount >= 50000) //KlonessWand(MS.20)
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))		
			{   			
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM1, RGB(249,255,45));
				PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM1a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM1, RGB(255,255,255));
				PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM1a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM1, RGB(165,165,165));
			PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM1a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 10000) //ResurWand(MS.20)
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
			{   			
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM2, RGB(249,255,45));
				PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM2a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM2, RGB(255,255,255));
				PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM2a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM2, RGB(165,165,165));
			PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM2a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 90000) //BerserkWand(MS.20)
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
			{			
				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM3, RGB(249,255,45));
				PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM3a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM3, RGB(255,255,255));
				PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM3a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM3, RGB(165,165,165));
			PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM3a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 15000) //DemonSlayer
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 148) && (msY < sY + 157))
			{			
				PutString(sX + 155, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM4, RGB(249,255,45));
				PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM4a, RGB(249,255,45));
			}
			else{
				PutString(sX + 155, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM4, RGB(255,255,255));
				PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM4a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM4, RGB(165,165,165));
			PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM4a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 80000) //LightingBlade
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 163) && (msY < sY + 172))
			{		
				PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM5, RGB(249,255,45));
				PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM5a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM5, RGB(255,255,255));
				PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM5a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM5, RGB(165,165,165));
			PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM5a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 180000) //TheDevastator
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 178) && (msY < sY + 187))
			{  			
				PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM6, RGB(249,255,45));
				PutString(sX + 295, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM6a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM6, RGB(255,255,255));
				PutString(sX + 295, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM6a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM6, RGB(165,165,165));
			PutString(sX + 295, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM6a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 50000) //KlonessAxe
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 193) && (msY < sY + 202))
			{   			
				PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM7, RGB(249,255,45));
				PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM7a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM7, RGB(255,255,255));
				PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM7a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM7, RGB(165,165,165));
			PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM7a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 25000) //KlonessEsterk
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 208) && (msY < sY + 217))
			{    
				PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM8, RGB(249,255,45));
				PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM8a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM8, RGB(255,255,255));
				PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM8a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM8, RGB(165,165,165));
			PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM8a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 90000) //KlonessBlade
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 223) && (msY < sY + 232))
			{    			
				PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM9, RGB(249,255,45));
				PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM9a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM9, RGB(255,255,255));
				PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM9a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM9, RGB(165,165,165));
			PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM9a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 160000) //StormBringer
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 238) && (msY < sY + 247))
			{   		
				PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM10, RGB(249,255,45));
				PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM10a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM10, RGB(255,255,255));
				PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM10a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM10, RGB(165,165,165));
			PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM10a, RGB(165,165,165));
		}
		/*if (m_iEnemyKillCount >= 10000) //AresdenHeroBlade
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 253) && (msY < sY + 262))
			{  		
				PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM11, RGB(249,255,45));
				PutString(sX + 292, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM11a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM11, RGB(255,255,255));
				PutString(sX + 292, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM11a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM11, RGB(165,165,165));
			PutString(sX + 292, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM11a, RGB(165,165,165));
		}
		*/
	/*	if (m_iEnemyKillCount >= 10000) //ElvineHeroBlade
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 268) && (msY < sY + 277))
			{ 			
				PutString(sX + 155, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM12, RGB(249,255,45));
				PutString(sX + 292, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM12a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM12, RGB(255,255,255));
				PutString(sX + 292, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM12a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM12, RGB(165,165,165));
			PutString(sX + 292, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM12a, RGB(165,165,165));
		}
		*/
		//"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
			 PutString_SprFont(sX + 149, sY + 300, "Menu", 250,250,250);
		else PutString_SprFont(sX + 149, sY + 300, "Menu", 1,1,8);
		
		//"Next Page" Button
		if ((msX > sX + 268) && (msX < sX + 350) && (msY > sY + 300) && (msY < sY + 315))
			 PutString_SprFont(sX + 285, sY + 300, "Siguiente", 250,250,250);
		else PutString_SprFont(sX + 285, sY + 300, "Siguiente", 1,1,8);

		//Botones - NetPanel
		//Trade Ek Activado
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 192, 1);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
	   break;

	case 8: 
		//Armor and weapons Page 2		
		PutString_SprFont(sX + 170, sY + 51, DRAW_DIALOGBOX_CITYHALL_MENU81, 250, 250, 0);

		//EspaceBar N° 1
		PutString(sX + 145, sY + 65, "-----------------------------------------------------", RGB(255,255,255));
		
		//EspaceBar N° 2
		PutString(sX + 145, sY + 84, "-----------------------------------------------------", RGB(255,255,255));

		PutString(sX + 155, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0, RGB(255,255,255));
		PutString(sX + 305, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0a, RGB(255,255,255));
		
		if (m_iEnemyKillCount >= 12000) //GiantBattleHammer
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))		
			{   			
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM29, RGB(249,255,45));
				PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM29a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM29, RGB(255,255,255));
				PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM29a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM29, RGB(165,165,165));
			PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM29a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 30000) //MerienShield
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))		
			{   			
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM13, RGB(249,255,45));
				PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM13a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM13, RGB(255,255,255));
				PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM13a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM13, RGB(165,165,165));
			PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM13a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 20000) //MerienPlateMailM
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
			{   			
				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM14, RGB(249,255,45));
				PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM14a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM14, RGB(255,255,255));
				PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM14a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM14, RGB(165,165,165));
			PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM14a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 20000) //MerienPlateMailW
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 148) && (msY < sY + 157))
			{			
				PutString(sX + 154, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM15, RGB(249,255,45));
				PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM15a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM15, RGB(255,255,255));
				PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM15a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM15, RGB(165,165,165));
			PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM15a, RGB(165,165,165));
		}
	/*	if (m_iEnemyKillCount >= 6000) //BlackAxe
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 163) && (msY < sY + 172))
			{		
				PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM42, RGB(249,255,45));
				PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM42a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM42, RGB(255,255,255));
				PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM42a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM42, RGB(165,165,165));
			PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM42a, RGB(165,165,165));
		}
		
		if (m_iEnemyKillCount >= 8000) //BlackHammer
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 178) && (msY < sY + 187))
			{  			
				PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM43, RGB(249,255,45));
				PutString(sX + 295, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM43a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM43, RGB(255,255,255));
				PutString(sX + 295, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM43a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM43, RGB(165,165,165));
			PutString(sX + 295, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM43a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 15000) //BlackDevastator
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 193) && (msY < sY + 202))
			{   			
				PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM44, RGB(249,255,45));
				PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM44a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM44, RGB(255,255,255));
				PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM44a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM44, RGB(165,165,165));
			PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM44a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 3000) //BlackTowerShield
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 208) && (msY < sY + 217))
			{    
				PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM45, RGB(249,255,45));
				PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM45a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM45, RGB(255,255,255));
				PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM45a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM45, RGB(165,165,165));
			PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM45a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 7000) //AresElfBow
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 223) && (msY < sY + 232))
			{    			
				PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM46, RGB(249,255,45));
				PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM46a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM46, RGB(255,255,255));
				PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM46a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM46, RGB(165,165,165));
			PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM46a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 7000) //ElvinElfBow
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 238) && (msY < sY + 247))
			{   		
				PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM47, RGB(249,255,45));
				PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM47a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM47, RGB(255,255,255));
				PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM47a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM47, RGB(165,165,165));
			PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM47a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 15000) //AresdenStormBringer
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 253) && (msY < sY + 262))
			{  		
				PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM48, RGB(249,255,45));
				PutString(sX + 292, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM48a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM48, RGB(255,255,255));
				PutString(sX + 292, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM48a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM48, RGB(165,165,165));
			PutString(sX + 292, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM48a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 15000) //ElvineStormBringer
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 268) && (msY < sY + 277))
			{ 			
				PutString(sX + 155, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM49, RGB(249,255,45));
				PutString(sX + 292, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM49a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM49, RGB(255,255,255));
				PutString(sX + 292, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM49a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM49, RGB(165,165,165));
			PutString(sX + 292, sY + 265, DRAW_DIALOGBOX_TRADEEKITEM49a, RGB(165,165,165));
		}
		*/
		//"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
			 PutString_SprFont(sX + 149, sY + 300, "Menu", 250,250,250);
		else PutString_SprFont(sX + 149, sY + 300, "Menu", 1,1,8);

		//"Back Page" Button
		if ((msX > sX + 268) && (msX < sX + 350) && (msY > sY + 300) && (msY < sY + 315))
			 PutString_SprFont(sX + 300, sY + 300, "Atras", 250,250,250);
		else PutString_SprFont(sX + 300, sY + 300, "Atras", 1,1,8);	

		//Botones - NetPanel
		//Trade Ek Activado
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 192, 1);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
	   break;

	case 9: //Rings and Neck page
	    PutString_SprFont(sX + 188, sY + 51, DRAW_DIALOGBOX_CITYHALL_MENU82, 250, 250, 0);
	   
		//EspaceBar N° 1
		PutString(sX + 145, sY + 65, "-----------------------------------------------------", RGB(255,255,255));
		
		//EspaceBar N° 2
		PutString(sX + 145, sY + 84, "-----------------------------------------------------", RGB(255,255,255));

		PutString(sX + 155, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0, RGB(255,255,255));
		PutString(sX + 305, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0a, RGB(255,255,255));
		
		if (m_iEnemyKillCount >= 5500) //RingofArcmage
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))		
			{   			
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM16, RGB(249,255,45));
				PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM16a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM16, RGB(255,255,255));
				PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM16a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM16, RGB(165,165,165));
			PutString(sX + 295, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM16a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 5500) //RingoftheAbaddon RingofPowerWar
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
			{   			
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM17, RGB(249,255,45));
				PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM17a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM17, RGB(255,255,255));
				PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM17a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM17, RGB(165,165,165));
			PutString(sX + 295, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM17a, RGB(165,165,165));
		}
		/*if (m_iEnemyKillCount >= 3500) //NecklaceofMerien 
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
			{			
//				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM18, RGB(249,255,45));
//				PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM18a, RGB(249,255,45));
			}
			else {
//				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM18, RGB(255,255,255));
//				PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM18a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM18, RGB(165,165,165));
			PutString(sX + 295, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM18a, RGB(165,165,165));
		}
	*/
	 /* if (m_iEnemyKillCount >= 9000) //NecklaceofKloness
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 148) && (msY < sY + 157))
			{			
				PutString(sX + 155, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM19, RGB(249,255,45));
				PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM19a, RGB(249,255,45));
			}
			else{
				PutString(sX + 155, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM19, RGB(255,255,255));
				PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM19a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM19, RGB(165,165,165));
			PutString(sX + 295, sY + 145, DRAW_DIALOGBOX_TRADEEKITEM19a, RGB(165,165,165));
		}
		*/
	/*	if (m_iEnemyKillCount >= 8000) //NecklaceofXelima
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 163) && (msY < sY + 172))
			{		
				PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM20, RGB(249,255,45));
				PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM20a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM20, RGB(255,255,255));
				PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM20a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM20, RGB(165,165,165));
			PutString(sX + 295, sY + 160, DRAW_DIALOGBOX_TRADEEKITEM20a, RGB(165,165,165));
		}
		*/
		if (m_iEnemyKillCount >= 25000) //KnecklaceOfMedusa
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 178) && (msY < sY + 187))
			{  			
				PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM21, RGB(249,255,45));
				PutString(sX + 290, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM21a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM21, RGB(255,255,255));
				PutString(sX + 290, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM21a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM21, RGB(165,165,165));
			PutString(sX + 290, sY + 175, DRAW_DIALOGBOX_TRADEEKITEM21a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 50000) //BeholderNeck
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 193) && (msY < sY + 202))
			{   			
				PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM22, RGB(249,255,45));
				PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM22a, RGB(249,255,45));
			}
			else {
				PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM22, RGB(255,255,255));
				PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM22a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 155, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM22, RGB(165,165,165));
			PutString(sX + 295, sY + 190, DRAW_DIALOGBOX_TRADEEKITEM22a, RGB(165,165,165));
		}
		//if (m_iEnemyKillCount >= 1500) //MagicNecklace(RM30)
		//{
		//	if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 208) && (msY < sY + 217))
		//	{    
		//		PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM23, RGB(249,255,45));
		//		PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM23a, RGB(249,255,45));
		//	}
		//	else {
		//		PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM23, RGB(255,255,255));
		//		PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM23a, RGB(255,255,255));
		//	}
		//}
		//else {
		//	PutString(sX + 155, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM23, RGB(165,165,165));
		//	PutString(sX + 295, sY + 205, DRAW_DIALOGBOX_TRADEEKITEM23a, RGB(165,165,165));
		//}
		//if (m_iEnemyKillCount >= 1500) //MagicNecklace(DM+5)
		//{
		//	if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 223) && (msY < sY + 232))
		//	{    			
		//		PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM24, RGB(249,255,45));
		//		PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM24a, RGB(249,255,45));
		//	}
		//	else {
		//		PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM24, RGB(255,255,255));
		//		PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM24a, RGB(255,255,255));
		//	}
		//}
		//else {
		//	PutString(sX + 155, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM24, RGB(165,165,165));
		//	PutString(sX + 295, sY + 220, DRAW_DIALOGBOX_TRADEEKITEM24a, RGB(165,165,165));
		//}
		//if (m_iEnemyKillCount >= 1500) //MagicNecklace(DF+30)
		//{
		//	if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 238) && (msY < sY + 247))
		//	{   		
		//		PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM25, RGB(249,255,45));
		//		PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM25a, RGB(249,255,45));
		//	}
		//	else {
		//		PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM25, RGB(255,255,255));
		//		PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM25a, RGB(255,255,255));
		//	}
		//}
		//else {
		//	PutString(sX + 155, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM25, RGB(165,165,165));
		//	PutString(sX + 295, sY + 235, DRAW_DIALOGBOX_TRADEEKITEM25a, RGB(165,165,165));
		//}
		//if (m_iEnemyKillCount >= 10000) //NecklaceOfBeholder
		//{
		//	if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 253) && (msY < sY + 262))
		//	{  		
		//		PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM37, RGB(249,255,45));
		//		PutString(sX + 290, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM37a, RGB(249,255,45));
		//	}
		//	else {
		//		PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM37, RGB(255,255,255));
		//		PutString(sX + 290, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM37a, RGB(255,255,255));
		//	}
		//}
		//else {
		//	PutString(sX + 155, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM37, RGB(165,165,165));
		//	PutString(sX + 290, sY + 250, DRAW_DIALOGBOX_TRADEEKITEM37a, RGB(165,165,165));
		//}

	    //"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
			 PutString_SprFont(sX + 149, sY + 300, "Menu", 250,250,250);
		else PutString_SprFont(sX + 149, sY + 300, "Menu", 1,1,8);

		//Botones - NetPanel
		//Trade Ek Activado
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 192, 1);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
	   break;

	case 10: //stones and armor dyes
		PutString_SprFont(sX + 215, sY + 51, DRAW_DIALOGBOX_CITYHALL_MENU83, 250, 250, 0);

		//EspaceBar N° 1
		PutString(sX + 145, sY + 65, "-----------------------------------------------------", RGB(255,255,255));
		
		//EspaceBar N° 2
		PutString(sX + 145, sY + 84, "-----------------------------------------------------", RGB(255,255,255));
		
		PutString(sX + 155, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0, RGB(255,255,255));
		PutString(sX + 305, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0a, RGB(255,255,255));

		if (m_iEnemyKillCount >= 100) //StoneOfXelima
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))		
			{   			
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM26, RGB(249,255,45));
				PutString(sX + 310, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM26a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM26, RGB(255,255,255));
				PutString(sX + 310, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM26a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM26, RGB(165,165,165));
			PutString(sX + 310, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM26a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 100) //StoneOfMerien
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
			{   			
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27, RGB(249,255,45));
				PutString(sX + 310, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27, RGB(255,255,255));
				PutString(sX + 310, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27, RGB(165,165,165));
			PutString(sX + 310, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 100) //ZemStoneOfSacrifice
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
			{			
				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28, RGB(249,255,45));
				PutString(sX + 305, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28, RGB(255,255,255));
				PutString(sX + 305, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28, RGB(165,165,165));
			PutString(sX + 305, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28a, RGB(165,165,165));
		}
		
		//"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
			 PutString_SprFont(sX + 149, sY + 300, "Menu", 250,250,250);
		else PutString_SprFont(sX + 149, sY + 300, "Menu", 1,1,8);

		//Botones - NetPanel
		//Trade Ek Activado
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 192, 1);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
		break;

	case 12:
		PutString_SprFont(sX + 185, sY + 51, DRAW_DIALOGBOX_CITYHALL_MENU84, 250, 250, 0);

		//EspaceBar N° 1
		PutString(sX + 145, sY + 65, "-----------------------------------------------------", RGB(255,255,255));
		
		//EspaceBar N° 2
		PutString(sX + 145, sY + 84, "-----------------------------------------------------", RGB(255,255,255));
		
		PutString(sX + 155, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0, RGB(255,255,255));
		PutString(sX + 305, sY + 75, DRAW_DIALOGBOX_TRADEEKITEM0a, RGB(255,255,255));

		if (m_iEnemyKillCount >= 12000) //Inhibition Casting Manual
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 103) && (msY < sY + 112))		
			{   			
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM40, RGB(249,255,45));
				PutString(sX + 310, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM41a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM40, RGB(255,255,255));
				PutString(sX + 310, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM41a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM40, RGB(165,165,165));
			PutString(sX + 310, sY + 100, DRAW_DIALOGBOX_TRADEEKITEM41a, RGB(165,165,165));
		}
		/*if (m_iEnemyKillCount >= 50) //StoneOfMerien
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 118) && (msY < sY + 127))
			{   			
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27, RGB(249,255,45));
				PutString(sX + 310, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27, RGB(255,255,255));
				PutString(sX + 310, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27, RGB(165,165,165));
			PutString(sX + 310, sY + 115, DRAW_DIALOGBOX_TRADEEKITEM27a, RGB(165,165,165));
		}
		if (m_iEnemyKillCount >= 100) //ZemStoneOfSacrifice
		{
			if ((msX > sX + 154) && (msX < sX + 345) && (msY > sY + 133) && (msY < sY + 142))
			{			
				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28, RGB(249,255,45));
				PutString(sX + 305, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28a, RGB(249,255,45));
			}
			else {
				PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28, RGB(255,255,255));
				PutString(sX + 305, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28a, RGB(255,255,255));
			}
		}
		else {
			PutString(sX + 154, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28, RGB(165,165,165));
			PutString(sX + 305, sY + 130, DRAW_DIALOGBOX_TRADEEKITEM28a, RGB(165,165,165));
		}*/
		
		//"Back to Main" Button
		if ((msX > sX + 149) && (msX < sX + 190) && (msY > sY + 300) && (msY < sY + 315))
			 PutString_SprFont(sX + 149, sY + 300, "Menu", 250,250,250);
		else PutString_SprFont(sX + 149, sY + 300, "Menu", 1,1,8);

		//Botones - NetPanel
		//Trade Ek Activado
		DrawNewDialogBox(DEF_SPRID_INTERFACE_NETPANEL,sX + 15, sY + 192, 1);
		// Noticias
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 165) && (msY < sY + 188)) 
		{ 
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 163, 0, dwTime);
		}
		// Top Ek
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 223) && (msY < sY + 246)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 221, 2, dwTime);
		}
		// Eventos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 252) && (msY < sY + 275)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 250, 3, dwTime);
		}
		// Comandos
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 281) && (msY < sY + 304)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 279, 4, dwTime);
		}
		// Cerrar
		if((msX > sX + 17 ) && (msX < sX + 132) && (msY > sY + 310) && (msY < sY + 333)) 
		{
			m_pSprite[DEF_SPRID_INTERFACE_NETPANEL]->PutSpriteFast(sX + 15, sY + 308, 5, dwTime);
		}
		break;
	}
}
/*****************************************************************************************************************
***** void CGame::DrawDialogBox_ChangeCity(short msX, short msY)											 *****
*****--------------------------------------------------------------------------------------------------------*****
***** Créditos		:: By hora		
****  Usando la base de : Centuu.-																	 *****
***** Descripción	:: Pregunta si quieres elegir de ciudad.												 *****
*****************************************************************************************************************/

void CGame::DrawDialogBox_Destiny(short msX, short msY)
{short sX, sY;
	sX = m_stDialogBoxInfo[54].sX;
	sY = m_stDialogBoxInfo[54].sY;
	DrawNewDialogBox(DEF_SPRID_INTERFACE_ND_GAME1, sX, sY, 2);
	PutString(sX + 70, sY + 20, "Helbreath Return", RGB(255,165,0));
	PutString(sX + 80, sY + 35, "Choose your city", RGB(255,215,0));
	if ((msX >= sX + 50) && (msX <= sX + 50 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 60 + DEF_BTNSZY))
	{	PutString(sX + 50, sY + 55, DRAW_DIALOGBOX_DESTINY1 , RGB(255,69,0));
	}else {	 
		PutString(sX + 50, sY + 55, DRAW_DIALOGBOX_DESTINY1 , RGB(4,0,50));
	}	    
	if ((msX >= sX + 160 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY)) 
	{
		PutString(sX + 160, sY + 55, DRAW_DIALOGBOX_DESTINY2 , RGB(65,105,255));
	}else{
		PutString(sX + 160, sY + 55, DRAW_DIALOGBOX_DESTINY2 , RGB(4,0,50));
	}
}
/*****************************************************************************************************************
***** void CGame::DlgBoxClick_ChangeCity(short msX, short msY)												 *****
*****--------------------------------------------------------------------------------------------------------*****
***** Créditos		:: By hora		
****  Usando la base de : Centuu.-																			 *****
***** Descripción	:: Da las opciones Aresden o Elvine para elejir.										 *****
*****************************************************************************************************************/

void CGame::DlgBoxClick_ChangeDestiny(short msX, short msY)
{short sX, sY;
	sX = m_stDialogBoxInfo[54].sX;
	sY = m_stDialogBoxInfo[54].sY;
	if ((msX >= sX + 50) && (msX <= sX + 50 + DEF_BTNSZX) && (msY >= sY + 55) && (msY <= sY + 55 + DEF_BTNSZY)) 
	{   bSendCommand(DEF_REQUEST_DESTINY, NULL, NULL, 1, NULL ,NULL, NULL, NULL);
		DisableDialogBox(54);
		bSendCommand(MSGID_REQUEST_CIVILRIGHT, DEF_MSGTYPE_CONFIRM, NULL, NULL, NULL, NULL, NULL);
	}else if ((msX >= sX + 160 ) && (msX <= sX + 170 + DEF_BTNSZX ) && (msY >= sY + 55 ) && (msY <= sY + 55 + DEF_BTNSZY)) 
	{	bSendCommand(DEF_REQUEST_DESTINY, NULL, NULL, 2, NULL ,NULL, NULL, NULL);
	DisableDialogBox(54);
		bSendCommand(MSGID_REQUEST_CIVILRIGHT, DEF_MSGTYPE_CONFIRM, NULL, NULL, NULL, NULL, NULL);
	}
}




void CGame::TestList(char * pTxt, char cColor, BOOL bDupAllow)
{int i;
if ((bDupAllow == FALSE) && (strcmp(m_stEventHistory[5].cTxt, pTxt) == 0)) return;
if (cColor == 11, 12, 13)
{ for (i = 1; i < 6; i++)
{ strcpy(m_stEventHistory2[i-1].cTxt, m_stEventHistory2[i].cTxt);
m_stEventHistory2[i-1].cColor = m_stEventHistory2[i].cColor;
m_stEventHistory2[i-1].dwTime = m_stEventHistory2[i].dwTime;
}
ZeroMemory(m_stEventHistory2[5].cTxt, sizeof(m_stEventHistory2[5].cTxt));
strcpy(m_stEventHistory2[5].cTxt, pTxt);
m_stEventHistory2[5].cColor = cColor;
m_stEventHistory2[5].dwTime = m_dwCurTime;
}else
{ for (i = 1; i < 6; i++)
{ strcpy(m_stEventHistory[i-1].cTxt, m_stEventHistory[i].cTxt);
m_stEventHistory[i-1].cColor = m_stEventHistory[i].cColor;
m_stEventHistory[i-1].dwTime = m_stEventHistory[i].dwTime;
}
ZeroMemory(m_stEventHistory[5].cTxt, sizeof(m_stEventHistory[5].cTxt));
strcpy(m_stEventHistory[5].cTxt, pTxt);
m_stEventHistory[5].cColor = cColor;
m_stEventHistory[5].dwTime = m_dwCurTime;
}
}


void CGame::NotifyMsg_DGKill(char *pData) // MORLA 2.2 - Actualiza la info del Deathmach Game
{
 char * cp, cStr[11];
 int  * ip, iV1, iV2, iV3;

	cp = (char *)(pData + DEF_INDEX2_MSGTYPE + 2);

	ip = (int *)cp;
	iV1 = *ip;
	cp += 4;

	ip = (int *)cp;
	iV2 = *ip;
	cp += 4;

	ip = (int *)cp;
	iV3 = *ip;
	cp += 4;

	ZeroMemory(cStr, sizeof(cStr));
	memcpy(cStr, cp, 10);
	cp += 10;

switch (iV1)
{
	case 1:	
		iDGKill1 = iV2;	
		iDGDeath1 = iV3; 
		ZeroMemory(cDGName1, sizeof(cDGName1)); 
		memcpy (cDGName1, cStr, 10); 
		break;
	case 2:	
		iDGKill2 = iV2;
		iDGDeath2 = iV3;
		ZeroMemory(cDGName2, sizeof(cDGName2));
		memcpy (cDGName2, cStr, 10);
		break;
	case 3:	
		iDGKill3 = iV2;	
		iDGDeath3 = iV3; 
		ZeroMemory(cDGName3, sizeof(cDGName3)); 
		memcpy (cDGName3, cStr, 10); 
		break;
	case 4:	
		iDGKill4 = iV2;	
		iDGDeath4 = iV3; 
		ZeroMemory(cDGName4, sizeof(cDGName4)); 
		memcpy (cDGName4, cStr, 10); break;
	case 5:	
		iDGKill5 = iV2;	
		iDGDeath5 = iV3; 
		ZeroMemory(cDGName5, sizeof(cDGName5)); 
		memcpy (cDGName5, cStr, 10); 
		break;
	case 6:	
		iDGKill6 = iV2;	
		iDGDeath6 = iV3; 
		ZeroMemory(cDGName6, sizeof(cDGName6)); 
		memcpy (cDGName6, cStr, 10); 
		break;
	case 7:	
		iDGKill7 = iV2;	
		iDGDeath7 = iV3; 
		ZeroMemory(cDGName7, sizeof(cDGName7)); 
		memcpy (cDGName7, cStr, 10); 
		break;
	case 8:	
		iDGKill8 = iV2;	
		iDGDeath8 = iV3; 
		ZeroMemory(cDGName8, sizeof(cDGName8)); 
		memcpy (cDGName8, cStr, 10); 
		break;
	case 9:	
		iDGKill9 = iV2;	
		iDGDeath9 = iV3; 
		ZeroMemory(cDGName9, sizeof(cDGName9)); 
		memcpy (cDGName9, cStr, 10); 
		break;
	case 10: 
		iDGKill10 = iV2; 
		iDGDeath10 = iV3; 
		ZeroMemory(cDGName10, sizeof(cDGName10)); 
		memcpy (cDGName10, cStr, 10); 
		break;
	default: break;
	}
}

void CGame::NotifyMsg_Top15(char *pData) // MORLA 2.10 - Top 15 en deathmach
{
 char * cp, cStr[256];
 int  * ip, iV1, iV2, iV3;

	cp = (char *)(pData + DEF_INDEX2_MSGTYPE + 2);

	ip = (int *)cp;
	iV1 = *ip;
	cp += 4;

	ip = (int *)cp;
	iV2 = *ip;
	cp += 4;

	ip = (int *)cp;
	iV3 = *ip;
	cp += 4;
	
	strcpy(cStr, cp);
	switch (iV1)
	{
	case 1:	iDGTOPk[1] = iV2; iDGTOPd[1] = iV3;	ZeroMemory(iDGTOPn[1], sizeof(iDGTOPn[1])); memcpy (iDGTOPn[1], cStr, 10); break;
	case 2:	iDGTOPk[2] = iV2; iDGTOPd[2] = iV3;	ZeroMemory(iDGTOPn[2], sizeof(iDGTOPn[2])); memcpy (iDGTOPn[2], cStr, 10); break;
	case 3:	iDGTOPk[3] = iV2; iDGTOPd[3] = iV3;	ZeroMemory(iDGTOPn[3], sizeof(iDGTOPn[3])); memcpy (iDGTOPn[3], cStr, 10); break;
	case 4:	iDGTOPk[4] = iV2; iDGTOPd[4] = iV3;	ZeroMemory(iDGTOPn[4], sizeof(iDGTOPn[4])); memcpy (iDGTOPn[4], cStr, 10); break;
	case 5:	iDGTOPk[5] = iV2; iDGTOPd[5] = iV3;	ZeroMemory(iDGTOPn[5], sizeof(iDGTOPn[5])); memcpy (iDGTOPn[5], cStr, 10); break;
	case 6:	iDGTOPk[6] = iV2; iDGTOPd[6] = iV3;	ZeroMemory(iDGTOPn[6], sizeof(iDGTOPn[6])); memcpy (iDGTOPn[6], cStr, 10); break;
	case 7:	iDGTOPk[7] = iV2; iDGTOPd[7] = iV3;	ZeroMemory(iDGTOPn[7], sizeof(iDGTOPn[7])); memcpy (iDGTOPn[7], cStr, 10); break;
	case 8:	iDGTOPk[8] = iV2; iDGTOPd[8] = iV3;	ZeroMemory(iDGTOPn[8], sizeof(iDGTOPn[8])); memcpy (iDGTOPn[8], cStr, 10); break;
	case 9:	iDGTOPk[9] = iV2; iDGTOPd[9] = iV3;	ZeroMemory(iDGTOPn[9], sizeof(iDGTOPn[9])); memcpy (iDGTOPn[9], cStr, 10); break;
	case 10:	iDGTOPk[10] = iV2; iDGTOPd[10] = iV3;	ZeroMemory(iDGTOPn[10], sizeof(iDGTOPn[10])); memcpy (iDGTOPn[10], cStr, 10); break;
	default: break;
	}
}
