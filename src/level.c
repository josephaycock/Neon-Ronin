#include <string.h>
#include "level.h"
#include "level_maps.h"

int levelData[LEVEL_HEIGHT][LEVEL_WIDTH];

void Level_LoadRoom(int roomId) {
    const int (*src)[LEVEL_WIDTH] = NULL;

    switch (roomId) {
        case 0: src = ROOM_0; break;
        case 1: src = ROOM_1; break;
        default: src = ROOM_0; break; // fallback
    }

    // copy into the active level buffer
    memcpy(levelData, src, sizeof(levelData));
}

void Level_Draw(void) {
    for (int y = 0; y < LEVEL_HEIGHT; y++) {
        for (int x = 0; x < LEVEL_WIDTH; x++) {
            if (levelData[y][x] == 1) {
                DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGRAY);
            }
        }
    }
}