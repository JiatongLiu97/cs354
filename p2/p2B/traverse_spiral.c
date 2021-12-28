////////////////////////////////////////////////////////////////////////////////
// Main File:        (name of file with main function)
// This File:        (name of this file)
// Other Files:      (name of all other files if any)
// Semester:         CS 354 Spring 2019
//
// Author:           (your name)
// Email:            (your wisc email address)
// CS Login:         (your CS login name)
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

// Structure representing Matrix
// size: Dimension of the square (size*size)
// array: 2D array of integers
typedef struct _Square
{
  int size;
  int **array;
} Square;

/* TODO:
 * Retrieves from the first line of the input file,
 * the size of the square matrix.
 * 
 * fp: file pointer for input file
 * size: pointer to size of the square matrix
 */
void
get_dimensions (FILE * fp, int *size)
{
  char *line = NULL;
  size_t len = 0;
  if (getline (&line, &len, fp) == -1)
    {
      printf ("Error in reading the file\n");
      exit (1);
    }
  char *token = NULL;
  token = strtok (line, COMMA);
  *size = atoi (token);

}

/* PARTIALLY COMPLETED:
 * Traverses a given layer from the square matrix
 * 
 * array: Heap allocated 2D square matrix
 * size: size of the 2D square matrix
 * layer: layer number to be traversed
 * op: pointer to the output file
 */
void
traverse_layer (int **array, int size, int layer, FILE * op)
{
  int row_num, col_num;
  int i, j;

  //corner case: size is odd & the layer is last so only one entry to print
  if (size % 2 == 1 && layer == (size + 1) / 2 - 1)
    {
      fprintf (op, "%d\n", *(*(array + layer) + layer));
      return; 
    }

  //Traverse upper row from left to right with appropriate bounds
  row_num = layer;
  printf("row_num  %d", row_num);
  for (j = row_num; j < (size - layer); j++)
    {
      fprintf (op, "%d\n", *(*(array + row_num) + j));
      printf("Th  %d", *(*(array + row_num) + j));
      return;
    }

  //Traverse right column from top to bottom with appropriate bounds
  col_num = size - layer - 1;
  for (i = layer; i < size - layer; i++)
    {
      fprintf (op, "%d\n", *(*(array + i) + col_num));
      return;
    }

  //Traverse lower row from right to left with appropriate bounds
  row_num = size - layer - 1;
  for (j = j; layer <= j; j--)
    {
      fprintf (op, "%d\n", *(*(array + row_num) + j));
      return;
    }

  //Traverse left column from bottom to top with appropriate bounds
  col_num = layer;
  for (i = i; i >= layer; i--)
    {
      fprintf (op, "%d\n", *(*(array + i) + col_num));
     return;
    }
  return; 
}


/* COMPLETED:
 * Traverses the square matrix spirally
 * 
 * square: pointer to a structure that contains 2D square matrix
 * op: pointer to the output file
 */
void
traverse_spirally (Square * square, FILE * op)
{
  int size = square->size;
  int num_layers = 0;
  num_layers = size / 2;
  if (size % 2 == 1)
    {
      num_layers++;
    }

  int i;
  for (i = 0; i < num_layers; i++)
    {
      traverse_layer (square->array, size, i, op);
    }
     printf("size  %d\n", (size));
}

/* PARTIALLY COMPLETED:
 * This program reads a square matrix from the input file
 * and outputs its spiral order traversal to the output file
 *
 * argc: CLA count
 * argv: CLA value
 */

int
main (int argc, char *argv[])
{
  //TODO: Check if number of command-line arguments is correct.
  if (argc != 3)
    {
      printf ("Usage: ./check_queens <input_filename>\n");
      exit (1);
    }

  //Open the file and check if it opened successfully.
  FILE *fp = fopen (*(argv + 1), "r");
  if (fp == NULL)
    {
      printf ("Cannot open file for reading\n");
      exit (1);
    }
  //Call the function get_dimensions to retrieve size of the square matrix
  int *size = malloc (sizeof (int));
  get_dimensions (fp, size);
  //Dynamically allocate a 2D array as per the retrieved dimensions
  int size_num = *size;		// the size
  
  //
  
 
  printf("Enter an integer\n");
  
 
  printf("The integer is %d\n", size_num);
 
  //

  int **board = malloc (sizeof (int *) * size_num);
  for (int i = 0; i < size_num; i++)
    {
      *(board + i) = malloc (sizeof (int) * size_num);
    }


  //Read the file line by line by using the function getline as used in get_dimensions
  //Tokenize each line wrt comma to store the values in the square matrix
  char *line = NULL;
  size_t len = 0;
  char *token = NULL;
  for (int i = 0; i < size_num; i++)
    {

      if (getline (&line, &len, fp) == -1)
	{
	  printf ("Error while reading the file\n");
	  exit (1);
	}

      token = strtok (line, COMMA);
      for (int j = 0; j < size_num; j++)
	{
	  //TODO: Complete the line of code below
	  //to initialize your 2D array.
	  /* ADD ARRAY ACCESS CODE HERE */
	  *(*(board + i) + j) = atoi (token);
	  token = strtok(NULL, COMMA);    
	}
    }

    

 




  //Create a structure and initialize its size and array fields appropriately
  Square *square = malloc (sizeof (*square));
  (*square).size = size_num;
  (*square).array = board;
 
  //



    for ( int i = 0; i < 4; i++){
        for ( int j = 0; j < 4; j++){

          printf("Th  %d\n", ((*square).array)[i][j]);
        }
        printf(" new row\n");
    }


    //

  //Open the output file
  //Open the output file and check if it opened successfully.
  FILE *ofp = fopen (*(argv + 2), "w");
  if (ofp == NULL)
    {
      printf ("Cannot open file for reading\n");
      exit (1);
    }


  //Call the function traverse_spirally
  traverse_spirally (square, ofp);


  //Free the dynamically allocated memory
  //Free each columns in each row
  for (int i = 0; i < size_num; i++)
    {
      free (*(board + i));
    }
  // free the array of arrays
  free (board);

  //Close the input file
  if (fclose (fp) != 0)
    {
      printf ("Error while closing the file\n");
      exit (1);
    }

  //Close the output file
  if (fclose (ofp) != 0)
    {
      printf ("Error while closing the file\n");
      exit (1);
    }
  return 0;
}
