/* lib/getloadavg.c - bsd-games implementation of getloadavg.
 *
 * Copyright (c) 1998, 1999 Joseph Samuel Myers.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef HAVE_getloadavg
int
getloadavg(double loadavg[], int nelem)
{
  double load_averages[3];
  FILE *fp;
  int count;
  int i;
  int nc;
  fp = fopen("/proc/loadavg", "r");
  if (fp == NULL)
    return -1;
  count = fscanf(fp, "%lf%lf%lf", &(load_averages[0]), &(load_averages[1]),
		 &(load_averages[2]));
  fclose(fp);
  if ((count == EOF) || (count == 0))
    return -1;
  nc = ((nelem < count) ? nelem : count);
  for (i = 0; i < nc; i++)
    loadavg[i] = load_averages[i];
  return nc;
}
#endif
