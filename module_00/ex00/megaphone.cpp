#include <ctype.h>
#include <iostream>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			putchar(toupper(argv[i][j]));
            j++;
		}
		i++;
	}
	std::cout << "\n";
	return (0);
}
