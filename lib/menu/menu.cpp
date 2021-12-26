//
// Created by nov11 on 23.12.2021.
//

#include <iostream>
#include "menu.h"
#include "menu_common.h"

#define PC_DEBUG_MODE

menu_t* menu_t::add_option(menu_option_t* option) {
    // Check if option exists then add it
    if(option != nullptr)
        options.push_back(option);

    return this;
}

// Render menu
void menu_t::render(int start, int count, int selected) {
    for(int q = start; q < start + count; q++) {
        if(q > options.size() - 1)
            break;

        options[q]->render(selected == q);
    }

    // Ask for action
#ifdef PC_DEBUG_MODE
    char num;

    std::cout << "Please select an option:" << std::endl;
    std::cin >> num;

    if(num == '+')
        menu_common_t::next();
    if(num == '-')
        menu_common_t::previous();
    if(num == 's')
        menu_common_t::execute(ON_PRESS, nullptr);
    if(num == ']')
        menu_common_t::execute(ON_INCREASE, nullptr);
    if(num == '[')
        menu_common_t::execute(ON_DECREASE, nullptr);
#endif
}

void menu_t::execute_option(int i, action_type_t actionType, i_action_metadata* metadata) {
    if(i < options.size())
        options[i]->execute(actionType, metadata);
}

int menu_t::available_options_count() {
    return (int) options.size();
}
