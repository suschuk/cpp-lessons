#pragma once

void OnPaint(HWND);
void OnDestroy(HWND);
void OnLButtonDown(HWND, BOOL, int, int, UINT);
void OnLButtonUp(HWND, int, int, UINT);

namespace myNS
{
	static std::vector<RECT> rects;
	static RECT currentRect;
}