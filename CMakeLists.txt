cmake_minimum_required(VERSION 3.20)
project(menuLib)

set(CMAKE_CXX_STANDARD 23)
add_executable(menuLib main.cpp lib/menu/menu.cpp lib/menu/menu.h lib/menu/menu_option.cpp lib/menu/menu_option.h lib/menu/action.cpp lib/menu/action.h lib/menu/i_renderer.cpp lib/menu/i_renderer.h lib/menu/renderers/printf_text_renderer_t.cpp lib/menu/renderers/printf_text_renderer_t.h lib/menu/actions/submenu_action_t.cpp lib/menu/actions/submenu_action_t.h lib/menu/menu_common.cpp lib/menu/menu_common.h lib/menu/actions/submenu_back_action_t.cpp lib/menu/actions/submenu_back_action_t.h lib/menu/actions/i_action_metadata.cpp lib/menu/actions/i_action_metadata.h lib/menu/actions/metadata/int32_metadata_t.cpp lib/menu/actions/metadata/int32_metadata_t.h)
