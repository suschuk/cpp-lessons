#pragma once

#include <atlwin.h>
#include "HIMLAPI.h"

class CDlgTwo : public CDialogImpl<CDlgTwo> {

public:
	enum { IDD = IDD_DIALOG_ONE };

	BEGIN_MSG_MAP(CDlgTwo)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
		COMMAND_ID_HANDLER( 444, OnShowEdit );
		NOTIFY_HANDLER(666, NM_CLICK, OnClick);
	//	COMMAND_ID_HANDLER(555, OnDropBox);
		COMMAND_ID_HANDLER(555, OnSelChange);
	END_MSG_MAP()

	LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT      OnClose(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT   OnShowEdit(WORD, WORD, HWND, BOOL& );

	LRESULT OnClick(int, LPNMHDR, BOOL&);
//	LRESULT   OnDropBox(WORD, WORD, HWND, BOOL& );
	LRESULT   OnSelChange(WORD, WORD, HWND, BOOL& );

private:
	ATLControls::CTreeViewCtrlEx tree;
		ATLControls::CListViewCtrl lst_view;
		ATLControls::CComboBox cbox;

	void InitControls();

};