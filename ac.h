#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <chrono>
#include <wtypes.h>

using namespace std;

void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);

    horizontal = desktop.right;
    vertical = desktop.bottom;
}

void ClickMouse(string mouse, int posx, int posy, bool wait = false, int slptime = 1000)
{
    if (mouse == "left")
    {
        SetCursorPos(posx, posy);
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, posx, posy, 0, 0);
        if (wait) {
            Sleep(slptime);
        }
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP, posx, posy, 0, 0);

    }
    else if (mouse == "right")
    {
        SetCursorPos(posx, posy);
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN, posx, posy, 0, 0);
        if (wait) {
            Sleep(slptime);
        }
        mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP, posx, posy, 0, 0);
    }

}
