//
// Created by nov11 on 27.12.2021.
//

#include <cstdio>
#include "printf_text_renderer_with_value_t.h"

template <class T>
void printf_text_renderer_with_value_t<T>::render(int index, bool selected) {
    // Draw selection mark
    if(selected) printf("> ");
    else printf("  ");

    // Draw option name
    printf("%d. %s [%d]\r\n", index + 1, text, *this->value);
}

template <class T>
printf_text_renderer_with_value_t<T>::printf_text_renderer_with_value_t(const char *text, T* value) {
    this->text = (char*) text;
    this->value = value;

}

template class printf_text_renderer_with_value_t<int>;
template class printf_text_renderer_with_value_t<double>;



