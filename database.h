#ifndef DATABASE_H
#define DATABASE_H

enum JobType {
    JOB_ENGINEER,
    JOB_MEDIC,
    JOB_RANGER,
    JOB_TECHNICIAN,
    JOB_BIOLOGIST,
    JOB_MECHANIC
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
    int food;
    int risk;
    enum Status status;
};

typedef struct Node {
    struct Person person;
    struct Node * next;
} Node;

const char* job_name(enum JobType job);

const char* status_name(enum Status status);

#endif