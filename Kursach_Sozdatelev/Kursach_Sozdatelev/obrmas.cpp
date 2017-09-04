#include "stdafx.h"
#include "Kursach_Sozdatelev.h"
void obr(fstream& file,HWND hDlg, HWND hListBox)
{
	int mas1[300];
	int mas2[300];
	STUD mas[300];
	STUD std;
	int l=0;
	TCHAR buff[300]=TEXT("");
	int k=0;
	file.clear();
	file.seekg(0,ios::beg);
	read(file,std);
	mas1[0]=0;
	mas1[1]=1;
	mas1[2]=2;
	mas1[3]=3;
	mas2[0]=0;
	mas2[1]=0;
	mas2[2]=0;
	mas2[3]=0;
	while(read(file,std))
	{
		if(std.spec==mas1[0]&&std.nb>mas2[0])
		{
			mas1[0]=std.spec;
			mas2[0]=std.nb;
			mas[k]=std;
			k++;
		}
		else
			if(std.spec==mas1[1]&&std.nb>mas2[1])
			{
			mas1[1]=std.spec;
			mas2[1]=std.nb;
			mas[k]=std;
			k++;
			}
			else
				if(std.spec==mas1[2]&&std.nb>mas2[2])
			{
			mas1[2]=std.spec;
			mas2[2]=std.nb;
			mas[k]=std;
			k++;
			}
				else
					if(std.spec==mas1[3]&&std.nb>mas2[3])
			{
			mas1[3]=std.spec;
			mas2[3]=std.nb;
			mas[k]=std;
			k++;
			}

	}
	for(int i=0; i<4;i++)
	{
		PutToStr(mas[i],buff);
		SendMessage(hListBox,LB_ADDSTRING,0,(LPARAM)buff);

	}

}