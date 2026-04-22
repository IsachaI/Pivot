#include <stdio.h>
#include <raylib.h>
#include "../headers/map_data.h"
#include "../headers/map_elem_parser.h"

int main() {
    InitWindow(800, 600, "Parser Test");
    
    MapData testMap = {0};
    if(LoadMapFromFile("beatmaps/Music1/test.txt", &testMap, 800, 600)){
        printf("✓ Loaded: BPM=%.1f, Circles=%d\n", testMap.BPM, testMap.totalCircles);
        for(int i = 0; i < testMap.totalCircles; i++){
            printf("  Circle %d: t=%.1f pos=(%.0f,%.0f) key=%d\n", 
                   i, testMap.circle[i].spawnTime, 
                   testMap.circle[i].position.x, 
                   testMap.circle[i].position.y,
                   testMap.circle[i].key);
        }
    } else {
        printf("✗ Failed to load\n");
    }
    
    CloseWindow();
    return 0;
}