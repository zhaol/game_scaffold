void clear_screen () {
  int i;
  for (i=1; i <= SCREEN_HEIGHT; i++) {
    printf ("\n");
  }
}

void print_smiley(int current_screen_row) {
  if (current_screen_row == 2) {
    printf (".  .\n");
  } else if (current_screen_row == 3) {
    printf ("  |  \n");
  } else if (current_screen_row == 4) {
    printf ("\\___/\n");
  } else {
    printf ("\n");
  }
}

void print_frowney(int current_screen_row) {
  if (current_screen_row == 2) {
    printf (".  .\n");
  } else if (current_screen_row == 3) {
    printf ("  |  \n");
  } else if (current_screen_row == 4) {
    printf ("/`````\\\n");
  } else {
    printf ("\n");
  }
}

void print_blank_screen() {
  int i;
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

void draw_horizontal_borders(int current_screen_row) {
  int i;  
  if ((current_screen_row == 1) || (current_screen_row == SCREEN_HEIGHT)) {
    for (i=1; i <= SCREEN_WIDTH; i++) {
      printf ("%c", HORIZONTAL_BORDER);
    }
    printf ("\n");
  }
}