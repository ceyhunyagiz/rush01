int	check_col_up(int grid[4][4], int col, int expected);
int	check_col_down(int grid[4][4], int col, int expected);
int	check_row_left(int grid[4][4], int row, int expected);
int	check_row_right(int grid[4][4], int row, int expected);

int	is_duplicate(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_case(int grid[4][4], int pos, int *entry)
{
	int	row;
	int	col;

	row = pos / 4;
	col = pos % 4;
	if (row == 3)
	{
		if (!check_col_up(grid, col, entry[col]))
			return (0);
		if (!check_col_down(grid, col, entry[4 + col]))
			return (0);
	}
	if (col == 3)
	{
		if (!check_row_left(grid, row, entry[8 + row]))
			return (0);
		if (!check_row_right(grid, row, entry[12 + row]))
			return (0);
	}
	return (1);
}