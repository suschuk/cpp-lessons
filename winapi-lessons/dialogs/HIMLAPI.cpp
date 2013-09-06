#include "stdafx.h"
#include "HIMLAPI.H"


typedef BOOL (WINAPI * SH_GIL_PROC)(HIMAGELIST *phLarge, HIMAGELIST *phSmall);
typedef BOOL (WINAPI * FII_PROC)   (BOOL fFullInit);



BOOL GetSystemImageLists(HIMAGELIST* phimlLarge, HIMAGELIST* phimlSmall) {


    HMODULE      hShell32;
    hShell32 = LoadLibrary(L"shell32.dll");
    assert(hShell32);
    //
    // Get Undocumented APIs from Shell32.dll:
    //
    SH_GIL_PROC  Shell_GetImageLists;
    FII_PROC     FileIconInit;  

    Shell_GetImageLists  = (SH_GIL_PROC) GetProcAddress(hShell32, (LPCSTR)71);
    FileIconInit         = (FII_PROC)    GetProcAddress(hShell32, (LPCSTR)660);

   assert(FileIconInit);
   FileIconInit(TRUE);

    assert(Shell_GetImageLists);
    Shell_GetImageLists(phimlLarge, phimlSmall);

    assert(phimlLarge);
    assert(phimlSmall);

    return TRUE;
}