#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../matrix.h"
#include "../colour.h"
#include "../file.h"
#include "../read_string.h"
#include "all.h"


void raise_power() {
    matrix *m = get_matrix(true, BLANK);
    double power;

    while(true) {
        change_colour(bright_cyan);

        char *input = read_string("Enter the number you'd like to raise the power by: ");

        sscanf(input, "%lf", &power);

        if(ceil(power) != power) {
            change_colour(yellow);
            printf("\nPower cannot be a decimal.\n\n");
        } else if(power > 10 || power < -10) {
            printf("\nPower has to be between -10 and 10");
        } else {
            printf("\n");
            break;
        }

    }

    matrix *result = create_empty_matrix(m->rows, m->columns);
    if(power > 0) {
        memcpy(result, m, sizeof(matrix));
        for(int i = 0; i < power-1; i++) {
            result = do_multiplication(result, m);
        }
    } else if(power == 0) {
        // Finds the identity matrix since A^0 = I for any A
        for(int i=0; i < m->rows; i++) {
            for(int j=0; j < m->columns; j++) {
                *get_pointer(result, i, j) = i == j;
            }
        }
    } else {
        matrix *inverse = find_inverse(m);
        if(inverse==0) return;
        memcpy(result, inverse, sizeof(matrix));
        for(int i = 0; i < (-power)-1; i++) {
            result = do_multiplication(result, inverse);
        }
        free(inverse);
        

    }
    free_matrix(m);
    change_colour(red);
    printf("\n\nThe result of your power is:\n\n");
    display_matrix(result);

};

