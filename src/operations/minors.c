#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "all.h"


void minors_matrix() {
    matrix *m = get_matrix(true, BLANK);

    if(m->rows < 2) {
        change_colour(yellow);
        printf("A matrix of minors cannot be made from a 1x1 matrix");
        return;
    }

    matrix *result = matrix_of_minors(m);

    free_matrix(m);
    change_colour(red);
    printf("\n\nYour matrix of minors is:\n\n");
    display_matrix(result);
}

matrix *matrix_of_minors(matrix *m) {

    matrix *minors = create_empty_matrix(m->rows, m->columns);

    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->columns; j++) {
            matrix *minor = create_minor(m, i, j);
            *get_pointer(minors, i, j) = find_determinant(minor);
            free_matrix(minor);
        }
    }

    return minors;

}

matrix *create_minor(matrix *original, int row, int column) {

    matrix *minor = create_empty_matrix(original->rows-1, original->columns-1);

    for(int i = 0; i < minor->rows; i++) {
        for(int j = 0; j < minor->columns; j++) {

            int og_row = i, og_col = j;

            /**********************************************************
            * Bumps up the original column and row index in order to  *
            * skip the unnecessary row and column that we do not wish *
            * to be in the minor matrix.                              *
            ***********************************************************/ 
            if(og_col >= column) og_col++;
            if(og_row >= row) og_row++;

            *get_pointer(minor, i, j) = *get_pointer(original, og_row, og_col);

        }
    }

    return minor;
}
