#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "colour.h"
#include "matrix.h"
#include "read_string.h"
#include "file.h"
#include "operations/all.h"

FILE *open_file(char* mode) {
    change_colour(bright_blue);
    char file_path[100] = "data/matrices/";

    char *file_name = read_string("Enter the file name: ");
    strcat(file_path, file_name);

    FILE *file_obj = fopen(file_path, mode);
    free(file_name);

    if(file_obj == NULL) {
        change_colour(yellow);
        printf("\nUnable to open the file.\n");
    }

    return file_obj;
}


matrix *load_matrix(bool square_required) {
    FILE *input_file = open_file("r");

    if(input_file == NULL) return get_matrix(square_required, BLANK);

    // reads the dimensions of the matrix from the first line of the text file
    char dimensions[MAXLINELENGTH];
    fgets(dimensions, MAXLINELENGTH-1, input_file);

    int rows, columns;
    sscanf(dimensions, "%i x %i", &rows, &columns);

    if(!check_for_errors(rows, columns, square_required)) return get_matrix(square_required, BLANK);

    matrix *m = create_empty_matrix(rows, columns);

    for(int i = 0; i < rows; i++) {
        int j = 0;
        char buffer[MAXLINELENGTH];
        fgets(buffer, MAXLINELENGTH-1, input_file);

        // remove the newline character if it has one
        if(buffer[strlen(buffer)-1] == '\n') buffer[strlen(buffer)-1] = '\0';
        
        char *input = buffer;      
        char *token = strtok(input, " ");
        
        while(token) {
            if(j == columns) {
                printf("Error: Input exceeds number of columns. File invalid.\n\n");
                return get_matrix(square_required, BLANK);
            }
            sscanf(token, "%lf", get_pointer(m, i, j++));

            token = strtok(NULL, " ");
        }
        if(j < columns) {
            printf("Error: Input doesn't have enough columns. File invalid.\n\n");
            return get_matrix(square_required, BLANK);  
        }
    }

    fclose(input_file);
    return m;
    
    
}

bool ask_question(char* question) {
    while(true) {
        change_colour(bright_yellow);
        printf("%s", question);
        char *input = read_string("Type 'Y' for yes and 'N' for no\n");
        printf("\n");

        if(strcmp(input, "Y") == 0) {
            free(input);
            return true;
        }
        else if(strcmp(input, "N") == 0) {
            free(input);
            return false;
        }
        else {
            change_colour(yellow);
            printf("I only recognise 'Y' or 'N'\n\n");
        }
    }
}


matrix *get_matrix(bool square_required, char* pretext) {
    change_colour(bright_cyan);
    printf("%s", pretext);

    while(true) {

        if(ask_question("Would you like to import this matrix from a text file?\n")) {
            return load_matrix(square_required);
        } else {
            return create_matrix(square_required);
        }
    }
}

void export_matrix(matrix *m) {
    
    if(!ask_question("\n\nWould you like to export the result matrix to a text file?\n")) return;

    FILE *output_file = open_file("w");

    if(output_file == NULL) return export_matrix(m);

    fprintf(output_file, "%i x %i\n", m->rows, m->columns);

    int largest = find_largest_length_of_numbers(m);
    
    for(int i = 0; i < m->rows; i++) {
        for(int j = 0; j < m->columns; j++) {
            fprintf(output_file, "%*g  ", largest, *get_pointer(m, i, j));
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    change_colour(bright_red);
    printf("\n\nSaved!\n\n");

}