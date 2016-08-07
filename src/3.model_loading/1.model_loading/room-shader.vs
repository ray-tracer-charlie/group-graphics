/* Room Shader - Vertex Shader */

#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Since our transformations matrices are mat4s, we append a fourth w-term of 1.0f to position.
    vec4 position4 = vec4(position, 1.0f);

    // Transform position4 to NDC coordinates for gl_Position (cf. Lecture 7, Slide 28).
    gl_Position = projection * view * model * position4;

    // Transform the normal vector by the normal matrix.  Algebraic details at http://www.lighthouse3d.com/tutorials/glsl-12-tutorial/the-normal-matrix/.
    Normal = normalize(mat3(transpose(inverse(model))) * normal);

    // Calculate FragPos as the world-space location of position4.
    FragPos = vec3(model * position4);
}

