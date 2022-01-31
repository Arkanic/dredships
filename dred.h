#include <stdlib.h>
#include <cjson/cJSON.h>

#define GRAB_AMOUNT 1000

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