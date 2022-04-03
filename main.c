#include "include/raylib.h"
#include <stdio.h>

#define SCREENWIDTH 400
#define SCREENHEIGHT 400

void printKeyboardEvent(void);
void printMouseEvent(void);
int GetMouseButtonPressed(void);

int main(void)
{
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Game Window");
    SetTargetFPS(60);

    // Load Texture
    Texture2D cutieAmongUs = LoadTexture("resources/littleamogus.png");

    while (!WindowShouldClose())
    {
        // Debug Input
        printKeyboardEvent();
        printMouseEvent();
        // Begin Drawing items on screen
        BeginDrawing();

        DrawTexture(cutieAmongUs, SCREENWIDTH/2, SCREENHEIGHT/2, WHITE);

        EndDrawing();
    }

    UnloadTexture(cutieAmongUs);
    CloseWindow();
}

void printKeyboardEvent(void)
{
    int key = GetKeyPressed();
    if (key) printf("Key pressed: %d\n", key);
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