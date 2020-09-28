#include <stdio.h>
#include "system.h"
#include <alt_types.h>
#include <io.h> /* Leiutura e escrita no Avalon */

int delay(int n)
{
    unsigned int delay = 0;
    while (delay < n)
    {
        delay++;
    }
}

int main(void)
{
    unsigned int led = 0;
    unsigned int motorPhase = 0;
    unsigned int switches = 0;
    char en = 0;
    char dir = 0;
    char vel0 = 0;
    char vel1 = 0;
    char vel2 = 0;
    char vel3 = 0;
    printf("Embarcados++ \n");

    while (1)
    {
        en = IORD_32DIRECT(PIO_1_BASE, 0) & 1;
        dir = IORD_32DIRECT(PIO_1_BASE, 0) & 2;
        //vel0 = IORD_32DIRECT(PIO_1_BASE, 0) & 4;
        //vel1 = IORD_32DIRECT(PIO_1_BASE, 0) & 4 & 8;
        //vel2 = IORD_32DIRECT(PIO_1_BASE, 0) & 4 & 8 & 16;
        //vel3 = IORD_32DIRECT(PIO_1_BASE, 0) & 4 & 8 & 16 & 32;
        //printf("vel0:%c\n",vel0);
        //printf("vel1:%c\n",vel1);
        //printf("vel2:%c\n",vel2);
        //printf("vel3:%c\n",vel3);
        if (en)
        {
            if (dir)
            {
                if (motorPhase <= 3)
                {

                    IOWR_32DIRECT(PIO_2_BASE, 0, 0x01 << motorPhase++);
                    usleep(5000);

                    // if (vel0)
                    // {
                    //     usleep(50000);
                    // }
                    // else if (vel1)
                    // {
                    //     usleep(5000);
                    // }
                    // else if (vel2)
                    // {
                    //     usleep(500);
                    // }
                    // else
                    // {
                    //     usleep(50);
                    // }
                }
                else
                {
                    motorPhase = 0;
                }
            }
            else
            {

                if (motorPhase <= 3)
                {

                    IOWR_32DIRECT(PIO_2_BASE, 0, 0x08 >> motorPhase++);
                    usleep(5000);

                    // if (vel0)
                    // {
                    //     usleep(50000);
                    // }
                    // else if (vel1)
                    // {
                    //     usleep(5000);
                    // }
                    // else if (vel2)
                    // {
                    //     usleep(500);
                    // }
                    // else
                    // {
                    //     usleep(50);
                    // }
                }
                else
                {
                    motorPhase = 0;
                }
            }
        };
    }
    return 0;
}
