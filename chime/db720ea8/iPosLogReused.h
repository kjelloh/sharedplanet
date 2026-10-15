#pragma once

#include  <cstdint>
#include <windows.h> // WaitForSingleObject...
#include <stdio.h> // FILE* and C file functions

// Re-used code from iPosLog.dll
namespace iPosLog {

	int               cb                      /* Our callback function         */
	(
		unsigned int terminalid, 
		unsigned int msglen
	);

	/*
	**************************************************************************

	Format strings (unique per function).
	-------------------------------------
	*/
#define  FMT_CLOSE         "TS=%s L=%.9u Fn=%-15s RC=%i ID=%i"
	/* ipos_Close:                   */
	/* -----------                   */
	/*                               */
	/* Timestamp                     */
	/* Function (ipos_Close)         */
	/* Return code from real DLL     */
	/* Access ID                     */

#define  FMT_CONF          "TS=%s L=%.9u Fn=%-15s RC=%i ID=%i D=%s"
	/* ipos_Conf:                    */
	/* ----------                    */
	/*                               */
	/* Timestamp                     */
	/* Function (ipos_Conf)          */
	/* Return code from real DLL     */
	/* Access ID                     */
	/* Data                          */

#define  FMT_GETVER        "TS=%s L=%.9u Fn=%-15s RC=%i D=%s"
	/* ipos_GetVersion:              */
	/* ----------------              */
	/*                               */
	/* Timestamp                     */
	/* Function (ipos_GetVersion)    */
	/* Return code from real DLL     */
	/* Data                          */

#define  FMT_INIT          "TS=%s L=%.9u Fn=%-15s RC=%i ID=%i Hwnd=%i Msg=%i CB=%p"
	/* ipos_Init:                    */
	/* ----------                    */
	/*                               */
	/* Timestamp                     */
	/* Function (ipos_Init)          */
	/* Return code from real DLL     */
	/* Access ID                     */
	/* Data (hwnd, msg, callback)    */

#define  FMT_READ          "TS=%s L=%.9u Fn=%-15s RC=%i ID=%i D=%s"
	/* ipos_Read:                    */
	/* ----------                    */
	/*                               */
	/* Timestamp                     */
	/* Function (ipos_Read)          */
	/* Return code from real DLL     */
	/* Access ID                     */
	/* Data                          */

#define  FMT_WRITE         "TS=%s L=%.9u Fn=%-15s RC=%i ID=%i D=%s"
	/* ipos_Write:                   */
	/* -----------                   */
	/*                               */
	/* Timestamp                     */
	/* Function (ipos_Write)         */
	/* Return code from real DLL     */
	/* Access ID                     */
	/* Data                          */

#define  FMT_CB            "TS=%s L=%.9u Fn=%-15s RC=%i ID=%i Len=%i"
	/* callback function:            */
	/* ------------------            */
	/*                               */
	/* Timestamp                     */
	/* Function (cb)                 */
	/* Return code from SACI/OS      */
	/* wParam (Access ID)            */
	/* lParam (Length of msg)        */

	char*             hex2Ascii               /* Convert hex to ASCII          */
	(
		void*          pvHex,                  /* Hex data                      */
		int            iLen                    /* Number of bytes with hex data */
	);

	char*             collectTimestamp        /* Collect time stamp            */
	(
		void
	);

	void              handleMsg               /* Handle a message              */
	(
		int            iLogLevel,              /* Log level for this msg        */
		char*          pszText,                /* Message to be handled         */
		...                                    /* Any complementary parameters  */
	);


#undef   MODULE
#define  MODULE   "ZeposApi"

	/*
	**************************************************************************

	Define log levels.
	------------------
	*/

#define  LL_ALWAYS         0
#define  LL_CRITICAL       1
#define  LL_ERROR          2
#define  LL_WARNING        3
#define  LL_INFORMATION    4
#define  LL_TRACE          5
#define  LL_DEBUG          6

#define  LL_NORMAL         LL_INFORMATION

#define  MAXFILESIZE       1024           /* Max size of file name         */
#define  MAXBUFSIZE        4096           /* Max size of buffer for msg    */

#define  PGM               "iPosLog"      /* Name of pgm                   */
#define  REG_SUBKEY        "Software\\SCC\\" PGM
#define  KEY_LOGFILE       "LogFile"      /* Keyword: Name of log file     */
#define  KEY_LOGIPOSMSG    "LogiPosMessages"
#define  KEY_LOGLEVEL      "LogLevel"     /* Log level for iPosLog         */

	void              xLog                    /* Extra log function            */
	(
		int            iMandatory,             /* Mandatory logging ?           */
											   /* 1 = YES                       */
											   /* 0 = NO                        */
		char*          pszText,                /* Text to be logged             */
		...                                    /* Any complementary parameters  */
	);

	BOOL              getParameters           /* Get parameter values          */
	(
		void
	);

	/*
	Define prototype for callback function.
	---------------------------------------
	*/
	typedef int(__stdcall * pCallback)(unsigned int wParam, unsigned int lParam);

	/*
	GI
	--

	Global info (for each instance of DLL).
	*/
	struct GI
	{

		void init(HMODULE _hinstDLL);

		/*
		Data related to our DLL.
		------------------------
		*/
		//HANDLE         mutexiPos;              /* Mutex for iPos messages       */
		HANDLE         mutexLog;               /* Mutex for logging             */
		//HANDLE         mutexSocket;            /* Mutex for sockets             */
		HINSTANCE      hinstDLL;               /* Instance handle of our DLL    */
		HKEY           hkey;                   /* Registry subkey for pgm       */

		HWND           hwnd;                   /* HWND used to notify SACI      */
		unsigned int   uiMsg;                  /* Msg ID used to notify SACI    */
											   /* of new messages               */
		pCallback      pcb;                    /* Callback function used to     */
											   /* notify SACI of new messages   */

		HWND           hwndPopup;              /* HWND popup window             */
		int            iTimerValue;            /* Value for timer in dialog box */
		char           szTimer[MAXBUFSIZE];    /* Buffer for timer              */
		char           szEvent[MAXBUFSIZE];    /* Buffer for event msg          */
		char           szFormat[MAXBUFSIZE];   /* Buffer for system formatted   */

		unsigned int   uiLineNumber;           /* Line number in log            */

		FILE*          pfLog;                  /* Handle log file               */
		//int            iOldMsg;                /* Number of old messages in     */
		//									   /* temporary log                 */
		//int            iStdCall;               /* Does real DLL use __stdcall   */
		//									   /* when calling callback         */
		//									   /* function in iPosLog ?         */
		//									   /*                               */
		//									   /* 0 = NO, other = YES           */
		int            iLogIposMsg;            /* Log iPos messages ?           */
		//									   /* 0 = NO, other = YES           */
		int            iLogLevel;              /* Log level for iPosLog         */
		//int            iFilterPort;            /* Port for filter client        */
		//int            iFilterClientMandatory; /* Is filter client mandatory?   */
		//int            iListenBeforePort;      /* Port for clients listening    */
		//									   /* to iPos messages before       */
		//									   /* filtering                     */
		//int            iListenAfterPort;       /* Port for clients listening    */
		//									   /* to iPos messages after        */
		//									   /* filtering                     */


		char           szTimestamp[32];        /* Collected time stamp          */

		//char           szInifile[MAXFILESIZE]; /* Name of INI file              */
		char           szLogFile[MAXFILESIZE]; /* Name of log file              */
		//char           szTempLog[MAXFILESIZE]; /* Name of temporary log file    */

		//char           szRealDll[MAXFILESIZE]; /* Name of real DLL              */

		char           szBuf[MAXBUFSIZE];      /* Buffer for log text           */
		//									   /* msg                           */
		char           szMsgSnd[MAXBUFSIZE];   /* Send buffer for handled       */
		//									   /* messages                      */
		//char           szMsgRcv[MAXBUFSIZE];   /* Receive buffer for handled    */
		//									   /* messages                      */
		//char           szTempBuf[MAXBUFSIZE];  /* Buffer for temporary messages */

		char           szHexAsciiBuf[MAXBUFSIZE];
		///* Buffer with hex-ASCII display */


		/*
		Data related to threads and sockets.
		------------------------------------
		*/
		//BOOL           fSocketInitialized;     /* Has socket interface been     */
		//									   /* initialized ?                 */

		//TI             tiAfter;                /* Thread info - after thread    */
		//SI             siAfter[MAXCLIENT];     /* Sockets after filtering       */

		//TI             tiBefore;               /* Thread info - before thread   */
		//SI             siBefore[MAXCLIENT];    /* Sockets before filtering      */

		//TI             tiFilter;               /* Thread info - filter thread   */
		//SI             siFilter;               /* Socket for filter             */


		/*
			Data related to real DLL.
			-------------------------
		*/
		//HMODULE        hmodDLL;                /* Module handle                 */
		//FARPROC        fpClose;                /* Function ipos_Close           */
		//FARPROC        fpConf;                 /* Function ipos_Conf            */
		//FARPROC        fpGetVer;               /* Function ipos_GetVersion      */
		//FARPROC        fpInit;                 /* Function ipos_Init            */
		//FARPROC        fpRead;                 /* Function ipos_Read            */
		//FARPROC        fpWrite;                /* Function ipos_Write           */

	};

	extern GI* gs_pgi;                 /* Global info (per instance)    */

	void logEvent	/* Write a message in the event  */
					/* log                           */
	(
		char*          pszMsg,                 /* Msg to be logged              */
		...                                    /* Any complementary parameters  */
	);
	
}