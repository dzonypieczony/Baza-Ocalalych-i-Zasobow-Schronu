#ifndef DATABASE_H
#define DATABASE_H

enum JobType {
    JOB_ENGINEER,
    JOB_MEDIC,
    JOB_RANGER,
    JOB_TECHNICIAN,
    JOB_BIOLOGIST,
    JOB_MECHANIC,
    JOB_OTHER
};

enum Status {
    STATUS_ACTIVE,
    STATUS_ILL,
    STATUS_INJURED,
    STATUS_OUT,
    STATUS_LOST
};

struct Person {
    char name[50];
    enum JobType job;
    int food[2];
    int health;
    int risk;
    enum Status status;
};

typedef struct Node {
    struct Person person;
    struct Node * next;
} Node;

Node* push_back(Node* head, struct Person person);

Node* add_person(Node* head);

Node* find_list(Node* head, char word[]);

Node* modify_list(Node* head, char word[]);

Node* insert_sorted(Node* head, struct Person person);

Node* sort_list(Node* head);

Node* delete_person(Node* head, char word[]);

Node* free_list(Node* head);

#endif