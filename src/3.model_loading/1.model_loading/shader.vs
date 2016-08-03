#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;
layout (location = 3) in vec3 color;

out VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec3 Color;
} vs_out;

uniform mat4 projection;
uniform mat4 view;

void main()
{	
    gl_Position = projection * view * vec4(position, 1.0f);
    vs_out.FragPos = position;
    vs_out.Normal = normal;
    vs_out.TexCoords = texCoords;
    vs_out.Color = color;
}