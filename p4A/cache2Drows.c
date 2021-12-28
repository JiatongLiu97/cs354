////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Drows.c
// This File:        cache2Drows.c
// Other Files:      cache1D.c cache2Dcols.c
// Semester:         CS 354
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

int arr2D[3000][500];// create a 2D array with 3000 rows and 500 columns 


int main(){
     int row, col;
     for (row = 0; row < 3000; row++){// outer loop to iterate rows
          for (col = 0; col < 500; col++){// inner loop to iterate each element in a row
              arr2D[row][col] = row + col;
	  }	  

     }
     return 0;
}	
