//
// Created by nov11 on 23.12.2021.
//

#ifndef MENULIB_PRINTF_TEXT_RENDERER_T_H
#define MENULIB_PRINTF_TEXT_RENDERER_T_H

#include <cstdlib>
#include "../i_renderer.h"

class printf_text_renderer_t : i_renderer {
private:
    char* text;

public:
    void render(bool selected) override;
    explicit printf_text_renderer_t(const char* text);
};


#endif //MENULIB_PRINTF_TEXT_RENDERER_T_H
