#include <raylib.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "../headers/map.h"
#include"../headers/map_data.h"

int totalLoadedMaps = 0;
MapData allMaps[MAX_MAPS];
MapEntry maps[] = {
    {"Map 1", "assets/music1.mp3"},
    {"Map 2", "assets/music2.mp3"}
};

const int mapCount = sizeof(maps)/sizeof(maps[0]);

float distances[5] = {100,150,200,250,300};
int keys[5] = {KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T};
const char *labels[5] = {"Q", "W", "E", "R", "T"};

int InitAllMaps(MapEntry maps[], int mapCount){
    for (int i = 0; i<mapCount; i++){
        allMaps[i].music = LoadMusicStream(maps[i].musicfile);
        allMaps[i].isLoaded = true;
        allMaps[i].duration = GetMusicTimeLength(allMaps[i].music);
        allMaps[i].elapsedTime = 0.0f;
        allMaps[i].totalCircles = 0;
        allMaps[i].circlesHit = 0;
        allMaps[i].circle = malloc(sizeof(Circle) * MAX_CIRCLES);
    }
    totalLoadedMaps = mapCount;
    return totalLoadedMaps;
}

void InitMap(MapData *map, int mapIndex, int screenWidth, int screenHeight) {
    Vector2 screenCenter = {
        .x = screenWidth /2.0f,
        .y = screenHeight / 2.0f
    };

    map->BPM = 120.0f;
    map->totalCircles = 3;

    map->circle = malloc(sizeof(Circle) * map->totalCircles);
    if (!map->circle){
        fprintf(stderr, "fail\n");
        return;
    }
    for (int i = 0; i < map->totalCircles; i++){

        int type = i % 5;

        float angle = (float)i * (PI / 6);
        float dist = distances[type];

        map->circle[i].position.x = screenCenter.x + cosf(angle) * dist;
        map->circle[i].position.y = screenCenter.y + sinf(angle) * dist;
        map->circle[i].radius = 30;

        map->circle[i].lifeTime = 2.0f;
        map->circle[i].spawnTime = i* 2.0f;

        map->circle[i].key = keys[type];
        map->circle[i].keyLabel = labels[type];

        map->circle[i].active = false;
        map->circle[i].isHit = false;
        
    }

    map->music = LoadMusicStream(maps[mapIndex].musicfile);
    PlayMusicStream(map->music);
    map->duration = GetMusicTimeLength(map->music);
}