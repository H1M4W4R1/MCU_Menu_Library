//
// Created by nov11 on 23.12.2021.
//

#include "action.h"

action_t::action_t(callback_t callback, action_type_t actionType) {
    this->callback = callback;
    this->actionType = actionType;
}

void action_t::execute(i_action_metadata* metadata) {
    callback(this, metadata);
}

action_type_t action_t::getActionType() {
    return actionType;
}


