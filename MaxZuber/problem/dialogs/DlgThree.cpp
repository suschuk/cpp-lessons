#include "stdafx.h"
#include "DlgThree.h"

extern  HINSTANCE g_hInst;


LRESULT CDlgThree::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow();
    InitControls();
    return 1;
}

LRESULT CDlgThree::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
      return EndDialog(0);
}


void CDlgThree::InitControls() {

    const int lineHeight = 30;
    RECT rc;
    
    GetClientRect(&rc);
    InflateRect(&rc, -20, -20);
    rc.top = 10;
    rc.bottom = rc.top + lineHeight;

	INITCOMMONCONTROLSEX icex;           // Structure for control initialization.
	icex.dwICC = ICC_LISTVIEW_CLASSES;
	//InitCommonControlsEx(&icex);
	InitCommonControlsEx(&icex);

	rc.bottom += 150;

	tree.Create(m_hWnd, &rc, 0, TVS_LINESATROOT | TVS_HASBUTTONS | TVS_HASLINES | TVS_INFOTIP | TVS_SHOWSELALWAYS | WS_VISIBLE | WS_CHILD | WS_BORDER | TVS_HASLINES | TVS_FULLROWSELECT);
	 assert(tree.IsWindow());

	 tree.SetDlgCtrlID(IDC_TREEVIEW_ONE);

	ATLControls::CTreeItem item1;
	HIMAGELIST hLrg = 0;
	HIMAGELIST hSml = 0;
	GetSystemImageLists(&hLrg, &hSml);
	ATLControls::CImageList img_lst(hLrg);

	tree.SetImageList(img_lst, TVSIL_NORMAL);

	ATLControls::CTreeItem root = tree.GetRootItem();
	int count = img_lst.GetImageCount();
	 std::wostringstream wss;
	 wss.str(L"");
	 wss << L"level 0, item " << 1;
	ATLControls::CTreeItem item = root.AddTail(wss.str().c_str(), count / 2);
	
	ATLControls::CTreeItem subitem = item.AddTail(wss.str().c_str(), count /3);
	subitem.AddTail(_T("tail"), 5);

	ATLControls::CTreeItem subitem1 = subitem.AddTail(wss.str().c_str(), count /4);
	subitem1.AddHead(_T("Head"), 5);

	//tree.DeleteItem(subitem1);

};


	LRESULT   CDlgThree::onDBClick(int wParam, LPNMHDR lParam, BOOL& b)
	{
		tree.DeleteItem(tree.GetSelectedItem());
		return 1;
	}

		LRESULT   CDlgThree::onDrag(int wParam, LPNMHDR lParam, BOOL& b)
		{
			MessageBox(L"start Draging");		
			return 1;
		}
		LRESULT   CDlgThree::onSelChange(int wParam, LPNMHDR lParam, BOOL&b)
		{
			MessageBox(L"select changed");
			return 1;
		}
