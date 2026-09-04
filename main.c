#include <unistd.h>

int		solve(int grid[4][4], int *entry, int pos);
void	print_grid(int grid[4][4]);

void	ft_puterror(void)
{
	write(1, "Error\n", 6);
}

int	parse_args(char *str, int *entry)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (count >= 16)
				return (0);
			entry[count] = str[i] - '0';
			count++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (count == 16);
}

int	main(int argc, char **argv)
{
	int	entry[16];
	int	grid[4][4];
	int	i;
	int	j;

	if (argc != 2 || !parse_args(argv[1], entry))
	{
		ft_puterror();
		return (1);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			grid[i][j++] = 0;
		i++;
	}
	if (solve(grid, entry, 0))
		print_grid(grid);
	else
		ft_puterror();
	return (0);
}