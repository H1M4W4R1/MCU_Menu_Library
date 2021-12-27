//
// Created by nov11 on 23.12.2021.
//

#include <iostream>
#include "menu.h"
#include "menu_common.h"


#ifdef PC_DEBUG_MODE
#ifdef WIN32

#include <conio.h>

#endif
#endif

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

        options[q]->render(q, selected == q);
    }

    // Ask for action
#ifdef PC_DEBUG_MODE
    int num;

    num = getch();

#if WIN32
    system("cls");
#endif
    if(num == '2')
        menu_common_t::next();
    else if(num == '8')
        menu_common_t::previous();
    else if(num == 's' || num == 13)
        menu_common_t::execute(ON_PRESS, nullptr);
    else if(num == '+')
        menu_common_t::execute(ON_INCREASE, nullptr);
    else if(num == '-')
        menu_common_t::execute(ON_DECREASE, nullptr);
    else
        menu_common_t::refresh();
#endif
}

void menu_t::execute_option(int i, action_type_t actionType, i_action_metadata* metadata) {
    if(i < options.size())
        options[i]->execute(actionType, metadata);
}

int menu_t::available_options_count() {
    return (int) options.size();
}
