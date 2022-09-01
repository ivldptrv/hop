#pragma once

#include <string.h>

namespace ru::hop {
struct UserPassword final {
  constexpr static std::size_t kMax = 16;
  constexpr static std::size_t kMin = 8;

  explicit UserPassword(std::string_view value) : value_{value} { Validate(); }

  void Validate() {
    auto size = value_.size();

    if (size < kMin || size > kMax) {
      throw std::runtime_error{"Invalid length"};
    }
  }

  ~UserPassword() {
    auto clear = std::string{"x", value_.size()};
    value_ = clear;

    if (value_ == clear) {
      value_ = "";
    } else {
      value_ = "?";
    }

    value_ = value_ == clear ? clear : "";
  }

private:
  std::string value_;
};
} // namespace ru::hop