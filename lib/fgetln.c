/* fgetln.c - bsd-games implementation of fgetln */

#include <stdio.h>
#include <stdlib.h>

char *
fgetln(FILE *stream, size_t *len)
{
  static char *buf = NULL;
  static size_t buflen = 0;
  char *res;
  char *nbuf;
  if (buf == NULL) {
    buf = (char *)malloc(buflen = 1024);
    if (buf == NULL) {
      return NULL;
    }
  }
  buf[buflen - 1] = 1;
  res = fgets(buf, buflen, stream);
  if (res == NULL)
    return NULL;
  while (buf[buflen - 1] == 0) { /* long line */
    nbuf = realloc(buf, buflen * 2);
    if (nbuf == NULL)
      return NULL;
    buf = nbuf;
    buflen *= 2;
    buf[buflen - 1] = 1;
    res = fgets(buf + buflen/2 - 1, buflen/2 + 1, stream);
    if (res == NULL)
      return NULL;
  }
  *len = strlen(buf);
  return buf;
}
