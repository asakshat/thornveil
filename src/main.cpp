#include "raylib.h"
#include "game.h"

int main() {
    InitWindow(800, 450, "My C++ Raylib Game");
    InitGame(); // initialize game state

    while (!WindowShouldClose()) {
        UpdateGame();   // game logic
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawGame();     // draw everything
        EndDrawing();
    }

    CloseGame();       // free resources
    CloseWindow();
    return 0;
}

