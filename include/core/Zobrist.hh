#pragma once

#include <cstdint>

namespace cvazz::zobrist {

constexpr std::uint64_t COLOR_KEYS[2][64] = {
    {0x380663c1cf879254ULL, 0x3ab4cc707dbb27ffULL, 0x9afd995e1fa294c4ULL,
     0x5dcc596d8b7bd539ULL, 0xd0e3c4ec2f4da87cULL, 0x4f8aeb8404f52a74ULL,
     0x8b3cbe8ee22eba39ULL, 0xf1ab84bfbe285b49ULL, 0x8499080c0aad8a47ULL,
     0xe9f7127a6fb77f6cULL, 0x8792d292f9a6e486ULL, 0x33fa873b73a388b6ULL,
     0x4312cd357d533d50ULL, 0xe565536dce637c68ULL, 0xd3493ac30dc4a912ULL,
     0x23e0f709b88e4f9fULL, 0x344cefa88695b3adULL, 0xb3edffa11cd936baULL,
     0x55ae26bfbbf6d039ULL, 0xa3da584c076c3de8ULL, 0x89f41237ea801becULL,
     0x70286f389886a129ULL, 0x3853754bd32b9688ULL, 0x3a10acaa493b2075ULL,
     0x79def5c12056f46eULL, 0x67b19f51fb9cfd0cULL, 0x5e994d6f940fc541ULL,
     0x697bbb7af3a2e5f4ULL, 0xb6909f7ee65a5797ULL, 0x20fef60206f7df0aULL,
     0x603642d758f3a5d7ULL, 0x86b7d31b7f35dd4ULL,  0x7443124e9c1ca4d2ULL,
     0x4fd1e8f977d73b27ULL, 0x2196d5e6340d48daULL, 0x3682361850155e33ULL,
     0xe98915772d95298dULL, 0x2b0a85cb7ed9bb9bULL, 0xc7d3f8ffb6387f9eULL,
     0x5e1b9c7943769c4dULL, 0xdb397c0106f743cdULL, 0x3278470520c4fa6aULL,
     0x161b5fa64407a4a7ULL, 0xbd9f3934b3590394ULL, 0xb93ae261f918e050ULL,
     0x2ec276f814c581cdULL, 0x564ed68d44b436adULL, 0x1ec7e8a398701805ULL,
     0x265c4da3fba4fb40ULL, 0x66d0e95514e0aebcULL, 0xdbf578a70f237efeULL,
     0xef6159355a731c18ULL, 0x6d2f45f81e91b075ULL, 0xbb4226df370a3ccULL,
     0x49ab1c76c44a4be2ULL, 0xc3bf2a4ae31005cULL,  0x177e0a6a254ee781ULL,
     0x3debc5a13d539d1bULL, 0xb0ab5aa46bc7098dULL, 0x474eb27938d253e3ULL,
     0x434794d17a7a3773ULL, 0x5d40b01ef3fa72eULL,  0xe3a618ae3a6614c6ULL,
     0x794aef8feec8fb3cULL},
    {0x90e7d957d0c32d6ULL,  0x222268fb861b5159ULL, 0x3f9f6fcd416bc8ffULL,
     0x8e75f5814bf61418ULL, 0x679cd49ac406a38dULL, 0xd5f8891c5779195aULL,
     0x5785bd7ad3901cb7ULL, 0x3437a4f6f5f64c19ULL, 0x963df0241a2e555dULL,
     0xc6d80cef63e64b32ULL, 0xba763d79f5ba691dULL, 0xac6787295862cdd8ULL,
     0xcef7fe71526d5b24ULL, 0x1ef4231d1346420aULL, 0x8b494c7c50efc20cULL,
     0x41ea72bfca0502c4ULL, 0x16a4604aeb3b53cULL,  0xba76ec842a9b01eeULL,
     0x1160ac5dbedafb98ULL, 0xcf0534b0f96e20deULL, 0x88899cea682a7be2ULL,
     0x93a85b9826093edcULL, 0x842579ba6cf0747ULL,  0x14b1c139800e5909ULL,
     0xef20fca394c3d69bULL, 0xc53db0ae4b20a583ULL, 0x2d9e8ef4b18d106dULL,
     0x9c83ad88a9d349d4ULL, 0xa3cd502b8067975dULL, 0x1416f62bd17c66bcULL,
     0xe9514f4bcdaa86ULL,   0x5297726eb5e1d78eULL, 0x348f419b8b640bddULL,
     0x7a570a0bb247b04fULL, 0x1c3aeb750f5afb2ULL,  0x6b2ce28d12259517ULL,
     0x7aa33fc70394fa73ULL, 0xfab147cd5f4784d2ULL, 0x7f344fd49bba04b9ULL,
     0xc2fdb224e8418e19ULL, 0xd33f9336c6cfea12ULL, 0x1fdebdf65c7078f9ULL,
     0x1c741ea068387833ULL, 0x9179aa4e6eabee07ULL, 0xb3318f1e33e97e3eULL,
     0xb497e8d8e05df25cULL, 0xce8639ce97996fedULL, 0xaa4f1a0e8f8d9518ULL,
     0x28824ca65cf13b04ULL, 0x546631a4ae6ab6bdULL, 0xddc85cb05a4c7c5eULL,
     0xfa3f9a812e28bb90ULL, 0x3958406f45fdcf5fULL, 0x7a684b5e6964add4ULL,
     0x3181c278e97df23eULL, 0xb7758eec9512a49aULL, 0xf999f480ae4b0501ULL,
     0xf46456a0b956d49dULL, 0x61acb657ac424e80ULL, 0xce5f487ad795c457ULL,
     0xc1c73bc2d37f8106ULL, 0x4a8c879d1192ca20ULL, 0xdbf2b0058b89ab14ULL,
     0x622752246997eba1ULL},
};

constexpr std::uint64_t FILL_KEYS[64] = {
    0x27d3cee299f3c8bbULL, 0x3eeabfabcc460048ULL, 0x54522ac804b9a905ULL,
    0xa3722cc2a895752eULL, 0x8dee7db6338d043ULL,  0x4f850b07371d94bULL,
    0xf5aa87eb8e06e77ULL,  0x94a44c0321ed9197ULL, 0x775d94940669b149ULL,
    0x339bcc03e12ee553ULL, 0x2c0f39556dcf6b6dULL, 0xa2f18ed6839db8faULL,
    0x17477692d09db9c2ULL, 0x8c88d5184b509586ULL, 0x7b10000e211ca5f4ULL,
    0x3f4a4b810987182bULL, 0x12244d7a842f0f9cULL, 0xc40594913271d0c9ULL,
    0x1ad4c13e6bc49cd2ULL, 0x7c4903b6100be07eULL, 0xebff9de153898694ULL,
    0x4dae0a6b7fdc749bULL, 0xaac234076a5d24c0ULL, 0x54286135ab14d226ULL,
    0xdcb979b9f4806aa2ULL, 0x65913a2d7f9fd61aULL, 0xc4b8d9585529e61cULL,
    0x54331a87c7acb61fULL, 0xbf28bc10e0c1f5b6ULL, 0xf0641f2870915783ULL,
    0x21fd9fa9e13f1d6eULL, 0xe466df72287d97ccULL, 0x36e2b1d5ca5fab99ULL,
    0x413c1a4e12328933ULL, 0xf53cf216210a5c36ULL, 0xe2c9a0aa7f87986aULL,
    0x74d13810f2ac5bd7ULL, 0x5dceb253f7b355c3ULL, 0x29c12e8bf1d7c613ULL,
    0xef9ecda8fd5dc8bcULL, 0x7f24365401592b7eULL, 0x3da55371eb03d8ULL,
    0x5f30ef1b89bdb079ULL, 0x764db42e77881b09ULL, 0x40531916bb105756ULL,
    0x6eb0e16132d3ec12ULL, 0x6593dbb95572870aULL, 0x7c84f3ba8ec0e036ULL,
    0xde68b42b9382e84fULL, 0xbdcc85691336b9cdULL, 0xb3b446d90ab9cff2ULL,
    0xec2aec624b19d1f0ULL, 0xfea7877d9f008224ULL, 0x9600e8f0d23962d2ULL,
    0xc76d7cf2ee4e32adULL, 0x4cc0a1bf7c08bce1ULL, 0x8fbe8493c9b56a28ULL,
    0xd842efb1f8464080ULL, 0xb884e106c431891fULL, 0xd03cbba1686e7e7cULL,
    0xec26b89744eaa02ULL,  0x96d5b0651c10e42fULL, 0x678b86d30c1e869fULL,
    0xf9982128d7d2c47bULL,
};

constexpr std::uint64_t STM_KEY = 0xf4ad28a4feabd042ULL;

} // namespace cvazz
