/*****************************************************************
//
// NAME: Woojoon Hwang
//
// HOMEWORK: 3-b
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: September 22, 2018
//
// FILE: prototypes.h
//
// DESCRIPTION: This file contains the prototypes
//
****************************************************************/

#include <stdio.h>
#include "record.h"

int addRecord (struct record **, int, char [ ],char [ ]);
int printRecord (struct record *, int);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
