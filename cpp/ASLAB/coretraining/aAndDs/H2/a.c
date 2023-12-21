#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORKER_SIZE 5

typedef struct Land {
    char landID[10];
    char officeID[10];
    char officeName[100];
    char officeAddress[100];
    struct Division *division;
    struct Land *north;
    struct Land *east;
    struct Land *south;
    struct Land *west;
} Land;

typedef struct Division {
    char divisionID[10];
    char divisionName[100];
    struct Worker workers[WORKER_SIZE];
    struct Division *next;
} Division;

typedef struct Worker {
    char workerID[10];
    char workerName[100];
    char workerPosition[50];
    long workerSalary;
    struct Worker *next;
} Worker;

Land * createLand(char *landID) {
    Land *land = (Land *) malloc(sizeof(Land *));

    strcpy(land->landID, landID);

    return land;
}

void convertLandToOffice(Land *land, char *officeID, char *officeName, char *officeAddress) {
    strcpy(land->officeID, officeID);
    strcpy(land->officeName, officeName);
    strcpy(land->officeAddress, officeAddress);
}

void initialize() {
    Land *land = NULL;
    land = createLand("LA345");
    convertLandToOffice(land, "OF123", "FFontinental Office", "Jl bla bla bla");
    printf("%s %s %s %s", land->landID, land->officeID, land->officeName, land->officeAddress);
}

int main() {
    initialize();
    return 0;
}