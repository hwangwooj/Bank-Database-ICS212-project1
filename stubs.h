/*****************************************************************
//
// NAME:         Woojoon Hwang
//
// HOMEWORK:     project1
//
// CLASS:        ICS 212
//
// INSTRUCTOR:   Ravi Narayan
//
// DATE:         march 10, 2019
//
// FILE:         stubs.h
//
// DESCRIPTION:  This file contains function prototypes.
//
****************************************************************/
#include "record.h"

int addRecord (struct record **, int, char [ ],char [ ]);
int printRecord (struct record *, int);
void printAllRecords(struct record *);
int findRecords (struct record *, char [ ]);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
void writefile(struct record *, char []);
