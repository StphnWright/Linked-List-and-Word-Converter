#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

/**
 * Take an array of char* pointers and print each of the strings to standard
 * out. This function must use only pointer arithmetic and no array
 * subscripting. The output start with "[", ends with "]\n", and prints the
 * strings inside, each separated by a comma and space.
 * Example: [Hi, BYE, AP, COMSW 3157, FunTimes]
 */
void display_strings(char **strings) {
    printf("[");
    if (strings != NULL) {
        char **str_ptr = strings;
        if (*str_ptr != NULL) {
            printf("%s", *str_ptr++);
            while (*str_ptr != NULL) {
                printf(", %s", *str_ptr++);
            }
        }
    }
    printf("]\n");
}

static char **copy_args_lowercase(int argc, char **argv) {
    char **argv_copy = malloc(sizeof(char *) * argc);
    
    if (argv_copy == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        argv_copy[i - 1] = malloc(my_strlen(argv[i]) + 1);
        my_strcpy(argv_copy[i - 1], argv[i]);
        my_strlower(argv_copy[i - 1]); 
    }

    argv_copy[argc - 1] = NULL;
    return argv_copy;
}

static void free_copy(char **copy) {
    for (char **p = copy; *p != NULL; p++) {
        free(*p);
    }
    free(copy);
}

/**
 * DO NOT MODIFY main()
 */
int main(int argc, char **argv) {
    char **copy;
    copy = copy_args_lowercase(argc, argv);

    printf("Raw arguments       : ");
    display_strings(argv + 1);

    printf("Lowercase arguments : ");
    display_strings(copy);

    free_copy(copy);

    return EXIT_SUCCESS;
}
