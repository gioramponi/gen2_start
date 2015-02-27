#include "msp430x26x.h"
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;             // Stop watchdog timer
  P4DIR |= 0x04;                        // Set P4.2 to output direction
  for (;;)
  {
    volatile unsigned int i;            // volatile to prevent optimization
    P4OUT ^= 0x04;                      // Toggle P4.2 using exclusive-OR
    i = 50000;                          // SW Delay
    do i--;
    while (i != 0);
  }
}