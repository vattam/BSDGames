/* stdlib.h - bsd-games wrapper for <stdlib.h> */

#include_next <stdlib.h>

extern int getloadavg(double loadavg[], int nelem);
