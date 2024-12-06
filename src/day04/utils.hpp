#pragma once

#include <array>

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
}
