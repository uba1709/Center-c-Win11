#include <iostream>
#include <windows.h>
#include <winuser.h>
using namespace std;

const int WINDOW_WIDTH = 2440;
const int WINDOW_HEIGHT = 1080;

void centerActiceWindow(){
    HWND hwnd = GetForegroundWindow();
    if(hwnd == NULL)
        cout << "Nie zaleziono aktulanego okna\n";

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CXSCREEN);

    int x = (screenWidth - WINDOW_WIDTH) / 2;
    int y = (screenHeight - WINDOW_HEIGHT) /2;
}

int main(){
    cout << "Program uruchomiony\n";
    cout << "Skrot to: CTRL + ALT + C\n";

    if(!RegisterHotKey(NULL, 1, MOD_CONTROL | MOD_ALT, 'c')){
        cout << "Nie udalo sie zarejesrowac skrotu\n";
        return 1;
    }
    MSG msg;

    while(GetMessage(&msg, NULL, 0, 0)){
        if(msg.message == WM_HOTKEY){
            if(msg.wParam == 1){
                centerActiceWindow();
            }
        }
    }
    UnregisterHotKey(NULL, 1);
    return 1;
}