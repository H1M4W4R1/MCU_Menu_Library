//
// Created by nov11 on 23.12.2021.
//

#ifndef MENULIB_ACTION_H
#define MENULIB_ACTION_H

#include "actions/i_action_metadata.h"

class action_t;

// Callback definition
typedef void (*callback_t)(action_t* action, i_action_metadata* metadata);

// Action types
typedef enum {
    ON_PRESS = 1,
    ON_RELEASE = 2,
    ON_HOLD = 4,
    ON_DECREASE = 8,
    ON_INCREASE = 16,
    ON_CHANGE = (ON_DECREASE | ON_INCREASE)
} action_type_t;

class action_t {
private:
    callback_t callback;
    action_type_t actionType;
public:
    action_t(callback_t callback, action_type_t actionType);
    void execute(i_action_metadata* metadata);
    action_type_t getActionType();
};


#endif //MENULIB_ACTION_H
