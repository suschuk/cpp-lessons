// WinATLControls.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "WinATLControls.h"
#include "DlgOne.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    _Module.Init(NULL, hInstance, &LIBID_ATLLib);

    CDlgOne one;
    one.DoModal(0);


    _Module.Term();

    return 0;

}

CComModule _Module;