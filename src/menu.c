#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "read_string.h"
#include "operations/all.h"
#include "menu.h"
#include "colour.h"

void display_menu() {
    change_colour(bright_magenta);
    printf("\nMATRIX CALCULATOR\n\n");
    printf("%i. Add 2 matrices\n", ADD);
    printf("%i. Subtract 2 matrices\n", SUBTRACT);
    printf("%i. Multiply 2 matrices\n", MULTIPLY);
    printf("%i. Multiply a matrix by its scalar\n", SCALAR);
    printf("%i. Find the determinant of a matrix\n", DETERMINANT);
    printf("%i. Invert a matrix\n", INVERT);
    printf("%i. Transpose a matrix\n", TRANSPOSE);
    printf("%i. Find the matrix of cofactors of a matrix\n", COFACTORS);
    printf("%i. Find the matrix of minors of a matrix\n", MINORS);
    printf("%i. Raise a matrix to a power\n", POWER);
    printf("\n   Type %i to quit\n\n", QUIT);

}

bool get_menu_option() {
    int option = -2;
    change_colour(bright_blue);
    char *input = read_string("Enter selection: ");
    sscanf(input, "%i", &option);
    free(input);
    printf("\n");
    do_option(option);
    return option==QUIT;
}

void do_option(int option) {
    switch(option) {
        case ADD : add_matrices(); break;
        case SUBTRACT: subtract_matrices(); break;
        case MULTIPLY: multiply_matrices(); break;
        case SCALAR: multiply_by_scalar(); break;
        case DETERMINANT: determinant_of_a_matrix(); break;
        case INVERT: invert_matrix(); break;
        case TRANSPOSE: transpose_matrix(); break;
        case COFACTORS: cofactors_matrix(); break;
        case MINORS: minors_matrix(); break;
        case POWER: raise_power(); break;
        case QUIT: change_colour(white); printf("Goodbye!\n\n"); break;
        default: printf("\nSorry, I don't recognise that option, try again.\n");
    }
}