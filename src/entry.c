#include "kinetic/game.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <stdio.h>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int modifiers) {
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                game_input_callback(KEY_ESCAPE);
                break;
            case GLFW_KEY_SPACE:
                game_input_callback(KEY_SPACE);
                break;
            case GLFW_KEY_A:
                game_input_callback(KEY_A);
                break;
            case GLFW_KEY_D:
                game_input_callback(KEY_D);
                break;
            case GLFW_KEY_S:
                game_input_callback(KEY_S);
                break;
            case GLFW_KEY_W:
                game_input_callback(KEY_W);
                break;
            default:
                break;
        }
    }
}

GLFWwindow *window;

unsigned int vertexArray;
unsigned int vertexBuffer;

int main(int argc, char *argv[]) {
    if (!glfwInit()) return -1;

    window = glfwCreateWindow(800, 800, "Snake", NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Error: Could not create a window!\n");
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "Error: Failed to initialize GLAD\n");
        glfwTerminate();
        return -1;
    }

    game_setup();

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(vertexArray);

        game_loop();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    game_cleanup();
    glfwTerminate();
    return 0;
}

void exit_game() {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
