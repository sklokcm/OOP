#include "module2.h"
#include "resource2.h"

static INT_PTR CALLBACK Step1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	if (iMessage == WM_COMMAND) {
		if (LOWORD(wParam) == IDNEXT) { EndDialog(hDlg, 1); return TRUE; }
		if (LOWORD(wParam) == IDCANCEL) { EndDialog(hDlg, 0); return TRUE; }
	}
	return FALSE;
}

int Func_MOD2(HWND hWnd) {
    HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
    return (int)DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_STEP1), hWnd, Step1);
}