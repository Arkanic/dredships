#include <cjson/cJSON.h>
#include <stdio.h>
#include <string.h>

#include "dred.h"

void parseship(cJSON *ship, struct ship *s) {
    s->name = strdup(cJSON_GetObjectItem(ship, "ship_name")->valuestring);
    s->hex = strdup(cJSON_GetObjectItem(ship, "hex_code")->valuestring);
    s->color = cJSON_GetObjectItem(ship, "color")->valueint;
    s->score = cJSON_GetObjectItem(ship, "score")->valueint;
}

void parsetext(char *sjson, struct ship *buf) {
    cJSON *data = cJSON_Parse(sjson);
    
    cJSON *ships = cJSON_GetObjectItem(data, "ships");
    cJSON *ship;
    int i = 0;
    cJSON_ArrayForEach(ship, ships) {
        struct ship s;
        parseship(ship, &s);
        buf[i] = s;
        i++;
    }

    cJSON_Delete(data);
}