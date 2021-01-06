#ifndef FILE_HEADER
#define FILE_HEADER

FILE *open_file(char*);
// Opens a file and returns the file object.

matrix *load_matrix(bool);
// Imports a matrix from a text file.

bool ask_question(char*);
// Asks the given yes or no question and returns true on yes and false on no.

matrix *get_matrix(bool, char*);
// Gets a matrix by creating one or importing from a text file.

void export_matrix(matrix*);
// Exports the received matrix into a text file.

#endif