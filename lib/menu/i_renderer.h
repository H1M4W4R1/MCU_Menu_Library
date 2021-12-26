//
// Created by nov11 on 23.12.2021.
//

#ifndef MENULIB_I_RENDERER_H
#define MENULIB_I_RENDERER_H


class i_renderer {
public:
    virtual void render(bool selected) = 0; // Render this display item
};


#endif //MENULIB_I_RENDERER_H
