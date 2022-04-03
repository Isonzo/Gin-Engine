#include "include/raylib.h"
#include "include/inputDebugger.h"

#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Window");
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

        DrawTexture(cutieAmongUs, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, WHITE);

        EndDrawing();
    }

    UnloadTexture(cutieAmongUs);
    CloseWindow();
}