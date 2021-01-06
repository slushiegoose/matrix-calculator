#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "../read_string.h"
#include "all.h"

void multiply_by_scalar() {
    matrix *m = get_matrix(false, BLANK);

    double value;
    change_colour(bright_cyan);
    char *input = read_string("Enter the scalar to multiply with: ");
    sscanf(input, "%lf", &value);
    printf("\n");

    matrix *result = create_empty_matrix(m->rows, m->columns);

    for(int i = 0; i < m->rows; ++i) {
        for(int j = 0; j < m->columns; j++) {
            *get_pointer(result, i, j) = *get_pointer(m, i, j) * value;
        }
    }

    free_matrix(m);
    change_colour(red);
    printf("\n\nThe result of your scalar multiplication is:\n\n");
    display_matrix(result);

}
