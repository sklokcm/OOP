#include "module3.h"
#include "resource3.h"

static INT_PTR CALLBACK Step2(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam) {
	if (iMessage == WM_COMMAND) {
		if (LOWORD(wParam) == IDC_BACK) { EndDialog(hDlg, -1); return TRUE; }
		if (LOWORD(wParam) == IDOK) { EndDialog(hDlg, 1); return TRUE; }
		if (LOWORD(wParam) == IDCANCEL) { EndDialog(hDlg, 0); return TRUE; }
	}
	return FALSE;
}

int Func_MOD3(HWND hWnd) {
	HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
	return (int)DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_STEP2), hWnd, Step2);
}