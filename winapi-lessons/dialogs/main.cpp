#include "stdafx.h"
#include "DlgOne.h"
#include "DlgTwo.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{

    _Module.Init(NULL, hInstance);

    INITCOMMONCONTROLSEX iccex = {sizeof(iccex), ICC_TREEVIEW_CLASSES};
/*
    if(CDlgOne().DoModal(0))
        return 1;
*/
    
    if(CDlgTwo().DoModal(0))
        return 1;

    _Module.Term();

    return 0;

}

CComModule _Module;