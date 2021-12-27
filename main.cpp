#include <iostream>
#include "lib/menu/menu_common.h"

int targetTemperature = 0;


ACTION(preheat_pla)
{
    targetTemperature = 210;
}

ACTION(preheat_abs)
{
    targetTemperature = 230;
}

ACTION(preheat_petg)
{
    targetTemperature = 240;
}

ACTION(preheat_off)
{
    targetTemperature = 0;
}

ACTION(temperature_up)
{
    targetTemperature += 5;
}

ACTION(temperature_down)
{
    targetTemperature -= 5;
}

menu_t* preheat  = (new menu_t())
        ->add_option(MENU_BACK_OPTION("Back")
        ->add_option(MENU_SIMPLE_OPTION("Preheat OFF", preheat_off, action_type_t::ON_PRESS))
        ->add_option(MENU_SIMPLE_OPTION("Preheat PLA", preheat_pla, action_type_t::ON_PRESS))
        ->add_option(MENU_SIMPLE_OPTION("Preheat ABS", preheat_abs, action_type_t::ON_PRESS))
        ->add_option(MENU_SIMPLE_OPTION("Preheat PETG", preheat_petg, action_type_t::ON_PRESS));

menu_t* menu1 = (new menu_t())
        ->add_option(MENU_BACK_OPTION("Back")
        ->add_option(MENU_SUBMENU_OPTION("Preheat", preheat));

menu_t* menu = (new menu_t())
        ->add_option(MENU_INCREASE_DECREASE_OPTION(MENU_TEXT_WITH_INT("Target temperature", targetTemperature), temperature_up, temperature_down)) // Temperature
        ->add_option(MENU_SUBMENU_OPTION("Settings...", menu1));


int main() {
    menu_common_t::open_menu(menu);

    return 0;
}
