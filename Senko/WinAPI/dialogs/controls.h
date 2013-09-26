#pragma once

#include <commctrl.h>
#include <atlwin.h>


namespace ATLControls {

/////////////////////////////////////////////////////////////////////////////
// CStatic - client side for a Windows STATIC control

template <class Base> class CStaticT;

template <class Base>
class CStaticT : public Base
{
public:
// Constructors
    CStaticT(HWND hWnd = NULL) : Base(hWnd) { }

    CStaticT< Base >& operator=(HWND hWnd)
    {
        m_hWnd = hWnd;
        return *this;
    }

    HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_TABSTOP, DWORD dwExStyle = 0,
            UINT nID = 0, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
    }
    HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_TABSTOP, DWORD dwExStyle = 0,
            HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
    }

// Attributes
    static LPCTSTR GetWndClassName()
    {
        return _T("STATIC");
    }

    HICON SetIcon(HICON hIcon)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HICON)::SendMessage(m_hWnd, STM_SETICON, (WPARAM)hIcon, 0L);
    }
    HICON GetIcon() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HICON)::SendMessage(m_hWnd, STM_GETICON, 0, 0L);
    }

    HENHMETAFILE SetEnhMetaFile(HENHMETAFILE hMetaFile)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HENHMETAFILE)::SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_ENHMETAFILE, (LPARAM)hMetaFile);
    }
    HENHMETAFILE GetEnhMetaFile() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HENHMETAFILE)::SendMessage(m_hWnd, STM_GETIMAGE, IMAGE_ENHMETAFILE, 0L);
    }
    HBITMAP SetBitmap(HBITMAP hBitmap)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HBITMAP)::SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
    }
    HBITMAP GetBitmap() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HBITMAP)::SendMessage(m_hWnd, STM_GETIMAGE, IMAGE_BITMAP, 0L);
    }
    HCURSOR SetCursor(HCURSOR hCursor)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HCURSOR)::SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_CURSOR, (LPARAM)hCursor);
    }
    HCURSOR GetCursor()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HCURSOR)::SendMessage(m_hWnd, STM_GETIMAGE, IMAGE_CURSOR, 0L);
    }
};

typedef CStaticT<CWindow>   CStatic;

/////////////////////////////////////////////////////////////////////////////
// CEdit - client side for a Windows EDIT control

template <class Base> class CEditT;

template <class Base>
class CEditT : public Base
{
public:
// Constructors
    CEditT(HWND hWnd = NULL) : Base(hWnd) { }

    CEditT< Base >& operator=(HWND hWnd)
    {
        m_hWnd = hWnd;
        return *this;
    }

    HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            UINT nID = 0, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
    }
    HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
    }

// Attributes
    static LPCTSTR GetWndClassName()
    {
        return _T("EDIT");
    }

    BOOL CanUndo() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_CANUNDO, 0, 0L);
    }
    int GetLineCount() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_GETLINECOUNT, 0, 0L);
    }
    BOOL GetModify() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_GETMODIFY, 0, 0L);
    }
    void SetModify(BOOL bModified = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETMODIFY, bModified, 0L);
    }
    void GetRect(LPRECT lpRect) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_GETRECT, 0, (LPARAM)lpRect);
    }
    DWORD GetSel() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::SendMessage(m_hWnd, EM_GETSEL, 0, 0L);
    }
    void GetSel(int& nStartChar, int& nEndChar) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&nStartChar, (LPARAM)&nEndChar);
    }
    HLOCAL GetHandle() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HLOCAL)::SendMessage(m_hWnd, EM_GETHANDLE, 0, 0L);
    }
    void SetHandle(HLOCAL hBuffer)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETHANDLE, (WPARAM)hBuffer, 0L);
    }
    void SetMargins(UINT nLeft, UINT nRight)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETMARGINS, EC_LEFTMARGIN|EC_RIGHTMARGIN, MAKELONG(nLeft, nRight));
    }
    DWORD GetMargins() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (DWORD)::SendMessage(m_hWnd, EM_GETMARGINS, 0, 0L);
    }
    void SetLimitText(UINT nMax)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETLIMITTEXT, nMax, 0L);
    }
    UINT GetLimitText() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (UINT)::SendMessage(m_hWnd, EM_GETLIMITTEXT, 0, 0L);
    }
    POINT PosFromChar(UINT nChar) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        POINT point;
        ::SendMessage(m_hWnd, EM_POSFROMCHAR, (WPARAM)&point, (LPARAM)nChar);
        return point;
    }
    int CharFromPos(POINT pt) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_CHARFROMPOS, 0, MAKELPARAM(pt.x, pt.y));
    }

    // NOTE: first word in lpszBuffer must contain the size of the buffer!
    int GetLine(int nIndex, LPTSTR lpszBuffer) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
    }
    int GetLine(int nIndex, LPTSTR lpszBuffer, int nMaxLength) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        *(LPWORD)lpszBuffer = (WORD)nMaxLength;
        return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
    }

// Operations
    void EmptyUndoBuffer()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_EMPTYUNDOBUFFER, 0, 0L);
    }
    BOOL FmtLines(BOOL bAddEOL)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_FMTLINES, bAddEOL, 0L);
    }
    void LimitText(int nChars = 0)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_LIMITTEXT, nChars, 0L);
    }
    int LineFromChar(int nIndex = -1) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_LINEFROMCHAR, nIndex, 0L);
    }
    int LineIndex(int nLine = -1) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_LINEINDEX, nLine, 0L);
    }
    int LineLength(int nLine = -1) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_LINELENGTH, nLine, 0L);
    }
    void LineScroll(int nLines, int nChars = 0)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_LINESCROLL, nChars, nLines);
    }
    void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_REPLACESEL, (WPARAM) bCanUndo, (LPARAM)lpszNewText);
    }
    void SetPasswordChar(TCHAR ch)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETPASSWORDCHAR, ch, 0L);
    }
    void SetRect(LPCRECT lpRect)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETRECT, 0, (LPARAM)lpRect);
    }
    void SetRectNP(LPCRECT lpRect)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETRECTNP, 0, (LPARAM)lpRect);
    }
    void SetSel(DWORD dwSelection, BOOL bNoScroll = FALSE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETSEL, LOWORD(dwSelection), HIWORD(dwSelection));
        if(!bNoScroll)
            ::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0L);
    }
    void SetSel(int nStartChar, int nEndChar, BOOL bNoScroll = FALSE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETSEL, nStartChar, nEndChar);
        if(!bNoScroll)
            ::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0L);
    }
    BOOL SetTabStops(int nTabStops, LPINT rgTabStops)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_SETTABSTOPS, nTabStops, (LPARAM)rgTabStops);
    }
    BOOL SetTabStops()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::SendMessage(m_hWnd, EM_SETTABSTOPS, 0, 0L);
    }
    BOOL SetTabStops(const int& cxEachStop)    // takes an 'int'
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_SETTABSTOPS, 1, (LPARAM)(LPINT)&cxEachStop);
    }

    // Additional operations
    void ScrollCaret()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0L);
    }
    void InsertText(int nInsertAfterChar, LPCTSTR lpstrText, BOOL bNoScroll = FALSE, BOOL bCanUndo = FALSE)
    {
        SetSel(nInsertAfterChar, nInsertAfterChar, bNoScroll);
        ReplaceSel(lpstrText, bCanUndo);
    }
    void AppendText(LPCTSTR lpstrText, BOOL bNoScroll = FALSE, BOOL bCanUndo = FALSE)
    {
        InsertText(GetWindowTextLength(), lpstrText, bNoScroll, bCanUndo);
    }

    // Clipboard operations
    BOOL Undo()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_UNDO, 0, 0L);
    }
    void Clear()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_CLEAR, 0, 0L);
    }
    void Copy()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_COPY, 0, 0L);
    }
    void Cut()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_CUT, 0, 0L);
    }
    void Paste()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_PASTE, 0, 0L);
    }

    BOOL SetReadOnly(BOOL bReadOnly = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_SETREADONLY, bReadOnly, 0L);
    }
    int GetFirstVisibleLine() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_GETFIRSTVISIBLELINE, 0, 0L);
    }
    TCHAR GetPasswordChar() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (TCHAR)::SendMessage(m_hWnd, EM_GETPASSWORDCHAR, 0, 0L);
    }
};

typedef CEditT<CWindow>     CEdit;

/////////////////////////////////////////////////////////////////////////////
// CButton - client side for a Windows BUTTON control

template <class Base> class CButtonT;

template <class Base>
class CButtonT : public Base
{
public:
// Constructors
    CButtonT(HWND hWnd = NULL) : Base(hWnd) { }

    CButtonT< Base >& operator=(HWND hWnd)
    {
        m_hWnd = hWnd;
        return *this;
    }

    HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            UINT nID = 0, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
    }
    HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
    }

// Attributes
    static LPCTSTR GetWndClassName()
    {
        return _T("BUTTON");
    }

    UINT GetState() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (UINT)::SendMessage(m_hWnd, BM_GETSTATE, 0, 0L);
    }
    void SetState(BOOL bHighlight)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, BM_SETSTATE, bHighlight, 0L);
    }
    int GetCheck() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, BM_GETCHECK, 0, 0L);
    }
    void SetCheck(int nCheck)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, BM_SETCHECK, nCheck, 0L);
    }
    UINT GetButtonStyle() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (UINT)::GetWindowLong(m_hWnd, GWL_STYLE) & 0xff;
    }
    void SetButtonStyle(UINT nStyle, BOOL bRedraw = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, BM_SETSTYLE, nStyle, (LPARAM)bRedraw);
    }

    HICON SetIcon(HICON hIcon)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HICON)::SendMessage(m_hWnd, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon);
    }
    HICON GetIcon() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HICON)::SendMessage(m_hWnd, BM_GETIMAGE, IMAGE_ICON, 0L);
    }
    HBITMAP SetBitmap(HBITMAP hBitmap)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HBITMAP)::SendMessage(m_hWnd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
    }
    HBITMAP GetBitmap() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HBITMAP)::SendMessage(m_hWnd, BM_GETIMAGE, IMAGE_BITMAP, 0L);
    }
    HCURSOR SetCursor(HCURSOR hCursor)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HCURSOR)::SendMessage(m_hWnd, BM_SETIMAGE, IMAGE_CURSOR, (LPARAM)hCursor);
    }
    HCURSOR GetCursor()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (HCURSOR)::SendMessage(m_hWnd, BM_GETIMAGE, IMAGE_CURSOR, 0L);
    }
};

typedef CButtonT<CWindow>   CButton;

/////////////////////////////////////////////////////////////////////////////
// CListBoxT - client side for a Windows ListBox control

template <class Base>
class CListBoxT : public Base
{
public:
// Constructors
    CListBoxT(HWND hWnd = NULL) : Base(hWnd) { }

    CListBoxT< Base >& operator=(HWND hWnd)
    {
        m_hWnd = hWnd;
        return *this;
    }

    HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            UINT nID = 0, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
    }
    HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
    }

// Attributes
    static LPCTSTR GetWndClassName()
    {
        return _T("LISTBOX");
    }

    // for entire listbox
    int GetCount() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETCOUNT, 0, 0L);
    }
    int GetHorizontalExtent() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETHORIZONTALEXTENT, 0, 0L);
    }
    void SetHorizontalExtent(int cxExtent)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, LB_SETHORIZONTALEXTENT, cxExtent, 0L);
    }
    int GetTopIndex() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETTOPINDEX, 0, 0L);
    }
    int SetTopIndex(int nIndex)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_SETTOPINDEX, nIndex, 0L);
    }
    LCID GetLocale() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (LCID)::SendMessage(m_hWnd, LB_GETLOCALE, 0, 0L);
    }
    LCID SetLocale(LCID nNewLocale)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (LCID)::SendMessage(m_hWnd, LB_SETLOCALE, (WPARAM)nNewLocale, 0L);
    }
    int InitStorage(int nItems, UINT nBytes)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_INITSTORAGE, (WPARAM)nItems, nBytes);
    }
    UINT ItemFromPoint(POINT pt, BOOL& bOutside) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        DWORD dw = (DWORD)::SendMessage(m_hWnd, LB_ITEMFROMPOINT, 0, MAKELPARAM(pt.x, pt.y));
        bOutside = !!HIWORD(dw);
        return LOWORD(dw);
    }

    // for single-selection listboxes
    int GetCurSel() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(!(GetStyle() & LBS_MULTIPLESEL));
        return (int)::SendMessage(m_hWnd, LB_GETCURSEL, 0, 0L);
    }
    int SetCurSel(int nSelect)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(!(GetStyle() & LBS_MULTIPLESEL));
        return (int)::SendMessage(m_hWnd, LB_SETCURSEL, nSelect, 0L);
    }

    // for multiple-selection listboxes
    int GetSel(int nIndex) const           // also works for single-selection
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETSEL, nIndex, 0L);
    }
    int SetSel(int nIndex, BOOL bSelect = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
        return (int)::SendMessage(m_hWnd, LB_SETSEL, bSelect, nIndex);
    }
    int GetSelCount() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
        return (int)::SendMessage(m_hWnd, LB_GETSELCOUNT, 0, 0L);
    }
    int GetSelItems(int nMaxItems, LPINT rgIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
        return (int)::SendMessage(m_hWnd, LB_GETSELITEMS, nMaxItems, (LPARAM)rgIndex);
    }
    void SetAnchorIndex(int nIndex)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
        ::SendMessage(m_hWnd, LB_SETANCHORINDEX, nIndex, 0L);
    }
    int GetAnchorIndex() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
        return (int)::SendMessage(m_hWnd, LB_GETANCHORINDEX, 0, 0L);
    }

    // for listbox items
    DWORD_PTR GetItemData(int nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::SendMessage(m_hWnd, LB_GETITEMDATA, nIndex, 0L);
    }
    int SetItemData(int nIndex, DWORD_PTR dwItemData)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_SETITEMDATA, nIndex, (LPARAM)dwItemData);
    }
    void* GetItemDataPtr(int nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (LPVOID)::SendMessage(m_hWnd, LB_GETITEMDATA, nIndex, 0L);
    }
    int SetItemDataPtr(int nIndex, void* pData)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return SetItemData(nIndex, (DWORD_PTR)pData);
    }
    int GetItemRect(int nIndex, LPRECT lpRect) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETITEMRECT, nIndex, (LPARAM)lpRect);
    }
    int GetText(int nIndex, LPTSTR lpszBuffer) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETTEXT, nIndex, (LPARAM)lpszBuffer);
    }
#ifndef _ATL_NO_COM
    BOOL GetTextBSTR(int nIndex, BSTR& bstrText) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(bstrText == NULL);

        int nLen = GetTextLen(nIndex);
        if(nLen == LB_ERR)
            return FALSE;

        LPTSTR lpszText = (LPTSTR)_alloca((nLen + 1) * sizeof(TCHAR));

        if(GetText(nIndex, lpszText) == LB_ERR)
            return FALSE;

        bstrText = ::SysAllocString(CT2OLE(lpszText));
        return (bstrText != NULL) ? TRUE : FALSE;
    }
#endif //!_ATL_NO_COM
    int GetTextLen(int nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETTEXTLEN, nIndex, 0L);
    }

    // Settable only attributes
    void SetColumnWidth(int cxWidth)
    {
        ATLENSURE(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, LB_SETCOLUMNWIDTH, cxWidth, 0L);
    }
    BOOL SetTabStops(int nTabStops, LPINT rgTabStops)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, LB_SETTABSTOPS, nTabStops, (LPARAM)rgTabStops);
    }
    BOOL SetTabStops()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, LB_SETTABSTOPS, 0, 0L);
    }
    BOOL SetTabStops(const int& cxEachStop)    // takes an 'int'
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, LB_SETTABSTOPS, 1, (LPARAM)(LPINT)&cxEachStop);
    }

    int SetItemHeight(int nIndex, UINT cyItemHeight)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_SETITEMHEIGHT, nIndex, MAKELONG(cyItemHeight, 0));
    }
    int GetItemHeight(int nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETITEMHEIGHT, nIndex, 0L);
    }
    int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_FINDSTRINGEXACT, nIndexStart, (LPARAM)lpszFind);
    }
    int GetCaretIndex() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_GETCARETINDEX, 0, 0);
    }
    int SetCaretIndex(int nIndex, BOOL bScroll = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_SETCARETINDEX, nIndex, MAKELONG(bScroll, 0));
    }

// Operations
    // manipulating listbox items
    int AddString(LPCTSTR lpszItem)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_ADDSTRING, 0, (LPARAM)lpszItem);
    }
    int DeleteString(UINT nIndex)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_DELETESTRING, nIndex, 0L);
    }
    int InsertString(int nIndex, LPCTSTR lpszItem)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_INSERTSTRING, nIndex, (LPARAM)lpszItem);
    }
    void ResetContent()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, LB_RESETCONTENT, 0, 0L);
    }
    int Dir(UINT attr, LPCTSTR lpszWildCard)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_DIR, attr, (LPARAM)lpszWildCard);
    }

    // selection helpers
    int FindString(int nStartAfter, LPCTSTR lpszItem) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_FINDSTRING, nStartAfter, (LPARAM)lpszItem);
    }
    int SelectString(int nStartAfter, LPCTSTR lpszItem)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, LB_SELECTSTRING, nStartAfter, (LPARAM)lpszItem);
    }
    int SelItemRange(BOOL bSelect, int nFirstItem, int nLastItem)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return bSelect ? (int)::SendMessage(m_hWnd, LB_SELITEMRANGEEX, nFirstItem, nLastItem) : (int)::SendMessage(m_hWnd, LB_SELITEMRANGEEX, nLastItem, nFirstItem);
    }
};

typedef CListBoxT<CWindow>  CListBox;


// CComboBox - client side for a Windows COMBOBOX control

template <class Base>
class CComboBoxT : public Base
{
public:
// Constructors
    CComboBoxT(HWND hWnd = NULL) : Base(hWnd) { }

    CComboBoxT< Base >& operator=(HWND hWnd)
    {
        m_hWnd = hWnd;
        return *this;
    }

    HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            UINT nID = 0, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
    }
    HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
    }

// Attributes
    static LPCTSTR GetWndClassName()
    {
        return _T("COMBOBOX");
    }

    // for entire combo box
    int GetCount() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_GETCOUNT, 0, 0L);
    }
    int GetCurSel() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_GETCURSEL, 0, 0L);
    }
    int SetCurSel(int nSelect)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_SETCURSEL, nSelect, 0L);
    }
    LCID GetLocale() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (LCID)::SendMessage(m_hWnd, CB_GETLOCALE, 0, 0L);
    }
    LCID SetLocale(LCID nNewLocale)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (LCID)::SendMessage(m_hWnd, CB_SETLOCALE, (WPARAM)nNewLocale, 0L);
    }
    int GetTopIndex() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_GETTOPINDEX, 0, 0L);
    }
    int SetTopIndex(int nIndex)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_SETTOPINDEX, nIndex, 0L);
    }
    int InitStorage(int nItems, UINT nBytes)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_INITSTORAGE, (WPARAM)nItems, nBytes);
    }
    void SetHorizontalExtent(UINT nExtent)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, CB_SETHORIZONTALEXTENT, nExtent, 0L);
    }
    UINT GetHorizontalExtent() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (UINT)::SendMessage(m_hWnd, CB_GETHORIZONTALEXTENT, 0, 0L);
    }
    int SetDroppedWidth(UINT nWidth)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_SETDROPPEDWIDTH, nWidth, 0L);
    }
    int GetDroppedWidth() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_GETDROPPEDWIDTH, 0, 0L);
    }

    // for edit control
    DWORD GetEditSel() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::SendMessage(m_hWnd, CB_GETEDITSEL, 0, 0L);
    }
    BOOL LimitText(int nMaxChars)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, CB_LIMITTEXT, nMaxChars, 0L);
    }
    BOOL SetEditSel(int nStartChar, int nEndChar)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, CB_SETEDITSEL, 0, MAKELONG(nStartChar, nEndChar));
    }

    // for combobox item
    DWORD_PTR GetItemData(int nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::SendMessage(m_hWnd, CB_GETITEMDATA, nIndex, 0L);
    }
    int SetItemData(int nIndex, DWORD_PTR dwItemData)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_SETITEMDATA, nIndex, (LPARAM)dwItemData);
    }
    void* GetItemDataPtr(int nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (LPVOID)GetItemData(nIndex);
    }
    int SetItemDataPtr(int nIndex, void* pData)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return SetItemData(nIndex, (DWORD_PTR)pData);
    }
    int GetLBText(int nIndex, LPTSTR lpszText) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_GETLBTEXT, nIndex, (LPARAM)lpszText);
    }
#ifndef _ATL_NO_COM
    BOOL GetLBTextBSTR(int nIndex, BSTR& bstrText) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(bstrText == NULL);

        int nLen = GetLBTextLen(nIndex);
        if(nLen == CB_ERR)
            return FALSE;

        LPTSTR lpszText = (LPTSTR)_alloca((nLen + 1) * sizeof(TCHAR));

        if(GetLBText(nIndex, lpszText) == CB_ERR)
            return FALSE;

        bstrText = ::SysAllocString(CT2OLE(lpszText));
        return (bstrText != NULL) ? TRUE : FALSE;
    }
#endif //!_ATL_NO_COM
    int GetLBTextLen(int nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_GETLBTEXTLEN, nIndex, 0L);
    }

    int SetItemHeight(int nIndex, UINT cyItemHeight)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_SETITEMHEIGHT, nIndex, MAKELONG(cyItemHeight, 0));
    }
    int GetItemHeight(int nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_GETITEMHEIGHT, nIndex, 0L);
    }
    int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_FINDSTRINGEXACT, nIndexStart, (LPARAM)lpszFind);
    }
    int SetExtendedUI(BOOL bExtended = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_SETEXTENDEDUI, bExtended, 0L);
    }
    BOOL GetExtendedUI() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, CB_GETEXTENDEDUI, 0, 0L);
    }
    void GetDroppedControlRect(LPRECT lprect) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, CB_GETDROPPEDCONTROLRECT, 0, (DWORD)lprect);
    }
    BOOL GetDroppedState() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, CB_GETDROPPEDSTATE, 0, 0L);
    }

// Operations
    // for drop-down combo boxes
    void ShowDropDown(BOOL bShowIt = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, CB_SHOWDROPDOWN, bShowIt, 0L);
    }

    // manipulating listbox items
    int AddString(LPCTSTR lpszString)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_ADDSTRING, 0, (LPARAM)lpszString);
    }
    int DeleteString(UINT nIndex)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_DELETESTRING, nIndex, 0L);
    }
    int InsertString(int nIndex, LPCTSTR lpszString)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_INSERTSTRING, nIndex, (LPARAM)lpszString);
    }
    void ResetContent()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, CB_RESETCONTENT, 0, 0L);
    }
    int Dir(UINT attr, LPCTSTR lpszWildCard)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_DIR, attr, (LPARAM)lpszWildCard);
    }

    // selection helpers
    int FindString(int nStartAfter, LPCTSTR lpszString) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_FINDSTRING, nStartAfter, (LPARAM)lpszString);
    }
    int SelectString(int nStartAfter, LPCTSTR lpszString)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, CB_SELECTSTRING, nStartAfter, (LPARAM)lpszString);
    }

    // Clipboard operations
    void Clear()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_CLEAR, 0, 0L);
    }
    void Copy()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_COPY, 0, 0L);
    }
    void Cut()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_CUT, 0, 0L);
    }
    void Paste()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_PASTE, 0, 0L);
    }
};

typedef CComboBoxT<CWindow> CComboBox;

/////////////////////////////////////////////////////////////////////////////
// CScrollBar - client side for a Windows SCROLLBAR control

template <class Base>
class CScrollBarT : public Base
{
public:
// Constructors
    CScrollBarT(HWND hWnd = NULL) : Base(hWnd) { }

    CScrollBarT< Base >& operator=(HWND hWnd)
    {
        m_hWnd = hWnd;
        return *this;
    }

    HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            UINT nID = 0, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
    }
    HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
    }

// Attributes
    static LPCTSTR GetWndClassName()
    {
        return _T("SCROLLBAR");
    }

    int GetScrollPos() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::GetScrollPos(m_hWnd, SB_CTL);
    }
    int SetScrollPos(int nPos, BOOL bRedraw = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::SetScrollPos(m_hWnd, SB_CTL, nPos, bRedraw);
    }
    void GetScrollRange(LPINT lpMinPos, LPINT lpMaxPos) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::GetScrollRange(m_hWnd, SB_CTL, lpMinPos, lpMaxPos);
    }
    void SetScrollRange(int nMinPos, int nMaxPos, BOOL bRedraw = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SetScrollRange(m_hWnd, SB_CTL, nMinPos, nMaxPos, bRedraw);
    }
    void ShowScrollBar(BOOL bShow = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::ShowScrollBar(m_hWnd, SB_CTL, bShow);
    }

    BOOL EnableScrollBar(UINT nArrowFlags = ESB_ENABLE_BOTH)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::EnableScrollBar(m_hWnd, SB_CTL, nArrowFlags);
    }

    BOOL SetScrollInfo(LPSCROLLINFO lpScrollInfo, BOOL bRedraw = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::SetScrollInfo(m_hWnd, SB_CTL, lpScrollInfo, bRedraw);
    }
    BOOL GetScrollInfo(LPSCROLLINFO lpScrollInfo)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return ::GetScrollInfo(m_hWnd, SB_CTL, lpScrollInfo);
    }
    int GetScrollLimit()
    {
        int nMin, nMax;
        ::GetScrollRange(m_hWnd, SB_CTL, &nMin, &nMax);
        SCROLLINFO info;
        info.cbSize = sizeof(SCROLLINFO);
        info.fMask = SIF_PAGE;
        if(::GetScrollInfo(m_hWnd, SB_CTL, &info))
            nMax -= ((info.nPage-1) > 0) ? (info.nPage-1) : 0;

        return nMax;
    }
};

typedef CScrollBarT<CWindow>    CScrollBar;

/////////////////////////////////////////////////////////////////////////////
// CStatusBarCtrl

template <class Base>
class CStatusBarCtrlT : public Base
{
public:
// Constructors
    CStatusBarCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

    CStatusBarCtrlT< Base >& operator=(HWND hWnd)
    {
        m_hWnd = hWnd;
        return *this;
    }

    HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            UINT nID = 0, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
    }
    HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
    }

// Attributes
    static LPCTSTR GetWndClassName()
    {
        return STATUSCLASSNAME;
    }

    BOOL SetText(int nPane, LPCTSTR lpszText, int nType = 0)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(nPane < 256);
        return (BOOL)::SendMessage(m_hWnd, SB_SETTEXT, (nPane | nType), (LPARAM)lpszText);
    }
    int GetText(int nPane, LPSTR lpszText, int* pType = NULL) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(nPane < 256);
        DWORD dw = ::SendMessage(m_hWnd, SB_GETTEXT, (WPARAM)nPane, (LPARAM)lpszText);
        if(pType != NULL)
            *pType = HIWORD(dw);
        return LOWORD(dw);
    }
#ifndef _ATL_NO_COM
    BOOL GetTextBSTR(int nPane, BSTR& bstrText, int* pType = NULL) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(nPane < 256);
        ATLENSURE(bstrText == NULL);
        int nLength = LOWORD(::SendMessage(m_hWnd, SB_GETTEXTLENGTH, (WPARAM)nPane, 0L));
        if(nLength == 0)
            return FALSE;

        LPSTR lpszText = (LPSTR)_alloca((nLength + 1) * sizeof(char));
        if(!GetText(nPane, lpszText, pType))
            return FALSE;

        bstrText = ::SysAllocString(CA2W(lpszText));
        return (bstrText != NULL) ? TRUE : FALSE;
    }
#endif //!_ATL_NO_COM
    int GetTextLength(int nPane, int* pType = NULL) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(nPane < 256);
        DWORD dw = ::SendMessage(m_hWnd, SB_GETTEXTLENGTH, (WPARAM)nPane, 0L);
        if (pType != NULL)
            *pType = HIWORD(dw);
        return LOWORD(dw);
    }
    BOOL SetParts(int nParts, int* pWidths)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, SB_SETPARTS, nParts, (LPARAM)pWidths);
    }
    int GetParts(int nParts, int* pParts) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, SB_GETPARTS, nParts, (LPARAM)pParts);
    }
    BOOL GetBorders(int* pBorders) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, SB_GETBORDERS, 0, (LPARAM)pBorders);
    }
    BOOL GetBorders(int& nHorz, int& nVert, int& nSpacing) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        int borders[3];
        BOOL bResult = (BOOL)::SendMessage(m_hWnd, SB_GETBORDERS, 0, (LPARAM)&borders);
        if (bResult)
        {
            nHorz = borders[0];
            nVert = borders[1];
            nSpacing = borders[2];
        }
        return bResult;
    }
    void SetMinHeight(int nMin)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, SB_SETMINHEIGHT, nMin, 0L);
    }
    BOOL SetSimple(BOOL bSimple = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, SB_SIMPLE, bSimple, 0L);
    }
    BOOL GetRect(int nPane, LPRECT lpRect) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, SB_GETRECT, nPane, (LPARAM)lpRect);
    }

    // new common control support
    BOOL IsSimple() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, SB_ISSIMPLE, 0, 0L);
    }
};

typedef CStatusBarCtrlT<CWindow>    CStatusBarCtrl;

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CRichEditCtrl

#include <richedit.h>
#include <richole.h>

#ifdef _UNICODE
#if (_RICHEDIT_VER == 0x0100)
#undef RICHEDIT_CLASS
#define RICHEDIT_CLASS  L"RICHEDIT"
#endif //(_RICHEDIT_VER == 0x0100)
#endif //_UNICODE

template <class Base>
class CRichEditCtrlT : public Base
{
public:
// Constructors
    CRichEditCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

    CRichEditCtrlT< Base >& operator=(HWND hWnd)
    {
        m_hWnd = hWnd;
        return *this;
    }

    HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            UINT nID = 0, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
    }
    HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
            DWORD dwStyle = 0, DWORD dwExStyle = 0,
            HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
    {
        return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
    }

// Attributes
    static LPCTSTR GetWndClassName()
    {
        return RICHEDIT_CLASS;
    }

    BOOL CanUndo() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_CANUNDO, 0, 0L);
    }
    int GetLineCount() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_GETLINECOUNT, 0, 0L);
    }
    BOOL GetModify() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_GETMODIFY, 0, 0L);
    }
    void SetModify(BOOL bModified = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETMODIFY, bModified, 0L);
    }
    void GetRect(LPRECT lpRect) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_GETRECT, 0, (LPARAM)lpRect);
    }
    POINT GetCharPos(long lChar) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        POINT pt;
        ::SendMessage(m_hWnd, EM_POSFROMCHAR, (WPARAM)&pt, (LPARAM)lChar);
        return pt;
    }
    UINT SetOptions(WORD wOp, DWORD dwFlags)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (UINT)::SendMessage(m_hWnd, EM_SETOPTIONS, (WPARAM)wOp, (LPARAM)dwFlags);
    }

    // NOTE: first word in lpszBuffer must contain the size of the buffer!
    int GetLine(int nIndex, LPTSTR lpszBuffer) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
    }
    int GetLine(int nIndex, LPTSTR lpszBuffer, int nMaxLength) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        *(LPINT)lpszBuffer = nMaxLength;
        return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
    }

    BOOL CanPaste(UINT nFormat = 0) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_CANPASTE, nFormat, 0L);
    }
    void GetSel(long& nStartChar, long& nEndChar) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        CHARRANGE cr;
        ::SendMessage(m_hWnd, EM_EXGETSEL, 0, (LPARAM)&cr);
        nStartChar = cr.cpMin;
        nEndChar = cr.cpMax;
    }
    void GetSel(CHARRANGE &cr) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_EXGETSEL, 0, (LPARAM)&cr);
    }
    void LimitText(long nChars = 0)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_EXLIMITTEXT, 0, nChars);
    }
    long LineFromChar(long nIndex) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, EM_EXLINEFROMCHAR, 0, nIndex);
    }
    int SetSel(long nStartChar, long nEndChar)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        CHARRANGE cr;
        cr.cpMin = nStartChar;
        cr.cpMax = nEndChar;
        return (int)::SendMessage(m_hWnd, EM_EXSETSEL, 0, (LPARAM)&cr);
    }
    int SetSel(CHARRANGE &cr)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_EXSETSEL, 0, (LPARAM)&cr);
    }
    DWORD GetDefaultCharFormat(CHARFORMAT &cf) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        cf.cbSize = sizeof(CHARFORMAT);
        return (DWORD)::SendMessage(m_hWnd, EM_GETCHARFORMAT, 0, (LPARAM)&cf);
    }
    DWORD GetSelectionCharFormat(CHARFORMAT &cf) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        cf.cbSize = sizeof(CHARFORMAT);
        return (DWORD)::SendMessage(m_hWnd, EM_GETCHARFORMAT, 1, (LPARAM)&cf);
    }
    long GetEventMask() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, EM_GETEVENTMASK, 0, 0L);
    }
    long GetLimitText() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, EM_GETLIMITTEXT, 0, 0L);
    }
    DWORD GetParaFormat(PARAFORMAT &pf) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        pf.cbSize = sizeof(PARAFORMAT);
        return (DWORD)::SendMessage(m_hWnd, EM_GETPARAFORMAT, 0, (LPARAM)&pf);
    }
    // richedit EM_GETSELTEXT is ANSI
    long GetSelText(LPSTR lpBuf) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, EM_GETSELTEXT, 0, (LPARAM)lpBuf);
    }
#ifndef _ATL_NO_COM
    BOOL GetSelTextBSTR(BSTR& bstrText) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ATLENSURE(bstrText == NULL);

        CHARRANGE cr;
        cr.cpMin = cr.cpMax = 0;
        ::SendMessage(m_hWnd, EM_EXGETSEL, 0, (LPARAM)&cr);
        LPSTR lpstrText = (char*)_alloca((cr.cpMax - cr.cpMin + 1) * 2);
        lpstrText[0] = 0;
        if(::SendMessage(m_hWnd, EM_GETSELTEXT, 0, (LPARAM)lpstrText) == 0)
            return FALSE;

        bstrText = ::SysAllocString(CA2W(lpstrText));
        return (bstrText != NULL) ? TRUE : FALSE;
    }
#endif //!_ATL_NO_COM
    WORD GetSelectionType() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (WORD)::SendMessage(m_hWnd, EM_SELECTIONTYPE, 0, 0L);
    }
    COLORREF SetBackgroundColor(BOOL bSysColor, COLORREF cr)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (COLORREF)::SendMessage(m_hWnd, EM_SETBKGNDCOLOR, bSysColor, cr);
    }
    BOOL SetDefaultCharFormat(CHARFORMAT &cf)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        cf.cbSize = sizeof(CHARFORMAT);
        return (BOOL)::SendMessage(m_hWnd, EM_SETCHARFORMAT, 0, (LPARAM)&cf);
    }
    BOOL SetSelectionCharFormat(CHARFORMAT &cf)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        cf.cbSize = sizeof(CHARFORMAT);
        return (BOOL)::SendMessage(m_hWnd, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&cf);
    }
    BOOL SetWordCharFormat(CHARFORMAT &cf)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        cf.cbSize = sizeof(CHARFORMAT);
        return (BOOL)::SendMessage(m_hWnd, EM_SETCHARFORMAT, SCF_SELECTION|SCF_WORD, (LPARAM)&cf);
    }
    DWORD SetEventMask(DWORD dwEventMask)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (DWORD)::SendMessage(m_hWnd, EM_SETEVENTMASK, 0, dwEventMask);
    }
    BOOL SetParaFormat(PARAFORMAT &pf)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        pf.cbSize = sizeof(PARAFORMAT);
        return (BOOL)::SendMessage(m_hWnd, EM_SETPARAFORMAT, 0, (LPARAM)&pf);
    }
    BOOL SetTargetDevice(HDC hDC, long lLineWidth)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_SETTARGETDEVICE, (WPARAM)hDC, lLineWidth);
    }
    long GetTextLength() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, WM_GETTEXTLENGTH, 0, 0L);
    }
    BOOL SetReadOnly(BOOL bReadOnly = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_SETREADONLY, bReadOnly, 0L);
    }
    int GetFirstVisibleLine() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_GETFIRSTVISIBLELINE, 0, 0L);
    }

// Operations
    void EmptyUndoBuffer()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_EMPTYUNDOBUFFER, 0, 0L);
    }

    int LineIndex(int nLine = -1) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_LINEINDEX, nLine, 0L);
    }
    int LineLength(int nLine = -1) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (int)::SendMessage(m_hWnd, EM_LINELENGTH, nLine, 0L);
    }
    BOOL LineScroll(int nLines, int nChars = 0)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_LINESCROLL, nChars, nLines);
    }
    void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_REPLACESEL, (WPARAM) bCanUndo, (LPARAM)lpszNewText);
    }
    void SetRect(LPCRECT lpRect)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SETRECT, 0, (LPARAM)lpRect);
    }

    BOOL DisplayBand(LPRECT pDisplayRect)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_DISPLAYBAND, 0, (LPARAM)pDisplayRect);
    }
    long FindText(DWORD dwFlags, FINDTEXTEX* pFindText) const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, EM_FINDTEXTEX, dwFlags, (LPARAM)pFindText);
    }
    long FormatRange(FORMATRANGE* pfr, BOOL bDisplay = TRUE)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, EM_FORMATRANGE, (WPARAM)bDisplay, (LPARAM)pfr);
    }
    void HideSelection(BOOL bHide, BOOL bPerm)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_HIDESELECTION, bHide, bPerm);
    }
    void PasteSpecial(UINT nClipFormat, DWORD dvAspect = 0, HMETAFILE hMF = 0)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        REPASTESPECIAL reps;
        reps.dwAspect = dvAspect;
        reps.dwParam = (DWORD)hMF;
        ::SendMessage(m_hWnd, EM_PASTESPECIAL, nClipFormat, (LPARAM)&reps);
    }
    void RequestResize()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_REQUESTRESIZE, 0, 0L);
    }
    long StreamIn(int nFormat, EDITSTREAM& es)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, EM_STREAMIN, nFormat, (LPARAM)&es);
    }
    long StreamOut(int nFormat, EDITSTREAM& es)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (long)::SendMessage(m_hWnd, EM_STREAMOUT, nFormat, (LPARAM)&es);
    }

    // Additional operations
    void ScrollCaret()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0L);
    }
    int InsertText(long nInsertAfterChar, LPCTSTR lpstrText, BOOL bCanUndo = FALSE)
    {
        int nRet = SetSel(nInsertAfterChar, nInsertAfterChar);
        ReplaceSel(lpstrText, bCanUndo);
        return nRet;
    }
    int AppendText(LPCTSTR lpstrText, BOOL bCanUndo = FALSE)
    {
        return InsertText(GetWindowTextLength(), lpstrText, bCanUndo);
    }

    // Clipboard operations
    BOOL Undo()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_UNDO, 0, 0L);
    }
    void Clear()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_CLEAR, 0, 0L);
    }
    void Copy()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_COPY, 0, 0L);
    }
    void Cut()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_CUT, 0, 0L);
    }
    void Paste()
    {
        ATLENSURE(::IsWindow(m_hWnd));
        ::SendMessage(m_hWnd, WM_PASTE, 0, 0L);
    }

// OLE support
    IRichEditOle* GetIRichEditOle() const
    {
        ATLENSURE(::IsWindow(m_hWnd));
        IRichEditOle *pRichItem = NULL;
        ::SendMessage(m_hWnd, EM_GETOLEINTERFACE, 0, (LPARAM)&pRichItem);
        return pRichItem;
    }
    BOOL SetOLECallback(IRichEditOleCallback* pCallback)
    {
        ATLENSURE(::IsWindow(m_hWnd));
        return (BOOL)::SendMessage(m_hWnd, EM_SETOLECALLBACK, 0, (LPARAM)pCallback);
    }
};

typedef CRichEditCtrlT<CWindow>     CRichEditCtrl;

} //namespace ATL