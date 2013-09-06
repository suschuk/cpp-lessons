#pragma once

#include "DlgBase.h"

class CDlgTwo : public CDlgBase {

public:

   BEGIN_MSG_MAP(CDlgTwo)

      CHAIN_MSG_MAP(CDlgBase)
   END_MSG_MAP()

private:

    void processOk();
    void InitControls();

private:

    ATLControls::CTreeViewCtrlEx tree;

};