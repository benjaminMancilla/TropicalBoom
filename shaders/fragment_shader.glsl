#version 330 core

#define MAX_LIGHTS 10
#define LIGHT_DIRECTIONAL 0
#define LIGHT_POINT 1

struct Light {
    int type; // 0 = Directional, 1 = Point
    vec3 position;
    vec3 color;
    vec3 direction;
};

uniform Light lights[MAX_LIGHTS];
uniform int lightCount;

out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec4 FragPosLightSpace;

uniform sampler2D shadowMap;
uniform vec3 viewPos;
uniform vec3 objectColor;

// SImplified Shadow Calculation
float ShadowCalculation(vec4 fragPosLightSpace)
{
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;

    if (projCoords.z > 1.0)
        return 0.0;

    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;

    float bias = 0.05; // Bias to reduce shadow acne (Heuristic)
    float shadow = currentDepth > closestDepth + bias ? 1.0 : 0.0;
    return shadow;
}

void main() {
    vec3 result = vec3(0.0);

    for (int i = 0; i < min(lightCount, MAX_LIGHTS); ++i) {
        vec3 lightDir = vec3(0.0);;
        vec3 norm = normalize(Normal);

        // lightDir depends on light type
        if (lights[i].type == LIGHT_DIRECTIONAL) {
            lightDir = normalize(-lights[i].direction);
        }
        
        else if (lights[i].type == LIGHT_POINT) {
            lightDir = normalize(lights[i].position - FragPos);
        }

        else {
            // Unsupported Light Type, cout and continue
            continue;
        }

        // Ambient Light
        vec3 ambient = 0.1 * lights[i].color;

        // Diffuse Light
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff * lights[i].color;

        // Specular Light
        float specularStrength = 0.5;
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
        vec3 specular = specularStrength * spec * lights[i].color;

        // Shadow
        float shadow = ShadowCalculation(FragPosLightSpace);

        // Combine Results
        result += (1.0 - shadow) * (ambient + diffuse + specular);
    }

    FragColor = vec4(result * objectColor, 1.0);
}


