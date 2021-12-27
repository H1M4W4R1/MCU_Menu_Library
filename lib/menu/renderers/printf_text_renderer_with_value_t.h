//
// Created by nov11 on 27.12.2021.
//

#ifndef MENULIB_PRINTF_TEXT_RENDERER_WITH_VALUE_T_H
#define MENULIB_PRINTF_TEXT_RENDERER_WITH_VALUE_T_H


#include "../i_renderer.h"

template<class T>
class printf_text_renderer_with_value_t : public i_renderer {
private:
    char* text{};
    T* value{};

public:
    void render(int index, bool selected) override;
    explicit printf_text_renderer_with_value_t(const char* text, T* value);
};


#endif //MENULIB_PRINTF_TEXT_RENDERER_WITH_VALUE_T_H
