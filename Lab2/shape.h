#pragma once
#include "framework.h"

class Shape {
protected:
	long xs1 =0, ys1 =0, xs2 =0, ys2 =0;
public:
	virtual ~Shape(){}
	void Set(long x1, long y1, long x2, long y2);
	virtual void Show(HDC hdc)=0;
};

class PointShape : public Shape {
public:
	virtual void Show(HDC hdc) override;
};

class LineShape : public Shape {
public:
	virtual void Show(HDC hdc) override;
};

class RectShape : public Shape {
public:
	virtual void Show(HDC hdc) override;
};

class EllipseShape : public Shape {
public:
	virtual void Show(HDC hdc) override;
};