#include "raylib.h"
#include <cmath>

typedef struct VectorEntity2 {
  float magnitude;
  float direction;
} VectorEntity2;

typedef struct Body {
  float x;
  float y;
  float mass;
  Vector2 velocity;
  VectorEntity2 acceleration;
} Body;

int main() {
  const int screenWidth = 800;
  const int screenHeight = 445;

  const float r1 = 35;
  const float r2 = 10;

  Body body1 = {200.0f, 120.0f, r1 * 10000, {0, 0}, {0, 0}};
  Body body2 = {600.0f, 120.0f, r2 * 10000, {0, 0}, {0, 0}};
  const float dt = 0.001f;

  InitWindow(screenWidth, screenHeight, "trash gravity");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawCircle(body1.x, body1.y, r1, ORANGE);
    DrawCircle(body2.x, body2.y, r2, RED);

    DrawLineV({body1.x, body1.y},
              {body1.x + 100 * cos(body1.acceleration.direction),
               body1.y + 100 * sin(body1.acceleration.direction)},
              GREEN);
    DrawLineV({body2.x, body2.y},
              {body2.x + 100 * cos(body2.acceleration.direction),
               body2.y + 100 * sin(body2.acceleration.direction)},
              GREEN);

    EndDrawing();

    // update position
    const float x1 = body1.x;
    const float x2 = body2.x;

    const float y1 = body1.y;
    const float y2 = body2.y;

    float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    float force = (body1.mass * body2.mass) / pow(distance, 2);

    body1.acceleration.magnitude = force / body1.mass;
    body2.acceleration.magnitude = force / body2.mass;

    body1.acceleration.direction = atan2(y2 - y1, x2 - x1);
    body2.acceleration.direction = atan2(y1 - y2, x1 - x2);

    body1.velocity.x +=
        body1.acceleration.magnitude * cos(body1.acceleration.direction) * dt;
    body1.velocity.y +=
        body1.acceleration.magnitude * sin(body1.acceleration.direction) * dt;

    body2.velocity.x +=
        body2.acceleration.magnitude * cos(body2.acceleration.direction) * dt;
    body2.velocity.y +=
        body2.acceleration.magnitude * sin(body2.acceleration.direction) * dt;

    body1.x += body1.velocity.x * dt;
    body1.y += body1.velocity.y * dt;

    body2.x += body2.velocity.x * dt;
    body2.y += body2.velocity.y * dt;
  }

  CloseWindow();

  return 0;
}
