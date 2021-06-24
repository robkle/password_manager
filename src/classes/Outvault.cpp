#include "pwd.h"

void outvault::printall()
{
	int i;

	i = -1;
	while (++i < this->pswd.size())
	{
		std::cout << this->pswd.at(i) << std::endl;
	}
}

void outvault::printpwd(char *av)
{
	int i;
	int	len;
	std::string	str;
	std::string tmp;

	str = av;
	len = str.size();
	i = -1;
	while (++i < this->pswd.size())
	{
		tmp = this->pswd.at(i);
		if (!str.compare(0, len - 1, tmp, 0, len - 1) && tmp.at(len) == '=') 
			this->decode(tmp.substr(len + 1));
	}
}

void outvault::decode(std::string pwd)
{
	/*Decoding algorithm here*/
	std::cout << pwd << std::endl;
}
