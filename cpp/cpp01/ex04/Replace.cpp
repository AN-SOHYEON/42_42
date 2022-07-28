#include "Replace.hpp"

int	inputFile(std::string& content, const char* filename) 
{
	std::ifstream	in(filename, std::ifstream::in);
	std::string		line;

	if (!in.is_open()) 
	{
		std::cout << "fail to open file" << std::endl;
		return (0);
	}
	while (!in.eof())
	{
		std::getline(in, line);
		content = content + line;
		content.push_back('\n');
	}
	in.close();
	return (1);
}

int	outputFile(const std::string& content, const char* filename)
{
	std::string		filename_re;
	filename_re = std::string(filename) + ".replace";

	std::ofstream	out(filename_re.c_str(), std::ofstream::out);
	if (!out.is_open())
	{
		std::cout << "fail to open replace file." << std::endl;
		return (0);
	}
	out << content;
	out.close();
	return (1);
}

int replace(const char* filename, const char* search, const char* replace)
{
	std::string	content;
	std::size_t	i;

	if (!inputFile(content, filename))
		return (0);
	i = 0;
	while (1)
	{
		i = content.find(search, i);
		if (i == std::string::npos)
			break;
		content.erase(i, strlen(search));
		content.insert(i, replace);
		i  = i + strlen(replace);
	}
	if (!outputFile(content, filename))
		return (0);
	return (1);
}