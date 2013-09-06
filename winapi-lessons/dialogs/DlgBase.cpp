#include "stdafx.h"
#include "DlgBase.h"

LRESULT CDlgBase::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {

    CenterWindow();

    CRect rc;
    
    GetClientRect(&rc);
    InflateRect(&rc, -HORIZONTAL_GAP, -VERTICAL_GAP);
    rc.top = rc.bottom - BUTTON_HEIGHT;
    rc.left = rc.right - BUTTON_WIDTH;

    ok.Create(m_hWnd, &rc, _T("ok"), WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER);
    ok.SetDlgCtrlID(IDOK);
    ok.SetFocus();
   
    rc.OffsetRect( -(HORIZONTAL_GAP + BUTTON_WIDTH), 0);
    cancel.Create(m_hWnd, &rc, _T("cancel"), WS_CHILD | WS_BORDER | WS_TABSTOP | WS_VISIBLE);
    cancel.SetDlgCtrlID(IDCANCEL);


    InitControls();

    return 1;
}

LRESULT CDlgBase::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
      return EndDialog(0);
}


LRESULT CDlgBase::OnOk(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {

    assert(wID == IDOK);

    processOk();

    EndDialog(0);

    return 0;
}

LRESULT CDlgBase::OnCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled) {

    assert(wID == IDCANCEL);

    EndDialog(1);

    return 0;
}

void CDlgBase::processOk() {

    MessageBox(_T("CDlgBase::processOk()"));

}