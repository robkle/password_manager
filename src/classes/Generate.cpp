#include "pwd.h"

std::string generate::pwd(int len)
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
	return (psswd);
}
