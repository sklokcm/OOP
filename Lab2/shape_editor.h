#pragma once
#include "framework.h"

class ShapeObjectsEditor {
private:
	class ShapeEditor* pse;
public:
	ShapeObjectsEditor();
	~ShapeObjectsEditor();

	void StartPointEditor(HWND hWND);
	void StartLineEditor(HWND hWND);
	void StartRectEditor(HWND hWND);
	void StartEllipseEditor(HWND hWND);

	void OnLBdown(HWND hWND);
	void OnLBup(HWND hWND);
	void OnMouseMove(HWND hWND);
	void OnPaint(HWND hWND);
};