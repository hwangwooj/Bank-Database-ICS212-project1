/****************************************************************
//
//  NAME:         Woojoon Hwang
//
//  HOMEWORK:     project1
//
//  CLASS:        ICS 212
//
//  INSTRUCTOR:   Ravi Narayan
//
//  DATE:         March 10, 2019
//
//  FILE:         main.c
//
//  DESCRIPTION:  This file contains a main function and other
//                functions in order for users to run the
//                program.  
//
*****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stubs.h"

void menuOption(struct record **);
void debugSwitch(int, char*[]); 
void addOption(struct record **);
void printOption(struct record *);
void findOption(struct record *);
void deleteOption(struct record **);
void getAddress(char[], int);
int debugmode;

/***************************************************************
//  
//  FUNCTION NAME:  main
//  
//  DESCRIPTION:    This main function calls debugSwitch function
//                  and menuOption function.
//   
//  PARAMETERS:     argc (int):    the number of arguments
//                  argv (char**): argument vector
//                                 
//  RETURN VALUES:  0: success
//                 -1: fail
//
***************************************************************/

int main(int argc, char *argv[])
{
    int returnValue;
    struct record * start = NULL;
    
    returnValue = readfile(&start, "records.txt");
    
    debugSwitch(argc, &argv[1]);
    menuOption(&start);
    
    writefile(start, "records.txt");
    return returnValue;  
}

/*************************************************************
//
//  FUNCTION NAME:  menuOption
//
//  DESCRIPTION:    This function provides a menu with 
//                  different options.
//
//  PARAMETERS:
//
//  RETURN VALUES:  void
//
**************************************************************/

void menuOption(struct record **start)
{
    int userOption = 0;
    
    if(debugmode) 
    {
        printf("\n*******************************\n");
        printf("Debug Mode Initiated\n");
        printf("Function called: menuOption\n");
        printf("No Paramaters Passed:\n");
        printf("*******************************\n");
    }

    printf("\n                <Choose one of options>\n");

    while(userOption != 6)
    {
        printf("\n*********************************************************\n");
     	printf("\n1. Add a new record in the database");
        printf("\n2. Print information about a record");
        printf("\n3. Print all information in the database");
        printf("\n4. Print records whose names start with the given string");
        printf("\n5. Delete an existing record from the database");
        printf("\n6. Quit the program\n");
        printf("\n*********************************************************\n");
        
        printf("\nYour Option: ");

        scanf("%d", &userOption);

        while(getchar() != '\n');

        switch(userOption)
        {
            case 1: addOption(start);

            break;

            case 2: printOption(*start);

            break;

            case 3: printAllRecords(*start);

            break;

            case 4: findOption(*start);

            break;

            case 5: deleteOption(start);

            break;

            case 6:

            break;

            default:

            printf("\nInvalid menu choice!\n");

            break;
        }
    }
}

/*************************************************************
//
//  Function name: debugSwitch
//
//  DESCRIPTION:   This function decides whether debugging mode
//                 is initiated or not.
//
//  PARAMETERS:     nums  (int):    the number of arguments.
//                  arg (char*[]):  the second string of 
//                                  command line input.
//
//  Return values:  void
//
**************************************************************/

void debugSwitch(int nums, char* arg[])
{
    if(nums == 2)
    {
        if(strcmp(*arg, "debug") == 0)
        { 
            debugmode = 1;
            printf("\nDebug Mode Initiated\n");
        }
        else
        {
            debugmode = 0;
            printf("\n%s: Command not found.\n", *arg);
            exit(0);
        }
    }
    else if(nums > 2)
    {
        debugmode = 0;
        printf("\nError: There are too many paramaters.\n");
        printf("Try either: ./main\n");
        printf("            ./main debug\n\n");
        exit(0);
    }
    else
    {
        debugmode = 0;
        printf("Debug Mode Not Initiated\n");
    }
} 

/*************************************************************
//
//  Function name:  addOption
//
//  DESCRIPTION:    A user can add information through
//                  this function.
//
//  Parameters:     start(struct record **): 
//
//  Return values:  void
//                  
***************************************************************/
void addOption(struct record **start)

{
    int uaccountno;
    char uname[25];
    char uaddress[80];
    
    if(debugmode)
    {
        printf("\n*******************************\n");
        printf("Debug Mode Initiated\n");
        printf("Function called: addOption\n");
        printf("No parameters passed.\n");
        printf("*******************************\n\n");
    }

    printf("\nOption #1: Adding a new record");

    printf("\nPlease enter the account number: ");
    scanf("%d", &uaccountno);
    while(getchar() != '\n');
    fflush(stdin);

    printf("Please enter name: ");
    fgets(uname, 25, stdin);
    strtok(uname, "\n");
    fflush(stdin);

    getAddress(uaddress, 80);

    if(addRecord(start, uaccountno, uname, uaddress) == 0)
    {
        printf("\nThank you. Record was added successfully.\n");
    }

    else
    {
        printf("\nI'm sorry. Record was not added.\n");
    }
}

/*************************************************************
//
//  Function name:  printOption
//
//  DESCRIPTION:    A user can print a record information
//                  through this function.
//
//  Parameters:     start(struct record **):
//
//  Return values:  void
//
**************************************************************/

void printOption(struct record *start)
{
    int accountNum;

    if(debugmode)
    {
        printf("\n*******************************\n");
        printf("Debug Mode Initiated\n");
        printf("Function called: printOption\n");
        printf("No parameters passed.\n");
        printf("*******************************\n\n");
    }

    printf("\nOption #2: Printing a record");
    printf("\nPlease enter account number: ");
    scanf("%d", &accountNum);

    if(printRecord(start, accountNum) == 0)
    {
        printf("\nHere is a record you requested.\n");
    }

    else
    {
        printf("\nI'm sorry. Record was not retrieved.\n");
    }
}

/*************************************************************
//
//  Function name:  findOption
//
//  DESCRIPTION:    A user can retrieve a record information 
//                  through name as a key.
//
//  Parameters:     start(struct record **):
//
//  Return values:  void
//
**************************************************************/

void findOption(struct record *start)
{
    char fName[25];
    
    if(debugmode)
    {
     	printf("\n*******************************\n");
        printf("Debug Mode Initiated\n");
        printf("Function called: findOption\n");
        printf("No parameters passed.\n\n");
        printf("*******************************\n\n");
    }

    printf("\nOption #4: Printing records whose names start with the given string");
    printf("\nPlease enter key string: ");
    fgets(fName, 25, stdin);

    if(findRecords(start, fName) == 0)
    {
     	printf("\nHere is a record you requested.\n");
    }

    else
    {
     	printf("\nI'm sorry. Record was not retrieved.\n");
    }
}

/*************************************************************
//
//  Function name:  deleteOption
//
//  DESCRIPTION:    A user can delete a record information
//                  through this function.
//
//  Parameters:     start(struct record **): 
//
//  Return values:  void       
//
***************************************************************/

void deleteOption(struct record **start)

{
    int accountNum;
    
    if(debugmode)
    {
        printf("\n*******************************\n");
     	printf("Debug Mode Initiated\n");
        printf("Function called: deleteOption\n");
        printf("No parameters passed.\n");
        printf("*******************************\n\n");
    }

    printf("Option #5: Deleting a record\n");

    printf("Please enter account number: \n");
    scanf("%d", &accountNum);

    if(deleteRecord(start, accountNum) == 0)
    {
        printf("\nThank you. Record was deleted successfully.");
    }

    else
    {
        printf("\nRecord was not deleted!\n");
    }
}

/*************************************************************  
//
//  Function name: getAddress
//
//  DESCRIPTION:   A user can obtain the address information
//                 through this function.
//
//  Parameters:    address[](char): the address stored as
//                 one character array
//                 max(int): the maximum length of the address
//  
//  Return values:  void
//
**************************************************************/

void getAddress(char address[], int max)

{
    int counter;
    char userInput[80];

    if(debugmode)
    {
        printf("\n*******************************\n");
        printf("Debug Mode Initiated\n");
        printf("Function called: getAddress\n");
        printf("Paramaters passed:\n");
        printf("address: %s\n", address);
        printf("max: %d\n", max);
        printf("*******************************\n\n");
    }
  
    printf("Please enter address(enter two times when you are finished): ");
    
    do
    {
        fgets(userInput, max, stdin);
        
        if(((int)strlen(address)+(int)strlen(userInput)) >= max)
        {
            printf("\nError: Address is too long.");
            printf("\nThe maximum number of characters allowed at this moment is: ");
            printf("%d", (max - (int)strlen(address) -2));
            printf("\n\nPlease enter the rest of address(enter empty line when you are finished): ");
        }
        else if(((int)strlen(address)+(int)strlen(userInput)) == (max-1))
        {
            printf("\nYour address is full!\n");
            strcat(address, userInput);
        }
        else
        {
            strcat(address, userInput);
        }
        
    } while(userInput[0] != '\n');
    
    for(counter=0; counter < 80; counter ++)
    {
        if(address[counter] == '\n')
        {
            address[counter] = ' ';
        }
    }
    
    fflush(stdin);
    
}




