#ifndef OUTVAULT_H
#define OUTVAULT_H

class outvault : public vault
{
public :
	void printall();
	void printpwd(char *av);
	void decode(std::string pwd);
};

#endif
