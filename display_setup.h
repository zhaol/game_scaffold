#include <termios.h>    //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO

/*
EE160 Students, you can ignore the contents of this file.  If you are curious, you can read this SO post for more information:
//http://stackoverflow.com/questions/1798511/how-to-avoid-press-enter-with-any-getchar
*/

#define SETUP_DISPLAY static struct termios oldt, newt;         \
                      tcgetattr( STDIN_FILENO, &oldt);          \
                      newt = oldt;                              \
                      newt.c_lflag &= ~(ICANON);                \
                      tcsetattr( STDIN_FILENO, TCSANOW, &newt);
                      
#define BREAKDOWN_DISPLAY tcsetattr( STDIN_FILENO, TCSANOW, &oldt);