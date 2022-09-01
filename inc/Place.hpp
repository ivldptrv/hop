#pragma once

#include "../inc/CardDeck.hpp"

namespace ru::hop {
using Bet = std::uint64_t;

struct Place {
  using Hand = CardDeck;

  Place() noexcept : hand_{0} {}

  void MakeBet(Bet size) noexcept {
    stack_ -= size;
    bet += size;
  }
  
  void SetStack(Bet size) noexcept { stack_ = size; }

private:
  Hand hand_;
  Bet stack_;
  Bet bet_;
  uint32_t empty : 1;
  uint32_t fold : 1;
};
} // namespace ru::hop