/*****************************************************************
// 
// NAME:        Woojoon Hwang
//
// HOMEWORK:    Project 1
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        October 25, 2018
//
// FILE:        menu.c
//
// DESCRIPTION: This file contains the driver and the user-interface functions
// 		for Project 1. 
//
****************************************************************/

#include "prototypes.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void isDebug(int, char*[]);
void printMenu();
int getOptionInput();
void getInfo(int*, char[], char[]);
int getAccountno();
void getaddress(char[], int);

int debugmode;

/*****************************************************************
//
// Function name:  main
//
// Description:  This main function will let the user
//                choose depending on the menu options and
//                also run the debugging mode if desired.
//
// Parameters:  argc (int) : number of argments.
//	        argv (char*[]) : the poiner to the string of arguments.
//
****************************************************************/

int main(int argc, char * argv[])
{
    struct record * start = NULL;
    int choice;
    char name[25], address[80], reset[80];
    int accountno;

    isDebug(argc, &argv[1]);

    readfile(&start, "file.txt");

    do
    {    
        printMenu();
        choice = getOptionInput();

        printf("\n");

        switch(choice)
        {
            case 1: getInfo(&accountno, name, address);

                    if(addRecord(&start, accountno, name, address) == 0)
                    {
                        printf("Add successful.\n");
                    }
                    else
                    {
                        printf("Error: Add unsucessful.\n");
                    }

                    *address = *reset;

                    break;

            case 2: if(printRecord(start, getAccountno()) == -1)
                    {
                        printf("Error: Account number not found.\n");
                    } 

                    break;

            case 3: printAllRecords(start); 
                    printf("All records printed.\n");
                    break;

            case 4: if(deleteRecord(&start, getAccountno()) == 0)
                    {
                        printf("Delete successful.\n");
                    }
                    else
                    {
                        printf("Error: Account number not found.\n");
                    }
 
                    break;

            case 5: printf("Exited Program.\n"); 
                    break;

            default: printf("Error. Command not read.\n"); break;

        }

    } while(choice != 5);

    writefile(start, "file.txt");
    return 0;

}

/*****************************************************************
//
// Function name: isDebug
//
// Description: A function that activates debug mode.
//
// Parameters:	count (int) : contains the number of arguments that 
//		were processed.
//              argv (char*[]) : the poiner to the string of arguments.
//
// Return Values: void
****************************************************************/

void isDebug(int count, char* arg[])
{
    if(count == 2)
    {
        if(strcmp(*arg, "debug") == 0)
        { 
            debugmode = 1;
            printf("Debug Mode On\n");
        }
        else
        {
            debugmode = 0;
            printf("%s: Command not found.\n", *arg);
            exit(0);
        }
    }
    else if(count > 2)
    {
        debugmode = 0;
        printf("Error: There are more than 2 paramaters.\n");
        printf("Usage: ./menu\n");
        printf("       ./menu debug\n");
        exit(0);
    }
    else
    {
        debugmode = 0;
        printf("Debug Mode: Off\n");
    }
} 

/*****************************************************************
//
// Function name: printMenu
//
// Description:	This function prints the menu options.
//
// Parameters: 
//
// Return Values: void
****************************************************************/


void printMenu()
{
    if(debugmode)
    {
        printf("Debug Mode On\n");

        printf("\nFunction called: printMenu\n");
        printf("No parameters passed.\n");
        printf("\n");
    }

    printf("\n******************************************************************\n");
    printf("\nPlease enter a number 1 - 5 to select your option.\n");
    printf("\n");
    printf("[1] Add a new record\n");
    printf("[2] Print information in a record\n");
    printf("[3] Print all records\n");
    printf("[4] Delete a record\n");
    printf("[5] Quit the program\n");
    printf("\n");
    printf("\n******************************************************************\n");

}

/*****************************************************************
//
// Function name: getOptionInput
//   
// Description: This function gets the menu option input from the user
//              and then return the input of the user as an int.
//
// Parameters: 
//
// Return values: input : the menu choice of the user
****************************************************************/



int getOptionInput()
{
    int input;
    char junk[10];

    if(debugmode)
    {
        printf("Debug Mode On\n");

        printf("\nFunction called: getOptionInput\n");
        printf("No parameters passed.\n");
        printf("\n");
    }

    do
    {
        printf("Enter your choice of option: ");
        scanf("%d", &input);
        fgets(junk, 10, stdin);

        if (input < 1 || input > 5)
        {
            printf("Error: Please choose a number 1 - 5 for an option.\n");
        }
        
    } while (input < 1 || input > 5);


    return input;

}


/*****************************************************************
//
// Function name: getInfo
//
// DESCRIPTION: This function gets the information from the user.
//
// Parameters:	uaccountno (int*) : an int pointer for the users account no.
//	   	uname (char[]) : a char pointer for the users name.
//		uaddr (char[]) : a char pointer for the users address.
//		uyob (int *) : an int pointer for the users year of birth.
//
// Return Values: void
****************************************************************/




void getInfo(int * uaccountno, char uname[], char uaddr[])
{
  
    if(debugmode)
    {
        printf("Debug Mode On\n");
 
        printf("\nFunction called: getInfo\n");
        printf("Paramaters passed:\n");

        printf("uname: %s\n", uname);
        printf("uaddr: %s\n", uaddr);
        printf("\n");
    }

    *uaccountno = getAccountno();

    printf("\nType your full name and then press enter.\n");
    fgets(uname, 25, stdin);
    strtok(uname, "\n");
    
     
    getaddress(uaddr, 80);

}

/*****************************************************************
//
// Function name: getAccountno
//
// DESCRIPTION: This function obtains the account number of the user.
//              Then, return the account number of the user as int.
//
// Return values: userAccount : the account number of the user
//
****************************************************************/



int getAccountno()
{
    int userAccount = -1, i;
    char junk[10];

    if(debugmode)
    {
        printf("Debug Mode On\n");

        printf("\nFunction called: getAccountNo\n");
        printf("No parameters passed\n");
        printf("\n");
    }

    for(i = 0; userAccount < 0; i++)
    {
        if(i > 1)
        {
            printf("\nType the NUMBER of your account.");
        } 
        else
        {
            printf("\nPlease type your account number.");
        }

        printf("Then press enter.\n");

        scanf("%d", &userAccount);
        fgets(junk, 10, stdin);
    }

    return userAccount;
}

/*************************************************************  
//
//  Function name: getAddress
//
//  DESCRIPTION:   A user can obtain the address information
//                 through this function.
//
//  Parameters:    addressInput[](char): the address stored as
//                 one character array
//                 size(int): the size of char array being inputed.
//  
//  Return values:  void
//
**************************************************************/


void getaddress(char addressInput[], int size)
{
    char line[80];
    int i; 
    
    if(debugmode)
    {
        printf("Debug Mode On\n");

        printf("\nFunction called: getaddress\n");
        printf("Paramaters passed:\n");
 
        printf("addressInput: %s\n", addressInput);
        printf("size: %d\n", size);
        printf("\n");
    }

    printf("\nEnter address lines (empty line to finish): \n");

    while(*line != '\n')
    {
        fgets(line, 80, stdin);
        strcat(addressInput, line);
    }

    for(i = 0; i < 80; i++)
    {
        if(addressInput[i] == '\n')
        {
            addressInput[i] = ' ';
        }
    }
}
