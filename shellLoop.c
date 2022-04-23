#include "shellLoop.h"
#include <stdio.h>

   int status = 1;          //global variable. Used to check if we should stay in the loop to keep asking for prompts
const int MAX = 50;

 char *commands[MAX];
void startShellLoop(){
    char buf[MAX];

    do{
        printf("prompt> ");
        fgets(buf, MAX, stdin);     //reading from stdin
        parseInput(buf, &status);
        execute(commands, status);
    }
    while(status == 1);
}

//possible errors: user did not enter valid command --> execvp will check that. Then how about command? 

void parseInput(char *input, int* status){
    //passed in an array which is essentially broken down to as a pointer
    //Input is a char* argv[] double pointer but is a copy so let us make it a double pointer
    //each separate commands are separated by a semicolon 
    //(Ex) prompt> ls -latr ; cat filll
        int bufLength = strlen(input);
      for(int i = 0; i < bufLength; i++){
        if(input[i] == '\n'){
            input[i] = '\0';
        }
    }

    char *cpyWord = strdup(input);
    char *token;
    int i = 0;
    if(strncmp(input, "Exit", 4) == 0 || strncmp(input, "exit", 4)== 0){
        printf("Exiting...\n");
        *status = 0;
        return ;
    }
    

    //For now let us assume users input one command for each stdin. Might need to do some error checking
    token = strtok(cpyWord," ");
    while(token != NULL){
        commands[i] = token;
        printf("%s", commands[i]);
        i+=1;
        token = strtok(NULL, " ");
    }
    commands[i] = (char *) '\0';
    printf("Last command: %s\n", commands[i]);
}

void execute(char **input, int status){
    if(status == 1){
          int i =0;
    int pid; 
    pid = fork();
    
    //Check if forking was a success
    if(pid < 0){
        fprintf(stderr, "Error in creating newly forked child process\n");
    
    }
      //child process will execute the command which will replace its whole program
    else if(pid == 0){
        printf("Child process of pid: %d of parent pid: %d now executing command: %s\n", getpid(), getppid(),*input);
        if(execvp(input[0], input) == -1){
            fprintf(stderr, "Failed to execute command\n");
        }

    }
    //parent shall wait for the child process to finish executing and get the exit code of child
    else if(pid > 0){
        int status;
        while(wait(&status) >= 0){

                if(WIFSIGNALED(status)){
                    fprintf(stderr, "Child %d terminated abnormally with signal number: %d\n",pid, WTERMSIG(status));
                }
                else if(WIFEXITED((status))){
                    fprintf(stdout, "Exited with exitcode = %d\n", WEXITSTATUS((status)));
                }
        }
        
    }
    }
  
}