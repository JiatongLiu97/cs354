////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
// Other Files:      division.c sendsig.c
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
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include  <signal.h>
#include <time.h>
#include <string.h>

int SIGUSER1_count = 0; // counter of the number of how mant times SIGUSER1 signal has been received


/* Handler for SIGUSR1 signal
 *
 * sig: signal number
 * void
 */
void  USER1handler(int sig)
{
    ++ SIGUSER1_count;	
    printf("Recieving SIGUSER1 %d time(s)\n", SIGUSER1_count);

    
}

/* Handler for SIGALRM signal
 *
 * sig: signal number
 * void
 */
void  ALARMhandler(int sig)
{
  
  /* get the process id */
  pid_t pid;
  if ((pid = getpid()) < 0) {
	  perror("unable to get pid");
	} 
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);     
    printf("PID: %05d | Current Time:%s",pid, asctime(tm));

    alarm(3);     /* reset alarm */
}

/* Handler for SIGINT signal
 *
 * sig: signal number
 * void
 */
void  SIGINThandler(int sig)
{   
    printf("\nSIGINT received.\n");
    printf("SIGUSR1 was received %d times. Exiting now.\n", SIGUSER1_count);//print how many times SIGUSR1 has been received by this process
    exit(0);// terminate this program
 
}

/* 
 * A driver method. Main method
 * 
 */
int main(int argc, char *argv[])
{
  printf("Pid and time will be printed every 3 seconds.\n");
  printf("Enter ^C to end the program.\n");
  struct sigaction act;
  memset (&act, 0, sizeof(act));
  act.sa_handler = ALARMhandler;
  act.sa_flags = 0;
  if ( sigaction(SIGALRM, &act, NULL) != 0){
     printf("error binding to SIGALRM handler\n");
     exit(1);
  } 
  alarm(3);  /* set alarm clock     */

  struct sigaction act1;
  memset (&act1, 0, sizeof(act1));
  act1.sa_handler = USER1handler;
  act1.sa_flags = 0;
  if ( sigaction(SIGUSR1, &act1, NULL) != 0){
     printf("error binding to SIGUSER1 handler\n");
     exit(1);
  }

  struct sigaction act2;
  memset (&act2, 0, sizeof(act2));
  act2.sa_handler = SIGINThandler;
  act2.sa_flags = 0;
  if ( sigaction(SIGINT, &act2, NULL) != 0){
     printf("error binding to SIGINT handler\n");
     exit(1);
  }


  while (1){
}
  printf("All done");
}
