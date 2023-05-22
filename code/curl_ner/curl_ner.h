#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <unistd.h>

struct memory {
   char *response;
   size_t size;
};
 
static size_t cb(void *data, size_t size, size_t nmemb, void *userp);
bool ner(char *text,struct memory *buf);
