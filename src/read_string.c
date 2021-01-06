#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "colour.h"
#include "read_string.h"

char* read_string(char* prompt) {
  char buffer[MAXLINELENGTH];
  printf("%s", prompt);

  change_colour(bright_green);
  fgets(buffer, MAXLINELENGTH, stdin);

  size_t input_length = strlen(buffer);

  char *input = calloc(input_length, sizeof(char));
  strncpy(input, buffer, input_length-1);

  input[input_length-1] = '\0';

  return input;
}