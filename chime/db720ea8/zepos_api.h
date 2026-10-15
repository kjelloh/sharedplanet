// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ZEPOS_API_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ZEPOS_API_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ZEPOS_API_EXPORTS
#define ZEPOS_API_API __declspec(dllexport)
#else
#define ZEPOS_API_API __declspec(dllimport)
#endif

// BEGIN iPOS API
typedef int(_stdcall *TOnEvent) (unsigned int wParam, unsigned int lParam);
ZEPOS_API_API int  ipos_Init(HWND Handle, unsigned int Message, TOnEvent Callback, int Id);
ZEPOS_API_API int  ipos_Conf(char* szConfigString, int Id);
ZEPOS_API_API int  ipos_Write(unsigned char *Data, int DataLen, int Id);
ZEPOS_API_API int  ipos_Read(unsigned char *Data, int MaxLen, int *DataLen, int Id);
ZEPOS_API_API int  ipos_Close(int Id);
typedef struct {
	DWORD DLLVersionMajor;
	DWORD DLLVersionMinor;
	DWORD IsDebugVersion;
	char Name[64];
	char Manufacturer[64];
	char Copyright[64];
} IPOS_VERSIONINFO;
ZEPOS_API_API int  ipos_GetVersion(IPOS_VERSIONINFO* versionInfo);
// END iPOS API