#include <raylib.h>
#include <raymath.h>
#include "constants.h"
#include "game.h"
#include "debug.h"

/* 
*  Template 5.5 - Basic window 
*  ----------------------------------------------------------------------------------
*  To run example, just press F5 or go to Build and Run
*  or
*  Manually complile using the following script: 
*
*  make build_osx
*  ./bin/build_osx
*/

int main(void) {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Neon Ronin");

    Game game; // Game instance
    Game_Initialize(&game); // Initialize game

    SetTargetFPS(120);               // Set our game to run at 120 frames-per-second

    while (!WindowShouldClose()) {
        // delta time
        float dt = GetFrameTime();

        // Update
        Game_Update(&game, dt);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw game
        Game_Draw(&game);

        // Debug Info
        Draw_FPS_Counter();
        Draw_Player_Info(&game.player, 10, 30);

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}