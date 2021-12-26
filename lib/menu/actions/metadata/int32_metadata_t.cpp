//
// Created by nov11 on 27.12.2021.
//

#include "int32_metadata_t.h"

int32_t int32_metadata_t::get_value() {
    return this->value;
}

int32_metadata_t::int32_metadata_t(int32_t val) {
    this->value = val;
}
