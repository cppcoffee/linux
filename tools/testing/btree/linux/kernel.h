#ifndef _LINUX_KERNEL_H
#define _LINUX_KERNEL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <linux/compiler.h>

#define likely(x) (x)
#define unlikely(x) (x)
#define BUG_ON(x) assert(!(x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define ENOMEM 12
#define ENOENT 2
#define EAGAIN 11

#define printk printf
#define KERN_ALERT ""

#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type,member) );})

/* BITS_PER_LONG */
#define BITS_PER_LONG 64

#endif
