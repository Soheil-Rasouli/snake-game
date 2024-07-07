#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <chrono>  // For std::chrono
#include <thread>  // For std::this_thread::sleep_for

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

#ifdef _WIN32
void gotoxy(int x, int y) {
    COORD CursorPosition;
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
#else
void gotoxy(int x, int y) {
    cout << "\033[" << y << ";" << x << "H";
}
#endif

void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
#endif
}

class point {
private:
    int x, y;
public:
    point(int x, int y) : x(x), y(y) {}
    point() : x(0), y(0) {}

    void setpoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    void moveUP() {
        y--;
    }
    void moveDown() {
        y++;
    }
    void moveRight() {
        x++;
    }
    void moveLeft() {
        x--;
    }
    void Draw() const {
        gotoxy(x, y);
        cout << "*";
    }
    void erase() const {
        gotoxy(x, y);
        cout << " ";
    }
};

int X = 0;
int Y = 0;

void feed() {
    X = rand() % 50;
    Y = rand() % 50;
    gotoxy(X, Y);
    cout << "#";
}

int main() {
    srand(time(0)); // Initialize random seed

    int size = 6;
    point a[10];

    while (true) {
        feed();
        for (int pashmak = 1; pashmak <= size; pashmak++) {
            a[pashmak].setpoint(pashmak, 1);
        }

        while (a[size].getX() < X) {
            for (int f = 1; f <= size; f++) {
                a[f].moveRight();
                a[f].Draw();
                sleep_ms(10);
                a[1].erase();

                if (a[f].getX() == X) {
                    for (int g = 1; g <= size; g++) {
                        a[g].erase();
                    }
                }
            }
        }

        for (int pashmak = 1; pashmak <= size; pashmak++) {
            a[pashmak].setpoint(X, pashmak);
        }

        while (a[1].getY() < Y) {
            for (int f = 1; f <= size; f++) {
                a[f].moveDown();
                a[f].Draw();
                sleep_ms(10);
                a[1].erase();
                if (a[f].getY() == Y) {
                    break;
                }
            }
        }

        for (int pashmak = 1; pashmak <= size; pashmak++) {
            a[pashmak].setpoint(X, pashmak);
        }

        while (a[1].getY() > Y) {
            for (int f = 1; f <= size; f++) {
                a[f].moveUP();
                a[f].Draw();
                sleep_ms(10);
                a[1].erase();
                if (a[f].getY() == Y) {
                    break;
                }
            }
        }

        for (int pashmak = 1; pashmak <= size; pashmak++) {
            a[pashmak].setpoint(1, pashmak);
        }

        while (a[size].getX() > X) {
            for (int f = 1; f <= size; f++) {
                a[f].moveLeft();
                a[f].Draw();
                sleep_ms(10);
                a[1].erase();

                if (a[f].getX() == X) {
                    for (int g = 1; g <= size; g++) {
                        a[g].erase();
                    }
                }
            }
        }
    }

    return 0;
}
