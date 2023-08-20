#pragma once

#include <vector>
#include <string_view>
#include <optional>

namespace anka
{

enum class LexType
{
  DeadSpace,
  UserDefinedString,
  DoubleColon,
  Equal,
  IntegerNumber,
  SemiColon,
  EndOfFile,
};

struct LexAtom
{
  LexType type;
  int relative_position;
};

[[nodiscard]] auto lex(std::string_view text) -> std::optional<std::vector<LexAtom>>;
[[nodiscard]] auto print_atoms(const std::vector<LexAtom>& atoms);

} // namespace anka
