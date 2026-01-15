#include <stdio.h>
#include "menu.h"
#include "walidacja.h"

int show_menu() {
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
        printf("\nPodaj wybor: ");
        choice = walidacja_liczba(0, 8);
        break;
    }
    return choice;
}