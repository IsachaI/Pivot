#include <stdlib.h>
#include "raylib.h"
#include "math.h"
#include "../headers/utils.h"
#include "../headers/map_data.h"


void DrawSmoothCircleLines(Vector2 center, float radius, Color color, int segments)
{
    for (int i = 0; i < segments; i++)
    {
        float theta1 = (2 * PI * i) / segments;
        float theta2 = (2 * PI * (i + 1)) / segments;

        Vector2 p1 = { center.x + cosf(theta1) * radius, center.y + sinf(theta1) * radius };
        Vector2 p2 = { center.x + cosf(theta2) * radius, center.y + sinf(theta2) * radius };

        DrawLineV(p1, p2, color);
    }
}


void CleanupMap(MapData *m){
    if (m == NULL) return;

    //free circle array
    if (m->circle != NULL) {
        free(m->circle);
        m->circle = NULL;
    }

    // Unload music
    if (m->isLoaded) {
        UnloadMusicStream(m->music);
        m->isLoaded = false;
    }
    //reset stats
    m->circlesHit = 0;
    m->elapsedTime = 0.0f;
    m->duration = 0.0f;
}