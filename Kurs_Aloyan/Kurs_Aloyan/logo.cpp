#include "stdafx.h"
#include "Kurs_Aloyan.h"
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
	HPEN hPen;
	hPen=CreatePen(PS_INSIDEFRAME,0,0);

	COLORREF COL[3][8]={
	{RGB(0,0,0),RGB(255,188,91),RGB(255,255,255),RGB(73,255,0),RGB(255,0,81),RGB(255,255,0),RGB(120,130,100),RGB(80,130,244)}, 
	{RGB(0,0,0),RGB(255,0,191),RGB(255,255,255),RGB(255,188,91),RGB(255,0,81),RGB(255,255,0),RGB(120,130,100),RGB(0,199,255)},
	{RGB(0,0,0),RGB(255,188,91),RGB(255,255,255),RGB(176,0,255),RGB(255,0,81),RGB(255,255,0),RGB(120,130,100),RGB(150,50,100)}
	};

	//sky
	HBRUSH hBrush = CreateSolidBrush(COL[cvet][3]);
	HBRUSH hOldBrush=(HBRUSH)SelectObject(hdc,hBrush);
	Rectangle (hdc,0,yCl,xCl,0);

	//рамка
	hBrush = CreateSolidBrush(COL[cvet][2]);
	DeleteObject(SelectObject(hdc,hBrush));
	
	Rectangle (hdc, 1*dxPix, 1*dyPix, 11*dxPix, 10*dyPix);
	
	//треугольник
	hBrush = CreateSolidBrush(COL[cvet][2]);
	SelectObject (hdc, CreatePen (PS_NULL, 0, RGB (73,255,0)));
	DeleteObject(SelectObject(hdc,hBrush));
	POINT pt[4];
			pt[0].x = 5*dxPix;	pt[0].y = 2*dyPix;
			pt[1].x = 6*dxPix;  pt[1].y = 2*dyPix;
			pt[2].x = 7*dxPix; 	pt[2].y = 2*dyPix;
			pt[3].x = 6*dxPix;  pt[3].y = 0*dyPix;
	Polygon(hdc,pt,4);
	
	//хвост
	hBrush = CreateSolidBrush(COL[cvet][0]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,6*dxPix,2*dyPix,10.5*dxPix,6*dyPix);
	//хвост
	hBrush = CreateSolidBrush(COL[cvet][2]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,6*dxPix,2.3*dyPix,10.3*dxPix,6*dyPix);
	//лапы зад
	hBrush = CreateSolidBrush(COL[cvet][6]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,4.7*dxPix,4.2*dyPix,4.9*dxPix,5.2*dyPix);
	//туловище
	hBrush = CreateSolidBrush(COL[cvet][1]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,4.5*dxPix,4*dyPix,9.5*dxPix,8*dyPix);
	Ellipse(hdc,3*dxPix,6*dyPix,5*dxPix,8*dyPix);
	//лапы
	hBrush = CreateSolidBrush(COL[cvet][6]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,7.3*dxPix,4*dyPix,8.7*dxPix,5.9*dyPix);
	Ellipse(hdc,6.9*dxPix,3.5*dyPix,8*dxPix,4.3*dyPix);
	Ellipse(hdc,5*dxPix,4.5*dyPix,5.9*dxPix,5.7*dyPix);
	Ellipse(hdc,4.9*dxPix,4*dyPix,5.2*dxPix,5*dyPix);
	//уши
	hBrush = CreateSolidBrush(COL[cvet][1]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,4*dxPix,7.5*dyPix,5*dxPix,9*dyPix);
	Ellipse(hdc,3.5*dxPix,7.5*dyPix,4*dxPix,8.5*dyPix);
	//голова
	hBrush = CreateSolidBrush(COL[cvet][0]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,3.7*dxPix,7.4*dyPix,3.9*dxPix,7.7*dyPix);
	
	//голова
	hBrush = CreateSolidBrush(COL[cvet][1]);
	DeleteObject(SelectObject(hdc,hBrush));
	POINT pr[4];
			pr[0].x = 3.3*dxPix;	pr[0].y = 6.3*dyPix;
			pr[1].x = 3.4*dxPix;  pr[1].y = 7*dyPix;
			pr[2].x = 3.3*dxPix; 	pr[2].y = 7.7*dyPix;
			pr[3].x = 2.6*dxPix;  pr[3].y = 7*dyPix;
	Polygon(hdc,pr,4);
	//голова
	hBrush = CreateSolidBrush(COL[cvet][0]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,2.6*dxPix,6.8*dyPix,2.9*dxPix,7.2*dyPix);
}