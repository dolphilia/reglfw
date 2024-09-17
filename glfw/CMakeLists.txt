cmake_minimum_required(VERSION 3.26.4)
project(glfw)

set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/include/)
link_directories(${PROJECT_SOURCE_DIR}/)
link_directories(${PROJECT_SOURCE_DIR}/lib/)

# 共通のソースファイル
set(SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/include/GLFW/glfw3.h"
        "${PROJECT_SOURCE_DIR}/include/GLFW/glfw3native.h"
        src/internal.h
        src/platform.h
        src/mappings.h
        src/context.c
        src/init.c
        src/input.c
        src/monitor.c
        src/platform.c
        src/vulkan.c
        src/window.c
        src/egl_context.c
        src/osmesa_context.c
        src/null_platform.h
        src/null_joystick.h
        src/null_init.c
        src/null_monitor.c
        src/null_window.c
        src/null_joystick.c
)

# OSごとのソースファイル追加
if(APPLE)
    list(APPEND SOURCE_FILES
            src/cocoa_time.h
            src/cocoa_time.c
            src/posix_thread.h
            src/posix_module.c
            src/posix_thread.c
            src/cocoa_platform.h
            src/cocoa_joystick.h
            src/cocoa_init.m
            src/cocoa_joystick.m
            src/cocoa_monitor.m
            src/cocoa_window.m
            src/nsgl_context.m
    )
elseif(WIN32)
    list(APPEND SOURCE_FILES
            src/win32_time.h
            src/win32_thread.h
            src/win32_module.c
            src/win32_time.c
            src/win32_thread.c
            src/win32_platform.h
            src/win32_joystick.h
            src/win32_init.c
            src/win32_joystick.c
            src/win32_monitor.c win32_window.c
            src/wgl_context.c
    )
elseif(UNIX AND NOT APPLE)
    list(APPEND SOURCE_FILES
            src/posix_time.h
            src/posix_thread.h
            src/posix_module.c
            src/posix_time.c
            src/posix_thread.c
            # X11
            src/x11_platform.h
            src/xkb_unicode.h
            src/x11_init.c
            src/x11_monitor.c
            src/x11_window.c
            src/xkb_unicode.c
            src/glx_context.c
            # Wayland
            #wl_platform.h
            #xkb_unicode.h
            #wl_init.c
            #wl_monitor.c
            #wl_window.c
            #xkb_unicode.c
    )
endif()

#add_executable(glfw main.c ${SOURCE_FILES})
add_library(glfw STATIC ${SOURCE_FILES})

if (APPLE)
    target_link_libraries(glfw
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreFoundation"
    )
endif()

if (APPLE)
    target_compile_definitions(glfw PRIVATE _GLFW_COCOA)
elseif(WIN32)
    target_compile_definitions(glfw PRIVATE _GLFW_WIN32)
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(glfw PRIVATE _GLFW_X11)
    #target_compile_definitions(glfw PRIVATE _GLFW_WAYLAND)
endif()