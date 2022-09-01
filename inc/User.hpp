#pragma once

#include <vector>

#include "../inc/Table.hpp"
#include "../inc/UserName.hpp"
#include "../inc/UserPassword.hpp"

namespace ru::hop {
struct User {
  using Id = std::uint64_t;

  explicit User(UserName name, UserPassword pass) : name_{std::move(name)}, id_{MakeId()} {}

private:
  Id MakeId() { return 0; }

private:
  Id id_;
  UserName name_;
  std::vector<TableBase> tables_;
};
} // namespace ru::hop