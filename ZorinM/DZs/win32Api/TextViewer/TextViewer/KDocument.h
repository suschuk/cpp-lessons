//////////////////////////////////////////////////////////////////////
// KDocument.h
#include <windows.h>
#include <vector>
#include <string>
using namespace std;

class KDocument {
public:
	BOOL Open(const char* file);
	void Initialize(LPTEXTMETRIC tm);
	void ScrollSettings(HWND hwnd, int width, int height);
	void UpdateHscroll(HWND hwnd, int xInc);
	void UpdateVscroll(HWND hwnd, int yInc);
	void PutText(HWND hwnd, HDC hdc);

	int cxChar;     // средня ширина символу
	int yStep;      // висота строки
	int lineLenMax; // максимальна довжина строки

	SCROLLINFO vsi; // скролінг vert
	int vertRange;  // діапазон верт. полоси прокрутки
	SCROLLINFO hsi; // скролінг horz
	int horzRange;  // діапазон гор. полось прокрутки

private:
	vector<string> lines; // вектор для зберігання строк документу
};

