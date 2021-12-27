//
// Created by nov11 on 23.12.2021.
//

#include "printf_text_renderer_t.h"
#include <cstdio>

void printf_text_renderer_t::render(int index, bool selected) {

    // Draw selection mark
    if(selected) printf("> ");
    else printf("  ");

    // Draw option name
    printf("%d. %s \r\n", index + 1, text);
}

printf_text_renderer_t::printf_text_renderer_t(const char *text) {
    this->text = (char*) text;
}
