#include "debug.h"
#include <stdio.h>

// FPS Counter
void Draw_FPS_Counter() {
    DrawFPS(10, 10);
}

// Player Info
void Draw_Player_Info(const Player* p, int x, int y) {
    char buffer[128];
    sprintf(buffer, "pos(%.2f, %.2f) vel(%.2f, %.2f) on Ground: %d", 
        p->position.x, p->position.y, 
        p->velocity.x, p->velocity.y, 
        p->onGround);
    DrawText(buffer, x, y, 10, RED);
}