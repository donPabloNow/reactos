#define WIN32_LEAN_AND_MEAN
#define __ROS_LONG64__
#include <windows.h>

#define STANDALONE
#include "wine/test.h"

extern void func_RtlInitializeBitMap(void);
extern void func_ZwContinue(void);

const struct test winetest_testlist[] =
{
    { "RtlInitializeBitMap", func_RtlInitializeBitMap },
    { "ZwContinue", func_ZwContinue },

    { 0, 0 }
};

