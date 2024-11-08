#include "core/Move.hh"
#include "core/Perft.hh"
#include "core/Position.hh"
#include <cassert>
#include <iostream>

using namespace cvazz;

int main() {
  Position Pos("x5o/7/7/7/7/7/o5x x 0 1");


  assert([](){
    Position a("x5o/7/7/7/7/7/o5x x 0 1");
    Position b(a);
    std::cout << a.Hash << std::endl;
    makeMove(b, {0, 2});
    std::cout << b.Hash << std::endl;
    makeMove(b, {6, 22});
    std::cout << b.Hash << std::endl;
    makeMove(b, {2, 0});
    std::cout << b.Hash << std::endl;
    makeMove(b, {22, 6});
    std::cout << b.Hash << std::endl;
    std::cout << b.Hash << std::endl;
    std::cout << a.Pieces[0] << std::endl;
    std::cout << a.Pieces[1] << std::endl;
    std::cout << b.Pieces[0] << std::endl;
    std::cout << b.Pieces[1] << std::endl;
    return b == a;
  }());

  std::cout << "Perft\n\n";
  for (int i = 1; i <= 6; ++i)
    std::cout << "Depth " << i << ": " << perft(Pos, i) << std::endl;
}
