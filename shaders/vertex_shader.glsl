#version 330 core
layout (location = 0) in vec3 aPos; // Vertex position
layout (location = 1) in vec3 aNormal; // Normal

uniform mat4 model; // Model Matrix
uniform mat4 view; // Camera matrix
uniform mat4 projection; // General projection Matrix

void main() {
    // Add up all matrix
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
