//
// Created by dolphilia on 24/08/07.
//
#include <stdio.h>
#include <stdlib.h>
//#define _GLFW_COCOA
#include "GLFW/glfw3.h"

int main() {
    if (!glfwInit()) {
        const char* description;
        glfwGetError(&description);
        printf("Error: %s\n", description);
        exit(EXIT_FAILURE);
    }
    GLFWwindow *window = glfwCreateWindow(300, 300, "example", NULL, NULL);
    while(glfwWindowShouldClose(window) == 0) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    printf("HelloWorld");
    return 0;
}