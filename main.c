#include "raylib.h"

int screenWidth = 400;
int screenHeight = 400;

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Game Window");
    SetTargetFPS(60);

    // Load Texture
    Texture2D cutieAmongUs = LoadTexture("resources/littleamogus.png");

    while (!WindowShouldClose())
    {
        // Begin Drawing items on screen
        BeginDrawing();

        DrawTexture(cutieAmongUs, screenWidth/2, screenHeight/2, WHITE);

        EndDrawing();
    }

    UnloadTexture(cutieAmongUs);
    CloseWindow();
}