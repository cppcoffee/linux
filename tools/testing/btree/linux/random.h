#ifndef _LINUX_RANDOM_H
#define _LINUX_RANDOM_H

#include <stdlib.h>
#include <linux/types.h>

static inline u32 get_random_u32(void)
{
    return rand();
}

static inline void prandom_seed_state(void *state, u64 seed)
{
    srand((unsigned int)seed);
}

#endif
