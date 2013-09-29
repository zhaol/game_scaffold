void clear_screen () {
  int i;
  for (i=1; i <= SCREEN_HEIGHT; i++) {
    printf ("\n");
  }
}

void display_instructions() {
  printf("Press 's' for smileys, 'f' for frowneys, and 'q' to quit\n");
}

void print_smiley(int current_screen_row) {
  int remaining_line_width = SCREEN_WIDTH;
  remaining_line_width = draw_left_of_content(remaining_line_width);
  
  if (current_screen_row == SMILEY_EYE_HEIGHT) {
    remaining_line_width -= draw_smiley_eyes();
    draw_rest_of_line(remaining_line_width);
  } else if (current_screen_row == SMILEY_NOSE_HEIGHT) {
    remaining_line_width -= draw_smiley_nose();
    draw_rest_of_line(remaining_line_width);
  } else if (current_screen_row == SMILEY_MOUTH_HEIGHT) {
    remaining_line_width -= draw_smiley_mouth();
    draw_rest_of_line(remaining_line_width);
  } else {
    draw_rest_of_line(remaining_line_width);
  }
}

void print_frowney(int current_screen_row) {
  int remaining_line_width = SCREEN_WIDTH;
  remaining_line_width = draw_left_of_content(remaining_line_width);
  
  if (current_screen_row == FROWNEY_EYE_HEIGHT) {
    remaining_line_width -= draw_frowney_eyes();
    draw_rest_of_line(remaining_line_width);
  } else if (current_screen_row == FROWNEY_NOSE_HEIGHT) {
    remaining_line_width -= draw_frowney_nose();
    draw_rest_of_line(remaining_line_width);
  } else if (current_screen_row == FROWNEY_MOUTH_HEIGHT) {
    remaining_line_width -= draw_frowney_mouth();
    draw_rest_of_line(remaining_line_width);
  } else {
    draw_rest_of_line(remaining_line_width);
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

int draw_left_of_content(int remaining_line_width) {
  remaining_line_width -= draw_left_border();  
  remaining_line_width -= draw_left_margin(LEFT_MARGIN);
  return remaining_line_width;
}

int draw_left_border() {
  printf("%c", VERTICAL_BORDER);  
  return 1;
}

int draw_left_margin(int margin) {
  int i;
  for (i=1; i<=margin; i++) {
    printf("%c", EMPTY_SPACE);
  }
}

void draw_rest_of_line(int remaining_line_width) {
  while (remaining_line_width >= 1) {
    printf("%c", EMPTY_SPACE);
    remaining_line_width--;
  }  
  draw_right_border();
}

void draw_right_border() {
  printf("%c\n", VERTICAL_BORDER);
}