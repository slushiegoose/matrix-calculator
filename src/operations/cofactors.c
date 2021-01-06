#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "all.h"


void cofactors_matrix() {
    matrix *m = get_matrix(true, BLANK);

    matrix *result = matrix_of_cofactors(m);

    free_matrix(m);
    change_colour(red);
    printf("\n\nYour matrix of cofactors is:\n\n");
    display_matrix(result);
}

matrix *matrix_of_cofactors(matrix *m) {

    matrix *cofactors = create_empty_matrix(m->rows, m->columns);

    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->columns; j++) {

            /**********************************************************
            * -1 or 1 based on the row number (i) & column number (j) *
            * This is simpler than using if statements based on the   *
            * matrix size and the row and column number               *
            * and nicely simplifies it into one line of code          *
            ***********************************************************/
    
            int multiplier = pow(-1, 2-(i%2)+j);
            *get_pointer(cofactors, i, j) = *get_pointer(m, i, j) * multiplier;
        }
    }

    return cofactors;

}

