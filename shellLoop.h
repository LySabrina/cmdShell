#ifndef SHELL_LOOP
#define SHELL_LOOP

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * @brief Used to start the shell loop 
 * Ask user for input. If typed "Exit" or "exit", then stop program
 * If user typed command(s) then tell them what they print then execute commands
 * After that, ask users for commands again.
 * In the case the user did not type anything or invalid command, ask them to reenter commands
 * Repeat cycle
 * 
 */
void startShellLoop();

/**
 * @brief Parse the input such that it will work for execvp in later use
 * 
 * @param input a double char pointer to the user string input
 * @return char* a char pointer to the modified input 
 */
void parseInput(char* input, int* status);

/**
 * @brief Execute the commands from the user input
 * 
 * @param input the user input
 */
void execute(char** input, int *status);

#endif