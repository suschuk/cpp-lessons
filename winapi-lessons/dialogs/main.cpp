#include "stdafx.h"
#include "DlgOne.h"
#include "DlgTwo.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{

    _Module.Init(NULL, hInstance);

    INITCOMMONCONTROLSEX iccex = {sizeof(iccex), ICC_TREEVIEW_CLASSES};

    CDlgOne().DoModal(0);
    CDlgTwo().DoModal(0);

    _Module.Term();

    return 0;

}

CComModule _Module;