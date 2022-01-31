#include <cjson/cJSON.h>
#include <stdio.h>

#include "dred.h"

void parseship(cJSON *ship, struct ship *s) {
    s->name = cJSON_GetObjectItem(ship, "ship_name")->valuestring;
    s->hex = cJSON_GetObjectItem(ship, "hex_code")->valuestring;
    s->color = cJSON_GetObjectItem(ship, "color")->valueint;
    s->score = cJSON_GetObjectItem(ship, "score")->valueint;
    printf("%s %s %d %d\n", s->name, s->hex, s->color, s->score);
}

void parsetext(char *sjson, struct ship *buf) {
    cJSON *data = cJSON_Parse(sjson);
    
    cJSON *ships = cJSON_GetObjectItem(data, "ships");

    cJSON *ship;
    int i = 0;
    cJSON_ArrayForEach(ship, ships) {
        parseship(ship, &buf[i]);
        i++;
    }

    cJSON_Delete(data);
}