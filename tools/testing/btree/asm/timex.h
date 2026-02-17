#ifndef _ASM_TIMEX_H
#define _ASM_TIMEX_H

#include <time.h>
#include <linux/types.h>

static inline cycles_t get_cycles(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

static inline u64 div_u64(u64 dividend, u32 divisor)
{
    return dividend / divisor;
}

#endif
