//
// Created by nov11 on 23.12.2021.
//

#ifndef MENULIB_MENU_OPTION_H
#define MENULIB_MENU_OPTION_H

#include "action.h"
#include <vector>
#include "i_renderer.h"

class menu_option_t;

class menu_option_t {
    private:
        std::vector<action_t*> listeners = {};
        i_renderer* renderer;
    public:
        menu_option_t* add_listener(action_t* listener);
        void execute(action_type_t actionType, i_action_metadata* metadata);
        explicit menu_option_t(i_renderer* rendererPtr);
        explicit menu_option_t(const char* text);
        void render(int index, bool selected);
};


#endif //MENULIB_MENU_OPTION_H
