#include <stdio.h>
#include "raport.h"

const char* job_name(enum JobType job) {
    switch (job) {
        case JOB_ENGINEER: return "ENGINEER";
        case JOB_MEDIC: return "MEDIC";
        case JOB_RANGER: return "RANGER";
        case JOB_TECHNICIAN: return "TECHNICIAN";
        case JOB_BIOLOGIST: return "BIOLOGIST";
        case JOB_MECHANIC: return "MECHANIC";
        case JOB_OTHER: return "OTHER";
        default: return "UNKNOWN";
    }
}

const char* status_name(enum Status status) {
    switch (status) {
        case STATUS_ACTIVE: return "ACTIVE";
        case STATUS_ILL: return "ILL";
        case STATUS_INJURED: return "INJURED";
        case STATUS_LOST: return "LOST";
        case STATUS_OUT: return "OUT";
        default: return "UNKNOWN";
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