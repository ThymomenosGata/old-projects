#include "stdafx.h"
#include "Kursach_Sozdatelev.h"
void write(fstream &file, STUD& stud, int n)
{
	file.clear();
	if(n)
		file.seekg((n-1)*sizeLOT,ios::beg);
	file<<setw(20)<<stud.fam;
	file<<setw(10)<<stud.shi;
	file<<setw(10)<<stud.spec;
	file<<setw(10)<<stud.nb;
	file<<setw(10)<<stud.delpol<<endl;
	if(!file)
		MessageBox(0,TEXT("ошибка записи!"),TEXT("ОШИБКА!"),MB_OK);
}
fstream& read(fstream& file,STUD& stud,int n)
{
	if(n)
		file.seekg((n-1)*sizeLOT,ios::beg);
	file>>stud.fam;
	file>>stud.shi;
	file>>stud.spec;
	file>>stud.nb;
	file>>stud.delpol;
	if(!file && !file.eof())
		MessageBox(0,TEXT("Ошибка чтения!"),TEXT("Ошибка!"),MB_OK);
	return file;
}
void readon(fstream& file, HWND hListBox)
{
	STUD stud;
	TCHAR buff[100];
	file.clear();
	file.seekg(0,ios::beg);
	SendMessage(hListBox,LB_RESETCONTENT,0,0);
	while(read(file,stud))
	{
		PutToStr(stud,buff);
		SendMessage(hListBox,LB_ADDSTRING,0,(LPARAM)buff);
	}
}