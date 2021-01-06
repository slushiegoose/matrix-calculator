#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "all.h"


void determinant_of_a_matrix() {
    matrix *m = get_matrix(true, BLANK);

    double determinant = find_determinant(m);

    change_colour(red);
    printf("\n\nThe determinant of the matrix is:\n\n%g\n\n", determinant);
    free_matrix(m);

}


double find_determinant(matrix *m) {
    double determinant = 0;

    if(m->rows == 1) {
        determinant = *m->array;
    } else {
        for(int i = 0; i < m->rows; i++) {

            /*****************************************************
             * This recursive function allows the determinant    *
             * to be determined for any square matrix by finding *
             * the determinant of each of the top row's minors   *
             * recursively.                                      *
             *****************************************************/

            matrix *minor = create_minor(m, 0, i);
            determinant += pow(-1, i) * *get_pointer(m, 0, i) * find_determinant(minor);
            free_matrix(minor);
        }
    }

    return determinant;    
}
