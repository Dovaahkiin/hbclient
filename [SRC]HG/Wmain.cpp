// -------------------------------------------------------------- 
//                      New Game Server  						  
//
//                      1998.11 by Soph
//
// --------------------------------------------------------------







// --------------------------------------------------------------


#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <stdlib.h>
#include <winbase.h>
#include <mmsystem.h>
#include <time.h>				   
#include "winmain.h"
#include "Game.h"
#include "UserMessages.h"
#include "resource.h"
#include <shellapi.h>
#include <shlobj.h>



// --------------------------------------------------------------

#define WM_USER_TIMERSIGNAL		WM_USER + 500
#pragma warning(disable : 4996)

char			szAppClass[32];
HWND			G_hWnd = NULL;
char			G_cMsgList[120*50];
BOOL            G_cMsgUpdated =	FALSE;
char            G_cTxt[512];
char			G_cData50000[50000];
MMRESULT        G_mmTimer = NULL;

// v2.14 로그 부하 감소용 버퍼및 카운터 그리고 시간 플래그 
char			G_cLogBuffer[30000] ;
short			G_sLogCounter ;
DWORD			G_dwLogTime ; 


class XSocket * G_pListenSock = NULL;
class XSocket * G_pLogSock    = NULL;
class CGame *   G_pGame       = NULL;

int             G_iQuitProgramCount = 0;
BOOL			G_bIsThread = TRUE;
BOOL            G_bShutdown = FALSE ; 

FILE * pLogFile;
char			G_cCrashTxt[50000];
// --------------------------------------------------------------

void ThreadProc(void *ch)
{
	while (G_bIsThread == TRUE) {
		if (G_pGame = NULL)	G_pGame->OnTimer(NULL);
		Sleep(100);
	}

	ExitThread(0);
}

LRESULT CALLBACK WndProc( HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam )
{ 
	switch (message) {
	case WM_CREATE:
		break;
	
	case WM_KEYDOWN:
		G_pGame->OnKeyDown(wParam, lParam);
		return (DefWindowProc(hWnd, message, wParam, lParam));
		break;

	case WM_KEYUP:
		G_pGame->OnKeyUp(wParam, lParam);
		return (DefWindowProc(hWnd, message, wParam, lParam));
		break;
	
	case WM_USER_STARTGAMESIGNAL:
		G_pGame->OnStartGameSignal();
		break;
	
	case WM_USER_TIMERSIGNAL:
	    if(G_bShutdown == FALSE) G_pGame->OnTimer(NULL);
		break;

	case WM_USER_ACCEPT:
		OnAccept();
		break;

	//case WM_KEYUP:
	//	OnKeyUp(wParam, lParam);
	//	break;

	case WM_PAINT:
		OnPaint();
		break;

	case WM_DESTROY:
		G_bShutdown = TRUE ;
		OnDestroy();
		break;

	case WM_CLOSE:
		if (G_pGame->bOnClose() == TRUE) return (DefWindowProc(hWnd, message, wParam, lParam));
		//G_iQuitProgramCount++;
		//if (G_iQuitProgramCount >= 2) {
		//	return (DefWindowProc(hWnd, message, wParam, lParam));
		//}
		break;

	case WM_ONGATESOCKETEVENT:
		if ( G_bShutdown == TRUE) break;
		if(G_pGame->m_bOnExitProcess != TRUE ) G_pGame->OnGateSocketEvent(message, wParam, lParam);
		break;

	case WM_ONLOGSOCKETEVENT:
		if ( G_bShutdown == TRUE) break;
		G_pGame->OnMainLogSocketEvent(message, wParam, lParam);
		break;
#ifdef DEF_RADMIN
	case WM_ONRADMINSOCKETEVENT:
		if ( G_bShutdown == TRUE) break;
		G_pGame->OnRAdminSocketEvent(message, wParam, lParam);
		break;
#endif
	default: 
		if ( G_bShutdown == TRUE) break;
		if ((message >= WM_ONLOGSOCKETEVENT + 1) && (message <= WM_ONLOGSOCKETEVENT + DEF_MAXSUBLOGSOCK))
			G_pGame->OnSubLogSocketEvent(message, wParam, lParam);
		
		if ((message >= WM_ONCLIENTSOCKETEVENT) && (message < WM_ONCLIENTSOCKETEVENT + DEF_MAXCLIENTS)) 
			G_pGame->OnClientSocketEvent(message, wParam, lParam);

		return (DefWindowProc(hWnd, message, wParam, lParam));
	}
	
	return NULL;
}


BOOL CALLBACK lpCrashDialogFunc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam){
HANDLE outHand;
char cCrashFileName[MAX_PATH];
char cLF[]={0x0d,0x0a};
char cDash ='-';
SYSTEMTIME sysTime;
DWORD written;

	switch(uMsg) {
	case WM_CLOSE:
		EndDialog(hDlg, TRUE);
		break;

	case WM_COMMAND:
		switch(LOWORD(wParam)) {
		case IDC_CLOSE:
			EndDialog(hDlg, TRUE);
			break;
		}
		break;

	case WM_INITDIALOG:
		//Show Crash Data
		SetWindowText(GetDlgItem(hDlg, IDC_EDIT1), G_cCrashTxt);
		GetLocalTime(&sysTime);
		wsprintf(cCrashFileName,"CrashData - %d-%d-%d.txt", sysTime.wDay, sysTime.wMonth, sysTime.wYear);
		SetWindowText(GetDlgItem(hDlg, IDC_EDITPATH), cCrashFileName);
		//Open File For Writing
		outHand = CreateFile(cCrashFileName,GENERIC_READ+GENERIC_WRITE,FILE_SHARE_READ+FILE_SHARE_WRITE,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
		SetFilePointer(outHand, 0, 0, FILE_END);
		WriteFile(outHand, G_cCrashTxt, strlen(G_cCrashTxt), &written, NULL);
		for (int i = 0; i < 80; i++)
			WriteFile(outHand, &cDash, 1, &written, NULL);
		WriteFile(outHand, cLF, 2, &written, NULL);
		WriteFile(outHand, cLF, 2, &written, NULL);
		CloseHandle(outHand);
		break;

	}
	return 0;
}
LONG lpTopLevelExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo){

	//Shutdown everything
	G_bIsThread = FALSE;
	_StopTimer(G_mmTimer);

	try{
		delete G_pGame;
		G_pGame = NULL;
	}
	catch (...) {
	}
  /* BOOL bMiniDumpSuccessful;
    WCHAR* szAppName = L"AppName";
    WCHAR* szVersion = L"v1.0";
    HANDLE hDumpFile;
    MINIDUMP_EXCEPTION_INFORMATION ExpParam;

    CreateDirectory((LPSTR)"CrashDump", NULL );

    hDumpFile = CreateFile((LPSTR)"CrashDump\\HGserver.dmp", GENERIC_READ|GENERIC_WRITE, 
                FILE_SHARE_WRITE|FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);

    ExpParam.ThreadId = GetCurrentThreadId();
    ExpParam.ExceptionPointers = pExceptionPointers;
    ExpParam.ClientPointers = TRUE;

    bMiniDumpSuccessful = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), 
                    hDumpFile, MiniDumpWithDataSegs, &ExpParam, NULL, NULL);

   // return EXCEPTION_EXECUTE_HANDLER;

*/
	ZeroMemory(G_cCrashTxt, sizeof(G_cCrashTxt));

	//Format a nice output

	//Reason for crash
	strcpy(G_cCrashTxt, "HGServer Exception Information\r\n");
	strcat(G_cCrashTxt, "Code : ");
	wsprintf(&G_cCrashTxt[strlen(G_cCrashTxt)], "0x%.8X\r\n", ExceptionInfo->ExceptionRecord->ExceptionCode);
	strcat(G_cCrashTxt, "Flags : ");
	wsprintf(&G_cCrashTxt[strlen(G_cCrashTxt)], "0x%.8X\r\n", ExceptionInfo->ExceptionRecord->ExceptionFlags);
	strcat(G_cCrashTxt, "Address : ");
	wsprintf(&G_cCrashTxt[strlen(G_cCrashTxt)], "0x%.8X\r\n", ExceptionInfo->ExceptionRecord->ExceptionAddress);
	strcat(G_cCrashTxt, "Parameters : ");
	wsprintf(&G_cCrashTxt[strlen(G_cCrashTxt)], "0x%.8X\r\n\r\n", ExceptionInfo->ExceptionRecord->NumberParameters);

	//Retrieve OS version
	//GetOSName();
	//strcat(G_cCrashTxt, "\r\n");

	//Crash Details
	strcat(G_cCrashTxt, "Context :\r\n");
	wsprintf(&G_cCrashTxt[strlen(G_cCrashTxt)], "EDI: 0x%.8X\t\tESI: 0x%.8X\t\tEAX: 0x%.8X\r\n",ExceptionInfo->ContextRecord->Edi,
																						ExceptionInfo->ContextRecord->Esi,
																						ExceptionInfo->ContextRecord->Eax);
	wsprintf(&G_cCrashTxt[strlen(G_cCrashTxt)], "EBX: 0x%.8X\t\tECX: 0x%.8X\t\tEDX: 0x%.8X\r\n",ExceptionInfo->ContextRecord->Ebx,
																						ExceptionInfo->ContextRecord->Ecx,
																						ExceptionInfo->ContextRecord->Edx);
	wsprintf(&G_cCrashTxt[strlen(G_cCrashTxt)], "EIP: 0x%.8X\t\tEBP: 0x%.8X\t\tSegCs: 0x%.8X\r\n",ExceptionInfo->ContextRecord->Eip,
																						ExceptionInfo->ContextRecord->Ebp,
																						ExceptionInfo->ContextRecord->SegCs);
	wsprintf(&G_cCrashTxt[strlen(G_cCrashTxt)], "EFlags: 0x%.8X\tESP: 0x%.8X\t\tSegSs: 0x%.8X\r\n",ExceptionInfo->ContextRecord->EFlags,
																						ExceptionInfo->ContextRecord->Esp,
																						ExceptionInfo->ContextRecord->SegSs);
	// Show Dialog
	DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG2), NULL, (DLGPROC)lpCrashDialogFunc);
	return EXCEPTION_EXECUTE_HANDLER;
}


int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
               LPSTR lpCmdLine, int nCmdShow )
{	
	SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)lpTopLevelExceptionFilter);
	sprintf( szAppClass, "GameServer%d", hInstance);
	if (!InitApplication( hInstance))		return (FALSE);
    if (!InitInstance(hInstance, nCmdShow)) return (FALSE);
	
	Initialize();
	EventLoop();
    return 0;
}
  


BOOL InitApplication( HINSTANCE hInstance)
{     
 WNDCLASS  wc;

	wc.style = (CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS);
	wc.lpfnWndProc   = (WNDPROC)WndProc;             
	wc.cbClsExtra    = 0;                            
	wc.cbWndExtra    = sizeof (int);             
	wc.hInstance     = hInstance;                    
	wc.hIcon         = NULL;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);  
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);	 
	wc.lpszMenuName  = NULL;                    		 
	wc.lpszClassName = szAppClass;                   
        
	return (RegisterClass(&wc));
}


BOOL InitInstance( HINSTANCE hInstance, int nCmdShow )
{
 char cTitle[100];
 SYSTEMTIME SysTime;
	// 서버 부팅시간 기록 
	
	//hFile = hFile = CreateFile("HGserver.exe", GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, NULL);
	//if (hFile == INVALID_HANDLE_VALUE) return FALSE;
	//GetFileTime(hFile, &ftCT, &ftLAT, &ftLWT);
	//CloseHandle(hFile);

	GetLocalTime(&SysTime);
	wsprintf(cTitle, "Helbreath Return v1.0 (Executed at: %d %d %d)", DEF_UPPERVERSION, DEF_LOWERVERSION, DEF_BUILDDATE, SysTime.wMonth, SysTime.wDay, SysTime.wHour);
	
	G_hWnd = CreateWindowEx(0,  // WS_EX_TOPMOST,
        szAppClass,
        cTitle,
        WS_VISIBLE | // so we don't have to call ShowWindow
        WS_POPUP |   // non-app window
        WS_CAPTION | // so our menu doesn't look ultra-goofy
        WS_SYSMENU |  // so we get an icon in the tray
        WS_MINIMIZEBOX, 
		CW_USEDEFAULT,
        CW_USEDEFAULT,
        800, //GetSystemMetrics(SM_CXSCREEN),
        600, //GetSystemMetrics(SM_CYSCREEN),
        NULL,
        NULL,
        hInstance,
        NULL );

    if (!G_hWnd) return (FALSE);
        WNDCLASS Wc;
	Wc.style         =  CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	Wc.lpfnWndProc   =  WndProc;
	Wc.cbClsExtra    =  0;
	Wc.cbWndExtra    =  0;
	Wc.hInstance     =  hInstance;
	Wc.hIcon         =  LoadIcon(NULL,IDI_WINLOGO);
	Wc.hCursor       =  LoadCursor(NULL,IDC_ARROW);
	Wc.hbrBackground =  (HBRUSH)(COLOR_BTNFACE+1);
	RegisterClass(&Wc);

	ShowWindow(G_hWnd, nCmdShow);    
	UpdateWindow(G_hWnd);            

	return (TRUE);                 
}



int EventLoop()
{
 static unsigned short _usCnt = 0; 
 register MSG msg;

	while( 1 ) {
		if( PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ) ) {
			if( !GetMessage( &msg, NULL, 0, 0 ) ) {
				return msg.wParam;
			}
            TranslateMessage(&msg);
            DispatchMessage(&msg);
			UpdateScreen();
		}
		else WaitMessage();
	}
}



void Initialize()
{
 char cTitle[100];
	if (_InitWinsock() == FALSE) {
		MessageBox(G_hWnd, "Socket 1.1 not found! Cannot execute program.","ERROR", MB_ICONEXCLAMATION | MB_OK);
		PostQuitMessage(0);
		return;
	}

	G_pGame = new class CGame(G_hWnd);
	if (G_pGame->bInit() == FALSE) {
		PutLogList("(!!!) STOPPED!");
		return;
	}
	wsprintf(cTitle, "Helbreath Return https://helbreathreturn.github.io/hbReturn/", DEF_UPPERVERSION, DEF_LOWERVERSION, DEF_BUILDDATE, G_pGame->m_cServerName);
    SetWindowText(G_hWnd, cTitle); 
	// 게임 진행용 타이머 
	G_mmTimer = _StartTimer(300);

	G_pListenSock = new class XSocket(G_hWnd, DEF_SERVERSOCKETBLOCKLIMIT);
	G_pListenSock->bListen(G_pGame->m_cGameServerAddr, G_pGame->m_iGameServerPort, WM_USER_ACCEPT);

	pLogFile = NULL;
	//  v2.14 성후니 변경 대만 로그 부하 줄이기 위해 
	G_sLogCounter = 0 ;
	ZeroMemory(G_cLogBuffer, sizeof(G_cLogBuffer));
}



void OnDestroy()
{
	if (G_pListenSock != NULL) delete G_pListenSock;
	if (G_pLogSock != NULL) delete G_pLogSock;

	if (G_pGame != NULL) {
		G_pGame->Quit();
		delete G_pGame;
	}

	if (G_mmTimer != NULL) _StopTimer(G_mmTimer);
	_TermWinsock();

	if (pLogFile != NULL) fclose(pLogFile);

	PostQuitMessage(0);
}
void PutLogFileList(char * cStr)
{
 FILE * pFile;
 char cBuffer[512];

 SYSTEMTIME SysTime;	
	pFile = fopen("Events.log", "at");
	if (pFile == NULL) return;

	ZeroMemory(cBuffer, sizeof(cBuffer));
	
	GetLocalTime(&SysTime);
	wsprintf(cBuffer, "(%4d:%2d:%2d:%2d:%2d) - ", SysTime.wYear, SysTime.wMonth, SysTime.wDay, SysTime.wHour, SysTime.wMinute);
	strcat(cBuffer, cStr);
	strcat(cBuffer, "\n");

	fwrite(cBuffer, 1, strlen(cBuffer), pFile);
	fclose(pFile);
}


void PutLogList(char * cMsg)
{
 char cTemp[120*50];
	
	G_cMsgUpdated = TRUE;
	ZeroMemory(cTemp, sizeof(cTemp));
	memcpy((cTemp + 120), G_cMsgList, 120*49);
	memcpy(cTemp, cMsg, strlen(cMsg));
	memcpy(G_cMsgList, cTemp, 120*50);
}

void UpdateScreen()
{
	if (G_cMsgUpdated == TRUE) {
		InvalidateRect(G_hWnd, NULL, TRUE);
		G_cMsgUpdated = FALSE;
	}
}


void OnPaint()
{
 HDC hdc;
 PAINTSTRUCT ps;
 register short i;
 char * cMsg;

	hdc = BeginPaint(G_hWnd, &ps);
	
	SetBkMode(hdc,TRANSPARENT);

	// 이벤트 리스트를 출력한다.
	for (i = 0; i < 20; i++) {
		cMsg = (char *)(G_cMsgList + i*120);
		TextOut(hdc, 5, 5 + 350 - i*16, cMsg, strlen(cMsg));
	}
	
	if (G_pGame	!= NULL)
		G_pGame->DisplayInfo(hdc);

	EndPaint(G_hWnd, &ps);
}



void  OnKeyUp(WPARAM wParam, LPARAM lParam)
{
}


void OnAccept()
{
	G_pGame->bAccept(G_pListenSock);
}


void CALLBACK _TimerFunc(UINT wID, UINT wUser, DWORD dwUSer, DWORD dw1, DWORD dw2)
{
	PostMessage(G_hWnd, WM_USER_TIMERSIGNAL, wID, NULL);
}



MMRESULT _StartTimer(DWORD dwTime)
{
 TIMECAPS caps;
 MMRESULT timerid;

	timeGetDevCaps(&caps, sizeof(caps));
	timeBeginPeriod(caps.wPeriodMin);
	timerid = timeSetEvent(dwTime,0,_TimerFunc,0, (UINT)TIME_PERIODIC);

	return timerid;
}



void _StopTimer(MMRESULT timerid)
{
 TIMECAPS caps;

	if (timerid != 0) {
		timeKillEvent(timerid);
		timerid = 0;
		timeGetDevCaps(&caps, sizeof(caps));
		timeEndPeriod(caps.wPeriodMin);
	}
}





void PutAdminLogFileList(char * cStr, BOOL bIsSave)
{
 // v2.14 성후니 변경 대만 로그 부하를 줄이기 위해 
 char cTempBuffer[512];
 SYSTEMTIME SysTime;
 DWORD dwTime;

   	dwTime = timeGetTime();

	if (G_sLogCounter == 0 ) G_dwLogTime = dwTime ; 

	G_sLogCounter++ ;

	GetLocalTime(&SysTime);
	
	ZeroMemory(cTempBuffer, sizeof(cTempBuffer)) ;
	wsprintf(cTempBuffer, "%02d:%02d:%02d\t", SysTime.wHour, SysTime.wMinute, SysTime.wSecond );
	strcat(cTempBuffer, cStr);
	strcat(cTempBuffer, "\n");

	strcat(G_cLogBuffer, cTempBuffer) ;

	// 로그 버퍼에 100개의 로그가 쌓여 있던지 
	// 혹은 로그를 쓴지 10초가 지난경우 그리고 마지막 셧다운시는 무조건 저장한다.
	if ( G_sLogCounter >= 100 || (dwTime - G_dwLogTime  >  10*1000)  || bIsSave == TRUE) {
		ZeroMemory(cTempBuffer, sizeof(cTempBuffer)) ;
		_mkdir("AdminLogData");

		wsprintf(cTempBuffer,"AdminLogData\\AdminLog%04d%02d%02d.log",SysTime.wYear,SysTime.wMonth,SysTime.wDay) ;

		pLogFile = fopen(cTempBuffer, "at");

		if (pLogFile == NULL) return;
	
		fwrite(G_cLogBuffer, 1, strlen(G_cLogBuffer), pLogFile);
		fclose(pLogFile);
		G_sLogCounter = 0 ;
		ZeroMemory(G_cLogBuffer, sizeof(G_cLogBuffer));	
	}

}

void PutCrusadeLogFileList(char * cStr, BOOL bIsSave)
{
 // v2.14 성후니 변경 대만 로그 부하를 줄이기 위해 
 char cTempBuffer[512];
 SYSTEMTIME SysTime;
 DWORD dwTime;

   	dwTime = timeGetTime();

	if (G_sLogCounter == 0 ) G_dwLogTime = dwTime ; 

	G_sLogCounter++ ;

	GetLocalTime(&SysTime);
	
	ZeroMemory(cTempBuffer, sizeof(cTempBuffer)) ;
	wsprintf(cTempBuffer, "%02d:%02d:%02d\t", SysTime.wHour, SysTime.wMinute, SysTime.wSecond );
	strcat(cTempBuffer, cStr);
	strcat(cTempBuffer, "\n");

	strcat(G_cLogBuffer, cTempBuffer) ;

	// 로그 버퍼에 100개의 로그가 쌓여 있던지 
	// 혹은 로그를 쓴지 10초가 지난경우 그리고 마지막 셧다운시는 무조건 저장한다.
	if ( G_sLogCounter >= 100 || (dwTime - G_dwLogTime  >  10*1000)  || bIsSave == TRUE) {
		ZeroMemory(cTempBuffer, sizeof(cTempBuffer)) ;
		_mkdir("CrusadeLog");

		wsprintf(cTempBuffer,"CrusadeLog\\CrusadeLog%04d%02d%02d.log",SysTime.wYear,SysTime.wMonth,SysTime.wDay) ;

		pLogFile = fopen(cTempBuffer, "at");

		if (pLogFile == NULL) return;
	
		fwrite(G_cLogBuffer, 1, strlen(G_cLogBuffer), pLogFile);
		fclose(pLogFile);
		G_sLogCounter = 0 ;
		ZeroMemory(G_cLogBuffer, sizeof(G_cLogBuffer));	
	}

}
void PutEkAndPkLogFileList(char * cStr)
{
 FILE * pFile;
 char cBuffer[512];
 SYSTEMTIME SysTime;
	
	pFile = fopen("..\\PvpLog\\EkAndPk.log", "at");
	if (pFile == NULL) return;

	ZeroMemory(cBuffer, sizeof(cBuffer));
	
	GetLocalTime(&SysTime);
	wsprintf(cBuffer, "(%4d:%2d:%2d:%2d:%2d) - ", SysTime.wYear, SysTime.wMonth, SysTime.wDay, SysTime.wHour, SysTime.wMinute);
	strcat(cBuffer, cStr);
	strcat(cBuffer, "\n");

	fwrite(cBuffer, 1, strlen(cBuffer), pFile);
	fclose(pFile);
}

void PutFenixLogList(char * cStr)
{
 FILE * pFile;
 char cBuffer[512];
 SYSTEMTIME SysTime;
	
	pFile = fopen("FenixVip.log", "at");
	if (pFile == NULL) return;

	ZeroMemory(cBuffer, sizeof(cBuffer));
	
	GetLocalTime(&SysTime);
	wsprintf(cBuffer, "(%4d:%2d:%2d:%2d:%2d) - ", SysTime.wYear, SysTime.wMonth, SysTime.wDay, SysTime.wHour, SysTime.wMinute);
	strcat(cBuffer, cStr);
	strcat(cBuffer, "\n");

	fwrite(cBuffer, 1, strlen(cBuffer), pFile);
	fclose(pFile);
}

void PutItemLogFileList(char * cStr, BOOL bIsSave)
{
 char cTempBuffer[512];
 SYSTEMTIME SysTime;
 DWORD dwTime;

   	dwTime = timeGetTime();

	if (G_sLogCounter == 0 ) G_dwLogTime = dwTime ; 

	G_sLogCounter++ ;

	GetLocalTime(&SysTime);
	
	ZeroMemory(cTempBuffer, sizeof(cTempBuffer)) ;
	wsprintf(cTempBuffer, "%02d:%02d:%02d\t", SysTime.wHour, SysTime.wMinute, SysTime.wSecond );
	strcat(cTempBuffer, cStr);
	strcat(cTempBuffer, "\n");

	strcat(G_cLogBuffer, cTempBuffer) ;

	if ( G_sLogCounter >= 100 || (dwTime - G_dwLogTime  >  10*1000)  || bIsSave == TRUE) {
		ZeroMemory(cTempBuffer, sizeof(cTempBuffer)) ;
		_mkdir("LogData");

		wsprintf(cTempBuffer,"LogData\\ItemEvents%04d%02d%02d.log",SysTime.wYear,SysTime.wMonth,SysTime.wDay) ;

		pLogFile = fopen(cTempBuffer, "at");

		if (pLogFile == NULL) return;
	
		fwrite(G_cLogBuffer, 1, strlen(G_cLogBuffer), pLogFile);
		fclose(pLogFile);
		G_sLogCounter = 0 ;
		ZeroMemory(G_cLogBuffer, sizeof(G_cLogBuffer));	
	}

}

void PutLogEventFileList(char * cStr)
{
 FILE * pFile;
 char cBuffer[512];
 SYSTEMTIME SysTime;
	
	pFile = fopen("LogEvents.log", "at");
	if (pFile == NULL) return;

	ZeroMemory(cBuffer, sizeof(cBuffer));
	
	GetLocalTime(&SysTime);
	wsprintf(cBuffer, "(%4d:%2d:%2d:%2d:%2d) - ", SysTime.wYear, SysTime.wMonth, SysTime.wDay, SysTime.wHour, SysTime.wMinute);
	strcat(cBuffer, cStr);
	strcat(cBuffer, "\n");

	fwrite(cBuffer, 1, strlen(cBuffer), pFile);
	fclose(pFile);
}

void PutDebugMsg(char * cStr)
{
 FILE * pFile;
 char cBuffer[512];
 SYSTEMTIME SysTime;
	
	pFile = fopen("DebugMsg.log", "at");
	if (pFile == NULL) return;

	ZeroMemory(cBuffer, sizeof(cBuffer));
	
	GetLocalTime(&SysTime);
	wsprintf(cBuffer, "(%4d:%2d:%2d:%2d:%2d) - ", SysTime.wYear, SysTime.wMonth, SysTime.wDay, SysTime.wHour, SysTime.wMinute);
	strcat(cBuffer, cStr);
	strcat(cBuffer, "\n");

	fwrite(cBuffer, 1, strlen(cBuffer), pFile);
	fclose(pFile);
}

void PutHackLog(char * cStr)
{
 FILE * pFile;
 char cBuffer[512];
 SYSTEMTIME SysTime;
	
	pFile = fopen("HackLog.log", "at");
	if (pFile == NULL) return;

	ZeroMemory(cBuffer, sizeof(cBuffer));
	
	GetLocalTime(&SysTime);
	wsprintf(cBuffer, "(%4d:%2d:%2d:%2d:%2d) - ", SysTime.wYear, SysTime.wMonth, SysTime.wDay, SysTime.wHour, SysTime.wMinute);
	strcat(cBuffer, cStr);
	strcat(cBuffer, "\n");

	fwrite(cBuffer, 1, strlen(cBuffer), pFile);
	fclose(pFile);
}



