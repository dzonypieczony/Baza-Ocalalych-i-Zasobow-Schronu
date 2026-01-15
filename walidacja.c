#include "walidacja.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int walidacja_liczba(int min, int max) {
    int liczba;
    while (1) {
        if (scanf("%d", &liczba) == 1) {
            if (liczba >= min && liczba <= max) {
                while (getchar() != '\n');
                return liczba;
            }
            else {
                printf("\nWartosc poza zakresem, wprowadz ponownie: ");
            }
        }
        else {
            printf("\nWprowadz liczbe: ");
            while (getchar() != '\n');
        }
    }
}

char* walidacja_tekst(char tekst[], int rozmiar) {
    while (1) {
        fgets(tekst, rozmiar, stdin);
        if (strlen(tekst) == 0) {
            printf("\nMusisz wpisac imie: ");
        }
        else {
            for (int i = 0; i < strlen(tekst); i++) {
                if (tekst[i] == '\n') {
                    tekst[i] = '\0';
                }
            }
            return tekst;
        }
    }
}