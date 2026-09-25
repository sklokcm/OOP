#include "module1.h"
#include "resource1.h"


static INT_PTR CALLBACK Work1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM) {
	HWND hScroll = GetDlgItem(hDlg, IDC_SCROLLBAR1);
	int pos = GetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL);
	switch (iMessage)
	{
	case WM_INITDIALOG:
		SetScrollRange(hScroll, SB_CTL, 1, 100, FALSE);
		SetScrollPos(hScroll, SB_CTL, 50, TRUE);
		SetDlgItemInt(hDlg, IDC_STATIC_TEXT, 50, FALSE);
		return TRUE;
	case WM_HSCROLL:
	{
		switch (LOWORD(wParam)) {
		case SB_LINELEFT:
			pos--;
			break;
		case SB_LINERIGHT:
			pos++;
			break;
		case SB_THUMBPOSITION:
		case SB_THUMBTRACK:
			pos = HIWORD(wParam);
			break;
		default: break;
		}
		SetScrollPos(hScroll, SB_CTL, pos, TRUE);
		SetDlgItemInt(hDlg, IDC_STATIC_TEXT, pos, FALSE);
		break;
	}
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK) {
			int pos = GetScrollPos(hScroll, SB_CTL);
			EndDialog(hDlg, pos);
			return TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, pos);
			return TRUE;
		}
	default: break;
	}
	return FALSE;
}


int Func_MOD1(HWND hWnd) {
	HINSTANCE hInstance = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
	return (int)DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
}

