#ifndef MAP_H
#define MAP_H
#define MAX_MAPS 128

#include <raylib.h>
#include"map_data.h"

typedef struct {
    const char *name;
    const char *musicfile;
} MapEntry;

extern Music currentMusic;
extern bool isMusicLoaded;

extern MapEntry maps[MAX_MAPS];
extern const int mapCount;
extern int totalLoadedMaps;
extern MapData allMaps[MAX_MAPS];

int InitAllMaps(MapEntry maps[], int mapCount);

void InitMap(MapData *map, int mapIndex, int screenWidth, int screenHeight);  // Declaration for the init function

#endif
