#pragma once

#include "DlgBase.h"

class CDlgTwo : public CDlgBase {

public:

   BEGIN_MSG_MAP(CDlgTwo)

      NOTIFY_HANDLER(IDC_TREEVIEW_ONE, NM_CLICK, OnNMClickTree)
      NOTIFY_HANDLER(IDC_TREEVIEW_ONE, TVN_GETINFOTIP, OnInfoTipTree)

      CHAIN_MSG_MAP(CDlgBase)

   END_MSG_MAP()

public:

     LRESULT OnNMClickTree(int, LPNMHDR, BOOL&);
     LRESULT OnInfoTipTree(int, LPNMHDR, BOOL&);

private:

    void processOk();
    void InitControls();

private:

    ATLControls::CTreeViewCtrlEx tree;

};