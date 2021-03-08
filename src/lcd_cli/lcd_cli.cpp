// #include <lcd.h>

// #include "lcd_console_drawer.h"
// #include <iostream>

// int main(int argc, char** argv)
// {
// 	std::shared_ptr<opensalad::lcd::lcd_console_drawer> lcd_drawer = std::make_shared<opensalad::lcd::lcd_console_drawer>();
// 	opensalad::lcd::lcd lcd(lcd_drawer);

// 	while (1)
// 	{
// 		std::string command;
// 		std::cin >> command;

// 		if (command == "exit")
// 			break;
// 		else if (command == "write")
// 		{
// 			std::cin >> command;
// 			for (opensalad::lcd::byte_t byte : command)
// 				lcd.send_data(byte);
// 		}
// 	}

// 	return 0;
// }

#include <stdafx.h>
#include <lcd_lib/HD44780.h>
#include <lcd_windows_console_gui/lcd_console_drawer.h>

#include <windows.h>
#include <iostream>

int getKey()
{
	while (true)
	{
		for(int i = 8; i <= 256; i++)
		{
			if(GetAsyncKeyState(i) & 0x7FFF)
			{
				return i;
			}
		}
	}
}

int main()
{
	std::shared_ptr<opensalad::lcd::lcd_console_drawer> drawer = std::make_shared<opensalad::lcd::lcd_console_drawer>(20, 4);
	drawer->setup();
	std::shared_ptr<opensalad::lcd::iface::i_lcd_controller> controller = drawer->get_controller().lock();
	std::shared_ptr<opensalad::lcd::iface::i_lcd_controller_simplified> scontroller = std::dynamic_pointer_cast<opensalad::lcd::iface::i_lcd_controller_simplified>(drawer->get_controller().lock());

	std::string d = "Hello world My Name is Arsen";

	std::thread([=] {
		while(1)
		{
			char ch = getKey();
			controller->send_data(ch);
		}
	}).detach();

	scontroller->set_light_intencity(1.0);

	drawer->run();
	return 0;
}