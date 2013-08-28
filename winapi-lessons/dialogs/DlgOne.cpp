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
    header.Create(m_hWnd, &rc, _T("Це перший діалог із серії. Демонструє елемети управління."), WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP);

}