#include <stdio.h>
#include "display_setup.h"
#include "display_constants.h"
#include "display_helpers.h"

main () {
  int i;
  int current_screen_row = 1;
  char command;
  
  SETUP_DISPLAY

  do {
    clear_screen();

    current_screen_row = 1;
    while (current_screen_row <= SCREEN_HEIGHT) {
      if ((current_screen_row == 1) || (current_screen_row == SCREEN_HEIGHT)) {
        for (i=1; i <= SCREEN_WIDTH; i++) {
          printf ("%c", HORIZONTAL_BORDER);
        }
        printf ("\n");
      }
      if ((current_screen_row != 1) && (current_screen_row != SCREEN_HEIGHT)) {
        if (command == 's') {
          if (current_screen_row == 2) {
            printf (".  .\n");
          } else if (current_screen_row == 3) {
            printf ("  |  \n");
          } else if (current_screen_row == 4) {
            printf ("\\___/\n");
          } else {
            printf ("\n");
          }
        } else if (command == 'b') {
          if (current_screen_row == 2) {
            printf (".  .\n");
          } else if (current_screen_row == 3) {
            printf ("  |  \n");
          } else if (current_screen_row == 4) {
            printf ("/`````\\\n");
          } else {
            printf ("\n");
          }
        } else {
          for (i=1; i <= SCREEN_WIDTH; i++) {
            if (i == 1) {  
              printf("%c", VERTICAL_BORDER);
            } else if (i == SCREEN_WIDTH) {  
              printf("%c\n", VERTICAL_BORDER);
            } else {
              printf(" ");
            }
          }
        }
      }
      current_screen_row++;  
    }
    command = getchar();
  } while (command != 'q');
  
  BREAKDOWN_DISPLAY
}