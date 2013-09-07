#pragma once

#include <atlwin.h>
#include "AtlControls.h"

class CDlgOne : public CDialogImpl<CDlgOne> {

public:
   enum { IDD = IDD_DIALOG_ONE };

   BEGIN_MSG_MAP(CDlgOne)
      MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
      MESSAGE_HANDLER(WM_CLOSE, OnClose)

	  COMMAND_ID_HANDLER( IDD_BUTTON_ONE, onButtonClick );
   END_MSG_MAP()

   LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&);
   LRESULT      OnClose(UINT, WPARAM, LPARAM, BOOL&);
   LRESULT   onButtonClick(WORD, WORD, HWND, BOOL& );   


private:

    void InitControls();

	ATLControls::CStatic _label1;
	ATLControls::CButton _button1;
	ATLControls::CEdit   _edit1;

};