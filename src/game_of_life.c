#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 25
#define M 80
#define white '.'
#define black '0'

void print_rules();
void print_field(char **field);
void create_field(char ***field);
void free_field(char ***field);
void input(char ***field, FILE *f);

int change_generation(char ***matrix);
int check_for_end(char **matrix, char **new_matrix);
int count_alive_neighbours(char **matrix, int i, int j);

void init_screen();
void get_speed(int *speed);
void make_pause(int speed);

int main() {
  FILE *f;
  while (1) {
    printf("Please enter name of file!\n");
    char name[50];
    scanf("%s", name);
    f = fopen(name, "r");
    if (f != NULL) {
      break;
    }
  }

  init_screen();
  char **field;
  int speed = 1;
  create_field(&field);
  input(&field, f);
  print_field(field);

  while (1) {
    get_speed(&speed);
    int res = change_generation(&field);
    if (res == 1) {
      break;
    }

    make_pause(speed);
    print_field(field);
    refresh();
  }

  free_field(&field);
  fclose(f);
  printf("END");
  sleep(2);

  nocbreak();
  echo();
  endwin();
  return 0;
}

void print_rules() { printw("HELLO\n"); }

void init_screen() {
  clear();
  initscr();
  cbreak();
  noecho();
  timeout(0);
  print_rules();
  refresh();
  sleep(2);
}

void get_speed(int *speed) {
  printw("f - make faster, s - make slower\n");
  printw("current speed is %d\n", *speed);
  refresh();

  char c = getch();

  if (c == 'f' && *speed < 100) {
    (*speed)++;
  } else if (c == 's' && *speed > 0) {
    (*speed)--;
  }
}

void create_field(char ***field) {
  *field = malloc(N * sizeof(char *));
  for (int i = 0; i < N; ++i) {
    (*field)[i] = malloc(M * sizeof(char));
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      (*field)[i][j] = white;
    }
  }
}

void free_field(char ***field) {
  for (int i = 0; i < N; ++i) {
    free((*field)[i]);
  }
  free(*field);
}

void print_field(char **field) {
  clear();
  for (int i = -1; i < N + 1; i++) {
    for (int j = -1; j < M + 1; j++) {
      if (i == -1 || i == N) {
        printw("=");
      } else {
        if ((j == -1) || (j == M)) {
          printw("|");
        } else {
          printw("%c", field[i][j]);
        }
      }
    }
    printw("\n");
  }
}

void input(char ***field, FILE *f) {
  int x = 0, y = 0;
  while (fscanf(f, "%d %d", &x, &y) != EOF) {
    (*field)[x - 1][y - 1] = black;
  }
}

int change_generation(char ***matrix) {
  char **new_matrix;
  create_field(&new_matrix);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int num = count_alive_neighbours(*matrix, i, j);
      if ((*matrix)[i][j] == white && num == 3) {
        new_matrix[i][j] = black;
      }
      if ((*matrix)[i][j] == black && (num == 2 || num == 3)) {
        new_matrix[i][j] = black;
      }
    }
  }

  int is_end = 0;
  if (check_for_end(*matrix, new_matrix)) {
    is_end = 1;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      (*matrix)[i][j] = new_matrix[i][j];
    }
  }

    free_field(&new_matrix);
    return is_end;
}

int count_alive_neighbours(char **matrix, int i, int j) {
  int num = 0;

  for (int n = -1; n <= 1; ++n) {
    for (int m = -1; m <= 1; ++m) {
      if (matrix[(i + n + N) % N][(j + m + M) % M] == black) {
        num++;
      }
    }
  }
  if (matrix[i][j] == black)
    num--;
  return num;
}

int check_for_end(char **matrix, char **new_matrix) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (matrix[i][j] != new_matrix[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

void make_pause(int speed) { usleep((100 / speed) * 10000); }
