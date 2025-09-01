#include <raylib.h>
#include <raymath.h>
#include "player.h"
#include "constants.h"

#define GRAVITY 0.11f
#define JUMP_FORCE -6.5f

// Initialize player
void Player_Initialize(Player* p, Vector2 startPos, Vector2 startVel) {
    p->position = startPos;
    p->velocity = startVel;
    p->onGround = true;
}

// Update player state
void Player_Update(Player* p) {
    // Basic movement
    if (IsKeyDown(KEY_RIGHT)) p->position.x += p->velocity.x; // Move right
    if (IsKeyDown(KEY_LEFT)) p->position.x -= p->velocity.x; // Move left

    // Jumping mechanics
    if (IsKeyPressed(KEY_UP) && p->onGround) {
        p->velocity.y = JUMP_FORCE;
        p->onGround = false;
    }

    p->velocity.y += GRAVITY; // Apply gravity
    p->position.y += p->velocity.y; // Update vertical position

    // Terminal velocity
    if (p->velocity.y > 10) p->velocity.y = 10;

    // Simple ground collision
    if (p->position.y >= SCREEN_HEIGHT - 32) {
        p->position.y = SCREEN_HEIGHT - 32; // Ground level
        p->velocity.y = 0;
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