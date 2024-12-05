#pragma once

#include <optional>
#include <string>
#include <vector>

namespace InputReader
{
    std::vector<std::string> readLines(const std::string& day, bool test = false);
    std::string              readFile(const std::string& day, bool test = false, std::optional<int> part = std::nullopt);
}
