////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        sendsig.c
// Other Files:      division.c intdate.c
// Semester:         CS 354 Spring 2019
//
// Author:           Jiatong Liu
// Email:            jliu794@wisc.edu
// CS Login:         jiatongl
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
//////////////////////////// 80 columns wide ///////////////////////////////////
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 * Call the system call kill()
 *
 * pid:the process ID which will receive this signal
 * signal: signal type
 * void
 */
void send (int pid, char signal){
	printf("pid:%d  signal:%c\n", pid, signal);
	if (signal == 'i'){
           kill(pid, 2); 
	}
	if (signal == 'u'){
           kill(pid, 10);
	}
}

/*
 * Driver method which has two command arguments
 */
int main(int argc, char *argv[]){
        if (argc == 1){
		printf("Usage: <signal type> <pid>\n");
	        exit(0);
	}
	int pid = atoi(argv[2]);// Converts a string into int from command argument
        send(pid, *(argv[1]+1));	
}
