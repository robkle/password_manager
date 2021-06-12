#include <iostream>
#include <string>
#include "pwd.h"

class Generate
{
public :
	static void pwd(int len)
	{
		std::string chars;
		std::string psswd;
		int	n;

		chars.append(UPPERCASE);
		chars.append(LOWERCASE);
		chars.append(DIGITS);
		chars.append(SPECIAL);
		n = chars.length();
		srand(time(0));
		while (--len >= 0)
			psswd += chars[std::rand() % n];
		std::cout << psswd << std::endl;
	}	
};

int	main(int argc, char **argv)
{
	Generate::pwd(16);
	return (0);
}
