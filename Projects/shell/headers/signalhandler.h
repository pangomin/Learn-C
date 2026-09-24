#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <signal.h>

int sigblocker(int signo);
int sigcleaner(int sig);

#endif
