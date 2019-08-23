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

// Compile With
// g++ -c -Wall autoclicker.cpp
// g++ -o autoclicker autoclicker.o ac.h -static

// OR
// g++ -Wall -o autoclicker autoclicker.cpp ac.h -static

#include <Windows.h>
#include <wtypes.h>
#include <winuser.h>
#include <chrono>
#include <iostream>
#include "ac.h"

using namespace std;

int main()
{
    std::cout << "Starting!\nLeft click to set lockation.\nRight click to start session.\n'E' to end session.\n'S' to pause session (Go Back To Location Loop).\n" << std::flush;

    int nX = 0;
    int nY = 0;
    float cX = 0;
    float cY = 0;

    GetDesktopResolution(nX, nY);

    while (1) {

        // If right mouse button is pressed.
        if (GetAsyncKeyState(VK_RBUTTON) < 0) {

            // If the location has not been set yet, set the position here.
            if (cX == 0 && cY == 0) {
                std::cout << "Needed to auto place.\n" << std::flush;
                POINT p;
                GetCursorPos(&p);
                cX = p.x;
                cY = p.y;

            }

            std::cout << "Should Have Started!\n" << std::flush;
            while (true) {
                SetCursorPos(cX, cY);
                ClickMouse("left", cX, cY, true, 100);

                // E Key Pressed
                // End the program.
                if (GetAsyncKeyState(0x45) < 0) {
                    std::cout << "Done!\n" << std::flush;
                    return 0;
                }

                // S Key Pressed
                // Pausing The Program (Back to set loop)
                if (GetAsyncKeyState(0x53) < 0) {
                    std::cout << "Pausing (Back to set loop).\n" << std::flush;
                    break;
                }
            }

        }

        // If left button is pressed.
        // Set the location of the click.
        if (GetAsyncKeyState(VK_LBUTTON) < 0) {
            std::cout << "Left Clicked. Set the location.\n" << std::flush;
            POINT p;
            GetCursorPos(&p);
            cX = p.x;
            cY = p.y;
        }

        if (GetAsyncKeyState(0x45) < 0) {
            std::cout << "Exiting...\n" << std::flush;
            return 0;
        }
    }
    return 0;
}
