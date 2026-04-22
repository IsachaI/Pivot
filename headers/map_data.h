#pragma once
#include<raylib.h>
#define MAX_CIRCLES 1024
/**
 * @param Vector2 positional vector for note
 * @param float radius of every note
 * @param float spawnTime = when the note appears
 * @param bool isHit = was the note hit by the player or not
 * @param bool active = is the note currenty active (depends on lifeTime)
 * @param float lifeTime = the time that the note shows on screen
 * @param int key = index of the key that is required to hit 
 * @param char *keyLabel = array of characters thaat represents the key required to hit
 */
typedef struct Circle {
    Vector2 position;
    float radius;
    float spawnTime;
    float lifeTime;
    //float overallDifficulty;
    //float HP;
    bool isHit;
    bool active;
    int key;
    const char *keyLabel;
} Circle;

/**
 * @param Circle see circles struct
 * @param int totalCircles = number of circles in a map
 * @param int circlesHit = number of circles hit (for stats)
 * @param float circleMaxDist = the maximum distance between each circle
 * @param float duration = length of the map
 * @param float elapsedTime = current time 
 * @param float BPM = BPM of a map
 * @param Music the music that should be played
 * @param bool isLoaded = check if music is loaded
 */
typedef struct MapData {
    Circle *circle;
    int totalCircles;
    int circlesHit;
    float circleMaxDist;

    float duration;
    float elapsedTime;

    float BPM;
    float AR;
    float CS;
    Music music;
    bool isLoaded;
} MapData;
