#include <lcd.h>

#include "lcd_console_drawer.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::shared_ptr<opensalad::lcd::lcd_console_drawer> lcd_drawer = std::make_shared<opensalad::lcd::lcd_console_drawer>();
	opensalad::lcd::lcd lcd(lcd_drawer);
	
	while (1)
	{
		std::string command;
		std::cin >> command;

		if (command == "exit")
			break;
		else if (command == "write")
		{
			std::cin >> command;
			for (opensalad::lcd::byte_t byte : command)
				lcd.send_data(byte);
		}
	}

	return 0;
}