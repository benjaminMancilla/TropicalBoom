#include <gtest/gtest.h>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

// Mock para inicializar el triángulo
void mockInitializeTriangle(unsigned int& VAO, unsigned int& VBO) {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

TEST(TriangleTest, GeneratesCorrectly) {
    // Crear un contexto OpenGL
    if (!glfwInit()) {
        FAIL() << "GLFW initialization failed!";
    }
    GLFWwindow* window = glfwCreateWindow(800, 600, "Test Context", nullptr, nullptr);
    ASSERT_NE(window, nullptr) << "Failed to create GLFW window!";
    glfwMakeContextCurrent(window);

    // Verificar inicialización de GLAD
    if (!gladLoadGL(glfwGetProcAddress)) {
        glfwDestroyWindow(window);
        glfwTerminate();
        FAIL() << "GLAD initialization failed!";
    }

    unsigned int VAO, VBO;
    mockInitializeTriangle(VAO, VBO);

    EXPECT_GT(VAO, 0);
    EXPECT_GT(VBO, 0);

    glBindVertexArray(VAO);
    int enabled;
    glGetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);
    EXPECT_EQ(enabled, GL_TRUE);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // Limpiar contexto
    glfwDestroyWindow(window);
    glfwTerminate();
}
