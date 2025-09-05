#include <raylib.h>
#include <raymath.h>
#include "player.h"
#include "constants.h"

#define PLAYER_SPEED 220.0f     // px/s
#define GRAVITY      1800.0f    // px/s^2
#define JUMP_FORCE   -650.0f    // px/s
#define TERMINAL_VEL 900.0f     // px/s

// Initialize player
void Player_Initialize(Player* p, Vector2 startPos, Vector2 startVel) {
    p->position = startPos;
    p->velocity = startVel;
    p->onGround = true;
}

void Player_Update(Player* p, float dt) {
    // Horizontal movement: use constant speed (px/s), not velocity.x as "speed"
    float dx = 0.0f;
    if (IsKeyDown(KEY_RIGHT)) dx += 1.0f;
    if (IsKeyDown(KEY_LEFT))  dx -= 1.0f;
    p->position.x += dx * PLAYER_SPEED * dt;

    // Jumping: set instantaneous upward velocity in px/s
    if (IsKeyPressed(KEY_UP) && p->onGround) {
        p->velocity.y = JUMP_FORCE;
        p->onGround = false;
    }

    // Gravity (px/s^2) integrated with dt
    p->velocity.y += GRAVITY * dt;

    // Clamp terminal velocity
    if (p->velocity.y > TERMINAL_VEL) p->velocity.y = TERMINAL_VEL;

    // Integrate vertical position
    p->position.y += p->velocity.y * dt;

    // Ground collision
    if (p->position.y >= SCREEN_HEIGHT - 32) {
        p->position.y = SCREEN_HEIGHT - 32;
        p->velocity.y = 0.0f;
        p->onGround = true;
    }
}

// Clamp player position to screen bounds
void Player_ClampToScreen(Player* p) {
    if (p->position.x < 0) p->position.x = 0; // Left bound
    if (p->position.x > SCREEN_WIDTH - 32) p->position.x = SCREEN_WIDTH - 32; // Right bound
    if (p->position.y < 0) p->position.y = 0; // Top bound
    if (p->position.y > SCREEN_HEIGHT - 32) p->position.y = SCREEN_HEIGHT - 32; // Bottom bound
}

// Draw player
void Player_Draw(const Player* p) {
    DrawRectangleV(p->position, (Vector2) { 32,32 }, RED);
}