#include <unistd.h>

int		is_duplicate(int grid[4][4], int row, int col, int num);
int		check_case(int grid[4][4], int pos, int *entry);

void	print_grid(int grid[4][4])
{
	int		r;
	int		c;
	char	ch;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			ch = grid[r][c] + '0';
			write(1, &ch, 1);
			if (c < 3)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int	solve(int grid[4][4], int *entry, int pos)
{
	int	num;
	int	row;
	int	col;

	if (pos == 16)
		return (1);
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (!is_duplicate(grid, row, col, num))
		{
			grid[row][col] = num;
			if (check_case(grid, pos, entry))
			{
				if (solve(grid, entry, pos + 1))
					return (1);
			}
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

// solver.c: Rekürsif Backtracking (çözücü motoru).