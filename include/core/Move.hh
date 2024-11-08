#pragma once

#include "core/Position.hh"
#include "core/types/Square.hh"

#include <array>
#include <cstddef>
#include <string>

namespace cvazz {

struct Move {
  Square From; // Assign Square::None for one-step move
  Square To;

  bool isHop() const { return From != Square::None; }
  bool isNull() const { return From == To; }
  std::string toStr() const;
};

constexpr Move NULL_MOVE { Square::None, Square::None };

class MoveList {
  std::array<Move, 256> Data;
  std::size_t Length = 0;

public:
  explicit MoveList(const MoveList &) = default;
  MoveList(MoveList &&) = default;
  MoveList &operator=(const MoveList &) = default;
  MoveList &operator=(MoveList &&) = default;
  MoveList() = default;

  Move &operator[](std::size_t Idx) { return Data[Idx]; }

  Move *begin() { return Data.begin(); }
  Move *end() { return Data.begin() + Length; }

  int size() const { return Length; }

  void push_back(Move Item) { Data[Length++] = Item; }
  void pop_back() { --Length; }
  void clear() { Length = 0; }

  Move takeLast() { return Data[--Length]; };
};

void genCloneMoves(MoveList &, const Position &);
void genHopMoves(MoveList &, const Position &);
void genAllMoves(MoveList &, const Position &);
void makeMove(Position &, const Move);

} // namespace cvazz
