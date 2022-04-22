#include "shellLoop.h"
#include <stdio.h>

const int MAX = 50;
void startShellLoop(){
    int status = 1;
    char buf[MAX];
    char *command[MAX];

    do{
        printf("Enter command(s):");
        fgets(buf, MAX, stdin);
        parseInput(buf, &status);

    }
    while(status == 1);
}

void parseInput(char *input, int* status){
    //passed in an array which is essentially broken down to as a pointer
    //Input is a char* argv[] double pointer but is a copy so let us make it a double pointer
    //each separate commands are separated by a semicolon 
    //(Ex) prompt> ls -latr ; cat filll
    int bufLength = strlen(input);
    printf("buflength: %d\n", bufLength);
    if(strncmp(input, "Exit", 4) == 0 || strncmp(input, "exit", 4)==-0){
        printf("Exiting...");
        *status = 0;
    }

}