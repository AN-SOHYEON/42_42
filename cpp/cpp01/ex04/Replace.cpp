#include "Replace.hpp"

int	inputFile(std::string& content, const char* filename) 
{
	std::ifstream	in(filename);
	std::string		line;

	if (!in.is_open()) 
	{
		std::cerr << "faile to open file" << std::endl;
		return (1);
	}
	while (std::getline(in, line))
	{
		content = content + line;
		content.push_back('\n');
	}
	return (0);
}

int	outputFile(const std::string& content, const char* filename)
{
	std::string		filename_re;
	filename_re = std::string(filename) + ".replace";

	std::ofstream	out(filename_re.c_str());
	if (!out.is_open())
	{
		std::cerr << "faile to open new file." << std::endl;
		return (1);
	}
	out << content;
	return (0);
}

int replace(const char* filename, const char* search, const char* replace)
{
	std::string content;
	std::size_t i;

	if (!inputFile(content, filename))
		return false;
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
		return false;
	return true;
}