#include "iPosLogReused.h"
#include <stdexcept>
#include <cstdio> // vsprintf...
#include <windows.h> // WaitForSingleObject...

// Re-used code from iPosLog.dll
namespace iPosLog {

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	cb
	--

	Our callback function. This function is called when real DLL wants to
	notify SACI about a new message. This callback function assumes that
	the real DLL does N-O-T use calling convention __stdcall when calling
	callback function in iPosLog.


	Parameters:
	-----------

	wParam         Parameter 1.

	lParam         Parameter 2.


	Return value:
	-------------

	Return code from SACI or OS, depending on method used by SACI.

	*/
	int               cb                      /* Our callback function         */
	(
		unsigned int terminalid,
		unsigned int msglen
	)
	{
#undef   FUNCTION
#define  FUNCTION "cb"

		int            iRet=0;                   /* Return code from function     */

		//BOOL           fcc;                    /* Return code from API          */


		//LOG_ENTRY;
		//writeLog(LL_TRACE, "%s/%s: Entry", MODULE, FUNCTION);


		///*
		//Initialize socket interface if this has not been done previously.
		//-----------------------------------------------------------------
		//*/
		//if (gs_pgi->fSocketInitialized == FALSE)
		//	/* Has socket interface been     */
		//	/* initialized previously ?      */
		//{
		//	writeLog(LL_TRACE, "%s/%s: Calling <%s>", MODULE, FUNCTION, "initSocketInterface");
		//	fcc = initSocketInterface();        /* Initialize socket             */
		//										/* interface !!!                 */
		//	if (fcc == TRUE)                    /* OK ?                          */
		//	{
		//		gs_pgi->fSocketInitialized = TRUE;
		//		/* Indicate that socket          */
		//		/* interface has been            */
		//		/* initialized !!!               */
		//		writeLog(LL_DEBUG, "%s/%s: <%s> successful", MODULE, FUNCTION, "initSocketInterface");
		//	}
		//	else
		//	{
		//		writeLog(LL_WARNING, "%s/%s: <%s> failed", MODULE, FUNCTION, "initSocketInterface");
		//	}
		//}


		if (gs_pgi->pcb != 0)                  /* Does SACI use a callback      */
											   /* function ?                    */
		{
			//writeTempLog("%s (%.9lu) %s/%s: Calling <%s>", collectTimestamp(), gs_pgi->uiLineNumber, MODULE, FUNCTION, "gs_pgi->pcb");
			iRet = gs_pgi->pcb(terminalid,msglen);  /* Call it !!!                   */
			//writeTempLog("%s (%.9lu) %s/%s: Back from <%s>", collectTimestamp(), gs_pgi->uiLineNumber, MODULE, FUNCTION, "gs_pgi->pcb");
		}
		else
		{
			//writeTempLog("%s (%.9lu) %s/%s: Calling <%s>", collectTimestamp(), gs_pgi->uiLineNumber, MODULE, FUNCTION, "PostMessage");
			iRet = (int)PostMessage(gs_pgi->hwnd, gs_pgi->uiMsg, terminalid, msglen);
			/* Post message to SACI          */
			//writeTempLog("%s (%.9lu) %s/%s: Back from <%s>", collectTimestamp(), gs_pgi->uiLineNumber, MODULE, FUNCTION, "PostMessage");
		}

		/*
		Handle message.
		---------------
		*/
		gs_pgi->uiLineNumber++;                /* Adjust line number            */
		handleMsg                              /* Handle message                */
		(
			LL_ALWAYS,                          /* Log level                     */
			FMT_CB,                             /* Format string                 */
			collectTimestamp(),                 /* Time stamp                    */
			gs_pgi->uiLineNumber,               /* Line number                   */
			FUNCTION,                           /* Function                      */
			iRet,                               /* Return value                  */
			terminalid,                             /* Access ID                     */
			msglen                              /* Length of msg                 */
		);


		//LOG_EXIT;
		//writeLog(LL_TRACE, "%s/%s: Exit", MODULE, FUNCTION);

		return   iRet;                         /* And return                    */
	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	hex2Ascii
	---------

	Convert a hex buffer to hex-ASCII, ie two ASCII characters for each hex
	byte. The resulting hex-ASCII string is placed in global info.


	Parameters:
	-----------

	pvHex          Start hex data.

	iLen           Number of bytes with hex data.


	Return value:
	-------------

	Resulting hex-ASCII string.

	*/
	char*             hex2Ascii               /* Convert hex to ASCII          */
	(
		void*          pvHex,                  /* Hex data                      */
		int            iLen                    /* Number of bytes with hex data */
	)
	{
#undef   FUNCTION
#define  FUNCTION "hex2Ascii"

		char*          pszTemp = gs_pgi->szHexAsciiBuf;
		/* Moving ptr                    */
		int            iCnt;                   /* Loop counter                  */
		unsigned char* pucTemp = (unsigned char*)pvHex;
		/* Temporary ptr                 */
		unsigned char  uc;                     /* Extracted characters          */


		memset(gs_pgi->szHexAsciiBuf, 0, sizeof(gs_pgi->szHexAsciiBuf));
		/* Clear resulting buffer        */


		/*
		Traverse hex buffer.
		--------------------
		*/
		for (iCnt = 0; iCnt < iLen; iCnt++)
		{
			uc = pucTemp[iCnt];                 /* Extract one byte              */
			sprintf(pszTemp, "%.2X", uc);         /* Convert to hex-ASCII          */
			pszTemp += strlen(pszTemp);         /* Advance temp ptr              */
		}

		return   gs_pgi->szHexAsciiBuf;        /* And return                    */
	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	collectTimestamp
	----------------

	Collect time stamp. The collected time stamp is saved in global info.


	Parameters:
	-----------

	-


	Return value:
	-------------

	Resulting time stamp.

	*/
	char*             collectTimestamp        /* Collect time stamp            */
	(
		void
	)
	{
#undef   FUNCTION
#define  FUNCTION "collectTimestamp"

		SYSTEMTIME     st;                     /* System time                   */


		memset(gs_pgi->szTimestamp, 0, sizeof(gs_pgi->szTimestamp));
		/* Clear area                    */
		GetLocalTime(&st);                     /* Extract local time            */
		sprintf                                /* Assemble time                 */
		(
			gs_pgi->szTimestamp,                /* Receiver                      */
			"%.4u%.2u%.2u%.2u%.2u%.2u%.3u",     /* Format string                 */
			st.wYear,                           /* Year                          */
			st.wMonth,                          /* Month                         */
			st.wDay,                            /* Day of month                  */
			st.wHour,                           /* Hours                         */
			st.wMinute,                         /* Minutes                       */
			st.wSecond,                         /* Seconds                       */
			st.wMilliseconds                    /* Milliseconds                  */
		);

		return   gs_pgi->szTimestamp;          /* And return                    */
	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	stripTrailing
	-------------

	Strip off trailing characters in a buffer.


	Parameters:
	-----------

	pszBuf         Buffer.

	pszStrip       Set of characters to strip off. Any trailing character in
	buffer that is also included in this parameter will be
	removed from the buffer.


	Return:
	-------

	Buffer.

	*/
	char*             stripTrailing(char* pszBuf, char* pszStrip)
		// Strip off trailing character in a buffer
	{
#undef   FUNCTION
#define  FUNCTION "stripTrailing"

		char        cExt;                      // Extracted character


		while (pszBuf[0] != 0)
		{
			cExt = pszBuf[strlen(pszBuf) - 1];  // Last character
			if (strchr(pszStrip, cExt) != 0)     // Character found ?
			{
				pszBuf[strlen(pszBuf) - 1] = 0;  // Strip off trailing character !!!
			}
			else                                // No - done !!!
			{
				break;
			}
		}

		return   pszBuf;
	}

#define  MUTEX_NAME_LOG    "iPosLog_mutex_for_logging"
#define  MUTEX_NAME_IPOS   "iPosLog_mutex_for_iPos_messages"

#define  VER               "Version 1.0"  /* Version of pgm                */
#define  CPR               "Copyright (c) Swedbank card Service AB"
	/* Copyright of pgm              */
#define  DTE               "2016-09-14"   /* Date for current version      */
#define  DLM               "  "           /* Delimiter                     */
#define  WHO_AM_I          "ZeposApi" DLM VER DLM CPR DLM DTE

	GI* gs_pgi = nullptr;                 /* Global info (per instance)    */

	void GI::init(HMODULE _hinstDLL)
	{
		hinstDLL = _hinstDLL;        /* Remember our DLL instance     */
		if (getParameters()) {
			mutexLog = CreateMutex      /* Create mutex                  */
			(
				0,                               /* Inheritance flag              */
				FALSE,                           /* Initial owner                 */
				MUTEX_NAME_LOG                   /* Name of mutex                 */
			);
			szBuf[0] = '\0';
			gs_pgi->pfLog = fopen        /* Open log file                 */
			(
				gs_pgi->szLogFile,               /* Name of log file              */
				"a"                              /* Mode for log file             */
			);
		}
		else {
			throw std::runtime_error("Failed to get parameters.");
		}

	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	writeLog
	--------

	Write to log file. After the message is written to the log, the log file
	is flushed.


	Parameters:
	-----------

	iLogLevel      Log level for this message.

	pszText        Text to be logged.


	...            Any complementary parameters. Format as printf.


	Return value:
	-------------

	-

	*/
	void              writeLog                /* Write to log                  */
	(
		int            iLogLevel,              /* Log level for this msg        */
		char*          pszText,                /* Text to be logged             */
		...                                    /* Any complementary parameters  */
	)
	{
#undef   FUNCTION
#define  FUNCTION "writeLog"

		va_list        vl;                     /* Reference variable parameters */


											   /*
											   Check if this message is to be logged.
											   --------------------------------------
											   */
		if (iLogLevel <= gs_pgi->iLogLevel)    /* Is this message to be logged? */
		{


			/*
			Request mutex for logging.
			--------------------------
			*/
			WaitForSingleObject(gs_pgi->mutexLog, INFINITE);
			/* Request mutex                 */


			/*
			Assemble message.
			-----------------
			*/
			va_start(vl, pszText);               /* Reference variable parameters */
			vsprintf(gs_pgi->szBuf, pszText, vl); /* Assemble message with         */
												  /* variable parameters           */
			va_end(vl);                         /* Terminate reference           */
			strcat(gs_pgi->szBuf, "\r\n");       /* Append CR/LF                  */


												 /*
												 Write to log file.
												 ------------------
												 */
			fwrite                              /* Write to log file             */
			(
				gs_pgi->szBuf,                   /* Message to write              */
				1,                               /* Size of each item             */
				strlen(gs_pgi->szBuf),           /* Number of bytes to write      */
				gs_pgi->pfLog                    /* File                          */
			);


			/*
			Flush log file.
			---------------
			*/
			fflush(gs_pgi->pfLog);              /* Flush log file !!!            */


												/*
												Release mutex for logging.
												--------------------------
												*/
			ReleaseMutex(gs_pgi->mutexLog);     /* Release mutex                 */
		}
	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	handleMsg
	---------

	Handle a message.


	Parameters:
	-----------

	iLogLevel      Log level for this message.

	pszMsg         Message to be handled.


	...            Any complementary parameters. Format as printf.


	Return value:
	-------------

	-

	*/
	void              handleMsg               /* Handle a message              */
	(
		int            iLogLevel,              /* Log level for this msg        */
		char*          pszMsg,                 /* Message to be handled         */
		...                                    /* Any complementary parameters  */
	)
	{
#undef   FUNCTION
#define  FUNCTION "handleMsg"

		va_list        vl;                     /* Reference variable parameters */


											   //LOG_ENTRY;
											   //writeLog(LL_TRACE, "%s/%s: Entry", MODULE, FUNCTION);


											   ///*
											   //Request iPos mutex.
											   //-------------------
											   //*/
											   //WaitForSingleObject(gs_pgi->mutexiPos, INFINITE);
											   ///* Request mutex                 */


											   /*
											   Assemble message.
											   -----------------
											   */
		va_start(vl, pszMsg);                   /* Reference variable parameters */
		vsprintf(gs_pgi->szMsgSnd, pszMsg, vl);  /* Assemble message with         */
												 /* variable parameters           */
		va_end(vl);                            /* Terminate reference           */
		strcat(gs_pgi->szMsgSnd, "\r\n");       /* Append CR/LF                  */

												//writeLog(LL_TRACE, "%s/%s: Handling listeners before filtering", MODULE, FUNCTION);
												//handleBefore();                        /* Handle listeners before       */

												//writeLog(LL_TRACE, "%s/%s: Handling filtering", MODULE, FUNCTION);
												//handleFilter();                        /* Handle filter                 */

		stripTrailing(gs_pgi->szMsgSnd, "\r\n");
		/* Strip trailing CR / LF        */
		if (strlen(gs_pgi->szMsgSnd) != 0)     /* Is there any data left?       */
		{
			//writeLog(LL_TRACE, "%s/%s: Handling listeners after filtering", MODULE, FUNCTION);
			//handleAfter();                      /* Handle listeners after        */
			if (gs_pgi->iLogIposMsg != 0)       /* Log to file?                  */
			{
				//writeLog(LL_TRACE, "%s/%s: Handling logging to file", MODULE, FUNCTION);
				writeLog(iLogLevel, gs_pgi->szMsgSnd);
				/* Log this message !!!          */
			}
		}

		///*
		//Release mutex.
		//--------------
		//*/
		//ReleaseMutex(gs_pgi->mutexiPos);       /* Release mutex                 */


		//LOG_EXIT;
		//writeLog(LL_TRACE, "%s/%s: Exit", MODULE, FUNCTION);
	}

	void              xLog                    /* Extra log function            */
	(
		int            iMandatory,             /* Mandatory logging ?           */
											   /* 1 = YES                       */
											   /* 0 = NO                        */
		char*          pszText,                /* Text to be logged             */
		...                                    /* Any complementary parameters  */
	)
	{
		// Todo: Implement logging if required. For now - No Operation
	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	checkIfService
	--------------

	Check if the current process is running as a service.


	Parameters:
	-----------

	-


	Return value:
	-------------

	Resulting time stamp.

	*/
	/*++

	Routine Description:

	This routine returns if the service specified is running interactively
	(not invoked by the service controller).

	Arguments:

	None

	Return Value:

	BOOL - TRUE if the service is an EXE.


	Note:

	--*/

	BOOL WINAPI       checkIfService          /* Check if process is running   */
											  /* as a service                  */
											  (
												  void
											  )
	{
#undef   FUNCTION
#define  FUNCTION "checkIfService"

		BOOL           fRet = FALSE;           /* Return code from function     */

		BOOL           fcc;                    /* Return code from API          */
		HANDLE         hProcessToken = 0;      /* Handle to token for process   */
		DWORD          dwcc;                   /* Return code from API          */
		DWORD          groupLength = 0;        /* Info about group policies     */
											   //DWORD          groupLength = 50;       /* Info about group policies     */
		DWORD          i;
		//PSID           InteractiveSid = 0;
		PSID           ServiceSid = 0;
		PTOKEN_GROUPS  groupInfo = 0;          /* Memory for group info         */
		SID_IDENTIFIER_AUTHORITY
			siaNt = SECURITY_NT_AUTHORITY;


		xLog(0, "%s/%s: Entry", MODULE, FUNCTION);


		//   /*
		//      Allocate memeory.
		//      -----------------
		//   */
		//xLog("%s/%s: Calling <%s>",MODULE,FUNCTION,"LocalAlloc");
		//   groupInfo = (PTOKEN_GROUPS) LocalAlloc(0,groupLength);
		//                                          /* Allocate memory for group     */
		//                                          /* info                          */
		//   if (groupInfo == 0)                    /* OK?                           */
		//   {
		//xLog("%s/%s: Call to <%s> failed",MODULE,FUNCTION,"LocalAlloc");
		//      goto  l_Synk;
		//   }


		/*
		Start with assumption that process is an EXE, not a Service.
		------------------------------------------------------------
		*/
		//BOOL           fExe = TRUE;


		/*
		Open token for this process.
		----------------------------
		*/
		xLog(0, "%s/%s: Calling <%s>", MODULE, FUNCTION, "OpenProcessToken");
		fcc = OpenProcessToken                 /* Open process token            */
		(
			GetCurrentProcess(),                /* Handle for process            */
			TOKEN_QUERY,                        /* Access requested              */
			&hProcessToken                      /* Receiver process token        */
		);
		if (fcc == FALSE)                      /* OK?                           */
		{
			xLog(0, "%s/%s: Call to <%s> failed, rc = <%i>", MODULE, FUNCTION, "OpenProcessToken", GetLastError());
			goto  l_Synk;
		}
		xLog(0, "%s/%s: Call to <%s> OK, handle = <%i>", MODULE, FUNCTION, "OpenProcessToken", hProcessToken);


		/*
		Extract information about token.
		--------------------------------
		*/
		xLog(0, "%s/%s: Calling <%s>", MODULE, FUNCTION, "GetTokenInformation");
		//fcc = GetTokenInformation(hProcessToken,TokenGroups,groupInfo,groupLength,&groupLength);
		fcc = GetTokenInformation              /* Extract token info            */
		(
			hProcessToken,                      /* Token that info is asked for  */
			TokenGroups,                        /* Type of info requested        */
			0,                                  /* Receiving buffer              */
			groupLength,                        /* Size of buffer                */
			&groupLength                        /* Receiver needed size          */
		);
		if (fcc == FALSE)                      /* OK?                           */
		{
			xLog(0, "%s/%s: Call to <%s> failed", MODULE, FUNCTION, "GetTokenInformation");
			dwcc = GetLastError();              /* Extract error code            */
			if (dwcc != ERROR_INSUFFICIENT_BUFFER)
				/* Needs more memory?            */
			{
				xLog(0, "%s/%s: Unexpected return code <%i> from <%s>", MODULE, FUNCTION, dwcc, "GetTokenInformation");
				goto  l_Synk;                    /* (Other error)                 */
			}

			//xLog("%s/%s: Calling <%s>",MODULE,FUNCTION,"LocalFree");
			//      LocalFree(groupInfo);               /* Release previous allocation   */
			//      groupInfo = 0;                      /* No memory allocated!!!        */
			xLog(0, "%s/%s: Calling <%s>", MODULE, FUNCTION, "LocalAlloc");
			groupInfo = (PTOKEN_GROUPS)LocalAlloc(0, groupLength);
			/* Allocate needed amount of     */
			/* memory                        */
			if (groupInfo == 0)                 /* OK?                           */
			{
				xLog(0, "%s/%s: Call to <%s> failed", MODULE, FUNCTION, "LocalAlloc");
				goto  l_Synk;
			}


			/*
			Try again to extract token info.
			--------------------------------
			*/
			xLog(0, "%s/%s: Calling <%s> again", MODULE, FUNCTION, "GetTokenInformation");
			fcc = GetTokenInformation(hProcessToken, TokenGroups, groupInfo, groupLength, &groupLength);
			/* Extract token info            */
			if (fcc == FALSE)
			{
				xLog(0, "%s/%s: Call to <%s> failed", MODULE, FUNCTION, "GetTokenInformation");
				goto l_Synk;
			}
		}

		//
		//  We now know the groups associated with this token.  We want to look to see if
		//  the interactive group is active in the token, and if so, we know that
		//  this is an interactive process.
		//
		//  We also look for the "service" SID, and if it's present, we know we're a service.
		//
		//  The service SID will be present iff the service is running in a
		//  user account (and was invoked by the service controller).
		//


		//fcc = AllocateAndInitializeSid(&siaNt,1,SECURITY_INTERACTIVE_RID,0,0,0,0,0,0,0,&InteractiveSid);
		//if (fcc == FALSE)                      /* OK?                           */
		//{
		//   goto  l_Synk;
		//}

		xLog(0, "%s/%s: Calling <%s>", MODULE, FUNCTION, "AllocateAndInitializeSid");
		fcc = AllocateAndInitializeSid(&siaNt, 1, SECURITY_SERVICE_RID, 0, 0, 0, 0, 0, 0, 0, &ServiceSid);
		if (fcc == FALSE)                      /* OK?                           */
		{
			xLog(0, "%s/%s: Call to <%s> failed", MODULE, FUNCTION, "AllocateAndInitializeSid");
			goto  l_Synk;
		}


		xLog(0, "%s/%s: Before for loop", MODULE, FUNCTION);
		for (i = 0; i < groupInfo->GroupCount; i += 1)
		{
			SID_AND_ATTRIBUTES
				sanda;
			PSID        Sid;
			xLog(0, "%s/%s: Inside loop, i = <%i>", MODULE, FUNCTION, i);


			sanda = groupInfo->Groups[i];
			Sid = sanda.Sid;


			//
			//  Check to see if the group we're looking at is one of
			//  the 2 groups we're interested in.
			//

			//if (EqualSid(Sid, InteractiveSid))
			//{
			//   //
			//   //  This process has the Interactive SID in its
			//   //  token.  This means that the process is running as
			//   //  an EXE.
			//   //
			//   goto l_Synk;
			//}
			/* else */
			xLog(0, "%s/%s: Calling <%s>", MODULE, FUNCTION, "EqualSid");
			fcc = EqualSid(Sid, ServiceSid);     /* Same SID?                     */
			if (fcc == TRUE)                    /* OK?                           */
			{
				//
				//  This process has the Service SID in its
				//  token.  This means that the process is running as
				//  a service running in a user account.
				//
				//fRet = FALSE;
				xLog(0, "%s/%s: Call to <%s> succeeded, we ARE a service!!!", MODULE, FUNCTION, "EqualSid");
				fRet = TRUE;
				goto  l_Synk;
			}
		}
		xLog(0, "%s/%s: After for loop", MODULE, FUNCTION);

		//
		//  Neither Interactive or Service was present in the current users token,
		//  This implies that the process is running as a service, most likely
		//  running as LocalSystem.
		//
		//fRet = FALSE;


	l_Synk:


		/*
		Clean up.
		---------
		*/
		//if (InteractiveSid != 0)
		//{
		//   FreeSid(InteractiveSid);
		//}

		if (ServiceSid != 0)
		{
			FreeSid(ServiceSid);
		}

		if (groupInfo != 0)
		{
			LocalFree(groupInfo);
		}

		if (hProcessToken != 0)                /* Do we have a process token?   */
		{
			CloseHandle(hProcessToken);         /* Close it!!!                   */
		}

		return   fRet;                         /* And return                    */
	}

#define  DLG_TIMER_ID      1              /* ID for timer in dlg box       */
#define  DLG_TIMEOUT       60             /* Time-out value for dlg box    */

#define  BEEP_FREQ         500            /* Frequency for beeping         */
#define  BEEP_DUR          500            /* Duration for beeping          */

#define IDD_DIALOG1                     101
#define IDC_STATIC_MSG                  1000
#define IDC_STATIC_TIMEOUT              1001

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	dlgProc
	-------

	Dlg procedure.


	Parameters:
	-----------

	hwndDlg        Hwnd for dialog box.

	uMsg           Message.

	wParam         First msg parameter.

	lParam         Second msg parameter.


	Return value:
	-------------

	Message dependent.

	*/
	INT_PTR CALLBACK  dlgProc                 /* Dlg procedure                 */
	(
#undef   FUNCTION
#define  FUNCTION "dlgProc"

		HWND           hwndDlg,                /* Handle to dialog box          */
		UINT           uMsg,                   /* Message                       */
		WPARAM         wParam,                 /* First message parameter       */
		LPARAM         lParam                  /* Second message parameter      */
	)
	{
		switch (uMsg)
		{

		case  WM_INITDIALOG:
			xLog(0, "%s/%s: Message <%s>", MODULE, FUNCTION, "WM_INITDIALOG");
			//sprintf                          /* Assemble msg                  */
			//(
			//   &(gs_pgi->szEvent[strlen(gs_pgi->szEvent)]),
			//   "\r\n\r\n%s. Please make sure that registry key HKEY_LOCAL_MACHINE\\%s is correctly configured",
			//   REG_PROBLEM,
			//   REG_SUBKEY
			//);
			sprintf                          /* Assemble msg                  */
			(
				&(gs_pgi->szEvent[strlen(gs_pgi->szEvent)]),
				"\r\n\r\nNote: This information is also logged in the event log"
			);
			SetDlgItemText(hwndDlg, IDC_STATIC_MSG, gs_pgi->szEvent);
			/* Insert msg                    */
			gs_pgi->iTimerValue = DLG_TIMEOUT;
			/* Start value for timer         */
			sprintf                          /* Assemble timer msg            */
			(
				gs_pgi->szTimer,
				"(This dialog box will be automatically dismissed within %i second%s)",
				gs_pgi->iTimerValue,
				(gs_pgi->iTimerValue == 1) ? "" : "s"
			);
			SetDlgItemText(hwndDlg, IDC_STATIC_TIMEOUT, gs_pgi->szTimer);
			/* Insert timer msg              */
			Beep(BEEP_FREQ, BEEP_DUR);        /* Short beep!!!                 */
			SetTimer(hwndDlg, DLG_TIMER_ID, 1000, 0);
			/* Start timer                   */
			return   TRUE;

		case  WM_TIMER:
			xLog(0, "%s/%s: Message <%s>", MODULE, FUNCTION, "WM_TIMER");
			gs_pgi->iTimerValue--;           /* Adjust timer value            */
			if (gs_pgi->iTimerValue == 0)    /* Time-out?                     */
			{
				Beep(BEEP_FREQ, BEEP_DUR);     /* Short beep!!!                 */
				KillTimer(hwndDlg, 1);         /* Kill timer                    */
				EndDialog(hwndDlg, IDOK);      /* Stop dialog                   */
			}
			else
			{
				sprintf                       /* Assemble timer msg            */
				(
					gs_pgi->szTimer,
					"(This dialog box will be automatically dismissed within %i second%s)",
					gs_pgi->iTimerValue,
					(gs_pgi->iTimerValue == 1) ? "" : "s"
				);
				SetDlgItemText(hwndDlg, IDC_STATIC_TIMEOUT, gs_pgi->szTimer);
				/* Insert timer msg              */
			}
			return   FALSE;                  /* And return                    */

		case  WM_COMMAND:
			xLog(0, "%s/%s: Message <%s>", MODULE, FUNCTION, "WM_COMMAND");
			switch (LOWORD(wParam))
			{
			case  IDOK:
				KillTimer(hwndDlg, 1);      /* Kill timer                    */
				EndDialog(hwndDlg, wParam);
				/* Stop dialog                   */
				return TRUE;               /* And return                    */

			default:
				break;
			}
		}
		return FALSE;
	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	wndProc
	-------

	Wnd procedure.


	Parameters:
	-----------

	hwnd           Hwnd for window.

	uMsg           Message.

	wParam         First msg parameter.

	lParam         Second msg parameter.


	Return value:
	-------------

	Message dependent.

	*/
	LRESULT CALLBACK  wndProc                 /* Wnd procedure                 */
	(
		HWND           hwnd,                   /* Handle to window              */
		UINT           uMsg,                   /* Message identifier            */
		WPARAM         wParam,                 /* First message parameter       */
		LPARAM         lParam                  /* Second message parameter      */
	)
	{
#undef   FUNCTION
#define  FUNCTION "wndProc"

		//HDC            hdc;                    /* Handle Device Context         */
		LRESULT        lresult;                /* Return code from function     */
											   //PAINTSTRUCT    ps;                     /* Struct for WM_PAINT           */


		switch (uMsg)                        /* Analyse msg                   */
		{


		case  WM_CREATE:


			xLog(0, "%s/%s: Message <%s>", MODULE, FUNCTION, "WM_CREATE");
			/*
			Display a popup (dlg box) with the message.
			-------------------------------------------
			*/
			DialogBox                        /* Display a dlg box             */
			(
				gs_pgi->hinstDLL,             /* HINSTANCE                     */
				MAKEINTRESOURCE(IDD_DIALOG1), /* Template                      */
				0,                            /* HWND                          */
				dlgProc                       /* Dlg procedure                 */
			);

			// 120417, Do not shut down parent process! /KoH
			//         PostMessage(hwnd,WM_QUIT,0L,0L); /* Post final msg                */
			lresult = (LRESULT)FALSE;
			goto  l_Synk;


#if defined(BLAJ)
		case  WM_PAINT:

			hdc = BeginPaint(hwnd, &ps);      /* Get a Device Context          */
			if (hdc != (HDC)NULL)           /* OK ?                          */
			{
				EndPaint(hwnd, &ps);           /* Release Device Context        */
			}
			lresult = (LRESULT)FALSE;
			goto  l_Synk;
#endif


		case  WM_DESTROY:

			xLog(0, "%s/%s: Message <%s>", MODULE, FUNCTION, "WM_DESTROY");
			// 120417, Do not shut down parent process! /KoH
			//         PostMessage(hwnd,WM_QUIT,0L,0L); /* Post final msg                */
			lresult = (LRESULT)FALSE;
			goto  l_Synk;
		}


		// Use default message handler.
		// ----------------------------
		xLog(0, "%s/%s: Message <%i>", MODULE, FUNCTION, uMsg);
		lresult = DefWindowProc(hwnd, uMsg, wParam, lParam);
		// Use default message handler


	l_Synk:


		return   lresult;                      /* And return                    */
	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	handlePopup
	-----------

	Handle popup dlg. This popup is used when iPosLog encounters some sort
	of initial problem, like reading configuration info from registry.


	Parameters:
	-----------

	-


	Return value:
	-------------

	-

	*/
	void              handlePopup             /* Handle popup dlg              */
	(
		void
	)
	{
#undef   FUNCTION
#define  FUNCTION "handlePopup"

		static
			char           s_szBuf[1024];

		ATOM           atom = 0;               /* Return code from API          */
		BOOL           fcc;                    /* Return code from API          */
		DWORD          dwcc;                   /* Return code from API          */
											   //MSG            msg;                    /* Struct for messages handled   */
		WNDCLASS       wndClass = { 0 };       /* Info for window class         */


											   //GetCurrentProcess
											   //OpenProcessToken
											   //GetTokenInformation
											   //AllocateAndInitializeSid
		//xLog(0, "%s/%s: Entry", MODULE, FUNCTION);


		memset(s_szBuf, 0, sizeof(s_szBuf));
		dwcc = GetModuleFileName(0, s_szBuf, sizeof(s_szBuf));
		if (dwcc != 0)
		{
			xLog(0, "%s/%s: Current file name is <%s>", MODULE, FUNCTION, s_szBuf);
		}

		fcc = checkIfService();                /* Check if running as a service */
		xLog(0, "%s/%s: Call to <%s> returned <%s>", MODULE, FUNCTION, "checkIfService", (fcc == TRUE) ? "TRUE" : "FALSE");


		/*
		Prepare window info.
		--------------------
		*/
		memset(&wndClass, 0, sizeof(wndClass));  /* Clear info                    */
		wndClass.lpfnWndProc = wndProc;        /* Wnd procedure                 */
		wndClass.hInstance = gs_pgi->hinstDLL; /* Instance of DLL               */
		wndClass.lpszClassName = WHO_AM_I;     /* Name of window class          */
		wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		/* Icon for window               */
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		/* Cursor for window             */
		wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		/* Brush for window              */


		/*
		Register window class.
		----------------------
		*/
		atom = RegisterClass                   /* Register window class         */
		(
			&wndClass                           /* Info for window class         */
		);
		if (atom == 0)                         /* OK?                           */
		{
			xLog(1, "%s/%s: Call to <%s> failed, rc = <%i>", MODULE, FUNCTION, "RegisterClass", GetLastError());
			goto  l_Synk;
		}


		/*
		Create window.
		--------------

		The main purpose of this window is to become tha parent of the
		dialog box that shows a message to the user.

		*/
		gs_pgi->hwndPopup = CreateWindow       /* Create window                 */
		(
			WHO_AM_I,                           /* Name of window class          */
			"",                                 /* Window title                  */
			WS_POPUP,                           /* Window style                  */
			0,                                  /* X                             */
			0,                                  /* Y                             */
			0,                                  /* Width                         */
			0,                                  /* Height                        */
												//HWND_MESSAGE,                       /* Parent window                 */
			0,                                  /* Parent window                 */
			0,                                  /* Menu                          */
			gs_pgi->hinstDLL,                   /* Instance of DLL               */
			0                                   /* lParam                        */
		);
		if (gs_pgi->hwndPopup == 0)            /* OK?                           */
		{
			xLog(1, "%s/%s: Call to <%s> failed, rc = <%i>", MODULE, FUNCTION, "CreateWindow", GetLastError());
			goto  l_Synk;
		}


		/*
		(Don't) show window and paint it.
		---------------------------------
		*/
		ShowWindow(gs_pgi->hwndPopup, SW_HIDE); /* Don't show window!!!          */
												//UpdateWindow(gs_pgi->hwndPopup);       /* Update client area            */


#if defined(BLAJ)
												/*
												Message loop.
												-------------
												*/
		while (GetMessage(&msg, 0, 0, 0) == TRUE)
		{
			TranslateMessage(&msg);             /* Translate keyboard            */
												/* accelerators                  */
			DispatchMessage(&msg);              /* Dispatch message              */
		}
#endif


	l_Synk:


		/*
		Destroy window.
		---------------
		*/
		if (gs_pgi->hwndPopup != 0)            /* Have we created a popup       */
											   /* window?                       */
		{
			DestroyWindow(gs_pgi->hwndPopup);   /* Destroy it!!!                 */
			gs_pgi->hwndPopup = 0;              /* No window!!!                  */
		}


		/*
		Deregister windows class.
		-------------------------
		*/
		if (atom != 0)                         /* Have we registered a window   */
											   /* class?                        */
		{
			UnregisterClass
			(
				WHO_AM_I,                        /* Name of window class          */
				gs_pgi->hinstDLL                 /* Instance of DLL               */
			);
		}

		xLog(0, "%s/%s: Exit", MODULE, FUNCTION);
	}

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	logEvent
	--------

	Write a message in the event log.


	Parameters:
	-----------

	pszMsg         Msg to be logged.

	...            Any complementary parameters. Format as printf.


	Return value:
	-------------

	-

	*/
	void              logEvent                /* Write a message in the event  */
											  /* log                           */
											  (
												  char*          pszMsg,                 /* Msg to be logged              */
												  ...                                    /* Any complementary parameters  */
											  )
	{
#undef   FUNCTION
#define  FUNCTION "logEvent"

		char*          pszStrings[1] = { 0 };  /* Strings to be logged          */
		HANDLE           hkey = 0;               /* Handle to key for event log   */
		va_list        vl;                     /* Reference variable parameters */


											   /*
											   Assemble message.
											   -----------------
											   */
		sprintf(gs_pgi->szEvent, "%s\r\n\r\n", WHO_AM_I);
		va_start(vl, pszMsg);                   /* Reference variable parameters */
		vsprintf(&(gs_pgi->szEvent[strlen(gs_pgi->szEvent)]), pszMsg, vl);
		/* Assemble message with         */
		/* variable parameters           */
		va_end(vl);                            /* Terminate reference           */


											   /*
											   Register source for event.
											   --------------------------
											   */

											   // TODO 120427/KoH.
											   // See http://msdn.microsoft.com/en-us/library/aa363661(v=vs.85).aspx and others
											   // for information about hot to register a source for us.
											   // 1) We need to add the source to the registry
											   // 2) Provide a "message file" to be used to ientify the format of event entries in the Log.

		hkey = RegisterEventSource(0, "Application"); // Default Source is Application
													  //   hkey = RegisterEventSource(0,"iPosLog"); // TODO 120427, Implement "iPosLog" provider (See above)
													  /* Register key for event log    */
		if (hkey != 0)                         /* OK?                           */
		{
			pszStrings[0] = gs_pgi->szEvent;    /* Message to be logged          */


												/*
												Report event.
												-------------
												*/
			ReportEvent                         /* Log message                   */
			(
				hkey,
				EVENTLOG_INFORMATION_TYPE,
				0,
				0,
				0,
				1,
				0,
				(LPCSTR*)pszStrings,
				0
			);

			DeregisterEventSource(hkey);        /* De-register key for event log */
		}


		/*
		Handle popup dlg.
		-----------------
		*/
		handlePopup();                         /* Handle popup dlg              */
	}

#define  FMT_MSG           FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,0,0,0,gs_pgi->szFormat,sizeof(gs_pgi->szFormat),0)
#define  REG_PROBLEM_MSG   "\r\n\r\n%s. Please make sure that registry key HKEY_LOCAL_MACHINE\\%s is correctly configured"
#define  REG_PROBLEM       "Registry problem"

	/*
	**************************************************************************
	**************************************************************************
	**************************************************************************
	**************************************************************************

	getParameters
	-------------

	Get parameter values from registry.


	Parameters:>
	-----------

	-


	Return value:
	-------------

	TRUE           Parameter values extracted OK from registry.

	FALSE          Something went wrong.

	*/
	BOOL              getParameters           /* Get parameter values          */
	(
		void
	)
	{
#undef   FUNCTION
#define  FUNCTION "getParameters"

		BOOL           fRet = FALSE;           /* Return code from function     */

		DWORD          dwLen;                  /* Length of parameter value     */
		DWORD          dwType;                 /* Type of value                 */
		LONG           lcc;                    /* Return code from API          */

	//	xLog(0, "%s/%s: Entry", MODULE, FUNCTION);


		/*
		***********************************************************************

		Open key for pgm.
		-----------------
		*/

		// xLog(0, "%s/%s: Calling <%s>", MODULE, FUNCTION, "RegOpenKeyEx");
		gs_pgi->hkey = 0;                      /* No key!!!                     */
		lcc = RegOpenKeyEx                     /* Open key for pgm              */
		(
			HKEY_LOCAL_MACHINE,                 /* Base key                      */
			REG_SUBKEY,                         /* Subkey for pgm                */
			//R"(Software\SCC\iPosLog)",
			0,                                  /* RSU                           */
			KEY_ALL_ACCESS,                     /* Complete access!!!            */
			&(gs_pgi->hkey)                     /* Receiver subkey               */
		);
		if (lcc != ERROR_SUCCESS)              /* OK?                           */
		{

			FMT_MSG;
			logEvent
			(
				"%s/%s: Call to <%s> failed, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
				MODULE,
				FUNCTION,
				"RegOpenKeyEx",
				lcc,
				gs_pgi->szFormat,
				REG_PROBLEM,
				REG_SUBKEY
			);
			//xLog
			//(
			//	1,
			//	"%s/%s: Call to <%s> failed, rc = <%li>, msg = %s",
			//	MODULE,
			//	FUNCTION,
			//	"RegOpenKeyEx",
			//	lcc,
			//	gs_pgi->szFormat
			//);
			goto  l_Synk;
		}
		//xLog
		//(
		//	0,
		//	"%s/%s: Call to <%s> successful",
		//	MODULE,
		//	FUNCTION,
		//	"RegOpenKeyEx"
		//);


	//	/*
	//	***********************************************************************

	//	Read values for all parameters used by pgm.
	//	-------------------------------------------

	//	All parameters are optional.

	//	*/


		/*
		***********************************************************************

		Name of log file.
		-----------------
		*/
		dwLen = sizeof(gs_pgi->szLogFile);     /* Length of receiver field      */
		lcc = RegQueryValueEx                  /* Extract name of log file      */
		(
			gs_pgi->hkey,                       /* Registry key                  */
			KEY_LOGFILE,                        /* Name for value                */
			0,                                  /* (Reserved)                    */
			&dwType,                            /* Receiver parameter type       */
			reinterpret_cast<LPBYTE>(gs_pgi->szLogFile),                  /* Receiving buffer              */
			&dwLen                              /* Length of buffer              */
		);

		if (lcc != ERROR_SUCCESS)              /* OK?                           */
		{
			//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGFILE,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGFILE,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
			goto  l_Synk;
		}
		if (dwType != REG_SZ)                  /* Is data type correct?         */
		{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGFILE,
	//			REG_SZ,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGFILE,
	//			REG_SZ,
	//			dwType
	//		);
			goto  l_Synk;
		}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%s>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_LOGFILE,
	//		gs_pgi->szLogFile
	//	);


	//	/*
	//	***********************************************************************

	//	Name of temporary log file.
	//	---------------------------
	//	*/
	//	dwLen = sizeof(gs_pgi->szTempLog);     /* Length of receiver field      */
	//	lcc = RegQueryValueEx                  /* Extract name of log file      */
	//	(
	//		gs_pgi->hkey,                       /* Registry key                  */
	//		KEY_TEMPLOG,                        /* Name for value                */
	//		0,                                  /* (Reserved)                    */
	//		&dwType,                            /* Receiver parameter type       */
	//		gs_pgi->szTempLog,                  /* Receiving buffer              */
	//		&dwLen                              /* Length of buffer              */
	//	);
	//	if (lcc != ERROR_SUCCESS)              /* OK?                           */
	//	{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_TEMPLOG,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_TEMPLOG,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
	//		goto  l_Synk;
	//	}
	//	if (dwType != REG_SZ)                  /* Is data type correct?         */
	//	{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_TEMPLOG,
	//			REG_SZ,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_TEMPLOG,
	//			REG_SZ,
	//			dwType
	//		);
	//		goto  l_Synk;
	//	}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%s>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_TEMPLOG,
	//		gs_pgi->szTempLog
	//	);


	//	/*
	//	***********************************************************************

	//	Name of real DLL.
	//	-----------------
	//	*/
	//	dwLen = sizeof(gs_pgi->szRealDll);     /* Length of receiver field      */
	//	lcc = RegQueryValueEx                  /* Extract name of log file      */
	//	(
	//		gs_pgi->hkey,                       /* Registry key                  */
	//		KEY_REALDLL,                        /* Name for value                */
	//		0,                                  /* (Reserved)                    */
	//		&dwType,                            /* Receiver parameter type       */
	//		gs_pgi->szRealDll,                  /* Receiving buffer              */
	//		&dwLen                              /* Length of buffer              */
	//	);
	//	if (lcc != ERROR_SUCCESS)              /* OK?                           */
	//	{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_REALDLL,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_REALDLL,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
	//		goto  l_Synk;
	//	}
	//	if (dwType != REG_SZ)                  /* Is data type correct?         */
	//	{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_REALDLL,
	//			REG_SZ,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_REALDLL,
	//			REG_SZ,
	//			dwType
	//		);
	//		goto  l_Synk;
	//	}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%s>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_REALDLL,
	//		gs_pgi->szRealDll
	//	);


	//	/*
	//	***********************************************************************

	//	Max number of messages in temporary log file.
	//	---------------------------------------------
	//	*/
	//	dwLen = sizeof(gs_pgi->iOldMsg);       /* Length of receiver field      */
	//	lcc = RegQueryValueEx                  /* Extract name of log file      */
	//	(
	//		gs_pgi->hkey,                       /* Registry key                  */
	//		KEY_MAXOLDMSG,                      /* Name for value                */
	//		0,                                  /* (Reserved)                    */
	//		&dwType,                            /* Receiver parameter type       */
	//		(LPBYTE) &(gs_pgi->iOldMsg),        /* Receiving buffer              */
	//		&dwLen                              /* Length of buffer              */
	//	);
	//	if (lcc != ERROR_SUCCESS)              /* OK?                           */
	//	{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_MAXOLDMSG,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_MAXOLDMSG,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
	//		goto  l_Synk;
	//	}
	//	if (dwType != REG_DWORD)               /* Is data type correct?         */
	//	{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_MAXOLDMSG,
	//			REG_DWORD,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_MAXOLDMSG,
	//			REG_DWORD,
	//			dwType
	//		);
	//		goto  l_Synk;
	//	}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%i>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_MAXOLDMSG,
	//		gs_pgi->iOldMsg
	//	);


	//	/*
	//	***********************************************************************

	//	Flag whether real DLL uses stdcall.
	//	-----------------------------------
	//	*/
	//	dwLen = sizeof(gs_pgi->iStdCall);      /* Length of receiver field      */
	//	lcc = RegQueryValueEx                  /* Extract name of log file      */
	//	(
	//		gs_pgi->hkey,                       /* Registry key                  */
	//		KEY_STDCALLDLL,                     /* Name for value                */
	//		0,                                  /* (Reserved)                    */
	//		&dwType,                            /* Receiver parameter type       */
	//		(LPBYTE) &(gs_pgi->iStdCall),       /* Receiving buffer              */
	//		&dwLen                              /* Length of buffer              */
	//	);
	//	if (lcc != ERROR_SUCCESS)              /* OK?                           */
	//	{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_STDCALLDLL,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_STDCALLDLL,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
	//		goto  l_Synk;
	//	}
	//	if (dwType != REG_DWORD)               /* Is data type correct?         */
	//	{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_STDCALLDLL,
	//			REG_DWORD,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_STDCALLDLL,
	//			REG_DWORD,
	//			dwType
	//		);
	//		goto  l_Synk;
	//	}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%i>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_STDCALLDLL,
	//		gs_pgi->iStdCall
	//	);


		/*
		***********************************************************************

		Flag whether iPos messages are to be logged.
		--------------------------------------------
		*/
		dwLen = sizeof(gs_pgi->iLogIposMsg);   /* Length of receiver field      */
		lcc = RegQueryValueEx                  /* Extract name of log file      */
		(
			gs_pgi->hkey,                       /* Registry key                  */
			KEY_LOGIPOSMSG,                     /* Name for value                */
			0,                                  /* (Reserved)                    */
			&dwType,                            /* Receiver parameter type       */
			(LPBYTE) &(gs_pgi->iLogIposMsg),    /* Receiving buffer              */
			&dwLen                              /* Length of buffer              */
		);
		if (lcc != ERROR_SUCCESS)              /* OK?                           */
		{
			//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGIPOSMSG,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGIPOSMSG,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
			goto  l_Synk;
		}
		if (dwType != REG_DWORD)               /* Is data type correct?         */
		{
			//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGIPOSMSG,
	//			REG_DWORD,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGIPOSMSG,
	//			REG_DWORD,
	//			dwType
	//		);
			goto  l_Synk;
		}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%i>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_LOGIPOSMSG,
	//		gs_pgi->iLogIposMsg
	//	);


	//	/*
	//	***********************************************************************

	//	Port for filter client.
	//	-----------------------
	//	*/
	//	dwLen = sizeof(gs_pgi->iFilterPort);   /* Length of receiver field      */
	//	lcc = RegQueryValueEx                  /* Extract name of log file      */
	//	(
	//		gs_pgi->hkey,                       /* Registry key                  */
	//		KEY_FILTER,                         /* Name for value                */
	//		0,                                  /* (Reserved)                    */
	//		&dwType,                            /* Receiver parameter type       */
	//		(LPBYTE) &(gs_pgi->iFilterPort),    /* Receiving buffer              */
	//		&dwLen                              /* Length of buffer              */
	//	);
	//	if (lcc != ERROR_SUCCESS)              /* OK?                           */
	//	{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_FILTER,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_FILTER,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
	//		goto  l_Synk;
	//	}
	//	if (dwType != REG_DWORD)               /* Is data type correct?         */
	//	{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_FILTER,
	//			REG_DWORD,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_FILTER,
	//			REG_DWORD,
	//			dwType
	//		);
	//		goto  l_Synk;
	//	}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%i>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_FILTER,
	//		gs_pgi->iFilterPort
	//	);


	//	/*
	//	***********************************************************************

	//	Flag whether filter client is mandatory.
	//	----------------------------------------
	//	*/
	//	dwLen = sizeof(gs_pgi->iFilterClientMandatory);
	//	/* Length of receiver field      */
	//	lcc = RegQueryValueEx                  /* Extract name of log file      */
	//	(
	//		gs_pgi->hkey,                       /* Registry key                  */
	//		KEY_FILTER_MAND,                    /* Name for value                */
	//		0,                                  /* (Reserved)                    */
	//		&dwType,                            /* Receiver parameter type       */
	//		(LPBYTE) &(gs_pgi->iFilterClientMandatory),
	//		/* Receiving buffer              */
	//		&dwLen                              /* Length of buffer              */
	//	);
	//	if (lcc != ERROR_SUCCESS)              /* OK?                           */
	//	{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_FILTER_MAND,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_FILTER_MAND,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
	//		goto  l_Synk;
	//	}
	//	if (dwType != REG_DWORD)               /* Is data type correct?         */
	//	{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_FILTER_MAND,
	//			REG_DWORD,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_FILTER_MAND,
	//			REG_DWORD,
	//			dwType
	//		);
	//		goto  l_Synk;
	//	}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%i>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_FILTER_MAND,
	//		gs_pgi->iFilterClientMandatory
	//	);


	//	/*
	//	***********************************************************************

	//	Port for clients listening before filtering.
	//	--------------------------------------------
	//	*/
	//	dwLen = sizeof(gs_pgi->iListenBeforePort);
	//	/* Length of receiver field      */
	//	lcc = RegQueryValueEx                  /* Extract name of log file      */
	//	(
	//		gs_pgi->hkey,                       /* Registry key                  */
	//		KEY_LISTENBEFORE,                   /* Name for value                */
	//		0,                                  /* (Reserved)                    */
	//		&dwType,                            /* Receiver parameter type       */
	//		(LPBYTE) &(gs_pgi->iListenBeforePort),
	//		/* Receiving buffer              */
	//		&dwLen                              /* Length of buffer              */
	//	);
	//	if (lcc != ERROR_SUCCESS)              /* OK?                           */
	//	{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LISTENBEFORE,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LISTENBEFORE,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
	//		goto  l_Synk;
	//	}
	//	if (dwType != REG_DWORD)               /* Is data type correct?         */
	//	{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LISTENBEFORE,
	//			REG_DWORD,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LISTENBEFORE,
	//			REG_DWORD,
	//			dwType
	//		);
	//		goto  l_Synk;
	//	}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%i>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_LISTENBEFORE,
	//		gs_pgi->iListenBeforePort
	//	);


	//	/*
	//	***********************************************************************

	//	Port for clients listening after filtering.
	//	-------------------------------------------
	//	*/
	//	dwLen = sizeof(gs_pgi->iListenAfterPort);
	//	/* Length of receiver field      */
	//	lcc = RegQueryValueEx                  /* Extract name of log file      */
	//	(
	//		gs_pgi->hkey,                       /* Registry key                  */
	//		KEY_LISTENAFTER,                    /* Name for value                */
	//		0,                                  /* (Reserved)                    */
	//		&dwType,                            /* Receiver parameter type       */
	//		(LPBYTE) &(gs_pgi->iListenAfterPort),
	//		/* Receiving buffer              */
	//		&dwLen                              /* Length of buffer              */
	//	);
	//	if (lcc != ERROR_SUCCESS)              /* OK?                           */
	//	{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LISTENAFTER,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LISTENAFTER,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
	//		goto  l_Synk;
	//	}
	//	if (dwType != REG_DWORD)               /* Is data type correct?         */
	//	{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LISTENAFTER,
	//			REG_DWORD,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LISTENAFTER,
	//			REG_DWORD,
	//			dwType
	//		);
	//		goto  l_Synk;
	//	}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%i>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_LISTENAFTER,
	//		gs_pgi->iListenAfterPort
	//	);


		/*
		***********************************************************************

		Log level for pgm.
		------------------
		*/
		dwLen = sizeof(gs_pgi->iLogLevel);     /* Length of receiver field      */
		lcc = RegQueryValueEx                  /* Extract name of log file      */
		(
			gs_pgi->hkey,                       /* Registry key                  */
			KEY_LOGLEVEL,                       /* Name for value                */
			0,                                  /* (Reserved)                    */
			&dwType,                            /* Receiver parameter type       */
			(LPBYTE) &(gs_pgi->iLogLevel),      /* Receiving buffer              */
			&dwLen                              /* Length of buffer              */
		);
		if (lcc != ERROR_SUCCESS)              /* OK?                           */
		{
	//		FMT_MSG;
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGLEVEL,
	//			lcc,
	//			gs_pgi->szFormat,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>, rc = <%li>, msg = %s",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGLEVEL,
	//			lcc,
	//			gs_pgi->szFormat
	//		);
			goto  l_Synk;
		}
		if (dwType != REG_DWORD)               /* Is data type correct?         */
		{
	//		logEvent
	//		(
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>" REG_PROBLEM_MSG,
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGLEVEL,
	//			REG_DWORD,
	//			dwType,
	//			REG_PROBLEM,
	//			REG_SUBKEY
	//		);
	//		xLog
	//		(
	//			1,
	//			"%s/%s: Call to <%s> failed for parameter <%s>. Bad type for value: expected <%i>, received <%i>",
	//			MODULE,
	//			FUNCTION,
	//			"RegQueryValueEx",
	//			KEY_LOGLEVEL,
	//			REG_DWORD,
	//			dwType
	//		);
			goto  l_Synk;
		}
	//	xLog
	//	(
	//		0,
	//		"%s/%s: Call to <%s> successful for parameter <%s>. Value extracted from registry is <%i>",
	//		MODULE,
	//		FUNCTION,
	//		"RegQueryValueEx",
	//		KEY_LOGLEVEL,
	//		gs_pgi->iLogLevel
	//	);


		/*
		***********************************************************************

		Indicate that everything is OK.
		-------------------------------
		*/
	//	xLog(0, "%s/%s: Everything is OK", MODULE, FUNCTION);
		fRet = TRUE;                           /* Everything is OK !!!          */


	l_Synk:


		/*
		***********************************************************************

		Close registry key if it is open.
		---------------------------------
		*/
		if (gs_pgi->hkey != 0)                 /* Is registry key open          */
		{
			RegCloseKey(gs_pgi->hkey);          /* Close it!!!                   */
		}
		gs_pgi->hkey = 0;                      /* No registry key!!!            */


		// xLog(0, "%s/%s: Entry (%s)", MODULE, FUNCTION, (fRet == TRUE) ? "TRUE" : "FALSE");

		if (fRet == false) {
			throw std::runtime_error("Failed to read parameters from registry");
		}

		return   fRet;                         /* And return                    */
	}


}
