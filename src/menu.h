#ifndef MENU_HEADER
#define MENU_HEADER

#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define SCALAR 4
#define DETERMINANT 5
#define INVERT 6
#define TRANSPOSE 7
#define COFACTORS 8
#define MINORS 9
#define POWER 0
#define QUIT -1
// The number values for each of the menu options.

void display_menu();
// Prints the menu to stdout.

bool get_menu_option();
// Asks the user for the menu option and returns whether the user quiited.

void do_option(int);
// Execute the relevant function based on the option selected.

#endif