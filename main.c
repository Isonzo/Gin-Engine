#include "raylib.h"
#include <stdio.h>

int screenWidth = 400;
int screenHeight = 400;

int GetMouseButtonPressed();

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Game Window");
    SetTargetFPS(60);

    // Load Texture
    Texture2D cutieAmongUs = LoadTexture("resources/littleamogus.png");

    while (!WindowShouldClose())
    {
        // Print input
        printf("Key pressed: %d\n", GetKeyPressed());
        printf("Mouse button pressed: %d\n", GetMouseButtonPressed());
        printf("Current Mouse Position: x: %.2f, y: %.2f\n", GetMousePosition().x, GetMousePosition().y);
        printf("Mouse Wheel: %.2f\n", GetMouseWheelMove());
        printf("========================================\n");
        // Begin Drawing items on screen
        BeginDrawing();

        DrawTexture(cutieAmongUs, screenWidth/2, screenHeight/2, WHITE);

        EndDrawing();
    }

    UnloadTexture(cutieAmongUs);
    CloseWindow();
}

int GetMouseButtonPressed()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) return 1;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) return 2;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) return 3;
    else return 0;
}