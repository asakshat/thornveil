#include "game.h"
#include "raylib.h"

static Vector2 circlePos = {400, 225};
static float circleSpeed = 200.0f;

void InitGame() {
    circlePos = {400, 225};  // starting position
}

void UpdateGame() {
    float delta = GetFrameTime();
    if (IsKeyDown(KEY_RIGHT)) circlePos.x += circleSpeed * delta;
    if (IsKeyDown(KEY_LEFT))  circlePos.x -= circleSpeed * delta;
    if (IsKeyDown(KEY_DOWN))  circlePos.y += circleSpeed * delta;
    if (IsKeyDown(KEY_UP))    circlePos.y -= circleSpeed * delta;
}

void DrawGame() {
    DrawCircleV(circlePos, 20, RED);
}

void CloseGame() {
}

