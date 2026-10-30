#include "framework.h"
#include "shape.h"

void Shape::Set(long x1, long y1, long x2, long y2) {
	xs1 = x1;
	ys1 = y1;
	xs2 = x2;
	ys2 = y2;
}

void PointShape::Show(HDC hdc) {
	SetPixel(hdc, xs1, ys1, RGB(0, 0, 0));
}

void LineShape::Show(HDC hdc) {
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, xs1, ys1, NULL);
	LineTo(hdc, xs2, ys2);

	SelectObject(hdc, hOldPen);
	DeleteObject(hPen);
}

void RectShape::Show(HDC hdc) {
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
	HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, min(xs1, xs2), min(ys1, ys2), max(xs1, xs2), max(ys1, ys2));
	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);
}

void EllipseShape::Show(HDC hdc) {
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Ellipse(hdc, min(xs1, xs2), min(ys1, ys2), max(xs1, xs2), max(ys1, ys2));
	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hPen);
	DeleteObject(hBrush);

}