#pragma once

#include "resource.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include<windows.h>
#include <string.h>
#include<stdio.h>
#include <math.h>
#include <fstream>
using namespace std;

#define nameFile "text.txt"
#define strlen wcslen
#define strcpy wscpy
#define LENNAME 11
#define LENPROF 10
#define fstream wfstream
#define ostream wostream
#define NB 6
#define FAM 20
#define SHI 10
#define SPEC 10
struct STUD
{
	TCHAR fam[FAM];
	TCHAR shi[SHI];
	int spec;
	int nb;
	TCHAR delpol;

};
#define sizeLOT (3*SPEC+FAM+SHI+2)
void text(HDC hdc, int& text);
void picture(HDC hdc,RECT rect,POINT beg, int& cvet);
STUD Get(HWND hDlg);
void PutToStr(STUD& stud,TCHAR* buff);
fstream& del(fstream& file);
void mark(fstream& file,HWND hListBox, HWND hDlg, int n);
void readon(fstream& file, HWND hListBox);
void write(fstream &file, STUD& stud, int n=0);
fstream& read(fstream& file,STUD& stud,int n=0);
void obr(fstream& file,HWND hDlg, HWND hListBox);

