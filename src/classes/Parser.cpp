#include "pwd.h"

int parser::parse(int& mode, int ac, char **av)
{
	if (ac > 4)
	{
		std::cerr << "Input error: Too many arguments." << std::endl;
		return (EXIT_FAILURE);
	}
	else if (ac == 1)
		mode = DISA;
	else if (!strcmp(av[1], "create"))
	{
		if (ac == 2)
			mode = NONE;
		else if (ac == 3)
			mode = SETR;
		else if (ac == 4)
			mode = SETD;
	}
	else if (!strcmp(av[1], "remove"))
	{
		if (ac == 3)
			mode = DELT;
		else if (ac < 3)
		{
			std::cerr << "Input error: Too few arguments.\nUsage: ./pwd remove <var to delete>" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (ac > 3)
		{
			std::cerr << "Input error: Too many arguments.\nUsage: ./pwd remove <var to delete>" << std::endl;
			return (EXIT_FAILURE);
		}
	}
	else if (ac == 2)
		mode = DISP;
	else if (ac > 2)
	{
		std::cerr << "Input error: Invalid option: " << av[1] << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
