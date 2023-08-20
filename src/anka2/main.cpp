#include <iostream>
#include <string>
#include <vector>

#include <loguru.hpp>

#include "argument_parser.h"
#include "log.h"

int main(int argc, char *argv[])
{
  auto arguments_opt = anka::parse(argc, argv);
  if (!arguments_opt)
    return -1;

  auto arguments = arguments_opt.value();
  anka::init_logging(arguments.output_comparison_file.has_value());

  LOG_F(INFO, "Anka 2 is starting...");

  // execute here.

  if (arguments.output_comparison_file.has_value())
  {
    return anka::compare_output(arguments.output_comparison_file.value()) ? 0 : -1;
  }

  return 0;
}
