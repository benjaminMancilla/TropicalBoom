#version 330 core

out vec4 FragColor;

uniform vec3 objectColor; // Object color

void main() {
    // For the moment is set at 1 color
    FragColor = vec4(objectColor, 1.0);
}

