//////////////////////////////////////////////////////////////////////
// KDocument.cpp
#include <windows.h>
#include <fstream>
#include "KDocument.h"
#include <tchar.h>

BOOL KDocument::Open(const char* file) {
	ifstream finp(file);
	char buf[200];

	if(!finp.good()) {
		MessageBox(NULL, L"Не найден входной файл", L"Error", MB_OK);
		return FALSE;
	}

	// Прочитать файл, сохранив информацию в векторе строк lines
	while(!finp.eof()) {
		finp.getline(buf, 199);
		buf[199] = 0;
		lines.push_back(string(buf));
	}

	// Вычислить максимальную длину строки
	lineLenMax = 0;
	for (int i = 0; i < (int)lines.size(); ++i) {
		int lineLen = lines[i].size();
		// Корректировка, если строка содержит символы табуляции
		int iTabPos = 0;
		while (1) {
			iTabPos = lines[i].find('\t', iTabPos);
			if (iTabPos != -1) {
				lineLen += 8;
				iTabPos++;
			}
			else  break;
		}
		if (lineLen > lineLenMax)  lineLenMax = lineLen;
	}
	return TRUE;
}

void KDocument::Initialize(LPTEXTMETRIC tm) {
	cxChar = tm->tmAveCharWidth;
	yStep = tm->tmHeight + tm->tmExternalLeading;
	vsi.nMin = vsi.nPos = 0;
	hsi.nMin = hsi.nPos = 0;
}

void KDocument::ScrollSettings(HWND hwnd, int width, int height) {

	// Вертикальный скроллинг
	vsi.cbSize = sizeof(vsi);
	vsi.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
	vsi.nPage = height / yStep - 1;
	vsi.nMax = lines.size() - 1;
	if (vsi.nPage > vsi.nMax)
		vsi.nPos = vsi.nMin;
	vertRange = vsi.nMax - vsi.nMin + 1;
	SetScrollInfo(hwnd, SB_VERT, &vsi, TRUE);

	// Горизонтальный скроллинг
	hsi.cbSize = sizeof(SCROLLINFO);
	hsi.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
	hsi.nPage = width/cxChar - 2;
	hsi.nMax = lineLenMax;
	if (hsi.nPage > hsi.nMax)
		hsi.nPos = hsi.nMin;
	horzRange = hsi.nMax - hsi.nMin + 1;
	SetScrollInfo(hwnd, SB_HORZ, &hsi, TRUE);
}

void KDocument::UpdateVscroll(HWND hwnd, int yInc) {
	// ограничение на положительное приращение
	yInc = min(yInc, vertRange - (int)vsi.nPage - vsi.nPos);
	// ограничение на отрицательное приращение
	yInc = max(yInc, vsi.nMin - vsi.nPos);

	if (yInc) {
		ScrollWindow(hwnd, 0, -yStep * yInc, NULL, NULL); 
		vsi.nPos += yInc;
		SetScrollInfo(hwnd, SB_VERT, &vsi, TRUE);
		InvalidateRect(hwnd, NULL, TRUE);
		UpdateWindow (hwnd); 
	} 
}

void KDocument::UpdateHscroll(HWND hwnd, int xInc) {
	// ограничение на положительное приращение
	xInc = min(xInc, horzRange - (int)hsi.nPage - hsi.nPos);
	// ограничение на отрицательное приращение
	xInc = max(xInc, hsi.nMin - hsi.nPos);

	if (xInc) {
		ScrollWindow(hwnd, -cxChar * xInc, 0, NULL, NULL); 
		hsi.nPos += xInc;
		SetScrollInfo(hwnd, SB_HORZ, &hsi, TRUE);
		InvalidateRect(hwnd, NULL, TRUE);
		UpdateWindow (hwnd); 
	} 
}

void KDocument::PutText(HWND hwnd, HDC hdc) {

	RECT rect;
	GetClientRect(hwnd, &rect);
	rect.left += cxChar;
	rect.right -= cxChar;
	HRGN hRgn = CreateRectRgnIndirect(&rect);
	SelectClipRgn(hdc, hRgn);

	int x = cxChar * (hsi.nMin - hsi.nPos + 1);
	int y = yStep;

	int amountLines = lines.size();
	int iBeg = vsi.nPos;
	int iEnd = (vsi.nPos+vsi.nPage < amountLines)? vsi.nPos+vsi.nPage : amountLines;
	for (int i = iBeg; i < iEnd; ++i) {
		int iTabPos = lines[i].find('\t');
		if (-1 == iTabPos)
		{
			TextOut(hdc, x, y, (LPWSTR)(lines[i].c_str()), lines[i].size());
		}
		else
		{
			TabbedTextOut(hdc, x, y, (LPWSTR)lines[i].c_str(), lines[i].size(), 0, 0, x);
		}
		y += yStep;
	}
	SelectClipRgn(hdc, NULL);
}

