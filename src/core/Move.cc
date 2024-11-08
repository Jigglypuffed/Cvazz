#include "core/Move.hh"
#include "core/Position.hh"
#include "core/Zobrist.hh"
#include "core/types/Bitboard.hh"
#include "core/types/Square.hh"
#include <cstdint>

using namespace cvazz;

// clang-format off
constexpr std::uint64_t FST_NEIGHBORS[] = {
  0x302ULL,            0x705ULL,            0xe0aULL,            0x1c14ULL,
  0x3828ULL,           0x7050ULL,           0x6020ULL,           0x0ULL,
  0x30203ULL,          0x70507ULL,          0xe0a0eULL,          0x1c141cULL,
  0x382838ULL,         0x705070ULL,         0x602060ULL,         0x0ULL,
  0x3020300ULL,        0x7050700ULL,        0xe0a0e00ULL,        0x1c141c00ULL,
  0x38283800ULL,       0x70507000ULL,       0x60206000ULL,       0x0ULL,
  0x302030000ULL,      0x705070000ULL,      0xe0a0e0000ULL,      0x1c141c0000ULL,
  0x3828380000ULL,     0x7050700000ULL,     0x6020600000ULL,     0x0ULL,
  0x30203000000ULL,    0x70507000000ULL,    0xe0a0e000000ULL,    0x1c141c000000ULL,
  0x382838000000ULL,   0x705070000000ULL,   0x602060000000ULL,   0x0ULL,
  0x3020300000000ULL,  0x7050700000000ULL,  0xe0a0e00000000ULL,  0x1c141c00000000ULL,
  0x38283800000000ULL, 0x70507000000000ULL, 0x60206000000000ULL, 0x0ULL,
  0x2030000000000ULL,  0x5070000000000ULL,  0xa0e0000000000ULL,  0x141c0000000000ULL,
  0x28380000000000ULL, 0x50700000000000ULL, 0x20600000000000ULL, 0x0ULL,
  0x0ULL,              0x0ULL,              0x0ULL,              0x0ULL,
  0x0ULL,              0x0ULL,              0x0ULL,              0x0ULL,
};

constexpr std::uint64_t SND_NEIGHBORS[] {
  0x70404ULL,          0xf0808ULL,          0x1f1111ULL,         0x3e2222ULL,
  0x7c4444ULL,         0x780808ULL,         0x701010ULL,         0x0ULL,
  0x7040404ULL,        0xf080808ULL,        0x1f111111ULL,       0x3e222222ULL,
  0x7c444444ULL,       0x78080808ULL,       0x70101010ULL,       0x0ULL,
  0x704040407ULL,      0xf0808080fULL,      0x1f1111111fULL,     0x3e2222223eULL,
  0x7c4444447cULL,     0x7808080878ULL,     0x7010101070ULL,     0x0ULL,
  0x70404040700ULL,    0xf0808080f00ULL,    0x1f1111111f00ULL,   0x3e2222223e00ULL,
  0x7c4444447c00ULL,   0x780808087800ULL,   0x701010107000ULL,   0x0ULL,
  0x7040404070000ULL,  0xf0808080f0000ULL,  0x1f1111111f0000ULL, 0x3e2222223e0000ULL,
  0x7c4444447c0000ULL, 0x78080808780000ULL, 0x70101010700000ULL, 0x0ULL,
  0x4040407000000ULL,  0x808080f000000ULL,  0x1111111f000000ULL, 0x2222223e000000ULL,
  0x4444447c000000ULL, 0x8080878000000ULL,  0x10101070000000ULL, 0x0ULL,
  0x4040700000000ULL,  0x8080f00000000ULL,  0x11111f00000000ULL, 0x22223e00000000ULL,
  0x44447c00000000ULL, 0x8087800000000ULL,  0x10107000000000ULL, 0x0ULL,
  0x0ULL,              0x0ULL,              0x0ULL,              0x0ULL,
  0x0ULL,              0x0ULL,              0x0ULL,              0x0ULL,
};
// clang-format on

void cvazz::genCloneMoves(MoveList &Ml, const Position &Pos) {
  auto Us = Pos.Pieces[Pos.Stm];
  auto Them = Pos.Pieces[Pos.xstm()];
  auto Tos = (Us << 1 | Us << 7 | Us << 8 | Us << 9 | Us >> 1 | Us >> 7 |
              Us >> 8 | Us >> 9);
  Tos &= ~(Us | Them | Pos.Fills);
  while (Tos)
    Ml.push_back({Square::None, Square(Tos.takeLsb())});
}

void cvazz::genHopMoves(MoveList &Ml, const Position &Pos) {
  auto Us = Pos.Pieces[Pos.Stm];
  auto Them = Pos.Pieces[Pos.xstm()];
  while (Us) {
    auto From = Us.takeLsb();
    auto Tos = Bitboard(SND_NEIGHBORS[From]);
    Tos &= ~(Us | Them | Pos.Fills);
    while (Tos)
      Ml.push_back({From, Square(Tos.takeLsb())});
  }
}

void cvazz::genAllMoves(MoveList &Ml, const Position &Pos) {
  genCloneMoves(Ml, Pos);
  genHopMoves(Ml, Pos);

  if (!Ml.size())
    Ml.push_back({Square::None, Square::None});
}

void cvazz::makeMove(Position &Pos, const Move Mv) {
  Pos.Fmc += static_cast<int>(Pos.Stm);

  // No legal move, skip turn
  if (Mv.isNull()) {
    Pos.Stm = Pos.xstm();
    return;
  }

  auto Stm = Pos.Stm;
  auto Xstm = Pos.xstm();
  auto &Us = Pos.Pieces[Stm];
  auto &Them = Pos.Pieces[Xstm];
  auto [From, To] = Mv;

  Us.set(To);
  Pos.Hash ^= zobrist::COLOR_KEYS[Stm][To];

  auto Captures = Them & Bitboard(FST_NEIGHBORS[To]);
  Us |= Captures;
  Them &= ~Captures;

  while (Captures) {
    auto c = Captures.takeLsb();
    Pos.Hash ^= zobrist::COLOR_KEYS[Stm][c];
    Pos.Hash ^= zobrist::COLOR_KEYS[Xstm][c];
  }

  if (Mv.isHop()) {
    Us.unset(From);
    Pos.Hash ^= zobrist::COLOR_KEYS[Stm][To];

    ++Pos.Hmc;
  } else {
    Pos.Hmc = 0;
  }

  Pos.Stm = Xstm;
  Pos.Hash ^= zobrist::STM_KEY;
}
