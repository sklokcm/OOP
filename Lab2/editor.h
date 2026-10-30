#pragma once
#include "framework.h"
#include "shape.h"

#define MY_SHAPE_ARRAY_SIZE 101 


class Editor {
public:
	virtual ~Editor() {}
	virtual void OnLBdown(HWND hWnd) = 0;
	virtual void OnLBup(HWND hWnd) = 0;
	virtual void OnMouseMove(HWND hWnd) = 0;
	virtual void OnPaint(HWND hWnd) = 0;
};

class ShapeEditor : public Editor {
protected:
	static Shape* pcshape[MY_SHAPE_ARRAY_SIZE];
	static int shapesCount;

	long xstart = 0, ystart = 0, xend = 0, yend = 0;
	bool isDrawing = false;
	void DrawRubberTrace(HWND hWnd, long x1, long y1, long x2, long y2);
	virtual void DrawTraceShape(HDC hdc, long x1, long y1, long x2, long y2) {}
	virtual Shape* CreateShape() { return nullptr; }
public:
	virtual void OnLBdown(HWND hWnd) override;
	virtual void OnLBup(HWND hWnd) override;
	virtual void OnMouseMove(HWND hWnd) override;
	virtual void OnPaint(HWND hWnd) override ;
	
	static void ClearShapes();
};

class PointEditor : public ShapeEditor {
public:
	virtual void OnLBdown(HWND hWnd) override;
};

class LineEditor : public ShapeEditor {
protected:
	virtual void DrawTraceShape(HDC hdc, long x1, long y1, long x2, long y2) override;
	virtual Shape* CreateShape() override;
};

class RectEditor : public ShapeEditor {
protected: 
	virtual void DrawTraceShape(HDC hdc, long x1, long y1, long x2, long y2) override;
	virtual Shape* CreateShape() override;
};

class EllipseEditor : public ShapeEditor {
protected:
	virtual void DrawTraceShape(HDC hdc, long x1, long y1, long x2, long y2) override;
	virtual Shape* CreateShape() override;
};
