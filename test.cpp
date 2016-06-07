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
//#include <asio.hpp>

/*int main()
{
	asio::io_service io;
	asio::serial_port port(io);

	port.open("/dev/ttyUSB1");
	port.set_option(asio::serial_port_base::baud_rate(9600));

	char c;

	asio::read(port, asio::buffer(&c, 1);

	std::cout << "read: " << c << std::endl;

	port.close();
}*/

int main()
{
	Serial_Comm comm1;

	comm1.Open_Port("/dev/ttyAMA0");
	comm1.Initialize_Port(B9600);

	for(;;)
	{
		//comm1.Send_Data("josh");
		if(!comm1.Read_Empty())
			std::cout<< comm1.Read_Data() << std::endl;	
		//sleep(10);
	}

	comm1.Close_Port();
}
