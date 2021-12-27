//
// Created by nov11 on 23.12.2021.
//

#include "menu_common.h"

void menu_common_t::open_menu(menu_t *menu) {
    path.push_back(menu);
    current_option_index = 0;
    current_render_index = 0;
    menu->render();
}

void menu_common_t::go_back(int amount) {

    for(int q = 0; q < amount; q++)
        if(path.size() > 1)
            path.pop_back();

    // Get top menu
    current_option_index = 0;
    current_render_index = 0;
    refresh();
}

void menu_common_t::next() {
    // Next option
    current_option_index++;

    // If index falls out of render then increase render
    if(current_option_index >= current_render_index + rendered_options_count)
        current_render_index++;

    int optionsCount = path.back()->available_options_count();

    // If current option index falls out of options count then reset
    if(current_option_index >= optionsCount) {
        current_option_index = 0;
        current_render_index = 0;
    }

    // Render
    refresh();
}

void menu_common_t::previous() {

    // Only if more than 1 option
    if(available_options_count() <= 1) return;

    // Previous option
    current_option_index--;

    // If index falls out of render then decrease render
    if(current_option_index < current_render_index)
        current_render_index--;

    // If current option index falls out of options count then reset
    if(current_option_index < 0) {
        current_option_index = path.back()->available_options_count() - 1;
        current_render_index = current_option_index - 1;
    }

    // Render
    refresh();
}

void menu_common_t::refresh() {
    // Refresh
    path.back()->render(current_render_index, menu_common_t::rendered_options_count, current_option_index);
}

// Execute current option
void menu_common_t::execute(action_type_t type, i_action_metadata* metadata) {
    path.back()->execute_option(current_option_index, type, metadata);
}

int menu_common_t::available_options_count() {
    return path.back()->available_options_count();
}


