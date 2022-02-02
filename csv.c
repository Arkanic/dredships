#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dred.h"

FILE *opendat() {
    FILE *fptr;
    if((fptr = fopen(CSV_FILE, "wr+b")) == NULL) {
        fprintf(stderr, "Err opening csv file\n");
        exit(1);
    }

    return fptr;
}

void appendcsvheader(FILE *fptr) {
    char *str = "name,hex,score,color\n";
    fwrite(str, 1, strlen(str), fptr);
}

void appendcsvship(FILE *fptr, struct ship ship) {
    char *buf = malloc(sizeof(char) * 128);
    snprintf(buf, 128, "\"%s\",\"%s\",%d,%d\n", ship.name, ship.hex, ship.score, ship.color);
    fwrite(buf, 1, strlen(buf), fptr);
    free(buf);
}

void appendcsvships(FILE *fptr, struct ship *ships, int len) {
    for(int i = 0; i < len; i++) {
        appendcsvship(fptr, ships[i]);
    }
}

void closedat(FILE *fptr) {
    fclose(fptr);
}