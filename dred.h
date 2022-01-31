#include <stdlib.h>

// net.c
struct string {
	char *str;
	size_t len;
};

void initstr(struct string *s);
void getstr(struct string *s, char *url);
