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
#define LINEB 20
struct STUD {
	          TCHAR dek[LINEB -5];
			  TCHAR star[LINEB -5];
			  TCHAR gr[LINEB -5];
			  TCHAR sp[LINEB -5];
			  int k;
			  int s;
			  int ss;
			  TCHAR del;
};
#define sizeLOT (7*LENPROF+2+2)
void lotereya(HDC hdc,RECT rect,POINT beg, int& cvet);
void textik(HDC hdc, int& text);
void PutToStr(STUD& stud,TCHAR* buff);
STUD Get(HWND hDlg);
fstream& read(fstream& file,STUD& stud,int n=0);
void write(fstream &file, STUD& stud, int n=0);
void readon(fstream& file, HWND hListBox);
fstream& del(fstream& file);
void mark(fstream& file,HWND hListBox, HWND hDlg, int n);