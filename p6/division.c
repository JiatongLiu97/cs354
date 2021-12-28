////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        division.c
// Other Files:      intdate.c sendsig.c
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
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include  <signal.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int ope_counter = 0;//A counter for how many time successful division operations were completed

/* Handler for SIGINT signal
 *
 * sig: signal number
 * void
 */
void  SIGINThandler(int sig)
{
    printf("\nTotal number of operations completed successfully: %d\n", ope_counter);//print the number of successful division operation
    printf("The program will be terminated.\n");
    exit(0);// terminates this program

}

/* Handler for SIGFPE signal
 *
 * sig: signal number
 * void
 */
void  SIGFPEhandler(int sig)
{
    printf("Error: a division by 0 operation was attempted.\n");
    printf("Total number of operations completed successfully: %d\n", ope_counter);////print the number of successful division operation
    printf("The program will be terminated.\n");
    exit(0);// terminates this program

}

/* 
 * A driver method for this program
 *
 */
int main(int argc, char *argv[]){

  struct sigaction act2;
  memset (&act2, 0, sizeof(act2));
  act2.sa_handler = SIGFPEhandler;
  act2.sa_flags = 0;
  if ( sigaction(SIGFPE, &act2, NULL) != 0){
     printf("error binding to SIGFPE handler\n");
     exit(1);
  }

  struct sigaction act1;
  memset (&act1, 0, sizeof(act2));
  act2.sa_handler = SIGINThandler;
  act2.sa_flags = 0;
  if ( sigaction(SIGINT, &act2, NULL) != 0){
     printf("error binding to SIGINT handler\n");
     exit(1);
  }
	
  while(1){
    char buf[100];
    printf("Enter first integer: "); 
    fgets(buf, 100, stdin);// reads in a int from user 
    int int1 = atoi(buf);
    printf("Enter second integer: ");
    fgets(buf, 100, stdin);// reads in a int from user 
    int int2 = atoi(buf); // converts a string into an int
    // Do the division operation
    int quotient = int1/int2;
    int remainder = int1%int2; 
    printf("%d / %d is %d with a remainder of %d\n", int1, int2, quotient, remainder);
    ope_counter++;// Increments the counter when a division is done
  }
  return 0;
}  
