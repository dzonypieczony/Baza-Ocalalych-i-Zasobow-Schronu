#include <stdio.h>
#include "raport.h"

const char* job_name(enum JobType job) {
    switch (job) {
        case JOB_ENGINEER: return "INZYNIER";
        case JOB_MEDIC: return "MEDYK";
        case JOB_RANGER: return "ZWIADOWCA";
        case JOB_TECHNICIAN: return "TECHNIK";
        case JOB_BIOLOGIST: return "BIOLOG";
        case JOB_MECHANIC: return "MECHANIK";
        case JOB_OTHER: return "INNY";
        default: return "NIEZNANY";
    }
}

const char* status_name(enum Status status) {
    switch (status) {
        case STATUS_ACTIVE: return "AKTYWNY/A";
        case STATUS_ILL: return "CHORY/A";
        case STATUS_INJURED: return "POSZKODOWANY/A";
        case STATUS_LOST: return "ZAGINIONY/A";
        case STATUS_OUT: return "POZA SCHRONEM";
        default: return "NIEZNANY";
    }
}

void show_raport(Node* head) {
    Node* p = head;
    if (p == NULL) {
        printf("\nBaza jest pusta");
    }
    while (p != NULL) {
        struct Person person = p->person;
        printf("\n[IMIE: %s] Specjalnosc: %s, Ilosc racji: woda: %d zywnosc: %d, Poziom zdrowia: %d, "
               "Poziom ryzyka: %d,\n    Status: %s", person.name, job_name(person.job),
            person.food[0], person.food[1], person.health, person.risk, status_name(person.status));
        p = p->next;
    }
}