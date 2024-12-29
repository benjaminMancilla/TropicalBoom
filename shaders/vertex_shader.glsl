#version 330 core
layout (location = 0) in vec3 aPos;      // Vertex position
layout (location = 1) in vec3 aNormal;   // Normal

out vec3 FragPos;             // Fragment position
out vec3 Normal;              // Normal
out vec4 FragPosLightSpace;   // Position in light space

uniform mat4 model;           // Model matrix
uniform mat4 view;            // Camera matrix
uniform mat4 projection;      // General projection matrix
uniform mat4 lightSpaceMatrix;// Light space matrix

void main() {
    // Transform vertex to world space
    FragPos = vec3(model * vec4(aPos, 1.0)).xyz;
    Normal = mat3(transpose(inverse(model))) * aNormal;

    // Transform to light space
    FragPosLightSpace = lightSpaceMatrix * vec4(FragPos, 1.0);

    // Final position in clip space
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}

