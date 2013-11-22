#pragma once
#include <atlbase.h>
#include <atlwin.h>
#include <Windows.h>
#include "resource6.h"

class ScoreDialog: public CDialogImpl<ScoreDialog>
{
public:
	enum {IDD = IDD_DIALOG_ONE};

	BEGIN_MSG_MAP(ScoreDialog)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_CLOSE, OnClose)
	END_MSG_MAP()


	LRESULT OnInitDialog(UINT, WPARAM, LPARAM, BOOL&);
	LRESULT      OnClose(UINT, WPARAM, LPARAM, BOOL&);

private:
	   void InitControls();
};