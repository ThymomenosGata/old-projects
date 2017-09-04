#include "stdafx.h"
#include "Kursach_Domaev.h"
void lotereya(HDC hdc,RECT rect,POINT beg, int& cvet)
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
	Ellipse(hdc,0*dxPix,0*dyPix,10*dxPix,10*dyPix);
	
		hBrush = CreateSolidBrush(COL[cvet][2]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,0*dxPix,0.5*dyPix,10*dxPix,10*dyPix);

	//леписток 1
	hBrush = CreateSolidBrush(COL[cvet][3]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,5.5*dxPix,5.5*dyPix,8.5*dxPix,9.5*dyPix);
	//леписток 2
	hBrush = CreateSolidBrush(COL[cvet][4]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,5*dxPix,1*dyPix,8*dxPix,5*dyPix);
	//леписток 3
	hBrush = CreateSolidBrush(COL[cvet][5]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,8.5*dxPix,5.5*dyPix,11.5*dxPix,10*dyPix);
	//леписток 4
	hBrush = CreateSolidBrush(COL[cvet][6]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,8*dxPix,0*dyPix,11*dxPix,3.5*dyPix);
	//леписток 5
	hBrush = CreateSolidBrush(COL[cvet][7]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,10*dxPix,2.75*dyPix,13*dxPix,6.75*dyPix);

	//голова
	hBrush = CreateSolidBrush(COL[cvet][1]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,6*dxPix,2*dyPix,12*dxPix,8*dyPix);

}