// Fragment Shader

#version 330 core
out vec4 FragColor;

in vec3 FragPos;  
in vec3 Normal;  
in vec2 TexCoords;
in vec3 Color;

uniform sampler2D roomTexture;

uniform vec3 lightPosRoom; 
uniform vec3 viewPos;
uniform vec3 lightColorRoom;
uniform vec3 objectColorRoom;

void main()
{
	FragColor = texture(roomTexture, TexCoords);
}
