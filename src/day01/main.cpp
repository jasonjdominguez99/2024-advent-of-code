#include "inputreader.hpp"
#include "part1.hpp"
#include "part2.hpp"
#include "utils.hpp"

#include <iostream>

int main()
{
    std::cout << "Advent of Code 2024 - Day 01" << std::endl;
    std::cout << "---------TEST INPUT---------" << std::endl;

    const bool               isTest = true;
    std::vector<std::string> testInput = InputReader::readLines("day01", isTest);
    const auto [testLeftList, testRightList] = Utils::getSortedListsFromInput(testInput, 1);

    std::cout << "Part 1: " << day01::part1::solve(testLeftList, testRightList) << std::endl;
    std::cout << "Part 2: " << day01::part2::solve(testLeftList, testRightList) << std::endl;

    std::cout << "---------REAL INPUT---------" << std::endl;

    std::vector<std::string> input = InputReader::readLines("day01");
    const auto [leftList, rightList] = Utils::getSortedListsFromInput(input, 5);

    std::cout << "Part 1: " << day01::part1::solve(leftList, rightList) << std::endl;
    std::cout << "Part 2: " << day01::part2::solve(leftList, rightList) << std::endl;

    return 0;
}
