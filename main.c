#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shellLoop.h"

int main(int argc, char* argv[]){
    //argc = 1 would be the executable so if it is <= 1 then we ask them to reenter commands or files
   //need a loop that keeps 
    startShellLoop();
    return 0;
}