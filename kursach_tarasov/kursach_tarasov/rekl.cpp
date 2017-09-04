#include "stdafx.h"
#include "kursach_tarasov.h"
void text(HDC hdc, int& text)
{
	COLORREF TEXT[3][3]={
	{RGB(0,81,255),RGB(125,0,230),RGB(0,0,0)}, 
	{RGB(255, 0,0),RGB(240,195,0),RGB(190,190,0)},
    {RGB(39,255,0),RGB(255,0,191),RGB(176,0,255)}
	}; //0 - фирма, 1 - описание, 2 - телефон
	RECT rect1;

	HFONT hFont = CreateFont(48, 0, 0, 0,FW_DONTCARE, FALSE,TRUE, FALSE,DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));
    SelectObject(hdc, hFont);       
	SetRect(&rect1, 200, 200, 400, 250);
    SetTextColor(hdc, TEXT[text][0]);
    DrawText(hdc, TEXT("Красный мак"), -1, &rect1, DT_NOCLIP);
	
	hFont = CreateFont(34,0,0,0,FW_DONTCARE,TRUE,FALSE,FALSE,DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
    SelectObject(hdc, hFont);       
	SetRect(&rect1, 200, 250, 400, 350);
    SetTextColor(hdc, TEXT[text][1]);
	DrawText(hdc, TEXT("Гостиница <<Красный мак>>. \n Самый лучший гостиничный дом \n Приезжайте к нам. \n И может быть ты еще будешь жить!"), -1, &rect1, DT_NOCLIP);
	
	hFont = CreateFont(25, 0, 0, 0, FW_DONTCARE,FALSE,FALSE,FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
    SelectObject(hdc, hFont);       
	SetRect(&rect1, 200, 400, 400, 450);
    SetTextColor(hdc, TEXT[text][2]);
	DrawText(hdc, TEXT("Телефон: 8(954)555-37-35 \nГен.Дир. Тарасов Максим"), -1, &rect1, DT_NOCLIP);

	DeleteObject(hFont);
}