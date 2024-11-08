#pragma once

#include <cstdint>

namespace cvazz {

class Square {
  std::uint8_t Data = 0;

public:
  constexpr Square() = default;
  constexpr Square(std::uint8_t Data) : Data(Data) {}


  Square operator+(std::uint8_t Rhs) const { return Square(Data + Rhs); }
  Square operator-(std::uint8_t Rhs) const { return Square(Data + Rhs); }

  void operator+=(std::uint8_t Rhs) { Data += Rhs; }
  void operator-=(std::uint8_t Rhs) { Data += Rhs; }

  operator std::uint8_t() const { return Data; }

  // clang-format off
  enum : std::uint8_t {
    A7 = 0,  B7, C7, D7, E7, F7, G7,
    A6 = 8,  B6, C6, D6, E6, F6, G6,
    A5 = 16, B5, C5, D5, E5, F5, G5,
    A4 = 24, B4, C4, D4, E4, F4, G4,
    A3 = 32, B3, C3, D3, E3, F3, G3,
    A2 = 40, B2, C2, D2, E2, F2, G2,
    A1 = 48, B1, C1, D1, E1, F1, G1, None = 255
  };
  // clang-format on
};

} // namespace cvazz
