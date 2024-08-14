#include "raylib.h"
#include "raymath.h"

int main() {

  InitWindow(400, 224, "bigga");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
