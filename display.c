#include <stdio.h>
#include "display_setup.h"
#include "display_constants.h"
#include "display_helpers.h"

main () {
  int i;
  int current_screen_row = 1;
  char command;
  
  SETUP_DISPLAY
  clear_screen();

  while (command != 'q') { // a do..while loop would have been a nicer fit here
    clear_screen();

    current_screen_row = 1;
    while (current_screen_row <= SCREEN_HEIGHT) {
      draw_horizontal_borders(current_screen_row);

      if ((current_screen_row != 1) && (current_screen_row != SCREEN_HEIGHT)) { // we will talk about the AND (&&) operator later
        if (command == 's') {
          print_smiley(current_screen_row);
        } else if (command == 'b') {
          print_frowney(current_screen_row);
        } else {
          print_blank_screen(current_screen_row);
        }
      }
      current_screen_row++;  
    }
    command = getchar(); // you should Google getchar and play around with this function to get comfortable with it
  }
  
  BREAKDOWN_DISPLAY
}