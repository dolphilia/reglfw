cmake_minimum_required(VERSION 3.26.4)
project(glfw)

include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/include/)
link_directories(${PROJECT_SOURCE_DIR}/)
link_directories(${PROJECT_SOURCE_DIR}/lib/)

#set(CMAKE_CXX_STANDARD 17)

add_executable(glfw
#add_library(glfw
#    SHARED
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
    main.c
)

if (APPLE)
    target_sources(glfw PRIVATE
        src/cocoa_time.h
        src/cocoa_time.c
        src/posix_thread.h
        src/posix_module.c
        src/posix_thread.c
    )
elseif (WIN32)
    target_sources(glfw PRIVATE
        src/win32_time.h
        src/win32_thread.h
        src/win32_module.c
        src/win32_time.c
        src/win32_thread.c
    )
else()
    target_sources(glfw PRIVATE
        src/posix_time.h
        src/posix_thread.h
        src/posix_module.c
        src/posix_time.c
        src/posix_thread.c
    )
endif()

target_sources(glfw PRIVATE
    src/cocoa_platform.h
    src/cocoa_joystick.h
    src/cocoa_init.m
    src/cocoa_joystick.m
    src/cocoa_monitor.m
    src/cocoa_window.m
    src/nsgl_context.m
)

target_link_libraries(glfw PRIVATE
#        glfw3
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreFoundation"
)