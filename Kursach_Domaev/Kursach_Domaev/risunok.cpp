#include "stdafx.h"
#include "Kursach_Domaev.h"
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


	//�������
		hBrush = CreateSolidBrush(COL[cvet][3]);
		SelectObject (hdc, CreatePen (PS_NULL, 0, RGB (73,255,0)));
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,0*dxPix,-3*dyPix,6*dxPix,10*dyPix);
	
		hBrush = CreateSolidBrush(COL[cvet][2]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,-1*dxPix,-2.75*dyPix,5.5*dxPix,10*dyPix);
	
	//�������� 1
	hBrush = CreateSolidBrush(COL[cvet][7]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,3.5*dxPix,9*dyPix,5.5*dxPix,12*dyPix);
	//�������� 2
	hBrush = CreateSolidBrush(COL[cvet][4]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,4.5*dxPix,6*dyPix,6.5*dxPix,10*dyPix);
	//�������� 3
	hBrush = CreateSolidBrush(COL[cvet][5]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,1.75*dxPix,7*dyPix,4*dxPix,11*dyPix);
	//�������� 4
	hBrush = CreateSolidBrush(COL[cvet][6]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,3.5*dxPix,3.5*dyPix,5.5*dxPix,7.5*dyPix);
	//�������� 5
	hBrush = CreateSolidBrush(COL[cvet][7]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,2*dxPix,4*dyPix,3.75*dxPix,8*dyPix);
	//������
	hBrush = CreateSolidBrush(COL[cvet][11]);
	DeleteObject(SelectObject(hdc,hBrush));
	Ellipse(hdc,2.25*dxPix,5*dyPix,5.75*dxPix,11*dyPix);

}