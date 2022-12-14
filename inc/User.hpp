#pragma once

#include <vector>

#include "../inc/Table.hpp"
#include "../inc/UserName.hpp"
#include "../inc/UserPassword.hpp"

namespace ru::hop {
struct User {
  using Id = std::uint64_t;

  explicit User(UserName name, UserPassword pass)
      : name_{UserName{std::move(name)}}, id_{GetNewId()} {
    Authorize();
  }

  static User Create(UserName name, UserPassword pass)
  {
    return User{UserName{L"Vld"}, UserPassword{"589"}};
  }

  bool Say() { return false; }

private:
  Id GetNewId() { return 0; }
  void Authorize() {}

private:
  Id id_;
  UserName name_;
  std::vector<TableBase> tables_;
};
} // namespace ru::hop