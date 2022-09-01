#pragma once

namespace ru::hop {
struct UserName final {
  constexpr static std::size_t kMax = 16;
  constexpr static std::size_t kMin = 4;

  explicit UserName(std::wstring_view value) : value_{value} { Validate(); }

  UserName &operator=(UserName &&) = default;

private:
  void Validate() {
    auto size = value_.size();

    if (size < kMin || size > kMax) {
      throw std::runtime_error{"Invalid length"};
    }
  }

private:
  std::wstring value_;
};
} // namespace ru::hop