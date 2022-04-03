#include "raylib.h"
#include <stdio.h>

int screenWidth = 400;
int screenHeight = 400;

void printKeyboardEvent(void);
void printMouseEvent(void);
int GetMouseButtonPressed(void);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Game Window");
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

        DrawTexture(cutieAmongUs, screenWidth/2, screenHeight/2, WHITE);

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
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) return 1;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) return 2;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) return 3;
    else return 0;
}