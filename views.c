int	check_row_left(int grid[4][4], int row, int expected)
{
	int	col;
	int	max_val;
	int	visible;

	col = 0;
	max_val = 0;
	visible = 0;
	while (col < 4)
	{
		if (grid[row][col] > max_val)
		{
			max_val = grid[row][col];
			visible++;
		}
		col++;
	}
	return (visible == expected);
}

int	check_row_right(int grid[4][4], int row, int expected)
{
	int	col;
	int	max_val;
	int	visible;

	col = 3;
	max_val = 0;
	visible = 0;
	while (col >= 0)
	{
		if (grid[row][col] > max_val)
		{
			max_val = grid[row][col];
			visible++;
		}
		col--;
	}
	return (visible == expected);
}

int	check_col_up(int grid[4][4], int col, int expected)
{
	int	row;
	int	max_val;
	int	visible;

	row = 0;
	max_val = 0;
	visible = 0;
	while (row < 4)
	{
		if (grid[row][col] > max_val)
		{
			max_val = grid[row][col];
			visible++;
		}
		row++;
	}
	return (visible == expected);
}

int	check_col_down(int grid[4][4], int col, int expected)
{
	int	row;
	int	max_val;
	int	visible;

	row = 3;
	max_val = 0;
	visible = 0;
	while (row >= 0)
	{
		if (grid[row][col] > max_val)
		{
			max_val = grid[row][col];
			visible++;
		}
		row--;
	}
	return (visible == expected);
}

// views.c: Görünürlük kurallarının (bina yükseklikleri sayımı) denetimi.