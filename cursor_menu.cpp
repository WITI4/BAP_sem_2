#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

static int lastSelectedPosition = 0;

void setCursorPos(int y) {
    static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, { 0, (short)y });
}

int showMenu(const std::string& title, const std::string opts[], int count, bool rememberPosition = false) {
    srand(time(0));
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");
    std::cout << title << '\n' << std::string(50, '-') << '\n';

    int ch = rememberPosition ? lastSelectedPosition : 0;
    if (ch >= count) ch = 0;

    for (int i = 0; i < count; i++) {
        setCursorPos(i + 2);
        std::cout << "  " << opts[i];
    }

    int prev = -1;
    while (true) {
        if (prev != ch) {
            if (prev >= 0) {
                setCursorPos(prev + 2);
                SetConsoleTextAttribute(h, 7);
                std::cout << "  " << opts[prev];
            }

            setCursorPos(ch + 2);
            int pipeColor = rand() % 6 + 9;
            int backgroundColor = (pipeColor - 8) << 4;

            SetConsoleTextAttribute(h, pipeColor);
            std::cout << " |";
            SetConsoleTextAttribute(h, backgroundColor | 7);
            std::cout << opts[ch];
            SetConsoleTextAttribute(h, 7);

            prev = ch;
        }

        switch (_getch()) {
        case 224: case 0:
            switch (_getch()) {
            case 72: ch = (ch - 1 + count) % count; break; // ¬верх
            case 80: ch = (ch + 1) % count; break; // ¬низ
            } break;
        case 13:
            if (rememberPosition) {
                lastSelectedPosition = ch;
            }
            setCursorPos(count + 3);
            return ch; // Enter
        }
    }
}