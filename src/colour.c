#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "colour.h"


void change_colour(colour c) {
    if(COLOUR) {
        switch(c) {
            case red: printf("\033[0;31m"); break;
            case green: printf("\033[0;32m"); break;
            case yellow: printf("\033[0;33m"); break;
            case blue: printf("\033[0;34m"); break;
            case magenta: printf("\033[0;35m"); break;
            case cyan: printf("\033[0;36m"); break;
            case white: printf("\033[0m"); break;
            case bright_red: printf("\033[0;91m"); break;
            case bright_green: printf("\033[0;92m"); break;
            case bright_yellow: printf("\033[0;93m"); break;
            case bright_blue: printf("\033[0;94m"); break;
            case bright_magenta: printf("\033[0;95m"); break;
            case bright_cyan: printf("\033[0;96m"); break;
    }
    }
}