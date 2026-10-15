// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "iPosLogReused.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (iPosLog::gs_pgi == nullptr) {
		iPosLog::gs_pgi = new iPosLog::GI();
		iPosLog::gs_pgi->init(hModule);
	}

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

