#include "pwd.h"

class Create
{
public :
	static void store(std::string service, std::string psswd)
	{
		std::string str;
		std::ofstream outfile;

		str.append(service);
		str.append("=");
		str.append(psswd);
		outfile.open(DEST, std::ios_base::app);
		outfile << str << std::endl;
	}
};

class Generate
{
public :
	static std::string pwd(int len)
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
};

int	main(int argc, char **argv)
{
	std::string psswd;
	//add
	// generate
	if (argc >= 2 && strcmp(argv[1], "generate") == 0)
	{
		psswd = Generate::pwd(16);
		if (argc == 2)
			std::cout << psswd << std::endl;
		if (argc == 3)
			Create::store(argv[2], psswd);
	}
	return (0);
}
