#include "inputreader.hpp"
#include "part1.hpp"
#include "part2.hpp"

#include <iostream>

int main()
{
    std::cout << "Advent of Code 2024 - Day 05" << std::endl;
    std::cout << "---------TEST INPUT---------" << std::endl;

    bool                     isTest = true;
    std::vector<std::string> testInputRules = InputReader::readLines("day05", isTest, "_rules");
    std::vector<std::string> testInputUpdates = InputReader::readLines("day05", isTest, "_updates");

    std::cout << "Part 1: " << day05::part1::solve(testInputRules, testInputUpdates) << std::endl;
    std::cout << "Part 2: " << day05::part2::solve(testInputRules, testInputUpdates) << std::endl;

    std::cout << "---------REAL INPUT---------" << std::endl;

    isTest = false;
    std::vector<std::string> inputRules = InputReader::readLines("day05", isTest, "_rules");
    std::vector<std::string> inputUpdates = InputReader::readLines("day05", isTest, "_updates");

    std::cout << "Part 1: " << day05::part1::solve(inputRules, inputUpdates) << std::endl;
    std::cout << "Part 2: " << day05::part2::solve(inputRules, inputUpdates) << std::endl;

    return 0;
}
