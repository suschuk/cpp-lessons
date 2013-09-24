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

	int cxChar;     // средняя ширина символа
	int yStep;      // высота (шаг) строки
	int lineLenMax; // максимальная длина строки

	SCROLLINFO vsi; // вертикальный скроллинг
	int vertRange;  // диапазон вертикальной полосы прокрутки
	SCROLLINFO hsi; // горизонтальный скроллинг
	int horzRange;  // диапазон горизонтальной полосы прокрутки

private:
	vector<string> lines; // вектор для хранения строк документа
};

