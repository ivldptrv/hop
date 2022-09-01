#pragma once 

#include <array>

#include "../inc/Place.hpp"

namespace ru::hop {
struct TableBase {};

template<std::size_t Capacity = 9>
struct Table final : TableBase
{
    constexpr static kCapacity = Capacity;
    std::array<std::unique_ptr<Place>, kCapacity> places_;
};
};