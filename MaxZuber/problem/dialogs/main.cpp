#include "stdafx.h"
#include "DlgOne.h"
#include "DlgTwo.h"
#include "DlgThree.h"

HINSTANCE g_hInst;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	g_hInst = hInstance;
    _Module.Init(NULL, hInstance, &LIBID_ATLLib);

    CDlgTwo two;
	two.DoModal();
	CDlgThree three;
	three.DoModal();

    _Module.Term();

    return 0;

}

CComModule _Module;