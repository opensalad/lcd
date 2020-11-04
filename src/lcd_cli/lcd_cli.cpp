#include <lcd.h>

#include "lcd_console_drawer.h"

int main(int argc, char** argv)
{
	std::shared_ptr<opensalad::lcd::lcd_console_drawer> lcd_drawer = std::make_shared<opensalad::lcd::lcd_console_drawer>();
	opensalad::lcd::lcd lcd(lcd_drawer);
	return 0;
}