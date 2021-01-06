#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#define MAXROWS 10
#define MAXCOLUMNS 10
// The maximum number of rows and columns supported

typedef struct matrix { 
    double *array;
    int columns;
    int rows;
} matrix;
/**************************************************
 * The matrix struct.                             *                      
 *                                                *
 * *array  - A pointer pointing to the            *
 *           first value of the array             *
 * columns - The number of columns the array has  *
 * rows    - The number of rows the array has     *
 **************************************************/

matrix *create_empty_matrix(int, int);
// Creates and memory allocates an empty matrix given the number of rows and columns.


bool check_for_errors(int, int, bool);
// Checks if there are any errors in the number of rows and columns.


matrix *create_matrix(bool);
// Creates matrix based on a set of inputs from the user.


int find_largest_length_of_numbers(matrix*); 
// Find the largest string length of any of the numbers, for formatting purposes.


double *get_pointer(matrix*, int, int);
// Gets the pointer of a value in the matrix given the position.

void display_matrix(matrix*);
// Displays a result matrix neatly in the stdout.


void free_matrix(matrix*);
// Frees a matrix from memory


#endif