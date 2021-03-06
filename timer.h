#ifndef INCLUDE_TIMER_H
#define INCLUDE_TIMER_H

#pragma once
#include "common.h"

/* PIT has an internal clock which oscillates at approximately 1.1931MHz,
 * this macro defines desired frequency, dividing the default frequency by 100
 * gives us the frequency of 100Hz, so we get approximately 100 ticks per
 * second.
 */
#define TIMER_FREQUENCY 100

void init_timer(u32int frequency);

/* This will continuously loop until the given time (in centiSeconds, 100
 * centiSeconds is 1 second) has been reached
 */
void sleep(u32int centiSeconds);

#endif /* INCLUDE_TIMER_H */
