/* signal.h - bsd-games wrapper for <signal.h> */

#include <features.h>

#ifndef __GLIBC__
#define __USE_BSD_SIGNAL	1 /* Get BSD signal semantics with libc5 */
#endif

#include_next <signal.h>

#ifndef __GLIBC__ /* glibc 2 has this; with libc5 we want to avoid
		   * <bsd/signal.h>.  */
#ifndef LINUX_BSD_GAMES_DEFINED_SIG_T
typedef __sighandler_t sig_t;
#define LINUX_BSD_GAMES_DEFINED_SIG_T	1
#endif
#endif
