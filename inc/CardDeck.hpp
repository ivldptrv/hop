#pragma once

#include <cinttypes>
#include <stdexcept>

namespace ru::hop {
struct CardDeck final {
  using ValueType = std::uint64_t;
  using Card = int;
  constexpr static ValueType kDefaultValue = 0xFFFFFFFFFFFFF;

  explicit constexpr CardDeck(ValueType value = kDefaultValue) noexcept
      : value_{value} {}

  ValueType pull() {
    if (!value_) {
      throw std::runtime_error("ru::hop::CardDeck: Deck empty");
    }

    auto size = __builtin_popcountll(value_);
    auto tmp = value_;
    auto n = rand() % size;

    while (--n) {
      tmp &= tmp - 1;
    }

    auto ctz = __builtin_ctzll(tmp);
    value_ &= ~static_cast<ValueType>(1) << ctz;

    return ctz;
  }

  void push(Card card) {
    if (has(card)) {
      throw std::runtime_error("ru::hop::CardDeck: Card already exists!");
    }

    value_ |= ~static_cast<ValueType>(1) << card;
  }

  bool has(Card card) const noexcept {
    return value_ & (~static_cast<ValueType>(1) << card);
  }

private:
  ValueType value_;
};

bool Deal(CardDeck &deck, Place &place, std::size_t count) noexcept {
  if (deck.Count() < count) {
    return false;
  }

  while (count--) {
    place.TakeCard(deck);
  }

  return true;
}

} // namespace ru::hop