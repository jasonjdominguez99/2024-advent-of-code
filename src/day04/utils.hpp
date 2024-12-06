#pragma once

#include <array>
#include <string>
#include <string_view>
#include <vector>

namespace Utils
{
    struct Position
    {
        size_t row;
        size_t col;
    };

    enum class Direction
    {
        Up,
        Down,
        Left,
        Right,
        UpLeft,
        UpRight,
        DownLeft,
        DownRight
    };

    constexpr std::array<Direction, 8> Directions = {
        Direction::Up,
        Direction::Down,
        Direction::Left,
        Direction::Right,
        Direction::UpLeft,
        Direction::UpRight,
        Direction::DownLeft,
        Direction::DownRight
    };

    constexpr std::pair<int, int> getIncrement(const Direction direction)
    {
        switch (direction)
        {
        case Direction::Up:
            return std::make_pair(-1, 0);
        case Direction::Down:
            return std::make_pair(1, 0);
        case Direction::Left:
            return std::make_pair(0, -1);
        case Direction::Right:
            return std::make_pair(0, 1);
        case Direction::UpLeft:
            return std::make_pair(-1, -1);
        case Direction::UpRight:
            return std::make_pair(-1, 1);
        case Direction::DownLeft:
            return std::make_pair(1, -1);
        case Direction::DownRight:
            return std::make_pair(1, 1);
        default:
            return std::make_pair(0, 0);
        }
    }

    inline bool findWord(const std::vector<std::string>& input, const Utils::Position startPosition, const Utils::Direction direction, const std::string_view& word)
    {
        const size_t startRow = startPosition.row;
        const size_t startCol = startPosition.col;

        const auto [rowIncrement, colIncrement] = getIncrement(direction);

        if (startRow - (word.size() - 1) * rowIncrement < 0)
        {
            return false;
        }

        if (startCol - (word.size() - 1) * colIncrement < 0)
        {
            return false;
        }

        if (startRow + (word.size() - 1) * rowIncrement >= input.size())
        {
            return false;
        }

        if (startCol + (word.size() - 1) * colIncrement >= input[startRow].size())
        {
            return false;
        }

        for (size_t i = 0; i < word.size(); ++i)
        {
            if (input[startRow + i * rowIncrement][startCol + i * colIncrement] != word[i])
            {
                return false;
            }
        }

        return true;
    }
}
