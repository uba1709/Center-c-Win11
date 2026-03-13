#include <windows.h>
#include <iostream>
using namespace std;

int WINDOW_WIDTH = 0;
int WINDOW_HEIGHT = 0;

void centerActiveWindow(){
    HWND hwnd = GetForegroundWindow();
    if (hwnd == NULL)
        return;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int x = (screenWidth - WINDOW_WIDTH) / 2;
    int y = (screenHeight - WINDOW_HEIGHT) / 2 - 24;
    SetWindowPos(
        hwnd,
        NULL,
        x,
        y,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SWP_NOZORDER | SWP_SHOWWINDOW
    );
}

void programLogic(){
    int choice;
    cout << "1. 21/9: 2440x1080\n";
    cout << "2. 16/9: 1600x900\n";
    cout << "choice: ";
    cin >> choice;
    switch (choice){
    case 1:
        WINDOW_WIDTH = 2440;
        WINDOW_HEIGHT = 1280;
        break;
    case 2:
        WINDOW_WIDTH = 1600;
        WINDOW_HEIGHT = 900;
        break;
    default:
        cout << "Invalid choice, using default 800x600.\n";
        WINDOW_WIDTH = 800;
        WINDOW_HEIGHT = 600;
        break;
    }
}

int main(){
    programLogic();
    if (!RegisterHotKey(NULL, 1, MOD_CONTROL | MOD_ALT, 'V'))
        return 1;
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)){
        if (msg.message == WM_HOTKEY){
            if (msg.wParam == 1){
                centerActiveWindow();
            }
        }
    }
    UnregisterHotKey(NULL, 1);
    return 0;
}