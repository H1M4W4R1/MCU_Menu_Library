#include <iostream>
#include "lib/menu/menu_common.h"

int volume = 0;

void on_menu_select_1(action_t* action, i_action_metadata* metadata) {
    std::cout << "Selected option 1! \n" << std::endl;
    menu_common_t::refresh();
}

void on_menu_select_2(action_t* action, i_action_metadata* metadata){
    std::cout << "Selected option 2! \n" << std::endl;
    menu_common_t::refresh();
}

void funny_text(action_t* action, i_action_metadata* metadata){
    std::cout << "***** *** \n" << std::endl;
    menu_common_t::refresh();
}

void on_value_changed(action_t* action, i_action_metadata* metadata){
    std::cout << "Value has been changed! \n" << std::endl;
    menu_common_t::refresh();
}


ACTION(on_increase){
    volume++;
    std::cout << "Volume increased to: " << volume << std::endl;
    menu_common_t::refresh();
}

ACTION(on_decrease)
{
    volume--;
    std::cout << "Volume decreased to: " << volume << std::endl;
    menu_common_t::refresh();
}

menu_t* menu2  = (new menu_t())
        ->add_option(MENU_SIMPLE_OPTION("1. Tell me a joke \n", funny_text, action_type_t::ON_PRESS))
        ->add_option(MENU_INCREASE_DECREASE_OPTION("2. Volume \n", on_increase, on_decrease))
        ->add_option(MENU_CHANGE_OPTION("3. Do Change \n", on_value_changed))
        ->add_option(MENU_BACK_OPTION("4. Back \n");

menu_t* menu1 = (new menu_t())
        ->add_option(MENU_SIMPLE_OPTION("1. Select option 2 \n", on_menu_select_2, action_type_t::ON_PRESS))
        ->add_option(MENU_SUBMENU_OPTION("2. More... \n", new submenu_action_t(menu2)))
        ->add_option(MENU_BACK_OPTION("3. Back \n");

menu_t* menu = (new menu_t())
        ->add_option(MENU_SIMPLE_OPTION("1. Select option 1 \n", on_menu_select_1, action_type_t::ON_PRESS))
        ->add_option(MENU_SUBMENU_OPTION("2. More... \n",
                                         new submenu_action_t(menu1)));


int main() {
    menu_common_t::open_menu(menu);

    return 0;
}
