
#include "motor.h"
#include <stdio.h>
#include "system.h"
#include <io.h> /* Leiutura e escrita no Avalon */
#include <unistd.h>


int main()
{
  printf("Aquecendo os motores!\n");

  volatile unsigned int *p_led = (unsigned int *) PERIPHERAL_LED_0_BASE;

  while(1){
	  motor_init(p_led);
	  usleep(5000000);

      motor_halt(p_led);
      usleep(5000000);

	  motor_en(p_led);
	  usleep(5000000);

	  motor_dir(p_led);
	  usleep(5000000);

	  motor_vel(p_led);
	  usleep(5000000);

	  printf("Fim de ciclo!\n");
};
  return 0;
}
