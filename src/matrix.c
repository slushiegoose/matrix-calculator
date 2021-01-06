#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "matrix.h"
#include "read_string.h"
#include "colour.h"
#include "file.h"

matrix *create_empty_matrix(int rows, int columns) {
    matrix *m = malloc(sizeof(matrix));

    m->columns = columns;
    m->rows = rows;

    // https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
    m->array = (double *)calloc(rows * columns, sizeof(double));

    return m;
}


bool check_for_errors(int rows, int columns, bool square_required) {
    change_colour(yellow);
    if(rows > MAXROWS || columns > MAXCOLUMNS) {
        printf("The biggest matrix I can do is %ix%i.\n\n", MAXROWS, MAXCOLUMNS);
        return false;
    }
    else if(rows < 0 || columns < 0) {
        printf("The smallest matrix I can do is 1x1.\n\n");
        return false;
    }
    else if (rows != columns && square_required) {
        printf("A square matrix is required for this function.\n\n");
        return false;
    }
    else {
        printf("\n");
        return true;
    }
}

matrix *create_matrix(bool square_required) {
    int rows, columns;
    while(true) {
        change_colour(bright_cyan);
        char *input = read_string("Enter the dimensions in the form M x N: ");

        sscanf(input, "%i x %i", &rows, &columns);
    
        if(check_for_errors(rows, columns, square_required)) break;

    }

    matrix *m = create_empty_matrix(rows, columns);    


    while(true) {
        bool success = true;
        change_colour(bright_cyan);
        printf("Enter the matrix, following the format below\na b represents [ a  b ]\nc d            [ c  d ]\n\n");
        for(int i = 0; i < rows; ++i) {
            if(!success) break;
            int j = 0;
            // Reads a whole row of numbers and splits the numbers by spaces
            char *input = read_string("");
            char *token = strtok(input, " ");
            while(token) {
                // If there are more numbers in the row input than columns of the matrix
                if(j == columns) {
                    printf("Error: Input exceeds number of columns.\n\n");
                    success = false;
                    break;
                }
                sscanf(token, "%lf", get_pointer(m, i, j++));

                token = strtok(NULL, " ");
            }
            // If there are less numbers in the row input than columns of the matrix
            if(j < columns && success) {
                printf("Error: Input doesn't have enough columns.\n\n");
                success = false;
            }
        }
        if(success) break;
    }

    printf("\n\n");
    return m;
}

int find_largest_length_of_numbers(matrix *m) {

    int greatest_length = 0;
    char printed_number[20];

    for(int i = 0; i < m->rows; ++i) {
        for(int j = 0; j < m->columns; j++) {
            sprintf(printed_number, "%g", *get_pointer(m, i, j));
            size_t length = strlen(printed_number);
            if(length > greatest_length) {
                greatest_length = length;
            }
        }
    }
    
    return greatest_length;

}


double *get_pointer(matrix *m, int i, int j) {
    return (m->array + i*m->columns + j);
}


void display_matrix(matrix *result) {
    change_colour(red);
    int largest = find_largest_length_of_numbers(result);

    for(int i = 0; i < result->rows; i++) {
        for(int j = 0; j < result->columns; j++) {
            // Pads numbers by the largest length for display sake
            printf("%*g  ", largest, *get_pointer(result, i, j));
        }   
        printf("\n");
    }
    export_matrix(result);
    free_matrix(result);

}

void free_matrix(matrix *m) {
    free(m->array);
    free(m);
}
