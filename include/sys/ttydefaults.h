/* ttydefaults.h - bsd-games wrapper for <sys/ttydefaults.h> */

#include <features.h>

#ifdef __GLIBC__
#include_next <sys/ttydefaults.h>
#endif

#ifndef CTRL
#define CTRL(x)	((x) & 037)
#endif

#ifndef OXTABS
#define OXTABS	XTABS
#endif
