#include "kinetic/game.h"

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <stdio.h>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int modifiers) {
    if (key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if (action == GLFW_PRESS) {
        if (darray_length(snake_block_list) != 0) {
            square *first = snake_block_list[0];
            if (key == GLFW_KEY_A) {
                square_set_direction(first, DIR_LEFT);
            }
            if (key == GLFW_KEY_D) {
                square_set_direction(first, DIR_RIGHT);
            }
            if (key == GLFW_KEY_W) {
                square_set_direction(first, DIR_UP);
            }
            if (key == GLFW_KEY_S) {
                square_set_direction(first, DIR_DOWN);
            }
        }
        if (key == GLFW_KEY_SPACE) {
            add_tail();
        }
    }
}

int main(int argc, char *argv[]) {
    if (!glfwInit()) return -1;

    GLFWwindow *window = glfwCreateWindow(800, 800, "Snake", NULL, NULL);
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

    glGenVertexArrays(1, &vertexArray);
    glGenBuffers(1, &vertexBuffer);

    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

    glEnableVertexAttribArray(0);

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