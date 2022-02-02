#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

#define GRAB_AMOUNT 1000
#define CSV_FILE "./ships.csv"

// net.c
struct string {
	char *str;
	size_t len;
};

void initstr(struct string *s);
void getstr(struct string *s, char *url);


// parse.c
struct ship {
	char *name;
	char *hex;
	int color;
	int score;
};

void parseship(cJSON *ship, struct ship *s);
void parsetext(char *sjson, struct ship *buf);

// csv.c
FILE *opendat();
void appendcsvheader(FILE *fptr);
void appendcsvship(FILE *fptr, struct ship ship);
void appendcsvships(FILE *fptr, struct ship *ships, int len);
void closedat(FILE *fptr);