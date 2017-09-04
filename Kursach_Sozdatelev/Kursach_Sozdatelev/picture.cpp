#include "stdafx.h"
#include "Kursach_Sozdatelev.h"
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
	HBRUSH hBrush = CreateSolidBrush(COL[cvet][2]);
	HBRUSH hOldBrush=(HBRUSH)SelectObject(hdc,hBrush);
	Rectangle (hdc,0,yCl,xCl,0);

	//ноги
	hBrush = CreateSolidBrush(COL[cvet][0]);
	DeleteObject(SelectObject(hdc,hBrush));
	
	Rectangle (hdc, 2*dxPix, 2*dyPix, 8.5*dxPix, 4*dyPix);
	Rectangle (hdc, 2*dxPix, 0.5*dyPix, 3*dxPix, 4*dyPix);
	Rectangle (hdc, 4.75*dxPix, 0.5*dyPix, 5.75*dxPix, 4*dyPix);
	Rectangle (hdc, 7.5*dxPix, 0.5*dyPix, 8.5*dxPix, 4*dyPix);
	
	//голова
	hBrush = CreateSolidBrush(COL[cvet][1]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,4.75*dxPix,9*dyPix,5.75*dxPix,11*dyPix);

	//голова
	hBrush = CreateSolidBrush(COL[cvet][3]);
	DeleteObject(SelectObject(hdc,hBrush));
	POINT pt[4];
			pt[0].x = 5.25*dxPix;	pt[0].y = 9*dyPix;
			pt[1].x = 3.25*dxPix;  pt[1].y = 4*dyPix;
			pt[2].x = 5.25*dxPix; 	pt[2].y = 4*dyPix;
			pt[3].x = 7.25*dxPix;  pt[3].y = 4*dyPix;
	Polygon(hdc,pt,4);
	//голова
	hBrush = CreateSolidBrush(COL[cvet][2]);
	DeleteObject(SelectObject(hdc,hBrush));
	POINT pr[4];
			pr[0].x = 5.25*dxPix;	pr[0].y = 8.5*dyPix;
			pr[1].x = 3.5*dxPix;  pr[1].y = 4*dyPix;
			pr[2].x = 5.25*dxPix; 	pr[2].y = 4*dyPix;
			pr[3].x = 7*dxPix;  pr[3].y = 4*dyPix;
	Polygon(hdc,pr,4);
	//ноги
	hBrush = CreateSolidBrush(COL[cvet][3]);
SelectObject (hdc, CreatePen (PS_NULL, 0, RGB (73,255,0)));
	DeleteObject(SelectObject(hdc,hBrush));
	Rectangle (hdc, 4.75*dxPix, 7.5*dyPix, 5.75*dxPix, 7.75*dyPix);
	Rectangle (hdc, 4.35*dxPix, 6.5*dyPix, 6.2*dxPix, 6.75*dyPix);
	Rectangle (hdc, 3.95*dxPix, 5.5*dyPix, 6.55*dxPix, 5.75*dyPix);
	Rectangle (hdc, 3.55*dxPix, 4.5*dyPix, 6.95*dxPix, 4.75*dyPix);
}