//
// Created by nov11 on 23.12.2021.
//

#include "menu_option.h"
#include "renderers/printf_text_renderer_t.h"
#include "menu_common.h"

menu_option_t* menu_option_t::add_listener(action_t *listener) {
    if(listener == nullptr) {
        return this;
    }
    listeners.push_back(listener);

    return this;
}

void menu_option_t::execute(action_type_t actionType, i_action_metadata *metadata) {
    // Execute all listeners with proper action type
    for(auto listener : listeners) {

        if((listener->getActionType() & actionType) > 0) {
            listener->execute(metadata);
        }
    }

    menu_common_t::refresh();
}

// Create new menu option
menu_option_t::menu_option_t(i_renderer* rendererPtr) {
    if(rendererPtr == nullptr)
        return;

    this->renderer = rendererPtr;
}

void menu_option_t::render(int index, bool selected) {
    if(renderer == nullptr)
        return;
    renderer->render(index, selected);
}

menu_option_t::menu_option_t(const char* text) {
    renderer = (i_renderer*) new printf_text_renderer_t(text);
}


