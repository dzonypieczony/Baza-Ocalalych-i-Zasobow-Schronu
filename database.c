#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Node* add_person(Node* head) {
    char name[50];
    while (getchar() != '\n');
    enum JobType job = 8;
    enum Status status = 6;
    int food[2];
    int risk;
    printf("Wpisz imie: ");
    fgets(name, sizeof(name), stdin);
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] == '\n') {
            name[i] = '\0';
        }
    }
    printf("\n1 - ENGINEER"
    "\n2 - MEDIC"
    "\n3 - RANGER"
    "\n4 - TECHNICIAN"
    "\n5 - BIOLOGIST"
    "\n6 - MECHANIC"
    "\n7 - OTHER");
    printf("\nWpisz zawod: ");
    scanf("%d", &job);
    printf("\n1 - ACTIVE"
    "\n2 - ILL"
    "\n3 - INJURED"
    "\n4 - OUT"
    "\n5 - LOST");
    printf("\nWpisz status: ");
    scanf("%d", &status);
    printf("\nWpisz ilosc wody (0-100): ");
    scanf("%d", &food[0]);
    printf("\nWpisz ilosc zywnosci (0-100): ");
    scanf("%d", &food[1]);
    printf("\nWpisz poziom ryzyka: ");
    scanf("%d", &risk);
    struct Person person;
    strcpy(person.name, name);
    person.job = job-1;
    person.status = status-1;
    person.food[0] = food[0];
    person.food[1] = food[1];
    person.risk = risk;
    head = push_back(head, person);
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

Node* modify_list(Node* head, char word[]) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->person.name, word) == 0) {
            printf("\nPodaj nowa ilosc wody (0-100): ");
            scanf("%d", &current->person.food[0]);
            printf("\nPodaj nowa ilosc zywnosci (0-100): ");
            scanf("%d", &current->person.food[1]);
            printf("\nPodaj nowy poziom ryzyka: ");
            scanf("%d", &current->person.risk);
            int nowyStatus = 6;
            while (nowyStatus > 5) {
                printf("\nPodaj nowy status (1-Active, 2-Ill, 3-Injured, 4-Out, 5-Lost): ");
                scanf("%d", &nowyStatus);
            }
            current->person.status = nowyStatus-1;
        }
        current = current->next;
    }
    return head;
}

Node* insert_sorted(Node* head, struct Person person) {
    Node* n = calloc(1, sizeof(Node));
    n->person = person;
    if (head == NULL || strcmp(person.name, head->person.name) <= 0) {
        n->next = head;
        return n;
    }
    Node* p = head;
    while (p->next != NULL && strcmp((p->next)->person.name, person.name) < 0) {
        p = p->next;
    }
    n->next = p->next;
    p->next = n;
    return head;
}

Node* sort_list(Node* head) {
    Node* sorted = NULL;
    while (head != NULL) {
        Node* next = head->next;
        //
        sorted = insert_sorted(sorted, head->person);
        free(head);
        head = next;
    }
    return sorted;
}

Node* delete_person(Node* head, char word[]) {
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    Node* prev = NULL;
    if (strcmp(current->person.name, word) == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while (current->next != NULL && strcmp(current->person.name, word) != 0) {
        prev = current;
        current = current->next;
    }
    if (current->person.status != 4) {
        printf("\nNie mozna usunac tej osoby");
        return head;
    }
    if (current->next == NULL) {
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}

Node* free_list(Node* head) {
    Node* p = head;
    while (p != NULL) {
        Node* next = p->next;
        free(p);
        p = next;
    }
    return NULL;
}