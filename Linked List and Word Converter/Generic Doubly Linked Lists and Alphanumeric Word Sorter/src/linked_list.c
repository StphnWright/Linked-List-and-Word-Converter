#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include <stdbool.h>
#include "node.h"

void print_list(linked_list *list, void (*print_function)(void*)) {
    putchar('[');
    node *cur = list->head;
    if (cur != NULL) {
        print_function(cur->data);
        cur = cur->next;
    }
    for ( ; cur != NULL; cur = cur->next) {
        printf(", ");
        print_function(cur->data);
    }
    printf("]\n{length: %lu, head->data: ", list->size);
    list->head != NULL ? print_function(list->head->data) :
                         (void)printf("NULL");
    printf(", tail->data: ");
    list->tail != NULL ? print_function(list->tail->data) :
                         (void)printf("NULL");
    printf("}\n\n");
}

linked_list* create_linked_list() {
    linked_list* list = malloc(sizeof(linked_list));
    
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }

    return list;
}

bool insert_in_order(linked_list *list, void *data, int (*cmp)(const void*, const void*)) {
    if (list == NULL) {
        return false; 
    }

    node *new_node = create_node(data);
    if (new_node == NULL) {
        return false;
    }
    
    node *prev = NULL;
    node *curr;
    for (curr = list->head; curr != NULL && cmp(data, curr->data) >= 0; curr = curr->next) {
        prev = curr;
    }

    if (curr == NULL) {
        if (prev == NULL) {
            list->head = new_node;
            list->tail = new_node;
        } else {
            prev->next = new_node;
            new_node->prev = prev;
            list->tail = new_node;
        }
    } else {
        if (prev == NULL) {
            curr->prev = new_node;
            new_node->next = curr;
            list->head = new_node;
        } else {
            prev->next = new_node;
            new_node->prev = prev;
            curr->prev = new_node;
            new_node->next = curr;
        }
    }

    list->size++;
    return true;
}

void free_list(linked_list *list, void (*free_data)(void *)) {
    node *prev = NULL;

    for (node *curr = list->tail; curr != NULL; curr = prev) {
       prev = curr->prev;
       free_node(curr, free_data);
    }

    free(list);
}
