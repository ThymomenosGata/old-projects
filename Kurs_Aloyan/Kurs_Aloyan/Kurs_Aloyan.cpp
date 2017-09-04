// Kurs_Aloyan.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Kurs_Aloyan.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна
int cvet=0;
int textik=0;
int choice;
STRACT stract;
fstream file;
// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK ViewDlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK GetDataDlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Serch(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Edit(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: разместите код здесь.
	MSG msg;
	HACCEL hAccelTable;

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_KURS_ALOYAN, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	file.open(nameFile,ios::in|ios::out|ios::ate);
	if(!file)
	{
		file.close();
		file.open(nameFile,ios::out);
		file.close();
		file.open(nameFile,ios::in|ios::out|ios::ate);
	}
	file.imbue(locale(".1251"));

	// Выполнить инициализацию приложения:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KURS_ALOYAN));

	// Цикл основного сообщения:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
//  КОММЕНТАРИИ:
//
//    Эта функция и ее использование необходимы только в случае, если нужно, чтобы данный код
//    был совместим с системами Win32, не имеющими функции RegisterClassEx'
//    которая была добавлена в Windows 95. Вызов этой функции важен для того,
//    чтобы приложение получило "качественные" мелкие значки и установило связь
//    с ними.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KURS_ALOYAN));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_KURS_ALOYAN);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND	- обработка меню приложения
//  WM_PAINT	-Закрасить главное окно
//  WM_DESTROY	 - ввести сообщение о выходе и вернуться.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case ID_VIEW:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_VIEW), hWnd, ViewDlgProc);
			break;
		case ID_LOGO:
			choice=0;
			DrawMenuBar(hWnd);
			break;
		case ID_TEXT:
			choice=1;
			DrawMenuBar(hWnd);
			break;
			case ID_CV1:
			cvet=0;
			break;
		case ID_CV2:
			cvet=1;
			break;
		case ID_CV3:
			cvet=2;
			break;
		case ID_TXT1:
			textik=0;
			break;
		case ID_TXT2:
			textik=1;
			break;
		case ID_TXT3:
			textik=2;
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		InvalidateRect(hWnd,NULL,TRUE);
		break;
		case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		RECT rect;
		if (choice==0)
		{
			GetClientRect(hWnd,&rect);
			POINT beg={0,0};
			picture(hdc, rect, beg, cvet);
		}
		if (choice==1)
		{
			GetClientRect(hWnd,&rect);
			text(hdc, textik);
			rect.top=50;
			rect.right=300;
			rect.bottom=150;
			rect.left=400;
			POINT begg={500,-50};
			picture(hdc,rect,begg,cvet);
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
BOOL CALLBACK ViewDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hListBox;
	static LOGFONT lf;
	HFONT hFont1;
	switch (message)
	{
	case WM_INITDIALOG:
		hListBox=GetDlgItem(hDlg,IDC_LIST1);
		SendMessage(hListBox,LB_RESETCONTENT,0,0);
		lf.lfHeight=16;
		lstrcpy((LPWSTR)&lf.lfFaceName,TEXT("Courier"));
		hFont1=CreateFontIndirect(&lf);
		SendMessage(hListBox,WM_SETFONT,(WPARAM)hFont1,TRUE);
		readon(file,hListBox);
		file.seekg(0,ios::beg);
	return FALSE;
		case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg, TRUE);
			return TRUE;

		case IDCANCEL:
			EndDialog(hDlg, FALSE);
			return TRUE;

		case IDC_MARK:
			mark(file,hListBox,hDlg,1);
			readon(file,hListBox);
			return(INT_PTR)TRUE;

		case IDC_UNMARK:
			mark(file,hListBox,hDlg,2);
			readon(file,hListBox);
			return(INT_PTR)TRUE;

		case IDC_DEL:
			del(file);
			readon(file,hListBox);
			return (INT_PTR)TRUE;

		case IDC_DELETED:
			mark(file,hListBox,hDlg,1);
			del(file);
			readon(file,hListBox);
			break;

		case IDC_GET:
			DialogBox((HINSTANCE)GetModuleHandle(NULL),MAKEINTRESOURCE(IDD_GET),hDlg,GetDataDlgProc);
			readon(file,hListBox);
			return(INT_PTR)TRUE;
		case IDC_EDIT:
			DialogBox((HINSTANCE)GetModuleHandle(NULL),MAKEINTRESOURCE(IDD_EDIT1),hDlg,Edit);
			break;
		case IDC_SERCH:
			DialogBox((HINSTANCE)GetModuleHandle(NULL),MAKEINTRESOURCE(IDD_SERCH),hDlg,Serch);
			break;
		case IDC_RELOAD:
			readon(file,hListBox);
			return (INT_PTR)TRUE;


		}
		break;
	}
	return FALSE;
}
BOOL CALLBACK Serch(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hListBox2;
	static LOGFONT lf;
	HFONT hFont1;
	switch (message)
	{
	case WM_INITDIALOG:
		hListBox2=GetDlgItem(hDlg,IDC_LIST2);
		SendMessage(hListBox2,LB_RESETCONTENT,0,0);
		lf.lfHeight = 16;
		lstrcpy((LPWSTR)&lf.lfFaceName,TEXT("Courier"));
		hFont1=CreateFontIndirect(&lf);
		SendMessage(hListBox2,WM_SETFONT,(WPARAM)hFont1,TRUE);
		SetFocus(hDlg);
	return FALSE;
		case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg, TRUE);
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, FALSE);
			return TRUE;
		case IDC_POISK:
			serche(file,hDlg,hListBox2);
			break;

		}
		break;
	}
	return FALSE;
}
BOOL CALLBACK GetDataDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	return FALSE;
		case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			stract=Get(hDlg);
			if(stract.sh!=0)
			{
				file.seekg(0,ios::end);
				write(file,stract);
				EndDialog(hDlg, TRUE);
			}
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, FALSE);
			return TRUE;

		}
		break;
	}
	return FALSE;
}
BOOL CALLBACK Edit(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hListBox;
	static LOGFONT lf;
	HFONT hFont1;
	switch (message)
	{
	case WM_INITDIALOG:
		
		hListBox=GetDlgItem(hDlg,IDC_LIST1);
		SendMessage(hListBox,LB_RESETCONTENT,0,0);
		lf.lfHeight=16;
		lstrcpy((LPWSTR)&lf.lfFaceName,TEXT("Courier"));
		hFont1=CreateFontIndirect(&lf);
		SendMessage(hListBox,WM_SETFONT,(WPARAM)hFont1,TRUE);
		file.seekg(0,ios::beg);

		{
			TCHAR buf[]=TEXT("Трудоемкость");
			TCHAR buf1[]=TEXT("Коэффициент");
			TCHAR buf2[]=TEXT("Плановый фонд");
			SendMessage(GetDlgItem(hDlg,IDC_EDIT),CB_ADDSTRING,0,(LPARAM)(buf));
			SendMessage(GetDlgItem(hDlg,IDC_EDIT),CB_ADDSTRING,0,(LPARAM)(buf1));
			SendMessage(GetDlgItem(hDlg,IDC_EDIT),CB_ADDSTRING,0,(LPARAM)(buf2));
			SendMessage(GetDlgItem(hDlg,IDC_EDIT),CB_SELECTSTRING,NULL,(LPARAM)(buf1));
		}
	return FALSE;
		case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDOK:
			izmen(file,hDlg,hListBox);
			MessageBox(0,TEXT("Информация в файле обновлена"),TEXT("Внимание!"),MB_OK);
			MessageBox(0,TEXT("Чтобы обновить информацию на экране нажмите на кнопку <ОБНОВИТЬ> "),TEXT("Внимание!"),MB_OK);
			EndDialog(hDlg, TRUE);
			return (INT_PTR)TRUE;
		case IDCANCEL:
			EndDialog(hDlg, FALSE);
			return TRUE;

		}
		break;
	}
	return FALSE;
}