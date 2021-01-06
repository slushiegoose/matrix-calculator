#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "all.h"

void add_matrices() {
    matrix *m1 = get_matrix(false, MATRIX1);
    matrix *m2 = get_matrix(false, MATRIX2);

    if(m1->rows != m2->rows || m1->columns != m2->columns) {
        // Matrix addition can only be done with two matrices of the same size.
        change_colour(yellow);
        printf("Error. Matrices should be the same size\n");
        return;
    }

    matrix *result = create_empty_matrix(m1->rows, m1->columns);

    for(int i = 0; i < m1->rows; ++i) {
        for(int j = 0; j < m1->columns; j++) {
            *get_pointer(result, i, j) = *get_pointer(m1, i, j) + *get_pointer(m2, i, j);
        }
    }

    free_matrix(m1);
    free_matrix(m2);
    change_colour(red);
    printf("\n\nThe result of your addition is:\n\n");
    display_matrix(result);
}
