#include "stdafx.h"
#include "DlgOne.h"


LRESULT CDlgOne::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow();
    return 1;
}

LRESULT CDlgOne::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
      return EndDialog(0);
}