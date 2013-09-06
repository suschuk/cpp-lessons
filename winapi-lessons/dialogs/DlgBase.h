#pragma once

#include <atlwin.h>
#include "AtlControls.h"

namespace UI = ATLControls;

class CDlgBase : public CDialogImpl<CDlgBase> {

public:

   enum { IDD = IDD_DIALOG_ONE };

   BEGIN_MSG_MAP(CDlgBase)
      MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
      MESSAGE_HANDLER(WM_CLOSE, OnClose)
      COMMAND_ID_HANDLER(IDOK, OnOk)
      COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
   END_MSG_MAP()

   LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&);
   LRESULT      OnClose(UINT, WPARAM, LPARAM, BOOL&);
   LRESULT         OnOk(WORD, WORD, HWND, BOOL&);
   LRESULT     OnCancel(WORD, WORD, HWND, BOOL&);

protected:

    virtual void processOk() = 0;
    virtual void InitControls() = 0;

protected:

    UI::CButton ok;
    UI::CButton cancel;

};