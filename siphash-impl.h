
#ifndef __SIPHASH_IMPL_H__
#define __SIPHASH_IMPL_H__

#if defined(_MSC_VER)
# include <intrin.h>
typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t;
#else
# include <stdint.h>
# include <stdlib.h>
#endif

uint64_t siphash(unsigned char key[16], const unsigned char *m, size_t len);

#endif
