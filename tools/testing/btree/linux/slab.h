#ifndef _LINUX_SLAB_H
#define _LINUX_SLAB_H

#include <stdlib.h>
#include <string.h>
#include <linux/types.h>
#include <linux/gfp.h>

#define SLAB_HWCACHE_ALIGN 0

struct kmem_cache {
    size_t size;
};

static inline struct kmem_cache *kmem_cache_create(const char *name, size_t size, size_t align,
		unsigned long flags, void (*ctor)(void *))
{
    struct kmem_cache *cache = malloc(sizeof(*cache));
    if (cache)
        cache->size = size;
    return cache;
}

static inline void kmem_cache_destroy(struct kmem_cache *cache)
{
    free(cache);
}

static inline void *kmem_cache_alloc(struct kmem_cache *cache, gfp_t flags)
{
    return malloc(cache->size);
}

static inline void kmem_cache_free(struct kmem_cache *cache, void *obj)
{
    free(obj);
}

static inline void *kmalloc(size_t size, gfp_t flags)
{
    return malloc(size);
}

static inline void kfree(const void *obj)
{
    free((void *)obj);
}

static inline void *kmalloc_array(size_t n, size_t size, gfp_t flags)
{
    return malloc(n * size);
}

#endif
