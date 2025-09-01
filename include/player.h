#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <stdbool.h>

// Player structure
typedef struct {
    Vector2 position;
    Vector2 velocity;
    bool onGround;
} Player;

// --- Functions ---

// Initialize player
void Player_Initialize(Player* p, Vector2 startPos, Vector2 startVel);

// Update player state
void Player_Update(Player* p);

// Clamp player position to screen bounds
void Player_ClampToScreen(Player* p);

// Draw player
void Player_Draw(const Player* p);

#endif