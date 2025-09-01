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

    while (!WindowShouldClose()) {
        // Update
        Game_Update(&game);

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