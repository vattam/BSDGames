/* getloadavg.c - bsd-games implementation of getloadavg */

#include <stdio.h>
#include <stdlib.h>

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
