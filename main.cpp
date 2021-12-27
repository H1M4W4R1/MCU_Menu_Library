#include <iostream>
#include "lib/menu/menu_common.h"

int volume = 0;

ACTION(on_menu_select_1)
{
    std::cout << "Selected option 1! \n" << std::endl;
}

ACTION(on_menu_select_2)
{
    std::cout << "Selected option 2! \n" << std::endl;
}

ACTION(funny_text)
{
    std::cout << "***** *** \n" << std::endl;
}

ACTION(on_value_changed)
{
    std::cout << "Value has been changed! \n" << std::endl;
}


ACTION(on_increase)
{
    volume++;
}

ACTION(on_decrease)
{
    volume--;
}

menu_t* menu2  = (new menu_t())
        ->add_option(MENU_SIMPLE_OPTION("Tell me a joke", funny_text, action_type_t::ON_PRESS))
        ->add_option(MENU_CHANGE_OPTION("Do Change", on_value_changed))
        ->add_option(MENU_BACK_OPTION("Back");

menu_t* menu1 = (new menu_t())
        ->add_option(MENU_SIMPLE_OPTION("Select option 2", on_menu_select_2, action_type_t::ON_PRESS))
        ->add_option(MENU_SUBMENU_OPTION("More...", new submenu_action_t(menu2)))
        ->add_option(MENU_BACK_OPTION("Back");

menu_t* menu = (new menu_t())
        ->add_option(MENU_SIMPLE_OPTION("Select option 1", on_menu_select_1, action_type_t::ON_PRESS))
        ->add_option(MENU_INCREASE_DECREASE_OPTION(MENU_TEXT_WITH_VALUE(int, "Volume", volume), on_increase, on_decrease))
        ->add_option(MENU_SUBMENU_OPTION("More...",
                                         new submenu_action_t(menu1)));


int main() {
    menu_common_t::open_menu(menu);

    return 0;
}
