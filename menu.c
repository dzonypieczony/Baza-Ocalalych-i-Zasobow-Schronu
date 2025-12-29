#include <stdio.h>
#include "menu.h"

int menu() {
    int choice = 9;
    while (choice) {
        printf("\n============================================\n"
               "1 - Wczytaj dane z pliku\n"
               "2 - Wyswietl raport\n"
               "3 - Zarejestruj nowa osobe\n"
               "4 - Wyszukaj osobe\n"
               "5 - Modyfikuj zapis\n"
               "6 - Sortuj baze\n"
               "7 - Usun zapis z bazy\n"
               "8 - Zapisz baze do pliku\n"
               "0 - Wylacz system\n"
               "============================================\n");
        while (scanf("%d", &choice) == 0) {
            while (getchar() != '\n')
                printf("\nPodaj wartosc liczbowa: ");
        }
        if (choice > 8) {
            printf("\nBledna wartosc, podaj ponownie");
        }
        else {
            break;
        }
    }
    return choice;
}