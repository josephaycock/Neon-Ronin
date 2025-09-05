#ifndef LEVEL_H
#define LEVEL_H

#include <raylib.h>
#include <stddef.h>

#define TILE_SIZE    32
#define LEVEL_WIDTH  32
#define LEVEL_HEIGHT 18

// 0 = empty, 1 = solid
extern int levelData[LEVEL_HEIGHT][LEVEL_WIDTH];

// Loads one of the built-in rooms by id (0,1,2,…)
void Level_LoadRoom(int roomId);

// Draw current level
void Level_Draw(void);

#endif