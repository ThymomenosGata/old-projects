#include "stdafx.h"
#include "Kursach_Domaev.h"

void write(fstream& file, STUD& stud, int n)
{
	file.clear();
	if(n)
		file.seekg((n-1)*sizeLOT,ios::beg);
	file<<setw(10)<<stud.dek;
	file<<setw(10)<<stud.gr;
	file<<setw(10)<<stud.sp;
	file<<setw(10)<<stud.star;
	file<<setw(10)<<stud.k;
	file<<setw(10)<<stud.s;
	file<<setw(10)<<stud.ss;
	file<<setw(2)<<stud.del<<endl;
	if(!file)
		MessageBox(0,TEXT("ERROR WRITE"),TEXT("ERROR"),MB_OK);
}
fstream& read(fstream& file,STUD& stud,int n)
{
	if(n)
		file.seekg((n-1)*sizeLOT,ios::beg);
	file >> stud.dek;
	file >> stud.gr;
	file >> stud.sp;
	file >> stud.star;
	file >> stud.del;
	if(!file && !file.eof())
		MessageBox(0,TEXT("Ошибка чтения!"),TEXT("Ошибка!"),MB_OK);
	return file;
}
void readon(fstream& file, HWND hListBox)
{
	STUD stud;
	TCHAR buff[400];
	file.clear();
	file.seekg(0,ios::beg);
	SendMessage(hListBox,LB_RESETCONTENT,0,0);
	while(read(file,stud))
	{
		PutToStr(stud,buff);
		SendMessage(hListBox,LB_ADDSTRING,0,(LPARAM)buff);
	}
}