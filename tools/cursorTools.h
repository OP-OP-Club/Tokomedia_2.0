#ifndef CURSOR_POSITION_PARAM
#define CURSOR_POSITION_PARAM 1

#include "hasherTools.h"
#include "timeTools.h"
#include "descriptionConverter.h"
#include "generator.h"

void SetCursorPosition(int x, int y);
void SetCursorVisible(bool flag);

void SetCursorPosition(int x, int y) {
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void SetCursorVisible(bool flag){
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = flag;
    lpCursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&lpCursor);
}

#endif // CURSOR_POSITION_PARAM
