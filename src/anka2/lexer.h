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
  IntegerNumber
};

struct LexAtom
{
  LexType type;
  int relativePosition;
};

[[nodiscard]] auto lex(std::string_view text) -> std::optional<std::vector<LexAtom>>;

} // namespace anka
