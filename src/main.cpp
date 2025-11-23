#include "raylib.h"
#include <cmath>


void CircleBoundsCollision(Vector2 &pos, float radius, int screenWidth, int screenHeight) {
    if (pos.x - radius < 0) pos.x = radius;
    if (pos.x + radius > screenWidth) pos.x = screenWidth - radius;
    if (pos.y - radius < 0) pos.y = radius;
    if (pos.y + radius > screenHeight) pos.y = screenHeight - radius;
}



int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Circle & Rectangle Collision");
    SetTargetFPS(60);

    //circle
    Vector2 circle_pos = {300.0f, screenHeight * 0.5f};
    float radius = 20.0f;

    // rectangle 
    Vector2 rectangle_pos = {600.0f, screenHeight * 0.5f};
    Vector2 rectangle_size = {30.0f, 70.0f};
    float rect_direction = 5.0f; // rectangle speed

    l_circle_x = circle_pos.x - radius;
    r_circle_x = circle_pos.x + radius;
    u_circle_y = circle_pos.y - radius;
    b_circle_y = circle_pos.y + radius;

    l_rectangle_x = rectangle_pos.x;
    r_rectangle_x = rectangle_pos.x + rectangle_size.y;
    u_rectangle_y = rectangle_pos.y;
    b_rectangle_y = rectangle_pos.x + rectangle_size.y;
    bool collision_with_rectangle = (b_rectangle_y >= u_circle_y) ; 
 
    while (!WindowShouldClose())
    {




        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (collision_with_rectangle){
            DrawText("Game Over!", 400, 300,20 , PURPLE);
        } else {
            if (IsKeyDown(KEY_RIGHT)) circle_pos.x += 5;
            if (IsKeyDown(KEY_LEFT))  circle_pos.x -= 5;
            if (IsKeyDown(KEY_UP))    circle_pos.y -= 5;
            if (IsKeyDown(KEY_DOWN))  circle_pos.y += 5;

            CircleBoundsCollision(circle_pos, radius, screenWidth, screenHeight);

            rectangle_pos.y += rect_direction;

            if (rectangle_pos.y < 0 || rectangle_pos.y + rectangle_size.y > screenHeight) {
                rect_direction = -rect_direction;
            }

            DrawCircleV(circle_pos, radius, BLUE);
            DrawRectangleV(rectangle_pos, rectangle_size, RED);

        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

