/* Cartoon Shader - Vertex Lighting */

#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;
layout (location = 3) in vec3 color;

out vec3 Normal;
out vec3 FragPos;
out vec2 TexCoords;
out vec3 Color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{   
    // **Reference: chuyi@'s HW3 vertex shader code.
    
    // Since our transformations matrices are mat4s, we append a fourth w-term of 1.0f to position.
    vec4 position4 = vec4(position, 1.0f);

    // Transform position4 to NDC coordinates for gl_Position (cf. Lecture 7, Slide 28).
    gl_Position = projection * view * model * position4;

    // Transform the normal vector by the normal matrix.
    Normal = normalize(mat3(transpose(inverse(model))) * normalize(normal));

    // Calculate FragPos as the world-space location of position4.
    FragPos = vec3(model * position4);

    // Set TexCoords.
    TexCoords = texCoords;
    
    // Set Color.
    Color = color;
}