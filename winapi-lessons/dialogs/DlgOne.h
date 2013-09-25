#pragma once

#include "DlgBase.h"

class CDlgOne : public CDlgBase {

public:

   BEGIN_MSG_MAP(CDlgOne)
       COMMAND_ID_HANDLER(IDC_BUTTON_SHOW, OnShowEdit)
       CHAIN_MSG_MAP(CDlgBase)
   END_MSG_MAP()

   LRESULT   OnShowEdit(WORD, WORD, HWND, BOOL& );

private:

    UI::CEdit edit;

private:

    void processOk();
    void InitControls();

};