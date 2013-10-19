#include "stdafx.h"
#include "DlgOne.h"
#include "controls.h"

LRESULT CDlgOne::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow();
    InitControls();
    return 1;
}

LRESULT CDlgOne::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
      return EndDialog(0);
}

void CDlgOne::InitControls() {

    const int lineHeight = 30;
    RECT rc;
    
    GetClientRect(&rc);
    InflateRect(&rc, -20, -20);
    rc.top = 10;
    rc.bottom = rc.top + lineHeight;
    ATLControls::CStatic header;
    header.Create(m_hWnd, &rc, _T("Це перший діалог із серії. Демонструє елемети управління."));

    OffsetRect(&rc, 0, lineHeight);
    RECT label = rc;
    label.right = 80;
    ATLControls::CStatic edit_label;
    edit_label.Create(m_hWnd, &label, _T("Edit: "));

    OffsetRect(&label, 100, 0);
    ATLControls::CEdit edit;
    edit.Create(m_hWnd, &label, _T("1234"), WS_CHILD | WS_VISIBLE | WS_TABSTOP);

    OffsetRect(&label, 100, 0);
    ATLControls::CButton edit_button;
    edit_button.Create(m_hWnd, &label, _T("Show"), WS_CHILD | WS_VISIBLE | WS_TABSTOP);
    edit_button.SetDlgCtrlID(444);

	/*
	*
	*/
	OffsetRect(&rc, -15, 50);
	ATLControls::CStatic myStatic;
	myStatic.Create(m_hWnd, &rc, _T("My static Text"));

	OffsetRect(&rc, 0, 50);
	static ATLControls::CEdit ed;
	rc.right = 100;
	rc.bottom = 200;
	ed.Create(m_hWnd, &rc, _T("hi"), WS_CHILD | WS_VISIBLE | WS_TABSTOP| ES_MULTILINE);

	OffsetRect(&rc, 100, 0);
	ATLControls::CButton transferB;
	rc.right = 250;
	transferB.Create(m_hWnd, &rc, _T("<TransferText>"),WS_CHILD | WS_VISIBLE);
	transferB.SetDlgCtrlID(445);

	OffsetRect(&rc, 180, 0);
	ATLControls::CEdit ed2;
	rc.right -= 50;
	ed2.Create(m_hWnd, &rc, _T("reciver"), WS_CHILD | WS_VISIBLE | ES_MULTILINE);

	OffsetRect(&rc, -200, 100 );
	ATLControls::CComboBox combBox;
	combBox.Create(m_hWnd, &rc, _T("cmbbx"), WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | WS_VSCROLL);

	combBox.AddString(_T("1"));
	combBox.AddString(_T("2"));
	combBox.AddString(_T("3"));
	combBox.SetCurSel(0);
	combBox.SetDlgCtrlID(446);

	OffsetRect(&rc, 150, 0);
	ATLControls::CListBox lstBox;
	lstBox.Create(m_hWnd, &rc, _T("lst"), WS_CHILD| WS_VISIBLE|WS_VSCROLL | LBS_NOTIFY);
	lstBox.AddString(_T("one"));
	lstBox.AddString(_T("two"));
	lstBox.AddString(_T("thre"));
	lstBox.AddString(_T("four"));
	lstBox.AddString(_T("five"));
	lstBox.SetCurSel(0);
	lstBox.SetDlgCtrlID(447);
};

 LRESULT  CDlgOne::OnShowEdit(WORD, WORD, HWND, BOOL& )
 {
     MessageBox(_T("Button Show pressed"));
     return 1;
 }
    LRESULT   CDlgOne::OnTransfer(WORD, WORD, HWND, BOOL& )
	{
		HWND hwnd;
		hwnd = FindWindowEx(m_hWnd, 0, L"EDIT", L"hi");
		TCHAR str[100];
		::GetWindowText(hwnd, str, 100);
		hwnd = FindWindowEx(m_hWnd, 0, L"EDIT", L"reciver");
		::SetWindowText(hwnd, str);

		return 1;
	}
	LRESULT   CDlgOne::OnDropBox(WORD hi , WORD lo , HWND lParam, BOOL& b)
	{
		HWND hwnd;
		hwnd = FindWindowEx(m_hWnd, 0, _T("COMBOBOX"),0);
		TCHAR str[100];
		ATLControls::CComboBox combBox(hwnd); 
		
		switch(hi)
		{
		case CBN_CLOSEUP:
			combBox.GetLBText(combBox.GetCurSel(), str);
			
			hwnd = FindWindowEx(m_hWnd, 0, L"EDIT", L"reciver");
			::SetWindowText(hwnd, str);
			break;
		}

		return 1;
	}

	LRESULT   CDlgOne::OnLstBox(WORD hi , WORD lo , HWND lParam, BOOL& b)
	{
		HWND hwnd;
		hwnd = FindWindowEx(m_hWnd, 0, _T("LISTBOX"),0);
		TCHAR str[100];
		ATLControls::CListBox lstBox(hwnd); 

		switch(hi)
		{
		case LBN_SELCHANGE:
			lstBox.GetText(lstBox.GetCurSel(), str);

			hwnd = FindWindowEx(m_hWnd, 0, L"EDIT", L"reciver");
			::SetWindowText(hwnd, str);
			break;
		}
		return 1;
	}