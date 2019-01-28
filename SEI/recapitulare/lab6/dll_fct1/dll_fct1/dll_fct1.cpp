// dll_fct1.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

 __declspec(dllexport) double fct_mat1 (double a, double b)
{
	return 10 * a + b;
}
