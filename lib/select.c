/* select.c - bsd-games emulation of BSD select for games that need it */

/* This uses __select, which works with libc5 and libc6.  This is a
 * substitute for the version in libbsd from libc5, and is essentially
 * equivalent.  */

#include <sys/time.h>

int
select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
       struct timeval *timeout)
{
  struct timeval timeout_copy;
  struct timeval *timeout_ptr;
  if (timeout) {
    /* Copy to a temporary */
    timeout_copy = *timeout;
    timeout_ptr = &timeout_copy;
  } else {
    timeout_ptr = timeout;
  }
  return __select(nfds, readfds, writefds, exceptfds, timeout_ptr);
}
