#pragma once

#include "core/types/Bitboard.hh"
#include "core/types/Color.hh"

#include <array>
#include <cstdint>
#include <string>

namespace cvazz {

struct Position {
  std::array<Bitboard, 2> Pieces;
  Bitboard Fills = OUT_OF_BOUND;
  Color Stm = Black;
  unsigned Hmc = 0;
  unsigned Fmc = 0;
  std::uint64_t Hash = 0;

  explicit Position(const Position &) = default;
  Position &operator=(const Position &) = default;
  Position(Position &&) = default;
  Position &operator=(Position &&) = default;

  Position(const std::string &Fen);

  bool operator==(const Position &Rhs) const { return Hash == Rhs.Hash; }
  Color xstm() const { return static_cast<Color>(!Stm); }
  bool isGameOver() const;
};

} // namespace cvazz
