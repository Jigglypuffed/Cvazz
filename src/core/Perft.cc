#include "core/Perft.hh"

#include "core/Move.hh"
#include "core/Position.hh"

#include <cstdint>
#include <iostream>

using namespace cvazz;

std::uint64_t cvazz::perft(const Position &Pos, int Depth) {
  if (Pos.isGameOver())
    return 0;

  MoveList Ml;
  genAllMoves(Ml, Pos);

  if (Depth == 1)
    return Ml.size();

  if (Depth <= 0)
    return 1;

  std::uint64_t NodeCount = 0;
  for (auto Mv : Ml) {
    auto NewPos = Position(Pos);
    makeMove(NewPos, Mv);
    NodeCount += perft(NewPos, Depth - 1);
  }

  return NodeCount;
}

std::uint64_t cvazz::splitperft(const Position &Pos, int Depth) {
  MoveList Ml;
  genAllMoves(Ml, Pos);

  for (auto Mv : Ml) {
    auto NewPos = Position(Pos);
    makeMove(NewPos, Mv);
    std::uint64_t NodeCount = perft(NewPos, Depth - 1);
    std::cout << Mv.toStr() << " " << NodeCount << std::endl;
    ;
  }

  return 0;
}
