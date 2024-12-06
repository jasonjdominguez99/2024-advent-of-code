#include "inputreader.hpp"
#include "part1.hpp"

#include <iostream>

int main()
{
    std::cout << "Advent of Code 2024 - Day 04" << std::endl;
    std::cout << "---------TEST INPUT---------" << std::endl;

    const bool               isTest = true;
    std::vector<std::string> testInput = InputReader::readLines("day04", isTest);

    std::cout << "Part 1: " << day04::part1::solve(testInput) << std::endl;

    std::cout << "---------REAL INPUT---------" << std::endl;

    std::vector<std::string> input = InputReader::readLines("day04");

    std::cout << "Part 1: " << day04::part1::solve(input) << std::endl;

    return 0;
}
