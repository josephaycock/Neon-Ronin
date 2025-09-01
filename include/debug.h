#ifndef DEBUG_H
#define DEBUG_H

#include <raylib.h>
#include "player.h"

// --- Functions ---

// FPS Counter
void Draw_FPS_Counter();

// Player Info
void Draw_Player_Info(const Player* p, int x, int y);

#endif