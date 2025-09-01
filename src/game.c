#include <raylib.h>
#include <raymath.h>
#include "constants.h"
#include "game.h"

// Initialize the game
void Game_Initialize(Game* g) {
    g->state = GAME_STATE_MENU; // Start in menu state
    Player_Initialize(&g->player, (Vector2){ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f }, (Vector2){ 1, 1 }); // Initialize player in center of screen
}

// Update the game state
void Game_Update(Game* g) {
    switch (g->state) {
        case GAME_STATE_MENU:
            // Handle menu logic
            if (IsKeyPressed(KEY_SPACE)) {
                g->state = GAME_STATE_PLAYING;
            }
            break;
        case GAME_STATE_PLAYING:
            // Handle gameplay logic
            Player_Update(&g->player); // Update player
            Player_ClampToScreen(&g->player); // Keep player on screen
            break;
        case GAME_OVER:
            // Handle game over logic
            break;
    }
}

// Draw the game
void Game_Draw(const Game* g) {

    // Draw current game state
    switch (g->state) {
        case GAME_STATE_MENU:
            // Handle menu drawing
            DrawText("Press SPACE to Start", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, 20, DARKGRAY);
            break;
        case GAME_STATE_PLAYING:
            // Handle gameplay drawing
            // Debugging:
            // ----------------------------------
            // Grid
            for (int x = 0; x < SCREEN_WIDTH; x += 32) 
                DrawLine(x, 0, x, SCREEN_HEIGHT, GREEN);
            for (int y = 0; y < SCREEN_HEIGHT; y += 32)
                DrawLine(0, y, SCREEN_WIDTH, y, GREEN);
            // Player
            Player_Draw(&g->player);
            break;
        case GAME_OVER:
            // Handle game over drawing
            break;
        default:
            break;
    }
}
