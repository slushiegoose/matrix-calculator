#ifndef COLOUR_HEADER
#define COLOUR_HEADER

typedef enum colour {red, green, yellow, blue, magenta, cyan, white, bright_red, bright_green, bright_yellow, bright_blue, bright_magenta, bright_cyan} colour;

#define COLOUR true
/*************************************************************
 * This macro decides on whether colours are used.           *
 *                                                           *
 * When this is set to true, ANSI-enabled terminals will     *
 * display colour-coded text. However, this can be set to    *
 * false if the terminal being used does not support ANSI    *
 * escape sequences.                                         *
 *************************************************************/

void change_colour(colour);
// Changes the terminal colours via ANSI escape sequences.

#endif