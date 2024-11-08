#include "core/Position.hh"
#include "core/Zobrist.hh"
#include "core/types/Bitboard.hh"
#include "core/types/Color.hh"
#include "core/types/Square.hh"

#include <algorithm>
#include <cctype>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace cvazz;

Position::Position(const std::string &Fen) {
  std::vector<std::string> Tokens;
  {
    std::stringstream Stream(Fen);
    std::copy(std::istream_iterator<std::string>(Stream),
              std::istream_iterator<std::string>(), std::back_inserter(Tokens));
  };

  Square Sq(0);
  for (char c : Tokens[0]) {
    if (isdigit(c))
      Sq += c - '0';

    else {
      const auto addPiece = [&](Color Col) {
        Pieces[Col].set(Sq);
        Hash ^= zobrist::COLOR_KEYS[Col][Sq];
      };

      // clang-format off
      switch (c) {
      case 'x': addPiece(Black); break;
      case 'o': addPiece(White); break;
      case '-':
        Fills.set(Sq);
        Hash ^= zobrist::FILL_KEYS[Sq];
        break;
      }

      Sq += 1;
      // clang-format on
    }
  }

  Stm = Tokens[1][0] == 'x' ? Black : White;
  if (Stm == Black)
    Hash ^= zobrist::STM_KEY;

  Hmc = std::stoi(Tokens[2]);
  Fmc = std::stoi(Tokens[3]);
}

bool cvazz::Position::isGameOver() const {
  return !(~(Pieces[White] | Pieces[Black] | Fills)) ||
         !(Pieces[White] && Pieces[Black]) || Hmc >= 100;
}
