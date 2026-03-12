#include <windows.h>
#include <iostream>
using namespace std;

enum class Operation{
    weith = 1,
    normal,
};

const int WINDOW_WIDTH = 2440;
const int WINDOW_HEIGHT = 1280;

void centerActiveWindow(){
    HWND hwnd = GetForegroundWindow();
    if (hwnd == NULL)
        return;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int x = (screenWidth - WINDOW_WIDTH) / 2;
    int y = (screenHeight - WINDOW_HEIGHT) / 2;
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

int windowSetting(int choice){
    cout << "choice: ";
    cin >> choice;
    cout << "1. 21/9: 2440x1080";
    cout << "2. 16/10: 1600x900";
    return choice;
}

int main(){
    int choice;
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