#include "pwd.h"

int	main(int argc, char **argv)
{
	int	mode;
	
	if (parser::parse(mode, argc, argv) == EXIT_SUCCESS)
	{
		if (mode == NONE)
			std::cout << generate::pwd(16) << std::endl;
		else if (mode % 4)
		{
			outvault pwd;
			if (mode == DISA)
				pwd.printall();
			else if (mode == DISP)
				pwd.printpwd(argv[1]);
		}
		else
		{
			invault	store;
			if (mode == SETD)
				store.insert(argv[2], argv[3]);
			else if (mode == SETR)
				store.insert(argv[2], generate::pwd(16));
			else if (mode == DELT)
				store.remove(argv[2]);
		}
	}
	return (0);
}
