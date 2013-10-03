/*   File:  display.c
//   By:    The Awesome Class of EE160
//   Date:	Today :)
*/

#include <stdio.h>
#include "display.h"

// This program provides the basic foundations to all future game type lab assignments in EE160
int main () {
  int i;
  char command;
  int x_position = HORIZONTAL_START;
  int y_position = VERTICAL_START;
  
  SETUP_DISPLAY
  clear_screen();

  while (command != QUIT_KEY) { // a do..while loop would have been a nicer fit here; we will talk about the do..while loop later
    clear_screen();
    display_instructions();
    update_position(&x_position, &y_position, command);
    display_position(x_position, y_position);
    
    redraw_screen(x_position, y_position);
    command = getchar(); // you should Google getchar and play around with this function to get comfortable with it
  }
  
  BREAKDOWN_DISPLAY
  return 0;
}