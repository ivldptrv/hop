#pragma once

#include "../inc/Place.hpp"

namespace ru::hop {
struct User {
  using Id = std::uint64_t;

private:
  Id id_;
  std::vector<Table> tables_;
};
} // namespace ru::hop_