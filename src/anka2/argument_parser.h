#pragma once
#include <optional>
#include <string>

namespace anka
{

struct Arguments
{
  std::optional<std::string> output_comparison_file = std::nullopt;
  std::optional<std::string> filename = std::nullopt;
  bool print_lex_output = false;
};

[[nodiscard]] auto parse(int argc, char *argv[]) -> std::optional<Arguments>;

} // namespace anka