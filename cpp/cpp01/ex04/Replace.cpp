#include "Replace.hpp"

int	readFile(std::string& file_contents, const char* filename) 
{
	std::ifstream	rdfile(filename);
	std::string		line;

	if (!rdfile.is_open()) 
	{
		std::cerr << "failed to open source file." << std::endl;
		return (1);
	}
  while (std::getline(rdfile, line)) {
    file_contents += line;
    file_contents.push_back('\n');
  }
  return true;
}

bool output_file(const std::string& file_contents, const char* filepath) {
  std::string output_path;
  output_path = std::string(filepath) + ".replace";
  std::ofstream ofs(output_path.c_str());
  if (!ofs.is_open()) {
    std::cerr << "failed to open output file." << std::endl;
    return false;
  }
  ofs << file_contents;
  return true;
}

bool replace(const char* filepath, const char* search, const char* replace) {
  std::string file_contents;
  std::size_t i;

  if (!readFile(file_contents, filepath))
    return false;
  i = 0;
  while (1) {
    i = file_contents.find(search, i);
    if (i == std::string::npos)
      break;
    file_contents.erase(i, strlen(search));
    file_contents.insert(i, replace);
    i += strlen(replace);
  }
  if (!output_file(file_contents, filepath))
    return false;
  return true;
}