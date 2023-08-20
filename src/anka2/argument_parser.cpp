#include <format>

#include <argumentum/argparse.h>

#include "argument_parser.h"

auto anka::parse(int argc, char *argv[]) -> std::optional<Arguments>
{
  using namespace argumentum;

  Arguments args;

  auto desc = "anka 2";

  auto parser = argument_parser{};
  auto params = parser.params();
  parser.config().program(argv[0]).description(desc);
  parser.add_default_help_option();
  params.add_parameter(args.print_lex_output, "--lex-output", "-l").nargs(0).help("Print lexer output.");
  params.add_parameter(args.output_comparison_file, "--compare-output-with-file", "-c").nargs(1).help("Compare the output of Anka with the contents of the given file.");
  params.add_parameter(args.filename, "--filename", "-f").nargs(1).help("File name to process.");

  if (!parser.parse_args(argc, argv))
  {
    return std::nullopt;
  }

  return args;
}
