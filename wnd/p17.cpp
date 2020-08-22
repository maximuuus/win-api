#include <windows.h>
#include <stdio.h>

//----------------------------------------------------------------
long __stdcall window_main_function(HWND hwnd,unsigned int message
					, unsigned int wparam,long lparam)
{

//strtok

	if(message==WM_COMMAND)
	{
	int ctrl_id = LOWORD(wparam);
		if(ctrl_id==10)
		{
		HWND h=0;
		h=GetDlgItem(hwnd,20);
		SendMessage(h,LB_DELETESTRING,0,0);

		h=GetDlgItem(hwnd,30);
		SendMessage(h,CB_DELETESTRING,0,0);

		}
	}
	else if(message==WM_RBUTTONDOWN)
	{
	//MessageBox(hwnd,"WM_RBUTTONDOWN=0x0204",0,0);
	}
	else if(message==WM_PAINT)
	{
	char text[32];
	static int counter=0;
	counter++;
	sprintf(text,"Counter = %d",counter);
	TextOut(GetDC(GetDesktopWindow()),1100,10,text,strlen(text));
	//MessageBox(0,"WM_PAINT=0x000F",0,0);
	}
	else if(message==WM_LBUTTONDOWN)
	{

	char text[32];
	int x=(unsigned short)lparam;
	int y=HIWORD(lparam);
	HDC hdc=GetDC(hwnd);

	sprintf(text,"(%d , %d)",x,y);
	//TextOut(hdc,0,0,text,strlen(text));

	HWND h=0;
	
	h=GetDlgItem(hwnd,10);
	SendMessage(h,WM_SETTEXT,strlen(text),(long)text);

	h=GetDlgItem(hwnd,20);
	SendMessage(h,LB_ADDSTRING,0,(long)text);

	h=GetDlgItem(hwnd,30);
	SendMessage(h,CB_ADDSTRING,0,(long)text);

	h=GetDlgItem(hwnd,40);
	SendMessage(h,WM_SETTEXT,strlen(text),(long)text);

	h=GetDlgItem(hwnd,50);
	SendMessage(h,WM_SETTEXT,strlen(text),(long)text);

	//SetPixel(hdc,x,y,RGB(250,0,0));
	}
	else if(message==WM_MOUSEMOVE)
	{
		if(wparam==MK_LBUTTON)
		{
		int x=(unsigned short)lparam;
		int y=HIWORD(lparam);
		HDC hdc=GetDC(hwnd);

		/*
		SetPixel(hdc,x,y-1,RGB(250,0,0));
		SetPixel(hdc,x-1,y-1,RGB(250,0,0));
		SetPixel(hdc,x-1,y,RGB(250,0,0));
		SetPixel(hdc,x,y,RGB(250,0,0));
		SetPixel(hdc,x+1,y,RGB(250,0,0));
		SetPixel(hdc,x+1,y+1,RGB(250,0,0));
		*/
		static POINT pt={0,0};
		
		//SetColor(
		MoveToEx(hdc,pt.x,pt.y,&pt);
		LineTo(hdc,x,y);
		pt.x=x;
		pt.y=y;
		}

	}
	else if(message==WM_RBUTTONDBLCLK)
	{
	//MessageBox(hwnd,"WM_RBUTTONDBLCLK=0x0206",0,0);
	}
	else if(message==WM_LBUTTONDBLCLK)
	{
	//MessageBox(hwnd,"WM_LBUTTONDBLCLK=0x0203",0,0);
	}

return DefWindowProc(hwnd,message,wparam,lparam);
}
//----------------------------------------------------------------

void main()
{
HWND hwnd=0;
int X,Y,W,H;
ULONG style=0;

WNDCLASS wc,wc1,A2121,wererterytr;
ZeroMemory(&wc,sizeof(WNDCLASS));

wc.style=CS_DBLCLKS;
wc.lpfnWndProc=(WNDPROC)&window_main_function;
wc.lpszClassName="12";
wc.hbrBackground=(HBRUSH)CreateSolidBrush(RGB(200,200,200));
wc.hIcon=(HICON)LoadImage(0,"c:\\1.ico",IMAGE_ICON,16,16,LR_LOADFROMFILE);

	if(RegisterClass(&wc)==0)
	{
	MessageBox(hwnd,"RegisterClass error",0,0);
	return;
	}


//mtavari fanjara:
style=WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
X=100;Y=30;W=1000;H=500;
hwnd=CreateWindow(wc.lpszClassName,"Main",style,X,Y,W,H,0,0,0,0);

//shvili fanjrebi:
style=WS_VISIBLE|WS_CHILD|WS_BORDER;

X=10;Y=30;W=100;H=100;
CreateWindow("button","button",style,X,Y,W,H,hwnd,(HMENU)10,0,0);


X=150;Y=30;W=100;H=100;
CreateWindow("listbox","listbox",style,X,Y,W,H,hwnd,(HMENU)20,0,0);

X=300;Y=30;W=100;H=100;
CreateWindow("combobox","combobox",style,X,Y,W,H,hwnd,(HMENU)30,0,0);

X=450;Y=30;W=100;H=100;
CreateWindow("static","static",style,X,Y,W,H,hwnd,(HMENU)40,0,0);

X=600;Y=30;W=100;H=100;
CreateWindow("edit","edit",style,X,Y,W,H,hwnd,(HMENU)50,0,0);

style=WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN;
X=1310;Y=230;W=200;H=100;
//CreateWindow("1223","Main",style,X,Y,W,H,0,0,0,0);
	
MSG msg;
int s=1;
	while(s!=0)
	{
	s=GetMessage(&msg,0,0,0);
	TranslateMessage(&msg);
	DispatchMessage(&msg);
	}
}