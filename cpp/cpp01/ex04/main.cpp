

#include <iostream>
#include "Replace.hpp"

int main(int ac, char **av) 
{
  if (ac != 4 || av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0') 
  {
    std::cout << "USAGE: ./sed [filename] [search] [replace]" << std::endl;
    return (1);
  }
  replace(av[1], av[2], av[3]);
  return (0);
}