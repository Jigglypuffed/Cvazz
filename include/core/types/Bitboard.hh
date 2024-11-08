#pragma once

#include "core/types/Square.hh"

#include <cstdint>

namespace cvazz {

class Bitboard {
  std::uint64_t Data = 0;

public:
  constexpr Bitboard() = default;
  explicit constexpr Bitboard(std::uint64_t Data) : Data(Data) {}
  explicit constexpr Bitboard(Square Sq) : Data(1ULL << Sq) {}

  Bitboard operator~() const { return Bitboard(~Data); }
  Bitboard operator&(Bitboard Rhs) const { return Bitboard(Data & Rhs); }
  Bitboard operator|(Bitboard Rhs) const { return Bitboard(Data | Rhs); }
  Bitboard operator^(Bitboard Rhs) const { return Bitboard(Data ^ Rhs); }
  Bitboard operator<<(int Rhs) const { return Bitboard(Data << Rhs); }
  Bitboard operator>>(int Rhs) const { return Bitboard(Data >> Rhs); }

  void operator&=(Bitboard Rhs) { Data &= Rhs; }
  void operator|=(Bitboard Rhs) { Data |= Rhs; }
  void operator^=(Bitboard Rhs) { Data ^= Rhs; }
  void operator<<=(int Rhs) { Data <<= Rhs; }
  void operator>>=(int Rhs) { Data >>= Rhs; }

  operator std::uint64_t() const { return Data; }

  void set(Square Sq) { Data |= 1ULL << Sq; }
  void unset(Square Sq) { Data &= ~(1ULL << Sq); }

  int lsb() { return __builtin_ctzll(Data); }
  int takeLsb() {
    int Lsb = lsb();
    Data &= Data - 1;
    return Lsb;
  }
};

constexpr Bitboard FILE_A = Bitboard(0x1010101010101ULL);
constexpr Bitboard FILE_B = Bitboard(0x2020202020202ULL);
constexpr Bitboard FILE_C = Bitboard(0x4040404040404ULL);
constexpr Bitboard FILE_D = Bitboard(0x8080808080808ULL);
constexpr Bitboard FILE_E = Bitboard(0x10101010101010ULL);
constexpr Bitboard FILE_F = Bitboard(0x20202020202020ULL);
constexpr Bitboard FILE_G = Bitboard(0x40404040404040ULL);

constexpr Bitboard RANK_1 = Bitboard(0x7f000000000000ULL);
constexpr Bitboard RANK_2 = Bitboard(0x7f0000000000ULL);
constexpr Bitboard RANK_3 = Bitboard(0x7f00000000ULL);
constexpr Bitboard RANK_4 = Bitboard(0x7f000000ULL);
constexpr Bitboard RANK_5 = Bitboard(0x7f0000ULL);
constexpr Bitboard RANK_6 = Bitboard(0x7f00ULL);
constexpr Bitboard RANK_7 = Bitboard(0x7fULL);

constexpr Bitboard OUT_OF_BOUND = Bitboard(0xff80808080808080ULL);

} // namespace cvazz
