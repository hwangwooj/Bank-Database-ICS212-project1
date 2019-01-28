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
// DATE: September 23, 2018
//
// FILE: record.h
//
// DESCRIPTION: This file contains the structure called record.
//		Record contains the information of an account.
//              This file also contain some functions and their
//              instructions during the debugging mode.
//
****************************************************************/

#include <stdio.h>

int Debugging = 0;

struct record

{

    int accountno;

    char name[25];

    char address[80];

    struct record* next;

};

/*****************************************************************
//
// Function name: addRecord
//
// DESCRIPTION: Only debugging mode
//
// Parameters:	start (struct record **):
//              accountno (int):
//              name[ ](char):
//              address[](char):
//
****************************************************************/ 

int addRecord (struct record **start, int accountno, char name[ ],char address[ ])

{

    if(Debugging)
    {
        printf("\nDEBUG: Function called: addRecord\n");
        printf("No parameters passed.\n");
        printf("\n");
    }


return 0;

}

/*****************************************************************
//
// Function name: printRecord
//
// DESCRIPTION: Only debugging mode                  
//
// Parameters:  start (struct record *):                            
//     	       	accountno (int):
//
****************************************************************/

int printRecord (struct record *start, int accountno)

{

    if(Debugging)
    {
        printf("\nDEBUG: Function called: printRecord\n");
        printf("No parameters passed.\n");
        printf("printRecord function called with accountno=%d \n", accountno);

    }

return 0;

}

/*****************************************************************
//
// Function name: printAllRecords
//
// DESCRIPTION: Only debugging mode
//
// Parameters:  start (struct record *):
//
****************************************************************/

void printAllRecords(struct record *start)

{

    if(Debugging)
    {
        printf("\nDEBUG: Function called: printAllRecords\n");
        printf("No parameters passed.\n");
        printf("\n");

    }
}

/*****************************************************************
//
// Function name: deleteRecord
// 
// DESCRIPTION: Only debugging mode
// 
// Parameters:  start (struct record **):
//              accountno (int):
//              
****************************************************************/

int deleteRecord(struct record **start, int accountno)

{

    if(Debugging)
    {
        printf("\nDEBUG: Function called: deleteRecord\n");
        printf("No parameters passed.\n");

    }

return 0;

}
