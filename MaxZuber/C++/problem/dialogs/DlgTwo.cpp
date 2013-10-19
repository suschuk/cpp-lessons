#include "stdafx.h"
#include "DlgTwo.h"





extern  HINSTANCE g_hInst;



LRESULT CDlgTwo::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
    CenterWindow();
    InitControls();
    return 1;
}

LRESULT CDlgTwo::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled) {
      return EndDialog(0);
}


void CDlgTwo::InitControls() {

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

	
	lst_view.Create(m_hWnd, &rc, _T("lst_view1"), WS_CHILD | WS_VISIBLE | WS_TABSTOP| WS_BORDER | LVS_REPORT);
	lst_view.SetDlgCtrlID(666);
	WCHAR szText[256] =  (L"hihihi");     // Temporary buffer.
	LVCOLUMN lvc;
	int iCol;

	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM ;

	// Add the columns.
	int col = 5;
	int colsize = (rc.right- rc.left) / 5;
	for (iCol = 0; iCol < col; iCol++)
	{
		// Load the names of the column headings from the string resources.
		LoadString(g_hInst,
			IDS_FIRSTCOLUMN + iCol,
			szText,
			sizeof(szText)/sizeof(szText[0]));

		// Insert the columns into the list view.
		lst_view.AddColumn(szText, iCol,-1,lvc.mask, LVCFMT_CENTER);
		lst_view.SetColumnWidth(iCol,colsize);

	}
	/*HIMAGELIST hLrg = 0;
	HIMAGELIST hSml = 0;
	GetSystemImageLists(&hLrg, &hSml);*/


	HIMAGELIST* hSml;

	Singleton* sImg = Singleton::getInctance();

	hSml = sImg->getSml();
	ATLControls::CImageList img_lst(*hSml);

	lst_view.SetImageList(*hSml, LVSIL_SMALL);
	int cItems = 5;

	lst_view.SetTextColor(0x00FF0000);
	lst_view.SetTextBkColor(0x00BCAFAA);
	for (int index = 0; index < cItems; index++)
	{
		LoadString(g_hInst,
			IDS_FIRSTCOLUMN + index,
			szText,
			sizeof(szText)/sizeof(szText[0]));

		// Insert items into the list.
		lst_view.AddItem(index, 0, szText, index);
		
	}
	for (int index = 0; index < cItems; index++)
	{
		LoadString(g_hInst,
			IDS_FIRSTCOLUMN + index,
			szText,
			sizeof(szText)/sizeof(szText[0]));
		// Insert items into the list.

		lst_view.AddItem(index, 1, szText);
	}

	for (int index = 0; index < cItems; index++)
	{
		LoadString(g_hInst,
			IDS_FIRSTCOLUMN + index,
			szText,
			sizeof(szText)/sizeof(szText[0]));

		// Insert items into the list.

		lst_view.AddItem(index, 2, szText);
		
	}

	for (int index = 0; index < cItems; index++)
	{
		LoadString(g_hInst,
			IDS_FIRSTCOLUMN + index,
			szText,
			sizeof(szText)/sizeof(szText[0]));

		// Insert items into the list.

		lst_view.AddItem(index, 3 , szText);
	}
		//lst_view.SetTextColor(0x00561234);
	for (int index = 0; index < cItems; index++)
	{
		LoadString(g_hInst,
			IDS_FIRSTCOLUMN + index,
			szText,
			sizeof(szText)/sizeof(szText[0]));

		// Insert items into the list.

		lst_view.AddItem(index, 4 , szText);
	}
	
	lst_view.SetHotItem(2);
	lst_view.SetItemText(0,2, L"NEW TEXT");

	/*
	tree.Create(m_hWnd, &rc, 0, TVS_LINESATROOT | TVS_HASBUTTONS | TVS_HASLINES | TVS_INFOTIP | TVS_SHOWSELALWAYS | WS_VISIBLE | WS_CHILD | WS_BORDER | TVS_HASLINES);
	 assert(tree.IsWindow());

	ATLControls::CTreeItem item1;
	HIMAGELIST hLrg = 0;
	HIMAGELIST hSml = 0;
	GetSystemImageLists(&hLrg, &hSml);
	tree.SetDlgCtrlID(IDC_TREEVIEW_ONE);
	ATLControls::CImageList img_lst(hSml);

	tree.SetImageList(img_lst, TVSIL_NORMAL);

	ATLControls::CTreeItem root = tree.GetRootItem();
	int count = img_lst.GetImageCount();
	 std::wostringstream wss;
	 wss.str(L"");
	 wss << L"level 0, item " << 1;
	ATLControls::CTreeItem item = root.AddTail(wss.str().c_str(), count);
	
	ATLControls::CTreeItem subitem = item.AddTail(wss.str().c_str(), count);
	subitem.AddTail(_T("tail"), 5);
	*/
	InflateRect(&rc, -150, -200);
	rc.bottom +=300;
	cbox.Create(m_hWnd, &rc, _T("cmbbox"), WS_VISIBLE| WS_CHILD | CBS_DROPDOWNLIST | WS_TABSTOP | WS_VSCROLL );
	cbox.AddString(_T("one"));
	cbox.AddString(_T("two"));
	cbox.AddString(_T("thre"));
	cbox.AddString(_T("thre"));
	cbox.SetCurSel(3);
	cbox.SetDlgCtrlID(555);

};


/*LRESULT   CDlgTwo::OnDropBox(WORD hi , WORD lo , HWND lParam, BOOL& b)
{
	int select = -1;
	LONG lStyle = 0 ;
	switch(hi)
	{
	case CBN_CLOSEUP:
		select = cbox.GetCurSel();
		switch(select)
		{
		case 0:
			lStyle = lst_view.GetWindowLongW(GWL_STYLE);
			lStyle &= ~LVS_REPORT;
			lStyle |= LVS_LIST;
			lst_view.SetWindowLong(GWL_STYLE, lStyle);
			break;
		case 1:
			lStyle = lst_view.GetWindowLongW(GWL_STYLE);
			lStyle &= ~LVS_LIST;
			lStyle |= LVS_REPORT;
			lst_view.SetWindowLong(GWL_STYLE, lStyle);
			break;
		case 2:
			lStyle = lst_view.GetWindowLongW(GWL_STYLE);
			lStyle &= ~LVS_REPORT;
			lStyle |= LVS_ICON;
			lst_view.SetWindowLong(GWL_STYLE, lStyle);
			break;
		default:
			break;
		}
	}

	return 1;
}
*/
LRESULT   CDlgTwo::OnSelChange(WORD hi , WORD lo , HWND lParam, BOOL& b)
{
	int select = -1;
	LONG lStyle = 0 ;
	switch(hi)
	{
	case CBN_CLOSEUP:
		select = cbox.GetCurSel();
		switch(select)
		{
		case 0:
			lStyle = lst_view.GetWindowLongW(GWL_STYLE);
			lStyle &= ~LVS_REPORT;
			lStyle |= LVS_LIST;
			lst_view.SetWindowLong(GWL_STYLE, lStyle);
			break;
		case 1:
			lStyle = lst_view.GetWindowLongW(GWL_STYLE);
			lStyle &= ~LVS_LIST;
			lStyle |= LVS_REPORT;
			lst_view.SetWindowLong(GWL_STYLE, lStyle);
			break;
		case 2:
			lStyle = lst_view.GetWindowLongW(GWL_STYLE);
			lStyle &= ~LVS_REPORT;
			lStyle |= LVS_ICON;
			lst_view.SetWindowLong(GWL_STYLE, lStyle);
			break;
		default:
			break;
		}
	}

	return 1;
}



 LRESULT  CDlgTwo::OnShowEdit(WORD, WORD, HWND, BOOL& )
 {
     MessageBox(_T("Button Show pressed"));
     return 1;
 }

 	LRESULT CDlgTwo::OnClick(int wParam, LPNMHDR lpmhdr, BOOL& bol)
	{
		TCHAR buf[32];
		wsprintf(buf, L"%i",wParam);
		//MessageBox(buf, L"Sd", MB_OK);
		LONG lStyle = lst_view.GetWindowLongW(GWL_STYLE);
		lStyle &= ~LVS_REPORT;
		lStyle |= LVS_LIST;
		//lst_view.SetWindowLong(GWL_STYLE, lStyle);
		return 1;
	}