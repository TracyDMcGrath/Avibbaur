#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void) {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Avibbaur");

  while (!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(BLACK);

    DrawText("This is text", 100, 100, 20, GREEN);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
