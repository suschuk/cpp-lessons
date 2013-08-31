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

} //namespace ATL