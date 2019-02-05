/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};
    char arg[BUFFER_LEN] = {0};

    // Parse the commands provided using argc and argv

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
	
	int length = strlen(buffer);
	int i = 0;
	int commandLength;
	while (buffer[i] != ' ' && i < length){
		if (buffer[i] != '\n')
			command[i] = buffer[i];
		i++;
	}
	commandLength = i + 1;
	command[i++] = '\0';

	while (i < length){
		if (buffer[i] != '\n')
			arg[i - commandLength] = buffer[i];
		i++;
	}
	arg[i++] = '\0';

	//printf("%s\n", command); 
	//printf("%s\n", arg); 
	

        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0)
        {
            // your code here
        }

        // other commands here...

	// run the echo command
	if (strcmp(command, "echo") == 0)
        {
	    for (int i = 0; i < strlen(arg); i++){
		if (arg[i] == ' ')
			printf("\n");
		else
	            printf("%c", arg[i]);
	    }
	    printf("\n");
        }

        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return 0;
        }

        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
    }
    return EXIT_SUCCESS;
}
