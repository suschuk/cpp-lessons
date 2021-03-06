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

	int cxChar;     // ������ ������ �������
	int yStep;      // ������ ������
	int lineLenMax; // ����������� ������� ������

	SCROLLINFO vsi; // ������� vert
	int vertRange;  // ������� ����. ������ ���������
	SCROLLINFO hsi; // ������� horz
	int horzRange;  // ������� ���. ������ ���������

private:
	vector<wstring> lines; // ������ ��� ��������� ����� ���������
};

