#include <gtest/gtest.h>
#include "uptime.h"

TEST(FormatUptime, Zero)
{
    EXPECT_EQ(format_uptime(0), "00:00:00");
}

TEST(FormatUptime, Seconds)
{
    EXPECT_EQ(format_uptime(45), "00:00:45");
}

TEST(FormatUptime, Minutes)
{
    EXPECT_EQ(format_uptime(90), "00:01:30");
}

TEST(FormatUptime, Hours)
{
    EXPECT_EQ(format_uptime(3661), "01:01:01");
}

TEST(FormatUptime, LargeValue)
{
    EXPECT_EQ(format_uptime(86399), "23:59:59");
}

TEST(FormatUptime, MultipleHours)
{
    EXPECT_EQ(format_uptime(36000), "10:00:00");
}
