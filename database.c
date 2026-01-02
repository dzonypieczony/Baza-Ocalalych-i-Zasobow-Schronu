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
    enum JobType job;
    enum Status status;
    int food[2];
    int risk;
    while (getchar() != '\n')
        printf("Wpisz imie: \n");
    fgets(name, sizeof(name), stdin);
    printf("1 - ENGINEER"
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
            printf("\nPodaj nową ilość wody (0-100): ");
            scanf("%d", &current->person.food[0]);
            printf("\nPodaj nową ilość zywnosci (0-100): ");
            scanf("%d", &current->person.food[1]);
            printf("\nPodaj nowy poziom ryzyka (0-10): ");
            scanf("%d", &current->person.risk);
            printf("\nPodaj nowy status (0-Active, 1-Ill, 2-Injured, 3-Out, 4-Lost): ");
            int nowyStatus;
            scanf("%d", &nowyStatus);
            current->person.status = (enum Status)nowyStatus;
        }
        current = current->next;
    }
    return head;
}

Node* insert_sorted(Node* head, struct Person person) {
    Node* n = calloc(1, sizeof(Node));
    n->person = person;
    if (head == NULL || person.name <= head->person.name) {
        n->next = head;
        return n;
    }
    Node* p = head;
    while (p->next != NULL && (p->next)->person.name < person.name) {
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
    Node* current = head;
    if (current->person.status != 4) {
        printf("\nNie mozna usunac tej osoby");
        return head;
    }
    if (head == NULL) {
        return NULL;
    }
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
    if (current->next == NULL) {
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}