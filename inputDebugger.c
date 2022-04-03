#include "include/raylib.h" //Capturing input
#include <stdio.h> //printf functionality
#include <stdbool.h> //bool data type

void printKeyboardEvent(void);
void printMouseEvent(void);
int GetMouseButtonPressed(void);

void printKeyboardEvent(void)
{
    bool first_key = true;
    for (char i = '0'; i < '~'; ++i)
        {
            bool key = IsKeyPressed(i);
            if (key)
            {
                if (first_key)
                {
                    first_key = false;
                    printf("Pressed: ");
                }
                printf("%c ", i);
            }
        }
    if (!first_key) printf("\n");
}

void printMouseEvent(void)
{
    int mouseClick = GetMouseButtonPressed();
    Vector2 mousePos = GetMousePosition();
    double mouseWheel = GetMouseWheelMove();

    if (mouseClick)
    {
        printf("Mouse button pressed: %d\n", mouseClick);
        printf("Current Mouse Position: x: %.2f, y: %.2f\n", mousePos.x, mousePos.y);
    }

    if (mouseWheel)
    {
        printf("Mouse wheel direction: %.2f\n", mouseWheel);
        printf("Current Mouse Position: x: %.2f, y: %.2f\n", mousePos.x, mousePos.y);
    }
}

int GetMouseButtonPressed(void)
{
    /*
    Basically, these numbers give a different sum for each combination of buttons.
    By looking at the resulting sum, we can determine which combination of buttons have been pressed!
    For example, a return value of 3 means that both the left and right mouse buttons have
    been pressed.

    Pretty neat and elegant, right?
    */

    int combo = 0;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) combo += 1;
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) combo += 2;
    if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) combo += 4;

    return combo;
}