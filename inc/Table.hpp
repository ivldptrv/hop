#pragma once

#include <array>
#include <memory>

#include "../inc/Place.hpp"

namespace ru::hop {
struct TableBase {
  virtual bool Sit() = 0;
  virtual ~TableBase() = default;
};

template <std::size_t Capacity = 9> struct Table final : TableBase {
  constexpr static std::size_t kCapacity = Capacity;

    virtual bool Sit(const Place)
    {
        if(places_.size() >= kCapacity) {
            return false;
        }

        // TODO:
    }
private:
  std::vector<std::unique_ptr<Place>> places_;
};
}; // namespace ru::hop