#include "winconapi.h"

int getX() {
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hout, &sbi);
    return sbi.dwCursorPosition.X;
}

int getY() {
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hout, &sbi);
    return sbi.dwCursorPosition.X;
}

void jumpTo(int x, int y) {
    COORD pos;
    pos.X = x; pos.Y = y;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hout, pos);
}