#include <raylib.h>

// define some constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

struct Player {
  Vector2 position;
  Vector2 velocity;
  Vector2 acceleration;
};

// main function
int main(void) {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Avibbaur");
  SetTargetFPS(60);

  //  init game

  struct Player player = {{111, 117}, {0, 0}, {0.011, 0.009}};

  // main game loop
  while (!WindowShouldClose()) {

    // update loop
    player.velocity.x += player.acceleration.x;
    player.velocity.y += player.acceleration.y;
    player.position.x += player.velocity.x;
    player.position.y += player.velocity.y;

    if (player.position.x < 0 || player.position.x > SCREEN_WIDTH) {
      player.acceleration.x *= -1;
      player.velocity.x *= -1;
    }

    if (player.position.y < 0 || player.position.y > SCREEN_HEIGHT) {
      player.acceleration.y *= -1;
      player.velocity.y *= -1;
    }

    // draw loop
    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("@", player.position.x, player.position.y, 20, GREEN);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
