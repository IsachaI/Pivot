#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/map_data.h"
#include "../headers/map.h"

#define MAX_LINE 256

int ParseMapInfo(FILE *file, MapData *map){
    char line[MAX_LINE];

    while(fgets(line, sizeof(line), file)){
        if(strstr(line, "START")) break;
        if(strstr(line,"BPM")){
            sscanf(line,"%*[^:]: %f", &map->BPM);
        }
        if(strstr(line,"AR")){
            sscanf(line,"%*[^:]: %f", &map->AR);
        }
        if(strstr(line,"CS")){
            sscanf(line,"%*[^:]: %f", &map->CS);
        }
    }
    return 1;
}

int ParseCircles(FILE *file, MapData *map, int screenWidth, int screenHeight){
    char line[MAX_LINE];
    int count = 0;
    map->circle = malloc(sizeof(Circle) * MAX_CIRCLES);
    if(!map->circle) return 0;

    while(fgets(line, sizeof(line),file)){
        if(strstr(line,"END")) break;

        if(line[0] == '=' || line[0] == '\n' || line[0] == '/') continue;

        float time,x,y;
        int key;
            
        if (sscanf(line, "%f, %f, %f, %d", &time, &x, &y, &key) == 4) {
            if (count >= MAX_CIRCLES) break;
            
            map->circle[count].spawnTime = time;
            map->circle[count].position.x = x * screenHeight;
            map->circle[count].position.y = y * screenWidth;
            map->circle[count].key = key;
            map->circle[count].active = false;
            map->circle[count].isHit = false;
            map->circle[count].lifeTime = map->AR;
            map->circle[count].radius = map->CS;

            count++;
        }
    }
    map->totalCircles = count;
    return 1;
}

int LoadMapFromFile(const char *filename, MapData *map, int screenWidth, int screenHeight){
    FILE *file = fopen(filename, "r");
    if(!file){
        fprintf(stderr, "Failed to open %s/n", filename);
        return 0;
    }
    if(!ParseMapInfo(file, map)){
        fclose(file);
        return 0;
    }
    if(!ParseCircles(file, map, screenWidth, screenHeight)){
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
}