#include <stdio.h>
#include <limits.h>
#include <bits/uio_lim.h>

int main(void) {
  printf("SSIZE_MAX: %lu\nLONG_MAX: %lu\nIOV_MAX: %lu", SSIZE_MAX, LONG_MAX, __IOV_MAX);
  return 0;
}

