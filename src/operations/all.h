#ifndef OPERATIONS_HEADER
#define OPERATIONS_HEADER

#include "../matrix.h"

#define MATRIX1 "Matrix 1\n"
#define MATRIX2 "Matrix 2\n"
#define BLANK ""


/************************************************************
 * Some functions seem to be duplicated however there's     *
 * a distinct difference between both of them.              *
 *                                                          *
 * One is the core mathematical function which is used by   *
 * many different menu options.                             *
 *                                                          *
 * The other is the menu function that includes both        *
 * inputting and outputting the matrix to the console.      *
 ************************************************************/


void add_matrices();
// Adds two matrices together.

void subtract_matrices();
// Subtacts one matrix from another.


void multiply_matrices();
matrix* do_multiplication(matrix*, matrix*);
// Multiplies two matrices together.


void determinant_of_a_matrix();
double find_determinant(matrix*);
// Finds the determinant of a matrix.

matrix *create_minor(matrix*, int, int);
// Create a minor matrix from another matrix,
// given the row and column to exclude.


void transpose_matrix();
matrix *matrix_transposition(matrix*);
// Finds the transpose matrix of a matrix.

void minors_matrix();
matrix *matrix_of_minors(matrix*);
// Finds the matrix of minors of a matrix.

void cofactors_matrix();
matrix *matrix_of_cofactors(matrix*);
// Finds the matrix of cofactors of a matrix.


void invert_matrix();
matrix *find_inverse(matrix*);
// Finds the inverse of a matrix.

matrix *divide_by_determinant(matrix*, double);
// Divides all values in a matrix by its given determinant.

void multiply_by_scalar();
// Multiplies a matrix by a scalar value.

void raise_power();
// Raises a matrix to a power.


#endif