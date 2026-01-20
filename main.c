#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"
#include "menu.h"
#include "pliki.h"
#include "raport.h"

int main(void) {
    printf("Witaj w Bazie Ocalalych!\n");
    Node* head = NULL;
    while (1) {
        int choice = show_menu();
        if (choice == 1) {
            head = read_file(head, "file.txt");
        }
        else if (choice == 2) {
            show_raport(head);
        }
        else if (choice == 3) {
            head = add_person(head);
        }
        else if (choice == 4) {
            if (head == NULL) {
                printf("\nBaza jest pusta");
            }
            else {
                char word[100];
                /*while (getchar() != '\n');*/
                printf("\nPodaj imie jakie chcesz wyszukac: ");
                fgets(word, 100, stdin);
                for (int i = 0; i < strlen(word); i++) {
                    if (word[i] == '\n') {
                        word[i] = '\0';
                    }
                }
                Node* find = find_list(head, word);
                show_raport(find);
                free_list(find);
            }
        }
        else if (choice == 5) {
            if (head == NULL) {
                printf("\nBaza jest pusta");
            }
            else {
                char word[100];
                /*while (getchar() != '\n');*/
                printf("\nPodaj imie osoby, ktorej dane chcesz zmodyfikowac: ");
                fgets(word, 100, stdin);
                for (int i = 0; i < strlen(word); i++) {
                    if (word[i] == '\n') {
                        word[i] = '\0';
                    }
                }
                head = modify_list(head, word);
            }
        }
        else if (choice == 6) {
            head = sort_list(head);
        }
        else if (choice == 7) {
            if (head == NULL) {
                printf("\nBaza jest pusta");
            }
            else {
                char word[100];
                /*while (getchar() != '\n');*/
                printf("\nPodaj imie osoby, ktora chcesz usunac z bazy: ");
                fgets(word, 100, stdin);
                for (int i = 0; i < strlen(word); i++) {
                    if (word[i] == '\n') {
                        word[i] = '\0';
                    }
                }
                head = delete_person(head, word);
            }
        }
        else if (choice == 8) {
            if (head == NULL) {
                printf("\nBaza jest pusta");
            }
            else {
                write_file(head, "file.txt");
            }
        }
        else if (choice == 0) {
            free_list(head);
            printf("\nPomyslnie wylaczono system");
            return 0;
        }
    }
}