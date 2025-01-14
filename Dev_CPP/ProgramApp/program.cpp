#include <windows.h>
#include <iostream>
#include "menu.h"

using namespace std;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "WindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{

    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */
				 //HDC hDC;
    HMENU menu;

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
   
    //wincl.hIcon = LoadIcon (NULL, IDI_ASTERISK);
    //wincl.hIconSm = LoadIcon (NULL, IDI_HAND);

    wincl.hIcon = (HICON)LoadImage( hThisInstance,"ProgramAppDev.ico",IMAGE_ICON,32, 32,LR_LOADFROMFILE);
    wincl.hIconSm = (HICON)LoadImage( hThisInstance,"ProgramAppDev.ico",IMAGE_ICON,16, 16,LR_LOADFROMFILE);
 
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_WINDOW;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    
    

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "ĳ������� ����",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           800,                 /* The programs width */
           600,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nFunsterStil);
    
    menu = LoadMenu(hThisInstance, MAKEINTRESOURCE(IDR_MENU));
    SetMenu(hwnd, menu);

    
    

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
       case WM_KEYDOWN: // ������ � �����������, �����
	  switch(wParam)
	  {
		case VK_ESCAPE: // ������ ������ ESC
			DestroyWindow(hwnd);//SendMessage(hwnd,WM_CLOSE,0,0);
			break;
	  }
	  break;


       case WM_COMMAND:
           switch( wParam )
           {
             case IDM_FILENEW:
             case IDM_FILEOPEN:
             case IDM_FILESAVE:
             case IDM_FILESAVEAS:
             case IDM_FILEPRINT:
             case IDM_FILEPAGESETUP:
             case IDM_FILEPRINTSETUP:

             case IDM_EDITUNDO:
             case IDM_EDITCUT:
             case IDM_EDITCOPY:
             case IDM_EDITPASTE:
             case IDM_EDITDELETE:
                  MessageBox( hwnd, (LPSTR) "Function Not Yet Implemented.",
                              (LPSTR) szClassName,
                              MB_ICONINFORMATION | MB_OK );
                  return 0;

             case IDM_HELPCONTENTS:
                  WinHelp( hwnd, (LPSTR) "HELPFILE.HLP",
                           HELP_CONTENTS, 0L );
                  return 0;

             case IDM_HELPSEARCH:
                  WinHelp( hwnd, (LPSTR) "HELPFILE.HLP",
                           HELP_PARTIALKEY, 0L );
                  return 0;

             case IDM_HELPHELP:
                  WinHelp( hwnd, (LPSTR) "HELPFILE.HLP",
                           HELP_HELPONHELP, 0L );
                  return 0;

             case IDM_FILEEXIT:
			{
			if( MessageBox( hwnd, (LPSTR) "Realy?",
                              (LPSTR) "Yes/No",
                              MB_YESNO | MB_ICONQUESTION )==IDYES) SendMessage( hwnd, WM_CLOSE, 0, 0L );
                  return 0;
		} break;

             case IDM_HELPABOUT:
                  MessageBox (NULL, "About..." , "Windows example version 0.01", 1);
                  return 0;

           }
           break;



	  
      case WM_CLOSE:
           DestroyWindow( hwnd );
           return 0;	  
	  
       case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
  
       default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

//if(MessageBox(hwnd,_T("�� �������?"),_T("��/���"),MB_YESNO|MB_ICONQUESTION) == IDYES)
//if(hwnd,MessageBox((LPSTR)"�� �������?",(LPSTR)"��/���",MB_YESNO|MB_ICONQUESTION) == IDYES)
