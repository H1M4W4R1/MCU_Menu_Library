//
// Created by nov11 on 27.12.2021.
//

#ifndef MENULIB_INT32_METADATA_T_H
#define MENULIB_INT32_METADATA_T_H


#include <cstdint>
#include "../i_action_metadata.h"

class int32_metadata_t : public i_action_metadata {
private:
    int32_t value;
public:
    int32_t get_value();
    explicit int32_metadata_t(int32_t val);
};


#endif //MENULIB_INT32_METADATA_T_H
