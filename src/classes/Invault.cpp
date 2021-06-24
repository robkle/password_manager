#include "pwd.h"

void invault::insert(std::string var, std::string val)
{
	int				i;
	std::string		str;

	str.append(var);
	str.append("=");
	str.append(this->encode(val));
	this->erase(var);
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
	this->write();
}

void invault::remove(std::string var)
{
	this->erase(var);
	this->write();
}
	
void invault::erase(std::string var)
{
	int			i;
	int			len;
	std::string tmp;

	len = var.size();
	i = -1;
	while (++i < this->pswd.size())
	{
		tmp = this->pswd.at(i);
		if (!var.compare(0, len - 1, tmp, 0, len - 1) && tmp.at(len) == '=')
		{
			this->pswd.erase(this->pswd.begin() + i);
			break;
		}
	}
}
	
std::string invault::encode(std::string val)
{
	/*Encoding algorithm here*/
	return (val);
}

void invault::write()
{
	int				i;
	std::ofstream	outfile;

	outfile.open(DEST, std::ios_base::trunc);
	i = -1;
	while (++i < this->pswd.size())
	{
		outfile << this->pswd.at(i) << std::endl;
	}
}
