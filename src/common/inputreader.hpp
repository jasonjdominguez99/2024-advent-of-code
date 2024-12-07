#pragma once

#include <optional>
#include <string>
#include <vector>

namespace InputReader
{
    std::vector<std::string> readLines(const std::string& day, bool test = false, const std::optional<std::string>& part = std::nullopt);
    std::string              readFile(const std::string& day, bool test = false, const std::optional<std::string>& part = std::nullopt);
}
