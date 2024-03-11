#include "plato.h"

/**
 * draw_board - draw the canvas of the animation
 * @board: xy grid
 * Return: void
 */
void draw_board(char board[HEIGHT][WIDTH])
{
	int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			printf("%c", board[y][x]);
		}
		printf("\n");
	}
}

/**
 * initialize_board - initialize board logic
 * @board: xy grid
 * Return: void
 */
void initialize_board(char board[HEIGHT][WIDTH])
{
	int x, y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			if (x < WIDTH / 3)
				board[y][x] = 'E';
			else if (x >= 2 * WIDTH / 3)
				board[y][x] = 'V';
			else
				board[y][x] = ' ';
		}
	}
}

/**
 * move - move all characters in a colum
 * board: xy grid
 * @c: character E or V
 * @f: frontline index
 * @b: backline index
 * @d: direction, 1 means right and -1 means left
 * Return: void
 */
void move(char board[HEIGHT][WIDTH], char c, int f, int b, int d)
{
	int y;

	for (y = 0; y < HEIGHT; y++)
	{
		board[y][b] = ' ';
		board[y][f + d] = c;
	}
}

/**
 * celebrate - celebrate logic
 * Return: 0
 */
int celebrate(void)
{
	printf("HOO HAA!\n");
	return (0);
}

/**
 * main - main function
 *
 * Return: 0 if successful
 */
int main(void)
{
	char board[HEIGHT][WIDTH];
	int eback = 0; /* E's backline */
	int efront = WIDTH / 3 - 1; /* E's frontline */
	int vfront = 2 * WIDTH / 3; /* V's frontline */
	int vback = WIDTH - 1; /* V's backline */


	initialize_board(board);
	srand(time(NULL)); /* seed random number generator */

	while (vfront > 0)
	{
		system("clear"); /* clear screen */
	
		/* E's turn to move */
		if (efront + 1 == vfront && eback > 0)
		{
			if (eback > 0)
				move(board, 'E', efront, eback, -1);
			efront--;
			eback--;
		}
		else if (efront + 1 < vfront)
		{
			move(board, 'E', efront, eback, 1);
			efront++;
			eback++;
		}

		/* V's turn to move */
		if (vfront > 0)
		{
			move(board, 'V', vfront, vback, -1);
			vfront--;
			vback--;
		}

		/* V gobbled up E */
		if (vfront == efront)
			efront--;

		draw_board(board);

		if (vfront <= 0)
			celebrate();

		struct timespec delay;

		delay.tv_sec = 1;
		delay.tv_nsec = 25000;
		nanosleep(&delay, NULL);
	}
	return (celebrate());
}
