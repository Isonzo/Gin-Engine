#include "include/raylib.h" //Capturing input
#include <stdio.h> //printf functionality
#include <stdbool.h> //bool data type
#include "include/inputDebugger.h"

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
    bool mouseClicked = printAndDetectClick();
    Vector2 mousePos = GetMousePosition();
    double mouseWheel = GetMouseWheelMove();

    if (mouseClicked)
    {
        printf("Current Mouse Position: x: %.2f, y: %.2f\n", mousePos.x, mousePos.y);
    }

    if (mouseWheel)
    {
        printf("Mouse wheel direction: %.2f\n", mouseWheel);
        printf("Current Mouse Position: x: %.2f, y: %.2f\n", mousePos.x, mousePos.y);
    }
}

bool printAndDetectClick(void)
{
    /*
    Basically, these numbers give a different sum for each combination of buttons.
    By looking at the resulting sum, we can determine which combination of buttons have been pressed!
    For example, a return value of 3 means that both the left and right mouse buttons have
    been pressed.

    Pretty neat and elegant, right?
    */
    bool clicked = false;

    for (int i = 0; i < 7; ++i)
    {
        if (IsMouseButtonPressed(i)) 
        {
            clicked = true;
            printf("%d ", i);
        }
    }

    return clicked;

}