#include "mystring.h"
#include <stddef.h>

size_t my_strlen(char *src) {
    size_t length = 0;
    
    for (char *p = src; *p != '\0'; p++) {
        length++;
    }
    return length;
}

char *my_strcpy(char *dst, char *src) {
    if (src == NULL) {
        return NULL;
    }

    char *q = dst;
    for (char *p = src; *p != '\0'; p++, q++) {
        *q = *p;
    }
    *q = '\0';

    return dst;
}

void my_strlower(char *src) {
    for (char *p = src; *p != '\0'; p++) {
        *p = tolower(*p);
    }
}
