#include "stdafx.h"
#include "DlgOne.h"

void CDlgOne::InitControls() {

    RECT rc;
    
    GetClientRect(&rc);
    InflateRect(&rc, -20, -20);
    rc.top = 10;
    rc.bottom = rc.top + BUTTON_HEIGHT;
    ATLControls::CStatic header;
    header.Create(m_hWnd, &rc, _T("Це перший діалог із серії. Демонструє елемети управління."));

    OffsetRect(&rc, 0, BUTTON_HEIGHT);
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


}

 LRESULT  CDlgOne::OnShowEdit(WORD, WORD, HWND, BOOL& )
 {
     MessageBox(_T("Button Show pressed"));
     return 1;
 }

 void CDlgOne::processOk() {

    MessageBox(_T("CDlgOne::processOk() "));

}