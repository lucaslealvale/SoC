#include <stdio.h>
#include "system.h"
#include <alt_types.h>
#include <io.h> /* Leiutura e escrita no Avalon */

//#define SIM

// LED Peripheral
#define REG_DATA_OFFSET 1

int main(void){
  unsigned int led = 0;
  unsigned int *p_led = (unsigned int *) PERIPHERAL_LED_0_BASE;
#ifndef SIM
  printf("Embarcados++ \n");
#endif


   *(p_led)=1;



  return 0;
}
