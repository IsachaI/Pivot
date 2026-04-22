#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map_data.h"
#include "map.h"



int ParseMapInfo(FILE *file, MapData *map, int screenHeigth, int screenWidth);
int ParseCircles(FILE *file, MapData *map, int screenHeight, int screenWidth);
/**
Open files then loads data, returns 0 if failed
* @param filename 
* @param MapData
* @return 0 on fail 1 on success
*/
int LoadMapFromFile(const char *filename, MapData *map, int screenHeight, int screenWidth);
