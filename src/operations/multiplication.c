#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "all.h"

void multiply_matrices() {
    matrix *m1 = get_matrix(false, MATRIX1);
    matrix *m2 = get_matrix(false, MATRIX2);

    if(m1->columns != m2->rows) {
        // Matrix multiplication requires M1's column number and M2's row count to be the same
        change_colour(yellow);
        printf("Error. The number of columns Matrix 1 has should be the same as the number of rows of Matrix 2");
        return;
    }

    matrix *result = do_multiplication(m1, m2);

    free_matrix(m1);
    free_matrix(m2);
    change_colour(red);
    printf("\n\nThe result of your mutliplication is:\n\n");
    display_matrix(result);

}

matrix *do_multiplication(matrix *m1, matrix *m2) {
    matrix *result = create_empty_matrix(m1->rows, m2->columns);

    for(int i = 0; i < m1->rows; ++i) {
        for(int j = 0; j < m2->columns; ++j) {
            for(int k=0; k < m1->columns; ++k) {
                *get_pointer(result, i, j) += *get_pointer(m1, i, k) * *get_pointer(m2, k, j);
            }
        }
    }

    return result;
}