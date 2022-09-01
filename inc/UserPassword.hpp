#pragma once

#include <string.h>

namespace ru::hop {
struct UserPassword final {
  constexpr static std::size_t kMax = 16;
  constexpr static std::size_t kMin = 8;

  explicit UserPassword(std::wstring_view value) : value_{value} { Validate(); }

private:
  void Validate() {
    auto size = value_.size();

    if (size < kMin || size > kMax) {
      throw std::runtime_error{"Invalid length"};
    }
  }
  UserPassword &operator=(UserPassword &&) = default;
  
  ~UserPassword() {
    auto clear = std::wstring{L"x", value_.size()};
    value_ = clear;
    if (value_ == clear) {
      value_ = L"";
    } else {
      value_ = L"?";
    }

    value_ = value_ == clear ? clear : L"";
  }

private:
  std::wstring value_;
};
} // namespace ru::hop