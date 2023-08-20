#pragma once
#include <loguru.hpp>

namespace anka
{

auto init_logging(bool store_messages) -> void;
[[nodiscard]] auto compare_output(const std::string &filename) -> bool;

} // namespace anka