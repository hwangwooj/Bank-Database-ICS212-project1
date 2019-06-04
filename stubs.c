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
// DATE:         March 10, 2019
//
// FILE:         stubs.c
//
// DESCRIPTION:  This file contains function definitions.
//
****************************************************************/
#include "record.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int debugmode;

/***************************************************************
//
//  FUNCTION NAME:  addRecord
//
//  DESCRIPTION:    This function adds a record
//                  to the database
//
//  PARAMETERS:     accountNum (int):  user account number   
//                  name (char[ ]):    user name
//                  address (char[ ]): user address
//
//  RETURN VALUES:  0: success
//                 -1: fail
//
***************************************************************/

int addRecord(struct record** start, int uaccountno, char uname[], char uaddress[])
{
    struct record * current = *start;
    struct record * newRecord;
    int isInRecord = 0;
    int returnValue = -1;
    
    if(debugmode == 1)
    {
        printf("\n*******************************");
        printf("Debug Mode Initiated\n");
        printf("Function called: addRecord\n");
        printf("Paramaters passed:\n");
        printf("accountNum : %d\n", uaccountno);
        printf("name: %s\n", uname);
        printf("address: %s\n", uaddress);
        printf("*******************************\n");
    }
    
    newRecord = (struct record*) malloc(sizeof(struct record));
    newRecord->accountno = uaccountno;
    strcpy(newRecord->name, uname);
    strcpy(newRecord->address, uaddress);
    
    if(current == NULL)
    {
        *start = newRecord;
        returnValue = 0;
    }
    
    else
    {
        do
        {
            if(uaccountno == (current->accountno))
            {
                isInRecord = 1;
            }
            else if((current->next) == NULL)
            {
                current->next = newRecord;
                returnValue = 0;
            }
            else
            {
                current = current->next;
            }
            
        } while((returnValue == -1) && (isInRecord == 0));
        
    }
    
    return returnValue;
}


/***************************************************************
//
//  FUNCTION NAME:  printRecord
//
//  DESCRIPTION:    This function prints a record             
//     	       	    for the users.
//
//  PARAMETERS:     accountNum (int):  user account number      
//
//  RETURN VALUES:  0: success
//                 -1: fail
//
***************************************************************/

int printRecord (struct record * start, int uaccountno)
{
    struct record * current = start;
    int returnValue = -1;
    
    if(debugmode == 1)
    {
       	printf("\n*******************************");
     	printf("Debug Mode Initiated\n"); 
        printf("Function called: printRecord\n");
        printf("Paramaters passed:\n");
        printf("accountno : %d\n", uaccountno);
       	printf("*******************************\n");
    }
    printf("\n");
    
    while(current != NULL)
    {
        if(uaccountno == current->accountno)
        {
            printf("%d\n", current->accountno);
            printf("%s\n", current->name);
            printf("%s\n", current->address);
            printf("\n");
            
            returnValue = 0;
        }
        
        current = current->next;
    }
    
    return returnValue;

}

/***************************************************************
//
//  FUNCTION NAME:  printAllRecords
//
//  DESCRIPTION:    This function adds a record             
//     	       	    to the database
//
//  PARAMETERS:      
//
//  RETURN VALUES: 
//
***************************************************************/

void printAllRecords(struct record * start)
{
    struct record * current = start;
    printf("calling printAllRecords");
    
    if(debugmode == 1)
    {
       	printf("\n*******************************");
     	printf("Debug Mode Initiated\n"); 
        printf("Function called: printAllRecords\n");
        printf("Paramaters passed:\n");
       	printf("*******************************\n");

    }
    printf("\nOption #3: Print all records\n");
    
    while(current != NULL)
    {
        printf("%d\n", current->accountno);
        printf("%s\n", current->name);
        printf("%s\n", current->address);
        printf("\n");
        
        current = current->next;
    }
}

/***************************************************************
//
//  FUNCTION NAME:  findRecords
//
//  DESCRIPTION:    This function finds a record             
//     	       	    using a name as key value.
//
//  PARAMETERS:     name (char[ ]): user name   
//
//  RETURN VALUES:  0: success
//                 -1: fail
//
***************************************************************/

int findRecords (struct record* start, char uname[ ])
{
    struct record * current = start;
    int returnValue = -1;
    char temp[25];
    int i;
    
    if(debugmode == 1)
    {
       	printf("\n*******************************");
     	printf("Debug Mode Initiated\n"); 
        printf("Function called: findRecords\n");
        printf("Paramaters passed:\n");
        printf("name: %s\n", uname);
       	printf("*******************************\n");
    }
    
    printf("\nRecords whose names start with %s\n", uname);
    
    while(current != NULL)
    {
        for(i=0; i<25; i++)
        {
            temp[i] = '\0';
        }
        for(i=0; i<((int)strlen(uname)-1); i++)
        {
            temp[i] = current->name[i];
        }
        temp[((int)strlen(uname)-1)] = '\n';
        
        for(i=(int)strlen(uname); i< 25; i++)
        {
            uname[i] = '\0';
        }
        
        if(strcmp(uname, temp) == 0)
        {
            printf("%d\n", current->accountno);
            printf("%s\n", current->name);
            printf("%s\n", current->address);
            printf("\n");
            
            returnValue = 0;
        }
        
        current = current->next;
    }
    
    return returnValue;
}

/***************************************************************
//
//  FUNCTION NAME:  deleteRecord
//
//  DESCRIPTION:    This function deletes a record             
//     	       	    for users.
//
//  PARAMETERS:     accountNum (int):  user account number      
//
//  RETURN VALUES:  0: success
//                 -1: fail
//
***************************************************************/

int deleteRecord(struct record ** start, int uaccountno)
{
    struct record * previous = *start;
    struct record * current = *start;
    int returnValue = -1;
    
    if(debugmode == 1)
    {
        printf("\n*******************************\n");
        printf("Debug Mode Initiated\n");
        printf("Function called: deleteRecord\n");
        printf("Paramaters passed:\n");
        printf("accountno : %d\n", uaccountno);
        printf("*******************************\n");
    }
    
    while(current != NULL)
    {
        if((current->accountno) == uaccountno)
        {
            if(current == *start)
            {
                *start = current->next;
                free(current);
                current = *start;
                returnValue = 0;
            }
            else
            {
                (previous -> next) = (current -> next);
                free(current);
                current = (previous -> next);
                returnValue = 0;
            }
        }
        
        else
        {
            previous = current;
            current = (current ->next);
        }
    }
    
    return returnValue;

}

/*****************************************************************
 //
 // Function name:   readfile
 //
 // DESCRIPTION:     Reads an array of records (bank accounts) from a file
 //
 // Parameters:      pstart (struct record **): pointer to start, which
 //                  points at the start of the list
 //                  filename (char []): the name of the file to be read
 //
 // Return values:   0: success
 //                  1: file not found
 //
 ****************************************************************/

int readfile(struct record ** pstart, char filename[])
{
    FILE * inputfile;
    int returnvalue, currentline, accountno;
    char line[25], name[25], address[80];
    
    returnvalue = currentline = accountno = 0;
    inputfile = fopen(filename, "r");
    
    if (inputfile == NULL)
    {
        returnvalue = 1;
    }
    else
    {
        while (fgets(line, 25, inputfile))
        {
            if (strcmp(line, "!\n") == 0)
            {
                address[strlen(address) - 1] = '\0';
                addRecord(pstart, accountno, name, address);
                currentline = 0;
            }
            else
            {
                if (currentline == 0)
                {
                    accountno = atoi(line);
                    currentline++;
                }
                else if (currentline == 1)
                {
                    strcpy(name, line);
                    name[strlen(name) - 1] = '\0';
                    currentline++;
                }
                else if (currentline == 2)
                {
                    strcpy(address, line);
                    currentline++;
                }
                else
                {
                    strcat(address, line);
                }
            }
        }
        
        fclose(inputfile);
    }
    
    return returnvalue;
}

/*****************************************************************
 //
 // Function name:   writefile
 //
 // DESCRIPTION:     Writes an array of records (bank accounts) to a file
 //
 // Parameters:      start (struct record *): pointer to the start of the list
 //                  filename (char []): the name of the file to be written
 //
 ****************************************************************/

void writefile(struct record * start, char filename[])
{
    FILE * outputfile;
    struct record * current;
    
    current = start;
    outputfile = fopen(filename, "w");
    
    while (current != NULL)
    {
        fprintf(outputfile, "%d\n%s\n%s\n!\n", current->accountno, current->name, current->address);
        current = current->next;
    }
    
    fclose(outputfile);
}
