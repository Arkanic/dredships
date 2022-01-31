#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "dred.h"

void initstr(struct string *s) {
	s->len = 0;
	
	s->str = malloc(s->len + 1);
	if(s->str == NULL) {
		fprintf(stderr, "malloc fail\n");
		exit(1);
	}
	s->str[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s) {
	size_t newlen = s->len + size * nmemb;
	s->str = realloc(s->str, newlen + 1);
	if(s->str == NULL) {
		fprintf(stderr, "realloc fail\n");
		exit(1);
	}

	memcpy(s->str + s->len, ptr, size * nmemb);
	s->str[newlen] = '\0';
	s->len = newlen;

	return size * nmemb;
}

void getstr(struct string *s, char *url) {
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(!curl) {
		fprintf(stderr, "curl fail\n");
		exit(1);
	}

	initstr(s);

	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, s);
	res = curl_easy_perform(curl);

	curl_easy_cleanup(curl);
}
