#include "stdafx.h"
#include "DlgOne.h"

void CDlgOne::InitControls() {

    RECT rc;
    
    GetClientRect(&rc);
    InflateRect(&rc, -20, -20);
    rc.top = 10;
    rc.bottom = rc.top + BUTTON_HEIGHT;
    UI::CStatic header;
    header.Create(m_hWnd, &rc, _T("Це перший діалог із серії. Демонструє елемети управління."));

    OffsetRect(&rc, 0, BUTTON_HEIGHT);
    RECT label = rc;
    label.right = 80;
    UI::CStatic edit_label;
    edit_label.Create(m_hWnd, &label, _T("Edit: "));

    OffsetRect(&label, 100, 0);
    edit.Create(m_hWnd, &label, _T("1234"), WS_CHILD | WS_VISIBLE | WS_TABSTOP);

    OffsetRect(&label, 100, 0);
    UI::CButton edit_button;
    edit_button.Create(m_hWnd, &label, _T("Show"), WS_CHILD | WS_VISIBLE | WS_TABSTOP);
    edit_button.SetDlgCtrlID(IDC_BUTTON_SHOW);


}

 LRESULT  CDlgOne::OnShowEdit(WORD, WORD, HWND, BOOL& )
 {
     const int msg_size = 256;
     std::vector<wchar_t> vmsg(msg_size);
     edit.GetWindowTextW(&vmsg[0], msg_size);
     std::wstring msg(&vmsg[0]);
     // _T("Button Show pressed")
     MessageBox(msg.c_str());

     std::wofstream wof("file.dat");
     wof << msg.c_str() << std::endl;
     wof.close();

     return 1;
 }

 void CDlgOne::processOk() {

    MessageBox(_T("CDlgOne::processOk() "));

}