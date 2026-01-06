#include <raylib.h>

// define some constants
#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 400
#define FONT_SIZE 32
#define SPEED 4

typedef struct {
  Vector2 position;
  Vector2 velocity;
  float width;
  float height;
  char *glyph;
  Color color;
  float health;
  float damage;
  int alive;
} Entity;

void updateEntity(Entity *);
void drawEntity(Entity *, Font *);

// main function
int main(void) {

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Avibbaur");
  SetTargetFPS(60);

  //  init game

  // init player
  Entity player = {
      {111, 117}, {0, 0}, FONT_SIZE * 0.6, FONT_SIZE, "@", GREEN, 10, 0, 1};

  Font fontTtf = LoadFontEx("resources/MonofurNerdFontMono-Regular.ttf",
                            FONT_SIZE, 0, 250);

  SetTextLineSpacing(16);

  // main game loop
  while (!WindowShouldClose()) {

    updateEntity(&player);

    // draw loop
    BeginDrawing();

    ClearBackground(BLACK);

    drawEntity(&player, &fontTtf);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}

void updateEntity(Entity *ptrEnt) {
  // handle input
  if (IsKeyDown(KEY_RIGHT)) {
    ptrEnt->velocity.x = SPEED;
  } else if (IsKeyDown(KEY_LEFT)) {
    ptrEnt->velocity.x = -SPEED;
  } else {
    ptrEnt->velocity.x = 0;
  }

  if (IsKeyDown(KEY_DOWN)) {
    ptrEnt->velocity.y = SPEED;
  } else if (IsKeyDown(KEY_UP)) {
    ptrEnt->velocity.y = -SPEED;
  } else {
    ptrEnt->velocity.y = 0;
  }

  // update ptrEnt->position
  ptrEnt->position.x += ptrEnt->velocity.x;
  ptrEnt->position.y += ptrEnt->velocity.y;

  if (ptrEnt->position.x < 0) {
    ptrEnt->position.x = 0;
  } else if (ptrEnt->position.x > SCREEN_WIDTH - ptrEnt->width) {
    ptrEnt->position.x = SCREEN_WIDTH - ptrEnt->width;
  }

  if (ptrEnt->position.y < 0) {
    ptrEnt->position.y = 0;
  } else if (ptrEnt->position.y > SCREEN_HEIGHT - ptrEnt->height) {
    ptrEnt->position.y = SCREEN_HEIGHT - ptrEnt->height;
  }
}

void drawEntity(Entity *ptrEnt, Font *font) {

  // draw player
  DrawTextEx(*font, ptrEnt->glyph, ptrEnt->position, FONT_SIZE, 2, GREEN);
}
