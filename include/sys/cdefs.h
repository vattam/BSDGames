/* cdefs.h - bsd-games wrapper for <sys/cdefs.h> */

#include_next <sys/cdefs.h>

#ifndef __RCSID
#define __RCSID(arg)	static const char rcsid[] __attribute__((unused)) = arg
#endif

#ifndef __COPYRIGHT
#define __COPYRIGHT(arg)	static const char copyright[] __attribute__((unused)) = arg
#endif
