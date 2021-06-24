#ifndef INVAULT_H
#define VAULT_H

class invault : public vault
{
public :
	void insert(std::string var, std::string val);
	void remove(std::string var);
	void erase(std::string var);
	std::string encode(std::string val);
	void write();
};

#endif
