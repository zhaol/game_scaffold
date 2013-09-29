/*   File:  display.c
//   By:    The Awesome Class of EE160
//   Date:	Today :)
*/

#include <stdio.h>
#include "display.h"

// This program provides the basic foundations to all future game type lab assignments in EE160
int main () {
  int i;
  int current_screen_row = 1;
  char command;
  
  SETUP_DISPLAY
  clear_screen();

  while (command != 'q') { // a do..while loop would have been a nicer fit here; we will talk about the do..while loop later
    clear_screen();
    display_instructions();

    current_screen_row = 1;
    while (current_screen_row <= SCREEN_HEIGHT) {
      draw_horizontal_borders(current_screen_row);

      if ((current_screen_row != 1) && (current_screen_row != SCREEN_HEIGHT)) { // we will talk about the AND (&&) operator later (but you can Google it for now)
        if (command == 's') {
          print_smiley(current_screen_row);
        } else if (command == 'f') { // we will talk about else if later (but you can Google it for now)
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
  return 0;
}