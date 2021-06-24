#include "pwd.h"

vault::vault()
{
	std::string line;
	std::ifstream myfile;

	myfile.open(DEST);
	if (!myfile.is_open())
	{
		perror("Error open");
		exit (EXIT_FAILURE);
	}
	while(std::getline(myfile, line))
	{
		this->pswd.push_back(line);
	}
}
