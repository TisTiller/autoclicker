/*
    Auto Clicker - An Auto Clicker
    Copyright (C) 2019 Tyler Rose

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

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
