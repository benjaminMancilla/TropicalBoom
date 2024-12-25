#version 330 core
layout (location = 0) in vec3 aPos; // Entrada: posición del vértice

void main() {
    gl_Position = vec4(aPos, 1.0); // Calcula la posición final del vértice
}
