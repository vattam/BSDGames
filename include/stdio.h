/* stdio.h - bsd-games wrapper for <stdio.h> */

#include_next <stdio.h>

extern char *fgetln(FILE *stream, size_t *len);
