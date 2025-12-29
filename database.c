#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "database.h"

Node* push_back(Node* head, struct Person person) {
    Node* n = calloc(1, sizeof(Node));
    n->person = person;
    if (head == NULL)
        return n;
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = n;
    return head;
}

Node* find_list(Node* head, char word[]) {
    Node* find = NULL;
    Node* current = head;
    while (current != NULL) {
        if (strstr(current->person.name, word) != NULL) {
            find = push_back(find, current->person);
        }
        current = current->next;
    }
    return find;
}
