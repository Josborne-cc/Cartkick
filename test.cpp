/*
Purpose: Recieve data serially to the RPi
Author: Josh Osborne
*/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <termios.h>
#include <cstring>
#include <string>
#include "comm.h"
#include "queue.h"

int main()
{
	Serial_Comm comm1;

	comm1.Open_Port("/dev/ttyAMA0");
	comm1.Initialize_Port(B9600);

	for(;;)
	{
	std::cout << comm1.Read_Data() << std::endl;
	sleep(10);
	}
	comm1.Close_Port();
	return 0;
}
