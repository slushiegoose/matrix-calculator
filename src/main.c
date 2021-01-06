#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "menu.h"

void main() {
    while(true) {
        display_menu();
        bool quit = get_menu_option();
        if(quit) break;
    }
}