#include "raylib.h"

int main() {
    constexpr auto screenWidth = 800;
    constexpr auto screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "My Window");
    SetTargetFPS(60);

    Vector2 vertices[3] = {
        { 200, 200 },
        { 600, 200 },
        { 400, 500 }
    };

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        for (int i = 0; i <= screenWidth; i += 100) {
            DrawLine(i, 0, i, screenHeight, LIGHTGRAY);
        }

        for (int i = 0; i <= screenHeight; i += 100) {
            DrawLine(0, i, screenWidth, i, LIGHTGRAY);
        }

        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, BLACK);
        DrawLine(0, screenHeight / 2, screenWidth, screenHeight / 2, BLACK);

        DrawTriangleLines(vertices[0], vertices[1], vertices[2], RED);

        auto midOfScreen = Vector2{ screenWidth / 2.0f, screenHeight / 2.0f };

        auto midOfTriangle = Vector2{ (vertices[0].x + vertices[1].x + vertices[2].x) / 3.0f,
        			(vertices[0].y + vertices[1].y + vertices[2].y) / 3.0f };

        DrawCircle(midOfTriangle.x, midOfTriangle.y, 5, RED);

        Vector2 topLeft = { 0, 0 };
        Vector2 topRight = { screenWidth, 0 };
        Vector2 bottomLeft = { 0, screenHeight };
        Vector2 bottomRight = { screenWidth, screenHeight };

        DrawLineV(topLeft, bottomRight, ORANGE);
        DrawLineV(topRight, bottomLeft, ORANGE);
        DrawLineV(topLeft, topRight, ORANGE);
        DrawLineV(topRight, bottomRight, ORANGE);
        DrawLineV(bottomRight, bottomLeft, ORANGE);
        DrawLineV(bottomLeft, topLeft, ORANGE);
        

        Vector2 a = { 400.f, 300.f };
        Vector2 b = { 500.f, 300.f };
        Vector2 c = { 500.f, 100.f };
        Vector2 d = { 400.f, 100.f };

        // print mid point text
        DrawText("(4,3)", 400, 300, 20, BLACK);
        DrawText("(5,5)", 500, 500, 20, BLACK);
        DrawText("(1,3)", 100, 300, 20, BLACK);

        // draw triangle
        DrawTriangle(a, b, c, VIOLET);
        DrawTriangle(a, b, d, VIOLET);

        DrawLineV(a,b,BLUE);
        //DrawLineV(b,c,BLUE);
        //DrawLineV(c,a,BLUE);

        //DrawTriangle(a, b, c, VIOLET);
        //DrawTriangleLines(a, b, c, VIOLET);

        /*DrawLine(400,300,0,0,DARKGREEN);*/

        EndDrawing();
    }

    CloseWindow();

    return 0;
}