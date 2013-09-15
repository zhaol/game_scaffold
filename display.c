#include <stdio.h>
#include <termios.h>    //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO

#define SCREEN_HEIGHT 20
#define SCREEN_WIDTH 40
#define HORIZONTAL_BORDER '-'
#define VERTICAL_BORDER '|'

main () {
  int i;
  int current_screen_row = 1;
  char command;
  
  //http://stackoverflow.com/questions/1798511/how-to-avoid-press-enter-with-any-getchar
  static struct termios oldt, newt;

  /*tcgetattr gets the parameters of the current terminal
  STDIN_FILENO will tell tcgetattr that it should write the settings
  of stdin to oldt*/
  tcgetattr( STDIN_FILENO, &oldt);
  /*now the settings will be copied*/
  newt = oldt;

  /*ICANON normally takes care that one line at a time will be processed
  that means it will return if it sees a "\n" or an EOF or an EOL*/
  newt.c_lflag &= ~(ICANON);          

  /*Those new settings will be set to STDIN
  TCSANOW tells tcsetattr to change attributes immediately. */
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  
  
  

  
  do {
    for (i=1; i <= SCREEN_HEIGHT * 5; i++) {
      printf ("\n");
    }
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
  
  /*restore the old settings*/
  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}