#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "all.h"


void transpose_matrix() {
    matrix *m = get_matrix(false, BLANK);

    matrix *result = matrix_transposition(m);

    free_matrix(m);
    change_colour(red);
    printf("\n\nThe result of your transposition is:\n\n");
    display_matrix(result);
}

matrix *matrix_transposition(matrix *m) {

    matrix *transposition = create_empty_matrix(m->columns, m->rows);

    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->columns; j++) {
            *get_pointer(transposition, j, i) = *get_pointer(m, i, j);
        }
    }

    return transposition;
}