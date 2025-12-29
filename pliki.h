#ifndef PLIKI_H
#define PLIKI_H
#include "database.h"

Node* read_file(Node* head, char* file_name);

void write_file(Node* head, char* file_name);

#endif