#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "all.h"


void invert_matrix() {
    matrix *m = get_matrix(true, BLANK);

    matrix *inverse = find_inverse(m);

    if(inverse == 0) {
        return;
    }

    free_matrix(m);
    change_colour(red);
    printf("\n\nThe inverse matrix is:\n\n");
    display_matrix(inverse);

}

matrix *divide_by_determinant(matrix *m, double determinant) {

    matrix *inverse = create_empty_matrix(m->rows, m->columns);

    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->columns; j++) {
            *get_pointer(inverse, i, j) = *get_pointer(m, i, j) / determinant;
        }
    }

    return inverse;
}

matrix *find_inverse(matrix *m) {

    if(m->rows > 5) {
        change_colour(yellow);
        printf("\nThe biggest matrix for this function is 5x5.\n");
        return 0;
    }


    double determinant = find_determinant(m);

    if(determinant == 0) {
        change_colour(yellow);
        printf("\nA matrix with a determinant of 0 is not invertible.\n");
        return 0;
    }

    if(m->rows == 1) {
        matrix *inverse = create_empty_matrix(1, 1);
        *inverse->array = 1 / *m->array;
        return inverse;
    }

    /*************************************************************
    * To invert a matrix, one has to find the matrix of minors   *
    * and then find the matrix of cofactors of that and then     *
    * transpose it. Dividing that result by the determinant      *
    * finds the inverse of the matrix.                           *
    **************************************************************/
 

    matrix *minors = matrix_of_minors(m);
    matrix *cofactors = matrix_of_cofactors(minors);
    matrix *transposition = matrix_transposition(cofactors);
    matrix *inverse = divide_by_determinant(transposition, determinant);

    free_matrix(minors);
    free_matrix(cofactors);
    free_matrix(transposition);

    return inverse;
}