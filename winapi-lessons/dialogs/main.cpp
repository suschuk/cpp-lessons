#include "stdafx.h"
#include "DlgOne.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{

    CDlgOne one;
    one.DoModal(0);

    return 0;

}