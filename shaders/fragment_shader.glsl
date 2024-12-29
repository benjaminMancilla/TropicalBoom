#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec4 FragPosLightSpace;

uniform sampler2D shadowMap;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

float ShadowCalculation(vec4 fragPosLightSpace)
{
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;

    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;

    float bias = 0.005;
    float shadow = currentDepth > closestDepth + bias ? 1.0 : 0.0;
    return shadow;
}

void main() {
    // Ambient Light
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // Difusse Light
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Specular Light
    float specularStrenght = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrenght * spec * lightColor;

    // Shadow
    float shadow = ShadowCalculation(FragPosLightSpace);

    // Total Light
    vec3 result = (ambient + (1.0 - shadow) * (diffuse + specular)) * objectColor;

    // Color
    FragColor = vec4(result, 1.0);
}

