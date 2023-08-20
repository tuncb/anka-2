#include <iostream>

#include "argument_parser.h"

int main(int argc, char *argv[])
{
  std:: cout << "anka 2.\n";

  auto arguments = anka::parse(argc, argv);
  return 0;  
}
