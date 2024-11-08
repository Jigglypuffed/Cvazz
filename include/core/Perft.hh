#pragma once

#include "core/Position.hh"
#include <cstdint>

namespace cvazz {

std::uint64_t perft(const Position&, int Depth);

} // namespace cvazz
