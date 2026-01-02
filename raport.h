#ifndef RAPORT_H
#define RAPORT_H
#include "database.h"

const char* job_name(enum JobType job);

const char* status_name(enum Status status);

void show_raport(Node* head);

#endif