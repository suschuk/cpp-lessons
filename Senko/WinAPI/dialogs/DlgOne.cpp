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

    const int lineHeight = 20;
	const int listHeight = 60;
	RECT rc;
	RECT ml;
    
    GetClientRect(&rc);
    InflateRect(&rc, -20, -20);
    rc.top = 10;
    rc.bottom = rc.top + lineHeight;

	GetClientRect(&ml);
    InflateRect(&ml, -20, -40);
    ml.top = 10;
    ml.bottom = ml.top + listHeight;

    ATLControls::CStatic header;
    header.Create(m_hWnd, &rc, _T("Це перший діалог із серії. Демонструє елемети управління."));
	 OffsetRect(&rc, 0, lineHeight);
    
	RECT label = rc;
    label.right = 80;

	RECT m_list = ml;
	ml.right = 20;

    ATLControls::CStatic edit_label;
    edit_label.Create(m_hWnd, &label, _T("Edit: "));
	
	OffsetRect(&label, 100, 0);
    ATLControls::CEdit edit;
    edit.Create(m_hWnd, &label, _T("1234"), WS_CHILD | WS_VISIBLE | WS_TABSTOP);

    OffsetRect(&label, 100, 0);
    ATLControls::CButton edit_button;
    edit_button.Create(m_hWnd, &label, _T("Show"), WS_CHILD | WS_VISIBLE | WS_TABSTOP);
    edit_button.SetDlgCtrlID(444);

	OffsetRect(&m_list, 0, 60);
	ATLControls::CListBox list_box;
	list_box.Create(m_hWnd, &m_list, _T("List"), WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | LBS_NOINTEGRALHEIGHT);
	list_box.AddString(L"Item 1");
	list_box.AddString(L"Item 2");
	list_box.AddString(L"Item 3");
	list_box.AddString(L"Item 4");
	list_box.SetCurSel(0);
	
	OffsetRect(&m_list, 0, 80);
	ATLControls::CComboBox combo_box;
	combo_box.Create(m_hWnd, &m_list, _T("Combobox"), WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | WS_VSCROLL);
	combo_box.AddString(L"Item 1");
	combo_box.AddString(L"Item 2");
	combo_box.AddString(L"Item 3");
	combo_box.AddString(L"Item 4");
	combo_box.SetCurSel(0);
	
    OffsetRect(&m_list, 0, 150);
	ATLControls::CScrollBar sb;
	sb.Create(m_hWnd, &m_list, _T("Scroll bar"), WS_CHILD | WS_VISIBLE | 0x0002L);

	OffsetRect(&m_list, 0, 180);
	ATLControls::CStatusBarCtrl stb;
	stb.Create(m_hWnd, &m_list, _T("Status bar"), WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP);
}

 LRESULT  CDlgOne::OnShowEdit(WORD, WORD, HWND, BOOL& )
 {
     MessageBox(_T("Button Show pressed"));
     return 1;
 }