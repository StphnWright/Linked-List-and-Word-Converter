#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int str_comparator(const void *a, const void *b) {
    const char *a_str = a; 
    const char *b_str = b;
    int cmp = strcmp(a_str, b_str);
    return cmp;
}

void free_str_data(void *data) {
    //no freeing needed
}

void print_str(void *data) {
    char *x = data;
    printf("\"%s\"", x);
}

int main(int argc, char *argv[]) {
    linked_list *list = create_linked_list();
    print_list(list, print_str);
    
    for (int i = 1; i < argc; i++) {
        insert_in_order(list, argv[i], str_comparator);
        print_list(list, print_str);
    }
    
    free_list(list, free_str_data);
    return 0;
}
