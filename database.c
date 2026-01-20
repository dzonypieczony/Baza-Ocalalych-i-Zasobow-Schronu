#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "walidacja.h"

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
    char name[100];
    enum JobType job = 8;
    enum Status status = 6;
    int food[2];
    int health;
    int risk;
    printf("Wpisz imie: ");
    walidacja_tekst(name, 100);
    printf("\n1 - Inzynier"
    "\n2 - Medyk"
    "\n3 - Zwiadowca"
    "\n4 - Technik"
    "\n5 - Biolog"
    "\n6 - Mechanik"
    "\n7 - Inny");
    printf("\nWpisz zawod: ");
    job = walidacja_liczba(1, 7);
    printf("\n1 - Aktywny/a"
    "\n2 - Chory/a"
    "\n3 - Poszkodowany/a"
    "\n4 - Poza schronem/a"
    "\n5 - Zaginiony/a");
    printf("\nWpisz status: ");
    status = walidacja_liczba(1, 5);
    printf("\nWpisz ilosc wody (0-100): ");
    food[0] = walidacja_liczba(0, 100);
    printf("\nWpisz ilosc zywnosci (0-100): ");
    food[1] = walidacja_liczba(0, 100);
    printf("\nWpisz poziom zdrowia (0-100): ");
    health = walidacja_liczba(0, 100);
    printf("\nWpisz poziom ryzyka (0-10): ");
    risk = walidacja_liczba(0, 10);
    struct Person person;
    strcpy(person.name, name);
    person.job = job-1;
    person.status = status-1;
    person.food[0] = food[0];
    person.food[1] = food[1];
    person.health = health;
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
    int i = 0;
    while (current != NULL) {
        if (strcmp(current->person.name, word) == 0) {
            printf("\nPodaj nowy zawod osoby (1-Inzynier, 2-Medyk, 3-Zwiadowca, 4-Technik, 5-Biolog, 6-Mechanik, 7-Inny): ");
            current->person.job = walidacja_liczba(1, 7)-1;
            printf("\nPodaj nowa ilosc wody (0-100): ");
            current->person.food[0] = walidacja_liczba(0, 100);
            printf("\nPodaj nowa ilosc zywnosci (0-100): ");
            current->person.food[1] = walidacja_liczba(0, 100);
            printf("\nPodaj nowy poziom zdrowia (0-100): ");
            current->person.health = walidacja_liczba(0, 100);
            printf("\nPodaj nowy poziom ryzyka (0-10): ");
            current->person.risk = walidacja_liczba(0, 10);
            printf("\nPodaj nowy status (1-Aktywny/a, 2-Chory/a, 3-Poszkodowany/a, 4-Poza schronem, 5-Zaginiony/a): ");
            current->person.status = walidacja_liczba(1, 5)-1;
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\nNie ma takiej osoby");
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
    if (head == NULL) {
        printf("\nBaza jest pusta");
        return head;
    }
    Node* sorted = NULL;
    while (head != NULL) {
        Node* next = head->next;
        //
        sorted = insert_sorted(sorted, head->person);
        free(head);
        head = next;
    }
    printf("\nSortowanie przebieglo pomyslnie");
    return sorted;
}

Node* delete_person(Node* head, char word[]) {
    Node* current = head;
    Node* prev = NULL;
    if (strcmp(current->person.name, word) == 0) {
        if (current->person.status != 4) {
            printf("\nNie mozna usunac tej osoby (jej status to nie Zaginiony/a)");
            return head;
        }
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("\nUsunieto zapis z bazy");
        return head;
    }
    while (current != NULL && strcmp(current->person.name, word) != 0) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("\nNie ma takiej osoby");
        return head;
    }
    if (current->person.status != 4) {
        printf("\nNie mozna usunac tej osoby (jej status to nie Zaginiony/a)");
        return head;
    }
    prev->next = current->next;
    free(current);
    printf("\nUsunieto zapis z bazy");
    return head;
}

void free_list(Node* head) {
    Node* p = head;
    while (p != NULL) {
        Node* next = p->next;
        free(p);
        p = next;
    }
}