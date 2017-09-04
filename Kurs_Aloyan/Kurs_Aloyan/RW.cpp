#include "stdafx.h"
#include "Kurs_Aloyan.h"
void write(fstream &file, STRACT& stract, int n)
{
	file.clear();
	if(n)
		file.seekg((n-1)*sizeLOT,ios::beg);
	file<<setw(10)<<stract.sh;
	file<<setw(10)<<stract.tr;
	file<<setw(10)<<stract.kef;
	file<<setw(10)<<stract.fond;
	file<<setw(3)<<stract.delpol<<endl;
	if(!file)
		MessageBox(0,TEXT("������ ������!"),TEXT("������!"),MB_OK);
}
fstream& read(fstream& file,STRACT& stract,int n)
{
	if(n)
		file.seekg((n-1)*sizeLOT,ios::beg);
	file>>stract.sh;
	file>>stract.tr;
	file>>stract.kef;
	file>>stract.fond;
	file>>stract.delpol;
	if(!file && !file.eof())
		MessageBox(0,TEXT("������ ������!"),TEXT("������!"),MB_OK);
	return file;
}
void readon(fstream& file, HWND hListBox)
{
	STRACT stract;
	TCHAR buff[100];
	file.clear();
	file.seekg(0,ios::beg);
	SendMessage(hListBox,LB_RESETCONTENT,0,0);
	while(read(file,stract))
	{
		PutToStr(stract,buff);
		SendMessage(hListBox,LB_ADDSTRING,0,(LPARAM)buff);
	}
}