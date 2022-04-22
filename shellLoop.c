#include "shellLoop.h"
#include <stdio.h>

   int status = 1;          //global variable. Used to check if we should stay in the loop to keep asking for prompts
const int MAX = 50;
int i = 0;
 char *command[MAX];
void startShellLoop(){
    char buf[MAX];

    do{
        printf("prompt> ");
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
    char *cpyWord = strdup(input);
    char *token;
    if(strncmp(input, "Exit", 4) == 0 || strncmp(input, "exit", 4)==-0){
        printf("Exiting...");
        *status = 0;
        return ;
    }
    
    for(int i = 0; i < bufLength; i++){
        if(input[i] == '\n'){
            input[i] = '\0';
        }
    }

    token = strtok(cpyWord, ";");
    while(token !=NULL){
       // printf("token: %s\n", token);
        command[i] = token;
        printf("Command: %s\n", command[i]);
        int commandLength = strlen(command[i]);    
         char *c = command[i];  
        for(int j = 0; j < commandLength; j++){
            if(c[j] == '\0'){
                break;
            }
            if(c[j] == ' '){
                printf("Found a space in command[%d] of %s\n", j, command[i]);
            }
        }
        ++i;
        token = strtok(NULL, ";");
    }
    command[i] = '\0';
}

void execute(char **input, int *status){

}