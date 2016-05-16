#include <windows.h>
#include <CommCtrl.h>
#include "resource.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct Programmer
{
    char name[256];
    char surname[256];
    char language[256];
    char company[256];
    double rating;
} programmer_t;

enum {
    STATIC_ID_NAME = 1,
    STATIC_ID_SURNAME,
    STATIC_ID_LANGUAGE,
    STATIC_ID_COMPANY,
    STATIC_ID_RATING,
    BUTTON_ID,
    STATIC_ID,
    BUTTON_ID_SAVE,
    ID_CB,
};

const char g_szClassName[] = "myWindowClass";

HINSTANCE hInst;
WNDPROC OldButtonProc;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ButtonProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(
                   HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow
                  )
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    hInst = hInstance;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 400,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

programmer_t programmer;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND hButton, hButtonSave;
    static HWND hStatic;
   static HWND hGroupBox;
     static HWND hStaticNameT, hStaticSurnameT, hStaticLanguageT, hStaticCompanyT;
     static HWND hEditName, hEditSurname, hEditLanguage, hEditCompany;
 int checked = 0;
 LPCSTR type;


    switch(msg)
    {

        case WM_CREATE:
            CreateWindowW(L"button", L"Change",
                      WS_VISIBLE | WS_CHILD | BS_CHECKBOX | BS_AUTOCHECKBOX,
                      210, 210, 105, 15,
                      hwnd, (HMENU)ID_CB, NULL, NULL);
         CheckDlgButton(hwnd, ID_CB, BST_CHECKED);



              hGroupBox = CreateWindow(WC_BUTTON, "Programmer",
                                 WS_CHILD | WS_VISIBLE | BS_GROUPBOX | WS_GROUP,
                                 20, 10, 270, 150,
                                 hwnd, NULL, hInst, NULL);
              hStaticNameT = CreateWindowEx(0, WC_STATIC, "Name:",
                                      WS_CHILD | WS_VISIBLE,
                                      15, 20, 45, 18,
                                     hGroupBox, NULL, hInst, NULL);
               hStaticSurnameT = CreateWindowEx(0, WC_STATIC, "Surname:",
                                      WS_CHILD | WS_VISIBLE,
                                      15, 45, 65, 18,
                                     hGroupBox, NULL, hInst, NULL);
                hStaticLanguageT = CreateWindowEx(0, WC_STATIC, "Language:",
                                      WS_CHILD | WS_VISIBLE,
                                      15, 70, 72, 18,
                                     hGroupBox, NULL, hInst, NULL);
                hStaticCompanyT = CreateWindowEx(0, WC_STATIC, "Company:",
                                      WS_CHILD | WS_VISIBLE,
                                      15, 95, 68, 18,
                                     hGroupBox, NULL, hInst, NULL);
                int checked = IsDlgButtonChecked(hwnd, ID_CB);
                  hEditName = CreateWindowEx(0, WC_EDIT, programmer.name,
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     120, 20, 120, 18,
                                     hGroupBox, (HMENU)STATIC_ID_NAME, hInst, NULL);
                 //SetWindowText(hStaticName,);
                hEditSurname = CreateWindowEx(0, WC_EDIT,programmer.surname,
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     120, 45, 120, 18,
                                     hGroupBox, (HMENU)STATIC_ID_SURNAME, hInst, NULL);
                hEditLanguage = CreateWindowEx(0,WC_EDIT, programmer.language,
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     120, 70, 120, 18,
                                     hGroupBox, (HMENU)STATIC_ID_LANGUAGE, hInst, NULL);
                hEditCompany = CreateWindowEx(0, WC_EDIT, programmer.company,
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     120, 95, 120, 18,
                                     hGroupBox, (HMENU)STATIC_ID_COMPANY, hInst, NULL);

            hButton = CreateWindowEx(0,WC_BUTTON,"Show",
                              WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
                             20, 170, 130, 23,
                             hwnd,(HMENU)BUTTON_ID,hInst,NULL);


             OldButtonProc = (WNDPROC) SetWindowLong (hButton, GWL_WNDPROC, (LONG) ButtonProc);


            break;
             case BUTTON_ID:

             GetDlgItemText (hGroupBox, STATIC_ID_NAME, programmer.name, sizeof(programmer.name));
             GetDlgItemText (hGroupBox, STATIC_ID_SURNAME, programmer.surname, sizeof(programmer.surname));
             GetDlgItemText (hGroupBox, STATIC_ID_LANGUAGE, programmer.language, sizeof(programmer.language));
             GetDlgItemText (hGroupBox, STATIC_ID_COMPANY, programmer.company, sizeof(programmer.company));


//             printf("%s",str);
            //GetWindowText(hEditName,programmer.name,sizeof(programmer.name));


        break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;

        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK ButtonProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    HWND parent = GetParent(hwnd);
    HWND hStatic = GetDlgItem(parent, STATIC_ID);
    switch (msg) {
        case WM_LBUTTONDOWN:

            break;
      case WM_LBUTTONUP:
           DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, (DLGPROC)DlgMain);
            break;
    }
   return CallWindowProc(OldButtonProc, hwnd, msg, wp, lp);
}

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HWND hDial;
    static HWND hStaticNameT, hStaticSurnameT, hStaticLanguageT, hStaticCompanyT;
    static HWND hStaticName, hStaticSurname, hStaticLanguage, hStaticCompany;
    char buf[256];
    sprintf(buf,"%f",programmer.rating,sizeof(programmer.rating));


    switch(uMsg)
    {
        case WM_INITDIALOG:
        {

             hDial = CreateWindow(WC_BUTTON, "Programmer",
                                 WS_CHILD | WS_VISIBLE | BS_GROUPBOX | WS_GROUP,
                                 20, 10, 270, 150,
                                 hwndDlg, NULL, hInst, NULL);
                hStaticNameT = CreateWindowEx(0, WC_STATIC, "Name:",
                                      WS_CHILD | WS_VISIBLE,
                                      15, 20, 45, 18,
                                     hDial, NULL, hInst, NULL);
               hStaticSurnameT = CreateWindowEx(0, WC_STATIC, "Surname:",
                                      WS_CHILD | WS_VISIBLE,
                                      15, 45, 65, 18,
                                     hDial, NULL, hInst, NULL);
                hStaticLanguageT = CreateWindowEx(0, WC_STATIC, "Language:",
                                      WS_CHILD | WS_VISIBLE,
                                      15, 70, 72, 18,
                                     hDial, NULL, hInst, NULL);
                hStaticCompanyT = CreateWindowEx(0, WC_STATIC, "Company:",
                                      WS_CHILD | WS_VISIBLE,
                                      15, 95, 68, 18,
                                     hDial, NULL, hInst, NULL);

                hStaticName = CreateWindowEx(0, WC_STATIC, programmer.name,
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     120, 20, 120, 18,
                                     hDial, (HMENU)STATIC_ID_NAME, hInst, NULL);
                 //SetWindowText(hStaticName,);
                hStaticSurname = CreateWindowEx(0, WC_STATIC,programmer.surname,
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     120, 45, 120, 18,
                                     hDial, (HMENU)STATIC_ID_SURNAME, hInst, NULL);
                hStaticLanguage = CreateWindowEx(0,WC_STATIC, programmer.language,
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     120, 70, 120, 18,
                                     hDial, (HMENU)STATIC_ID_LANGUAGE, hInst, NULL);
                hStaticCompany = CreateWindowEx(0, WC_STATIC, programmer.company,
                                     WS_CHILD | WS_VISIBLE | WS_BORDER,
                                     120, 95, 120, 18,
                                     hDial, (HMENU)STATIC_ID_COMPANY, hInst, NULL);


        }
        return TRUE;

        case WM_CLOSE:
            {
            SetWindowText(hStaticName,programmer.name);
            EndDialog(hwndDlg, 0);
        }
        return TRUE;

        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
                case 1: {
                    EndDialog(hwndDlg, 0);
                }
                case 2: {
                    EndDialog(hwndDlg, 0);
                }
                default: {
                    printf("%i", LOWORD(wParam));
                    break;
                }
            }
        }
        return TRUE;
    }
    return FALSE;
}
