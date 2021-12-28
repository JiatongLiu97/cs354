////////////////////////////////////////////////////////////////////////////////
// Main File:        check_queens.c (source file of check_queen, check it there 
//                       is a pair of queens attacking each other
// This File:        check-queens 
// Other Files:      
// Semester:         CS 354 SPRING 2019
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
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>   
 
char *COMMA = ",";
  
/* COMPLETED:
 * Retrieves from the first line of the input file,
 * the number of rows and columns for the board.
 * 
 * fp: file pointer for input file
 * rows: pointer to number of rows
 * cols: pointer to number of columns
 */
void get_dimensions(FILE *fp, int *rows, int *cols) {  
        char *line = NULL;  
        size_t len = 0;  
        if (getline(&line, &len, fp) == -1) {  
                printf("Error in reading the file\n");  
                exit(1);  
        }  
           
        char *token = NULL; 
        token = strtok(line, COMMA);
        *rows = atoi(token); 
           
        token = strtok(NULL, COMMA); 
        *cols = atoi(token);
}      


/* TODO:
 * Returns 1 if and only if there exists at least one pair
 * of queens that can attack each other.
 * Otherwise returns 0.
 * 
 * board: heap allocated 2D board
 * rows: number of rows
 * cols: number of columns
 */
int check_queens(int **board, int rows, int cols) {  
    int i;// row
    int j;// column
    for (  i = 0; i < rows; i++){
        for ( j = 0; j < cols; j++){
            int each_position = *(*(board + i) + j);
            // the first queen is found
            if (each_position == 1){
                // search if there is a queen in the same col
                for ( int m = i + 1; m < rows; m++){
                    int other_position = *(*(board + m) + j);
                    if (other_position == 1)
                        return 1;
                }
                // search if there is a queen in the same row
                for ( int m = j + 1; m < cols; m++){
                    int other_position = *(*(board + i) + m);
                    if (other_position == 1)
                        return 1;
                }
                // search if there is a queen in the same leading diagonal
	        int next_row = i + 1;
		int next_col = j + 1;
                while ( next_row < rows && next_col < cols){   
                   if ( *(*(board + next_row) + next_col ) == 1){
			 return 1;  
                   }
		   else{
		       // go to next postion on the leading  diagonal line
		       next_row++;
		       next_col++;
                   }
                }
		//  search if there is a queen in the same non-leading diagonal
		int next_row2 = i + 1;
                int next_col2 = j - 1;
                while ( next_row2 < rows && 0 <= next_col2){
                   if ( *(*(board + next_row) + next_col ) == 1){
                         return 1;
                   }
                   else{
                       // go to next postion on the leading  diagonal line
                       next_row2++;
                       next_col2--;
                   }
                }
            }
        }
    }
        return 0;
}     


/* PARTIALLY COMPLETED:
 * This program prints true if the input file has any pair
 * of queens that can attack each other, and false otherwise
 * 
 * argc: CLA count
 * argv: CLA value 
 */
int main(int argc, char *argv[]) {        

        //TODO: Check if number of command-line arguments is correct.
        if ( argc != 2){
             printf("Usage: ./check_queens <input_filename>\n");
             exit(1);
        }     

        //Open the file and check if it opened successfully.
        FILE *fp = fopen(*(argv + 1), "r");
        if (fp == NULL) {
                printf("Cannot open file for reading\n");
                exit(1);
        }


        //Declare local variables.
        int rows, cols;


        //TODO: Call get_dimensions to retrieve the board dimensions.
        get_dimensions(fp, &rows, &cols);

        //TODO: Dynamically allocate a 2D array of dimensions retrieved above.
        int **board = malloc(sizeof(int *) * rows);
        for ( int i = 0; i < rows; i++){
            *(board + i) = malloc(sizeof(int) * cols);
        }

        //Read the file line by line.
        //Tokenize each line wrt comma to store the values in your 2D array.
        char *line = NULL;
        size_t len = 0;
        char *token = NULL;
        for (int i = 0; i < rows; i++) {

                if (getline(&line, &len, fp) == -1) {
                        printf("Error while reading the file\n");
                        exit(1);        
                }

                token = strtok(line, COMMA);
                for (int j = 0; j < cols; j++) {
                        //TODO: Complete the line of code below
                        //to initialize your 2D array.
                        /* ADD ARRAY ACCESS CODE HERE */
		        *(*(board + i) + j) = atoi(token);
                        strtok(NULL, COMMA);    
                }
        }

        //TODO: Call the function check_queens and print the appropriate
        //output depending on the function's return value.
        int result;
        result = check_queens(board, rows, cols);
        if ( result == 1)
           printf("True\n");
        else
           printf("false\n");
        
        //TODO: Free all dynamically allocated memory.
        for ( int i = 0; i < rows; i++)
            free(*(board + i));
        // free the array of rows
        free(board);

        //Close the file.
        if (fclose(fp) != 0) {
                printf("Error while closing the file\n");
                exit(1);        
        }

        return 0;
}      
