#ifndef _LINUX_MEMPOOL_H
#define _LINUX_MEMPOOL_H

#include <linux/slab.h>

typedef void *mempool_t;
typedef void *(*mempool_alloc_t)(gfp_t gfp_mask, void *pool_data);
typedef void (*mempool_free_t)(void *element, void *pool_data);

static inline mempool_t *mempool_create(int min_nr, mempool_alloc_t alloc_fn,
					mempool_free_t free_fn, void *pool_data)
{
    return (mempool_t *)malloc(1);
}

static inline void mempool_destroy(mempool_t *pool)
{
    free(pool);
}

static inline void *mempool_alloc(mempool_t *pool, gfp_t gfp_mask)
{
    return malloc(128);
}

static inline void mempool_free(void *element, mempool_t *pool)
{
    free(element);
}

#endif
