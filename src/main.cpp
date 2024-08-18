#include "raylib.h"
#include <cmath>

typedef struct Vector2D {
  float x;
  float y;
} Vector2D;

typedef struct Body {
  Vector2D position;
  Vector2D velocity;
  Vector2D acceleration;
  float mass;
} Body;

void UpdatePhysics(Body *body1, Body *body2, float dt) {
  float dx = body2->position.x - body1->position.x;
  float dy = body2->position.y - body1->position.y;
  float distance = sqrt(pow(dx, 2) + pow(dy, 2));

  if (distance == 0)
    return;

  float G = 1.0f;
  float force = (G * body1->mass * body2->mass) / (pow(distance, 2));

  Vector2D direction = {dx / distance, dy / distance};
  body1->acceleration.x = force / body1->mass * direction.x;
  body1->acceleration.y = force / body1->mass * direction.y;
  body2->acceleration.x = -force / body2->mass * direction.x;
  body2->acceleration.y = -force / body2->mass * direction.y;

  body1->velocity.x += body1->acceleration.x * dt;
  body1->velocity.y += body1->acceleration.y * dt;
  body2->velocity.x += body2->acceleration.x * dt;
  body2->velocity.y += body2->acceleration.y * dt;

  body1->position.x += body1->velocity.x * dt;
  body1->position.y += body1->velocity.y * dt;
  body2->position.x += body2->velocity.x * dt;
  body2->position.y += body2->velocity.y * dt;
}

int main() {
  const int screenWidth = 800;
  const int screenHeight = 445;

  const float r1 = 35;
  const float r2 = 10;

  Body body1 = {{200.0f, 200.0f}, {0, 0}, {0, 0}, r1 * 10000};
  Body body2 = {{600.0f, 300.0f}, {0, -10}, {0, 0}, r2 * 10000};
  const float dt = 0.001f;

  InitWindow(screenWidth, screenHeight, "Gravity Simulation");

  while (!WindowShouldClose()) {
    UpdatePhysics(&body1, &body2, dt);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircle(body1.position.x, body1.position.y, r1, ORANGE);
    DrawCircle(body2.position.x, body2.position.y, r2, RED);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
