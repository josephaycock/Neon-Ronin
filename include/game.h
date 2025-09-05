#ifndef GAME_H
#define GAME_H

#include "player.h"

// Game states 
typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
    GAME_OVER,
} GameState;

// Game structure
typedef struct {
    GameState state;
    Player player;
} Game;


// --- Functions ---

// Intilialize the game
void Game_Initialize(Game* g);

// Update the game state
void Game_Update(Game* g, float dt);

// Draw the game 
void Game_Draw(const Game* g);

#endif