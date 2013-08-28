#pragma once

#include <atlwin.h>

class CDlgOne : public CDialogImpl<CDlgOne> {

public:
   enum { IDD = IDD_DIALOG_ONE };

   BEGIN_MSG_MAP(CDlgOne)
      MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
      MESSAGE_HANDLER(WM_CLOSE, OnClose)
   END_MSG_MAP()

   LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&);
   LRESULT      OnClose(UINT, WPARAM, LPARAM, BOOL&);
};