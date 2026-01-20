#include <stdio.h>
#include "pliki.h"
#include <stdlib.h>
#include <string.h>
#include "database.h"

Node* read_file(Node* head, char* file_name) {
    FILE* plik = fopen(file_name, "r");
    if (plik == NULL) {
        printf("\nBlad: Nie mozna otworzyc pliku %s", file_name);
        return head;
    }
    char bufor[128];
    while (fgets(bufor, sizeof(bufor), plik)) {
        struct Person nowaOsoba;
        char* token = strtok(bufor, ";");
        if (token != NULL) {
            strcpy(nowaOsoba.name, token);
            token = strtok(NULL, ";");
            nowaOsoba.job = atoi(token);
            token = strtok(NULL, ";");
            nowaOsoba.food[0] = atoi(token);
            token = strtok(NULL, ";");
            nowaOsoba.food[1] = atoi(token);
            token = strtok(NULL, ";");
            nowaOsoba.health = atoi(token);
            token = strtok(NULL, ";");
            nowaOsoba.risk = atoi(token);
            token = strtok(NULL, ";");
            nowaOsoba.status = atoi(token);
        }
        head = push_back(head, nowaOsoba);
    }
    fclose(plik);
    return head;
}

void write_file(Node* head, char* file_name) {
    FILE* plik = fopen(file_name, "w");
    if (plik == NULL) {
        printf("\nBlad: Nie mozna otworzyc pliku %s", file_name);
        return;
    }
    Node* current = head;
    while (current != NULL) {
        fprintf(plik, "%s;%d;%d;%d;%d;%d;%d\n",
                current->person.name,
                current->person.job,
                current->person.food[0],
                current->person.food[1],
                current->person.health,
                current->person.risk,
                current->person.status);
        current = current->next;
    }
    fclose(plik);
    printf("\nPomyslnie zapisano liste do pliku");
}