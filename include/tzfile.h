/* tzfile.h - bsd-games version of <tzfile.h> that defines isleap */

#ifndef LINUX_BSD_GAMES_TZFILE_H
#define LINUX_BSD_GAMES_TZFILE_H	1

#define isleap(y) ((((y) % 4) == 0 && ((y) % 100) != 0) || ((y) % 400) == 0)

#endif /* !defined(LINUX_BSD_GAMES_TZFILE_H) */
