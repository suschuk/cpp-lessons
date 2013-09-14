#include "stdafx.h"
#include "DlgOne.h"

#include <random>
#include <ctime>

LRESULT CDlgOne::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
    CenterWindow();
    InitControls();

	MessageBox(_T("Rising"));

    return 1;
}

LRESULT CDlgOne::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) 
{
	MessageBox(_T("Falling"));
    return EndDialog(0);
}

void CDlgOne::InitControls() 
{
	srand((unsigned)time(0));

	RECT rc;

	GetClientRect(&rc);

	int width = rc.right;
	int height = rc.bottom;

	rc.left   = 40;
	rc.right  = 500;
	rc.top    = 40;
	rc.bottom = 60;

	_label1.Create(m_hWnd, &rc,_T("This is Label"), WS_CHILD | WS_VISIBLE);

	rc.left   = 40;
	rc.right  = 500;
	rc.top    = 60;
	rc.bottom = 80;

	_edit1.Create(m_hWnd, &rc,_T("This is Edit1"), WS_CHILD | WS_VISIBLE | WS_BORDER);
		 
	rc.left   = rand() % (width - 150);
	rc.right  = rc.left + rand() % 51 + 100;
	rc.top    = rand() % (height - 150);
	rc.bottom = rc.top + rand() % 51 + 15;

	_button1.Create(m_hWnd, &rc, _T("Press Me!"), WS_CHILD | WS_VISIBLE | WS_BORDER); 
	_button1.SetDlgCtrlID(IDD_BUTTON_ONE);

}

 LRESULT  CDlgOne::onButtonClick(WORD, WORD, HWND, BOOL& )
 {
     
	/*RECT rc;

	GetClientRect(&rc);
	
	int width = rc.right;
	int height = rc.bottom;

	rc.left   = rand() % (width - 150);
	rc.right  = rc.left + rand() % 51 + 100;
	rc.top    = rand() % (height - 150);
	rc.bottom = rc.top + rand() % 51 + 100;*/	

	 _edit1.AppendText(_T("You have press button "));

	return 1;
 }