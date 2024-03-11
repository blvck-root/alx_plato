#ifndef PLATO_H	
#define PLATO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 10

int celebrate(void);
void draw_board(char board[HEIGHT][WIDTH]);
void initialize_board(char board[HEIGHT][WIDTH]);
void move(char board[HEIGHT][WIDTH], char c, int f, int b, int d);
int main(void);

#endif
