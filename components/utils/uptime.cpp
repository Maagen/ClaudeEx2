#include "uptime.h"
#include <cinttypes>
#include <cstdio>

std::string format_uptime(uint64_t seconds)
{
    uint32_t h = static_cast<uint32_t>(seconds / 3600);
    uint32_t m = static_cast<uint32_t>((seconds % 3600) / 60);
    uint32_t s = static_cast<uint32_t>(seconds % 60);
    char buf[16];
    snprintf(buf, sizeof(buf), "%02" PRIu32 ":%02" PRIu32 ":%02" PRIu32, h, m, s);
    return buf;
}
