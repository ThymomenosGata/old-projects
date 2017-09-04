#include "stdafx.h"
#include "kursach_tarasov.h"
void picture(HDC hdc,RECT rect,POINT beg, int& cvet)
{
	const int yCl=(rect.bottom	- rect.top);
	const int xCl=(rect.right	- rect.left);

	const double dxPix	= xCl/12.;
	const double dyPix	= yCl/11.;
	SetMapMode(hdc,MM_ISOTROPIC);
	SetWindowExtEx(hdc,xCl,yCl,NULL);
	SetViewportExtEx(hdc,xCl,-yCl,NULL);
	SetViewportOrgEx(hdc,beg.x,yCl-beg.y,  NULL);

	COLORREF COL[3][8]={
	{RGB(0,0,0),RGB(255,188,91),RGB(255,255,255),RGB(73,255,0),RGB(255,0,81),RGB(255,255,0),RGB(120,130,100),RGB(80,130,244)}, 
	{RGB(0,0,0),RGB(255,0,191),RGB(255,255,255),RGB(255,188,91),RGB(255,0,81),RGB(255,255,0),RGB(120,130,100),RGB(0,199,255)},
	{RGB(0,0,0),RGB(255,188,91),RGB(255,255,255),RGB(176,0,255),RGB(255,0,81),RGB(255,255,0),RGB(120,130,100),RGB(150,50,100)}
	};

	//sky
	HBRUSH hBrush = CreateSolidBrush(COL[cvet][2]);
	HBRUSH hOldBrush=(HBRUSH)SelectObject(hdc,hBrush);
	Rectangle (hdc,0,yCl,xCl,0);


	//внешние
		hBrush = CreateSolidBrush(COL[cvet][3]);
		SelectObject (hdc, CreatePen (PS_NULL, 0, RGB (73,255,0)));
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,0,yCl,xCl,0);
	//горы
	hBrush = CreateSolidBrush(COL[cvet][1]);
	DeleteObject(SelectObject(hdc,hBrush));
	POINT pt[4];
			pt[0].x = 5.25*dxPix;	pt[0].y = 9*dyPix;
			pt[1].x = 1*dxPix;  pt[1].y = 4*dyPix;
			pt[2].x = 3*dxPix; 	pt[2].y = 4*dyPix;
			pt[3].x = 7.25*dxPix;  pt[3].y = 4*dyPix;
	Polygon(hdc,pt,4);

	hBrush = CreateSolidBrush(COL[cvet][2]);
	DeleteObject(SelectObject(hdc,hBrush));
			pt[0].x = 5.25*dxPix;	pt[0].y = 9*dyPix;
			pt[1].x = 4.34*dxPix;  pt[1].y = 8*dyPix;
			pt[2].x = 5.25*dxPix; 	pt[2].y = 8*dyPix;
			pt[3].x = 5.7*dxPix;  pt[3].y = 8*dyPix;
	Polygon(hdc,pt,4);

	hBrush = CreateSolidBrush(COL[cvet][1]);
	DeleteObject(SelectObject(hdc,hBrush));
	POINT pr[4];
			pr[0].x = 7.25*dxPix;	pr[0].y = 9*dyPix;
			pr[1].x = 4*dxPix;  pr[1].y = 4*dyPix;
			pr[2].x = 7.25*dxPix; 	pr[2].y = 4*dyPix;
			pr[3].x = 11*dxPix;  pr[3].y = 4*dyPix;
	Polygon(hdc,pr,4);

	hBrush = CreateSolidBrush(COL[cvet][2]);
	DeleteObject(SelectObject(hdc,hBrush));
			pr[0].x = 7.25*dxPix;	pr[0].y = 9*dyPix;
			pr[1].x = 6.55*dxPix;  pr[1].y = 8*dyPix;
			pr[2].x = 7.2*dxPix; 	pr[2].y = 8*dyPix;
			pr[3].x = 8*dxPix;  pr[3].y = 8*dyPix;
	Polygon(hdc,pr,4);

	hBrush = CreateSolidBrush(COL[cvet][4]);
SelectObject (hdc, CreatePen (PS_NULL, 0, RGB (73,255,0)));
	DeleteObject(SelectObject(hdc,hBrush));
	Rectangle (hdc, 3.55*dxPix, 4*dyPix, 7*dxPix, 8*dyPix);

	hBrush = CreateSolidBrush(COL[cvet][5]);
SelectObject (hdc, CreatePen (PS_NULL, 0, RGB (73,255,0)));
	DeleteObject(SelectObject(hdc,hBrush));
	Rectangle (hdc, 3.7*dxPix, 7*dyPix, 4.7*dxPix, 7.9*dyPix);
	Rectangle (hdc, 5.9*dxPix, 7*dyPix, 6.9*dxPix, 7.9*dyPix);
	Rectangle (hdc, 3.7*dxPix, 6*dyPix, 4.7*dxPix, 6.9*dyPix);
	Rectangle (hdc, 5.9*dxPix, 6*dyPix, 6.9*dxPix, 6.9*dyPix);
	Rectangle (hdc, 3.7*dxPix, 5*dyPix, 4.7*dxPix, 5.9*dyPix);
	Rectangle (hdc, 5.9*dxPix, 5*dyPix, 6.9*dxPix, 5.9*dyPix);
}