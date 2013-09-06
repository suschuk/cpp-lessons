#pragma once

#include "DlgBase.h"

class CDlgOne : public CDlgBase {

public:

   BEGIN_MSG_MAP(CDlgOne)
      CHAIN_MSG_MAP(CDlgBase)
   END_MSG_MAP()

   LRESULT   OnShowEdit(WORD, WORD, HWND, BOOL& );

private:

    void processOk();
    void InitControls();

};