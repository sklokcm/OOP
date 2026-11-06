#include "framework.h"
#include "editor.h"

Shape* ShapeEditor::pcshape[MY_SHAPE_ARRAY_SIZE] = { nullptr };
int ShapeEditor::shapesCount = 0;

void ShapeEditor::ClearShapes() {
	for (int i = 0; i < shapesCount; i++) {
		if (pcshape[i]) {
			delete pcshape[i];
			pcshape[i] = nullptr;
		}
	}
	shapesCount = 0;
}

void ShapeEditor::DrawRubberTrace(HWND hWnd, long x1, long y1, long x2, long y2) {
	HDC hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);

	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

	DrawTraceShape(hdc, x1, y1, x2, y2);

	SelectObject(hdc, hOldBrush);
	SelectObject(hdc, hOldPen);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

void ShapeEditor::OnLBdown(HWND hWnd) {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xstart = xend = pt.x;
	ystart = yend = pt.y;
	isDrawing = true;
}

void ShapeEditor::OnMouseMove(HWND hWnd) {
	if (!isDrawing) return;
	DrawRubberTrace(hWnd, xstart, ystart, xend, yend);
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
	DrawRubberTrace(hWnd, xstart, ystart, xend, yend);
}

void ShapeEditor::OnLBup(HWND hWnd) {
	if (!isDrawing) return;
	DrawRubberTrace(hWnd, xstart, ystart, xend, yend);
	isDrawing = false;

	if (shapesCount < MY_SHAPE_ARRAY_SIZE) {
		Shape* p = CreateShape();
		if (p) {
			pcshape[shapesCount++] = p;
			InvalidateRect(hWnd, NULL, TRUE);
		}
	}
}

void ShapeEditor::OnPaint(HWND hWnd) {
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);

	for (int i = 0; i < shapesCount; i++) {
		if (pcshape[i]) {
			pcshape[i]->Show(hdc);
		}
	}
	EndPaint(hWnd, &ps);
}

void PointEditor::OnLBdown(HWND hWnd) {
	if (shapesCount < MY_SHAPE_ARRAY_SIZE) {
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		PointShape* p = new PointShape();
		p->Set(pt.x, pt.y, pt.x, pt.y);

		pcshape[shapesCount++] = p;

		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void LineEditor::DrawTraceShape(HDC hdc, long x1, long y1, long x2, long y2) {
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

Shape* LineEditor::CreateShape() {
	LineShape* p = new LineShape();
	p->Set(xstart, ystart, xend, yend);
	return p;
}

void RectEditor::DrawTraceShape(HDC hdc, long x1, long y1, long x2, long y2) {
	long left = 2 * x1 - x2;
	long top = 2 * y1 - y2;
	Rectangle(hdc, min(left, x2), min(top, y2), max(left, x2), max(top, y2));
}

Shape* RectEditor::CreateShape() {
	RectShape* p = new RectShape();
	long left = 2 * xstart - xend;
	long top = 2 * ystart - yend;
	p->Set(left, top, xend, yend);
	return p;
}

void EllipseEditor::DrawTraceShape(HDC hdc, long x1, long y1, long x2, long y2) {
	Ellipse(hdc, min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));
}

Shape* EllipseEditor::CreateShape() {
	EllipseShape* p = new EllipseShape();
	p->Set(xstart, ystart, xend, yend);
	return p;
}

