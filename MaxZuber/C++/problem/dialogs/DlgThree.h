#pragma once

#include <atlwin.h>
#include "HIMLAPI.h"

class CDlgThree : public CDialogImpl<CDlgThree> {

public:
	enum { IDD = IDD_DIALOG_ONE };

	BEGIN_MSG_MAP(CDlgThree)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		NOTIFY_HANDLER(IDC_TREEVIEW_ONE, NM_DBLCLK , onDBClick);
		NOTIFY_HANDLER(IDC_TREEVIEW_ONE, TVN_BEGINDRAG, onDrag);
		NOTIFY_HANDLER(IDC_TREEVIEW_ONE, TVN_SELCHANGED, onSelChange);

		
	END_MSG_MAP()

	LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT      OnClose(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT   OnShowEdit(WORD, WORD, HWND, BOOL& );
	LRESULT   onDBClick(int, LPNMHDR, BOOL&);
	LRESULT   onDrag(int, LPNMHDR, BOOL&);
	LRESULT   onSelChange(int, LPNMHDR, BOOL&);
private:
	ATLControls::CTreeViewCtrlEx tree;
	ATLControls::CListViewCtrl lst_view;
	ATLControls::CComboBox cbox;

	void InitControls();

};