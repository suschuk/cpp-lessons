#pragma once

#include <commctrl.h>
#include <atlwin.h>


namespace ATLControls {
/////////////////////////////////////////////////////////////////////////////
// Forward declarations

template <class Base> class CStaticT;

/////////////////////////////////////////////////////////////////////////////
// CStatic - client side for a Windows STATIC control

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




} //namespace ATL