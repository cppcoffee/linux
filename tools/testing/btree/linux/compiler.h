#ifndef _LINUX_COMPILER_H
#define _LINUX_COMPILER_H

#define __must_check
#define __init
#define __exit
#define inline inline

#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#endif
