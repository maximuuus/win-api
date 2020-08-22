


#include <windows.h>

//---------------------------------------------------------------------------------
long __stdcall raime_funqcia(HWND hwnd, UINT message, UINT wParam, long lParam)
//void saxeli(MSG m)
{

	if(message == WM_CREATE)
	{
	}
	else if(message == WM_COMMAND)
	{
	}
	else if(message == WM_KEYDOWN)
	{
	}
	else if(message == WM_CHAR)
	{
	}
	else if(message == WM_SIZE)
	{
	}
	else if(message == WM_TIMER)
	{
	}
	else if(message == WM_PAINT)
	{

	}
	else if(message == WM_MOUSEMOVE)
	{
	}
	else if(message == WM_LBUTTONDOWN)
	{

	}
	else if(message == WM_MBUTTONDOWN)
	{

	}
	else if(message == WM_RBUTTONDOWN)
	{
	}
	else if(message == WM_LBUTTONDBLCLK)
	{

	}
	else if(message == WM_DESTROY)
	{
	PostQuitMessage(0);
	}

return DefWindowProc(hwnd, message, wParam,lParam);

}
//---------------------------------------------------------------------------------


//int __stdcall WinMain(HINSTANCE,HINSTANCE,char*,int)
void main() //for win32 consol apps
{
int x=1;
MSG msg;
WNDCLASSEX wcx;
HWND hwnd1;


memset((WNDCLASSEX *)&wcx,0,sizeof(WNDCLASSEX));

wcx.cbSize = sizeof(wcx);           
wcx.lpfnWndProc = raime_funqcia;
wcx.lpszClassName = "trainings";
wcx.hbrBackground=(HBRUSH)CreateSolidBrush(RGB(100,200,110));


	if(RegisterClassEx(&wcx))
	{
	hwnd1=CreateWindow(wcx.lpszClassName,"Tr",WS_OVERLAPPEDWINDOW,100,10,800,400,0,0,0,0);
	
	HRGN hrgn;
	hrgn=CreateRoundRectRgn(5,5,700,300,100,300);
	//hrgn=CreateRectRgn(10, 200, 300, 200);
	//hrgn=CreateEllipticRgn(10,0, 630, 400);
	SetWindowRgn(hwnd1,hrgn,1);



	HBRUSH hbr=CreateSolidBrush(RGB(100,100,10));
	FrameRgn(GetDC(hwnd1),hrgn,hbr,10,10);

	ShowWindow(hwnd1,SW_SHOW);
	UpdateWindow(hwnd1);


		while(x)
		{
		x=GetMessage(&msg,0,0,0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		}
	}
	else
	{
	int err=GetLastError();
	}
}