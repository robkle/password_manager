#include "pwd.h"
#include <filesystem>

class vault
{
public :
	std::vector<std::string>	pswd;
	
	vault()
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
};

class invault : public vault
{
public :
	void insert(std::string var, std::string val)
	{
		int				i;
		std::string		str;
		std::ofstream	outfile;

		str.append(var);
		str.append("=");
		str.append(val);
		i = -1;
		while (++i < this->pswd.size())
		{
			if (str.compare(this->pswd.at(i)) <= 0)
			{
				this->pswd.insert(this->pswd.begin() + i, str);
				break;
			}
		}
		if (i == this->pswd.size() || this->pswd.empty())
			this->pswd.push_back(str);
		outfile.open(DEST, std::ios_base::trunc);
		i = -1;
		while (++i < this->pswd.size())
		{
			outfile << this->pswd.at(i) << std::endl;
		}
	}
};

class outvault : public vault
{
public :
	void printall()
	{
		int i;
	
		i = -1;
		while (++i < this->pswd.size())
		{
			std::cout << this->pswd.at(i) << std::endl;
		}
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

/*
** currently main is used to test existing classes
*/
int	main(int argc, char **argv)
{
	
	if (argc == 1)
	{
		outvault	pwd;
		pwd.printall();
	}
	else if (argc >= 2)
	{
		if (strcmp(argv[1], "insert") == 0)
		{
			invault		store;
			store.insert(argv[2], argv[3]);
		}
	}
	return (0);
}
